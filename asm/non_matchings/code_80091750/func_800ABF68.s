glabel func_800ABF68
/* 0ACB68 800ABF68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0ACB6C 800ABF6C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0ACB70 800ABF70 AFB00018 */  sw    $s0, 0x18($sp)
/* 0ACB74 800ABF74 8C820004 */  lw    $v0, 4($a0)
/* 0ACB78 800ABF78 00808025 */  move  $s0, $a0
/* 0ACB7C 800ABF7C 240E0140 */  li    $t6, 320
/* 0ACB80 800ABF80 10400008 */  beqz  $v0, .L800ABFA4
/* 0ACB84 800ABF84 240F0001 */   li    $t7, 1
/* 0ACB88 800ABF88 24010001 */  li    $at, 1
/* 0ACB8C 800ABF8C 10410015 */  beq   $v0, $at, .L800ABFE4
/* 0ACB90 800ABF90 24010002 */   li    $at, 2
/* 0ACB94 800ABF94 10410037 */  beq   $v0, $at, .L800AC074
/* 0ACB98 800ABF98 02002025 */   move  $a0, $s0
/* 0ACB9C 800ABF9C 1000005E */  b     .L800AC118
/* 0ACBA0 800ABFA0 8FBF001C */   lw    $ra, 0x1c($sp)
.L800ABFA4:
/* 0ACBA4 800ABFA4 AE0E000C */  sw    $t6, 0xc($s0)
/* 0ACBA8 800ABFA8 AE0F0004 */  sw    $t7, 4($s0)
/* 0ACBAC 800ABFAC 3C18800E */  lui   $t8, %hi(gCurrentCourseId) # $t8, 0x800e
/* 0ACBB0 800ABFB0 8718C5A0 */  lh    $t8, %lo(gCurrentCourseId)($t8)
/* 0ACBB4 800ABFB4 3C04800E */  lui   $a0, %hi(D_800E7524)
/* 0ACBB8 800ABFB8 0018C880 */  sll   $t9, $t8, 2
/* 0ACBBC 800ABFBC 00992021 */  addu  $a0, $a0, $t9
/* 0ACBC0 800ABFC0 0C024C0D */  jal   func_80093034
/* 0ACBC4 800ABFC4 8C847524 */   lw    $a0, %lo(D_800E7524)($a0)
/* 0ACBC8 800ABFC8 04410003 */  bgez  $v0, .L800ABFD8
/* 0ACBCC 800ABFCC 00024043 */   sra   $t0, $v0, 1
/* 0ACBD0 800ABFD0 24410001 */  addiu $at, $v0, 1
/* 0ACBD4 800ABFD4 00014043 */  sra   $t0, $at, 1
.L800ABFD8:
/* 0ACBD8 800ABFD8 240900A0 */  li    $t1, 160
/* 0ACBDC 800ABFDC 01285023 */  subu  $t2, $t1, $t0
/* 0ACBE0 800ABFE0 AE0A0020 */  sw    $t2, 0x20($s0)
.L800ABFE4:
/* 0ACBE4 800ABFE4 02002025 */  move  $a0, $s0
/* 0ACBE8 800ABFE8 0C02A482 */  jal   func_800A9208
/* 0ACBEC 800ABFEC 8E050020 */   lw    $a1, 0x20($s0)
/* 0ACBF0 800ABFF0 8E04000C */  lw    $a0, 0xc($s0)
/* 0ACBF4 800ABFF4 8E030020 */  lw    $v1, 0x20($s0)
/* 0ACBF8 800ABFF8 240C0008 */  li    $t4, 8
/* 0ACBFC 800ABFFC 240F0002 */  li    $t7, 2
/* 0ACC00 800AC000 00831023 */  subu  $v0, $a0, $v1
/* 0ACC04 800AC004 04410003 */  bgez  $v0, .L800AC014
/* 0ACC08 800AC008 00025883 */   sra   $t3, $v0, 2
/* 0ACC0C 800AC00C 24410003 */  addiu $at, $v0, 3
/* 0ACC10 800AC010 00015883 */  sra   $t3, $at, 2
.L800AC014:
/* 0ACC14 800AC014 29610009 */  slti  $at, $t3, 9
/* 0ACC18 800AC018 14200004 */  bnez  $at, .L800AC02C
/* 0ACC1C 800AC01C AE0B001C */   sw    $t3, 0x1c($s0)
/* 0ACC20 800AC020 AE0C001C */  sw    $t4, 0x1c($s0)
/* 0ACC24 800AC024 8E030020 */  lw    $v1, 0x20($s0)
/* 0ACC28 800AC028 8E04000C */  lw    $a0, 0xc($s0)
.L800AC02C:
/* 0ACC2C 800AC02C 8E0D001C */  lw    $t5, 0x1c($s0)
/* 0ACC30 800AC030 3C01800F */  lui   $at, %hi(D_800F2648)
/* 0ACC34 800AC034 D4282648 */  ldc1  $f8, %lo(D_800F2648)($at)
/* 0ACC38 800AC038 448D2000 */  mtc1  $t5, $f4
/* 0ACC3C 800AC03C 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 0ACC40 800AC040 44818800 */  mtc1  $at, $f17
/* 0ACC44 800AC044 468021A1 */  cvt.d.w $f6, $f4
/* 0ACC48 800AC048 44808000 */  mtc1  $zero, $f16
/* 0ACC4C 800AC04C 246E0014 */  addiu $t6, $v1, 0x14
/* 0ACC50 800AC050 01C4082A */  slt   $at, $t6, $a0
/* 0ACC54 800AC054 46283282 */  mul.d $f10, $f6, $f8
/* 0ACC58 800AC058 46305480 */  add.d $f18, $f10, $f16
/* 0ACC5C 800AC05C 46209120 */  cvt.s.d $f4, $f18
/* 0ACC60 800AC060 1420002C */  bnez  $at, .L800AC114
/* 0ACC64 800AC064 E6040024 */   swc1  $f4, 0x24($s0)
/* 0ACC68 800AC068 AE0F0004 */  sw    $t7, 4($s0)
/* 0ACC6C 800AC06C 10000029 */  b     .L800AC114
/* 0ACC70 800AC070 AE000018 */   sw    $zero, 0x18($s0)
.L800AC074:
/* 0ACC74 800AC074 0C02A482 */  jal   func_800A9208
/* 0ACC78 800AC078 8E050020 */   lw    $a1, 0x20($s0)
/* 0ACC7C 800AC07C 8E0A0018 */  lw    $t2, 0x18($s0)
/* 0ACC80 800AC080 8E18000C */  lw    $t8, 0xc($s0)
/* 0ACC84 800AC084 8E190020 */  lw    $t9, 0x20($s0)
/* 0ACC88 800AC088 254B0001 */  addiu $t3, $t2, 1
/* 0ACC8C 800AC08C 256CFFF6 */  addiu $t4, $t3, -0xa
/* 0ACC90 800AC090 448C3000 */  mtc1  $t4, $f6
/* 0ACC94 800AC094 03194823 */  subu  $t1, $t8, $t9
/* 0ACC98 800AC098 05210003 */  bgez  $t1, .L800AC0A8
/* 0ACC9C 800AC09C 00094083 */   sra   $t0, $t1, 2
/* 0ACCA0 800AC0A0 25210003 */  addiu $at, $t1, 3
/* 0ACCA4 800AC0A4 00014083 */  sra   $t0, $at, 2
.L800AC0A8:
/* 0ACCA8 800AC0A8 46803021 */  cvt.d.w $f0, $f6
/* 0ACCAC 800AC0AC AE08001C */  sw    $t0, 0x1c($s0)
/* 0ACCB0 800AC0B0 AE0B0018 */  sw    $t3, 0x18($s0)
/* 0ACCB4 800AC0B4 3C01800F */  lui   $at, %hi(D_800F2650)
/* 0ACCB8 800AC0B8 D4282650 */  ldc1  $f8, %lo(D_800F2650)($at)
/* 0ACCBC 800AC0BC 3C01800F */  lui   $at, %hi(D_800F2658)
/* 0ACCC0 800AC0C0 D4322658 */  ldc1  $f18, %lo(D_800F2658)($at)
/* 0ACCC4 800AC0C4 46280282 */  mul.d $f10, $f0, $f8
/* 0ACCC8 800AC0C8 29610009 */  slti  $at, $t3, 9
/* 0ACCCC 800AC0CC 46205402 */  mul.d $f16, $f10, $f0
/* 0ACCD0 800AC0D0 46328100 */  add.d $f4, $f16, $f18
/* 0ACCD4 800AC0D4 462021A0 */  cvt.s.d $f6, $f4
/* 0ACCD8 800AC0D8 1420000E */  bnez  $at, .L800AC114
/* 0ACCDC 800AC0DC E6060024 */   swc1  $f6, 0x24($s0)
/* 0ACCE0 800AC0E0 C60A0024 */  lwc1  $f10, 0x24($s0)
/* 0ACCE4 800AC0E4 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 0ACCE8 800AC0E8 44814800 */  mtc1  $at, $f9
/* 0ACCEC 800AC0EC 44804000 */  mtc1  $zero, $f8
/* 0ACCF0 800AC0F0 46005421 */  cvt.d.s $f16, $f10
/* 0ACCF4 800AC0F4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0ACCF8 800AC0F8 4630403C */  c.lt.d $f8, $f16
/* 0ACCFC 800AC0FC 00000000 */  nop   
/* 0ACD00 800AC100 45020005 */  bc1fl .L800AC118
/* 0ACD04 800AC104 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0ACD08 800AC108 44819000 */  mtc1  $at, $f18
/* 0ACD0C 800AC10C 00000000 */  nop   
/* 0ACD10 800AC110 E6120024 */  swc1  $f18, 0x24($s0)
.L800AC114:
/* 0ACD14 800AC114 8FBF001C */  lw    $ra, 0x1c($sp)
.L800AC118:
/* 0ACD18 800AC118 8FB00018 */  lw    $s0, 0x18($sp)
/* 0ACD1C 800AC11C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0ACD20 800AC120 03E00008 */  jr    $ra
/* 0ACD24 800AC124 00000000 */   nop   

