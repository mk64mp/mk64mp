#include <ultra64.h>
#include <macros.h>
#include <types.h>
#include <common_structs.h>
#include <config.h>
#include <defines.h>
#define MP 1

extern Player *D_800DC4E0;
extern Player *D_800DC4E4;
extern Player *D_800DC4E8;
extern Player *D_800DC4FC;
extern Player *D_800DC500;

extern struct Camera *camera1;
extern struct Camera *camera2;
extern struct Camera *camera3;
extern struct Camera *camera4;

extern struct Controller gControllers[];
extern struct Controller *D_800DC4BC;
extern struct Controller *D_800DC4C4;
extern struct Controller *D_800DC4C8;
extern struct Controller *D_800DC4CC;
extern struct Controller *D_800DC4D0;
extern struct Controller *D_800DC4D4;

extern struct UnkStruct_800DC5EC D_8015F480[];
extern struct UnkStruct_800DC5EC *D_800DC5EC;
extern struct UnkStruct_800DC5EC *D_800DC5F0;
extern struct UnkStruct_800DC5EC *D_800DC5F4;
extern struct UnkStruct_800DC5EC *D_800DC5F8;

extern u8 *D_8015F8BC;
extern u8 *D_8015F8B8;
extern u8 *D_8015F8C0;
extern u8 *D_8015F8C4;
extern u8 *D_8015F8C8;
extern u8 *D_8015F8CC;

extern s16 D_8018D8C0[];
extern s16 D_8016348C;
extern s8 gCourseSelection;
extern s32 D_800DC544;

extern Player gPlayers[];
extern Player *D_800DC4E0;
extern Player *D_800DC4DC;
extern s32 lapCount[];
extern s32 D_80150120;
extern s32 gModeSelection;
extern s32 gPlayerCountSelection1;
extern u16 D_802BA048;
extern s32 D_800DC510;

extern s32 D_80150124;
extern u16 D_800DC5B4;
extern u16 D_800DC5B0;
extern u16 D_800DC5B8;
extern s32 D_800E86A0;

extern s8 D_8018EE08;
extern u16 D_800DC51C;
extern f32 D_80150118;
extern u16 D_800DC518;
extern u16 D_8015011E;
extern float gCourseTimer;
extern float D_800DC594;
extern s32 D_800DC530;
extern s32 D_8018D2AC;
extern s32 D_800DC52C;
extern s16 gCurrentCourseId;
extern u16 D_80162DD4[];
extern u16 D_8015F890;
extern u32 D_800DC5AC;
extern u16 gEnableDebugMode;
extern s32 D_800DC5E8;
extern u16 D_800DC5C0, D_800DC5C4;
extern s32 D_802B91E0;
extern s16 D_8015F8F2[];

extern f32 D_8015F8D8;
extern f32 D_80150148;

extern void func_800CA118();
extern void func_800CA49C();
extern void func_8028E678();
extern void func_80009B60();

extern void func_800CA330();
extern void func_800CA388();

extern void func_80092630();
extern void func_8028E438();
extern void func_800C8EF8();
extern void play_sound2();
extern void func_80002DAC();
extern void func_8005C64C();
extern void func_8028F914();
extern void func_802A7940();
extern void func_802A7728();
extern void func_80078F64();
extern void func_800925A0();
extern void func_8028F4E8();
extern void func_8028EDA8();
extern void func_8028E0F0();
extern void func_8028F3F0();
extern void func_8028F970();
extern void func_8028E298();
extern void func_80092564();
extern void func_8028F8BC();
extern void func_800029B0();
extern void func_800C8EAC();
extern void func_800074D4();
extern void func_80005AE8();

extern u16 D_8015F894;

u16 D_802BA030;
u16 D_802BA032;

float D_802BA034;


s32 D_802BA038;
UNUSED s32 D_802BA03C;


s16 D_802BA040[4];
u16 D_802BA048;

#ifdef MP
//s16 raceComplete = 3;
#endif

void func_8028DF00(void) {
    struct Controller *controllers = &gControllers[0];
    s32 i;
    for (i = 0; i < 4; i++) {
        D_802BA040[i] = controllers->button;
        controllers++; 
    }
}

void func_8028DF38(void) {
    struct Controller *controllers = &gControllers[0];
    s32 i;
    for (i = 0; i < 4; i++) {
        controllers->buttonPressed = (controllers->button & (D_802BA040[i] ^ controllers->button));
        controllers->buttonDepressed = (D_802BA040[i] & (D_802BA040[i] ^ controllers->button));
        controllers->button = D_802BA040[i];
        controllers++;
    }
}

void func_8028E028(void) {

    switch(gPlayerCountSelection1) {
        case 2:
            *(D_8015F8C4 + D_800DC5E8) += 1;
            break;
        case 3:
            *(D_8015F8C8 + D_800DC5E8) += 1;
            break;
        case 4:
            *(D_8015F8CC + D_800DC5E8) += 1;
            break;
    }
    func_800CA118((u8) D_800DC5E8);
    D_800DC510 = 5;
    D_802BA038 = 10;
}

void func_8028E0F0(void) {
    Player *ply;
    s32 i;
    s16 unk_arr2[4];
    s16 unk_arr[4];
    s16 phi_s1 = 0;
    s16 phi_s2 = 0;
    
    for(i = 0; i < 4; i++) {
        ply = (Player *)&gPlayers[i];
        if (!(ply->unk_000 & PLAYER_EXISTS)) {
            continue;
        }
        if (ply->unk_000 & PLAYER_CINEMATIC_MODE) {
            continue;
        }

        if (D_8018D8C0[i] < 0) {
            ply->unk_000 |= PLAYER_CINEMATIC_MODE;
            unk_arr[phi_s2] = (s16) (ply - D_800DC4DC);
            phi_s2++;
            func_800CA118((u8) i);
        } else {
            unk_arr2[phi_s1] = (s16) (ply - D_800DC4DC);
            phi_s1++;
        }
    }
    if (phi_s1 == 1) {
        D_800DC5E8 = (s32) unk_arr2[0];
        func_8028E028();
    } else if (phi_s1 == 0) {
        D_800DC5E8 = (s32) unk_arr[0];
        func_8028E028();
    }
}
extern f32 D_8015F898[];
extern u16 D_801645B0[];
extern u16 D_801645C8[];
extern f32 D_801644A8[];

