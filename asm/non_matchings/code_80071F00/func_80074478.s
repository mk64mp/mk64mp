glabel func_80074478
/* 075078 80074478 000470C0 */  sll   $t6, $a0, 3
/* 07507C 8007447C 01C47023 */  subu  $t6, $t6, $a0
/* 075080 80074480 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 075084 80074484 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 075088 80074488 000E7140 */  sll   $t6, $t6, 5
/* 07508C 8007448C 01CF1021 */  addu  $v0, $t6, $t7
/* 075090 80074490 8C580054 */  lw    $t8, 0x54($v0)
/* 075094 80074494 37190001 */  ori   $t9, $t8, 1
/* 075098 80074498 03E00008 */  jr    $ra
/* 07509C 8007449C AC590054 */   sw    $t9, 0x54($v0)
