glabel func_800797AC
/* 07A3AC 800797AC 000478C0 */  sll   $t7, $a0, 3
/* 07A3B0 800797B0 01E47823 */  subu  $t7, $t7, $a0
/* 07A3B4 800797B4 000F7900 */  sll   $t7, $t7, 4
/* 07A3B8 800797B8 01E47823 */  subu  $t7, $t7, $a0
/* 07A3BC 800797BC 3C19800E */  lui   $t9, %hi(gCurrentCourseId) # $t9, 0x800e
/* 07A3C0 800797C0 8739C5A0 */  lh    $t9, %lo(gCurrentCourseId)($t9)
/* 07A3C4 800797C4 000F7880 */  sll   $t7, $t7, 2
/* 07A3C8 800797C8 3C18800E */  lui   $t8, %hi(D_800DC4DC) # $t8, 0x800e
/* 07A3CC 800797CC 8F18C4DC */  lw    $t8, %lo(D_800DC4DC)($t8)
/* 07A3D0 800797D0 00047080 */  sll   $t6, $a0, 2
/* 07A3D4 800797D4 3C068018 */  lui   $a2, %hi(D_80183DB8) # 0x8018
/* 07A3D8 800797D8 01E47823 */  subu  $t7, $t7, $a0
/* 07A3DC 800797DC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 07A3E0 800797E0 00CE3021 */  addu  $a2, $a2, $t6
/* 07A3E4 800797E4 000F78C0 */  sll   $t7, $t7, 3
/* 07A3E8 800797E8 2401000C */  li    $at, 12
/* 07A3EC 800797EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 07A3F0 800797F0 8CC63DB8 */  lw    $a2, %lo(D_80183DB8)($a2) # 0x3db8($a2)
/* 07A3F4 800797F4 1721000F */  bne   $t9, $at, .L80079834
/* 07A3F8 800797F8 01F81021 */   addu  $v0, $t7, $t8
/* 07A3FC 800797FC 844800CA */  lh    $t0, 0xca($v0)
/* 07A400 80079800 00C02025 */  move  $a0, $a2
/* 07A404 80079804 24050007 */  li    $a1, 7
/* 07A408 80079808 31090001 */  andi  $t1, $t0, 1
/* 07A40C 8007980C 5120000A */  beql  $t1, $zero, .L80079838
/* 07A410 80079810 00C02025 */   move  $a0, $a2
/* 07A414 80079814 AFA20018 */  sw    $v0, 0x18($sp)
/* 07A418 80079818 0C01C8E9 */  jal   func_800723A4
/* 07A41C 8007981C AFA6001C */   sw    $a2, 0x1c($sp)
/* 07A420 80079820 8FA20018 */  lw    $v0, 0x18($sp)
/* 07A424 80079824 844A00CA */  lh    $t2, 0xca($v0)
/* 07A428 80079828 354B0010 */  ori   $t3, $t2, 0x10
/* 07A42C 8007982C 10000005 */  b     .L80079844
/* 07A430 80079830 A44B00CA */   sh    $t3, 0xca($v0)
.L80079834:
/* 07A434 80079834 00C02025 */  move  $a0, $a2
.L80079838:
/* 07A438 80079838 24050003 */  li    $a1, 3
/* 07A43C 8007983C 0C01C8E9 */  jal   func_800723A4
/* 07A440 80079840 AFA6001C */   sw    $a2, 0x1c($sp)
.L80079844:
/* 07A444 80079844 8FA4001C */  lw    $a0, 0x1c($sp)
/* 07A448 80079848 0C01C8A9 */  jal   func_800722A4
/* 07A44C 8007984C 24050001 */   li    $a1, 1
/* 07A450 80079850 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07A454 80079854 27BD0020 */  addiu $sp, $sp, 0x20
/* 07A458 80079858 03E00008 */  jr    $ra
/* 07A45C 8007985C 00000000 */   nop   
