glabel func_802B7F7C
/* 12158C 802B7F7C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 121590 802B7F80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 121594 802B7F84 AFA60038 */  sw    $a2, 0x38($sp)
/* 121598 802B7F88 C4840004 */  lwc1  $f4, 4($a0)
/* 12159C 802B7F8C C48E0000 */  lwc1  $f14, ($a0)
/* 1215A0 802B7F90 E7A40028 */  swc1  $f4, 0x28($sp)
/* 1215A4 802B7F94 C4A60004 */  lwc1  $f6, 4($a1)
/* 1215A8 802B7F98 C48C0008 */  lwc1  $f12, 8($a0)
/* 1215AC 802B7F9C C4A20000 */  lwc1  $f2, ($a1)
/* 1215B0 802B7FA0 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 1215B4 802B7FA4 C4A00008 */  lwc1  $f0, 8($a1)
/* 1215B8 802B7FA8 44071000 */  mfc1  $a3, $f2
/* 1215BC 802B7FAC E7AE002C */  swc1  $f14, 0x2c($sp)
/* 1215C0 802B7FB0 44060000 */  mfc1  $a2, $f0
/* 1215C4 802B7FB4 E7AC0024 */  swc1  $f12, 0x24($sp)
/* 1215C8 802B7FB8 E7A20020 */  swc1  $f2, 0x20($sp)
/* 1215CC 802B7FBC 0C0ADFCD */  jal   func_802B7F34
/* 1215D0 802B7FC0 E7A00018 */   swc1  $f0, 0x18($sp)
/* 1215D4 802B7FC4 8FAE0038 */  lw    $t6, 0x38($sp)
/* 1215D8 802B7FC8 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 1215DC 802B7FCC A5C20002 */  sh    $v0, 2($t6)
/* 1215E0 802B7FD0 44070000 */  mfc1  $a3, $f0
/* 1215E4 802B7FD4 8FA6001C */  lw    $a2, 0x1c($sp)
/* 1215E8 802B7FD8 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 1215EC 802B7FDC 0C0ADFCD */  jal   func_802B7F34
/* 1215F0 802B7FE0 C7AC0028 */   lwc1  $f12, 0x28($sp)
/* 1215F4 802B7FE4 8FAF0038 */  lw    $t7, 0x38($sp)
/* 1215F8 802B7FE8 A5E20000 */  sh    $v0, ($t7)
/* 1215FC 802B7FEC 8FA7001C */  lw    $a3, 0x1c($sp)
/* 121600 802B7FF0 8FA60020 */  lw    $a2, 0x20($sp)
/* 121604 802B7FF4 C7AE0028 */  lwc1  $f14, 0x28($sp)
/* 121608 802B7FF8 0C0ADFCD */  jal   func_802B7F34
/* 12160C 802B7FFC C7AC002C */   lwc1  $f12, 0x2c($sp)
/* 121610 802B8000 8FB80038 */  lw    $t8, 0x38($sp)
/* 121614 802B8004 A7020004 */  sh    $v0, 4($t8)
/* 121618 802B8008 8FBF0014 */  lw    $ra, 0x14($sp)
/* 12161C 802B800C 27BD0030 */  addiu $sp, $sp, 0x30
/* 121620 802B8010 03E00008 */  jr    $ra
/* 121624 802B8014 00000000 */   nop   