/* 0ACD28 800AC128 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0ACD2C 800AC12C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0ACD30 800AC130 8C820004 */  lw    $v0, 4($a0)
/* 0ACD34 800AC134 24010001 */  li    $at, 1
/* 0ACD38 800AC138 240E0140 */  li    $t6, 320
/* 0ACD3C 800AC13C 10400009 */  beqz  $v0, .L800AC164
/* 0ACD40 800AC140 240F0001 */   li    $t7, 1
/* 0ACD44 800AC144 10410009 */  beq   $v0, $at, .L800AC16C
/* 0ACD48 800AC148 24010002 */   li    $at, 2
/* 0ACD4C 800AC14C 10410027 */  beq   $v0, $at, .L800AC1EC
/* 0ACD50 800AC150 24010003 */   li    $at, 3
/* 0ACD54 800AC154 50410046 */  beql  $v0, $at, .L800AC270
/* 0ACD58 800AC158 8C8E0018 */   lw    $t6, 0x18($a0)
/* 0ACD5C 800AC15C 10000065 */  b     .L800AC2F4
/* 0ACD60 800AC160 8FBF0014 */   lw    $ra, 0x14($sp)
.L800AC164:
/* 0ACD64 800AC164 AC8E000C */  sw    $t6, 0xc($a0)
/* 0ACD68 800AC168 AC8F0004 */  sw    $t7, 4($a0)
.L800AC16C:
/* 0ACD6C 800AC16C 24050064 */  li    $a1, 100
/* 0ACD70 800AC170 0C02A503 */  jal   func_800A940C
/* 0ACD74 800AC174 AFA40018 */   sw    $a0, 0x18($sp)
/* 0ACD78 800AC178 8FA40018 */  lw    $a0, 0x18($sp)
/* 0ACD7C 800AC17C 24010006 */  li    $at, 6
/* 0ACD80 800AC180 24190008 */  li    $t9, 8
/* 0ACD84 800AC184 8C83000C */  lw    $v1, 0xc($a0)
/* 0ACD88 800AC188 24090002 */  li    $t1, 2
/* 0ACD8C 800AC18C 2462FF9C */  addiu $v0, $v1, -0x64
/* 0ACD90 800AC190 0041001A */  div   $zero, $v0, $at
/* 0ACD94 800AC194 0000C012 */  mflo  $t8
/* 0ACD98 800AC198 2B010009 */  slti  $at, $t8, 9
/* 0ACD9C 800AC19C 14200003 */  bnez  $at, .L800AC1AC
/* 0ACDA0 800AC1A0 AC98001C */   sw    $t8, 0x1c($a0)
/* 0ACDA4 800AC1A4 AC99001C */  sw    $t9, 0x1c($a0)
/* 0ACDA8 800AC1A8 8C83000C */  lw    $v1, 0xc($a0)
.L800AC1AC:
/* 0ACDAC 800AC1AC 8C88001C */  lw    $t0, 0x1c($a0)
/* 0ACDB0 800AC1B0 3C01800F */  lui   $at, %hi(D_800F2660)
/* 0ACDB4 800AC1B4 D4282660 */  ldc1  $f8, %lo(D_800F2660)($at)
/* 0ACDB8 800AC1B8 44882000 */  mtc1  $t0, $f4
/* 0ACDBC 800AC1BC 3C01800F */  lui   $at, %hi(D_800F2668)
/* 0ACDC0 800AC1C0 D4302668 */  ldc1  $f16, %lo(D_800F2668)($at)
/* 0ACDC4 800AC1C4 468021A1 */  cvt.d.w $f6, $f4
/* 0ACDC8 800AC1C8 24010064 */  li    $at, 100
/* 0ACDCC 800AC1CC 46283282 */  mul.d $f10, $f6, $f8
/* 0ACDD0 800AC1D0 46305480 */  add.d $f18, $f10, $f16
/* 0ACDD4 800AC1D4 46209120 */  cvt.s.d $f4, $f18
/* 0ACDD8 800AC1D8 14610045 */  bne   $v1, $at, .L800AC2F0
/* 0ACDDC 800AC1DC E4840024 */   swc1  $f4, 0x24($a0)
/* 0ACDE0 800AC1E0 AC890004 */  sw    $t1, 4($a0)
/* 0ACDE4 800AC1E4 10000042 */  b     .L800AC2F0
/* 0ACDE8 800AC1E8 AC800018 */   sw    $zero, 0x18($a0)
.L800AC1EC:
/* 0ACDEC 800AC1EC 8C8A0018 */  lw    $t2, 0x18($a0)
/* 0ACDF0 800AC1F0 3C013FF8 */  li    $at, 0x3FF80000 # 1.937500
/* 0ACDF4 800AC1F4 44814800 */  mtc1  $at, $f9
/* 0ACDF8 800AC1F8 254B0001 */  addiu $t3, $t2, 1
/* 0ACDFC 800AC1FC 256CFFF1 */  addiu $t4, $t3, -0xf
/* 0ACE00 800AC200 448C3000 */  mtc1  $t4, $f6
/* 0ACE04 800AC204 AC8B0018 */  sw    $t3, 0x18($a0)
/* 0ACE08 800AC208 AC80001C */  sw    $zero, 0x1c($a0)
/* 0ACE0C 800AC20C 46803021 */  cvt.d.w $f0, $f6
/* 0ACE10 800AC210 3C01800F */  lui   $at, %hi(D_800F2670)
/* 0ACE14 800AC214 D42A2670 */  ldc1  $f10, %lo(D_800F2670)($at)
/* 0ACE18 800AC218 44804000 */  mtc1  $zero, $f8
/* 0ACE1C 800AC21C 29610010 */  slti  $at, $t3, 0x10
/* 0ACE20 800AC220 462A0402 */  mul.d $f16, $f0, $f10
/* 0ACE24 800AC224 00000000 */  nop   
/* 0ACE28 800AC228 46208482 */  mul.d $f18, $f16, $f0
/* 0ACE2C 800AC22C 46324101 */  sub.d $f4, $f8, $f18
/* 0ACE30 800AC230 462021A0 */  cvt.s.d $f6, $f4
/* 0ACE34 800AC234 1420002E */  bnez  $at, .L800AC2F0
/* 0ACE38 800AC238 E4860024 */   swc1  $f6, 0x24($a0)
/* 0ACE3C 800AC23C C48A0024 */  lwc1  $f10, 0x24($a0)
/* 0ACE40 800AC240 3C01800F */  lui   $at, %hi(D_800F2678)
/* 0ACE44 800AC244 D4282678 */  ldc1  $f8, %lo(D_800F2678)($at)
/* 0ACE48 800AC248 46005421 */  cvt.d.s $f16, $f10
/* 0ACE4C 800AC24C 240D0003 */  li    $t5, 3
/* 0ACE50 800AC250 4628803C */  c.lt.d $f16, $f8
/* 0ACE54 800AC254 00000000 */  nop   
/* 0ACE58 800AC258 45020026 */  bc1fl .L800AC2F4
/* 0ACE5C 800AC25C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0ACE60 800AC260 AC8D0004 */  sw    $t5, 4($a0)
/* 0ACE64 800AC264 10000022 */  b     .L800AC2F0
/* 0ACE68 800AC268 AC800018 */   sw    $zero, 0x18($a0)
/* 0ACE6C 800AC26C 8C8E0018 */  lw    $t6, 0x18($a0)
.L800AC270:
/* 0ACE70 800AC270 3C013FF4 */  li    $at, 0x3FF40000 # 1.906250
/* 0ACE74 800AC274 44812800 */  mtc1  $at, $f5
/* 0ACE78 800AC278 25CF0001 */  addiu $t7, $t6, 1
/* 0ACE7C 800AC27C 25F8FFF1 */  addiu $t8, $t7, -0xf
/* 0ACE80 800AC280 44989000 */  mtc1  $t8, $f18
/* 0ACE84 800AC284 AC8F0018 */  sw    $t7, 0x18($a0)
/* 0ACE88 800AC288 AC80001C */  sw    $zero, 0x1c($a0)
/* 0ACE8C 800AC28C 46809021 */  cvt.d.w $f0, $f18
/* 0ACE90 800AC290 3C01800F */  lui   $at, %hi(D_800F2680)
/* 0ACE94 800AC294 D4262680 */  ldc1  $f6, %lo(D_800F2680)($at)
/* 0ACE98 800AC298 44802000 */  mtc1  $zero, $f4
/* 0ACE9C 800AC29C 29E1000D */  slti  $at, $t7, 0xd
/* 0ACEA0 800AC2A0 46260282 */  mul.d $f10, $f0, $f6
/* 0ACEA4 800AC2A4 00000000 */  nop   
/* 0ACEA8 800AC2A8 46205402 */  mul.d $f16, $f10, $f0
/* 0ACEAC 800AC2AC 46302201 */  sub.d $f8, $f4, $f16
/* 0ACEB0 800AC2B0 462044A0 */  cvt.s.d $f18, $f8
/* 0ACEB4 800AC2B4 1420000E */  bnez  $at, .L800AC2F0
/* 0ACEB8 800AC2B8 E4920024 */   swc1  $f18, 0x24($a0)
/* 0ACEBC 800AC2BC C4860024 */  lwc1  $f6, 0x24($a0)
/* 0ACEC0 800AC2C0 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 0ACEC4 800AC2C4 44812800 */  mtc1  $at, $f5
/* 0ACEC8 800AC2C8 44802000 */  mtc1  $zero, $f4
/* 0ACECC 800AC2CC 460032A1 */  cvt.d.s $f10, $f6
/* 0ACED0 800AC2D0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0ACED4 800AC2D4 4624503C */  c.lt.d $f10, $f4
/* 0ACED8 800AC2D8 00000000 */  nop   
/* 0ACEDC 800AC2DC 45020005 */  bc1fl .L800AC2F4
/* 0ACEE0 800AC2E0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0ACEE4 800AC2E4 44818000 */  mtc1  $at, $f16
/* 0ACEE8 800AC2E8 00000000 */  nop   
/* 0ACEEC 800AC2EC E4900024 */  swc1  $f16, 0x24($a0)
.L800AC2F0:
/* 0ACEF0 800AC2F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L800AC2F4:
/* 0ACEF4 800AC2F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0ACEF8 800AC2F8 03E00008 */  jr    $ra
/* 0ACEFC 800AC2FC 00000000 */   nop   
