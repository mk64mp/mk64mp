glabel func_8005995C
/* 05A55C 8005995C 3C02800E */  lui   $v0, %hi(D_800DC4DC) # $v0, 0x800e
/* 05A560 80059960 3C078019 */  lui   $a3, %hi(D_8018CA70) # $a3, 0x8019
/* 05A564 80059964 3C058016 */  lui   $a1, %hi(D_80165890) # $a1, 0x8016
/* 05A568 80059968 8C42C4DC */  lw    $v0, %lo(D_800DC4DC)($v0)
/* 05A56C 8005996C 24A55890 */  addiu $a1, %lo(D_80165890) # addiu $a1, $a1, 0x5890
/* 05A570 80059970 24E7CA70 */  addiu $a3, %lo(D_8018CA70) # addiu $a3, $a3, -0x3590
/* 05A574 80059974 00001825 */  move  $v1, $zero
/* 05A578 80059978 240A0004 */  li    $t2, 4
/* 05A57C 8005997C 24090002 */  li    $t1, 2
/* 05A580 80059980 24080084 */  li    $t0, 132
/* 05A584 80059984 2406000C */  li    $a2, 12
.L80059988:
/* 05A588 80059988 80AE0000 */  lb    $t6, ($a1)
/* 05A58C 8005998C 51C0000B */  beql  $t6, $zero, .L800599BC
/* 05A590 80059990 944C0000 */   lhu   $t4, ($v0)
/* 05A594 80059994 944F0000 */  lhu   $t7, ($v0)
/* 05A598 80059998 31F80100 */  andi  $t8, $t7, 0x100
/* 05A59C 8005999C 53000007 */  beql  $t8, $zero, .L800599BC
/* 05A5A0 800599A0 944C0000 */   lhu   $t4, ($v0)
/* 05A5A4 800599A4 00680019 */  multu $v1, $t0
/* 05A5A8 800599A8 A4460010 */  sh    $a2, 0x10($v0)
/* 05A5AC 800599AC 0000C812 */  mflo  $t9
/* 05A5B0 800599B0 00F95821 */  addu  $t3, $a3, $t9
/* 05A5B4 800599B4 A1690075 */  sb    $t1, 0x75($t3)
/* 05A5B8 800599B8 944C0000 */  lhu   $t4, ($v0)
.L800599BC:
/* 05A5BC 800599BC 318D0100 */  andi  $t5, $t4, 0x100
/* 05A5C0 800599C0 51A0000F */  beql  $t5, $zero, .L80059A00
/* 05A5C4 800599C4 80AC0000 */   lb    $t4, ($a1)
/* 05A5C8 800599C8 844E0010 */  lh    $t6, 0x10($v0)
/* 05A5CC 800599CC 55C0000C */  bnel  $t6, $zero, .L80059A00
/* 05A5D0 800599D0 80AC0000 */   lb    $t4, ($a1)
/* 05A5D4 800599D4 00680019 */  multu $v1, $t0
/* 05A5D8 800599D8 00007812 */  mflo  $t7
/* 05A5DC 800599DC 00EF2021 */  addu  $a0, $a3, $t7
/* 05A5E0 800599E0 80980075 */  lb    $t8, 0x75($a0)
/* 05A5E4 800599E4 53000006 */  beql  $t8, $zero, .L80059A00
/* 05A5E8 800599E8 80AC0000 */   lb    $t4, ($a1)
/* 05A5EC 800599EC A4460010 */  sh    $a2, 0x10($v0)
/* 05A5F0 800599F0 80990075 */  lb    $t9, 0x75($a0)
/* 05A5F4 800599F4 272BFFFF */  addiu $t3, $t9, -1
/* 05A5F8 800599F8 A08B0075 */  sb    $t3, 0x75($a0)
/* 05A5FC 800599FC 80AC0000 */  lb    $t4, ($a1)
.L80059A00:
/* 05A600 80059A00 24420DD8 */  addiu $v0, $v0, 0xdd8
/* 05A604 80059A04 5180000B */  beql  $t4, $zero, .L80059A34
/* 05A608 80059A08 94590000 */   lhu   $t9, ($v0)
/* 05A60C 80059A0C 944D0000 */  lhu   $t5, ($v0)
/* 05A610 80059A10 31AE0100 */  andi  $t6, $t5, 0x100
/* 05A614 80059A14 51C00007 */  beql  $t6, $zero, .L80059A34
/* 05A618 80059A18 94590000 */   lhu   $t9, ($v0)
/* 05A61C 80059A1C 00680019 */  multu $v1, $t0
/* 05A620 80059A20 A4460010 */  sh    $a2, 0x10($v0)
/* 05A624 80059A24 00007812 */  mflo  $t7
/* 05A628 80059A28 00EFC021 */  addu  $t8, $a3, $t7
/* 05A62C 80059A2C A30900F9 */  sb    $t1, 0xf9($t8)
/* 05A630 80059A30 94590000 */  lhu   $t9, ($v0)
.L80059A34:
/* 05A634 80059A34 332B0100 */  andi  $t3, $t9, 0x100
/* 05A638 80059A38 5160000F */  beql  $t3, $zero, .L80059A78
/* 05A63C 80059A3C 24630002 */   addiu $v1, $v1, 2
/* 05A640 80059A40 844C0010 */  lh    $t4, 0x10($v0)
/* 05A644 80059A44 5580000C */  bnel  $t4, $zero, .L80059A78
/* 05A648 80059A48 24630002 */   addiu $v1, $v1, 2
/* 05A64C 80059A4C 00680019 */  multu $v1, $t0
/* 05A650 80059A50 00006812 */  mflo  $t5
/* 05A654 80059A54 00ED2021 */  addu  $a0, $a3, $t5
/* 05A658 80059A58 808E00F9 */  lb    $t6, 0xf9($a0)
/* 05A65C 80059A5C 51C00006 */  beql  $t6, $zero, .L80059A78
/* 05A660 80059A60 24630002 */   addiu $v1, $v1, 2
/* 05A664 80059A64 A4460010 */  sh    $a2, 0x10($v0)
/* 05A668 80059A68 808F00F9 */  lb    $t7, 0xf9($a0)
/* 05A66C 80059A6C 25F8FFFF */  addiu $t8, $t7, -1
/* 05A670 80059A70 A09800F9 */  sb    $t8, 0xf9($a0)
/* 05A674 80059A74 24630002 */  addiu $v1, $v1, 2
.L80059A78:
/* 05A678 80059A78 146AFFC3 */  bne   $v1, $t2, .L80059988
/* 05A67C 80059A7C 24420DD8 */   addiu $v0, $v0, 0xdd8
/* 05A680 80059A80 03E00008 */  jr    $ra
/* 05A684 80059A84 A0A00000 */   sb    $zero, ($a1)
