glabel func_8007993C
/* 07A53C 8007993C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07A540 80079940 AFBF0014 */  sw    $ra, 0x14($sp)
/* 07A544 80079944 84AE00CA */  lh    $t6, 0xca($a1)
/* 07A548 80079948 00A03025 */  move  $a2, $a1
/* 07A54C 8007994C 24050002 */  li    $a1, 2
/* 07A550 80079950 31CF0004 */  andi  $t7, $t6, 4
/* 07A554 80079954 11E0000E */  beqz  $t7, .L80079990
/* 07A558 80079958 00000000 */   nop   
/* 07A55C 8007995C AFA40018 */  sw    $a0, 0x18($sp)
/* 07A560 80079960 0C01C8A9 */  jal   func_800722A4
/* 07A564 80079964 AFA6001C */   sw    $a2, 0x1c($sp)
/* 07A568 80079968 8FA40018 */  lw    $a0, 0x18($sp)
/* 07A56C 8007996C 8FA6001C */  lw    $a2, 0x1c($sp)
/* 07A570 80079970 3C018016 */  lui   $at, %hi(D_80165CB8) # 0x8016
/* 07A574 80079974 0004C8C0 */  sll   $t9, $a0, 3
/* 07A578 80079978 0324C823 */  subu  $t9, $t9, $a0
/* 07A57C 8007997C 84D800C6 */  lh    $t8, 0xc6($a2)
/* 07A580 80079980 0019C940 */  sll   $t9, $t9, 5
/* 07A584 80079984 00390821 */  addu  $at, $at, $t9
/* 07A588 80079988 10000003 */  b     .L80079998
/* 07A58C 8007998C A4385CB8 */   sh    $t8, %lo(D_80165CB8)($at) # 0x5cb8($at)
.L80079990:
/* 07A590 80079990 0C01C8B3 */  jal   func_800722CC
/* 07A594 80079994 24050002 */   li    $a1, 2
.L80079998:
/* 07A598 80079998 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07A59C 8007999C 27BD0018 */  addiu $sp, $sp, 0x18
/* 07A5A0 800799A0 03E00008 */  jr    $ra
/* 07A5A4 800799A4 00000000 */   nop   
