glabel func_800628C0
/* 0634C0 800628C0 00077600 */  sll   $t6, $a3, 0x18
/* 0634C4 800628C4 000E7E03 */  sra   $t7, $t6, 0x18
/* 0634C8 800628C8 000FC0C0 */  sll   $t8, $t7, 3
/* 0634CC 800628CC 030FC021 */  addu  $t8, $t8, $t7
/* 0634D0 800628D0 0018C0C0 */  sll   $t8, $t8, 3
/* 0634D4 800628D4 AFA50004 */  sw    $a1, 4($sp)
/* 0634D8 800628D8 AFA60008 */  sw    $a2, 8($sp)
/* 0634DC 800628DC AFA7000C */  sw    $a3, 0xc($sp)
/* 0634E0 800628E0 00981021 */  addu  $v0, $a0, $t8
/* 0634E4 800628E4 24190001 */  li    $t9, 1
/* 0634E8 800628E8 A4590814 */  sh    $t9, 0x814($v0)
/* 0634EC 800628EC 8488002E */  lh    $t0, 0x2e($a0)
/* 0634F0 800628F0 240A0002 */  li    $t2, 2
/* 0634F4 800628F4 A44A080A */  sh    $t2, 0x80a($v0)
/* 0634F8 800628F8 00084823 */  negu  $t1, $t0
/* 0634FC 800628FC A4490818 */  sh    $t1, 0x818($v0)
/* 063500 80062900 A4400816 */  sh    $zero, 0x816($v0)
/* 063504 80062904 3C01800F */  lui   $at, %hi(D_800EE5FC) # $at, 0x800f
/* 063508 80062908 C424E5FC */  lwc1  $f4, %lo(D_800EE5FC)($at)
/* 06350C 8006290C 03E00008 */  jr    $ra
/* 063510 80062910 E4440804 */   swc1  $f4, 0x804($v0)
