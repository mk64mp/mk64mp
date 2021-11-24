#include <ultra64.h>
#include <PR/ultratypes.h>
#include <macros.h>
#include "types.h"

// Includes from SM64
//#include "buffers/buffers.h"
//#include "decompress.h"
//#include "game_init.h"
#include "main.h"
#include "memory.h"

//#include "segment_symbols.h"
//#include "segments.h"

#define ALIGN4(val) (((val) + 0x3) & ~0x3)
#define ALIGN16(val) (((val) + 0xF) & ~0xF)
#define ALIGN32(val) (((val) + 0xF) & ~0xF)

struct MainPoolState {
    u32 freeSpace;
    struct MainPoolBlock *listHeadL;
    struct MainPoolBlock *listHeadR;
    struct MainPoolState *prev;
};

struct MainPoolBlock {
    struct MainPoolBlock *prev;
    struct MainPoolBlock *next;
};

extern uintptr_t gSegmentTable[16];


extern s32 D_801502A0;
s32 D_802BA270;
s32 D_802BA274;
u32 sPoolFreeSpace;
struct MainPoolBlock *sPoolListHeadL;
struct MainPoolBlock *sPoolListHeadR;

extern u32 gPrevLoadedAddress;
extern s32 gPrevMainThreadTask;

extern Gfx *gDisplayListHead;
extern u32 D_8015F724;
extern u32 gHeapEndPtr;
extern u32 gIsMirrorMode;

extern struct D_80150158 gD_80150158[];

struct MainPoolState *gMainPoolState = NULL;

struct UnkStruct_802B8CD4 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 fill; 
};

struct UnkStruct_802B8CD4 D_802B8CD4[] = {
    0
};
s32 D_802B8CE4 = 0; // pad
s32 D_802B8CE8[] = {0xBC000002, 0x80000040};

s32 func_802A7B70(s32 segment) {
    s32 old;
    old = gPrevLoadedAddress;
    segment = ALIGN16(segment);
    gPrevLoadedAddress += segment;
    return old;
}

uintptr_t set_segment_base_addr(s32 segment, void *addr) {
    gSegmentTable[segment] = (uintptr_t) addr & 0x1FFFFFFF;
    return gSegmentTable[segment];
}

void *get_segment_base_addr(s32 segment) {
    return (void *) (gSegmentTable[segment] | 0x80000000);
}

s32 lookup_item(u32 segment) {
    return (gSegmentTable[segment >> 0x18] + (segment & 0xFFFFFF)) | 0x80000000;
}

void move_segment_table_to_dmem(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        gSPSegment(gDisplayListHead++, i, gSegmentTable[i]);
    }
}

void func_802A7CF0(s32 start, s32 end) {

    start = ALIGN32(start);
    end &= ~0xF;

    D_8015F724 = (end - start) - 0x10;
    gPrevLoadedAddress = start;
}


s32 func_802A7D1C(s32 arg0) {
    s32 addr;

    arg0 = ALIGN32(arg0);
    D_8015F724 -= arg0;
    addr = gPrevLoadedAddress;
    gPrevLoadedAddress += arg0;

    return addr;
}

UNUSED void func_802A7D54(s32 arg0, s32 arg1) {
    gD_80150158[arg0].unk0 = arg0;
    gD_80150158[arg0].unk8 = arg1;
}

void dma_copy(s32, s32, s32); // extern
s32 func_802A7D1C(s32 arg0); // extern

s32 func_802A7D70(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_a2 = arg1 - arg0;

    temp_v0 = func_802A7D1C(temp_a2);
    if (temp_v0 != 0) {
        dma_copy(temp_v0, arg0, temp_a2);
    }
    return temp_v0;
}

UNUSED void main_pool_init(u32 start, u32 end) {
    start = ALIGN16(start);
    end = ALIGN16(end - 15);

    sPoolFreeSpace = (end - start) - 16;

    sPoolListHeadL = (struct MainPoolBlock *) start;
    sPoolListHeadR = (struct MainPoolBlock *) end;
    sPoolListHeadL->prev = NULL;
    sPoolListHeadL->next = NULL;
    sPoolListHeadR->prev = NULL;
    sPoolListHeadR->next = NULL;
}

/**
 * Allocate a block of memory from the pool of given size, and from the
 * specified side of the pool (MEMORY_POOL_LEFT or MEMORY_POOL_RIGHT).
 * If there is not enough space, return NULL.
 */
void *main_pool_alloc(u32 size, u32 side) {
    struct MainPoolBlock *newListHead;
    void *addr = NULL;

    size = ALIGN16(size) + 8;
    if (sPoolFreeSpace >= size) {
        sPoolFreeSpace -= size;
        if (side == MEMORY_POOL_LEFT) {
            newListHead = (struct MainPoolBlock *) ((u8 *) sPoolListHeadL + size);
            sPoolListHeadL->next = newListHead;
            newListHead->prev = sPoolListHeadL;
            addr = (u8 *) sPoolListHeadL + 8;
            sPoolListHeadL = newListHead;
        } else {
            newListHead = (struct MainPoolBlock *) ((u8 *) sPoolListHeadR - size);
            sPoolListHeadR->prev = newListHead;
            newListHead->next = sPoolListHeadR;
            sPoolListHeadR = newListHead;
            addr = (u8 *) sPoolListHeadR + 8;
        }
    }
    return addr;
}
/**
 * Free a block of memory that was allocated from the pool. The block must be
 * the most recently allocated block from its end of the pool, otherwise all
 * newer blocks are freed as well.
 * Return the amount of free space left in the pool.
 */
u32 main_pool_free(void *addr) {
    struct MainPoolBlock *block = (struct MainPoolBlock *) ((u8 *) addr - 8);
    struct MainPoolBlock *oldListHead = (struct MainPoolBlock *) ((u8 *) addr - 8);

    if (oldListHead < sPoolListHeadL) {
        while (oldListHead->next != NULL) {
            oldListHead = oldListHead->next;
        }
        sPoolListHeadL = block;
        sPoolListHeadL->next = NULL;
        sPoolFreeSpace += (uintptr_t) oldListHead - (uintptr_t) sPoolListHeadL;
    } else {
        while (oldListHead->prev != NULL) {
            oldListHead = oldListHead->prev;
        }
        sPoolListHeadR = block->next;
        sPoolListHeadR->prev = NULL;
        sPoolFreeSpace += (uintptr_t) sPoolListHeadR - (uintptr_t) oldListHead;
    }
    return sPoolFreeSpace;
}
// main_pool_realloc
UNUSED void *main_pool_realloc(void *addr, u32 size) {
    void *newAddr = NULL;
    struct MainPoolBlock *block = (struct MainPoolBlock *) ((u8 *) addr - 8);

    if (block->next == sPoolListHeadL) {
        main_pool_free(addr);
        newAddr = main_pool_alloc(size, MEMORY_POOL_LEFT);
    }
    return newAddr;
}

UNUSED s32 main_pool_available(void) {
    return sPoolFreeSpace - 8;
}

UNUSED u32 main_pool_push_state(void) {
    struct MainPoolState *prevState = gMainPoolState;
    u32 freeSpace = sPoolFreeSpace;
    struct MainPoolBlock *lhead = sPoolListHeadL;
    struct MainPoolBlock *rhead = sPoolListHeadR;

    gMainPoolState = main_pool_alloc(sizeof(*gMainPoolState), MEMORY_POOL_LEFT);
    gMainPoolState->freeSpace = freeSpace;
    gMainPoolState->listHeadL = lhead;
    gMainPoolState->listHeadR = rhead;
    gMainPoolState->prev = prevState;
    return sPoolFreeSpace;
}

/**
 * Restore pool state from a previous call to main_pool_push_state. Return the
 * amount of free space left in the pool.
 */
UNUSED u32 main_pool_pop_state(void) {
    sPoolFreeSpace = gMainPoolState->freeSpace;
    sPoolListHeadL = gMainPoolState->listHeadL;
    sPoolListHeadR = gMainPoolState->listHeadR;
    gMainPoolState = gMainPoolState->prev;
    return sPoolFreeSpace;
}
// similar to sm64 dma_read
void *func_802A80B0(u8 *dest, u8 *srcStart, u8 *srcEnd) {
    u32 addr;
    u32 size = srcStart - dest;
    addr = main_pool_alloc(size, srcEnd);
    
    if (addr != 0) {

        osInvalDCache(addr, size);
        osPiStartDma(&gDmaIoMesg, OS_MESG_PRI_NORMAL, OS_READ, dest, addr, size,
                     &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, OS_MESG_BLOCK);
    }
    return addr;
}

// replaces call to dynamic_dma_read with dma_read.
UNUSED void *load_segment(s32 segment, u8 *srcStart, u8 *srcEnd, u32 side) {
    void *addr = func_802A80B0(srcStart, srcEnd, side);

    if (addr != NULL) {
        set_segment_base_addr(segment, addr);
    }
    return addr;
}

// Similar to sm64 load_to_fixed_pool_addr?
void *func_802A8190(s32 arg0, s32 arg1) {
    //u32 srcSize = ALIGN16(srcEnd - srcStart);
    //u32 destSize = ALIGN16((u8 *) sPoolListHeadR - destAddr);
    u32 addr;
    u32 temp_v0 = D_802B8CD4[arg0].unk4;
    u32 temp_v1 = D_802B8CD4[arg0].unk8;
    u32 temp_v2 = D_802B8CD4[arg0].unk2;
    addr = func_802A80B0(temp_v0, temp_v1, arg1);

        //dest = main_pool_alloc(destSize, MEMORY_POOL_RIGHT);
        if (addr != 0) {
            
            set_segment_base_addr(temp_v2, addr);
        }
    return addr;
}

UNUSED void func_802A81EC(void) {
    u32 addr;
    s32 temp_s0;
    s16 *phi_s1;
    s32 phi_s0;

    phi_s1 = &D_802B8CD4;
    phi_s0 = 0;
    do {
        if ((*phi_s1 & 1) != 0) {
            func_802A8190(phi_s0, 0);
        }
        temp_s0 = phi_s0 + 1;
        phi_s1 += 8;
        phi_s0 = temp_s0;
    } while (phi_s0 != 3);
}

UNUSED struct AllocOnlyPool *alloc_only_pool_init(u32 size, u32 side) {
    void *addr;
    struct AllocOnlyPool *subPool = NULL;

    size = ALIGN4(size);
    addr = main_pool_alloc(size + sizeof(struct AllocOnlyPool), side);
    if (addr != NULL) {
        subPool = (struct AllocOnlyPool *) addr;
        subPool->totalSpace = size;
        subPool->usedSpace = (u8 *) addr + sizeof(struct AllocOnlyPool);
        subPool->startPtr = 0;
        subPool->freePtr = (u8 *) addr + sizeof(struct AllocOnlyPool);
    }
    return subPool;
}

UNUSED u32 func_802A82AC(s32 arg0) {
    u32 temp_v0;
    u32 phi_v1;

    temp_v0 = D_801502A0 - arg0;
    phi_v1 = 0;
    if (temp_v0 >= (u32) gDisplayListHead) {
        D_801502A0 = temp_v0;
        phi_v1 = temp_v0;
    }
    return phi_v1;
}

s32 func_802A82E4(s32 arg0, s32 arg1) {
    s32 sp24;
    s32 sp1C;

    sp1C = ALIGN16(arg1 - arg0);
    sp24 = gPrevLoadedAddress;
    dma_copy(sp24, arg0, sp1C);
    gPrevLoadedAddress += sp1C;
    return sp24;
}

extern u8 _other_texturesSegmentRomStart[];
// unused mio0 decode func.
UNUSED s32 func_802A8348(s32 arg0, s32 arg1, s32 arg2) {
    s32 offset;
    UNUSED s32 *pad;
    s32 oldAddr;
    s32 newAddr;
    
    offset = ALIGN16(arg1 * arg2);
    oldAddr = gPrevLoadedAddress;
    newAddr = oldAddr + offset;
    pad = &newAddr;
    osInvalDCache(newAddr, offset);
    osPiStartDma(&gDmaIoMesg, 0, 0, &_other_texturesSegmentRomStart[arg0 & 0xFFFFFF], newAddr, offset, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, 1);
    
    func_80040030(newAddr, oldAddr);
    gPrevLoadedAddress += offset;
    return oldAddr;
}

UNUSED s32 func_802A841C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_a0;
    temp_v0 = gPrevLoadedAddress;
    temp_a0 = temp_v0 + arg2;
    arg1 = ALIGN16(arg1);
    arg2 = ALIGN16(arg2);
    
    osInvalDCache(temp_a0, arg1);
    osPiStartDma(&gDmaIoMesg, 0, 0, &_other_texturesSegmentRomStart[arg0 & 0xFFFFFF],temp_a0, arg1, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, 1);
    func_80040030(temp_a0, temp_v0);
    gPrevLoadedAddress += arg2;
    return temp_v0;
}

s32 func_802A84F4(s32 arg0, u32 arg1, u32 arg2) {
    u8 *temp_v0;
    u32 temp_a0;

    temp_v0 = gPrevLoadedAddress;
    temp_a0 = temp_v0 + arg2;
    arg1 = ALIGN16(arg1);
    arg2 = ALIGN16(arg2);
    osInvalDCache(temp_a0, arg1);
    osPiStartDma(&gDmaIoMesg, 0, 0, &_other_texturesSegmentRomStart[arg0 & 0xFFFFFF], temp_a0, arg1, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, (int) 1);
    mio0decode(temp_a0, temp_v0);
    gPrevLoadedAddress += arg2;
    return temp_v0;
}

u32 MIO0_0F(s32 arg0, u32 arg1, u32 arg2) {
    u32 oldHeapEndPtr;
    u8 *temp_v0;
    u32 temp_a0;

    arg1 = ALIGN16(arg1);
    arg2 = ALIGN16(arg2);
    oldHeapEndPtr = gHeapEndPtr;
    temp_v0 = gPrevLoadedAddress;

    osInvalDCache(temp_v0, arg1);
    osPiStartDma(&gDmaIoMesg, 0, 0, &_other_texturesSegmentRomStart[arg0 & 0xFFFFFF], temp_v0, arg1, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, 1);
    mio0decode(temp_v0, oldHeapEndPtr);
    gHeapEndPtr += arg2;
    return oldHeapEndPtr;
}

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern f32 D_800DC608;
// 802A86C0, 00000010
struct UnkStruct_802A86A8 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;

};

