#include <ultra64.h>
#include <macros.h>

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_8003DC40(void *arg0) {
    arg0->unkDAC = 1.0f;
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003DC40.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(void *, s32, f32, f32); // extern
? func_80031F48(void *, ?); // extern
? func_8008D554(void *); // extern
? func_802B63B8(void *, void *); // extern
extern f64 D_800EDF30;
extern f32 D_800EDF38;

void func_8003E048(void *arg0, void *arg1, void *arg3, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    *arg5 = *arg5 + (arg1->unk0 * arg0->unk124 * 1.0f);
    *arg6 = *arg6 + ((arg1->unk4 * arg0->unk124) * D_800EDF30);
    *arg7 = *arg7 + (arg1->unk8 * arg0->unk124 * 1.0f);
    func_8002A5F4(arg1, *arg4, 1.0f, 2.0f);
    if (arg0->unk144 <= D_800EDF38) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0xB4;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0xB4;
        func_80031F48(arg0, 0x40800000);
        arg0->unkDAC = 0.5f;
        if ((arg0->unkBC & 0x2000) != 0) {
            func_8008D554(arg0);
            arg0->unk9C = arg0->unk9C / 2.0f;
            arg0->unk8C = arg0->unk8C / 2.0f;
        }
    } else if ((((arg0->unk94 / 18.0f) * 216.0f) > 20.0f) || ((arg0->unkBC & 0x10000) == 0x10000)) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x32;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x3C;
    } else {
        arg3->unk0 = 0.0f;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x32;
    }
    arg3->unk4 = 0.0f;
    func_802B63B8(arg3, arg0 + 0x174);
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003E048.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(void *, s32, ?, f32); // extern
? func_80031F48(void *, ?); // extern
? func_8008D554(void *); // extern
? func_802B63B8(void *, void *); // extern
extern f64 D_800EDF40;
extern f32 D_800EDF48;

void func_8003E37C(void *arg0, void *arg1, void *arg3, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    *arg5 = *arg5 + (arg1->unk0 * arg0->unk124 * 1.0f);
    *arg6 = *arg6 + ((arg1->unk4 * arg0->unk124) * D_800EDF40);
    *arg7 = *arg7 + (arg1->unk8 * arg0->unk124 * 1.0f);
    func_8002A5F4(arg1, *arg4, 0x3F000000, 2.0f);
    if ((arg0->unk144 <= D_800EDF48) || (arg0->unkF8 == 0xC)) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0xB4;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0xB4;
        if (((arg0->unk94 / 18.0f) * 216.0f) >= 8.0f) {
            func_80031F48(arg0, 0x40A00000);
        }
        arg0->unkDAC = 0.5f;
        if ((arg0->unkBC & 0x2000) != 0) {
            func_8008D554(arg0);
            arg0->unk9C = arg0->unk9C / 2.0f;
            arg0->unk8C = arg0->unk8C / 2.0f;
        }
    } else if ((((arg0->unk94 / 18.0f) * 216.0f) > 20.0f) || ((arg0->unkBC & 0x10000) == 0x10000)) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x32;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0x32;
    } else {
        arg3->unk0 = 0.0f;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0x32;
    }
    arg3->unk4 = 0.0f;
    func_802B63B8(arg3, arg0 + 0x174);
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003E37C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(void *, s32, ?, f32); // extern
? func_80031F48(void *, ?); // extern
? func_8003DC40(void *); // extern
? func_802B63B8(void *, void *); // extern
extern f64 D_800EDF50;
extern f32 D_800EDF58;

