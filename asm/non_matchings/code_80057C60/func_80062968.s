glabel func_80062968
/* 063568 80062968 00077600 */  sll   $t6, $a3, 0x18
/* 06356C 8006296C 000E7E03 */  sra   $t7, $t6, 0x18
/* 063570 80062970 000FC0C0 */  sll   $t8, $t7, 3
/* 063574 80062974 030FC021 */  addu  $t8, $t8, $t7
/* 063578 80062978 0018C0C0 */  sll   $t8, $t8, 3
/* 06357C 8006297C AFA50004 */  sw    $a1, 4($sp)
/* 063580 80062980 AFA60008 */  sw    $a2, 8($sp)
/* 063584 80062984 AFA7000C */  sw    $a3, 0xc($sp)
/* 063588 80062988 00981021 */  addu  $v0, $a0, $t8
/* 06358C 8006298C 24190001 */  li    $t9, 1
/* 063590 80062990 A4590814 */  sh    $t9, 0x814($v0)
/* 063594 80062994 8488002E */  lh    $t0, 0x2e($a0)
/* 063598 80062998 240A0005 */  li    $t2, 5
/* 06359C 8006299C A44A080A */  sh    $t2, 0x80a($v0)
/* 0635A0 800629A0 00084823 */  negu  $t1, $t0
/* 0635A4 800629A4 A4490818 */  sh    $t1, 0x818($v0)
/* 0635A8 800629A8 A4400816 */  sh    $zero, 0x816($v0)
/* 0635AC 800629AC 3C01800F */  lui   $at, %hi(D_800EE600) # $at, 0x800f
/* 0635B0 800629B0 C424E600 */  lwc1  $f4, %lo(D_800EE600)($at)
/* 0635B4 800629B4 03E00008 */  jr    $ra
/* 0635B8 800629B8 E4440804 */   swc1  $f4, 0x804($v0)
