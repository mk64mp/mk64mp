glabel func_80280A28
/* 124068 80280A28 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 12406C 80280A2C 44866000 */  mtc1  $a2, $f12
/* 124070 80280A30 AFA50064 */  sw    $a1, 0x64($sp)
/* 124074 80280A34 00802825 */  move  $a1, $a0
/* 124078 80280A38 AFBF0014 */  sw    $ra, 0x14($sp)
/* 12407C 80280A3C AFA40060 */  sw    $a0, 0x60($sp)
/* 124080 80280A40 8FA60064 */  lw    $a2, 0x64($sp)
/* 124084 80280A44 27A40020 */  addiu $a0, $sp, 0x20
/* 124088 80280A48 0C008784 */  jal   func_80021E10
/* 12408C 80280A4C E7AC0068 */   swc1  $f12, 0x68($sp)
/* 124090 80280A50 3C028028 */  lui   $v0, %hi(D_80287500) # $v0, 0x8028
/* 124094 80280A54 24427500 */  addiu $v0, %lo(D_80287500) # addiu $v0, $v0, 0x7500
/* 124098 80280A58 C7AC0068 */  lwc1  $f12, 0x68($sp)
/* 12409C 80280A5C C4440000 */  lwc1  $f4, ($v0)
/* 1240A0 80280A60 C4480010 */  lwc1  $f8, 0x10($v0)
/* 1240A4 80280A64 C4500020 */  lwc1  $f16, 0x20($v0)
/* 1240A8 80280A68 460C2182 */  mul.s $f6, $f4, $f12
/* 1240AC 80280A6C C4440004 */  lwc1  $f4, 4($v0)
/* 1240B0 80280A70 3C0F8016 */  lui   $t7, %hi(D_80164AF0) # $t7, 0x8016
/* 1240B4 80280A74 460C4282 */  mul.s $f10, $f8, $f12
/* 1240B8 80280A78 C4480014 */  lwc1  $f8, 0x14($v0)
/* 1240BC 80280A7C 85EF4AF0 */  lh    $t7, %lo(D_80164AF0)($t7)
/* 1240C0 80280A80 460C8482 */  mul.s $f18, $f16, $f12
/* 1240C4 80280A84 E7A60020 */  swc1  $f6, 0x20($sp)
/* 1240C8 80280A88 C4500024 */  lwc1  $f16, 0x24($v0)
/* 1240CC 80280A8C 460C2182 */  mul.s $f6, $f4, $f12
/* 1240D0 80280A90 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 1240D4 80280A94 C4440008 */  lwc1  $f4, 8($v0)
/* 1240D8 80280A98 460C4282 */  mul.s $f10, $f8, $f12
/* 1240DC 80280A9C E7B20028 */  swc1  $f18, 0x28($sp)
/* 1240E0 80280AA0 C4480018 */  lwc1  $f8, 0x18($v0)
/* 1240E4 80280AA4 460C8482 */  mul.s $f18, $f16, $f12
/* 1240E8 80280AA8 E7A60030 */  swc1  $f6, 0x30($sp)
/* 1240EC 80280AAC C4500028 */  lwc1  $f16, 0x28($v0)
/* 1240F0 80280AB0 460C2182 */  mul.s $f6, $f4, $f12
/* 1240F4 80280AB4 E7AA0034 */  swc1  $f10, 0x34($sp)
/* 1240F8 80280AB8 3C0E8015 */  lui   $t6, %hi(gGfxPool) # $t6, 0x8015
/* 1240FC 80280ABC 460C4282 */  mul.s $f10, $f8, $f12
/* 124100 80280AC0 E7B20038 */  swc1  $f18, 0x38($sp)
/* 124104 80280AC4 8DCEEF40 */  lw    $t6, %lo(gGfxPool)($t6)
/* 124108 80280AC8 460C8482 */  mul.s $f18, $f16, $f12
/* 12410C 80280ACC 000FC180 */  sll   $t8, $t7, 6
/* 124110 80280AD0 3401FAC0 */  li    $at, 64192
/* 124114 80280AD4 01D82021 */  addu  $a0, $t6, $t8
/* 124118 80280AD8 E7A60040 */  swc1  $f6, 0x40($sp)
/* 12411C 80280ADC E7AA0044 */  swc1  $f10, 0x44($sp)
/* 124120 80280AE0 00812021 */  addu  $a0, $a0, $at
/* 124124 80280AE4 E7B20048 */  swc1  $f18, 0x48($sp)
/* 124128 80280AE8 0C008860 */  jal   func_80022180
/* 12412C 80280AEC 27A50020 */   addiu $a1, $sp, 0x20
/* 124130 80280AF0 3C048015 */  lui   $a0, %hi(gDisplayListHead) # $a0, 0x8015
/* 124134 80280AF4 24840298 */  addiu $a0, %lo(gDisplayListHead) # addiu $a0, $a0, 0x298
/* 124138 80280AF8 8C830000 */  lw    $v1, ($a0)
/* 12413C 80280AFC 3C080102 */  lui   $t0, (0x01020040 >> 16) # lui $t0, 0x102
/* 124140 80280B00 35080040 */  ori   $t0, (0x01020040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 124144 80280B04 24790008 */  addiu $t9, $v1, 8
/* 124148 80280B08 AC990000 */  sw    $t9, ($a0)
/* 12414C 80280B0C 3C0A8016 */  lui   $t2, %hi(D_80164AF0) # $t2, 0x8016
/* 124150 80280B10 AC680000 */  sw    $t0, ($v1)
/* 124154 80280B14 854A4AF0 */  lh    $t2, %lo(D_80164AF0)($t2)
/* 124158 80280B18 3C098015 */  lui   $t1, %hi(gGfxPool) # $t1, 0x8015
/* 12415C 80280B1C 8D29EF40 */  lw    $t1, %lo(gGfxPool)($t1)
/* 124160 80280B20 000A5980 */  sll   $t3, $t2, 6
/* 124164 80280B24 3401FAC0 */  li    $at, 64192
/* 124168 80280B28 012B6021 */  addu  $t4, $t1, $t3
/* 12416C 80280B2C 01816821 */  addu  $t5, $t4, $at
/* 124170 80280B30 3C011FFF */  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
/* 124174 80280B34 3421FFFF */  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 124178 80280B38 01A17824 */  and   $t7, $t5, $at
/* 12417C 80280B3C AC6F0004 */  sw    $t7, 4($v1)
/* 124180 80280B40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 124184 80280B44 27BD0060 */  addiu $sp, $sp, 0x60
/* 124188 80280B48 03E00008 */  jr    $ra
/* 12418C 80280B4C 00000000 */   nop   