void func_8003E6EC(void *arg0, void *arg1, void *arg3, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    *arg5 = *arg5 + (arg1->unk0 * arg0->unk124 * 1.0f);
    *arg6 = *arg6 + ((arg1->unk4 * arg0->unk124) * D_800EDF50);
    *arg7 = *arg7 + (arg1->unk8 * arg0->unk124 * 1.0f);
    func_8002A5F4(arg1, *arg4, 0x3F000000, 2.0f);
    if (arg0->unk144 <= D_800EDF58) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0xB4;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0xB4;
        func_80031F48(arg0, 0x40800000);
        func_8003DC40(arg0);
    } else if ((((arg0->unk94 / 18.0f) * 216.0f) > 20.0f) || ((arg0->unkBC & 0x10000) == 0x10000)) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x32;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x3C;
    } else {
        arg3->unk0 = 0.0f;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x32;
    }
    arg3->unk4 = 0.0f;
    func_802B63B8(arg3, arg0 + 0x174);
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003E6EC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(void *, s32, ?, f32); // extern
? func_80031F48(void *, ?); // extern
? func_8003DC40(void *); // extern
? func_802B63B8(void *, void *); // extern
extern f64 D_800EDF60;
extern f32 D_800EDF68;

void func_8003E9EC(void *arg0, void *arg1, void *arg3, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    s32 phi_v0;

    *arg5 = *arg5 + (arg1->unk0 * arg0->unk124 * 1.0f);
    *arg6 = *arg6 + ((arg1->unk4 * arg0->unk124) * D_800EDF60);
    *arg7 = *arg7 + (arg1->unk8 * arg0->unk124 * 1.0f);
    func_8002A5F4(arg1, *arg4, 0x3F99999A, 2.0f);
    if (arg0->unk144 <= D_800EDF68) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x78;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0xB4;
        func_80031F48(arg0, 0x40800000);
        func_8003DC40(arg0);
    } else {
        if ((((arg0->unk94 / 18.0f) * 216.0f) > 20.0f) || ((arg0->unkBC & 0x10000) == 0x10000)) {
            if ((arg0->unk1D4 == 1) || (arg0->unk1EC == 1) || (arg0->unk1BC == 1) || (arg0->unk1A4 == 1)) {
                arg3->unk0 = (arg0->unk206 / 0xB6) * 5;
            } else {
                arg3->unk0 = (arg0->unk206 / 0xB6) * 0x28;
            }
            arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x28;
            phi_v0 = 0xB6;
        } else {
            arg3->unk0 = 0.0f;
            arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x32;
            phi_v0 = 0xB6;
        }
        if ((arg0->unkBC & 0x10000) != 0) {
            arg3->unk0 = (arg0->unk206 / phi_v0) * 0x78;
            arg3->unk8 = (arg0->unkC4 / phi_v0) * -0xB4;
        }
    }
    arg3->unk4 = 0.0f;
    func_802B63B8(arg3, arg0 + 0x174);
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003E9EC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(void *, s32, ?, f32); // extern
? func_80031F48(void *, ?); // extern
? func_8003DC40(void *); // extern
? func_802B63B8(void *, void *); // extern
extern f64 D_800EDF70;
extern f32 D_800EDF78;

void func_8003EE2C(void *arg0, void *arg1, void *arg3, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    *arg5 = *arg5 + (arg1->unk0 * arg0->unk124 * 1.0f);
    *arg6 = *arg6 + ((arg1->unk4 * arg0->unk124) * D_800EDF70);
    *arg7 = *arg7 + (arg1->unk8 * arg0->unk124 * 1.0f);
    func_8002A5F4(arg1, *arg4, 0x3F000000, 2.0f);
    if (arg0->unk144 <= D_800EDF78) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x78;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0xB4;
        func_80031F48(arg0, 0x40800000);
        func_8003DC40(arg0);
    } else if ((((arg0->unk94 / 18.0f) * 216.0f) > 20.0f) || ((arg0->unkBC & 0x10000) == 0x10000)) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x32;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x3C;
    } else {
        arg3->unk0 = 0.0f;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x32;
    }
    arg3->unk4 = 0.0f;
    func_802B63B8(arg3, arg0 + 0x174);
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003EE2C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(void *, s32, ?, f32); // extern
? func_80031F48(void *, ?); // extern
? func_802B63B8(void *, void *); // extern
extern f64 D_800EDF80;
extern f32 D_800EDF88;