void func_8028E298(void) {
    f32 temp_v0;
    s32 i;
    u16 temp_a2;

    for (i = 0; i < 8; i++) {

        if ((gPlayers[i].unk_000 & PLAYER_CINEMATIC_MODE)) {
            continue;
        }
            temp_a2 = D_801645B0[i];
            
            temp_v0 = ((2 - gPlayers[i].unk_008) * D_801645C8[temp_a2]);
            temp_v0 += D_801645C8[temp_a2] * (1.0f - D_801644A8[i]);
            temp_v0 /= 15.0f;

            D_8015F898[i] = gCourseTimer + temp_v0;
    }
    D_8016348C = 1;
    func_800070F4();
}

void func_8028E3A0(void) {

    if (D_80150120) {
        #ifdef MP
            //raceComplete = 3;
        #endif

        if (gCourseSelection == COURSE_BANSHEE_BOARDWALK) {
            D_80150124 = 5;
        } else {
            D_800DC544++;
            gCourseSelection++;
            D_80150124 = 4;
        }
    } else {
        D_800DC544++;
        gCourseSelection++;
        D_80150124 = 4;
    }
}

void func_8028E438(void) {
    struct UnkStruct_800DC5EC *temp_v0 = &D_8015F480[D_800DC5E8];
    s32 phi_v1_4;

    D_800DC5B0 = 1;

    switch(D_8015F894) {
        case 0:
            D_800DC5B8 = 0;
            D_8015F894 = 1;
            if (gPlayerCountSelection1 == 3) {
                func_800925CC();
            }
            break;
        case 1:
            if (temp_v0->screenWidth < SCREEN_WIDTH) {
                temp_v0->screenWidth += 2;
            }
            if (temp_v0->screenHeight < SCREEN_HEIGHT) {
                temp_v0->screenHeight += 2;
            }
            if (temp_v0->screenStartX < 160) {
                temp_v0->screenStartX += 1;

            } else if (temp_v0->screenStartX > 160) {
                temp_v0->screenStartX -= 1;
            }
            if (temp_v0->screenStartY < 120) {
                temp_v0->screenStartY += 1;
            } else if (temp_v0->screenStartY > 120) {
                temp_v0->screenStartY -= 1;
            }
            phi_v1_4 = 0;

            if (temp_v0->screenHeight >= SCREEN_HEIGHT) {
                phi_v1_4++;
                temp_v0->screenHeight = SCREEN_HEIGHT;
            }
            if (temp_v0->screenWidth >= SCREEN_WIDTH) {
                temp_v0->screenWidth = SCREEN_WIDTH;
                phi_v1_4++;
            }

            if (temp_v0->screenStartY == 120) {
                phi_v1_4++;
            }
            if (temp_v0->screenStartX == 160) {
                phi_v1_4++;
            }
            D_80150148 = (f32) ((f32) temp_v0->screenWidth / (f32) temp_v0->screenHeight);
            if (phi_v1_4 == 4) {
                D_8015F894 = 2;
                D_800DC52C = 0;
                D_800DC5EC->screenWidth = temp_v0->screenWidth;
                D_800DC5EC->screenHeight = temp_v0->screenHeight;
                D_800DC5EC->screenStartX = temp_v0->screenStartX;
                D_800DC5EC->screenStartY = temp_v0->screenStartY;
                if (gModeSelection == BATTLE) {
                    func_80092604();
                } else if (gModeSelection == VERSUS) {
                    func_80092604();
                    func_80019DF4();
                } else {
                    func_80092564();
                    D_800DC510 = 7;
                }
            }
            break;
        case 2:
            break;
    }
}

