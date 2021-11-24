
#include "global.h"
#include <defines.h>

extern s16 D_80165560[];
extern s32* D_800E3C50[];
extern u16* D_800E3890[];
extern struct_D_800E261C D_800E2400;
extern struct_D_800E261C D_800E24B4;
extern struct_D_800E261C D_800E2568;
extern s16 D_80165340;

extern Camera *camera1;
extern Camera *camera2;
extern Camera *camera3;
extern Camera *camera4;

//GLOBAL_ASM("asm/non_matchings/code_800393C0/spawn_player.s")

void spawn_player(Player *player, s8 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u16 arg6, s16 arg7) {
    f32 ret;
    s8 idx;

    player->unk_000 = PLAYER_INACTIVE;
    player->unk_08C = 0;
    player->characterId = arg6;
    player->unk_0B6 = 0;
    player->unk_0FC = gKartFrictionTable[player->characterId];
    player->unk_070 = gKartBoundingBoxTable[player->characterId];
    player->unk_100 = gKartGravityTable[player->characterId];

    switch (gModeSelection) {
        case GRAND_PRIX:
        case VERSUS:
            player->unk_084 = D_800E2400.unk_00[gCCSelection][player->characterId];
            player->unk_088 = D_800E24B4.unk_00[gCCSelection][player->characterId];
            player->unk_210 = D_800E2568.unk_00[gCCSelection][player->characterId];
            player->unk_214 = D_800E261C.unk_00[gCCSelection][player->characterId];
            break;

        // Uses 100CC values
        case TIME_TRIALS:
            player->unk_084 = D_800E2400.unk_00[1][player->characterId];
            player->unk_088 = D_800E24B4.unk_00[1][player->characterId];
            player->unk_210 = D_800E2568.unk_00[1][player->characterId];
            player->unk_214 = D_800E261C.unk_00[1][player->characterId];
            break;

        case BATTLE:
            player->unk_084 = D_800E2400.unk_00[4][player->characterId];
            player->unk_088 = D_800E24B4.unk_00[4][player->characterId];
            player->unk_210 = D_800E2568.unk_00[4][player->characterId];
            player->unk_214 = D_800E261C.unk_00[4][player->characterId];
            break;
    }

    player->posX = arg2;
    ret = func_802AE1C0(arg2, arg4 + 50.0f, arg3) + player->unk_070;
    player->posZ = arg3;
    player->posY = ret;
    player->rotX = arg2;
    player->rotY = ret;

    D_80164510[arg1] = ret;


    player->unk_02C = 0;
    player->rotZ = arg3;
    player->unk_05C = 1.0f;
    player->unk_058 = 0.0f;
    player->unk_060 = 0.0f;
    player->unk_034 = 0.0f;
    player->unk_038 = 0.0f;
    player->unk_03C = 0.0f;
    player->unk_02E = arg5;
    player->unk_030 = 0;
    player->unk_0FA = 0;
    player->unk_002 = 0;
    
    player->unk_0BC = 0;
    player->unk_0C0 = 0;
    player->unk_07C = 0;
    player->unk_07A = 0;
    player->unk_006 = 0;
    player->unk_008 = -1;
    player->unk_08C = 0.0f;
    player->unk_090 = 0.0f;
    player->unk_094 = 0.0f;
    player->unk_074 = 0.0f;
    player->unk_000 = arg7;
    player->unk_0CA = 0;
    player->unk_0DE = 0;
    player->unk_10C = 0;
    player->unk_0E2 = 0;
    player->unk_0E8 = 0.0f;
    player->unk_0A0 = 0.0f;
    player->unk_104 = 0.0f;
    player->unk_09C = 0.0f;
    player->unk_20C = 0.0f;
    player->unk_DAC = 0.0f;
    player->unk_044 = 0;
    player->unk_046 = 0;
    player->unk_00C = 0;
    player->unk_0C6 = 0xFF;

    
    player->unk_206 = 0;
    player->unk_0C4 = 0;
    player->unk_D98 = 0;
    player->unk_D9A = 0;
    player->unk_DA4 = 0;
    player->unk_DA6 = 0;
    player->unk_DB4 = 0;
    player->unk_DB6 = 0;
    player->unk_DCC = 0;
    player->unk_DCE = 0;
    player->unk_DD0 = 0;
    player->unk_DD2 = 0;
    player->unk_DD4 = 0;


    player->unk_042 = 0;
    player->unk_078 = 0;
    player->unk_0A8 = 0;
    player->unk_0AA = 0;
    player->unk_0AC = 0;
    player->unk_0AE = 0;
    player->unk_0B0 = 0;
    player->unk_0B2 = 0;
    player->unk_0B4 = 0;
    player->unk_0C0 = 0;
    player->unk_0C2 = 0;
    player->unk_0C8 = 0;
    player->unk_0CA = 0;
    player->unk_0DC = 0;
    player->unk_0DE = 0;
    player->unk_0E0 = 0;
    player->unk_0E2 = 0;
    player->unk_10C = 0;
    player->unk_200 = 0;
    player->unk_204 = 0;
    player->unk_220 = 0;
    player->unk_228 = 0;
    player->unk_22A = 0;
    player->unk_234 = 0;
    player->unk_236 = 0;
    player->unk_238 = 0;
    player->unk_23A = 0;
    player->unk_240 = 0;
    player->unk_256 = 0;

    player->unk_224 = 1.0f;
    player->unk_DAC = 1.0f;

    player->unk_064 = 0.0f;
    player->unk_068 = 0.0f;
    player->unk_06C = 0.0f;
    player->unk_080 = 0.0f;
    player->unk_D9C = 0.0f;
    player->unk_DA0 = 0.0f;
    player->unk_DA8 = 0.0f;
    player->unk_DB0 = 0.0f;
    player->unk_DB8 = 0.0f;
    player->unk_DBC = 0.0f;
    player->unk_DC0 = 0.0f;
    player->unk_DC4 = 0.0f;
    player->unk_DC8 = 0.0f;
    player->unk_084 = 0.0f;
    player->unk_088 = 0.0f;
    player->unk_08C = 0.0f;
    player->unk_090 = 0.0f;
    player->unk_094 = 0.0f;
    player->unk_098 = 0.0f;
    player->unk_09C = 0.0f;
    player->unk_0A0 = 0.0f;
    player->unk_0A4 = 0.0f;
    player->unk_0B8 = 0.0f;
    player->unk_0E4 = 0.0f;
    player->unk_0E8 = 0.0f;
    player->kartHopVelocity = 0.0f;
    player->kartHopJerk = 0.0f;
    player->kartHopAcceleration = 0.0f;
    player->unk_104 = 0.0f;
    player->unk_108 = 0.0f;
    player->unk_1F8 = 0.0f;
    player->unk_1FC = 0.0f;
    player->unk_208 = 0.0f;
    player->unk_20C = 0.0f;
    player->unk_210 = 0.0f;
    player->unk_218 = 0.0f;
    player->unk_21C = 0.0f;
    player->unk_22C = 0.0f;
    player->unk_230 = 0.0f;
    player->unk_23C = 0.0f;

    idx = arg1;

    D_801650D0[0][idx] = 0;
    D_801650D0[1][idx] = 0;
    D_801650D0[2][idx] = 0;
    D_801650D0[3][idx] = 0;
    D_80165110[0][idx] = 0;
    D_80165110[1][idx] = 0;
    D_80165110[2][idx] = 0;
    D_80165110[3][idx] = 0;
    D_80165190[0][idx] = 0;
    D_80165190[1][idx] = 0;
    D_80165190[2][idx] = 0;
    D_80165190[3][idx] = 0;
    D_801651D0[0][idx] = 0;
    D_801651D0[1][idx] = 0;
    D_801651D0[2][idx] = 0;
    D_801651D0[3][idx] = 0;

    D_80165420[idx] = 0;
    D_80165440[idx] = 0;
    D_80165460[idx] = 0;
    D_80165480[idx] = 0;
    D_801654E0[idx] = 0;
    D_80165500[idx] = 0;
    D_80165520[idx] = 0;
    D_80165540[arg1] = 0;
    D_8018D900 = 0;

    D_801652E0[arg1] = 0;
    D_801652C0[arg1] = 0;
    D_80165020[arg1] = 0;
    D_80165070[arg1][0] = 0.0f;
    D_80165070[arg1][1] = 0.0f;
    D_80165070[arg1][2] = 0.0f;
    D_80165280[arg1] = 0.0f;
    D_801652A0[arg1] = 0.0f;
    D_801653E0[arg1] = 0;
    D_80165400[arg1] = 0;
    D_801654A0[arg1] = 0;
    D_801654C0[arg1] = 0;
    D_80165340 = 0;

    player->unk_1A4 = 0;
    player->unk_1BC = 0;
    player->unk_1D4 = 0;
    player->unk_1EC = 0;
    player->unk_1A5 = 0;
    player->unk_1BD = 0;
    player->unk_1D5 = 0;
    player->unk_1ED = 0;
    player->unk_1A6 = 0;
    player->unk_1BE = 0;
    player->unk_1D6 = 0;
    player->unk_1EE = 0;
    player->unk_1C4 = 0;
    player->unk_1AC = 0;
    player->unk_1DC = 0;
    player->unk_1F4 = 0;
    player->unk_110 = 0;
    player->unk_112 = 0;
    player->unk_114 = 0;
    player->unk_116 = 0;
    player->unk_118 = 0;
    player->unk_11A = 0;
    player->unk_198 = 0.0f;
    player->unk_19C = 0.0f;
    player->unk_1A0 = 0.0f;
    player->unk_1B0 = 0.0f;
    player->unk_1B4 = 0.0f;
    player->unk_1B8 = 0.0f;
    player->unk_1C8 = 0.0f;
    player->unk_1CC = 0.0f;
    player->unk_1D0 = 0.0f;
    player->unk_1E0 = 0.0f;
    player->unk_1E4 = 0.0f;
    player->unk_1E8 = 0.0f;
    player->unk_1A8 = 0.0f;
    player->unk_1C0 = 0.0f;
    player->unk_1D8 = 0.0f;
    player->unk_1F0 = 0.0f;
    player->unk_11C = 0.0f;
    player->unk_120 = 0.0f;
    player->unk_124 = 0.0f;
    player->unk_128 = 0.0f;
    player->unk_12C = 0.0f;
    player->unk_130 = 0.0f;
    player->unk_134 = 0.0f;
    player->unk_138 = 0.0f;
    player->unk_13C = 0.0f;
    player->unk_140 = 0.0f;
    player->unk_144 = 0.0f;
    player->unk_148 = 0.0f;

    D_80165300[arg1] = 0;
    D_8018CE10[arg1].unk_04 = 0.0f;
    D_8018CE10[arg1].unk_0C = 0.0f;
    func_80295BF8(arg1);
    func_8005D6C0(player);
    func_8006B87C(player, arg1);
    if (gModeSelection == BATTLE) {
        func_8006B7E4(player, arg1);
    }
    func_802B6540(player->unk_150, player->unk_058, player->unk_05C, player->unk_060, player->unk_02E);
    func_802B6540(player->unk_174, player->unk_058, player->unk_05C, player->unk_060, player->unk_02E);
}

