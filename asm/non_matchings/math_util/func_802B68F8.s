glabel func_802B68F8
/* 11FF08 802B68F8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 11FF0C 802B68FC 44866000 */  mtc1  $a2, $f12
/* 11FF10 802B6900 44812000 */  mtc1  $at, $f4
/* 11FF14 802B6904 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 11FF18 802B6908 44857000 */  mtc1  $a1, $f14
/* 11FF1C 802B690C 46046032 */  c.eq.s $f12, $f4
/* 11FF20 802B6910 AFBF001C */  sw    $ra, 0x1c($sp)
/* 11FF24 802B6914 AFA40020 */  sw    $a0, 0x20($sp)
/* 11FF28 802B6918 AFA7002C */  sw    $a3, 0x2c($sp)
/* 11FF2C 802B691C 45000018 */  bc1f  .L802B6980
/* 11FF30 802B6920 3C01BF80 */   li    $at, 0xBF800000 # -1.000000
/* 11FF34 802B6924 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 11FF38 802B6928 44810000 */  mtc1  $at, $f0
/* 11FF3C 802B692C 44801000 */  mtc1  $zero, $f2
/* 11FF40 802B6930 00002025 */  move  $a0, $zero
/* 11FF44 802B6934 8FA70020 */  lw    $a3, 0x20($sp)
/* 11FF48 802B6938 24090003 */  li    $t1, 3
/* 11FF4C 802B693C 2406000C */  li    $a2, 12
.L802B6940:
/* 11FF50 802B6940 00042880 */  sll   $a1, $a0, 2
/* 11FF54 802B6944 00001025 */  move  $v0, $zero
/* 11FF58 802B6948 00E01825 */  move  $v1, $a3
.L802B694C:
/* 11FF5C 802B694C 54A20004 */  bnel  $a1, $v0, .L802B6960
/* 11FF60 802B6950 E4620000 */   swc1  $f2, ($v1)
/* 11FF64 802B6954 10000002 */  b     .L802B6960
/* 11FF68 802B6958 E4600000 */   swc1  $f0, ($v1)
/* 11FF6C 802B695C E4620000 */  swc1  $f2, ($v1)
.L802B6960:
/* 11FF70 802B6960 24420004 */  addiu $v0, $v0, 4
/* 11FF74 802B6964 1446FFF9 */  bne   $v0, $a2, .L802B694C
/* 11FF78 802B6968 24630004 */   addiu $v1, $v1, 4
/* 11FF7C 802B696C 24840001 */  addiu $a0, $a0, 1
/* 11FF80 802B6970 1489FFF3 */  bne   $a0, $t1, .L802B6940
/* 11FF84 802B6974 24E7000C */   addiu $a3, $a3, 0xc
/* 11FF88 802B6978 1000003F */  b     .L802B6A78
/* 11FF8C 802B697C 8FBF001C */   lw    $ra, 0x1c($sp)
.L802B6980:
/* 11FF90 802B6980 44818000 */  mtc1  $at, $f16
/* 11FF94 802B6984 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 11FF98 802B6988 00002025 */  move  $a0, $zero
/* 11FF9C 802B698C 46106032 */  c.eq.s $f12, $f16
/* 11FFA0 802B6990 8FA70020 */  lw    $a3, 0x20($sp)
/* 11FFA4 802B6994 24090003 */  li    $t1, 3
/* 11FFA8 802B6998 45000015 */  bc1f  .L802B69F0
/* 11FFAC 802B699C 00000000 */   nop   
/* 11FFB0 802B69A0 44801000 */  mtc1  $zero, $f2
/* 11FFB4 802B69A4 44810000 */  mtc1  $at, $f0
/* 11FFB8 802B69A8 2406000C */  li    $a2, 12
.L802B69AC:
/* 11FFBC 802B69AC 00001025 */  move  $v0, $zero
/* 11FFC0 802B69B0 00E01825 */  move  $v1, $a3
/* 11FFC4 802B69B4 00042880 */  sll   $a1, $a0, 2
.L802B69B8:
/* 11FFC8 802B69B8 54A20004 */  bnel  $a1, $v0, .L802B69CC
/* 11FFCC 802B69BC E4620000 */   swc1  $f2, ($v1)
/* 11FFD0 802B69C0 10000002 */  b     .L802B69CC
/* 11FFD4 802B69C4 E4600000 */   swc1  $f0, ($v1)
/* 11FFD8 802B69C8 E4620000 */  swc1  $f2, ($v1)
.L802B69CC:
/* 11FFDC 802B69CC 24420004 */  addiu $v0, $v0, 4
/* 11FFE0 802B69D0 1446FFF9 */  bne   $v0, $a2, .L802B69B8
/* 11FFE4 802B69D4 24630004 */   addiu $v1, $v1, 4
/* 11FFE8 802B69D8 24840001 */  addiu $a0, $a0, 1
/* 11FFEC 802B69DC 1489FFF3 */  bne   $a0, $t1, .L802B69AC
/* 11FFF0 802B69E0 24E7000C */   addiu $a3, $a3, 0xc
/* 11FFF4 802B69E4 8FAE0020 */  lw    $t6, 0x20($sp)
/* 11FFF8 802B69E8 10000022 */  b     .L802B6A74
/* 11FFFC 802B69EC E5D00010 */   swc1  $f16, 0x10($t6)
.L802B69F0:
/* 120000 802B69F0 0C0ADF3A */  jal   func_802B7CE8
/* 120004 802B69F4 E7AE0024 */   swc1  $f14, 0x24($sp)
/* 120008 802B69F8 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 12000C 802B69FC 44813000 */  mtc1  $at, $f6
/* 120010 802B6A00 3C01802C */  lui   $at, %hi(D_802B9FC8)
/* 120014 802B6A04 D4329FC8 */  ldc1  $f18, %lo(D_802B9FC8)($at)
/* 120018 802B6A08 46060202 */  mul.s $f8, $f0, $f6
/* 12001C 802B6A0C C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 120020 802B6A10 3C01802C */  lui   $at, %hi(D_802B9FD0)
/* 120024 802B6A14 D4269FD0 */  ldc1  $f6, %lo(D_802B9FD0)($at)
/* 120028 802B6A18 C7AC002C */  lwc1  $f12, 0x2c($sp)
/* 12002C 802B6A1C 8FA40020 */  lw    $a0, 0x20($sp)
/* 120030 802B6A20 24070000 */  li    $a3, 0
/* 120034 802B6A24 460042A1 */  cvt.d.s $f10, $f8
/* 120038 802B6A28 46325103 */  div.d $f4, $f10, $f18
/* 12003C 802B6A2C 460E7482 */  mul.s $f18, $f14, $f14
/* 120040 802B6A30 46243201 */  sub.d $f8, $f6, $f4
/* 120044 802B6A34 460C6182 */  mul.s $f6, $f12, $f12
/* 120048 802B6A38 46204287 */  neg.d $f10, $f8
/* 12004C 802B6A3C 46006207 */  neg.s $f8, $f12
/* 120050 802B6A40 462050A0 */  cvt.s.d $f2, $f10
/* 120054 802B6A44 46069000 */  add.s $f0, $f18, $f6
/* 120058 802B6A48 4600110D */  trunc.w.s $f4, $f2
/* 12005C 802B6A4C 46000004 */  sqrt.s $f0, $f0
/* 120060 802B6A50 44052000 */  mfc1  $a1, $f4
/* 120064 802B6A54 00000000 */  nop   
/* 120068 802B6A58 0005C400 */  sll   $t8, $a1, 0x10
/* 12006C 802B6A5C 00182C03 */  sra   $a1, $t8, 0x10
/* 120070 802B6A60 46004283 */  div.s $f10, $f8, $f0
/* 120074 802B6A64 46007483 */  div.s $f18, $f14, $f0
/* 120078 802B6A68 44065000 */  mfc1  $a2, $f10
/* 12007C 802B6A6C 0C0ADAA1 */  jal   func_802B6A84
/* 120080 802B6A70 E7B20010 */   swc1  $f18, 0x10($sp)
.L802B6A74:
/* 120084 802B6A74 8FBF001C */  lw    $ra, 0x1c($sp)
.L802B6A78:
/* 120088 802B6A78 27BD0020 */  addiu $sp, $sp, 0x20
/* 12008C 802B6A7C 03E00008 */  jr    $ra
/* 120090 802B6A80 00000000 */   nop   