void func_8003F138(void *arg0, void *arg1, void *arg3, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    *arg5 = *arg5 + (arg1->unk0 * arg0->unk124 * 1.0f);
    *arg6 = *arg6 + ((arg1->unk4 * arg0->unk124) * D_800EDF80);
    *arg7 = *arg7 + (arg1->unk8 * arg0->unk124 * 1.0f);
    func_8002A5F4(arg1, *arg4, 0x3F000000, 2.0f);
    if (arg0->unkF8 == 8) {
        arg0->unk44 = arg0->unk44 & ~1;
    }
    if (arg0->unk144 <= D_800EDF88) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0xC8;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0xC8;
        func_80031F48(arg0, 0x40800000);
        arg0->unkDAC = 0.5f;
        arg3->unk0 = 0.0f;
    } else if ((((arg0->unk94 / 18.0f) * 216.0f) > 20.0f) || ((arg0->unkBC & 0x10000) == 0x10000)) {
        arg3->unk0 = (arg0->unk206 / 0xB6) * 0x78;
        arg3->unk0 = 0.0f;
        arg3->unk8 = -(arg0->unkC4 / 0xB6) * 0x78;
    } else {
        arg3->unk0 = 0.0f;
        arg3->unk8 = (arg0->unkC4 / 0xB6) * -0x32;
    }
    arg3->unk4 = 0.0f;
    arg3->unk8 = 0.0f;
    func_802B63B8(arg3, arg0 + 0x174);
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003F138.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit bd0364fa19633bd6201f8007e2d0a7ed87825909
? func_8002A5F4(void *, f32, ?, f32);               /* extern */
? func_8003E048(Player *, void *, f32 *, f32 *, f32 *, f32 *); /* extern */
? func_8003E37C(Player *, void *, f32 *, f32 *, f32 *, f32 *); /* extern */
? func_8003E6EC(Player *, void *, f32 *, f32 *, f32 *, f32 *); /* extern */
? func_8003E9EC(Player *, void *, f32 *, f32 *, f32 *, f32 *); /* extern */
? func_8003EE2C(Player *, void *, f32 *, f32 *, f32 *, f32 *); /* extern */
? func_8003F138(Player *, void *, f32 *, f32 *, f32 *, f32 *); /* extern */
u16 gCurrentCourseId;                               /* unable to generate initializer */