void func_8028E678(void) {
    s32 phi_a0_10 = 0;

    D_800DC5B0 = 1;

    switch (D_8015F894) {
        case 0:
            // Unused switch?
            switch(gModeSelection) {
                case GRAND_PRIX:
                case VERSUS:
                    break;
                case TIME_TRIALS:
                    break;
            }
            D_800DC5B8 = 0;
            switch(D_800DC530) {
                case 0:
                    D_8015F894 = 1;
                    break;
                case 1:
                    D_8015F894 = 5;
                    break;
                case 2:
                    D_8015F894 = 6;
                    break;
            }
            break;
        case 5:
            D_800DC5EC->screenWidth -= 4;

            D_800DC5F0->screenWidth -= 4;

            D_800DC5EC->screenStartX -= 2;

            D_800DC5F0->screenStartX += 2;

            if (D_800DC5EC->screenWidth < 160) {
                D_800DC5EC->screenWidth = 160;
                phi_a0_10++;
            }
            
            if (D_800DC5F0->screenWidth < 160) {
                D_800DC5F0->screenWidth = 160;
                phi_a0_10++;
            }


            if (D_800DC5EC->screenStartX < 80) {
                D_800DC5EC->screenStartX = 80;
                phi_a0_10++;
            }

            if (D_800DC5F0->screenStartX > SCREEN_HEIGHT) {
                D_800DC5F0->screenStartX = SCREEN_HEIGHT;
                phi_a0_10++;
            }

            D_80150148 = (f32) ((f32) D_800DC5EC->screenWidth / (f32) D_800DC5EC->screenHeight);
            if (phi_a0_10 == 4) {
                D_8015F894 = 3;
                func_80092500();
                func_80019DE4();
                func_80041D24();
            }
            break;
        case 6:
            D_800DC5EC->screenHeight -= 4;
            D_800DC5F0->screenHeight -= 4;
            D_800DC5EC->screenStartY -= 2;
            D_800DC5F0->screenStartY += 2;

            if (D_800DC5EC->screenHeight < 120) {
                D_800DC5EC->screenHeight = 120;
                phi_a0_10++;
            }

            if (D_800DC5F0->screenHeight < 120) {
                D_800DC5F0->screenHeight = 120;
                phi_a0_10++;
            }

            if ( D_800DC5EC->screenStartY < 60) {
                D_800DC5EC->screenStartY = 60;
                phi_a0_10++;
            }

            if ( D_800DC5F0->screenStartY > 180) {
                D_800DC5F0->screenStartY = 180;
                phi_a0_10++;
            }

            D_80150148 = (f32) ((f32) D_800DC5EC->screenWidth / (f32) D_800DC5EC->screenHeight);
            if (phi_a0_10 == 4) {
                D_8015F894 = 3;
                func_80092500();
                func_80019DE4();
            }
            break;
        case 1:
            D_800DC5EC->screenHeight -= 2;
            D_800DC5EC->screenWidth = (D_800DC5EC->screenHeight * SCREEN_WIDTH) / SCREEN_HEIGHT;

            if (D_800DC5EC->screenHeight < 120) {

                D_800DC5EC->screenHeight = 120;
                D_800DC5EC->screenWidth = (D_800DC5EC->screenHeight * SCREEN_WIDTH) / SCREEN_HEIGHT;
                D_8015F894 = 2;

                D_800DC5F0->screenWidth = D_800DC5EC->screenWidth;
                D_800DC5F0->screenHeight = D_800DC5EC->screenHeight;
                D_800DC5F0->screenStartX = D_800DC5EC->screenStartX;
                D_800DC5F0->screenStartY = D_800DC5EC->screenStartY;

                D_800DC52C = 2;
                D_80150148 = 1.33333337;
                gPlayerCountSelection1 = 2;
                func_8003DB5C();
                func_8005994C();
            }
            break;
        case 2:
            D_800DC5EC->screenStartX -= 4;

            D_800DC5EC->screenStartY -= 2;

            if (D_800DC5EC->screenStartX < 80) {
                D_800DC5EC->screenStartX = 80;
                phi_a0_10++;
            }

            if (D_800DC5EC->screenStartY < 60) {
                D_800DC5EC->screenStartY = 60;
                phi_a0_10++;
            }
            D_800DC5F0->screenStartX += 4;
            D_800DC5F0->screenStartY += 2;

            if (D_800DC5F0->screenStartX > SCREEN_HEIGHT) {
                D_800DC5F0->screenStartX = SCREEN_HEIGHT;
                phi_a0_10++;
            }
            if (D_800DC5F0->screenStartY > 180) {
                D_800DC5F0->screenStartY = 180;
                phi_a0_10++;
            }
            if (phi_a0_10 == 4) {
                D_8015F894 = 7;
                D_802BA030 = 3;
            }
            break;
        case 7:
            D_802BA030--;
            if (D_802BA030 == 0) {
                D_8015F894 = 3;
                func_80092500();
                if (gModeSelection == GRAND_PRIX) {
                    func_80019DE4();
                } else {
                    func_80019E58();
                }
            }
            break;
        case 4:
            D_800DC5C0 = 1;
            D_800DC5C4 = 5;
            D_800DC510 = 7;
            func_8028E3A0();
            break;
    }
}

void func_8028EC38(s32 arg0) {
    D_80150124 = arg0;
    D_800DC510 = 6;
    func_800CA330(25);
    func_800CA388(25);
    D_800DC5B4 = 1;
    D_800DC5B0 = 1;
    D_800DC5B8 = 0;
    D_802BA038 = 5;
}

void func_8028EC98(s32 arg0) {

    if (D_800DC530 == 3) {
        return;
    }

    func_800029B0();

    switch (arg0) {
        case 0:
        case 7:
        case 8:
        case 14:
            func_800C8EAC(3);
            break;
        case 10:
            func_800C8EAC(21);
            break;
        case 4:
        case 9:
            func_800C8EAC(4);
            break;
        case 1:
        case 15:
        case 17:
            func_800C8EAC(5);
            break;
        case 11:
            func_800C8EAC(10);
            break;
        case 6:
            func_800C8EAC(6);
            break;
        case 2:
            func_800C8EAC(9);
            break;
        case 3:
            func_800C8EAC(7);
            break;
        case 5:
        case 12:
            func_800C8EAC(8);
            break;
        case 13:
            func_800C8EAC(18);
            break;
        case 18:
            func_800C8EAC(19);
            break;
        case 16:
        case 19:
            func_800C8EAC(25);
            break;
    }
    
}

void func_8028EDA8(void) {
    s32 i;

    D_8015011E = -1;
    if (D_800DC51C == 0) {
        func_8028EC98(gCurrentCourseId);
    }

    if (D_800DC510 == 2) {
        D_800DC510 = 3;
    }

    for (i = 0; i < 8; i++) {

        if ((gPlayers[i].unk_000 & PLAYER_EXISTS) == 0) {
            continue;
        }

        // Sets player to human.
        if (gPlayers[i].unk_000 & PLAYER_START_SEQUENCE) {
            gPlayers[i].unk_000 ^= PLAYER_START_SEQUENCE;
        }    
    }
}

f32 func_8028EE8C(s32 arg0) {
    f32 temp_v0 = gPlayers[arg0].posZ;
    f32 temp_v1 = gPlayers[arg0].rotZ;
    f32 temp_f14 = D_8015F8D8 - temp_v0;
    f32 temp_f16 = temp_v1 - D_8015F8D8;
    return gCourseTimer - ((0.01666666f * temp_f14) / (temp_f14 + temp_f16));
}

void func_8028EEF0(s32 i) {
    gPlayers[i].unk_000 |= PLAYER_CINEMATIC_MODE;
}
void mp_gp_win(Player*, s16, s32);
void mp_vs_win(Player*, s16, s32);