void func_80039AE4(void) {
    switch (D_800DC52C) {
        case 0:
            if (D_800DC50C == 5) {
                D_80165578 = 0x898;
                D_8016557A = 0;
                D_8016557C = 0x384;
                D_8016557E = 0;
                D_80165574 = 0x384;
                D_80165576 = 0;
                D_80165570 = 0x35C;
                D_80165572 = 0;
                D_80165580 = 0x1F4;
                D_80165582 = 0;
            } else {
                D_80165578 = 0x4B0;
                D_8016557A = -0xA;
                D_8016557C = 0x384;
                D_8016557E = 0x32;
                D_80165574 = 0x1F4;
                D_80165576 = 0;
                D_80165570 = 0x15E;
                D_80165572 = 0;
                D_80165580 = 0xFA;
                D_80165582 = 0;
            }
            break;

        case 1:
        case 2:
            if (gModeSelection == BATTLE) {
                D_80165578 = 0x898;
                D_8016557A = 0;
                D_8016557C = 0x320;
                D_8016557E = 0;
                D_80165574 = 0x190;
                D_80165576 = 0;
                D_80165570 = 0xC8;
                D_80165572 = 0;
                D_80165580 = 0xC8;
                D_80165582 = 0;
            } else {
                D_80165578 = 0x4B0;
                D_8016557A = 0x32;
                D_8016557C = 0x320;
                D_8016557E = 0x32;
                D_80165574 = 0x190;
                D_80165576 = 0;
                D_80165570 = 0x96;
                D_80165572 = 0;
                D_80165580 = 0x96;
                D_80165582 = 0;
            }
            break;

        default:
            if (gModeSelection == BATTLE) {
                D_80165578 = 0x898;
                D_8016557A = 0;
                D_8016557C = 0x320;
                D_8016557E = 0;
                D_80165574 = 0x190;
                D_80165576 = 0;
                D_80165570 = 0xC8;
                D_80165572 = 0;
                D_80165580 = 0xC8;
                D_80165582 = 0;
            } else {
                D_80165578 = 0x3E8;
                D_8016557A = 0;
                D_8016557C = 0x258;
                D_8016557E = 0;
                D_80165574 = 0x15E;
                D_80165576 = 0;
                D_80165570 = 0x96;
                D_80165572 = 0;
                D_80165580 = 0x96;
                D_80165582 = 0;
            }
            break;
    }
}