void func_8003F46C(Player *arg0, void *arg1, s32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg6, f32 *arg7) {
    u16 temp_t9;

    arg1->unk0 = -arg0->unk_140;
    arg1->unk4 = -arg0->unk_144;
    arg1->unk8 = -arg0->unk_148;
    if ((arg0->unk_144 < 0.0f) && ((arg0->unk_0CA & 2) == 0)) {
        *arg7 += arg1->unk0 * arg0->unk_124 * 1.0f;
        *arg6 += arg1->unk4 * arg0->unk_124 * 1.0f;
        *arg7 += arg1->unk8 * arg0->unk_124 * 1.0f;
        func_8002A5F4(arg1, *arg6, 0x3F99999A, 0.0f);
        arg0->kartHopJerk = 0.0f;
        arg0->kartHopAcceleration = 0.0f;
        arg0->kartHopVelocity = 0.0f;
        return;
    }
    temp_t9 = gCurrentCourseId;
    switch (temp_t9) {
    case 0:
        func_8003E048(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    case 1:
    case 6:
        func_8003E37C(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    case 2:
        func_8003E6EC(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    case 8:
        func_8003E9EC(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    case 14:
        func_8003EE2C(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    case 18:
        func_8003F138(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    default:
        func_8003E048(arg0, arg1, arg6, arg7, arg6, arg7);
        break;
    }
    if (arg0->unk_0BC & 0x10000) {
        arg0->unk_DAC = 0.5f;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003F46C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(f32, void *, s32, f32, f32); // extern
extern f64 D_800EDFD8;
extern f64 D_800EDFE0;
extern f64 D_800EDFE8;
extern f64 D_800EDFF0;
extern f64 D_800EDFF8;

void func_8003F734(void *arg0, void *arg1, void *arg2, s32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f12;
    f32 temp_f14;
    s32 temp_v0;
    s32 temp_v0_2;
    f32 phi_f2;

    arg1->unk0 = -arg0->unk128;
    arg1->unk4 = -arg0->unk12C;
    arg1->unk8 = -arg0->unk130;
    temp_f0 = arg0->unk12C;
    phi_f2 = 0.0f;
    phi_f2 = 0.0f;
    if (temp_f0 == 0.0f) {
        *arg4 = *arg4 + (arg1->unk0 * arg0->unk11C * 1.0f);
        *arg5 = *arg5 + ((arg1->unk4 * arg0->unk11C) * D_800EDFD8);
        *arg6 = *arg6 + (arg1->unk8 * arg0->unk11C * 1.0f);
        if ((arg0->unkC4 < 0) && (((arg0->unk94 / 18.0f) * 216.0f) < 10.0f)) {
            func_8002A5F4(1.0f, arg1, *arg3, 2.5f, 0.0f);
        } else {
            func_8002A5F4(1.0f, arg1, *arg3, 0.5f, 0.0f);
        }
        phi_f2 = 0.0f;
        goto block_16;
    }
    if (temp_f0 <= 0.5) {
        *arg4 = *arg4 + (arg1->unk0 * arg0->unk11C * 1.0f);
        *arg5 = *arg5 + ((arg1->unk4 * arg0->unk11C) * D_800EDFE0);
        *arg6 = *arg6 + (arg1->unk8 * arg0->unk11C * 1.0f);
        func_8002A5F4(1.0f, arg1, *arg3, 1.0f, 0.0f);
        temp_v0 = arg0->unkBC;
        if (((temp_v0 << 0xF) >= 0) && ((temp_v0 & 8) == 0)) {
            arg2->unk4 = arg2->unk4 * D_800EDFE8;
            goto block_16;
        }
    } else {
        *arg4 = *arg4 + (arg1->unk0 * arg0->unk11C * 1.0f);
        temp_f0_2 = arg1->unk4 * arg0->unk11C;
        if (temp_f0_2 < 0.0f) {
            *arg5 = *arg5 + (temp_f0_2 * D_800EDFF0);
        } else {
            *arg5 = *arg5 + (temp_f0_2 * 0.0f);
        }
        *arg6 = *arg6 + (arg1->unk8 * arg0->unk11C * 1.0f);
        func_8002A5F4(1.0f, arg1, *arg3, 1.2f, 0.0f);
        temp_v0_2 = arg0->unkBC;
        if (((temp_v0_2 << 0xF) >= 0) && ((temp_v0_2 & 8) == 0)) {
            arg2->unk4 = arg2->unk4 * D_800EDFF8;
block_16:
        }
    }
    arg0->unkBC = arg0->unkBC & ~0x10;
    temp_f0_3 = arg0->unk11C;
    temp_f12 = arg1->unk0 * temp_f0_3;
    temp_f14 = arg1->unk8 * temp_f0_3;
    if (((phi_f2 <= temp_f12) && (phi_f2 <= temp_f14)) || ((temp_f12 < phi_f2) && (phi_f2 <= temp_f14))) {
        temp_f0_4 = arg0->unk70 / 2.0f;
        arg0->unk218 = (*arg4 - temp_f12) - temp_f0_4;
        arg0->unk21C = (*arg6 - temp_f14) - temp_f0_4;
    }
    if (((temp_f12 < phi_f2) && (temp_f14 < phi_f2)) || ((phi_f2 <= temp_f12) && (temp_f14 < phi_f2))) {
        temp_f0_5 = arg0->unk70 / 2.0f;
        arg0->unk218 = *arg4 + temp_f12 + temp_f0_5;
        arg0->unk21C = *arg6 + temp_f14 + temp_f0_5;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003F734.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8002A5F4(f32, void *, s32, f32, f32); // extern
extern f64 D_800EE000;
extern f64 D_800EE008;
extern f64 D_800EE010;
extern f64 D_800EE018;
extern f64 D_800EE020;

void func_8003FBAC(void *arg0, void *arg1, void *arg2, s32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f12;
    f32 temp_f14;
    s32 temp_v0;
    s32 temp_v0_2;
    f32 phi_f2;

    arg1->unk0 = -arg0->unk134;
    arg1->unk4 = -arg0->unk138;
    arg1->unk8 = -arg0->unk13C;
    temp_f0 = arg0->unk138;
    phi_f2 = 0.0f;
    phi_f2 = 0.0f;
    if (temp_f0 == 0.0f) {
        *arg4 = *arg4 + (arg1->unk0 * arg0->unk120 * 1.0f);
        *arg5 = *arg5 + ((arg1->unk4 * arg0->unk120) * D_800EE000);
        *arg6 = *arg6 + (arg1->unk8 * arg0->unk120 * 1.0f);
        if ((arg0->unkC4 < 0) && (((arg0->unk94 / 18.0f) * 216.0f) < 10.0f)) {
            func_8002A5F4(1.0f, arg1, *arg3, 1.5f, 0.0f);
        } else {
            func_8002A5F4(1.0f, arg1, *arg3, 0.5f, 0.0f);
        }
        phi_f2 = 0.0f;
        goto block_16;
    }
    if (temp_f0 <= 0.5) {
        *arg4 = *arg4 + (arg1->unk0 * arg0->unk120 * 1.0f);
        *arg5 = *arg5 + ((arg1->unk4 * arg0->unk120) * D_800EE008);
        *arg6 = *arg6 + (arg1->unk8 * arg0->unk120 * 1.0f);
        func_8002A5F4(1.0f, arg1, *arg3, 1.0f, 0.0f);
        temp_v0 = arg0->unkBC;
        if (((temp_v0 << 0xF) >= 0) && ((temp_v0 & 8) == 0)) {
            arg2->unk4 = arg2->unk4 * D_800EE010;
            goto block_16;
        }
    } else {
        *arg4 = *arg4 + (arg1->unk0 * arg0->unk120 * 1.0f);
        temp_f0_2 = arg1->unk4 * arg0->unk120;
        if (temp_f0_2 < 0.0f) {
            *arg5 = *arg5 + (temp_f0_2 * D_800EE018);
        } else {
            *arg5 = *arg5 + (temp_f0_2 * 0.0f);
        }
        *arg6 = *arg6 + (arg1->unk8 * arg0->unk120 * 1.0f);
        func_8002A5F4(1.0f, arg1, *arg3, 1.2f, 0.0f);
        temp_v0_2 = arg0->unkBC;
        if (((temp_v0_2 << 0xF) >= 0) && ((temp_v0_2 & 8) == 0)) {
            arg2->unk4 = arg2->unk4 * D_800EE020;
block_16:
        }
    }
    arg0->unkBC = arg0->unkBC & ~0x10;
    temp_f0_3 = arg0->unk120;
    temp_f12 = arg1->unk0 * temp_f0_3;
    temp_f14 = arg1->unk8 * temp_f0_3;
    if (((phi_f2 <= temp_f12) && (phi_f2 <= temp_f14)) || ((phi_f2 <= temp_f12) && (temp_f14 < phi_f2))) {
        temp_f0_4 = arg0->unk70 / 2.0f;
        arg0->unk218 = (*arg4 - temp_f12) - temp_f0_4;
        arg0->unk21C = (*arg6 - temp_f14) - temp_f0_4;
    }
    if (((temp_f12 < phi_f2) && (phi_f2 <= temp_f14)) || ((temp_f12 < phi_f2) && (temp_f14 < phi_f2))) {
        temp_f0_5 = arg0->unk70 / 2.0f;
        arg0->unk218 = *arg4 + temp_f12 + temp_f0_5;
        arg0->unk21C = *arg6 + temp_f14 + temp_f0_5;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_8003DC40/func_8003FBAC.s")
#endif
