glabel func_80041A78
/* 042678 80041A78 44801000 */  mtc1  $zero, $f2
/* 04267C 80041A7C 44852000 */  mtc1  $a1, $f4
/* 042680 80041A80 44864000 */  mtc1  $a2, $f8
/* 042684 80041A84 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 042688 80041A88 468021A0 */  cvt.s.w $f6, $f4
/* 04268C 80041A8C 44810000 */  mtc1  $at, $f0
/* 042690 80041A90 E4820010 */  swc1  $f2, 0x10($a0)
/* 042694 80041A94 E4820020 */  swc1  $f2, 0x20($a0)
/* 042698 80041A98 E4820004 */  swc1  $f2, 4($a0)
/* 04269C 80041A9C 468042A0 */  cvt.s.w $f10, $f8
/* 0426A0 80041AA0 E4860030 */  swc1  $f6, 0x30($a0)
/* 0426A4 80041AA4 E4820024 */  swc1  $f2, 0x24($a0)
/* 0426A8 80041AA8 E4820008 */  swc1  $f2, 8($a0)
/* 0426AC 80041AAC E4820018 */  swc1  $f2, 0x18($a0)
/* 0426B0 80041AB0 E4820038 */  swc1  $f2, 0x38($a0)
/* 0426B4 80041AB4 E48A0034 */  swc1  $f10, 0x34($a0)
/* 0426B8 80041AB8 E482000C */  swc1  $f2, 0xc($a0)
/* 0426BC 80041ABC E482001C */  swc1  $f2, 0x1c($a0)
/* 0426C0 80041AC0 E482002C */  swc1  $f2, 0x2c($a0)
/* 0426C4 80041AC4 E4800000 */  swc1  $f0, ($a0)
/* 0426C8 80041AC8 E4800014 */  swc1  $f0, 0x14($a0)
/* 0426CC 80041ACC E4800028 */  swc1  $f0, 0x28($a0)
/* 0426D0 80041AD0 03E00008 */  jr    $ra
/* 0426D4 80041AD4 E480003C */   swc1  $f0, 0x3c($a0)
