glabel func_8005D800
/* 05E400 8005D800 AFA60008 */  sw    $a2, 8($sp)
/* 05E404 8005D804 0005C403 */  sra   $t8, $a1, 0x10
/* 05E408 8005D808 00054203 */  sra   $t0, $a1, 8
/* 05E40C 8005D80C 331900FF */  andi  $t9, $t8, 0xff
/* 05E410 8005D810 310900FF */  andi  $t1, $t0, 0xff
/* 05E414 8005D814 30AA00FF */  andi  $t2, $a1, 0xff
/* 05E418 8005D818 A4990038 */  sh    $t9, 0x38($a0)
/* 05E41C 8005D81C A489003A */  sh    $t1, 0x3a($a0)
/* 05E420 8005D820 A48A003C */  sh    $t2, 0x3c($a0)
/* 05E424 8005D824 03E00008 */  jr    $ra
/* 05E428 8005D828 A486003E */   sh    $a2, 0x3e($a0)