void func_802A86A8(struct UnkStruct_802A86A8 *arg0, u32 arg1) {
    s8 temp_a0;
    s8 temp_a3;
    u32 temp_a2;
    struct UnkStruct_802A86A8  *temp_v0;
    u32 temp_v1;
    struct UnkStruct_802A86A8 *temp_v1_2;
    struct UnkStruct_802A86A8 *phi_v0;
    s8 phi_v1;
    u32 phi_a2;

    temp_v1 = gHeapEndPtr - (((arg1 * 0x10) + 0xF) & ~0xF);
    gHeapEndPtr = temp_v1;
    phi_v0 = arg0;
    phi_a2 = 0; 
    // phi_v1 = temp_v1;
  
         
    if (arg1 != 0) {
        do {
            if (gIsMirrorMode != 0) {
                phi_v1 = -phi_v0->unk0;
            } else {
                phi_v1 = phi_v0->unk0;
            }
            temp_a2 = phi_a2 + 1;
            temp_v1_2 = phi_v1 + 0x10;
            temp_v0 = phi_v0 + 0xE;
            temp_v1_2->unkE = phi_v0->unk2 * D_800DC608;
            temp_a0 = temp_v0->unk4;
            temp_a3 = temp_v0->unk3;
            temp_v1_2->unkC = temp_v0->unkA;
            temp_v1_2->unk8 = temp_v0->unk8;
            temp_v1_2->unk4 = temp_a0 & 0xFC;
            temp_v1_2->unk3 = temp_a3 & 0xFC;
            temp_v1_2->unk6 = temp_v0->unk6;
            temp_v1_2->unk2 = temp_v0->unk2;
            temp_v1_2->unkA = (temp_a0 & 3) | ((temp_a3 * 4) & 0xC);
            temp_v1_2->unk1 = 0xFF;
            phi_v0 = temp_v0;
            // phi_v1 = temp_v1_2;
            phi_a2 = temp_a2;
        } while (temp_a2 < arg1);
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A86A8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
//? func_802A86A8(u8 *, s32); // extern
void func_802A87A8(s32 arg0, u32 arg1) {
    //u8 *sp18;
    u8 temp_v0;
    u32 endptr;
    u32 *addr;

    temp_v0 = ALIGN16(arg1 * 0x18);
    gPrevLoadedAddress += temp_v0;
    addr = VIRTUAL_TO_PHYSICAL2(&gSegmentTable[((arg0 >> 0x18) * 4)] + arg0);
    // &gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000
    //sp18 = temp_v0;
    mio0decode(addr, temp_v0);
    func_802A86A8(temp_v0, arg1);
    endptr = gHeapEndPtr;
    set_segment_base_addr(4, endptr);
}

UNUSED void func_802A8844(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A87A8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8CE8;
extern s32 D_802BA270;

void func_802A884C(s32 arg0, ? arg1, s8 arg2) {
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t3;
    s32 temp_t4;
    s32 temp_v0;

    sp->unk0 = D_802B8CE8.unk0;
    sp->unk4 = D_802B8CE8.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    temp_t2 = D_802BA270 + 1;
    temp_t3 = temp_t2 * 8;
    D_802BA270 = temp_t2;
    *(arg0 + temp_t3) = 0x3860010;
    temp_v0 = arg2 * 0x18;
    (arg0 + (D_802BA270 * 8))->unk4 = temp_v0 + 0x9000008;
    temp_t2_2 = D_802BA270 + 1;
    temp_t4 = temp_t2_2 * 8;
    D_802BA270 = temp_t2_2;
    *(arg0 + temp_t4) = 0x3880010;
    (arg0 + (D_802BA270 * 8))->unk4 = temp_v0 + 0x9000000;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A884C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;
extern s32 D_802BA274;

void func_802A8940(s32 arg0, s32 arg1, ? arg2) {
    s32 temp_t7;
    s32 temp_v1;
    u8 temp_v0;

    temp_v1 = D_802BA274;
    temp_t7 = temp_v1 + 1;
    temp_v0 = *(temp_v1 + arg1);
    D_802BA274 = temp_t7;
    D_802BA274 = temp_t7 + 1;
    *(arg0 + (D_802BA270 * 8)) = 0x6000000;
    (arg0 + (D_802BA270 * 8))->unk4 = (((*(temp_t7 + arg1) << 8) | temp_v0) * 8) + 0x7000000;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8940.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;

void func_802A89C0(s32 arg0, ? arg1, ? arg2) {
    *(arg0 + (D_802BA270 * 8)) = 0xB8000000;
    (arg0 + (D_802BA270 * 8))->unk4 = 0;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A89C0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8CF0;
extern s32 D_802BA270;

void func_802A8A04(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8CF0.unk0;
    sp->unk4 = D_802B8CF0.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8A04.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8CF8;
extern s32 D_802BA270;

void func_802A8A70(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8CF8.unk0;
    sp->unk4 = D_802B8CF8.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8A70.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D00;
extern s32 D_802BA270;

void func_802A8ADC(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D00.unk0;
    sp->unk4 = D_802B8D00.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8ADC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D08;
extern s32 D_802BA270;

void func_802A8B48(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D08.unk0;
    sp->unk4 = D_802B8D08.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8B48.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D10;
extern s32 D_802BA270;

void func_802A8BB4(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D10.unk0;
    sp->unk4 = D_802B8D10.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8BB4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D18;
extern s32 D_802BA270;

void func_802A8C20(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D18.unk0;
    sp->unk4 = D_802B8D18.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8C20.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D20;
extern s32 D_802BA270;

void func_802A8C8C(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D20.unk0;
    sp->unk4 = D_802B8D20.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8C8C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D28;
extern s32 D_802BA270;

void func_802A8CF8(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D28.unk0;
    sp->unk4 = D_802B8D28.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8CF8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D30;
extern s32 D_802BA270;

void func_802A8D64(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D30.unk0;
    sp->unk4 = D_802B8D30.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8D64.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D38;
extern s32 D_802BA270;

void func_802A8DD0(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D38.unk0;
    sp->unk4 = D_802B8D38.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8DD0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D40;
extern s32 D_802BA270;

void func_802A8E3C(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D40.unk0;
    sp->unk4 = D_802B8D40.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8E3C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D48;
extern s32 D_802BA270;

void func_802A8EA8(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D48.unk0;
    sp->unk4 = D_802B8D48.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8EA8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D50;
extern s32 D_802BA270;

void func_802A8F14(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D50.unk0;
    sp->unk4 = D_802B8D50.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8F14.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit bd0364fa19633bd6201f8007e2d0a7ed87825909
static ? D_802B8D58;                                /* unable to generate initializer */

void func_802A8F80(s32 arg0, s32 arg1, s8 arg2) {
    s32 sp58;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_a1;
    s32 temp_t5;
    s32 temp_t8;
    s32 temp_t9;
    u8 temp_a0;
    u8 temp_a0_2;
    s32 phi_v1;
    s32 phi_v0;

    sp58.unk0 = D_802B8D58.unk0;
    sp58.unk4 = D_802B8D58.unk4;
    phi_v0 = 0;
    phi_v0 = 0;
    switch (arg2) {
    case 26:
        sp44 = 0x20;
        sp40 = 0;
        phi_v1 = 0x20;
block_9:
        sp48 = phi_v1;
        break;
    case 44:
        sp44 = 0x20;
        sp40 = 0;
        phi_v1 = 0x20;
        phi_v0 = 0x100;
        goto block_9;
    case 27:
        sp44 = 0x20;
        sp40 = 0;
        phi_v1 = 0x40;
        goto block_9;
    case 28:
        sp44 = 0x40;
        sp40 = 0;
        phi_v1 = 0x20;
        goto block_9;
    case 29:
        sp44 = 0x20;
        sp40 = 3;
        phi_v1 = 0x20;
        goto block_9;
    case 30:
        sp44 = 0x20;
        sp40 = 3;
        phi_v1 = 0x40;
        goto block_9;
    case 31:
        sp44 = 0x40;
        sp40 = 3;
        phi_v1 = 0x20;
        goto block_9;
    }
    temp_a1 = D_802BA274;
    temp_a0 = *(temp_a1 + arg1);
    temp_t9 = temp_a1 + 1;
    D_802BA274 = temp_t9;
    temp_a0_2 = *(temp_t9 + arg1);
    D_802BA274 = temp_t9 + 1;
    *(arg0 + (D_802BA270 * 8)) = sp58;
    (arg0 + (D_802BA270 * 8))->unk4 = sp5C;
    D_802BA270 += 1;
    *(arg0 + (D_802BA270 * 8)) = (sp40 << 0x15) | 0xF5000000 | 0x100000 | ((((sp48 * 2) + 7) >> 3) << 9) | phi_v0;
    (arg0 + (D_802BA270 * 8))->unk4 = ((temp_a0_2 & 0xF) << 0x12) | (((temp_a0_2 & 0xF0) >> 4) << 0xE) | ((temp_a0 & 0xF) << 8) | (((temp_a0 & 0xF0) >> 4) * 0x10);
    temp_t5 = D_802BA270 + 1;
    temp_t8 = temp_t5 * 8;
    D_802BA270 = temp_t5;
    *(arg0 + temp_t8) = 0xF2000000;
    (arg0 + (D_802BA270 * 8))->unk4 = ((sp48 - 1) << 0xE) | ((sp44 - 1) * 4);
    D_802BA270 += 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A8F80.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit bd0364fa19633bd6201f8007e2d0a7ed87825909
static ? D_802B8D60;                                /* unable to generate initializer */
static ? D_802B8D68;                                /* unable to generate initializer */

void func_802A91E4(s32 arg0, s32 arg1, s8 arg2) {
    s32 sp48;
    s32 sp40;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_t1;
    s32 temp_t6;
    s32 temp_t6_2;
    s32 temp_t8;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 temp_v1;
    u32 temp_t2;
    u32 temp_t6_3;
    u8 temp_a2;
    u8 temp_a3;
    s32 phi_v0;
    u32 phi_v0_2;
    u32 phi_a2;
    u32 phi_v1;

    sp48.unk0 = D_802B8D60.unk0;
    sp48.unk4 = D_802B8D60.unk4;
    sp40.unk0 = D_802B8D68.unk0;
    sp40.unk4 = D_802B8D68.unk4;
    switch (arg2) {
    case 32:
        sp28 = 0x20;
        sp24 = 0;
        phi_v0 = 0x20;
block_8:
        sp2C = phi_v0;
        break;
    case 33:
        sp28 = 0x20;
        sp24 = 0;
        phi_v0 = 0x40;
        goto block_8;
    case 34:
        sp28 = 0x40;
        sp24 = 0;
        phi_v0 = 0x20;
        goto block_8;
    case 35:
        sp28 = 0x20;
        sp24 = 3;
        phi_v0 = 0x20;
        goto block_8;
    case 36:
        sp28 = 0x20;
        sp24 = 3;
        phi_v0 = 0x40;
        goto block_8;
    case 37:
        sp28 = 0x40;
        sp24 = 3;
        phi_v0 = 0x20;
        goto block_8;
    }
    temp_v1 = D_802BA274;
    temp_a2 = *(arg1 + temp_v1);
    temp_t9 = temp_v1 + 1;
    D_802BA274 = temp_t9;
    temp_t8 = temp_t9 + 1;
    D_802BA274 = temp_t8;
    temp_a3 = *(temp_t8 + arg1);
    D_802BA274 = temp_t8 + 1;
    temp_t6 = sp24 << 0x15;
    *(arg0 + (D_802BA270 * 8)) = temp_t6 | 0xFD000000 | 0x100000;
    (arg0 + (D_802BA270 * 8))->unk4 = (temp_a2 << 0xB) + 0x5000000;
    temp_t9_2 = D_802BA270 + 1;
    D_802BA270 = temp_t9_2;
    *(arg0 + (temp_t9_2 * 8)) = sp48;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4C;
    D_802BA270 += 1;
    *(arg0 + (D_802BA270 * 8)) = temp_t6 | 0xF5000000 | 0x100000 | (temp_a3 & 0xF);
    temp_t1 = ((temp_a3 & 0xF0) >> 4) << 0x18;
    (arg0 + (D_802BA270 * 8))->unk4 = temp_t1;
    temp_t6_2 = D_802BA270 + 1;
    D_802BA270 = temp_t6_2;
    *(arg0 + (temp_t6_2 * 8)) = sp40;
    (arg0 + (D_802BA270 * 8))->unk4 = sp44;
    temp_t6_3 = (sp2C * 2) >> 3;
    D_802BA270 += 1;
    temp_t2 = (sp2C * sp28) - 1;
    phi_v1 = 0x7FF;
    if (temp_t2 < 0x7FF) {
        phi_v1 = temp_t2;
    }
    if (temp_t6_3 == 0) {
        phi_v0_2 = 1;
    } else {
        phi_v0_2 = temp_t6_3;
    }
    phi_a2 = temp_t6_3;
    if (temp_t6_3 == 0) {
        phi_a2 = 1;
    }
    *(arg0 + (D_802BA270 * 8)) = 0xF3000000;
    (arg0 + (D_802BA270 * 8))->unk4 = ((phi_v0_2 + 0x7FF) / phi_a2) | temp_t1 | (phi_v1 << 0xC);
    D_802BA270 += 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A91E4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D70;
extern s32 D_802BA270;

void func_802A94D8(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D70.unk0;
    sp->unk4 = D_802B8D70.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A94D8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_802B8D78;
extern s32 D_802BA270;

void func_802A9544(s32 arg0, ? arg1, ? arg2) {
    sp->unk0 = D_802B8D78.unk0;
    sp->unk4 = D_802B8D78.unk4;
    *(arg0 + (D_802BA270 * 8)) = sp0;
    (arg0 + (D_802BA270 * 8))->unk4 = sp4;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A9544.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;
extern s32 D_802BA274;

void func_802A95B0(s32 arg0, s32 arg1, ? arg2) {
    s32 temp_t5;
    s32 temp_t7;
    s32 temp_t7_2;
    s32 temp_v1;
    u8 temp_v0;

    temp_v1 = D_802BA274;
    temp_t7 = temp_v1 + 1;
    temp_v0 = *(temp_v1 + arg1);
    D_802BA274 = temp_t7;
    temp_t5 = temp_t7 + 1;
    D_802BA274 = temp_t5;
    temp_t7_2 = temp_t5 + 1;
    D_802BA274 = temp_t7_2;
    D_802BA274 = temp_t7_2 + 1;
    *(arg0 + (D_802BA270 * 8)) = ((*(temp_t7_2 + arg1) & 0x3F) << 0x11) | 0x4000000 | (((*(temp_t5 + arg1) & 0x3F) * 0x410) - 1);
    (arg0 + (D_802BA270 * 8))->unk4 = (((*(temp_t7 + arg1) << 8) | temp_v0) * 0x10) + 0x4000000;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A95B0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;
extern s32 D_802BA274;

void func_802A9674(s32 arg0, s32 arg1, s8 arg2) {
    s32 temp_t9;
    s32 temp_v1;
    u8 temp_v0;

    temp_v1 = D_802BA274;
    temp_t9 = temp_v1 + 1;
    temp_v0 = *(temp_v1 + arg1);
    D_802BA274 = temp_t9;
    D_802BA274 = temp_t9 + 1;
    *(arg0 + (D_802BA270 * 8)) = (((arg2 - 0x32) * 0x410) - 1) | 0x4000000;
    (arg0 + (D_802BA270 * 8))->unk4 = (((*(temp_t9 + arg1) << 8) | temp_v0) * 0x10) + 0x4000000;
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A9674.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;
extern s32 D_802BA274;

void func_802A9714(s32 arg0, s32 arg1, ? arg2) {
    s32 temp_t7;
    s32 temp_v1;
    s32 temp_v1_2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    s32 phi_a3;
    s32 phi_a2;
    s32 phi_a0;

    temp_v1 = D_802BA274;
    temp_v0 = *(temp_v1 + arg1);
    temp_t7 = temp_v1 + 1;
    D_802BA274 = temp_t7;
    phi_a3 = temp_v0 & 0x1F;
    phi_a0 = temp_v0 & 0x1F;
    if (gIsMirrorMode != 0) {
        temp_v0_2 = *(temp_t7 + arg1);
        D_802BA274 = temp_t7 + 1;
        phi_a3 = (temp_v0_2 >> 2) & 0x1F;
        phi_a2 = ((temp_v0 >> 5) & 7) | ((temp_v0_2 & 3) * 8);
    } else {
        temp_v1_2 = D_802BA274;
        temp_v0_3 = *(temp_v1_2 + arg1);
        D_802BA274 = temp_v1_2 + 1;
        phi_a2 = ((temp_v0 >> 5) & 7) | ((temp_v0_3 & 3) * 8);
        phi_a0 = (temp_v0_3 >> 2) & 0x1F;
    }
    *(arg0 + (D_802BA270 * 8)) = 0xBF000000;
    (arg0 + (D_802BA270 * 8))->unk4 = (phi_a3 << 0x11) | (phi_a2 << 9) | (phi_a0 * 2);
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A9714.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;
extern s32 D_802BA274;

void func_802A980C(s32 arg0, s32 arg1, ? arg2) {
    s32 temp_a2;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v0_6;
    s32 phi_t0;
    s32 phi_a3;
    s32 phi_a0;
    s32 phi_t2;
    s32 phi_t1;
    s32 phi_a2;

    temp_v1 = D_802BA274;
    temp_v0 = *(temp_v1 + arg1);
    temp_t7 = temp_v1 + 1;
    D_802BA274 = temp_t7;
    temp_a2 = gIsMirrorMode;
    phi_t0 = temp_v0 & 0x1F;
    phi_a0 = temp_v0 & 0x1F;
    if (temp_a2 != 0) {
        temp_v0_2 = *(temp_t7 + arg1);
        D_802BA274 = temp_t7 + 1;
        phi_t0 = (temp_v0_2 >> 2) & 0x1F;
        phi_a3 = ((temp_v0 >> 5) & 7) | ((temp_v0_2 & 3) * 8);
    } else {
        temp_v1_2 = D_802BA274;
        temp_v0_3 = *(temp_v1_2 + arg1);
        D_802BA274 = temp_v1_2 + 1;
        phi_a3 = ((temp_v0 >> 5) & 7) | ((temp_v0_3 & 3) * 8);
        phi_a0 = (temp_v0_3 >> 2) & 0x1F;
    }
    temp_v1_3 = D_802BA274;
    temp_v0_4 = *(temp_v1_3 + arg1);
    temp_t9 = temp_v1_3 + 1;
    D_802BA274 = temp_t9;
    if (temp_a2 != 0) {
        temp_v0_5 = *(temp_t9 + arg1);
        D_802BA274 = temp_t9 + 1;
        phi_t2 = (temp_v0_5 >> 2) & 0x1F;
        phi_t1 = ((temp_v0_4 >> 5) & 7) | ((temp_v0_5 & 3) * 8);
        phi_a2 = temp_v0_4 & 0x1F;
    } else {
        temp_v1_4 = D_802BA274;
        temp_v0_6 = *(temp_v1_4 + arg1);
        temp_t8 = (temp_v0_6 & 3) * 8;
        temp_t9_2 = (temp_v0_6 >> 2) & 0x1F;
        D_802BA274 = temp_v1_4 + 1;
        phi_t2 = temp_v0_4 & 0x1F;
        phi_t1 = ((temp_v0_4 >> 5) & 7) | temp_t8;
        phi_a2 = temp_t9_2;
    }
    *(arg0 + (D_802BA270 * 8)) = (phi_t0 << 0x11) | 0xB1000000 | (phi_a3 << 9) | (phi_a0 * 2);
    (arg0 + (D_802BA270 * 8))->unk4 = (phi_t2 << 0x11) | (phi_t1 << 9) | (phi_a2 * 2);
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A980C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802BA270;
extern s32 D_802BA274;

void func_802A99A4(s32 arg0, s32 arg1, ? arg2) {
    s32 temp_t3;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_v1;
    s32 temp_v1_2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    s32 phi_a0;
    s32 phi_t0;
    s32 phi_a3;
    s32 phi_a2;

    temp_v1 = D_802BA274;
    temp_v0 = *(temp_v1 + arg1);
    temp_t7 = temp_v1 + 1;
    D_802BA274 = temp_t7;
    phi_a0 = temp_v0 & 0x1F;
    phi_t0 = temp_v0 & 0x1F;
    if (gIsMirrorMode != 0) {
        temp_v0_2 = *(temp_t7 + arg1);
        temp_t3 = temp_t7 + 1;
        D_802BA274 = temp_t3;
        D_802BA274 = temp_t3 + 1;
        phi_t0 = ((temp_v0_2 >> 7) & 1) | ((*(temp_t3 + arg1) & 0xF) * 2);
        phi_a3 = (temp_v0_2 >> 2) & 0x1F;
        phi_a2 = ((temp_v0 >> 5) & 7) | ((temp_v0_2 & 3) * 8);
    } else {
        temp_v1_2 = D_802BA274;
        temp_v0_3 = *(temp_v1_2 + arg1);
        temp_t6 = temp_v1_2 + 1;
        D_802BA274 = temp_t6;
        D_802BA274 = temp_t6 + 1;
        phi_a0 = ((temp_v0_3 >> 7) & 1) | ((*(temp_t6 + arg1) & 0xF) * 2);
        phi_a3 = ((temp_v0 >> 5) & 7) | ((temp_v0_3 & 3) * 8);
        phi_a2 = (temp_v0_3 >> 2) & 0x1F;
    }
    *(arg0 + (D_802BA270 * 8)) = 0xB5000000;
    (arg0 + (D_802BA270 * 8))->unk4 = (phi_a0 << 0x19) | (phi_t0 << 0x11) | (phi_a3 << 9) | (phi_a2 * 2);
    D_802BA270 = D_802BA270 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802A99A4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit bd0364fa19633bd6201f8007e2d0a7ed87825909
? func_802A884C(s32, s32, s8, s32 *);               /* extern */
? func_802A8940(s32, s32, s8, s32 *);               /* extern */
? func_802A89C0(s32, s32, s8, s32 *);               /* extern */
? func_802A8A04(s32, s32, s8, s32 *);               /* extern */
? func_802A8A70(s32, s32, s8, s32 *);               /* extern */
? func_802A8ADC(s32, s32, s8, s32 *);               /* extern */
? func_802A8B48(s32, s32, s32, s32 *);              /* extern */
? func_802A8BB4(s32, s32, s32, s32 *);              /* extern */
? func_802A8C20(s32, s32, s32, s32 *);              /* extern */
? func_802A8C8C(s32, s32, s32, s32 *);              /* extern */
? func_802A8CF8(s32, s32, s32, s32 *);              /* extern */
? func_802A8D64(s32, s32, s32, s32 *);              /* extern */
? func_802A8DD0(s32, s32, s32, s32 *);              /* extern */
? func_802A8E3C(s32, s32, s32, s32 *);              /* extern */
? func_802A8EA8(s32, s32, s32, s32 *);              /* extern */
? func_802A8F14(s32, s32, s32, s32 *);              /* extern */
? func_802A8F80(s32, s32, s8, s32 *);               /* extern */
? func_802A91E4(s32, s32, s8, s32 *);               /* extern */
? func_802A94D8(s32, s32, s8, s32 *);               /* extern */
? func_802A9544(s32, s32, s8, s32 *);               /* extern */
? func_802A95B0(s32, s32, s8, s32 *);               /* extern */
? func_802A9674(s32, s32, s8, s32 *);               /* extern */
? func_802A9714(s32, s32, s8, s32 *);               /* extern */
? func_802A980C(s32, s32, s8, s32 *);               /* extern */
? func_802A99A4(s32, s32, s8, s32 *);               /* extern */
? set_segment_base_addr(?, s32);                    /* extern */

void display_list_unpack(u32 arg0, s32 arg1, s32 arg2) {
    s32 sp2C;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v1;
    u8 temp_a0;
    s32 *phi_a3;

    temp_s0 = gSegmentTable[arg0 >> 0x18] + (arg0 & 0xFFFFFF) + 0x80000000;
    temp_s1 = gHeapEndPtr - (((arg1 + 0xF) & ~0xF) + 8);
    gHeapEndPtr = temp_s1;
    D_802BA270 = 0;
    sp2C = temp_s1;
    D_802BA274 = 0;
    phi_a3 = &D_802BA274;
loop_1:
    temp_v1 = *phi_a3;
    temp_a0 = *(temp_v1 + temp_s0);
    *phi_a3 = temp_v1 + 1;
    if (temp_a0 != 0xFF) {
        switch (temp_a0) {
        case 0x0:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x5:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x6:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x7:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x8:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x9:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0xA:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0xB:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0xC:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0xD:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0xE:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0xF:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x10:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x11:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x12:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x13:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x14:
            func_802A884C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x15:
            func_802A8B48(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x16:
            func_802A8BB4(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x17:
            func_802A8C20(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2E:
            func_802A8C8C(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x53:
            func_802A8CF8(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x18:
            func_802A8D64(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x19:
            func_802A8DD0(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2F:
            func_802A8E3C(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x54:
            func_802A8EA8(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x55:
            func_802A8F14(temp_s1, temp_s0, arg2, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1A:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2C:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1B:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1C:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1D:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1E:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x1F:
            func_802A8F80(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x20:
            func_802A91E4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x21:
            func_802A91E4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x22:
            func_802A91E4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x23:
            func_802A91E4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x24:
            func_802A91E4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x25:
            func_802A91E4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x26:
            func_802A94D8(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x27:
            func_802A9544(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x28:
            func_802A95B0(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x33:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x34:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x35:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x36:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x37:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x38:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x39:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3A:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3B:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3C:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3D:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3E:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x3F:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x40:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x41:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x42:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x43:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x44:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x45:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x46:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x47:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x48:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x49:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4A:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4B:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4C:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4D:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4E:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x4F:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x50:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x51:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x52:
            func_802A9674(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x29:
            func_802A9714(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x58:
            func_802A980C(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x30:
            func_802A99A4(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2D:
            func_802A8ADC(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2A:
            func_802A89C0(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x56:
            func_802A8A04(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x57:
            func_802A8A70(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        case 0x2B:
            func_802A8940(temp_s1, temp_s0, temp_a0, phi_a3);
            phi_a3 = &D_802BA274;
            break;
        }
        goto loop_1;
    }
    set_segment_base_addr(7, sp2C);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/display_list_unpack.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? MIO0_0F(s32, s32, s32); // extern
extern ? gSegmentTable;

void func_802AA7C8(u32 arg0) {
    void *sp20;
    s32 temp_a0;
    void *temp_s0;
    void *temp_t2;
    void *phi_s0;
    s32 phi_v0;
    void *phi_s0_2;

    temp_s0 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
    phi_s0 = temp_s0;
    phi_v0 = 0;
loop_1:
    if (phi_s0->unk0 != 0) {
        phi_s0 += 0x10;
        phi_v0 += phi_s0->unk8;
        goto loop_1;
    }
    temp_t2 = gHeapEndPtr - phi_v0;
    gHeapEndPtr = temp_t2;
    sp20 = temp_t2;
    phi_s0_2 = temp_s0;
loop_4:
    temp_a0 = phi_s0_2->unk0;
    if (temp_a0 != 0) {
        MIO0_0F(temp_a0, phi_s0_2->unk4, phi_s0_2->unk8);
        phi_s0_2 += 0x10;
        goto loop_4;
    }
    gHeapEndPtr = sp20;
    set_segment_base_addr(5, sp20);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AA7C8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? dma_copy(u8 *, s32, s32, s32); // extern
extern u8 *gPrevLoadedAddress;

s32 func_802AA88C(s32 arg0, s32 arg1) {
    s32 sp28;
    u8 *sp20;
    u8 *sp1C;
    s32 temp_t6;
    u8 *temp_a0;
    u8 *temp_a1;

    temp_t6 = ((arg1 - arg0) + 0xF) & ~0xF;
    temp_a0 = gHeapEndPtr - temp_t6;
    sp20 = temp_a0;
    dma_copy(temp_a0, arg0, temp_t6, arg1);
    temp_a1 = gPrevLoadedAddress;
    sp1C = temp_a1;
    sp28 = (temp_a0->unk4 + 0xF) & ~0xF;
    mio0decode(temp_a0, temp_a1);
    gPrevLoadedAddress = &gPrevLoadedAddress[sp28];
    return sp1C;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AA88C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? display_list_unpack(u32 *, u32 *, s32); // extern
s32 func_802A7D70(u32 *, u32 *, u32 *); // extern
s32 func_802A82E4(u32 *, u32 *); // extern
? func_802A87A8(mk64_Vtx *, u32); // extern
? func_802AA7C8(u32 *); // extern
extern s32 gPrevLoadedAddress;

void load_course(s32 arg0) {
    s32 sp4C;
    u32 *sp48;
    u32 *sp44;
    u32 *sp40;
    u32 *sp3C;
    u32 *sp30;
    mk64_Vtx *sp2C;
    u32 *sp28;
    u32 sp24;
    u32 *sp20;
    s32 sp1C;
    s32 sp18;
    s32 temp_v0_2;
    s32 temp_v1;
    struct courseTable *temp_v0;
    u32 *temp_a2;

    temp_v0 = &gCourseTable[arg0];
    temp_v1 = D_800DC50C;
    temp_a2 = temp_v0->offsetRomStart;
    sp48 = temp_v0->dlRomStart;
    sp44 = temp_v0->dlRomEnd;
    sp40 = temp_v0->vertexRomStart;
    sp3C = temp_v0->vertexRomEnd;
    sp30 = temp_v0->textures;
    sp2C = temp_v0->vertexStart;
    sp28 = temp_v0->packedStart;
    sp24 = temp_v0->vertexCount;
    sp20 = temp_v0->finalDL;
    sp1C = temp_v0->unknown1;
    if ((temp_v1 == 5) || (temp_v1 == 9)) {
        gHeapEndPtr = 0x80280000;
    } else {
        gHeapEndPtr = 0x8028DF00;
    }
    set_segment_base_addr(9, func_802A7D70(temp_a2, temp_v0->offsetRomEnd, temp_a2));
    if (D_800DC50C != 5) {
        set_segment_base_addr(6, func_802AA88C(sp48, sp44));
    }
    sp18 = gPrevLoadedAddress;
    temp_v0_2 = func_802A82E4(sp40, sp3C);
    sp4C = temp_v0_2;
    set_segment_base_addr(0xF, temp_v0_2);
    func_802A87A8(sp2C, sp24);
    display_list_unpack(sp28, sp20, sp1C);
    func_802AA7C8(sp30);
    gPrevLoadedAddress = sp18;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/load_course.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? gSegmentTable;

void func_802AAA70(u32 arg0) {
    void *temp_v0;

    temp_v0 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
    temp_v0->unk0 = 0xB8000000;
    temp_v0->unk4 = 0;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AAA70.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? load_giant_egg(void *, ?, ?, ?); // extern

void func_802AAAAC(void *arg0) {
    void *temp_a0;

    arg0->unk6 = 0x1388;
    arg0->unk8 = 0x1388;
    arg0->unkA = 0x1388;
    arg0->unk0 = 0;
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    temp_a0 = arg0 + 0x18;
    temp_a0->unk-C = 0.0f;
    temp_a0->unk-8 = 0.0f;
    temp_a0->unk-4 = 0.0f;
    load_giant_egg(temp_a0, 0, 0, 0x3F800000);
    load_giant_egg(arg0 + 0x24, 0x3F800000, 0, 0);
    load_giant_egg(arg0 + 0x30, 0, 0x3F800000, 0);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AAAAC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802ABD10(u16, void *); // extern
s32 func_802ABD40(u16, void *); // extern
extern f32 D_802B9E00;
extern f32 D_802B9E04;
extern f32 D_802B9E08;
extern f32 D_802B9E0C;
extern f32 D_802B9E10;
extern f32 D_802B9E14;
extern f32 D_802B9E18;
extern f32 D_802B9E1C;
extern f32 D_802B9E20;
extern f32 D_802B9E24;
extern f32 D_802B9E28;
extern f32 D_802B9E2C;
extern f32 D_802B9E30;
extern f32 D_802B9E34;
extern f32 D_802B9E38;
extern f32 D_802B9E3C;
extern f32 D_802B9E40;
extern f32 D_802B9E44;

f32 func_802AAB4C(void *arg0) {
    f32 sp1C;
    f32 sp18;
    f32 temp_f0;
    f32 temp_f2;
    s16 temp_v0;
    s32 temp_v1;
    u16 temp_a0;
    void *temp_a1;

    temp_v0 = gCurrentCourseId;
    temp_a1 = arg0;
    temp_f0 = arg0->unk14;
    temp_f2 = arg0->unk1C;
    if (temp_v0 != 2) {
        if (temp_v0 != 6) {
            if (temp_v0 != 0xC) {
                if (temp_v0 != 0x12) {
                    goto block_43;
                }
                temp_a0 = temp_a1->unk11A;
                sp18 = temp_f2;
                sp1C = temp_f0;
                arg0 = temp_a1;
                temp_v1 = func_802ABD40(temp_a0, temp_a1) & 0xFF;
                if (temp_v1 == 0xFF) {
                    sp18 = temp_f2;
                    sp1C = temp_f0;
                    if ((func_802ABD10(arg0->unk11A, arg0) & 0xFF) == 0xF) {
                        return D_802B9E1C;
                    }
                    if (temp_f0 > -478.0f) {
                        return D_802B9E20;
                    }
                    if (temp_f0 < D_802B9E24) {
                        return D_802B9E28;
                    }
                    if (temp_f2 > -436.0f) {
                        return D_802B9E2C;
                    }
                    if (temp_f2 < D_802B9E30) {
                        return D_802B9E34;
                    }
                    if (temp_f2 < temp_f0) {
                        return D_802B9E38;
                    }
                    return D_802B9E3C;
                }
                if (temp_v1 >= 0x14) {
                    return D_802B9E40;
                }
                return D_802B9E44;
            }
            if ((func_802ABD10(temp_a1->unk11A, temp_a1) & 0xFF) == 5) {
                return D_8015F6EE - 0xA;
            }
            goto block_43;
        }
        if (temp_f0 > 239.0f) {
            goto block_43;
        }
        if (temp_f0 < 67.0f) {
            goto block_43;
        }
        if (D_802B9E10 < temp_f2) {
            goto block_43;
        }
        if (temp_f2 < D_802B9E14) {
            goto block_43;
        }
        return D_802B9E18;
    }
    if (D_802B9E00 < temp_f0) {
        goto block_43;
    }
    if (temp_f0 < D_802B9E04) {
        goto block_43;
    }
    if (D_802B9E08 < temp_f2) {
        goto block_43;
    }
    if (temp_f2 < D_802B9E0C) {
block_43:
        return D_8015F8E4;
    }
    return 20.0f;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AAB4C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern f32 D_802B9E48;

s32 func_802AAE4C(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5) {
    f32 sp6C;
    f32 sp64;
    f32 sp3C;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f4;
    f32 temp_f8;
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;
    void *temp_v1;
    s32 phi_v0;
    f32 phi_f18;
    s32 phi_v0_2;

    temp_v1 = (arg5 * 0x2C) + D_8015F580;
    temp_f0 = temp_v1->unk20;
    phi_v0 = 1;
    phi_v0_2 = 1;
    if (temp_f0 < D_802B9E48) {
        return 0;
    }
    if (arg2 < temp_v1->unk4) {
        return 0;
    }
    if (arg4 < temp_v1->unk8) {
        return 0;
    }
    if (temp_v1->unkA < arg2) {
        return 0;
    }
    if (temp_v1->unkE < arg4) {
        return 0;
    }
    sp2C = temp_f0;
    arg2 = arg2;
    if (arg3 < (temp_v1->unk6 - (arg1 * 3.0f))) {
        return 0;
    }
    temp_a0 = temp_v1->unk10;
    temp_a3 = temp_v1->unk18;
    temp_a2 = temp_v1->unk14;
    sp6C = temp_a3->unk0;
    sp8 = arg4;
    sp10 = arg2;
    temp_f8 = temp_a0->unk4 - arg4;
    sp64 = temp_a3->unk4;
    temp_f4 = temp_a2->unk0 - arg2;
    sp28 = temp_f8;
    sp24 = temp_f4;
    sp20 = temp_a0->unk0 - arg2;
    temp_f0_2 = temp_f8 * temp_f4;
    sp8 = temp_f8;
    spC = temp_f4;
    sp1C = temp_a2->unk4 - arg4;
    temp_f2 = sp20 * sp1C;
    temp_f10 = temp_f0_2 - temp_f2;
    sp18 = temp_f10;
    sp3C = temp_f10;
    if (temp_f2 == temp_f0_2) {
        sp14 = arg4;
        temp_f0_3 = sp6C - sp10;
        temp_f2_2 = sp64 - arg4;
        phi_f18 = 0.0f;
        if ((((sp1C * temp_f0_3) - (spC * temp_f2_2)) * ((temp_f2_2 * sp20) - (temp_f0_3 * sp8))) < 0.0f) {
            goto block_22;
        }
    } else {
        temp_f2_3 = sp64 - arg4;
        temp_f0_4 = sp6C - arg2;
        temp_f14 = sp24 * temp_f2_3;
        temp_f12 = sp1C * temp_f0_4;
        if (temp_f14 == temp_f12) {
            phi_f18 = 0.0f;
            if ((sp3C * ((temp_f2_3 * sp20) - (temp_f0_4 * sp28))) < 0.0f) {
                goto block_22;
            }
        } else {
            temp_f16 = temp_f12 - temp_f14;
            if ((sp18 * temp_f16) < 0.0f) {
                goto block_22;
            }
            temp_f14_2 = temp_f0_4 * sp28;
            temp_f12_2 = temp_f2_3 * sp20;
            phi_f18 = 0.0f;
            if (temp_f14_2 != temp_f12_2) {
                phi_f18 = 0.0f;
                if ((temp_f16 * (temp_f12_2 - temp_f14_2)) < 0.0f) {
block_22:
                    phi_v0 = 0;
                    phi_f18 = 0.0f;
                }
            }
        }
    }
    if (phi_v0 == 0) {
        return 0;
    }
    temp_f0_5 = ((temp_v1->unk1C * arg2) + (sp2C * arg3) + (temp_v1->unk24 * arg4) + temp_v1->unk28) - arg1;
    if (phi_f18 < temp_f0_5) {
        if (temp_f0_5 < arg0->unk14) {
            arg0->unk4 = 1;
            arg0->unkA = arg5;
            arg0->unk14 = temp_f0_5;
            arg0->unk30 = temp_v1->unk1C;
            arg0->unk34 = temp_v1->unk20;
            arg0->unk38 = temp_v1->unk24;
        }
        return 0;
    }
    phi_v0_2 = 0;
    if (temp_f0_5 > -16.0f) {
        arg0->unk4 = 1;
        arg0->unkA = arg5;
        arg0->unk14 = temp_f0_5;
        arg0->unk30 = temp_v1->unk1C;
        arg0->unk34 = temp_v1->unk20;
        arg0->unk38 = temp_v1->unk24;
    }
    return phi_v0_2;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AAE4C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802AB288(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5) {
    f32 sp70;
    f32 sp6C;
    f32 sp3C;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;
    void *temp_v1;
    s32 phi_v0;
    f32 phi_f18;
    s32 phi_v0_2;

    temp_v1 = (arg5 * 0x2C) + D_8015F580;
    phi_v0 = 1;
    phi_v0_2 = 1;
    if (arg2 < temp_v1->unk4) {
        return 0;
    }
    if (temp_v1->unkA < arg2) {
        return 0;
    }
    if (temp_v1->unkC < arg3) {
        return 0;
    }
    if (arg3 < temp_v1->unk6) {
        return 0;
    }
    temp_f2 = arg1 * 3.0f;
    if (arg4 < (temp_v1->unk8 - temp_f2)) {
        return 0;
    }
    arg2 = arg2;
    arg3 = arg3;
    if ((temp_v1->unkE + temp_f2) < arg4) {
        return 0;
    }
    temp_a0 = temp_v1->unk10;
    temp_a3 = temp_v1->unk18;
    temp_a2 = temp_v1->unk14;
    sp70 = temp_a3->unk0;
    sp8 = arg3;
    sp10 = arg2;
    temp_f4 = temp_a0->unk2 - arg3;
    sp6C = temp_a3->unk2;
    temp_f8 = temp_a2->unk0 - arg2;
    sp2C = temp_f4;
    sp28 = temp_f8;
    sp24 = temp_a0->unk0 - arg2;
    temp_f0 = temp_f4 * temp_f8;
    sp8 = temp_f4;
    spC = temp_f8;
    sp20 = temp_a2->unk2 - arg3;
    temp_f2_2 = sp24 * sp20;
    temp_f6 = temp_f0 - temp_f2_2;
    sp1C = temp_f6;
    sp3C = temp_f6;
    if (temp_f2_2 == temp_f0) {
        sp14 = arg3;
        temp_f0_2 = sp70 - sp10;
        temp_f2_3 = sp6C - arg3;
        phi_f18 = 0.0f;
        if ((((sp20 * temp_f0_2) - (spC * temp_f2_3)) * ((temp_f2_3 * sp24) - (temp_f0_2 * sp8))) < 0.0f) {
            goto block_22;
        }
    } else {
        temp_f2_4 = sp6C - arg3;
        temp_f0_3 = sp70 - arg2;
        temp_f14 = sp28 * temp_f2_4;
        temp_f12 = sp20 * temp_f0_3;
        if (temp_f14 == temp_f12) {
            phi_f18 = 0.0f;
            if ((sp3C * ((temp_f2_4 * sp24) - (temp_f0_3 * sp2C))) < 0.0f) {
                goto block_22;
            }
        } else {
            temp_f16 = temp_f12 - temp_f14;
            if ((sp1C * temp_f16) < 0.0f) {
                goto block_22;
            }
            temp_f14_2 = temp_f0_3 * sp2C;
            temp_f12_2 = temp_f2_4 * sp24;
            phi_f18 = 0.0f;
            if (temp_f14_2 != temp_f12_2) {
                phi_f18 = 0.0f;
                if ((temp_f16 * (temp_f12_2 - temp_f14_2)) < 0.0f) {
block_22:
                    phi_v0 = 0;
                    phi_f18 = 0.0f;
                }
            }
        }
    }
    if (phi_v0 == 0) {
        return 0;
    }
    temp_f0_4 = ((temp_v1->unk1C * arg2) + (temp_v1->unk20 * arg3) + (temp_v1->unk24 * arg4) + temp_v1->unk28) - arg1;
    if (phi_f18 < temp_f0_4) {
        if (temp_f0_4 < arg0->unkC) {
            arg0->unk0 = 1;
            arg0->unk6 = arg5;
            arg0->unkC = temp_f0_4;
            arg0->unk18 = temp_v1->unk1C;
            arg0->unk1C = temp_v1->unk20;
            arg0->unk20 = temp_v1->unk24;
        }
        return 0;
    }
    phi_v0_2 = 0;
    if (temp_f0_4 > -16.0f) {
        arg0->unk0 = 1;
        arg0->unk6 = arg5;
        arg0->unkC = temp_f0_4;
        arg0->unk18 = temp_v1->unk1C;
        arg0->unk1C = temp_v1->unk20;
        arg0->unk20 = temp_v1->unk24;
    }
    return phi_v0_2;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AB288.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802AB6C4(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5) {
    f32 sp68;
    f32 sp64;
    f32 sp38;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f4;
    f32 temp_f6;
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;
    void *temp_v1;
    s32 phi_v0;
    f32 phi_f18;
    s32 phi_v0_2;

    temp_v1 = (arg5 * 0x2C) + D_8015F580;
    phi_v0 = 1;
    phi_v0_2 = 1;
    if (arg4 < temp_v1->unk8) {
        return 0;
    }
    if (temp_v1->unkE < arg4) {
        return 0;
    }
    if (temp_v1->unkC < arg3) {
        return 0;
    }
    if (arg3 < temp_v1->unk6) {
        return 0;
    }
    temp_f0 = arg1 * 3.0f;
    if (arg2 < (temp_v1->unk4 - temp_f0)) {
        return 0;
    }
    arg3 = arg3;
    if ((temp_v1->unkA + temp_f0) < arg2) {
        return 0;
    }
    temp_a0 = temp_v1->unk10;
    temp_a3 = temp_v1->unk18;
    temp_a2 = temp_v1->unk14;
    sp64 = temp_a3->unk4;
    sp8 = arg3;
    sp10 = arg4;
    temp_f6 = temp_a0->unk2 - arg3;
    sp68 = temp_a3->unk2;
    temp_f10 = temp_a2->unk4 - arg4;
    sp2C = temp_f6;
    sp28 = temp_f10;
    sp24 = temp_a0->unk4 - arg4;
    temp_f0_2 = temp_f6 * temp_f10;
    sp8 = temp_f6;
    spC = temp_f10;
    sp20 = temp_a2->unk2 - arg3;
    temp_f2 = sp24 * sp20;
    temp_f4 = temp_f0_2 - temp_f2;
    sp1C = temp_f4;
    sp38 = temp_f4;
    if (temp_f2 == temp_f0_2) {
        sp14 = arg3;
        temp_f0_3 = sp64 - sp10;
        temp_f2_2 = sp68 - arg3;
        phi_f18 = 0.0f;
        if ((((sp20 * temp_f0_3) - (spC * temp_f2_2)) * ((temp_f2_2 * sp24) - (temp_f0_3 * sp8))) < 0.0f) {
            goto block_22;
        }
    } else {
        temp_f2_3 = sp68 - arg3;
        temp_f0_4 = sp64 - arg4;
        temp_f14 = sp28 * temp_f2_3;
        temp_f12 = sp20 * temp_f0_4;
        if (temp_f14 == temp_f12) {
            phi_f18 = 0.0f;
            if ((sp38 * ((temp_f2_3 * sp24) - (temp_f0_4 * sp2C))) < 0.0f) {
                goto block_22;
            }
        } else {
            temp_f16 = temp_f12 - temp_f14;
            if ((sp1C * temp_f16) < 0.0f) {
                goto block_22;
            }
            temp_f14_2 = temp_f0_4 * sp2C;
            temp_f12_2 = temp_f2_3 * sp24;
            phi_f18 = 0.0f;
            if (temp_f14_2 != temp_f12_2) {
                phi_f18 = 0.0f;
                if ((temp_f16 * (temp_f12_2 - temp_f14_2)) < 0.0f) {
block_22:
                    phi_v0 = 0;
                    phi_f18 = 0.0f;
                }
            }
        }
    }
    if (phi_v0 == 0) {
        return 0;
    }
    temp_f0_5 = ((temp_v1->unk1C * arg2) + (temp_v1->unk20 * arg3) + (temp_v1->unk24 * arg4) + temp_v1->unk28) - arg1;
    if (phi_f18 < temp_f0_5) {
        if (temp_f0_5 < arg0->unk10) {
            arg0->unk2 = 1;
            arg0->unk8 = arg5;
            arg0->unk10 = temp_f0_5;
            arg0->unk24 = temp_v1->unk1C;
            arg0->unk28 = temp_v1->unk20;
            arg0->unk2C = temp_v1->unk24;
        }
        return 0;
    }
    phi_v0_2 = 0;
    if (temp_f0_5 > -16.0f) {
        arg0->unk2 = 1;
        arg0->unk8 = arg5;
        arg0->unk10 = temp_f0_5;
        arg0->unk24 = temp_v1->unk1C;
        arg0->unk28 = temp_v1->unk20;
        arg0->unk2C = temp_v1->unk24;
    }
    return phi_v0_2;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AB6C4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802ABB04(f32 arg0, f32 arg1, s32 arg2) {
    f32 sp6C;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp3C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f18;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f6;
    void *temp_a0;
    void *temp_a1;
    void *temp_a3;
    void *temp_v0;
    ? phi_v1;

    temp_v0 = ((arg2 & 0xFFFF) * 0x2C) + D_8015F580;
    temp_a1 = temp_v0->unk14;
    temp_a0 = temp_v0->unk10;
    sp60 = temp_a1->unk0;
    temp_f20 = temp_a0->unk4 - arg1;
    sp58 = temp_a1->unk4;
    temp_a3 = temp_v0->unk18;
    temp_f22 = temp_a0->unk0 - arg0;
    sp6C = temp_a3->unk0;
    temp_f10 = sp60 - arg0;
    temp_f0 = temp_f20 * temp_f10;
    sp28 = temp_f10;
    sp64 = temp_a3->unk4;
    temp_f6 = sp58 - arg1;
    temp_f2 = temp_f22 * temp_f6;
    sp20 = temp_f6;
    sp1C = temp_f0 - temp_f2;
    sp3C = sp1C;
    phi_v1 = 1;
    if (temp_f2 == temp_f0) {
        temp_f0_2 = sp6C - arg0;
        temp_f2_2 = sp64 - arg1;
        if ((((temp_f6 * temp_f0_2) - (temp_f10 * temp_f2_2)) * ((temp_f2_2 * temp_f22) - (temp_f0_2 * temp_f20))) < 0.0f) {
            goto block_10;
        }
    } else {
        temp_f2_3 = sp64 - arg1;
        temp_f0_3 = sp6C - arg0;
        temp_f18 = sp28 * temp_f2_3;
        temp_f16 = sp20 * temp_f0_3;
        if (temp_f18 == temp_f16) {
            if ((sp3C * ((temp_f2_3 * temp_f22) - (temp_f0_3 * temp_f20))) < 0.0f) {
                goto block_10;
            }
        } else {
            temp_f12 = temp_f16 - temp_f18;
            if ((sp1C * temp_f12) < 0.0f) {
                goto block_10;
            }
            temp_f16_2 = temp_f0_3 * temp_f20;
            temp_f14 = temp_f2_3 * temp_f22;
            if ((temp_f16_2 != temp_f14) && ((temp_f12 * (temp_f14 - temp_f16_2)) < 0.0f)) {
block_10:
                phi_v1 = 0;
            }
        }
    }
    return phi_v1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABB04.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s8 func_802ABD10(s32 arg0) {
    return (((arg0 & 0xFFFF) * 0x2C) + D_8015F580)->unk3;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABD10.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_802ABD40(s32 arg0) {
    return *(((arg0 & 0xFFFF) * 0x2C) + D_8015F580) & 0xFF;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABD40.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_802ABD7C(s32 arg0) {
    return *(((arg0 & 0xFFFF) * 0x2C) + D_8015F580) & 0x1000;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABD7C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_802ABDB8(s32 arg0) {
    return *(((arg0 & 0xFFFF) * 0x2C) + D_8015F580) & 0x400;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABDB8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_802ABDF4(s32 arg0) {
    return *(((arg0 & 0xFFFF) * 0x2C) + D_8015F580) & 0x800;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABDF4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
f32 func_802ABE30(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 temp_f2;
    void *temp_v0;

    temp_v0 = ((arg3 & 0xFFFF) * 0x2C) + D_8015F580;
    temp_f2 = temp_v0->unk20;
    if (temp_f2 == 0.0f) {
        return arg1;
    }
    return ((temp_v0->unk1C * arg0) + (temp_v0->unk24 * arg2) + temp_v0->unk28) / -temp_f2;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABE30.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
f32 func_802ABE30(f32, f32, s32, u16); // extern

f32 func_802ABEAC(void *arg0, void *arg1) {
    if (arg0->unk4 == 1) {
        return func_802ABE30(arg1->unk0, arg1->unk4, arg1->unk8, arg0->unkA);
    }
    if (arg0->unk0 == 1) {
        return func_802ABE30(arg1->unk0, arg1->unk4, arg1->unk8, arg0->unk6);
    }
    if (arg0->unk2 == 1) {
        return func_802ABE30(arg1->unk0, arg1->unk4, arg1->unk8, arg0->unk8);
    }
    return arg1->unk4;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ABEAC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void process_shell_collision(void *arg0, ? arg1, void *arg2, ? arg3) {
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp24;
    f32 spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_f18;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f6;
    f32 temp_f8;
    f64 temp_f16;

    temp_f2 = arg2->unk0;
    temp_f12 = arg2->unk4;
    temp_f14 = arg2->unk8;
    temp_f0 = sqrtf((temp_f2 * temp_f2) + (temp_f12 * temp_f12) + (temp_f14 * temp_f14));
    temp_f16 = temp_f0;
    sp24 = temp_f0;
    if ((temp_f16 > 4.5) || (temp_f16 < 3.5)) {
        sp24 = 4.0f;
    }
    temp_f10 = arg0->unk8;
    sp4 = temp_f10;
    temp_f16_2 = arg0->unk0;
    temp_f18 = arg0->unk4;
    temp_f0_2 = (temp_f10 * temp_f14) + ((temp_f16_2 * temp_f2) + (temp_f18 * temp_f12));
    sp0 = temp_f16_2 * temp_f0_2;
    spC = temp_f18 * temp_f0_2;
    sp40 = temp_f2 - sp0;
    sp3C = temp_f12 - spC;
    temp_f6 = temp_f10 * temp_f0_2;
    sp8 = temp_f6;
    sp38 = temp_f14 - temp_f6;
    temp_f2_2 = sp40 - sp0;
    temp_f12_2 = sp3C - spC;
    temp_f14_2 = sp38 - temp_f6;
    temp_f16_3 = (1.0f / sqrtf((temp_f2_2 * temp_f2_2) + (temp_f12_2 * temp_f12_2) + (temp_f14_2 * temp_f14_2))) * sp24;
    temp_f10_2 = temp_f12_2 * temp_f16_3;
    temp_f8 = temp_f14_2 * temp_f16_3;
    arg2->unk0 = temp_f2_2 * temp_f16_3;
    arg2->unk4 = temp_f10_2;
    arg2->unk8 = temp_f8;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/process_shell_collision.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? process_shell_collision(void *, f32, s32, ?); // extern

void func_802AC098(void *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = arg0->unkC;
    if (temp_f0 < 0.0f) {
        process_shell_collision(arg0 + 0x18, temp_f0, arg1, 0x40000000);
    }
    temp_f0_2 = arg0->unk10;
    if (temp_f0_2 < 0.0f) {
        process_shell_collision(arg0 + 0x24, temp_f0_2, arg1, 0x40000000);
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AC098.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_802AC114(void *arg0, f32 arg1, void *arg2, ? arg3) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f2;

    temp_f0 = arg2->unk0;
    temp_f2 = arg2->unk4;
    temp_f12 = arg2->unk8;
    temp_f14 = -arg0->unk0;
    temp_f16 = -arg0->unk4;
    temp_f18 = -arg0->unk8;
    if (arg1 < -3.5) {
        temp_f20 = (temp_f14 * temp_f0) + (temp_f16 * temp_f2) + (temp_f18 * temp_f12);
        arg2->unk0 = (temp_f0 - (temp_f20 * temp_f14)) - (temp_f20 * temp_f14 * 0.5f);
        arg2->unk4 = (temp_f2 - (temp_f20 * temp_f16)) - (temp_f20 * temp_f16 * 0.5f);
        arg2->unk8 = (temp_f12 - (temp_f20 * temp_f18)) - (temp_f20 * temp_f18 * 0.5f);
        return;
    }
    temp_f20_2 = (temp_f14 * temp_f0) + (temp_f16 * temp_f2) + (temp_f18 * temp_f12);
    arg2->unk0 = temp_f0 - (temp_f20_2 * temp_f14);
    arg2->unk4 = temp_f2 - (temp_f20_2 * temp_f16);
    arg2->unk8 = temp_f12 - (temp_f20_2 * temp_f18);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AC114.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AC760(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 sp6C;
    f32 sp64;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f18;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f4;
    f32 temp_f6;
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;
    void *temp_v1;
    s32 phi_v0;

    temp_v1 = (arg5 * 0x2C) + D_8015F580;
    phi_v0 = 1;
    if (arg2 < temp_v1->unk4) {
        return 0;
    }
    if (arg4 < temp_v1->unk8) {
        return 0;
    }
    if (temp_v1->unkA < arg2) {
        return 0;
    }
    if (temp_v1->unkE < arg4) {
        return 0;
    }
    arg2 = arg2;
    if (arg3 < (temp_v1->unk6 - (arg1 * 3.0f))) {
        return 0;
    }
    temp_a0 = temp_v1->unk10;
    temp_a3 = temp_v1->unk18;
    temp_a2 = temp_v1->unk14;
    sp6C = temp_a3->unk0;
    sp8 = arg4;
    sp10 = arg2;
    temp_f6 = temp_a0->unk4 - arg4;
    sp64 = temp_a3->unk4;
    temp_f4 = temp_a2->unk0 - arg2;
    sp28 = temp_f6;
    sp24 = temp_f4;
    sp20 = temp_a0->unk0 - arg2;
    temp_f0 = temp_f6 * temp_f4;
    sp8 = temp_f6;
    spC = temp_f4;
    temp_f18 = sp8;
    sp1C = temp_a2->unk4 - arg4;
    temp_f2 = sp20 * sp1C;
    temp_f10 = temp_f0 - temp_f2;
    sp18 = temp_f10;
    sp38 = temp_f10;
    if (temp_f2 == temp_f0) {
        sp8 = arg4;
        temp_f0_2 = sp6C - sp10;
        temp_f2_2 = sp64 - arg4;
        if ((((sp1C * temp_f0_2) - (spC * temp_f2_2)) * ((temp_f2_2 * sp20) - (temp_f0_2 * temp_f18))) < 0.0f) {
            goto block_20;
        }
    } else {
        temp_f2_3 = sp64 - arg4;
        temp_f0_3 = sp6C - arg2;
        temp_f14 = sp24 * temp_f2_3;
        temp_f12 = sp1C * temp_f0_3;
        if (temp_f14 == temp_f12) {
            if ((sp38 * ((temp_f2_3 * sp20) - (temp_f0_3 * sp28))) < 0.0f) {
                goto block_20;
            }
        } else {
            temp_f16 = temp_f12 - temp_f14;
            if ((sp18 * temp_f16) < 0.0f) {
                goto block_20;
            }
            temp_f14_2 = temp_f0_3 * sp28;
            temp_f12_2 = temp_f2_3 * sp20;
            if ((temp_f14_2 != temp_f12_2) && ((temp_f16 * (temp_f12_2 - temp_f14_2)) < 0.0f)) {
block_20:
                phi_v0 = 0;
            }
        }
    }
    if (phi_v0 == 0) {
        return 0;
    }
    temp_f2_4 = temp_v1->unk1C;
    temp_f12_3 = temp_v1->unk20;
    temp_f14_3 = temp_v1->unk24;
    temp_f16_2 = temp_v1->unk28;
    temp_f0_4 = (temp_f2_4 * arg2) + (temp_f12_3 * arg3) + (temp_f14_3 * arg4) + temp_f16_2;
    if (arg1 < temp_f0_4) {
        if (temp_f0_4 < arg0->unk14) {
            arg0->unk4 = 1;
            arg0->unkA = arg5;
            arg0->unk14 = temp_f0_4 - arg1;
            arg0->unk30 = temp_v1->unk1C;
            arg0->unk34 = temp_v1->unk20;
            arg0->unk38 = temp_v1->unk24;
        }
        return 0;
    }
    if (((temp_f2_4 * arg6) + (temp_f12_3 * arg7) + (temp_f14_3 * arg8) + temp_f16_2) < 0.0f) {
        return 0;
    }
    arg0->unk4 = 1;
    arg0->unkA = arg5;
    arg0->unk14 = temp_f0_4 - arg1;
    arg0->unk30 = temp_v1->unk1C;
    arg0->unk34 = temp_v1->unk20;
    arg0->unk38 = temp_v1->unk24;
    return 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AC760.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802ACBA4(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 sp70;
    f32 sp6C;
    f32 sp48;
    f32 sp3C;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f6;
    f32 temp_f8;
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;
    void *temp_v1;
    s32 phi_v0;
    f32 phi_f18;
    f32 phi_f10;

    temp_v1 = (arg5 * 0x2C) + D_8015F580;
    phi_v0 = 1;
    if (arg2 < temp_v1->unk4) {
        return 0;
    }
    if (temp_v1->unkA < arg2) {
        return 0;
    }
    if (temp_v1->unkC < arg3) {
        return 0;
    }
    if (arg3 < temp_v1->unk6) {
        return 0;
    }
    temp_f2 = arg1 * 3.0f;
    if (arg4 < (temp_v1->unk8 - temp_f2)) {
        return 0;
    }
    arg2 = arg2;
    arg3 = arg3;
    if ((temp_v1->unkE + temp_f2) < arg4) {
        return 0;
    }
    temp_a0 = temp_v1->unk10;
    temp_a3 = temp_v1->unk18;
    temp_a2 = temp_v1->unk14;
    sp70 = temp_a3->unk0;
    sp8 = arg3;
    sp10 = arg2;
    temp_f10 = temp_a0->unk2 - arg3;
    sp6C = temp_a3->unk2;
    temp_f6 = temp_a2->unk0 - arg2;
    sp2C = temp_f10;
    sp28 = temp_f6;
    sp24 = temp_a0->unk0 - arg2;
    temp_f0 = temp_f10 * temp_f6;
    sp8 = temp_f10;
    spC = temp_f6;
    sp20 = temp_a2->unk2 - arg3;
    temp_f2_2 = sp24 * sp20;
    temp_f4 = temp_f0 - temp_f2_2;
    sp1C = temp_f4;
    sp3C = temp_f4;
    if (temp_f2_2 == temp_f0) {
        sp14 = arg3;
        temp_f0_2 = sp70 - sp10;
        temp_f2_3 = sp6C - arg3;
        phi_f18 = 0.0f;
        if ((((sp20 * temp_f0_2) - (spC * temp_f2_3)) * ((temp_f2_3 * sp24) - (temp_f0_2 * sp8))) < 0.0f) {
            goto block_22;
        }
    } else {
        temp_f2_4 = sp6C - arg3;
        temp_f0_3 = sp70 - arg2;
        temp_f14 = sp28 * temp_f2_4;
        temp_f12 = sp20 * temp_f0_3;
        if (temp_f14 == temp_f12) {
            phi_f18 = 0.0f;
            if ((sp3C * ((temp_f2_4 * sp24) - (temp_f0_3 * sp2C))) < 0.0f) {
                goto block_22;
            }
        } else {
            temp_f16 = temp_f12 - temp_f14;
            if ((sp1C * temp_f16) < 0.0f) {
                goto block_22;
            }
            temp_f14_2 = temp_f0_3 * sp2C;
            temp_f12_2 = temp_f2_4 * sp24;
            phi_f18 = 0.0f;
            if (temp_f14_2 != temp_f12_2) {
                phi_f18 = 0.0f;
                if ((temp_f16 * (temp_f12_2 - temp_f14_2)) < 0.0f) {
block_22:
                    phi_v0 = 0;
                    phi_f18 = 0.0f;
                }
            }
        }
    }
    if (phi_v0 == 0) {
        return 0;
    }
    temp_f2_5 = temp_v1->unk1C;
    temp_f12_3 = temp_v1->unk20;
    temp_f14_3 = temp_v1->unk24;
    temp_f16_2 = temp_v1->unk28;
    temp_f0_4 = (temp_f2_5 * arg2) + (temp_f12_3 * arg3) + (temp_f14_3 * arg4) + temp_f16_2;
    if ((temp_v1->unk0 & 0x200) != 0) {
        temp_f4_2 = (temp_f2_5 * arg6) + (temp_f12_3 * arg7) + (temp_f14_3 * arg8) + temp_f16_2;
        sp48 = temp_f4_2;
        if ((phi_f18 < temp_f0_4) && (phi_f18 < temp_f4_2)) {
            if (temp_f0_4 < arg1) {
                arg0->unk0 = 1;
                arg0->unk6 = arg5;
                arg0->unkC = temp_f0_4 - arg1;
                arg0->unk18 = temp_v1->unk1C;
                arg0->unk1C = temp_v1->unk20;
                arg0->unk20 = temp_v1->unk24;
                return 1;
            }
            return 0;
        }
        if ((temp_f0_4 < phi_f18) && (sp48 < phi_f18)) {
            temp_f0_5 = temp_f0_4 * -1.0f;
            if (temp_f0_5 < arg1) {
                arg0->unk0 = 1;
                arg0->unk6 = arg5;
                arg0->unkC = temp_f0_5 - arg1;
                arg0->unk18 = -temp_v1->unk1C;
                arg0->unk1C = -temp_v1->unk20;
                arg0->unk20 = -temp_v1->unk24;
                return 1;
            }
            return 0;
        }
        if ((phi_f18 < temp_f0_4) && (sp48 < phi_f18)) {
            arg0->unk0 = 1;
            arg0->unk6 = arg5;
            arg0->unkC = -(temp_f0_4 + arg1);
            arg0->unk18 = -temp_v1->unk1C;
            arg0->unk1C = -temp_v1->unk20;
            phi_f10 = -temp_v1->unk24;
            goto block_54;
        }
        if ((temp_f0_4 < phi_f18) && (phi_f18 < sp48)) {
            arg0->unk0 = 1;
            arg0->unk6 = arg5;
            arg0->unkC = temp_f0_4 + arg1;
            arg0->unk18 = temp_v1->unk1C;
            arg0->unk1C = temp_v1->unk20;
            arg0->unk20 = temp_v1->unk24;
            return 1;
        }
        if (temp_f0_4 == phi_f18) {
            if (phi_f18 <= sp48) {
                arg0->unk0 = 1;
                arg0->unk6 = arg5;
                arg0->unkC = sp48 + arg1;
                arg0->unk18 = temp_v1->unk1C;
                arg0->unk1C = temp_v1->unk20;
                arg0->unk20 = temp_v1->unk24;
                return 1;
            }
            arg0->unk0 = 1;
            arg0->unk6 = arg5;
            arg0->unkC = -(sp48 + arg1);
            arg0->unk18 = temp_v1->unk1C;
            arg0->unk1C = temp_v1->unk20;
            phi_f10 = temp_v1->unk24;
            goto block_54;
        }
        return 0;
    }
    if (arg1 < temp_f0_4) {
        if (temp_f0_4 < arg0->unkC) {
            arg0->unk0 = 1;
            arg0->unk6 = arg5;
            arg0->unkC = temp_f0_4 - arg1;
            arg0->unk18 = temp_v1->unk1C;
            arg0->unk1C = temp_v1->unk20;
            arg0->unk20 = temp_v1->unk24;
        }
        return 0;
    }
    temp_f8 = (temp_f2_5 * arg6) + (temp_f12_3 * arg7) + (temp_f14_3 * arg8) + temp_f16_2;
    sp48 = temp_f8;
    if (temp_f8 < phi_f18) {
        return 0;
    }
    arg0->unk0 = 1;
    arg0->unk6 = arg5;
    arg0->unkC = temp_f0_4 - arg1;
    arg0->unk18 = temp_v1->unk1C;
    arg0->unk1C = temp_v1->unk20;
    phi_f10 = temp_v1->unk24;
block_54:
    arg0->unk20 = phi_f10;
    return 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ACBA4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AD278(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 sp68;
    f32 sp64;
    f32 sp44;
    f32 sp38;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;
    void *temp_v1;
    s32 phi_v0;
    f32 phi_f18;
    f32 phi_f8;

    temp_v1 = (arg5 * 0x2C) + D_8015F580;
    phi_v0 = 1;
    if (arg4 < temp_v1->unk8) {
        return 0;
    }
    if (temp_v1->unkE < arg4) {
        return 0;
    }
    if (temp_v1->unkC < arg3) {
        return 0;
    }
    if (arg3 < temp_v1->unk6) {
        return 0;
    }
    temp_f0 = arg1 * 3.0f;
    if (arg2 < (temp_v1->unk4 - temp_f0)) {
        return 0;
    }
    arg3 = arg3;
    if ((temp_v1->unkA + temp_f0) < arg2) {
        return 0;
    }
    temp_a0 = temp_v1->unk10;
    temp_a3 = temp_v1->unk18;
    temp_a2 = temp_v1->unk14;
    sp64 = temp_a3->unk4;
    sp8 = arg3;
    sp10 = arg4;
    temp_f8 = temp_a0->unk2 - arg3;
    sp68 = temp_a3->unk2;
    temp_f6 = temp_a2->unk4 - arg4;
    sp2C = temp_f8;
    sp28 = temp_f6;
    sp24 = temp_a0->unk4 - arg4;
    temp_f0_2 = temp_f8 * temp_f6;
    sp8 = temp_f8;
    spC = temp_f6;
    sp20 = temp_a2->unk2 - arg3;
    temp_f2 = sp24 * sp20;
    temp_f10 = temp_f0_2 - temp_f2;
    sp1C = temp_f10;
    sp38 = temp_f10;
    if (temp_f2 == temp_f0_2) {
        sp14 = arg3;
        temp_f0_3 = sp64 - sp10;
        temp_f2_2 = sp68 - arg3;
        phi_f18 = 0.0f;
        if ((((sp20 * temp_f0_3) - (spC * temp_f2_2)) * ((temp_f2_2 * sp24) - (temp_f0_3 * sp8))) < 0.0f) {
            goto block_22;
        }
    } else {
        temp_f2_3 = sp68 - arg3;
        temp_f0_4 = sp64 - arg4;
        temp_f14 = sp28 * temp_f2_3;
        temp_f12 = sp20 * temp_f0_4;
        if (temp_f14 == temp_f12) {
            phi_f18 = 0.0f;
            if ((sp38 * ((temp_f2_3 * sp24) - (temp_f0_4 * sp2C))) < 0.0f) {
                goto block_22;
            }
        } else {
            temp_f16 = temp_f12 - temp_f14;
            if ((sp1C * temp_f16) < 0.0f) {
                goto block_22;
            }
            temp_f14_2 = temp_f0_4 * sp2C;
            temp_f12_2 = temp_f2_3 * sp24;
            phi_f18 = 0.0f;
            if (temp_f14_2 != temp_f12_2) {
                phi_f18 = 0.0f;
                if ((temp_f16 * (temp_f12_2 - temp_f14_2)) < 0.0f) {
block_22:
                    phi_v0 = 0;
                    phi_f18 = 0.0f;
                }
            }
        }
    }
    if (phi_v0 == 0) {
        return 0;
    }
    temp_f2_4 = temp_v1->unk1C;
    temp_f12_3 = temp_v1->unk20;
    temp_f14_3 = temp_v1->unk24;
    temp_f16_2 = temp_v1->unk28;
    temp_f0_5 = (temp_f2_4 * arg2) + (temp_f12_3 * arg3) + (temp_f14_3 * arg4) + temp_f16_2;
    if ((temp_v1->unk0 & 0x200) != 0) {
        temp_f10_2 = (temp_f2_4 * arg6) + (temp_f12_3 * arg7) + (temp_f14_3 * arg8) + temp_f16_2;
        sp44 = temp_f10_2;
        if ((phi_f18 < temp_f0_5) && (phi_f18 < temp_f10_2)) {
            if (temp_f0_5 < arg1) {
                arg0->unk2 = 1;
                arg0->unk8 = arg5;
                arg0->unk10 = temp_f0_5 - arg1;
                arg0->unk24 = temp_v1->unk1C;
                arg0->unk28 = temp_v1->unk20;
                arg0->unk2C = temp_v1->unk24;
                return 1;
            }
            return 0;
        }
        if ((temp_f0_5 < phi_f18) && (sp44 < phi_f18)) {
            temp_f0_6 = temp_f0_5 * -1.0f;
            if (temp_f0_6 < arg1) {
                arg0->unk2 = 1;
                arg0->unk8 = arg5;
                arg0->unk10 = temp_f0_6 - arg1;
                arg0->unk24 = -temp_v1->unk1C;
                arg0->unk28 = -temp_v1->unk20;
                arg0->unk2C = -temp_v1->unk24;
                return 1;
            }
            return 0;
        }
        if ((phi_f18 < temp_f0_5) && (sp44 < phi_f18)) {
            arg0->unk2 = 1;
            arg0->unk8 = arg5;
            arg0->unk10 = -(temp_f0_5 + arg1);
            arg0->unk24 = -temp_v1->unk1C;
            arg0->unk28 = -temp_v1->unk20;
            phi_f8 = -temp_v1->unk24;
            goto block_54;
        }
        if ((temp_f0_5 < phi_f18) && (phi_f18 < sp44)) {
            arg0->unk2 = 1;
            arg0->unk8 = arg5;
            arg0->unk10 = temp_f0_5 + arg1;
            arg0->unk24 = temp_v1->unk1C;
            arg0->unk28 = temp_v1->unk20;
            arg0->unk2C = temp_v1->unk24;
            return 1;
        }
        if (temp_f0_5 == phi_f18) {
            if (phi_f18 <= sp44) {
                arg0->unk2 = 1;
                arg0->unk8 = arg5;
                arg0->unk10 = sp44 + arg1;
                arg0->unk24 = temp_v1->unk1C;
                arg0->unk28 = temp_v1->unk20;
                arg0->unk2C = temp_v1->unk24;
                return 1;
            }
            arg0->unk2 = 1;
            arg0->unk8 = arg5;
            arg0->unk10 = -(sp44 + arg1);
            arg0->unk24 = temp_v1->unk1C;
            arg0->unk28 = temp_v1->unk20;
            phi_f8 = temp_v1->unk24;
            goto block_54;
        }
        return 0;
    }
    if (arg1 < temp_f0_5) {
        if (temp_f0_5 < arg0->unk10) {
            arg0->unk2 = 1;
            arg0->unk8 = arg5;
            arg0->unk10 = temp_f0_5 - arg1;
            arg0->unk24 = temp_v1->unk1C;
            arg0->unk28 = temp_v1->unk20;
            arg0->unk2C = temp_v1->unk24;
        }
        return 0;
    }
    temp_f4 = (temp_f2_4 * arg6) + (temp_f12_3 * arg7) + (temp_f14_3 * arg8) + temp_f16_2;
    sp44 = temp_f4;
    if (temp_f4 < phi_f18) {
        return 0;
    }
    arg0->unk2 = 1;
    arg0->unk8 = arg5;
    arg0->unk10 = temp_f0_5 - arg1;
    arg0->unk24 = temp_v1->unk1C;
    arg0->unk28 = temp_v1->unk20;
    phi_f8 = temp_v1->unk24;
block_54:
    arg0->unk2C = phi_f8;
    return 1;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AD278.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802AC760(void *, f32, f32, f32, f32, ?32, ?32, ?32, ?32); // extern
s32 func_802ACBA4(void *, void *, f32, f32, f32, s32, ?32, ?32, ?32); // extern
s32 func_802AD278(void *, void *, f32, f32, f32, s32, ?32, ?32, ?32); // extern
extern ? D_8014F110;
extern s32 D_8015F584;

s32 func_802AD950(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, ?32 arg5, ?32 arg6, ?32 arg7) {
    s16 temp_v0_4;
    s16 temp_v1;
    s32 temp_f10;
    s32 temp_f16;
    s32 temp_t7;
    u16 temp_s6;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_5;
    u16 temp_v1_3;
    void *temp_v1_2;
    s32 phi_s4;
    s32 phi_s4_2;
    u16 phi_s2;
    s32 phi_s3;
    s32 phi_s4_3;
    s32 phi_s4_4;
    s32 phi_s4_5;
    s32 phi_s4_6;

    arg0->unk0 = 0;
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    arg0->unkC = 1000.0f;
    arg0->unk10 = 1000.0f;
    arg0->unk14 = 1000.0f;
    temp_v0 = arg0->unkA;
    phi_s4_6 = 0;
    if ((temp_v0 < D_8015F588) && (func_802AC760(arg1, arg2, arg3, arg4, (bitwise f32) temp_v0, arg5, arg6, arg7) == 1)) {
        phi_s4_6 = 0x4000;
    }
    temp_v0_2 = arg0->unk6;
    phi_s4_4 = phi_s4_6;
    if ((temp_v0_2 < D_8015F588) && (func_802ACBA4(arg0, arg1, arg2, arg3, arg4, temp_v0_2, arg5, arg6, arg7) == 1)) {
        phi_s4_4 = (phi_s4_6 | 0x2000) & 0xFFFF;
    }
    temp_v0_3 = arg0->unk8;
    phi_s4 = phi_s4_4;
    if ((temp_v0_3 < D_8015F588) && (func_802AD278(arg0, arg1, arg2, arg3, arg4, temp_v0_3, arg5, arg6, arg7) == 1)) {
        phi_s4 = (phi_s4_4 | 0x8000) & 0xFFFF;
    }
    phi_s4_2 = phi_s4;
    phi_s4_3 = phi_s4;
    if (phi_s4 == 0xE000) {
        goto block_39;
    }
    temp_v0_4 = D_8015F6EA;
    temp_v1 = D_8015F6F2;
    temp_f10 = (arg2 - temp_v0_4) / ((D_8015F6E8 - temp_v0_4) / 0x20);
    temp_f16 = (arg4 - temp_v1) / ((D_8015F6F0 - temp_v1) / 0x20);
    if (temp_f10 < 0) {
        return 0;
    }
    if (temp_f16 < 0) {
        return 0;
    }
    if (temp_f10 >= 0x20) {
        return 0;
    }
    if (temp_f16 >= 0x20) {
        return 0;
    }
    temp_v1_2 = ((temp_f10 + (temp_f16 << 5)) * 4) + &D_8014F110;
    temp_s6 = temp_v1_2->unk2;
    phi_s3 = 0;
    if (temp_s6 == 0) {

    } else {
        phi_s2 = temp_v1_2->unk0;
        if (temp_s6 > 0) {
loop_22:
            phi_s4_3 = phi_s4_2;
            phi_s4_5 = phi_s4_2;
            if (phi_s4_2 == 0xE000) {

            } else {
                temp_v0_5 = *(D_8015F584 + (phi_s2 * 2));
                temp_v1_3 = *(D_8015F580 + (temp_v0_5 * 0x2C));
                if ((temp_v1_3 & 0x4000) != 0) {
                    if (((phi_s4_2 & 0x4000) == 0) && (arg0->unkA != temp_v0_5) && (func_802AC760(arg0, (bitwise f32) arg1, arg2, arg3, arg4, temp_v0_5, arg5, arg6, arg7) == 1)) {
                        phi_s4_5 = (phi_s4_2 | 0x4000) & 0xFFFF;
                    }
                } else if ((temp_v1_3 & 0x8000) != 0) {
                    if (((phi_s4_2 & 0x8000) == 0) && (arg0->unk8 != temp_v0_5) && (func_802AD278(arg0, arg1, arg2, arg3, arg4, temp_v0_5, arg5, arg6, arg7) == 1)) {
                        phi_s4_5 = (phi_s4_2 | 0x8000) & 0xFFFF;
                    }
                } else if (((phi_s4_2 & 0x2000) == 0) && (arg0->unk6 != temp_v0_5) && (func_802ACBA4(arg0, arg1, arg2, arg3, arg4, temp_v0_5, arg5, arg6, arg7) == 1)) {
                    phi_s4_5 = (phi_s4_2 | 0x2000) & 0xFFFF;
                }
                temp_t7 = (phi_s3 + 1) & 0xFFFF;
                phi_s4_2 = phi_s4_5;
                phi_s2 = (phi_s2 + 1) & 0xFFFF;
                phi_s3 = temp_t7;
                phi_s4_3 = phi_s4_5;
                if (temp_t7 < temp_s6) {
                    goto loop_22;
                }
            }
        }
    }
block_39:
    return phi_s4_3;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AD950.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802AAE4C(void *, f32, f32, f32, f32, s32); // extern
s32 func_802AB288(void *, void *, f32, f32, f32, s32); // extern
s32 func_802AB6C4(void *, void *, f32, f32, f32, s32); // extern
extern ? D_8014F110;
extern s32 D_8015F584;

s32 func_802ADDC8(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4) {
    s16 temp_v0_4;
    s16 temp_v1;
    s32 temp_f4;
    s32 temp_f6;
    s32 temp_t7;
    u16 temp_s6;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_5;
    u16 temp_v1_3;
    void *temp_v1_2;
    s32 phi_s4;
    s32 phi_s4_2;
    u16 phi_s2;
    s32 phi_s3;
    s32 phi_s4_3;
    s32 phi_s4_4;
    s32 phi_s4_5;
    s32 phi_s4_6;

    arg0->unk0 = 0;
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    arg0->unkC = 1000.0f;
    arg0->unk10 = 1000.0f;
    arg0->unk14 = 1000.0f;
    temp_v0 = arg0->unkA;
    phi_s4_6 = 0;
    if ((temp_v0 < D_8015F588) && (func_802AAE4C(arg1, arg2, arg3, arg4, (bitwise f32) temp_v0) == 1)) {
        phi_s4_6 = 0x4000;
    }
    temp_v0_2 = arg0->unk6;
    phi_s4_4 = phi_s4_6;
    if ((temp_v0_2 < D_8015F588) && (func_802AB288(arg0, arg1, arg2, arg3, arg4, temp_v0_2) == 1)) {
        phi_s4_4 = (phi_s4_6 | 0x2000) & 0xFFFF;
    }
    temp_v0_3 = arg0->unk8;
    phi_s4 = phi_s4_4;
    if ((temp_v0_3 < D_8015F588) && (func_802AB6C4(arg0, arg1, arg2, arg3, arg4, temp_v0_3) == 1)) {
        phi_s4 = (phi_s4_4 | 0x8000) & 0xFFFF;
    }
    phi_s4_2 = phi_s4;
    phi_s4_3 = phi_s4;
    if (phi_s4 == 0xE000) {
        goto block_39;
    }
    temp_v0_4 = D_8015F6EA;
    temp_v1 = D_8015F6F2;
    temp_f4 = (arg2 - temp_v0_4) / ((D_8015F6E8 - temp_v0_4) / 0x20);
    temp_f6 = (arg4 - temp_v1) / ((D_8015F6F0 - temp_v1) / 0x20);
    if (temp_f4 < 0) {
        return 0;
    }
    if (temp_f6 < 0) {
        return 0;
    }
    if (temp_f4 >= 0x20) {
        return 0;
    }
    if (temp_f6 >= 0x20) {
        return 0;
    }
    temp_v1_2 = ((temp_f4 + (temp_f6 << 5)) * 4) + &D_8014F110;
    temp_s6 = temp_v1_2->unk2;
    phi_s3 = 0;
    if (temp_s6 == 0) {

    } else {
        phi_s2 = temp_v1_2->unk0;
        if (temp_s6 > 0) {
loop_22:
            phi_s4_3 = phi_s4_2;
            phi_s4_5 = phi_s4_2;
            if (phi_s4_2 == 0xE000) {

            } else {
                temp_v0_5 = *(D_8015F584 + (phi_s2 * 2));
                temp_v1_3 = *(D_8015F580 + (temp_v0_5 * 0x2C));
                if ((temp_v1_3 & 0x4000) != 0) {
                    if (((phi_s4_2 & 0x4000) == 0) && (arg0->unkA != temp_v0_5) && (func_802AAE4C(arg0, (bitwise f32) arg1, arg2, arg3, arg4, temp_v0_5) == 1)) {
                        phi_s4_5 = (phi_s4_2 | 0x4000) & 0xFFFF;
                    }
                } else if ((temp_v1_3 & 0x8000) != 0) {
                    if (((phi_s4_2 & 0x8000) == 0) && (arg0->unk8 != temp_v0_5) && (func_802AB6C4(arg0, arg1, arg2, arg3, arg4, temp_v0_5) == 1)) {
                        phi_s4_5 = (phi_s4_2 | 0x8000) & 0xFFFF;
                    }
                } else if (((phi_s4_2 & 0x2000) == 0) && (arg0->unk6 != temp_v0_5) && (func_802AB288(arg0, arg1, arg2, arg3, arg4, temp_v0_5) == 1)) {
                    phi_s4_5 = (phi_s4_2 | 0x2000) & 0xFFFF;
                }
                temp_t7 = (phi_s3 + 1) & 0xFFFF;
                phi_s4_2 = phi_s4_5;
                phi_s2 = (phi_s2 + 1) & 0xFFFF;
                phi_s3 = temp_t7;
                phi_s4_3 = phi_s4_5;
                if (temp_t7 < temp_s6) {
                    goto loop_22;
                }
            }
        }
    }
block_39:
    return phi_s4_3;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802ADDC8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802ABB04(f32, f32, s32); // extern
f32 func_802ABE30(f32, f32, f32, s32); // extern
extern ? D_8014F110;
extern s32 D_8015F584;
extern f32 D_802B9E4C;
extern f32 D_802B9E50;
extern f32 D_802B9E54;
extern f32 D_802B9E58;
extern f32 D_802B9E5C;
extern f32 D_802B9E60;

f32 func_802AE1C0(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f20;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_f4;
    s32 temp_f6;
    s32 temp_t0;
    s32 temp_t9;
    u16 temp_s0;
    u16 temp_t1;
    void *temp_t2;
    u16 phi_s1;
    f32 phi_f20;
    s32 phi_s2;
    f32 phi_f20_2;
    f32 phi_f20_3;

    temp_v0 = D_8015F6EA;
    temp_f20 = D_802B9E4C;
    temp_v1 = D_8015F6F2;
    temp_f4 = (arg0 - temp_v0) / ((D_8015F6E8 - temp_v0) / 0x20);
    temp_f6 = (arg2 - temp_v1) / ((D_8015F6F0 - temp_v1) / 0x20);
    temp_t0 = temp_f6 << 5;
    temp_t2 = ((temp_f4 + temp_t0) * 4) + &D_8014F110;
    temp_t1 = temp_t2->unk2;
    phi_f20 = temp_f20;
    phi_f20_2 = temp_f20;
    if (temp_f4 < 0) {
        return D_802B9E50;
    }
    if (temp_f6 & 0x4000000) {
        return D_802B9E54;
    }
    if (temp_f4 >= 0x20) {
        return D_802B9E58;
    }
    if (temp_t0 >= 0x400) {
        return D_802B9E5C;
    }
    if (temp_t1 == 0) {
        return D_802B9E60;
    }
    phi_s1 = temp_t2->unk0;
    phi_s2 = 0;
    if (temp_t1 > 0) {
        do {
            temp_s0 = *(D_8015F584 + (phi_s1 * 2));
            phi_f20_3 = phi_f20;
            if (((*(D_8015F580 + (temp_s0 * 0x2C)) & 0x4000) != 0) && (func_802ABB04(arg0, arg2, temp_s0 & 0xFFFF) == 1)) {
                temp_f0 = func_802ABE30(arg0, arg1, arg2, temp_s0 & 0xFFFF);
                if ((temp_f0 <= arg1) && (phi_f20 < temp_f0)) {
                    phi_f20_3 = temp_f0;
                }
            }
            temp_t9 = (phi_s2 + 1) & 0xFFFF;
            phi_s1 = (phi_s1 + 1) & 0xFFFF;
            phi_f20 = phi_f20_3;
            phi_s2 = temp_t9;
            phi_f20_2 = phi_f20_3;
        } while (temp_t9 < temp_t1);
    }
    return phi_f20_2;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AE1C0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_8015F5A4;
extern s16 D_8015F6FA;
extern s16 D_8015F6FC;
extern f32 D_802B9E64;
extern f32 D_802B9E68;
extern f32 D_802B9E6C;
extern f32 D_802B9E70;

void func_802AE434(void *arg0, void *arg1, void *arg2, s8 arg3, u16 arg4) {
    s16 spBA;
    s16 spB8;
    s16 spB6;
    s16 spB2;
    s16 spAC;
    s16 spAA;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    s16 sp4A;
    s16 sp48;
    s16 sp44;
    s16 sp42;
    void *sp1C;
    f64 sp10;
    f64 sp8;
    f64 sp0;
    f32 temp_f0;
    f32 temp_f18_2;
    f32 temp_f4_2;
    f64 temp_f12;
    f64 temp_f14;
    f64 temp_f16;
    f64 temp_f18;
    f64 temp_f2;
    f64 temp_f4;
    f64 temp_f8;
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_t3;
    s16 temp_t4;
    s32 temp_a0_2;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    u16 temp_a0_3;
    u16 temp_a3_2;
    u16 temp_v1_2;
    void *temp_t0;
    void *temp_t1;
    void *temp_t2;
    void *temp_t6;
    s32 phi_a0;
    s32 phi_t3;
    s32 phi_t5;
    s32 phi_a1;
    s32 phi_t4;
    s32 phi_v1;
    s32 phi_a2;
    s32 phi_a3;
    s32 phi_v0;
    s16 phi_t1;
    s16 phi_t2;
    u16 phi_a1_2;
    u16 phi_t9;
    u16 phi_t8;

    temp_t0 = (D_8015F588 * 0x2C) + D_8015F580;
    temp_t0->unk10 = arg0;
    temp_t0->unk14 = arg1;
    temp_t0->unk18 = arg2;
    if ((arg0->unk6 != 4) || (arg1->unk6 != 4) || (temp_t0->unk18->unk6 != 4)) {
        temp_t6 = temp_t0->unk10;
        sp1C = temp_t6;
        temp_t1 = temp_t0->unk14;
        temp_t2 = temp_t0->unk18;
        temp_a0 = temp_t6->unk0;
        temp_t3 = temp_t1->unk0;
        temp_a1 = temp_t6->unk4;
        temp_t4 = temp_t1->unk4;
        phi_a0 = temp_a0;
        phi_t3 = temp_t3;
        phi_t5 = temp_t2->unk0;
        phi_a1 = temp_a1;
        phi_t4 = temp_t4;
        phi_v1 = temp_t2->unk4;
        phi_a2 = temp_t6->unk2;
        phi_a3 = temp_t1->unk2;
        phi_v0 = temp_t2->unk2;
        if ((temp_a0 == temp_t3) && (temp_a1 == temp_t4)) {
            temp_t0->unk18 = arg1;
            temp_t0->unk14 = arg2;
            phi_a0 = arg0->unk0;
            phi_t3 = arg1->unk0;
            phi_t5 = arg2->unk0;
            phi_a1 = arg0->unk4;
            phi_t4 = arg1->unk4;
            phi_v1 = arg2->unk4;
            phi_a2 = arg0->unk2;
            phi_a3 = arg1->unk2;
            phi_v0 = arg2->unk2;
        }
        if (phi_a0 >= phi_t3) {
            if (phi_a0 >= phi_t5) {
                sp4A = phi_a0;
            } else {
                goto block_12;
            }
        } else if (phi_t3 >= phi_t5) {
            sp4A = phi_t3;
        } else {
block_12:
            sp4A = phi_t5;
        }
        if (phi_a1 >= phi_t4) {
            if (phi_a1 >= phi_v1) {
                sp48 = phi_a1;
            } else {
                goto block_19;
            }
        } else if (phi_t4 >= phi_v1) {
            sp48 = phi_t4;
        } else {
block_19:
            sp48 = phi_v1;
        }
        if (phi_a2 >= phi_a3) {
            if (phi_a2 >= phi_v0) {
                sp42 = phi_a2;
            } else {
                goto block_26;
            }
        } else if (phi_a3 >= phi_v0) {
            sp42 = phi_a3;
        } else {
block_26:
            sp42 = phi_v0;
        }
        if (phi_t3 >= phi_a0) {
            if (phi_t5 >= phi_a0) {
                sp44 = phi_a0;
            } else {
                goto block_33;
            }
        } else if (phi_t5 >= phi_t3) {
            sp44 = phi_t3;
        } else {
block_33:
            sp44 = phi_t5;
        }
        if (phi_a3 >= phi_a2) {
            if (phi_v0 >= phi_a2) {
                phi_t2 = phi_a2;
            } else {
                phi_t2 = phi_v0;
            }
        } else if (phi_v0 >= phi_a3) {
            phi_t2 = phi_a3;
        } else {
            phi_t2 = phi_v0;
        }
        if (phi_t4 >= phi_a1) {
            if (phi_v1 >= phi_a1) {
                phi_t1 = phi_a1;
            } else {
                phi_t1 = phi_v1;
            }
        } else if (phi_v1 >= phi_t4) {
            phi_t1 = phi_t4;
        } else {
            phi_t1 = phi_v1;
        }
        spAA = phi_v1;
        spB8 = phi_a2;
        spB2 = phi_a3;
        spAC = phi_v0;
        temp_v0 = spB2 - spB8;
        temp_v1 = spAA - phi_t4;
        spB6 = phi_a1;
        spBA = phi_a0;
        temp_a0_2 = phi_t4 - spB6;
        temp_a1_2 = spAC - spB2;
        temp_a2 = phi_t5 - phi_t3;
        temp_a3 = phi_t3 - spBA;
        temp_f12 = (temp_v0 * temp_v1) - (temp_a0_2 * temp_a1_2);
        temp_f18 = temp_f12 * temp_f12;
        sp10 = temp_f18;
        temp_f14 = (temp_a0_2 * temp_a2) - (temp_a3 * temp_v1);
        temp_f8 = temp_f14 * temp_f14;
        sp8 = temp_f8;
        temp_f16 = (temp_a3 * temp_a1_2) - (temp_v0 * temp_a2);
        temp_f4 = temp_f16 * temp_f16;
        sp0 = temp_f4;
        temp_f2 = sqrtf(temp_f18 + temp_f8 + temp_f4);
        if ((temp_f2 != 0.0) && ((temp_f0 = temp_f12 / temp_f2, sp58 = temp_f0, temp_f4_2 = temp_f14 / temp_f2, sp1C = (bitwise void *) temp_f4_2, sp54 = temp_f4_2, temp_f18_2 = temp_f16 / temp_f2, sp50 = temp_f18_2, sp4C = -((spBA * temp_f0) + (temp_f4_2 * spB8) + (temp_f18_2 * spB6)), (D_8015F59C == 0)) || (!(temp_f4_2 < D_802B9E64) && !(D_802B9E68 < temp_f4_2))) && ((D_8015F5A0 == 0) || !((bitwise f32) sp1C < D_802B9E6C) || !(D_802B9E70 < (bitwise f32) sp1C))) {
            temp_t0->unkA = sp4A;
            temp_t0->unk8 = phi_t1;
            temp_t0->unk6 = phi_t2;
            temp_t0->unk4 = sp44;
            temp_t0->unkC = sp42;
            temp_t0->unkE = sp48;
            if (sp44 < D_8015F6EA) {
                D_8015F6EA = sp44;
            }
            if (phi_t2 < D_8015F6EE) {
                D_8015F6EE = phi_t2;
            }
            if (phi_t1 < D_8015F6F2) {
                D_8015F6F2 = phi_t1;
            }
            if (D_8015F6E8 < sp4A) {
                D_8015F6E8 = sp4A;
            }
            if (D_8015F6EC < sp42) {
                D_8015F6EC = sp42;
            }
            if (D_8015F6F0 < sp48) {
                D_8015F6F0 = sp48;
            }
            temp_t0->unk1C = sp58;
            temp_t0->unk20 = sp54;
            temp_t0->unk24 = sp50;
            temp_t0->unk28 = sp4C;
            temp_t0->unk2 = arg3;
            D_8015F6FA = 0;
            D_8015F6FC = 0;
            temp_a3_2 = temp_t0->unk10->unk6;
            temp_v1_2 = temp_t0->unk14->unk6;
            temp_a0_3 = temp_t0->unk18->unk6;
            phi_a1_2 = arg4;
            if ((temp_a3_2 == 1) && (temp_v1_2 == 1) && (temp_a0_3 == 1)) {
                phi_t8 = (arg4 | 0x400) & 0xFFFF;
                goto block_81;
            }
            if ((temp_a3_2 == 2) && (temp_v1_2 == 2) && (temp_a0_3 == 2)) {
                phi_a1_2 = (arg4 | 0x800) & 0xFFFF;
            } else if ((temp_a3_2 == 3) && (temp_v1_2 == 3) && (temp_a0_3 == 3)) {
                phi_a1_2 = (arg4 | 0x1000) & 0xFFFF;
            } else if (D_8015F5A4 != 0) {
                phi_t8 = (arg4 | 0x200) & 0xFFFF;
block_81:
                phi_a1_2 = phi_t8;
            }
            temp_t0->unk0 = phi_a1_2;
            if ((sp10 <= sp8) && (phi_t9 = phi_a1_2 | 0x4000, (sp0 <= sp8))) {
                goto block_89;
            }
            if ((sp8 < sp10) && (sp0 <= sp10)) {
                temp_t0->unk0 = temp_t0->unk0 | 0x8000;
            } else {
                phi_t9 = temp_t0->unk0 | 0x2000;
block_89:
                temp_t0->unk0 = phi_t9;
            }
            D_8015F588 = D_8015F588 + 1;
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AE434.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AE434(s32, s32, s32, s8, s32); // extern
extern ? D_8015F668;

void func_802AEB14(s32 arg0, s8 arg1, u16 arg2) {
    func_802AE434(*(&D_8015F668 + ((((arg0 & 0xFF0000) >> 0x10) >> 1) * 4)), *(&D_8015F668 + ((((arg0 & 0xFF00) >> 8) >> 1) * 4)), *(&D_8015F668 + (((arg0 & 0xFF) >> 1) * 4)), arg1, arg2);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AEB14.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AE434(s32, s32, s32, s8, s32); // extern
extern ? D_8015F668;

void func_802AEBA4(s32 arg0, s32 arg1, s8 arg2, u16 arg3) {
    s32 sp28;
    s32 sp24;
    s32 sp20;

    sp28 = *(&D_8015F668 + ((((arg1 & 0xFF0000) >> 0x10) >> 1) * 4));
    sp24 = *(&D_8015F668 + ((((arg1 & 0xFF00) >> 8) >> 1) * 4));
    sp20 = *(&D_8015F668 + (((arg1 & 0xFF) >> 1) * 4));
    func_802AE434(*(&D_8015F668 + ((((arg0 & 0xFF0000) >> 0x10) >> 1) * 4)), *(&D_8015F668 + ((((arg0 & 0xFF00) >> 8) >> 1) * 4)), *(&D_8015F668 + (((arg0 & 0xFF) >> 1) * 4)), arg2, arg3);
    func_802AE434(sp28, sp24, sp20, arg2, arg3);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AEBA4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AE434(s32, s32, s32, s8, s32); // extern
extern ? D_8015F668;

void func_802AECA0(s32 arg0, s8 arg1, u16 arg2) {
    s32 sp2C;
    s32 sp24;
    s32 sp20;
    s32 temp_a0;
    s32 temp_a2;

    temp_a0 = *(&D_8015F668 + ((((arg0 & 0xFF0000) >> 0x10) >> 1) * 4));
    temp_a2 = *(&D_8015F668 + (((arg0 & 0xFF) >> 1) * 4));
    sp2C = temp_a0;
    sp24 = temp_a2;
    sp20 = *(&D_8015F668 + ((((arg0 & 0xFF000000) >> 0x18) >> 1) * 4));
    func_802AE434(temp_a0, *(&D_8015F668 + ((((arg0 & 0xFF00) >> 8) >> 1) * 4)), temp_a2, arg1, arg2);
    func_802AE434(temp_a0, sp24, sp20, arg1, arg2);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AECA0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_8015F668;
extern ? gSegmentTable;

void func_802AED6C(u32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a2;
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 phi_v0;
    s32 *phi_a0;
    s32 phi_v1;
    s32 phi_v0_2;
    void *phi_a0_2;
    s32 phi_v1_2;
    s32 phi_a2;
    s32 phi_a2_2;

    temp_v0 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
    phi_v0 = temp_v0;
    phi_v1 = 0;
    phi_v0_2 = temp_v0;
    phi_a2 = arg2;
    phi_v1_2 = 0;
    phi_a2_2 = arg2;
    if (arg1 != 0) {
        temp_t0 = arg1 & 3;
        if (temp_t0 != 0) {
            phi_a0 = (arg2 * 4) + &D_8015F668;
            do {
                *phi_a0 = phi_v0;
                temp_v1 = phi_v1 + 1;
                temp_v0_2 = phi_v0 + 0x10;
                temp_a2 = phi_a2_2 + 1;
                phi_v0 = temp_v0_2;
                phi_a0 += 4;
                phi_v1 = temp_v1;
                phi_v0_2 = temp_v0_2;
                phi_a2 = temp_a2;
                phi_v1_2 = temp_v1;
                phi_a2_2 = temp_a2;
            } while (temp_t0 != temp_v1);
            if (temp_v1 != arg1) {
                goto block_5;
            }
        } else {
block_5:
            phi_a0_2 = (phi_a2 * 4) + &D_8015F668;
            do {
                phi_a0_2->unk0 = phi_v0_2;
                temp_v0_3 = phi_v0_2 + 0x10;
                phi_a0_2->unk4 = temp_v0_3;
                temp_v0_4 = temp_v0_3 + 0x10;
                phi_a0_2->unk8 = temp_v0_4;
                temp_v0_5 = temp_v0_4 + 0x10;
                phi_a0_2->unkC = temp_v0_5;
                temp_v1_2 = phi_v1_2 + 4;
                phi_v0_2 = temp_v0_5 + 0x10;
                phi_a0_2 += 0x10;
                phi_v1_2 = temp_v1_2;
            } while (temp_v1_2 != arg1);
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AED6C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AEE1C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f18_3;
    f32 temp_f2;

    temp_f0 = arg6 - arg4;
    if (temp_f0 == 0.0f) {
        if (arg4 < arg0) {
            return 0;
        }
        if (arg1 < arg4) {
            return 0;
        }
        if ((arg7 - arg5) > 0.0f) {
            if ((arg5 < arg2) && (arg3 < arg7)) {
                return 1;
            }
            // Duplicate return node #36. Try simplifying control flow for better match
            return 0;
        }
        if ((arg7 < arg2) && (arg3 < arg5)) {
            return 1;
        }
        // Duplicate return node #36. Try simplifying control flow for better match
        return 0;
    }
    temp_f2 = arg7 - arg5;
    if (temp_f2 == 0.0f) {
        if (arg5 < arg2) {
            return 0;
        }
        if (arg3 < arg5) {
            return 0;
        }
        if (temp_f0 > 0.0f) {
            if ((arg4 < arg0) && (arg1 < arg6)) {
                return 1;
            }
            // Duplicate return node #36. Try simplifying control flow for better match
            return 0;
        }
        if ((arg6 < arg0) && (arg1 < arg4)) {
            return 1;
        }
        // Duplicate return node #36. Try simplifying control flow for better match
        return 0;
    }
    temp_f16 = temp_f0 / temp_f2;
    temp_f12 = arg4;
    temp_f14 = arg0;
    temp_f18 = (temp_f16 * (arg2 - arg5)) + temp_f12;
    if ((temp_f14 <= temp_f18) && (temp_f18 <= arg1)) {
        return 1;
    }
    temp_f18_2 = (temp_f16 * (arg3 - arg5)) + temp_f12;
    if ((temp_f14 <= temp_f18_2) && (temp_f18_2 <= arg1)) {
        return 1;
    }
    temp_f16_2 = temp_f2 / temp_f0;
    temp_f12_2 = arg5;
    temp_f14_2 = arg2;
    temp_f18_3 = (temp_f16_2 * (arg0 - arg4)) + temp_f12_2;
    if ((temp_f14_2 <= temp_f18_3) && (temp_f18_3 <= arg3)) {
        return 1;
    }
    temp_f0_2 = (temp_f16_2 * (arg1 - arg4)) + temp_f12_2;
    if ((temp_f14_2 <= temp_f0_2) && (temp_f0_2 <= arg3)) {
        return 1;
    }
    return 0;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AEE1C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802AEE1C(s16, s16, s16, s16, s32, s32, s32, s32); // extern

? func_802AF0FC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    s16 sp32;
    s16 sp30;
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_a3;
    s16 temp_a3_2;
    s16 temp_ra;
    s16 temp_t2;
    s16 temp_t3;
    s16 temp_t4;
    s16 temp_t5;
    void *temp_t0;
    void *temp_t1;
    void *temp_v0;
    void *temp_v1;

    temp_a0 = arg0;
    temp_a2 = arg2;
    temp_a1 = arg1;
    temp_a3 = arg3;
    temp_v0 = (arg4 * 0x2C) + D_8015F580;
    temp_v1 = temp_v0->unk10;
    temp_t0 = temp_v0->unk14;
    temp_t1 = temp_v0->unk18;
    temp_t2 = temp_v1->unk0;
    temp_t3 = temp_v1->unk4;
    temp_t4 = temp_t0->unk0;
    temp_t5 = temp_t0->unk4;
    temp_ra = temp_t1->unk0;
    sp28 = temp_t1->unk4;
    if ((temp_t2 >= temp_a0) && (temp_a1 >= temp_t2) && (temp_t3 >= temp_a2) && (temp_a3 >= temp_t3)) {
        return 1;
    }
    if ((temp_t4 >= temp_a0) && (temp_a1 >= temp_t4) && (temp_t5 >= temp_a2) && (temp_a3 >= temp_t5)) {
        return 1;
    }
    if ((temp_ra >= temp_a0) && (temp_a1 >= temp_ra) && (sp28 >= temp_a2) && (temp_a3 >= sp28)) {
        return 1;
    }
    sp2A = temp_ra;
    arg0 = temp_a0;
    arg1 = temp_a1;
    arg2 = temp_a2;
    arg3 = temp_a3;
    sp32 = temp_t2;
    sp30 = temp_t3;
    sp2E = temp_t4;
    sp2C = temp_t5;
    temp_a0_2 = arg0;
    temp_a1_2 = arg1;
    temp_a2_2 = arg2;
    temp_a3_2 = arg3;
    if (func_802AEE1C(temp_a0, temp_a1, temp_a2, temp_a3, temp_t2, temp_t3, temp_t4, temp_t5) == 1) {
        return 1;
    }
    sp2A = temp_ra;
    arg0 = temp_a0_2;
    arg1 = temp_a1_2;
    arg2 = temp_a2_2;
    arg3 = temp_a3_2;
    sp32 = temp_t2;
    sp30 = temp_t3;
    if (func_802AEE1C(temp_a0_2, temp_a1_2, temp_a2_2, temp_a3_2, temp_t4, temp_t5, temp_ra, sp28) == 1) {
        return 1;
    }
    if (func_802AEE1C(arg0, arg1, arg2, arg3, temp_ra, sp28, temp_t2, temp_t3) == 1) {
        return 1;
    }
    return 0;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF0FC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802AF0FC(s16, s16, s16, s16, s32); // extern
extern ? D_8014F110;
extern ? D_80150110;
extern s32 D_8015F584;
extern u16 D_8015F58A;
extern s32 gPrevLoadedAddress;

void func_802AF314(void) {
    s32 sp4C;
    ? *temp_v0;
    s16 temp_a1;
    s16 temp_a3;
    s16 temp_s1;
    s16 temp_s2;
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    void *temp_v0_2;
    void *temp_v0_3;
    ? *phi_v0;
    s32 phi_s7;
    s32 phi_v1;
    s32 phi_s3;
    s32 phi_s5;
    s32 phi_s0;
    s32 phi_v1_2;
    s32 phi_v1_3;

    phi_v0 = &D_8014F110;
    do {
        temp_v0 = phi_v0 + 0x10;
        temp_v0->unk-A = 0;
        temp_v0->unk-6 = 0;
        temp_v0->unk-2 = 0;
        temp_v0->unk-E = 0;
        phi_v0 = temp_v0;
    } while (temp_v0 != &D_80150110);
    D_8015F58A = 0;
    D_8015F584 = gPrevLoadedAddress;
    temp_s6 = (D_8015F6E8 - D_8015F6EA) / 0x20;
    temp_fp = (D_8015F6F0 - D_8015F6F2) / 0x20;
    phi_s7 = 0;
    phi_v1 = D_8015F588;
    do {
        sp4C = temp_fp * phi_s7;
        phi_s5 = 0;
loop_4:
        temp_s2 = (D_8015F6F2 + sp4C) - 0x14;
        temp_s1 = (D_8015F6EA + (temp_s6 * phi_s5)) - 0x14;
        phi_s3 = 0;
        phi_s0 = 0;
        phi_v1_3 = phi_v1;
        phi_v1_2 = phi_v1;
        if (phi_v1 > 0) {
            do {
                temp_a3 = temp_s2 + temp_fp + 0x28;
                temp_v0_2 = phi_s3 + D_8015F580;
                if ((temp_v0_2->unkE >= temp_s2) && (temp_a3 >= temp_v0_2->unk8)) {
                    temp_a1 = temp_s1 + temp_s6 + 0x28;
                    if ((temp_v0_2->unkA >= temp_s1) && (temp_a1 >= temp_v0_2->unk4)) {
                        if (func_802AF0FC(temp_s1, temp_a1, temp_s2, temp_a3, phi_s0) == 1) {
                            temp_v0_3 = (((phi_s7 << 5) + phi_s5) * 4) + &D_8014F110;
                            if (temp_v0_3->unk2 == 0) {
                                temp_v0_3->unk0 = D_8015F58A;
                            }
                            temp_v0_3->unk2 = temp_v0_3->unk2 + 1;
                            *(D_8015F584 + (D_8015F58A * 2)) = phi_s0;
                            D_8015F58A = D_8015F58A + 1;
                        }
                        phi_v1_2 = D_8015F588;
                    }
                }
                temp_s0 = phi_s0 + 1;
                phi_s3 += 0x2C;
                phi_s0 = temp_s0;
                phi_v1_3 = phi_v1_2;
            } while (temp_s0 < phi_v1_2);
        }
        temp_s5 = phi_s5 + 1;
        phi_v1 = phi_v1_3;
        phi_s5 = temp_s5;
        phi_v1 = phi_v1_3;
        if (temp_s5 != 0x20) {
            goto loop_4;
        }
        temp_s7 = phi_s7 + 1;
        phi_s7 = temp_s7;
    } while (temp_s7 != 0x20);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF314.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AF5D8(?, ?); // extern

void func_802AF588(void) {
    func_802AF5D8(-1, 0xFF);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF588.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AF5D8(s8, ?); // extern

void func_802AF5AC(s8 arg1) {
    func_802AF5D8(arg1, 0xFF);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF5AC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AEB14(u32, s8, s32); // extern
? func_802AEBA4(u32, u32, s8, s32); // extern
? func_802AECA0(u32, s8, s32); // extern
? func_802AED6C(u32, s32, u32); // extern
extern s16 D_8015F6FA;
extern s16 D_8015F6FC;
extern ? gSegmentTable;

void func_802AF5D8(u32 arg0, s8 arg1, s32 arg2) {
    s32 temp_s5;
    s32 temp_v0;
    u32 temp_s0;
    u32 temp_s1;
    void *phi_s3;
    s32 phi_s6;
    s32 phi_s6_2;

    D_8015F6FA = 0;
    temp_s5 = arg2 & 0xFFFF;
    D_8015F6FC = 0;
    phi_s3 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
    phi_s6_2 = 0;
loop_1:
    temp_s0 = phi_s3->unk0;
    temp_s1 = phi_s3->unk4;
    temp_v0 = temp_s0 & 0xFF000000;
    if (temp_v0 == 0x6000000) {
        func_802AF5D8(temp_s1, arg1, temp_s5 & 0xFFFF);
        phi_s6 = phi_s6_2 + 1;
        goto block_12;
    }
    if (temp_v0 == 0x4000000) {
        func_802AED6C(temp_s1, (temp_s0 >> 0xA) & 0x3F, ((temp_s0 >> 0x10) & 0xFF) >> 1);
        phi_s6 = phi_s6_2 + 1;
        goto block_12;
    }
    if (temp_v0 == 0xBF000000) {
        D_8015F58C += 1;
        func_802AEB14(temp_s1, arg1, temp_s5 & 0xFFFF);
        phi_s6 = phi_s6_2 + 1;
        goto block_12;
    }
    if (temp_v0 == 0xB1000000) {
        D_8015F58C += 2;
        func_802AEBA4(temp_s0, temp_s1, arg1, temp_s5 & 0xFFFF);
        phi_s6 = phi_s6_2 + 1;
        goto block_12;
    }
    if (temp_v0 == 0xB5000000) {
        D_8015F58C += 2;
        func_802AECA0(temp_s1, arg1, temp_s5 & 0xFFFF);
        phi_s6 = phi_s6_2 + 1;
        goto block_12;
    }
    phi_s6 = phi_s6_2 + 1;
    if (temp_v0 != 0xB8000000) {
block_12:
        phi_s3 += 8;
        phi_s6_2 = phi_s6;
        if (phi_s6 != 0x1FFF) {
            goto loop_1;
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF5D8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? gSegmentTable;

void func_802AF7B4(u32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    s32 *phi_v0;

    phi_v0 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
loop_1:
    temp_v1 = *phi_v0 & 0xFF000000;
    if (temp_v1 != 0xB8000000) {
        if (temp_v1 == 0xF2000000) {
            *phi_v0 = ((arg1 << 0xC) & 0xFFF000) | 0xF2000000 | (arg2 & 0xFFF);
            return;
        }
        phi_v0 += 8;
        goto loop_1;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF7B4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? gSegmentTable;

void func_802AF83C(u32 arg0, u32 arg1, ? arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    u32 temp_v1;
    void *phi_v0;
    u32 phi_v1;

    phi_v0 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
    phi_v1 = 0;
    if (arg1 != 0) {
        do {
            temp_v1 = phi_v1 + 1;
            phi_v1 = temp_v1;
            if (arg4 != 0) {
                phi_v0->unkC = arg4;
                phi_v0->unkD = arg5;
                phi_v0->unkE = arg6;
            }
            phi_v0->unkF = arg3;
            phi_v0 += 0x10;
        } while (temp_v1 < arg1);
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF83C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AF83C(u32, s32, u32, s8, s32, s32, s32); // extern
extern ? gSegmentTable;

void func_802AF8BC(u32 arg0, s8 arg1, s32 arg2, s32 arg3, u8 arg4) {
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v1;
    u32 temp_a0;
    u32 temp_v0;
    void *phi_s0;

    temp_s2 = arg2 & 0xFF;
    temp_s3 = arg3 & 0xFF;
    phi_s0 = *(&gSegmentTable + ((arg0 >> 0x18) * 4)) + (arg0 & 0xFFFFFF) + 0x80000000;
loop_1:
    temp_v0 = phi_s0->unk0;
    temp_a0 = phi_s0->unk4;
    temp_v1 = temp_v0 & 0xFF000000;
    if (temp_v1 != 0xB8000000) {
        if (temp_v1 == 0x6000000) {
            func_802AF8BC(temp_a0, arg1, temp_s2 & 0xFF, temp_s3 & 0xFF, arg4);
            phi_s0 += 8;
        } else {
            if (temp_v1 == 0x4000000) {
                func_802AF83C(temp_a0, (temp_v0 >> 0xA) & 0x3F, ((temp_v0 >> 0x10) & 0xFF) >> 1, arg1, temp_s2, temp_s3, arg4);
            }
            phi_s0 += 8;
        }
        goto loop_1;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF8BC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_802AF9F0(void *arg0, f32 arg1, void *arg2) {
    arg2->unk0 = arg2->unk0 - (arg0->unk0 * arg1);
    arg2->unk4 = arg2->unk4 - (arg0->unk4 * arg1);
    arg2->unk8 = arg2->unk8 - (arg0->unk8 * arg1);
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AF9F0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
f32 func_802ABE30(f32, f32, f32, u16); // extern
s32 func_802AC760(s16 *, f32, f32, f32, f32, s32, f32, f32, f32); // extern
s32 func_802ACBA4(s16 *, f32, f32, f32, f32, s32, f32, f32, f32); // extern
s32 func_802AD278(s16 *, f32, f32, f32, f32, s32, f32, f32, f32); // extern
? func_802AF9F0(f32, ? *, ?32, void *); // extern
extern ? D_8014F110;
extern s32 D_8015F584;

? func_802AFA34(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4) {
    ? sp128;
    ? sp11C;
    ? sp110;
    ?32 sp10C;
    ?32 sp108;
    ?32 sp104;
    s16 sp102;
    s16 sp100;
    s16 spFE;
    s16 spFC;
    s16 spFA;
    s16 spF8;
    f32 spD4;
    s32 sp8C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    s16 temp_v0_2;
    s16 temp_v1;
    s32 temp_f10;
    s32 temp_f16;
    s32 temp_s4;
    s32 temp_t6;
    u16 temp_s0;
    u16 temp_v0_3;
    u16 temp_v1_3;
    u8 temp_v0;
    void *temp_v0_4;
    void *temp_v1_2;
    u16 phi_s1;
    s16 *phi_s7;
    f32 phi_f30;
    s32 phi_s2;

    sp104 = 0x447A0000;
    sp108 = 0x447A0000;
    sp10C = 0x447A0000;
    temp_f20 = arg0->unk70;
    spFE = 0x1388;
    sp100 = 0x1388;
    sp102 = 0x1388;
    spF8 = 0;
    spFA = 0;
    spFC = 0;
    temp_v0 = arg1->unkD;
    temp_f22 = arg1->unk0;
    temp_f24 = arg1->unk4;
    temp_f26 = arg1->unk8;
    if (temp_v0 != 0) {
        phi_s7 = &spF8;
        if (temp_v0 != 0x20) {
            phi_s7 = &spF8;
            if (temp_v0 != 0x40) {
                phi_s7 = &spF8;
                if (temp_v0 != 0x80) {
                    goto block_21;
                }
                if ((func_802AD278(&spF8, temp_f20, temp_f22, temp_f24, temp_f26, arg1->unkE, arg2, arg3, arg4) == 1) && (temp_f0 = func_802ABE30(temp_f22, temp_f24, temp_f26, arg1->unkE), temp_f2 = arg0->unk18, !(temp_f2 < temp_f0)) && !((2.0f * temp_f20) < (temp_f2 - temp_f0))) {
                    arg1->unk10 = temp_f0;
                    func_802AF9F0(temp_f0, &sp11C, sp108, arg1);
                    return 1;
                }
                phi_f30 = 2.0f;
                goto block_22;
            }
            if ((func_802AC760(&spF8, temp_f20, temp_f22, temp_f24, temp_f26, arg1->unkE, arg2, arg3, arg4) == 1) && (temp_f0_2 = func_802ABE30(temp_f22, temp_f24, temp_f26, arg1->unkE), temp_f2_2 = arg0->unk18, !(temp_f2_2 < temp_f0_2)) && !((2.0f * temp_f20) < (temp_f2_2 - temp_f0_2))) {
                arg1->unk10 = temp_f0_2;
                func_802AF9F0(temp_f0_2, &sp128, sp10C, arg1);
                return 1;
            }
            phi_f30 = 2.0f;
            goto block_22;
        }
        if ((func_802ACBA4(&spF8, temp_f20, temp_f22, temp_f24, temp_f26, arg1->unkE, arg2, arg3, arg4) == 1) && (temp_f0_3 = func_802ABE30(temp_f22, temp_f24, temp_f26, arg1->unkE), temp_f2_3 = arg0->unk18, !(temp_f2_3 < temp_f0_3)) && !((2.0f * temp_f20) < (temp_f2_3 - temp_f0_3))) {
            arg1->unk10 = temp_f0_3;
            func_802AF9F0(temp_f0_3, &sp110, sp104, arg1);
            return 1;
        }
        phi_f30 = 2.0f;
        goto block_22;
    }
block_21:
    phi_s7 = &spF8;
    phi_f30 = 2.0f;
block_22:
    temp_v0_2 = D_8015F6EA;
    temp_v1 = D_8015F6F2;
    temp_f10 = (temp_f22 - temp_v0_2) / ((D_8015F6E8 - temp_v0_2) / 0x20);
    temp_f16 = (temp_f26 - temp_v1) / ((D_8015F6F0 - temp_v1) / 0x20);
    if (temp_f10 < 0) {
        goto block_57;
    }
    if (temp_f16 < 0) {
        goto block_57;
    }
    if (temp_f10 >= 0x20) {
        goto block_57;
    }
    if (temp_f16 >= 0x20) {
        goto block_57;
    }
    temp_v1_2 = ((temp_f10 + (temp_f16 << 5)) * 4) + &D_8014F110;
    temp_v0_3 = temp_v1_2->unk2;
    sp8C = temp_v0_3;
    if (temp_v0_3 == 0) {
        goto block_57;
    }
    phi_s1 = temp_v1_2->unk0;
    phi_s2 = 0;
    if (sp8C > 0) {
loop_34:
        temp_s0 = *(D_8015F584 + (phi_s1 * 2));
        temp_s4 = temp_s0 * 0x2C;
        temp_v0_4 = D_8015F580 + temp_s4;
        temp_v1_3 = temp_v0_4->unk0;
        if ((temp_v1_3 & 0x4000) != 0) {
            if ((arg1->unkE != temp_s0) && (func_802AC760(phi_s7, temp_f20, temp_f22, temp_f24, temp_f26, temp_s0, arg2, arg3, arg4) == 1) && (temp_f0_4 = func_802ABE30(temp_f22, temp_f24, temp_f26, temp_s0 & 0xFFFF), temp_f2_4 = arg0->unk18, !(temp_f2_4 < temp_f0_4)) && !((phi_f30 * temp_f20) < (temp_f2_4 - temp_f0_4))) {
                spD4 = temp_f0_4;
                func_802AF9F0(temp_f0_4, &sp128, sp10C, arg1);
                arg1->unk10 = temp_f0_4;
                arg1->unkD = 0x40;
                arg1->unkE = temp_s0;
                arg1->unkC = (D_8015F580 + temp_s4)->unk2;
                if ((*(D_8015F580 + temp_s4) & 0x1000) != 0) {
                    arg1->unk14 = 1;
                    return 1;
                }
                arg1->unk14 = 0;
                return 1;
            }
            goto block_55;
        }
        if ((temp_v1_3 & 0x8000) != 0) {
            if ((temp_v0_4->unk20 != 0.0f) && (arg1->unkE != temp_s0) && (func_802AD278(phi_s7, temp_f20, temp_f22, temp_f24, temp_f26, temp_s0, arg2, arg3, arg4) == 1) && (temp_f0_5 = func_802ABE30(temp_f22, temp_f24, temp_f26, temp_s0 & 0xFFFF), temp_f2_5 = arg0->unk18, !(temp_f2_5 < temp_f0_5)) && !((phi_f30 * temp_f20) < (temp_f2_5 - temp_f0_5))) {
                arg1->unk10 = temp_f0_5;
                func_802AF9F0(temp_f0_5, &sp11C, sp108, arg1);
                arg1->unk10 = func_802ABE30(temp_f22, temp_f24, temp_f26, temp_s0 & 0xFFFF);
                arg1->unkD = 0x80;
                arg1->unkE = temp_s0;
                arg1->unkC = (D_8015F580 + temp_s4)->unk2;
                return 1;
            }
            goto block_55;
        }
        if ((temp_v0_4->unk20 != 0.0f) && (arg1->unkE != temp_s0) && (func_802ACBA4(phi_s7, temp_f20, temp_f22, temp_f24, temp_f26, temp_s0, arg2, arg3, arg4) == 1) && (temp_f0_6 = func_802ABE30(temp_f22, temp_f24, temp_f26, temp_s0 & 0xFFFF), temp_f2_6 = arg0->unk18, !(temp_f2_6 < temp_f0_6)) && !((phi_f30 * temp_f20) < (temp_f2_6 - temp_f0_6))) {
            arg1->unk10 = temp_f0_6;
            func_802AF9F0(temp_f0_6, &sp110, sp104, arg1);
            arg1->unkD = 0x20;
            arg1->unkE = temp_s0;
            arg1->unkC = (D_8015F580 + temp_s4)->unk2;
            return 1;
        }
block_55:
        temp_t6 = (phi_s2 + 1) & 0xFFFF;
        phi_s1 = (phi_s1 + 1) & 0xFFFF;
        phi_s2 = temp_t6;
        if (temp_t6 >= sp8C) {
            goto block_56;
        }
        goto loop_34;
    }
block_56:
    arg1->unk10 = temp_f24;
    arg1->unkC = 0;
block_57:
    return 0;
}
#else
GLOBAL_ASM("asm/non_matchings/memory/func_802AFA34.s")
#endif