void func_8028EF28(void) {
    Player *ply;
    s16 currentPosition;
    s32 i;

    for (i = 0; i < 8; i ++) {
        ply = &gPlayers[i];
        
        // If player exists?
        if ((gPlayers[i].unk_000 & PLAYER_EXISTS) == 0) {
            continue;
        }

        // Set currentLap for each player.
        if (lapCount[i] < gPlayers[i].unk_008) {
            gPlayers[i].unk_008--;
        } else if (lapCount[i] > gPlayers[i].unk_008) {
            gPlayers[i].unk_008++;
        }

        

        // Player finished the race
        if (gPlayers[i].unk_008 == 3) {
            func_8028EEF0(i); // Cinematic mode.
            currentPosition = gPlayers[i].unk_004;



            if ((gPlayers[i].unk_000 & PLAYER_CPU) && ((gPlayers[i].unk_000 & PLAYER_HUMAN) == 0)) {
                
                if (currentPosition >= 6) {
                    D_80150120 = 1;
                    D_800DC510 = 4;
                }
                continue;
            }
            

            switch(gModeSelection) {
                case GRAND_PRIX:
                    mp_gp_win(ply, i, currentPosition);
                    break;
                case VERSUS:
                    mp_vs_win(ply, i, currentPosition);
                    break;

            }
        } else if (gPlayers[i].unk_008 == 2) {
            if ((gPlayers[i].unk_000 & PLAYER_INVISIBLE_OR_BOMB) != 0) {
                return;
            }
            // Activate final lap lakitu notification.
            if ((D_802BA032 & 0x4000) == 0) {
                D_802BA032 |= 0x4000;
                func_800CA49C((u8)i);
            }
        }
    }
    
} 

void mp_gp_win(Player *ply, s16 currentPosition, s32 i) {

    // if local player is human
    if ((i == 0) && (gPlayers[0].unk_000 & PLAYER_HUMAN) && (!(gPlayers[i].unk_000 & PLAYER_CPU))) {
        // Set to AI controlled
        gPlayers[0].unk_000 |= PLAYER_CPU;

        if (currentPosition >= 6) {
            D_80150120 = 1;
            D_800DC510 = 4;
        }

        // Finished race sound
        func_800CA118((u8)0);
        if ((D_802BA032 & 0x8000) == 0) {
                D_802BA032 |= 0x8000;
        }
    }
    if (D_800DC510 <= 3) {
        D_800DC510 = 3;
    }

    // Race completed
    // If in seventh
    // todo: Make game end despite eighth player not finishing.
    //if (currentPosition == 6) {
        /**
         * Force player 1 to be done race if in eighth.
         * @bug Eighth player wins if uncomment below.
        **/
        //if (currentPosition == 7) {
            
            // Stop timer
            //func_8028EEF0(0);
            // Set to computer
            // Todo: Set to silent computer.
            //gPlayers[i].unk_000 |= PLAYER_CPU;
        //}
        //return;
    //}
    // Continue racing or done.
    //if (D_800DC510 < 4) {
    //    D_800DC510 = 3;
    //}
}

void mp_vs_win(Player *ply, s16 currentPosition, s32 i) {
    // Potential future MP VS code.
}

void func_8028F3E8(void) {

}
extern s32 D_801643B8[];
extern s16 D_8015F8F0[];

void func_8028F3F0(void) {
    s16 i;
    s16 temp_a0_2;

    for (i = 0; i < 8; i++) {
        if (((gPlayers[i].unk_000 & PLAYER_EXISTS) != 0) &&
            ((gPlayers[i].unk_000 & PLAYER_CINEMATIC_MODE) == 0) &&
            ((gPlayers[i].unk_000 & PLAYER_INVISIBLE_OR_BOMB) == 0)) {
            temp_a0_2 = D_801643B8[i];
            gPlayers[i].unk_004 = temp_a0_2;
            D_8015F8F0[temp_a0_2] = i;
        }
    }
}

void func_8028F474(void) {
    s32 i;

        switch (D_800DC510) {
        case 3:
        case 4:
        case 5:
        case 7:
            for (i = 0; i < 8; i++) {
                func_80009B60(i);
            }
        case 1:
        case 2:
            func_800097E0();
            break;
        }
}

void func_8028F4E8(void) {
    if (gEnableDebugMode != 0) {
        if (((D_800DC4CC->button & 0x10) != 0) &&
            ((D_800DC4CC->button & 0x20) != 0) &&
            ((D_800DC4CC->button & 0x8000) != 0) &&
            ((D_800DC4CC->button & 0x4000) != 0)) {

            func_800CA330(0x19);
            func_800CA388(0x19);
            D_80150124 = 0;
            D_800DC510 = 6;
            D_800DC5B4 = 1;
            D_800DC5B0 = 1;
            D_800DC5B8 = 0;
            D_802BA038 = 5;
        }
    }
}

