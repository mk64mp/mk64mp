glabel func_8008D170
/* 08DD70 8008D170 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 08DD74 8008D174 AFBF001C */  sw    $ra, 0x1c($sp)
/* 08DD78 8008D178 AFB00018 */  sw    $s0, 0x18($sp)
/* 08DD7C 8008D17C AFA50034 */  sw    $a1, 0x34($sp)
/* 08DD80 8008D180 848300B4 */  lh    $v1, 0xb4($a0)
/* 08DD84 8008D184 3C01800F */  lui   $at, %hi(D_800EF550)
/* 08DD88 8008D188 D424F550 */  ldc1  $f4, %lo(D_800EF550)($at)
/* 08DD8C 8008D18C 24630001 */  addiu $v1, $v1, 1
/* 08DD90 8008D190 00037400 */  sll   $t6, $v1, 0x10
/* 08DD94 8008D194 000E1C03 */  sra   $v1, $t6, 0x10
/* 08DD98 8008D198 00630019 */  multu $v1, $v1
/* 08DD9C 8008D19C 44838000 */  mtc1  $v1, $f16
/* 08DDA0 8008D1A0 C48000B8 */  lwc1  $f0, 0xb8($a0)
/* 08DDA4 8008D1A4 00808025 */  move  $s0, $a0
/* 08DDA8 8008D1A8 468084A0 */  cvt.s.w $f18, $f16
/* 08DDAC 8008D1AC 848700AC */  lh    $a3, 0xac($a0)
/* 08DDB0 8008D1B0 0000C012 */  mflo  $t8
/* 08DDB4 8008D1B4 44983000 */  mtc1  $t8, $f6
/* 08DDB8 8008D1B8 00000000 */  nop   
/* 08DDBC 8008D1BC 46803221 */  cvt.d.w $f8, $f6
/* 08DDC0 8008D1C0 46282282 */  mul.d $f10, $f4, $f8
/* 08DDC4 8008D1C4 00000000 */  nop   
/* 08DDC8 8008D1C8 46009182 */  mul.s $f6, $f18, $f0
/* 08DDCC 8008D1CC 46003121 */  cvt.d.s $f4, $f6
/* 08DDD0 8008D1D0 462A2201 */  sub.d $f8, $f4, $f10
/* 08DDD4 8008D1D4 4620440D */  trunc.w.d $f16, $f8
/* 08DDD8 8008D1D8 44028000 */  mfc1  $v0, $f16
/* 08DDDC 8008D1DC 00000000 */  nop   
/* 08DDE0 8008D1E0 00023400 */  sll   $a2, $v0, 0x10
/* 08DDE4 8008D1E4 00064403 */  sra   $t0, $a2, 0x10
/* 08DDE8 8008D1E8 1060004B */  beqz  $v1, .L8008D318
/* 08DDEC 8008D1EC 01003025 */   move  $a2, $t0
/* 08DDF0 8008D1F0 00024C00 */  sll   $t1, $v0, 0x10
/* 08DDF4 8008D1F4 00095403 */  sra   $t2, $t1, 0x10
/* 08DDF8 8008D1F8 05410047 */  bgez  $t2, .L8008D318
/* 08DDFC 8008D1FC 3C01800F */   lui   $at, %hi(D_800EF558)
/* 08DE00 8008D200 D426F558 */  ldc1  $f6, %lo(D_800EF558)($at)
/* 08DE04 8008D204 460004A1 */  cvt.d.s $f18, $f0
/* 08DE08 8008D208 8C8200BC */  lw    $v0, 0xbc($a0)
/* 08DE0C 8008D20C 46269102 */  mul.d $f4, $f18, $f6
/* 08DE10 8008D210 00073823 */  negu  $a3, $a3
/* 08DE14 8008D214 00075C00 */  sll   $t3, $a3, 0x10
/* 08DE18 8008D218 24010001 */  li    $at, 1
/* 08DE1C 8008D21C 304D0001 */  andi  $t5, $v0, 1
/* 08DE20 8008D220 00001825 */  move  $v1, $zero
/* 08DE24 8008D224 000B3C03 */  sra   $a3, $t3, 0x10
/* 08DE28 8008D228 11A10004 */  beq   $t5, $at, .L8008D23C
/* 08DE2C 8008D22C 46202020 */   cvt.s.d $f0, $f4
/* 08DE30 8008D230 848E0044 */  lh    $t6, 0x44($a0)
/* 08DE34 8008D234 31CF0020 */  andi  $t7, $t6, 0x20
/* 08DE38 8008D238 15E00003 */  bnez  $t7, .L8008D248
.L8008D23C:
/* 08DE3C 8008D23C 3C040004 */   lui   $a0, 4
/* 08DE40 8008D240 0044C025 */  or    $t8, $v0, $a0
/* 08DE44 8008D244 AE1800BC */  sw    $t8, 0xbc($s0)
.L8008D248:
/* 08DE48 8008D248 3C01800F */  lui   $at, %hi(D_800EF560)
/* 08DE4C 8008D24C D42AF560 */  ldc1  $f10, %lo(D_800EF560)($at)
/* 08DE50 8008D250 46000221 */  cvt.d.s $f8, $f0
/* 08DE54 8008D254 3C040004 */  lui   $a0, 4
/* 08DE58 8008D258 462A403E */  c.le.d $f8, $f10
/* 08DE5C 8008D25C 00000000 */  nop   
/* 08DE60 8008D260 4500002D */  bc1f  .L8008D318
/* 08DE64 8008D264 00000000 */   nop   
/* 08DE68 8008D268 86190044 */  lh    $t9, 0x44($s0)
/* 08DE6C 8008D26C 8E0200BC */  lw    $v0, 0xbc($s0)
/* 08DE70 8008D270 3C01FFFB */  lui   $at, (0xFFFBFFFF >> 16) # lui $at, 0xfffb
/* 08DE74 8008D274 3328BFFF */  andi  $t0, $t9, 0xbfff
/* 08DE78 8008D278 00444824 */  and   $t1, $v0, $a0
/* 08DE7C 8008D27C 1089000D */  beq   $a0, $t1, .L8008D2B4
/* 08DE80 8008D280 A6080044 */   sh    $t0, 0x44($s0)
/* 08DE84 8008D284 02002025 */  move  $a0, $s0
/* 08DE88 8008D288 83A50037 */  lb    $a1, 0x37($sp)
/* 08DE8C 8008D28C A7A3002A */  sh    $v1, 0x2a($sp)
/* 08DE90 8008D290 A7A60026 */  sh    $a2, 0x26($sp)
/* 08DE94 8008D294 A7A70028 */  sh    $a3, 0x28($sp)
/* 08DE98 8008D298 0C0231CF */  jal   func_8008C73C
/* 08DE9C 8008D29C E7A0002C */   swc1  $f0, 0x2c($sp)
/* 08DEA0 8008D2A0 87A3002A */  lh    $v1, 0x2a($sp)
/* 08DEA4 8008D2A4 87A60026 */  lh    $a2, 0x26($sp)
/* 08DEA8 8008D2A8 87A70028 */  lh    $a3, 0x28($sp)
/* 08DEAC 8008D2AC 1000001A */  b     .L8008D318
/* 08DEB0 8008D2B0 C7A0002C */   lwc1  $f0, 0x2c($sp)
.L8008D2B4:
/* 08DEB4 8008D2B4 960A00B6 */  lhu   $t2, 0xb6($s0)
/* 08DEB8 8008D2B8 960D0000 */  lhu   $t5, ($s0)
/* 08DEBC 8008D2BC 3421FFFF */  ori   $at, (0xFFFBFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 08DEC0 8008D2C0 00416024 */  and   $t4, $v0, $at
/* 08DEC4 8008D2C4 24014000 */  li    $at, 16384
/* 08DEC8 8008D2C8 354B0020 */  ori   $t3, $t2, 0x20
/* 08DECC 8008D2CC 31AE4000 */  andi  $t6, $t5, 0x4000
/* 08DED0 8008D2D0 A60B00B6 */  sh    $t3, 0xb6($s0)
/* 08DED4 8008D2D4 15C10010 */  bne   $t6, $at, .L8008D318
/* 08DED8 8008D2D8 AE0C00BC */   sw    $t4, 0xbc($s0)
/* 08DEDC 8008D2DC 96050254 */  lhu   $a1, 0x254($s0)
/* 08DEE0 8008D2E0 3C012900 */  lui   $at, (0x29008008 >> 16) # lui $at, 0x2900
/* 08DEE4 8008D2E4 34218008 */  ori   $at, (0x29008008 & 0xFFFF) # ori $at, $at, 0x8008
/* 08DEE8 8008D2E8 00057900 */  sll   $t7, $a1, 4
/* 08DEEC 8008D2EC 01E12821 */  addu  $a1, $t7, $at
/* 08DEF0 8008D2F0 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 08DEF4 8008D2F4 A7A70028 */  sh    $a3, 0x28($sp)
/* 08DEF8 8008D2F8 A7A60026 */  sh    $a2, 0x26($sp)
/* 08DEFC 8008D2FC A7A3002A */  sh    $v1, 0x2a($sp)
/* 08DF00 8008D300 0C03243D */  jal   func_800C90F4
/* 08DF04 8008D304 93A40037 */   lbu   $a0, 0x37($sp)
/* 08DF08 8008D308 87A3002A */  lh    $v1, 0x2a($sp)
/* 08DF0C 8008D30C 87A60026 */  lh    $a2, 0x26($sp)
/* 08DF10 8008D310 87A70028 */  lh    $a3, 0x28($sp)
/* 08DF14 8008D314 C7A0002C */  lwc1  $f0, 0x2c($sp)
.L8008D318:
/* 08DF18 8008D318 00C70019 */  multu $a2, $a3
/* 08DF1C 8008D31C 8E0200BC */  lw    $v0, 0xbc($s0)
/* 08DF20 8008D320 24010001 */  li    $at, 1
/* 08DF24 8008D324 02002025 */  move  $a0, $s0
/* 08DF28 8008D328 304B0008 */  andi  $t3, $v0, 8
/* 08DF2C 8008D32C 00003012 */  mflo  $a2
/* 08DF30 8008D330 0006C400 */  sll   $t8, $a2, 0x10
/* 08DF34 8008D334 00183403 */  sra   $a2, $t8, 0x10
/* 08DF38 8008D338 1CC00004 */  bgtz  $a2, .L8008D34C
/* 08DF3C 8008D33C 00000000 */   nop   
/* 08DF40 8008D340 14E10002 */  bne   $a3, $at, .L8008D34C
/* 08DF44 8008D344 00000000 */   nop   
/* 08DF48 8008D348 00003025 */  move  $a2, $zero
.L8008D34C:
/* 08DF4C 8008D34C 04C00004 */  bltz  $a2, .L8008D360
/* 08DF50 8008D350 2401FFFF */   li    $at, -1
/* 08DF54 8008D354 54E10003 */  bnel  $a3, $at, .L8008D364
/* 08DF58 8008D358 86080078 */   lh    $t0, 0x78($s0)
/* 08DF5C 8008D35C 00003025 */  move  $a2, $zero
.L8008D360:
/* 08DF60 8008D360 86080078 */  lh    $t0, 0x78($s0)
.L8008D364:
/* 08DF64 8008D364 00064880 */  sll   $t1, $a2, 2
/* 08DF68 8008D368 01264821 */  addu  $t1, $t1, $a2
/* 08DF6C 8008D36C 00094880 */  sll   $t1, $t1, 2
/* 08DF70 8008D370 01095021 */  addu  $t2, $t0, $t1
/* 08DF74 8008D374 A60A0078 */  sh    $t2, 0x78($s0)
/* 08DF78 8008D378 E60000B8 */  swc1  $f0, 0xb8($s0)
/* 08DF7C 8008D37C A60300B4 */  sh    $v1, 0xb4($s0)
/* 08DF80 8008D380 11600006 */  beqz  $t3, .L8008D39C
/* 08DF84 8008D384 A60700AC */   sh    $a3, 0xac($s0)
/* 08DF88 8008D388 0C0231CF */  jal   func_8008C73C
/* 08DF8C 8008D38C 83A50037 */   lb    $a1, 0x37($sp)
/* 08DF90 8008D390 860C0044 */  lh    $t4, 0x44($s0)
/* 08DF94 8008D394 318DBFFF */  andi  $t5, $t4, 0xbfff
/* 08DF98 8008D398 A60D0044 */  sh    $t5, 0x44($s0)
.L8008D39C:
/* 08DF9C 8008D39C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 08DFA0 8008D3A0 8FB00018 */  lw    $s0, 0x18($sp)
/* 08DFA4 8008D3A4 27BD0030 */  addiu $sp, $sp, 0x30
/* 08DFA8 8008D3A8 03E00008 */  jr    $ra
/* 08DFAC 8008D3AC 00000000 */   nop   
