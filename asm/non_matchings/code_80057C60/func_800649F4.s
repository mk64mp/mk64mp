glabel func_800649F4
/* 0655F4 800649F4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0655F8 800649F8 00057400 */  sll   $t6, $a1, 0x10
/* 0655FC 800649FC 000E7C03 */  sra   $t7, $t6, 0x10
/* 065600 80064A00 000FC8C0 */  sll   $t9, $t7, 3
/* 065604 80064A04 032FC821 */  addu  $t9, $t9, $t7
/* 065608 80064A08 0019C8C0 */  sll   $t9, $t9, 3
/* 06560C 80064A0C AFBF0014 */  sw    $ra, 0x14($sp)
/* 065610 80064A10 AFA40028 */  sw    $a0, 0x28($sp)
/* 065614 80064A14 AFA5002C */  sw    $a1, 0x2c($sp)
/* 065618 80064A18 AFA60030 */  sw    $a2, 0x30($sp)
/* 06561C 80064A1C AFA70034 */  sw    $a3, 0x34($sp)
/* 065620 80064A20 00991021 */  addu  $v0, $a0, $t9
/* 065624 80064A24 C4440AE0 */  lwc1  $f4, 0xae0($v0)
/* 065628 80064A28 E7A40024 */  swc1  $f4, 0x24($sp)
/* 06562C 80064A2C 94440AE8 */  lhu   $a0, 0xae8($v0)
/* 065630 80064A30 0C0AE00E */  jal   func_802B8038
/* 065634 80064A34 AFA20020 */   sw    $v0, 0x20($sp)
/* 065638 80064A38 8FA20020 */  lw    $v0, 0x20($sp)
/* 06563C 80064A3C C7A20024 */  lwc1  $f2, 0x24($sp)
/* 065640 80064A40 8FA90028 */  lw    $t1, 0x28($sp)
/* 065644 80064A44 84480AE6 */  lh    $t0, 0xae6($v0)
/* 065648 80064A48 46001087 */  neg.s $f2, $f2
/* 06564C 80064A4C C532021C */  lwc1  $f18, 0x21c($t1)
/* 065650 80064A50 44883000 */  mtc1  $t0, $f6
/* 065654 80064A54 94440AE8 */  lhu   $a0, 0xae8($v0)
/* 065658 80064A58 46803220 */  cvt.s.w $f8, $f6
/* 06565C 80064A5C 46081282 */  mul.s $f10, $f2, $f8
/* 065660 80064A60 00000000 */  nop   
/* 065664 80064A64 460A0402 */  mul.s $f16, $f0, $f10
/* 065668 80064A68 46128100 */  add.s $f4, $f16, $f18
/* 06566C 80064A6C E4440AD0 */  swc1  $f4, 0xad0($v0)
/* 065670 80064A70 0C0AE006 */  jal   func_802B8018
/* 065674 80064A74 E7A2001C */   swc1  $f2, 0x1c($sp)
/* 065678 80064A78 8FA20020 */  lw    $v0, 0x20($sp)
/* 06567C 80064A7C C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 065680 80064A80 8FA40028 */  lw    $a0, 0x28($sp)
/* 065684 80064A84 84430AE6 */  lh    $v1, 0xae6($v0)
/* 065688 80064A88 3C01800F */  lui   $at, %hi(D_800EE738)
/* 06568C 80064A8C C4920218 */  lwc1  $f18, 0x218($a0)
/* 065690 80064A90 44833000 */  mtc1  $v1, $f6
/* 065694 80064A94 246A0001 */  addiu $t2, $v1, 1
/* 065698 80064A98 46803220 */  cvt.s.w $f8, $f6
/* 06569C 80064A9C C4460ADC */  lwc1  $f6, 0xadc($v0)
/* 0656A0 80064AA0 46081282 */  mul.s $f10, $f2, $f8
/* 0656A4 80064AA4 00000000 */  nop   
/* 0656A8 80064AA8 460A0402 */  mul.s $f16, $f0, $f10
/* 0656AC 80064AAC 46128100 */  add.s $f4, $f16, $f18
/* 0656B0 80064AB0 C4500AD4 */  lwc1  $f16, 0xad4($v0)
/* 0656B4 80064AB4 E4440AC8 */  swc1  $f4, 0xac8($v0)
/* 0656B8 80064AB8 C4880018 */  lwc1  $f8, 0x18($a0)
/* 0656BC 80064ABC 460084A1 */  cvt.d.s $f18, $f16
/* 0656C0 80064AC0 46083280 */  add.s $f10, $f6, $f8
/* 0656C4 80064AC4 E44A0ACC */  swc1  $f10, 0xacc($v0)
/* 0656C8 80064AC8 D424E738 */  ldc1  $f4, %lo(D_800EE738)($at)
/* 0656CC 80064ACC A44A0AE6 */  sh    $t2, 0xae6($v0)
/* 0656D0 80064AD0 84430AE6 */  lh    $v1, 0xae6($v0)
/* 0656D4 80064AD4 46249180 */  add.d $f6, $f18, $f4
/* 0656D8 80064AD8 2401000C */  li    $at, 12
/* 0656DC 80064ADC 46203220 */  cvt.s.d $f8, $f6
/* 0656E0 80064AE0 14610005 */  bne   $v1, $at, .L80064AF8
/* 0656E4 80064AE4 E4480AD4 */   swc1  $f8, 0xad4($v0)
/* 0656E8 80064AE8 A4400AE6 */  sh    $zero, 0xae6($v0)
/* 0656EC 80064AEC A4400AE4 */  sh    $zero, 0xae4($v0)
/* 0656F0 80064AF0 84430AE6 */  lh    $v1, 0xae6($v0)
/* 0656F4 80064AF4 A4400ADA */  sh    $zero, 0xada($v0)
.L80064AF8:
/* 0656F8 80064AF8 28610009 */  slti  $at, $v1, 9
/* 0656FC 80064AFC 54200009 */  bnel  $at, $zero, .L80064B24
/* 065700 80064B00 8FBF0014 */   lw    $ra, 0x14($sp)
/* 065704 80064B04 844B0B06 */  lh    $t3, 0xb06($v0)
/* 065708 80064B08 256CFFF0 */  addiu $t4, $t3, -0x10
/* 06570C 80064B0C A44C0B06 */  sh    $t4, 0xb06($v0)
/* 065710 80064B10 844D0B06 */  lh    $t5, 0xb06($v0)
/* 065714 80064B14 5DA00003 */  bgtzl $t5, .L80064B24
/* 065718 80064B18 8FBF0014 */   lw    $ra, 0x14($sp)
/* 06571C 80064B1C A4400B06 */  sh    $zero, 0xb06($v0)
/* 065720 80064B20 8FBF0014 */  lw    $ra, 0x14($sp)
.L80064B24:
/* 065724 80064B24 27BD0028 */  addiu $sp, $sp, 0x28
/* 065728 80064B28 03E00008 */  jr    $ra
/* 06572C 80064B2C 00000000 */   nop   