typedef struct {
    s32 unk00[8];
} temp_80039DA4; // to be removed when data is compilable
extern temp_80039DA4 D_800E4360;
extern temp_80039DA4 D_800E4380;

void func_80039DA4(void) {
    s32 i;
    // Put back in when data is compilable
    /*
    s32 sp2C[] = {
        0x00000007, 0x00000006, 0x00000005, 0x00000004,
        0x00000003, 0x00000002, 0x00000001, 0x00000000,
    };

    s32 spC[] = {
        0x00000000, 0x00000001, 0x00000002, 0x00000003,
        0x00000004, 0x00000005, 0x00000006, 0x00000007,
    };
    */
    temp_80039DA4 sp2C = D_800E4360;
    temp_80039DA4 spC = D_800E4380;

    if (((gCourseSelection == 0) && (D_8016556E == 0)) || 
        (D_800DC51C == 1) || 
        (D_8018EDEF == 0x40)) {
        for (i = 0; i < 8; i++) {
            D_80165270[i] = sp2C.unk00[i];
        }
    } else {
        for (i = 0; i < 8; i++) {
            D_80165270[i] = spC.unk00[D_801643B8[i]];
        }
    }
}

void func_80039F44(f32 *arg0, f32 *arg1, f32 arg2) {
    func_80039DA4();
    if (((gCourseSelection == 0) && (D_8016556E == 0)) ||
        (D_800DC51C == 1) || 
        (D_8018EDEF == 0x40)) {
        s16 rand;
        s16 i;

        do {
            rand = random_int(7);
        } while(rand == D_800E86A8[0]);

        D_80165560[0] = rand;

        for (i = 1; i < 7; i++) {
            u16* arr = D_800E3890[D_800E86A8[0]];
            if (rand == arr[i]) {
                D_80165560[i] = arr[0];
            } else {
                D_80165560[i] = arr[i];
            }
        }
    }

    D_8016556E = 0;
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4FC, 0, arg0[D_80165270[0]], arg1[D_80165270[0]], arg2, 32768.0f, D_800E86A8[0], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E0, 1, arg0[D_80165270[1]], arg1[D_80165270[1]], arg2, 32768.0f, D_80165560[0], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        spawn_player(D_800DC4E4, 2, arg0[D_80165270[2]], arg1[D_80165270[2]], arg2, 32768.0f, D_80165560[1], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        spawn_player(D_800DC4E8, 3, arg0[D_80165270[3]], arg1[D_80165270[3]], arg2, 32768.0f, D_80165560[2], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        spawn_player(D_800DC4EC, 4, arg0[D_80165270[4]], arg1[D_80165270[4]], arg2, 32768.0f, D_80165560[3], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        spawn_player(D_800DC4F0, 5, arg0[D_80165270[5]], arg1[D_80165270[5]], arg2, 32768.0f, D_80165560[4], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        spawn_player(D_800DC4F4, 6, arg0[D_80165270[6]], arg1[D_80165270[6]], arg2, 32768.0f, D_80165560[5], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        spawn_player(D_800DC4F8, 7, arg0[D_80165270[7]], arg1[D_80165270[7]], arg2, 32768.0f, D_80165560[6], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
        D_80164A28 = 0;
    } else {
        spawn_player(D_800DC4FC, 0, arg0[D_80165270[0]], arg1[D_80165270[0]] + 250.0f, arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[D_80165270[1]], arg1[D_80165270[1]] + 250.0f, arg2, 32768.0f, D_80165560[0], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4E4, 2, arg0[D_80165270[3]], arg1[D_80165270[2]] + 250.0f, arg2, 32768.0f, D_80165560[1], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4E8, 3, arg0[D_80165270[2]], arg1[D_80165270[3]] + 250.0f, arg2, 32768.0f, D_80165560[2], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4EC, 4, arg0[D_80165270[5]], arg1[D_80165270[4]] + 250.0f, arg2, 32768.0f, D_80165560[3], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4F0, 5, arg0[D_80165270[4]], arg1[D_80165270[5]] + 250.0f, arg2, 32768.0f, D_80165560[4], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4F4, 6, arg0[D_80165270[7]], arg1[D_80165270[6]] + 250.0f, arg2, 32768.0f, D_80165560[5], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4F8, 7, arg0[D_80165270[6]], arg1[D_80165270[7]] + 250.0f, arg2, 32768.0f, D_80165560[6], PLAYER_EXISTS | PLAYER_STAGING | PLAYER_START_SEQUENCE | PLAYER_CPU);
        D_80164A28 = 1;
    }
    func_80039AE4();
}

void func_8003A59C(f32 *arg0, f32 *arg1, f32 arg2) {
    spawn_player(D_800DC4E8, 3, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4EC, 4, arg0[3], arg1[3], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[4], arg1[4], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[5], arg1[5], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[6], arg1[6], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4FC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E0, 1, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
        spawn_player(D_800DC4E4, 2, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    } else if (D_8015F890 != 1) {
        spawn_player(D_800DC4FC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        if (D_80162DD4[0] == 0) {
            spawn_player(D_800DC4E0, 1, arg0[0], arg1[0], arg2, 32768.0f, D_80162DE0, PLAYER_EXISTS | PLAYER_HUMAN | PLAYER_START_SEQUENCE | PLAYER_INVISIBLE_OR_BOMB);
        } else {
            spawn_player(D_800DC4E0, 1, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
        }
        if (D_80162DD4[1] == 0) {
            spawn_player(D_800DC4E4, 2, arg0[0], arg1[0], arg2, 32768.0f, D_80162DE4, PLAYER_EXISTS | PLAYER_HUMAN | PLAYER_START_SEQUENCE | PLAYER_INVISIBLE_OR_BOMB);
        } else {
            spawn_player(D_800DC4E4, 2, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
        }
    } else {
        spawn_player(D_800DC4FC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_80162DE8, PLAYER_EXISTS | PLAYER_HUMAN | PLAYER_START_SEQUENCE | PLAYER_INVISIBLE_OR_BOMB);
        if (D_80162DD8 == 0) {
            spawn_player(D_800DC4E0, 1, arg0[0], arg1[0], arg2, 32768.0f, D_80162DE0, PLAYER_EXISTS | PLAYER_HUMAN | PLAYER_START_SEQUENCE | PLAYER_INVISIBLE_OR_BOMB);
        } else {
            spawn_player(D_800DC4E0, 1, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
        }
        if (D_80162DD4[1] == 0) {
            spawn_player(D_800DC4E4, 2, arg0[0], arg1[0], arg2, 32768.0f, D_80162DE4, PLAYER_EXISTS | PLAYER_HUMAN | PLAYER_START_SEQUENCE | PLAYER_INVISIBLE_OR_BOMB);
        } else {
            spawn_player(D_800DC4E4, 2, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
        }
    }
    D_80164A28 = 0;
    func_80039AE4();
}

void func_8003A9F0(f32* arg0, f32* arg1, f32 arg2) {
    func_80039DA4();
    if ((gCourseSelection == 0) || (D_800DC51C == 1) || (D_8018EDEF == 0x40)) {
        s16 rand;
        s16 i;

getRand:
        rand = random_int(7);
        if (D_800E86A8[0] == rand)
            goto getRand;
        if (D_800E86A8[1] == rand)
            goto getRand;

        D_80165560[0] = rand;

        for (i = 1; i < 6; i++) {
            u16* arr = D_800E3C50[D_800E86A8[0]][D_800E86A8[1]];
            if (rand == arr[i]) {
                D_80165560[i] = arr[0];
            } else {
                D_80165560[i] = arr[i];
            }
        }
    }

    spawn_player(D_800DC4E4, 2, arg0[D_80165270[2]], arg1[D_80165270[2]], arg2, 32768.0f, D_80165560[0], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4E8, 3, arg0[D_80165270[3]], arg1[D_80165270[3]], arg2, 32768.0f, D_80165560[1], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4EC, 4, arg0[D_80165270[4]], arg1[D_80165270[4]], arg2, 32768.0f, D_80165560[2], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4F0, 5, arg0[D_80165270[5]], arg1[D_80165270[5]], arg2, 32768.0f, D_80165560[3], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4F4, 6, arg0[D_80165270[6]], arg1[D_80165270[6]], arg2, 32768.0f, D_80165560[4], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4F8, 7, arg0[D_80165270[7]], arg1[D_80165270[7]], arg2, 32768.0f, D_80165560[5], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4FC, 0, arg0[D_80165270[0]], arg1[D_80165270[0]], arg2, 32768.0f, D_800E86A8[0], PLAYER_HUMAN_AND_CPU);
    } else {
        spawn_player(D_800DC4FC, 0, arg0[D_80165270[0]], arg1[D_80165270[0]], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4E0, 1, arg0[D_80165270[1]], arg1[D_80165270[1]], arg2, 32768.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    } else {
        spawn_player(D_800DC4E0, 1, arg0[D_80165270[1]], arg1[D_80165270[1]], arg2, 32768.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }

    D_80164A28 = 0;
    func_80039AE4();
}

void func_8003AE24(f32 *arg0, f32 *arg1, f32 arg2) {
    spawn_player(D_800DC4E4, 2, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4E8, 3, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4EC, 4, arg0[3], arg1[3], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[4], arg1[4], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[5], arg1[5], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[6], arg1[6], arg2, 32768.0f, D_800E86A8[0], PLAYER_START_SEQUENCE | PLAYER_CPU);
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4FC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_HUMAN_AND_CPU);
    } else {
        spawn_player(D_800DC4FC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[1], PLAYER_HUMAN_AND_CPU);
    } else {
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }
    D_80164A28 = 0;
    func_80039AE4();
}

void spawn_players_2p_battle(f32 *arg0, f32 *arg1, f32 arg2) {
    if (gCurrentCourseId == COURSE_BIG_DONUT) {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, -16384.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 16384.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    } else {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 0.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }
    spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[2], PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 32768.0f, D_800E86A8[3], PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4EC, 4, arg0[4], arg1[4], arg2, 32768.0f, 4, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[5], arg1[5], arg2, 32768.0f, 5, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[6], arg1[6], arg2, 32768.0f, 6, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[0], arg1[0], arg2, 32768.0f, 7, PLAYER_START_SEQUENCE | PLAYER_CPU);
    D_80164A28 = 0;
    func_80039AE4();
}

void func_8003B318(f32 *arg0, f32 *arg1, f32 arg2) {
    spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[2], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[1], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[2], PLAYER_HUMAN_AND_CPU);
    }

    spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 32768.0f, 3, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4EC, 4, arg0[4], arg1[4], arg2, 32768.0f, 4, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[5], arg1[5], arg2, 32768.0f, 5, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[6], arg1[6], arg2, 32768.0f, 6, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[0], arg1[0], arg2, 32768.0f, 7, PLAYER_START_SEQUENCE | PLAYER_CPU);
    D_80164A28 = 0;
    func_80039AE4();
}

void spawn_players_3p_battle(f32 *arg0, f32 *arg1, f32 arg2) {
    if (gCurrentCourseId == COURSE_BIG_DONUT) {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, -16384.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 16384.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 0.0f, D_800E86A8[2], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    } else {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 0.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, -16384.0f, D_800E86A8[2], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }
    spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 32768.0f, 3, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4EC, 4, arg0[4], arg1[4], arg2, 32768.0f, 4, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[5], arg1[5], arg2, 32768.0f, 5, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[6], arg1[6], arg2, 32768.0f, 6, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[0], arg1[0], arg2, 32768.0f, 7, PLAYER_START_SEQUENCE | PLAYER_CPU);
    D_80164A28 = 0;
    func_80039AE4();
}

void func_8003B870(f32 *arg0, f32 *arg1, f32 arg2) {
    spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[2], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 32768.0f, D_800E86A8[3], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    if (D_800DC51C == 1) {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 32768.0f, D_800E86A8[1], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 32768.0f, D_800E86A8[2], PLAYER_HUMAN_AND_CPU);
        spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 32768.0f, D_800E86A8[3], PLAYER_HUMAN_AND_CPU);
    }
    spawn_player(D_800DC4EC, 4, arg0[4], arg1[4], arg2, 32768.0f, 4, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[5], arg1[5], arg2, 32768.0f, 5, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[6], arg1[6], arg2, 32768.0f, 6, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[0], arg1[0], arg2, 32768.0f, 7, PLAYER_START_SEQUENCE | PLAYER_CPU);
    D_80164A28 = 0;
    func_80039AE4();
}

void spawn_players_4p_battle(f32 *arg0, f32 *arg1, f32 arg2) {
    if (gCurrentCourseId == COURSE_BIG_DONUT) {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, -16384.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 16384.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, 0.0f, D_800E86A8[2], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 32768.0f, D_800E86A8[3], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    } else {
        spawn_player(D_800DC4DC, 0, arg0[0], arg1[0], arg2, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E0, 1, arg0[1], arg1[1], arg2, 0.0f, D_800E86A8[1], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E4, 2, arg0[2], arg1[2], arg2, -16384.0f, D_800E86A8[2], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
        spawn_player(D_800DC4E8, 3, arg0[3], arg1[3], arg2, 16384.0f, D_800E86A8[3], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
    }
    spawn_player(D_800DC4EC, 4, arg0[4], arg1[4], arg2, 32768.0f, 4, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F0, 5, arg0[5], arg1[5], arg2, 32768.0f, 5, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F4, 6, arg0[6], arg1[6], arg2, 32768.0f, 6, PLAYER_START_SEQUENCE | PLAYER_CPU);
    spawn_player(D_800DC4F8, 7, arg0[0], arg1[0], arg2, 32768.0f, 7, PLAYER_START_SEQUENCE | PLAYER_CPU);
    D_80164A28 = 0;
    func_80039AE4();
}

/* Remove when rodata works */
extern f32 D_800EDE20;
extern f32 D_800EDE24;
extern f32 D_800EDE28;
extern f32 D_800EDE2C;
extern f32 D_800EDE30;
extern f32 D_800EDE34;
extern f32 D_800EDE38;
extern f32 D_800EDE3C;
extern f32 D_800EDE40;
extern f32 D_800EDE44;
extern f32 D_800EDE48;
extern f32 D_800EDE4C;
extern f32 D_800EDE50;
extern f32 D_800EDE54;
extern f32 D_800EDE58;
extern f32 D_800EDE5C;

void func_8003BE30(void) {
    spawn_player(D_800DC4DC, 0, -2770.774f, -345.187f, D_800EDE20, 0.0f, D_8018D9D0[0], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4E0, 1, -3691.506f, -6.822f, D_800EDE24, D_800EDE28, D_8018D9D0[1], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    spawn_player(D_800DC4E4, 2, -3475.028f, -998.485f, D_800EDE2C, D_800EDE30, D_8018D9D0[2], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    if (D_802874D8.unk_1D >= 3) {
        spawn_player(D_800DC4E8, 3, -3025.772f, 110.039f, D_800EDE34, D_800EDE38, D_802874D8.unk_1E, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    } else {
        spawn_player(D_800DC4E8, 3, -3025.772f, 110.039f, D_800EDE3C, D_800EDE40, D_8018D9D0[3], PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
    }
    spawn_player(D_800DC4EC, 4, -2770.774f, -345.187f, D_800EDE44, 0.0f, 0, 0x7000);
    spawn_player(D_800DC4F0, 5, -3691.506f, -6.822f, D_800EDE48, D_800EDE4C, 0, 0x7000);
    spawn_player(D_800DC4F4, 6, -3475.028f, -998.485f, D_800EDE50, D_800EDE54, 0, 0x7000);
    spawn_player(D_800DC4F8, 7, -3025.772f, 110.039f, D_800EDE58, D_800EDE5C, 0, 0x7000);
    D_80164A28 = 0;
    func_80039AE4();
}

#ifdef NON_MATCHING
void func_8003C0F0(void) {
    s16 sp5E;
    s16 sp5C;
    s16 sp5A;
    s32 temp;

    switch (gCurrentCourseId) {
        case COURSE_MARIO_RACEWAY:
        case COURSE_CHOCO_MOUNTAIN:
        case COURSE_BOWSER_CASTLE:
        case COURSE_BANSHEE_BOARDWALK:
        case COURSE_YOSHI_VALLEY:
        case COURSE_FRAPPE_SNOWLAND:
        case COURSE_KOOPA_BEACH:
        case COURSE_ROYAL_RACEWAY:
        case COURSE_LUIGI_RACEWAY:
        case COURSE_MOO_MOO_FARM:
        case COURSE_TOADS_TURNPIKE:
        case COURSE_KALAMARI_DESERT:
        case COURSE_SHERBET_LAND:
        case COURSE_RAINBOW_ROAD:
        case COURSE_WARIO_STADIUM:
        case COURSE_DK_JUNGLE:
            func_8000F2DC();
            sp5E = (f32)D_80164550[0];
            sp5C = (f32)D_80164550[2];
            sp5A = (f32)D_80164550[1];
            if (gCurrentCourseId == COURSE_TOADS_TURNPIKE) {
                sp5E = 0;
            }
            break;

        case COURSE_BLOCK_FORT:
        case COURSE_SKYSCRAPER:
        case COURSE_DOUBLE_DECK:
        case COURSE_BIG_DONUT:
            func_8000EEDC();
            break;
    }

    switch (gCurrentCourseId) {
        case COURSE_MARIO_RACEWAY:
        case COURSE_CHOCO_MOUNTAIN:
        case COURSE_BOWSER_CASTLE:
        case COURSE_BANSHEE_BOARDWALK:
        case COURSE_YOSHI_VALLEY:
        case COURSE_FRAPPE_SNOWLAND:
        case COURSE_KOOPA_BEACH:
        case COURSE_ROYAL_RACEWAY:
        case COURSE_LUIGI_RACEWAY:
        case COURSE_MOO_MOO_FARM:
        case COURSE_TOADS_TURNPIKE:
        case COURSE_KALAMARI_DESERT:
        case COURSE_SHERBET_LAND:
        case COURSE_RAINBOW_ROAD:
        case COURSE_WARIO_STADIUM:
        case COURSE_DK_JUNGLE:
            switch (D_800DC52C) {
                case 0:
                    switch (gModeSelection) {
                        case GRAND_PRIX:
                            D_80165210[0] = D_80165210[2] = D_80165210[4] = D_80165210[6] = sp5E + 0x14;
                            D_80165210[1] = D_80165210[3] = D_80165210[5] = D_80165210[7] = sp5E - 0x14;
                            D_80165230[0] = sp5C + 0x1E;
                            D_80165230[1] = sp5C + 0x32;
                            D_80165230[2] = sp5C + 0x46;
                            D_80165230[3] = sp5C + 0x5A;
                            D_80165230[4] = sp5C + 0x6E;
                            D_80165230[5] = sp5C + 0x82;
                            D_80165230[6] = sp5C + 0x96;
                            D_80165230[7] = sp5C + 0xAA;
                            func_80039F44(D_80165210, D_80165230, sp5A);
                            break;

                        case TIME_TRIALS:
                            D_80165210[0] = D_80165210[2] = D_80165210[4] = D_80165210[6] = sp5E;
                            D_80165210[1] = D_80165210[3] = D_80165210[5] = D_80165210[7] = sp5E;
                            D_80165230[0] = sp5C + 0x1E;
                            D_80165230[1] = sp5C + 0x1E;
                            D_80165230[2] = sp5C + 0x1E;
                            D_80165230[3] = sp5C + 0x1E;
                            D_80165230[4] = sp5C + 0x1E;
                            D_80165230[5] = sp5C + 0x1E;
                            D_80165230[6] = sp5C + 0x1E;
                            D_80165230[7] = sp5C + 0x1E;
                            func_8003A59C(D_80165210, D_80165230, sp5A);
                            break;
                    }
                    break;

                case 1:
                case 2:
                    switch (gModeSelection) {
                        case GRAND_PRIX:
                            D_80165210[0] = D_80165210[2] = D_80165210[4] = D_80165210[6] = sp5E + 0x14;
                            D_80165210[1] = D_80165210[3] = D_80165210[5] = D_80165210[7] = sp5E - 0x14;
                            D_80165230[0] = sp5C + 0x1E;
                            D_80165230[1] = sp5C + 0x32;
                            D_80165230[2] = sp5C + 0x46;
                            D_80165230[3] = sp5C + 0x5A;
                            D_80165230[4] = sp5C + 0x6E;
                            D_80165230[5] = sp5C + 0x82;
                            D_80165230[6] = sp5C + 0x96;
                            D_80165230[7] = sp5C + 0xAA;
                            func_8003A9F0(D_80165210, D_80165230, sp5A);
                            break;

                        case VERSUS:
                            D_80165210[0] = D_80165210[2] = D_80165210[4] = D_80165210[6] = sp5E + 0xA;
                            D_80165210[1] = D_80165210[3] = D_80165210[5] = D_80165210[7] = sp5E - 0xA;
                            D_80165230[0] = sp5C + 0x1E;
                            D_80165230[1] = sp5C + 0x1E;
                            D_80165230[2] = sp5C + 0x1E;
                            D_80165230[3] = sp5C + 0x1E;
                            D_80165230[4] = sp5C + 0x1E;
                            D_80165230[5] = sp5C + 0x1E;
                            D_80165230[6] = sp5C + 0x1E;
                            D_80165230[7] = sp5C + 0x1E;
                            func_8003AE24(D_80165210, D_80165230, sp5A);
                            break;
                    }
                    break;

                case 3:
                    switch (gModeSelection) {
                        case VERSUS:
                            D_80165210[0] = sp5E + 0x1E;
                            D_80165210[2] = D_80165210[4] = D_80165210[6] = sp5E - 0xA;
                            D_80165210[3] = D_80165210[5] = D_80165210[7] = sp5E - 0x1E;
                            D_80165210[1] = sp5E + 0xA;
                            
                            D_80165230[0] = sp5C + 0x1E;
                            D_80165230[1] = sp5C + 0x1E;
                            D_80165230[2] = sp5C + 0x1E;
                            D_80165230[3] = sp5C + 0x1E;
                            D_80165230[4] = sp5C + 0x1E;
                            D_80165230[5] = sp5C + 0x1E;
                            D_80165230[6] = sp5C + 0x1E;
                            D_80165230[7] = sp5C + 0x1E;
                            if (gPlayerCountSelection1 == 4) {
                                func_8003B870(D_80165210, D_80165230, sp5A);
                            } else {
                                func_8003B318(D_80165210, D_80165230, sp5A);
                            }
                            break;
                    }
                    break;
            }
            break;

        case COURSE_BLOCK_FORT:
            switch (D_800DC52C) {
                case 1:
                case 2:
                    temp = 5;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0;
                    D_80165210[1] = 0;
                    D_80165230[0] = -200.0f;
                    D_80165230[1] = 200.0f;
                    spawn_players_2p_battle(D_80165210, D_80165230, temp);
                    break;

                case 3:
                    temp = 5;
                    if (1){
                        if (1){};
                    };
                    D_80165210[2] = -200.0f;
                    D_80165230[1] = -200.0f;
                    
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165230[2] = 0.0f;
                    D_80165230[3] = 0.0f;

                    D_80165210[3] = 200.0f;
                    D_80165230[0] = 200.0f;
                    if (gPlayerCountSelection1 == 4) {
                        spawn_players_4p_battle(D_80165210, D_80165230, temp);
                    } else {
                        spawn_players_3p_battle(D_80165210, D_80165230, temp);
                    }
                    break;
            }
            break;

        case COURSE_SKYSCRAPER:
            switch (D_800DC52C) {
                case 1:
                case 2:
                    temp = 0x1E0;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165230[1] = -400.0f;
                    D_80165230[0] = 400.0f;
                    spawn_players_2p_battle(D_80165210, D_80165230, temp);
                    break;

                case 3:
                    temp = 0x1E0;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165210[2] = -400.0f;
                    D_80165210[3] = 400.0f;
                    D_80165230[0] = 400.0f;
                    D_80165230[1] = -400.0f;
                    D_80165230[2] = 0.0f;
                    D_80165230[3] = 0.0f;
                    if (gPlayerCountSelection1 == 4) {
                        spawn_players_4p_battle(D_80165210, D_80165230, temp);
                    } else {
                        spawn_players_3p_battle(D_80165210, D_80165230, temp);
                    }
                    break;
            }
            break;

        case COURSE_DOUBLE_DECK:
            switch (D_800DC52C) {
                case 1:
                case 2:
                    temp = 0x37;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165230[1] = -160.0f;
                    D_80165230[0] = 160.0f;
                    spawn_players_2p_battle(D_80165210, D_80165230, temp);
                    break;

                case 3:
                    temp = 0x37;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165210[2] = -160.0f;
                    D_80165210[3] = 160.0f;
                    D_80165230[0] = 160.0f;
                    D_80165230[1] = -160.0f;
                    D_80165230[2] = 0.0f;
                    D_80165230[3] = 0.0f;
                    if (gPlayerCountSelection1 == 4) {
                        spawn_players_4p_battle(D_80165210, D_80165230, temp);
                    } else {
                        spawn_players_3p_battle(D_80165210, D_80165230, temp);
                    }
                    break;
            }
            break;

        case COURSE_BIG_DONUT:
            switch (D_800DC52C) {
                case 1:
                case 2:
                    temp = 0xC8;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165230[1] = -575.0f;
                    D_80165230[0] = 575.0f;
                    spawn_players_2p_battle(D_80165210, D_80165230, temp);
                    break;

                case 3:
                    temp = 0xC8;
                    if (1){
                        if (1){};
                    };
                    D_80165210[0] = 0.0f;
                    D_80165210[1] = 0.0f;
                    D_80165210[2] = -575.0f;
                    D_80165210[3] = 575.0f;
                    D_80165230[0] = 575.0f;
                    D_80165230[1] = -575.0f;
                    D_80165230[2] = 0.0f;
                    D_80165230[3] = 0.0f;
                    if (gPlayerCountSelection1 == 4) {
                        spawn_players_4p_battle(D_80165210, D_80165230, temp);
                    } else {
                        spawn_players_3p_battle(D_80165210, D_80165230, temp);
                    }
                    break;
            }
            break;

        default:
            D_80165210[0] = D_80165210[2] = D_80165210[4] = D_80165210[6] = 20.0f;
            D_80165210[1] = D_80165210[3] = D_80165210[5] = D_80165210[7] = -20.0f;
            D_80165230[0] = 30.0f;
            D_80165230[1] = 50.0f;
            D_80165230[2] = 70.0f;
            D_80165230[3] = 90.0f;
            D_80165230[4] = 110.0f;
            D_80165230[5] = 130.0f;
            D_80165230[6] = 150.0f;
            D_80165230[7] = 170.0f;
            spawn_player(D_800DC4FC, 0, D_80165210[0], D_80165230[0], sp5A, 32768.0f, D_800E86A8[0], PLAYER_EXISTS | PLAYER_START_SEQUENCE | PLAYER_HUMAN);
            spawn_player(D_800DC4E0, 1, D_80165210[1], D_80165230[1], sp5A, 32768.0f, 1, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            spawn_player(D_800DC4E4, 2, D_80165210[2], D_80165230[2], sp5A, 32768.0f, 2, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            spawn_player(D_800DC4E8, 3, D_80165210[3], D_80165230[3], sp5A, 32768.0f, 3, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            spawn_player(D_800DC4EC, 4, D_80165210[4], D_80165230[4], sp5A, 32768.0f, 4, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            spawn_player(D_800DC4F0, 5, D_80165210[5], D_80165230[5], sp5A, 32768.0f, 5, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            spawn_player(D_800DC4F4, 6, D_80165210[6], D_80165230[6], sp5A, 32768.0f, 6, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            spawn_player(D_800DC4F8, 7, D_80165210[7], D_80165230[7], sp5A, 32768.0f, 7, PLAYER_EXISTS | PLAYER_CPU | PLAYER_START_SEQUENCE);
            D_80164A28 = 0;
            break;
    }

    if (gModeSelection != BATTLE) {
        func_8000F628();
    }
}
#else
void func_8003C0F0(void);
GLOBAL_ASM("asm/non_matchings//code_800393C0/func_8003C0F0.s")
#endif

void func_8003CD78(void) {
    func_8003BE30();
}

void func_8003CD98(Player *player, s32 arg1, s8 arg2, s8 arg3) {
    if (player->unk_000 & PLAYER_EXISTS) {
        if (arg3 == 0) {
            func_8002D268(player, arg1, arg3, arg2);
        }
        func_8002934C(player, arg1, arg3, arg2);
        if ((arg3 == 0) || (arg3 == 1)) {
            s32 idx;

            func_80027A20(player, arg2, arg3, 0);
            func_80027A20(player, arg2, arg3, 1);
            func_80027040(player, arg2, arg3, arg3, 0);
            mio0decode((u8*)&D_802DFB80[arg3][arg2], (u8*)&D_802BFB80[arg3][arg2]); // [0x8000][0x1000]
        } else {
            func_80027A20(player, arg2, arg3, 0);
            func_80027A20(player, arg2, arg3, 1);
            func_80027040(player, (s8) (arg2 + 4), arg3, (s8) (arg3 - 2), 0);
            mio0decode((u8*)&D_802DFB80[arg3][arg2] - 0x6D80, (u8*)&D_802BFB80[arg3][arg2] + 0xFFFF4000);
        }

        D_801650D0[arg3][arg2] = player->unk_244[arg3];
        D_80165110[arg3][arg2] = player->unk_24C[arg3];
        D_80165150[arg3][arg2] = player->unk_0A8;
        D_801651D0[arg3][arg2] = 0;
        func_800267AC(player, arg2, arg3);
    }
}

#ifdef NON_MATCHING
// issues with 1C, func_8001C4D0 seems to want it as an s32, but spawn_player saves it as a float
// it's z pos so it should be a float, m2c detects the arg as f32 in func_8001C4D0
// pointer loading/increments are wrong
void func_8003D080(void) {
    Player* ptr;

    func_8005D290();
    if (D_800DC50C == 5) {
        func_8003CD78();
    } else {
        func_8003C0F0();
    }
    if (D_800DC51C == 0) {
        switch (D_800DC52C) {
            case 0:
                switch (gModeSelection) {
                    case GRAND_PRIX:
                        if (gCurrentCourseId == COURSE_TOADS_TURNPIKE) {
                            func_8001C4D0(0.0f, D_800DC4DC->unk_0A8, D_8016524C, D_800DC4DC->unk_0BC, 8, 0);
                        } else {
                            func_8001C4D0((D_80165210[6] + D_80165210[7]) / 2, D_800DC4DC->unk_0A8, D_8016524C, D_800DC4DC->unk_0BC, 8, 0);
                        }
                        break;

                    case TIME_TRIALS:
                        func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_8016524C, D_800DC4DC->unk_0BC, 1, 0);
                        break;

                    default:
                        func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 10, 0);
                        break;
                }
                break;

            case 1:
            case 2:
                switch (gModeSelection) {
                    case GRAND_PRIX:
                        func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 1, 0);
                        func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 1, 1);
                        break;

                    case BATTLE:
                        func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 9, 0);
                        func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 9, 1);
                        break;

                    default:
                        func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 1, 0);
                        func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 1, 1);
                        break;
                }
                break;

            case 3:
                if (gModeSelection == BATTLE) {
                    ptr = &D_800DC4E4;
                    func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 9, 0);
                    func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 9, 1);
                    ptr++;
                    func_8001C4D0(ptr->posX, ptr->posY, ptr->posZ, ptr->unk_02E, 9, 2);
                    ptr++;
                    if (gPlayerCountSelection1 == 4) {
                        func_8001C4D0(ptr->posX, ptr->posY, ptr->posZ, ptr->unk_02E, 9, 3);
                    }
                } else {
                    ptr = &D_800DC4E4;
                    func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 1, 0);
                    func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 1, 1);
                    ptr++;
                    func_8001C4D0(ptr->posX, ptr->posY, ptr->posZ, ptr->unk_02E, 1, 2);
                    ptr++;
                    if (gPlayerCountSelection1 == 4) {
                        func_8001C4D0(ptr->posX, ptr->posY, ptr->posZ, ptr->unk_02E, 1, 3);
                    }
                }
                break;
        }
    } else {
        switch (D_800DC52C) {
            case 0:
                func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 3, 0);
                break;

            case 1:
            case 2:
                func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 3, 0);
                func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 3, 1);
                break;

            case 3:
                ptr = &D_800DC4E4;
                func_8001C4D0(D_800DC4DC->unk_0A4, D_800DC4DC->unk_0A8, D_800DC4DC->unk_0AC, D_800DC4DC->unk_0BC, 3, 0);
                func_8001C4D0(D_800DC4E0->posX, D_800DC4E0->posY, D_800DC4E0->posZ, D_800DC4E0->unk_02E, 3, 1);
                ptr++;
                func_8001C4D0(ptr->posX, ptr->posY, ptr->posZ, ptr->unk_02E, 3, 2);
                ptr++;
                func_8001C4D0(ptr->posX, ptr->posY, ptr->posZ, ptr->unk_02E, 3, 3);
                break;
        }
    }

    switch (D_800DC52C) {
        case 0:
            func_8003CD98(D_800DC4E0, camera1, 0, 0);
            func_8003CD98(D_800DC4E0, camera1, 1, 0);
            func_8003CD98(D_800DC4E4, camera1, 2, 0);
            func_8003CD98(D_800DC4E8, camera1, 3, 0);
            func_8003CD98(D_800DC4EC, camera1, 4, 0);
            func_8003CD98(D_800DC4F0, camera1, 5, 0);
            func_8003CD98(D_800DC4F4, camera1, 6, 0);
            func_8003CD98(D_800DC4F8, camera1, 7, 0);
            break;

        case 1:
        case 2:
            func_8003CD98(D_800DC4FC, camera1, 0, 0);
            func_8003CD98(D_800DC4E0, camera1, 1, 0);
            func_8003CD98(D_800DC4E4, camera1, 2, 0);
            func_8003CD98(D_800DC4E8, camera1, 3, 0);
            func_8003CD98(D_800DC4EC, camera1, 4, 0);
            func_8003CD98(D_800DC4F0, camera1, 5, 0);
            func_8003CD98(D_800DC4F4, camera1, 6, 0);
            func_8003CD98(D_800DC4F8, camera1, 7, 0);
            func_8003CD98(D_800DC4FC, camera2, 0, 1);
            func_8003CD98(D_800DC4E0, camera2, 1, 1);
            func_8003CD98(D_800DC4E4, camera2, 2, 1);
            func_8003CD98(D_800DC4E8, camera2, 3, 1);
            func_8003CD98(D_800DC4EC, camera2, 4, 1);
            func_8003CD98(D_800DC4F0, camera2, 5, 1);
            func_8003CD98(D_800DC4F4, camera2, 6, 1);
            func_8003CD98(D_800DC4F8, camera2, 7, 1);
            break;

        case 3:
            func_8003CD98(D_800DC4FC, camera1, 0, 0);
            func_8003CD98(D_800DC4E0, camera1, 1, 0);
            func_8003CD98(D_800DC4E4, camera1, 2, 0);
            func_8003CD98(D_800DC4E8, camera1, 3, 0);
            func_8003CD98(D_800DC4FC, camera2, 0, 1);
            func_8003CD98(D_800DC4E0, camera2, 1, 1);
            func_8003CD98(D_800DC4E4, camera2, 2, 1);
            func_8003CD98(D_800DC4E8, camera2, 3, 1);
            func_8003CD98(D_800DC4FC, camera3, 0, 2);
            func_8003CD98(D_800DC4E0, camera3, 1, 2);
            func_8003CD98(D_800DC4E4, camera3, 2, 2);
            func_8003CD98(D_800DC4E8, camera3, 3, 2);
            func_8003CD98(D_800DC4FC, camera4, 0, 3);
            func_8003CD98(D_800DC4E0, camera4, 1, 3);
            func_8003CD98(D_800DC4E4, camera4, 2, 3);
            func_8003CD98(D_800DC4E8, camera4, 3, 3);
            break;
    }
}
#else
GLOBAL_ASM("asm/non_matchings//code_800393C0/func_8003D080.s")
#endif

// #ifdef NON_MATCHING
// TODO: verify this claim because just changing the prototype makes it match
// if 1C is typed as s32 it matches, but spawn_player saves it as a float
// it's z pos so it should be a float, m2c detects it as f32 in func_8001C4D0
void func_8003DB5C(void) {
    Player *player = D_800DC4DC;
    s32 i;

    func_8001C4D0(player->posX, player->posY, player->posZ, player->unk_02E, 3, 0);
    func_8001C4D0(player->posX, player->posY, player->posZ, player->unk_02E, 3, 1);
    
    for (i = 0; i < 8; i++, player++) {
        func_80027A20(player, i, 1, 0);
        func_80027A20(player, i, 1, 1);
    }
}
// #else
// GLOBAL_ASM("asm/non_matchings/code_800393C0/func_8003DB5C.s")
// #endif
