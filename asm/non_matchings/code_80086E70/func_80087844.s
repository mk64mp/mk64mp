glabel func_80087844
/* 088444 80087844 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 088448 80087848 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08844C 8008784C 0C021D5F */  jal   func_8008757C
/* 088450 80087850 AFA40018 */   sw    $a0, 0x18($sp)
/* 088454 80087854 0C021DC4 */  jal   func_80087710
/* 088458 80087858 8FA40018 */   lw    $a0, 0x18($sp)
/* 08845C 8008785C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 088460 80087860 27BD0018 */  addiu $sp, $sp, 0x18
/* 088464 80087864 03E00008 */  jr    $ra
/* 088468 80087868 00000000 */   nop   

/* 08846C 8008786C AFA60008 */  sw    $a2, 8($sp)
/* 088470 80087870 AFA7000C */  sw    $a3, 0xc($sp)
/* 088474 80087874 C7AA000C */  lwc1  $f10, 0xc($sp)
/* 088478 80087878 C7A60008 */  lwc1  $f6, 8($sp)
/* 08847C 8008787C C7A40010 */  lwc1  $f4, 0x10($sp)
/* 088480 80087880 460E5401 */  sub.s $f16, $f10, $f14
/* 088484 80087884 46062201 */  sub.s $f8, $f4, $f6
/* 088488 80087888 460E6101 */  sub.s $f4, $f12, $f14
/* 08848C 8008788C 46104483 */  div.s $f18, $f8, $f16
/* 088490 80087890 46049282 */  mul.s $f10, $f18, $f4
/* 088494 80087894 03E00008 */  jr    $ra
/* 088498 80087898 46065000 */   add.s $f0, $f10, $f6
