glabel func_800B63F0
/* 0B6FF0 800B63F0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0B6FF4 800B63F4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0B6FF8 800B63F8 AFB00014 */  sw    $s0, 0x14($sp)
/* 0B6FFC 800B63FC 00808025 */  move  $s0, $a0
/* 0B7000 800B6400 AFB30020 */  sw    $s3, 0x20($sp)
/* 0B7004 800B6404 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0B7008 800B6408 0C001471 */  jal   func_800051C4
/* 0B700C 800B640C AFB10018 */   sw    $s1, 0x18($sp)
/* 0B7010 800B6410 240E0001 */  li    $t6, 1
/* 0B7014 800B6414 3C018016 */  lui   $at, %hi(D_80162DD6) # $at, 0x8016
/* 0B7018 800B6418 3C04800E */  lui   $a0, %hi(D_800DC4E4) # $a0, 0x800e
/* 0B701C 800B641C A42E2DD6 */  sh    $t6, %lo(D_80162DD6)($at)
/* 0B7020 800B6420 0C0016BA */  jal   func_80005AE8
/* 0B7024 800B6424 8C84C4E4 */   lw    $a0, %lo(D_800DC4E4)($a0)
/* 0B7028 800B6428 3C188019 */  lui   $t8, %hi(D_8018EE10) # $t8, 0x8019
/* 0B702C 800B642C 3C198019 */  lui   $t9, %hi(gCupSelection) # $t9, 0x8019
/* 0B7030 800B6430 8339EE09 */  lb    $t9, %lo(gCupSelection)($t9)
/* 0B7034 800B6434 2718EE10 */  addiu $t8, %lo(D_8018EE10) # addiu $t8, $t8, -0x11f0
/* 0B7038 800B6438 001079C0 */  sll   $t7, $s0, 7
/* 0B703C 800B643C 3C098019 */  lui   $t1, %hi(gCourseSelection) # $t1, 0x8019
/* 0B7040 800B6440 8129EE0B */  lb    $t1, %lo(gCourseSelection)($t1)
/* 0B7044 800B6444 01F81021 */  addu  $v0, $t7, $t8
/* 0B7048 800B6448 804B0005 */  lb    $t3, 5($v0)
/* 0B704C 800B644C 00194080 */  sll   $t0, $t9, 2
/* 0B7050 800B6450 01095021 */  addu  $t2, $t0, $t1
/* 0B7054 800B6454 114B0003 */  beq   $t2, $t3, .L800B6464
/* 0B7058 800B6458 00009825 */   move  $s3, $zero
/* 0B705C 800B645C 1000001B */  b     .L800B64CC
/* 0B7060 800B6460 24130002 */   li    $s3, 2
.L800B6464:
/* 0B7064 800B6464 3C0C8016 */  lui   $t4, %hi(D_80162DFC) # $t4, 0x8016
/* 0B7068 800B6468 8D8C2DFC */  lw    $t4, %lo(D_80162DFC)($t4)
/* 0B706C 800B646C 8C4D0000 */  lw    $t5, ($v0)
/* 0B7070 800B6470 3C0E8016 */  lui   $t6, %hi(D_80162DE0) # $t6, 0x8016
/* 0B7074 800B6474 118D0003 */  beq   $t4, $t5, .L800B6484
/* 0B7078 800B6478 00000000 */   nop   
/* 0B707C 800B647C 10000013 */  b     .L800B64CC
/* 0B7080 800B6480 24130003 */   li    $s3, 3
.L800B6484:
/* 0B7084 800B6484 8DCE2DE0 */  lw    $t6, %lo(D_80162DE0)($t6)
/* 0B7088 800B6488 904F0006 */  lbu   $t7, 6($v0)
/* 0B708C 800B648C 00008025 */  move  $s0, $zero
/* 0B7090 800B6490 00408825 */  move  $s1, $v0
/* 0B7094 800B6494 11CF0003 */  beq   $t6, $t7, .L800B64A4
/* 0B7098 800B6498 2412003C */   li    $s2, 60
/* 0B709C 800B649C 1000000B */  b     .L800B64CC
/* 0B70A0 800B64A0 24130004 */   li    $s3, 4
.L800B64A4:
/* 0B70A4 800B64A4 0C02D83A */  jal   func_800B60E8
/* 0B70A8 800B64A8 02002025 */   move  $a0, $s0
/* 0B70AC 800B64AC 92380007 */  lbu   $t8, 7($s1)
/* 0B70B0 800B64B0 26100001 */  addiu $s0, $s0, 1
/* 0B70B4 800B64B4 13020003 */  beq   $t8, $v0, .L800B64C4
/* 0B70B8 800B64B8 00000000 */   nop   
/* 0B70BC 800B64BC 10000003 */  b     .L800B64CC
/* 0B70C0 800B64C0 24130001 */   li    $s3, 1
.L800B64C4:
/* 0B70C4 800B64C4 1612FFF7 */  bne   $s0, $s2, .L800B64A4
/* 0B70C8 800B64C8 26310001 */   addiu $s1, $s1, 1
.L800B64CC:
/* 0B70CC 800B64CC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0B70D0 800B64D0 02601025 */  move  $v0, $s3
/* 0B70D4 800B64D4 8FB30020 */  lw    $s3, 0x20($sp)
/* 0B70D8 800B64D8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0B70DC 800B64DC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0B70E0 800B64E0 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0B70E4 800B64E4 03E00008 */  jr    $ra
/* 0B70E8 800B64E8 27BD0028 */   addiu $sp, $sp, 0x28