#ifdef MIPS_TO_C
void func_8028F588(void) {
    s32 temp_f10;
    s32 temp_f10_2;
    s32 temp_f10_3;
    s32 temp_f18;
    s32 temp_f18_2;
    s32 temp_f6;
    s32 temp_f6_2;
    s32 temp_f6_3;
    s32 temp_v0;
    s16 phi_v0;
    s16 phi_v0_2;
    s16 phi_v0_3;
    s16 phi_v0_4;
    s16 phi_v0_5;
    s16 phi_v0_6;
    s16 phi_v0_7;
    s16 phi_v0_8;

    temp_v0 = D_800DC52C;
    if (temp_v0 != 0) {
        if (temp_v0 != 1) {
            if (temp_v0 != 2) {
                if (temp_v0 != 3) {
                    return;
                }
                temp_f10 = (s32) (160.0f * D_802BA034);
                if ((s32) (s16) temp_f10 <= 0) {
                    phi_v0 = 1;
                } else {
                    phi_v0 = (s16) temp_f10;
                    if ((s32) (s16) temp_f10 >= 0x140) {
                        phi_v0 = 0x13C;
                    }
                }
                D_800DC5EC->screenWidth = phi_v0;
                D_800DC5F0->screenWidth = phi_v0;
                D_800DC5F4->screenWidth = phi_v0;
                D_800DC5F8->screenWidth = phi_v0;
                temp_f6 = (s32) (120.0f * D_802BA034);
                if ((s32) (s16) temp_f6 <= 0) {
                    phi_v0_2 = 1;
                } else {
                    phi_v0_2 = (s16) temp_f6;
                    if ((s32) (s16) temp_f6 >= 0xF0) {
                        phi_v0_2 = 0xEC;
                    }
                }
                D_800DC5EC->screenHeight = phi_v0_2;
                D_800DC5F0->screenHeight = phi_v0_2;
                D_800DC5F4->screenHeight = phi_v0_2;
                D_800DC5F8->screenHeight = phi_v0_2;
                return;
            }
            temp_f18 = (s32) (160.0f * D_802BA034);
            if ((s32) (s16) temp_f18 <= 0) {
                phi_v0_3 = 1;
            } else {
                phi_v0_3 = (s16) temp_f18;
                if ((s32) (s16) temp_f18 >= 0x140) {
                    phi_v0_3 = 0x13C;
                }
            }
            D_800DC5EC->screenWidth = phi_v0_3;
            D_800DC5F0->screenWidth = phi_v0_3;
            temp_f10_2 = (s32) (240.0f * D_802BA034);
            if ((s32) (s16) temp_f10_2 <= 0) {
                phi_v0_4 = 1;
            } else {
                phi_v0_4 = (s16) temp_f10_2;
                if ((s32) (s16) temp_f10_2 >= 0x1E0) {
                    phi_v0_4 = 0x1DC;
                }
            }
            D_800DC5EC->screenHeight = phi_v0_4;
            D_800DC5F0->screenHeight = phi_v0_4;
            return;
        }
        temp_f6_2 = (s32) (320.0f * D_802BA034);
        if ((s32) (s16) temp_f6_2 <= 0) {
            phi_v0_5 = 1;
        } else {
            phi_v0_5 = (s16) temp_f6_2;
            if ((s32) (s16) temp_f6_2 >= 0x280) {
                phi_v0_5 = 0x27C;
            }
        }
        D_800DC5EC->screenWidth = phi_v0_5;
        D_800DC5F0->screenWidth = phi_v0_5;
        temp_f18_2 = (s32) (120.0f * D_802BA034);
        if ((s32) (s16) temp_f18_2 <= 0) {
            phi_v0_6 = 1;
        } else {
            phi_v0_6 = (s16) temp_f18_2;
            if ((s32) (s16) temp_f18_2 >= 0xF0) {
                phi_v0_6 = 0xEC;
            }
        }
        D_800DC5EC->screenHeight = phi_v0_6;
        D_800DC5F0->screenHeight = phi_v0_6;
        return;
    }
    temp_f10_3 = (s32) (320.0f * D_802BA034);
    phi_v0_7 = (s16) temp_f10_3;
    if ((s32) (s16) temp_f10_3 < 0) {
        phi_v0_7 = 1;
    }
    D_800DC5EC->screenWidth = phi_v0_7;
    temp_f6_3 = (s32) (240.0f * D_802BA034);
    phi_v0_8 = (s16) temp_f6_3;
    if ((s32) (s16) temp_f6_3 < 0) {
        phi_v0_8 = 1;
    }
    D_800DC5EC->screenHeight = phi_v0_8;
}
#else
GLOBAL_ASM("asm/non_matchings/code_8028DF00/func_8028F588.s")
#endif

void func_8028F8BC(void) {
    D_802BA034 = (f32) (D_802BA034 - 0.017f);
    if (D_802BA034 < 0.0f) {
        D_802BA034 = 0.0f;
    }
    func_8028F588();
}

void func_8028F914(void) {
    D_802BA034 = (f32) (D_802BA034 + 0.028f);
    if (D_802BA034 > 1.0f) {
        D_802BA034 = 1.0f;
    }
    func_8028F588();
}

#ifdef MIPS_TO_C
void func_8028F970(void) {
    Player *temp_a0;
    Player *temp_a0_2;
    Player *temp_a0_3;
    s32 temp_s2;
    struct Controller *temp_a1;
    struct Controller *temp_s0;
    u16 temp_t7;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    Player *phi_s3;
    s32 phi_s2;
    u16 phi_a0;

    if (D_8015F890 == 0) {
        phi_s3 = gPlayers;
        phi_s2 = 0;
loop_2:
        temp_v0 = phi_s3->unk_000;
        if (((temp_v0 & PLAYER_HUMAN) != 0) && ((temp_v0 & PLAYER_CPU) == 0)) {
            temp_s0 = &gControllers[phi_s2];
            if (D_800DC52C != 3) {
                temp_v0_2 = temp_s0->buttonPressed;
                if (((temp_v0_2 & 0x20) != 0) && ((temp_s0->button & 0x10) == 0)) {
                    temp_s0->buttonPressed = temp_v0_2 & 0xFFDF;
                    temp_t7 = D_800DC5A8 + 1;
                    D_800DC5A8 = temp_t7;
                    if ((temp_t7 & 0xFFFF) >= 3) {
                        D_800DC5A8 = 0U;
                    }
                    play_sound2(0x4900801C);
                    func_800029B0();
                }
            }
            if (((temp_s0->buttonPressed & 0x1000) != 0) && (temp_v0_3 = temp_s0->button, ((temp_v0_3 & 0x10) == 0)) && ((temp_v0_3 & 0x20) == 0)) {
                func_8028DF00();
                D_800DC5FC = (s16) (((s32) (temp_s0 - D_800DC4BC) >> 4) + 1);
                temp_s0->buttonPressed = 0;
                func_800C9F90(1);
                D_80162DF0 = 1;
                if (gModeSelection == TIME_TRIALS) {
                    temp_a0 = D_800DC4DC;
                    if ((temp_a0->unk_000 & 0x8100) != 0) {
                        func_80005AE8(temp_a0);
                    }
                    temp_a0_2 = D_800DC4E0;
                    if ((temp_a0_2->unk_000 & 0x8100) != 0) {
                        func_80005AE8(temp_a0_2);
                    }
                    temp_a0_3 = D_800DC4E4;
                    if ((temp_a0_3->unk_000 & 0x8100) != 0) {
                        func_80005AE8(temp_a0_3);
                        return;
                    }
                    // Duplicate return node #29. Try simplifying control flow for better match
                    return;
                }
                // Duplicate return node #29. Try simplifying control flow for better match
                return;
            }
            goto block_20;
        }
block_20:
        temp_s2 = phi_s2 + 1;
        phi_s3 += 0xDD8;
        phi_s2 = temp_s2;
        if (temp_s2 == 4) {
            if ((gEnableDebugMode != 0) && (gModeSelection != BATTLE)) {
                temp_a1 = D_800DC4BC;
                if ((temp_a1->buttonPressed & 0x800) != 0) {
                    lapCount->unk0 = 2;
                }
                phi_a0 = temp_a1->buttonPressed;
                if ((temp_a1->buttonPressed & 0x100) != 0) {
                    lapCount->unk0 = 2;
                    lapCount->unk4 = 2;
                    phi_a0 = temp_a1->buttonPressed;
                }
                if ((phi_a0 & 0x400) != 0) {
                    lapCount->unk0 = 2;
                    lapCount->unk4 = 2;
                    lapCount->unk8 = 2;
                    lapCount->unkC = 2;
                    lapCount->unk10 = 2;
                    lapCount->unk14 = 2;
                    lapCount->unk18 = 2;
                    lapCount->unk1C = 2;
                }
            }
            // Duplicate return node #29. Try simplifying control flow for better match
            return;
        }
        goto loop_2;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_8028DF00/func_8028F970.s")
#endif

void func_8028FBD4(void) {
    D_80150124 = 0;
    D_800DC510 = 6;
    func_800CA330(25);
    func_800CA388(25);
    D_800DC5B4 = 1;
    D_800DC5B0 = 1;
    D_800DC5B8 = 0;
    D_802BA038 = 5;
}

void func_8028FC34(void) {
    if (D_802BA038 < 0) {
        D_802BA038 = 1920;
        return;
    }
    D_802BA038--;
    if (D_800DC4CC->buttonPressed != 0) {
        func_8028FBD4();
        D_800E86A0 = 10;
        return;
    }
    if (D_802BA038 == 0) {
        func_8028FBD4();
        D_800E86A0 = 8;
    }
}
extern u16 D_80162DD6;

void func_8028FCBC(void) {
    Player *ply = &gPlayers[0];
    s32 i;
    u32 phi_v0_4;

    if (D_8018EE08) {
        func_8028FC34();
    }
    switch (D_800DC510) {
        case 0:
            if (D_800DC51C == 0) {
                if (gModeSelection == GRAND_PRIX) {
                    func_800C8EF8(11);
                    play_sound2(0x49008018);
                    play_sound2(0x49008019);
                } else {
                    func_800C8EF8(22);
                }
            }
            func_80002DAC();
            D_800DC510 = 1;
            D_80150118 = 3.0f;
            D_800DC518 = 0;
            D_802BA032 = 0;
            D_8015011E = 0;
            gCourseTimer = 0.0f;
            D_800DC594 = 0.0f;
            D_800DC5B0 = 1;
            D_800DC5B4 = 1;
            D_802BA034 = 0.008f;
            D_8015F894 = 0;
            if (D_800DC530 != 0) {
                func_8005C64C(&D_8018D2AC);
            }
            for (i = 0; i < 8; i++) {
                if ((ply->unk_000 & PLAYER_EXISTS) == 0) {
                    continue;
                }
                ply->unk_000 |= PLAYER_START_SEQUENCE;
                ply++;
            }
            D_800DC5B8 = 1;
            break;
        case 1:
            func_8028F914();
            if (D_802BA034 == 1.0f) {
                if (D_800DC52C != 0) {
                    if (gCurrentCourseId == COURSE_LUIGI_RACEWAY) {
                        func_802A7940();
                    } else if (gCurrentCourseId == COURSE_WARIO_STADIUM) {
                        func_802A7728();
                    }
                }
                D_800DC510 = 2;
                D_800DC5B0 = 0;
                D_800DC5B8 = 1;
                func_80078F64();
                if ((gModeSelection == TIME_TRIALS) && (D_80162DD6 == 0)) {
                    phi_v0_4 = 0x1;
                    for (i = 0; i < gCurrentCourseId; i++) {
                        phi_v0_4 <<= 1;
                    }
                    if ((D_8015F890 == 0) && (!(D_800DC5AC & phi_v0_4))) {
                        func_80092630();
                        D_800DC5AC |= phi_v0_4;
                    }
                }
                if (gPlayerCountSelection1 == 3) {
                    func_800925A0();
                }
            }
            func_8028F4E8();
            break;
        case 2:
            if (D_800DC51C != 0) {
                func_8028EDA8();
            }
            if ((gEnableDebugMode != 0) && ((D_800DC4CC->buttonPressed & 0x2000) != 0)) {
                func_8028EDA8();
            }
            func_8028F4E8();
            break;
        case 3:
            if (gModeSelection == BATTLE) {
                func_8028E0F0();
            } else {
                func_8028F3F0();
                func_8028EF28();
            }
            func_8028F4E8();
            func_8028F970();
            break;
        case 4:

            switch(gModeSelection) {
                case GRAND_PRIX:
                    func_8028F4E8();
                    func_8028F3F0();
                    func_8028EF28();
                    func_8028F970();

                    switch(D_800DC530) {
                        case 0:
                            D_802BA038 = 690;
                            D_800DC510 = 5;
                            func_8028E298();
                            break;
                        case 1:
                        case 2:
                            if (((D_800DC4DC->unk_000 & PLAYER_CINEMATIC_MODE) != 0) && ((D_800DC4E0->unk_000 & PLAYER_CINEMATIC_MODE) != 0)) {
                            
                                if (D_800DC4DC->unk_004 < D_800DC4E0->unk_004) {
                                    D_800DC5E8 = 1;
                                } else {
                                    D_800DC5E8 = 0;
                                }

                                func_8028E298();
                                D_802BA038 = 600;
                                D_800DC510 = 5;
                            }
                            break;
                    }
                    break;
                case VERSUS:
                    func_8028F4E8();
                    func_8028F3F0();
                    func_8028EF28();
                    func_8028F970();
                    break;
                case TIME_TRIALS:
                    D_802BA038 = 360;
                    if (D_8015F890 != 0) {
                        D_800DC510 = 7;
                    } else {
                        D_800DC510 = 5;
                    }
                    break;
            }
            break;
        case 5:
            if (D_802BA038 != 0) {
                D_802BA038--;
            } else {
                switch(gModeSelection) {
                    case GRAND_PRIX:
                        if (D_80150120 != 0) {
                            func_8028E678();
                        } else if (D_800DC530 == 0) {
                            // Prevents losing in GP mode.
                            //func_80092564();
                            //D_800DC510 = 7;
                        } else {
                            func_8028E438();
                        }
                        break;
                    case TIME_TRIALS:
                        func_8028E678();
                        break;
                    case VERSUS:
                    case BATTLE:
                        func_8028E438();
                        break;
                }
            }
            func_8028F4E8();
            break;
        case 6:
            func_8028F8BC();
            if (D_802BA034 <= 0) {
                D_800DC5C0 = 1;
                D_800DC5C4 = 5;
            }
            break;
        case 7:
            break;
    }
}

UNUSED void func_80290314(void) {
    D_800DC5C0 = 1;
    D_800DC5C4 = 5;
    D_80150124 = 0;
}

void func_80290338(void) {
    D_800DC5C0 = 1;
    D_800DC5C4 = 5;
    D_80150124 = 1;
}

void func_80290360(void) {
    D_800DC5C0 = 1;
    D_800DC5C4 = 5;
    D_80150124 = 2;
}

void func_80290388(void) {
    D_800DC5C0 = 1;
    D_800DC5C4 = 5;
    D_80150124 = 3;
}

void func_802903B0(void) {
    D_800DC5C0 = 1;
    D_800DC5C4 = 5;
    D_80150124 = 4;
}

#ifdef MIPS_TO_C
void func_802903D8(u16 *arg0, u16 *arg1) {
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    ? sp28;
    f32 sp24;
    f32 sp20;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f6_2;
    s32 temp_v0;
    u16 *temp_a0;
    u16 *temp_a2;
    u16 *temp_a3;
    u16 *phi_a3;
    u16 *phi_a2;

    temp_f4 = (arg0->unk70 + arg1->unk70) - 5.0f;
    temp_a3 = arg0;
    temp_a2 = arg1;
    sp74 = temp_f4;
    sp28.unk0 = (s32) gFloatArray802B8790.unk0;
    sp28.unk4 = (s32) gFloatArray802B8790.unk4;
    sp28.unk8 = (s32) gFloatArray802B8790.unk8;
    sp28.unkC = (s32) gFloatArray802B8790.unkC;
    sp28.unk10 = (s32) gFloatArray802B8790.unk10;
    sp28.unk14 = (s32) gFloatArray802B8790.unk14;
    sp28.unk18 = (s32) gFloatArray802B8790.unk18;
    sp28.unk1C = (s32) gFloatArray802B8790.unk1C;
    sp24 = *(&sp28 + (arg0->unk254 * 4));
    sp20 = *(&sp28 + (arg1->unk254 * 4));
    sp60 = arg0->unk14 - arg1->unk14;
    temp_f6 = (arg0->unk18 - arg0->unk70) - (arg1->unk18 - arg1->unk70);
    sp64 = temp_f6;
    sp68 = arg0->unk1C - arg1->unk1C;
    sp54 = arg1->unk34 - arg0->unk34;
    sp58 = arg1->unk38 - arg0->unk38;
    sp5C = arg1->unk3C - arg0->unk3C;
    temp_f0 = (sp68 * sp68) + ((sp60 * sp60) + (temp_f6 * temp_f6));
    temp_f0_2 = sqrtf(temp_f0);
    if (!(temp_f0_2 < D_802B92A0) && !(temp_f4 < temp_f0_2)) {
        if ((arg0->unk0 & 0x40) != 0) {
            if ((arg1->unk0 & 0x40) != 0) {
                func_8008FC1C(temp_f0_2, temp_a2, temp_a3);
                func_8008FC1C((bitwise f32) arg1);
                func_800C9060(((s32) (arg1 - D_800DC4DC) / 0xDD8) & 0xFF, 6.643295e-24f, arg1);
                return;
            }
            temp_a0 = temp_a3;
            temp_a2->unkC = (s32) (temp_a2->unkC | 0x400000);
            sp70 = temp_f0_2;
            arg0 = temp_a3;
            arg1 = temp_a2;
            func_8008FC1C(temp_f0_2, temp_a0, temp_a2, temp_a3);
            func_800C9060(((s32) (arg1 - D_800DC4DC) / 0xDD8) & 0xFF, 6.643295e-24f, arg1);
            phi_a3 = arg0;
            phi_a2 = arg1;
            goto block_8;
        }
        phi_a3 = temp_a3;
        phi_a2 = temp_a2;
        if ((temp_a2->unk0 & 0x40) != 0) {
            temp_a3->unkC = (s32) (temp_a3->unkC | 0x400000);
            arg0 = temp_a3;
            func_8008FC1C(temp_f0_2, temp_a2, temp_a2, temp_a3);
            func_800C9060(((s32) (arg0 - D_800DC4DC) / 0xDD8) & 0xFF, 6.643295e-24f);
            return;
        }
block_8:
        temp_v0 = phi_a3->unkBC;
        if ((temp_v0 & 0x200) != 0) {
            if ((phi_a2->unkBC & 0x200) == 0) {
                phi_a2->unkC = (s32) (phi_a2->unkC | 0x1000000);
            }
        } else if ((phi_a2->unkBC & 0x200) != 0) {
            phi_a3->unkC = (s32) (phi_a3->unkC | 0x1000000);
        } else {
            phi_a3->unkBC = (s32) (temp_v0 | 0x8000);
            phi_a2->unkBC = (s32) (phi_a2->unkBC | 0x8000);
        }
        temp_f6_2 = sp60 / sqrtf(temp_f0);
        temp_f0_3 = sqrtf((sp5C * sp5C) + ((sp54 * sp54) + (sp58 * sp58)));
        sp60 = temp_f6_2;
        sp64 /= sqrtf(temp_f0);
        sp68 /= sqrtf(temp_f0);
        if (temp_f0_3 < D_802B92A4) {
            temp_f14 = (phi_a3->unk70 + phi_a2->unk70) * D_802B92A8;
            phi_a3->unk14 = (f32) ((temp_f6_2 * temp_f14) + phi_a2->unk14);
            phi_a3->unk18 = (f32) ((sp64 * temp_f14) + phi_a2->unk18);
            phi_a3->unk1C = (f32) ((sp68 * temp_f14) + phi_a2->unk1C);
            phi_a2->unk14 = (f32) (phi_a2->unk14 - (temp_f14 * sp60));
            phi_a2->unk18 = (f32) (phi_a2->unk18 - (temp_f14 * sp64));
            phi_a2->unk1C = (f32) (phi_a2->unk1C - (temp_f14 * sp68));
            return;
        }
        temp_f16 = (f32) ((f64) (temp_f0_3 * (((sp5C * sp68) + ((sp60 * sp54) + (sp64 * sp58))) / temp_f0_3)) * D_802B92B0);
        if ((phi_a3->unkBC & 0x200) != 0x200) {
            temp_f2 = (temp_f16 * sp20) / sp24;
            phi_a3->unk34 = (f32) (phi_a3->unk34 + (sp60 * temp_f2));
            phi_a3->unk38 = (f32) (phi_a3->unk38 + (sp64 * temp_f2));
            phi_a3->unk3C = (f32) (phi_a3->unk3C + (sp68 * temp_f2));
            temp_f0_4 = sqrtf(temp_f0) - sp74;
            phi_a3->unk14 = (f32) (phi_a3->unk14 - (sp60 * temp_f0_4 * 0.5f));
            phi_a3->unk18 = (f32) (phi_a3->unk18 - (sp64 * temp_f0_4 * 0.5f));
            phi_a3->unk1C = (f32) (phi_a3->unk1C - (sp68 * temp_f0_4 * 0.5f));
        }
        if ((phi_a2->unkBC & 0x200) != 0x200) {
            temp_f2_2 = (temp_f16 * sp24) / sp20;
            phi_a2->unk34 = (f32) (phi_a2->unk34 - (sp60 * temp_f2_2));
            phi_a2->unk38 = (f32) (phi_a2->unk38 - (sp64 * temp_f2_2));
            phi_a2->unk3C = (f32) (phi_a2->unk3C - (sp68 * temp_f2_2));
            temp_f0_5 = sqrtf(temp_f0) - sp74;
            phi_a2->unk14 = (f32) (phi_a2->unk14 + (sp60 * temp_f0_5 * 0.5f));
            phi_a2->unk18 = (f32) (phi_a2->unk18 + (sp64 * temp_f0_5 * 0.5f));
            phi_a2->unk1C = (f32) (phi_a2->unk1C + (sp68 * temp_f0_5 * 0.5f));
        }
        if ((phi_a3->unk0 & 0x4000) != 0) {
            func_800C9060((bitwise s32) 0.5f, sqrtf(temp_f0), (u16 *) (((s32) (phi_a3 - D_800DC4DC) / 0xDD8) & 0xFF), 0x19008001, phi_a2, phi_a3);
            return;
        }
        if ((phi_a2->unk0 & 0x4000) != 0) {
            func_800C9060((bitwise s32) 0.5f, sqrtf(temp_f0), (u16 *) (((s32) (phi_a2 - D_800DC4DC) / 0xDD8) & 0xFF), 0x19008001, phi_a2, phi_a3);
        }
        // Duplicate return node #24. Try simplifying control flow for better match
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_8028DF00/func_802903D8.s")
#endif

void func_802909F0(void) {
    Player *ply;
    Player *ply2;
    s32 i;
    s32 k;

    for (i = 0; i < 7; i++) {
        ply = &gPlayers[i];

        if ((ply->unk_000 & PLAYER_EXISTS) &&
          (!(ply->unk_0BC & 0x80000000)) &&
          (!(ply->unk_000 & PLAYER_INVISIBLE_OR_BOMB)) &&
          (!(ply->unk_0BC & 0x4000000))) {

            for (k = i + 1; k < 8; k++) {
                ply2 = &gPlayers[k];

                if ((ply2->unk_000 & PLAYER_EXISTS) &&
                    (!(ply2->unk_0BC & 0x80000000)) &&
                    (!(ply2->unk_000 & PLAYER_INVISIBLE_OR_BOMB)) &&
                    (!(ply2->unk_0BC & 0x4000000))) {

                    func_802903D8(ply, ply2);
                }
            }
        }
    }
}

void func_80290B14(void) {

    func_80059C50();

    switch(D_800DC52C) {
        case 0:
            func_8001EE98(D_800DC4FC, camera1, 0);
            break;
        case 1:
        case 2:
            func_8001EE98(D_800DC4FC, camera1, 0);
            func_8001EE98(D_800DC500, camera2, 1);
            break;
        case 3:
            func_8001EE98(D_800DC4FC, camera1, 0);
            func_8001EE98(D_800DC4E0, camera2, 1);
            func_8001EE98(D_800DC4E4, camera3, 2);
            func_8001EE98(D_800DC4E8, camera4, 3);
            break;
    }
}
