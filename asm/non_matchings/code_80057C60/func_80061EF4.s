glabel func_80061EF4
/* 062AF4 80061EF4 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 062AF8 80061EF8 AFB10028 */  sw    $s1, 0x28($sp)
/* 062AFC 80061EFC 00808825 */  move  $s1, $a0
/* 062B00 80061F00 AFBF002C */  sw    $ra, 0x2c($sp)
/* 062B04 80061F04 AFB00024 */  sw    $s0, 0x24($sp)
/* 062B08 80061F08 240800FF */  li    $t0, 255
/* 062B0C 80061F0C 00C08025 */  move  $s0, $a2
/* 062B10 80061F10 AFA50054 */  sw    $a1, 0x54($sp)
/* 062B14 80061F14 AFA7005C */  sw    $a3, 0x5c($sp)
/* 062B18 80061F18 AFA80048 */  sw    $t0, 0x48($sp)
/* 062B1C 80061F1C 0C0ADF8D */  jal   random_int
/* 062B20 80061F20 24040008 */   li    $a0, 8
/* 062B24 80061F24 30430001 */  andi  $v1, $v0, 1
/* 062B28 80061F28 24010001 */  li    $at, 1
/* 062B2C 80061F2C 8FA80048 */  lw    $t0, 0x48($sp)
/* 062B30 80061F30 14610006 */  bne   $v1, $at, .L80061F4C
/* 062B34 80061F34 87AA0056 */   lh    $t2, 0x56($sp)
/* 062B38 80061F38 C6220018 */  lwc1  $f2, 0x18($s1)
/* 062B3C 80061F3C 24090001 */  li    $t1, 1
/* 062B40 80061F40 00004025 */  move  $t0, $zero
/* 062B44 80061F44 AFA90044 */  sw    $t1, 0x44($sp)
/* 062B48 80061F48 E7A2003C */  swc1  $f2, 0x3c($sp)
.L80061F4C:
/* 062B4C 80061F4C 8FA90044 */  lw    $t1, 0x44($sp)
/* 062B50 80061F50 14600004 */  bnez  $v1, .L80061F64
/* 062B54 80061F54 C7A2003C */   lwc1  $f2, 0x3c($sp)
/* 062B58 80061F58 00004825 */  move  $t1, $zero
/* 062B5C 80061F5C 00004025 */  move  $t0, $zero
/* 062B60 80061F60 C6220018 */  lwc1  $f2, 0x18($s1)
.L80061F64:
/* 062B64 80061F64 55000091 */  bnel  $t0, $zero, .L800621AC
/* 062B68 80061F68 8FBF002C */   lw    $ra, 0x2c($sp)
/* 062B6C 80061F6C 15400049 */  bnez  $t2, .L80062094
/* 062B70 80061F70 24030048 */   li    $v1, 72
/* 062B74 80061F74 02030019 */  multu $s0, $v1
/* 062B78 80061F78 00007012 */  mflo  $t6
/* 062B7C 80061F7C 022E1021 */  addu  $v0, $s1, $t6
/* 062B80 80061F80 844F0AE6 */  lh    $t7, 0xae6($v0)
/* 062B84 80061F84 1DE00004 */  bgtz  $t7, .L80061F98
/* 062B88 80061F88 00000000 */   nop   
/* 062B8C 80061F8C 84580AE4 */  lh    $t8, 0xae4($v0)
/* 062B90 80061F90 57000041 */  bnel  $t8, $zero, .L80062098
/* 062B94 80061F94 24030048 */   li    $v1, 72
.L80061F98:
/* 062B98 80061F98 01430019 */  multu $t2, $v1
/* 062B9C 80061F9C 44800000 */  mtc1  $zero, $f0
/* 062BA0 80061FA0 44071000 */  mfc1  $a3, $f2
/* 062BA4 80061FA4 02202025 */  move  $a0, $s1
/* 062BA8 80061FA8 44060000 */  mfc1  $a2, $f0
/* 062BAC 80061FAC AFA80014 */  sw    $t0, 0x14($sp)
/* 062BB0 80061FB0 AFA90018 */  sw    $t1, 0x18($sp)
/* 062BB4 80061FB4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 062BB8 80061FB8 0000C812 */  mflo  $t9
/* 062BBC 80061FBC 02398021 */  addu  $s0, $s1, $t9
/* 062BC0 80061FC0 26050AC8 */  addiu $a1, $s0, 0xac8
/* 062BC4 80061FC4 0C0175E5 */  jal   func_8005D794
/* 062BC8 80061FC8 AFA50030 */   sw    $a1, 0x30($sp)
/* 062BCC 80061FCC 8FA40030 */  lw    $a0, 0x30($sp)
/* 062BD0 80061FD0 24050003 */  li    $a1, 3
/* 062BD4 80061FD4 0C0175F6 */  jal   func_8005D7D8
/* 062BD8 80061FD8 3C063F00 */   lui   $a2, 0x3f00
/* 062BDC 80061FDC 3C0500FF */  lui   $a1, (0x00FFFFFF >> 16) # lui $a1, 0xff
/* 062BE0 80061FE0 34A5FFFF */  ori   $a1, (0x00FFFFFF & 0xFFFF) # ori $a1, $a1, 0xffff
/* 062BE4 80061FE4 8FA40030 */  lw    $a0, 0x30($sp)
/* 062BE8 80061FE8 0C017600 */  jal   func_8005D800
/* 062BEC 80061FEC 24060060 */   li    $a2, 96
/* 062BF0 80061FF0 960B0AD8 */  lhu   $t3, 0xad8($s0)
/* 062BF4 80061FF4 24010001 */  li    $at, 1
/* 062BF8 80061FF8 A6000AE8 */  sh    $zero, 0xae8($s0)
/* 062BFC 80061FFC 55610006 */  bnel  $t3, $at, .L80062018
/* 062C00 80062000 860E0AE8 */   lh    $t6, 0xae8($s0)
/* 062C04 80062004 860C0AE8 */  lh    $t4, 0xae8($s0)
/* 062C08 80062008 258D0888 */  addiu $t5, $t4, 0x888
/* 062C0C 8006200C 10000004 */  b     .L80062020
/* 062C10 80062010 A60D0AE8 */   sh    $t5, 0xae8($s0)
/* 062C14 80062014 860E0AE8 */  lh    $t6, 0xae8($s0)
.L80062018:
/* 062C18 80062018 25CFF778 */  addiu $t7, $t6, -0x888
/* 062C1C 8006201C A60F0AE8 */  sh    $t7, 0xae8($s0)
.L80062020:
/* 062C20 80062020 86180AE8 */  lh    $t8, 0xae8($s0)
/* 062C24 80062024 8639002E */  lh    $t9, 0x2e($s1)
/* 062C28 80062028 862C00C0 */  lh    $t4, 0xc0($s1)
/* 062C2C 8006202C 03195823 */  subu  $t3, $t8, $t9
/* 062C30 80062030 016C2023 */  subu  $a0, $t3, $t4
/* 062C34 80062034 308DFFFF */  andi  $t5, $a0, 0xffff
/* 062C38 80062038 0C0AE00E */  jal   func_802B8038
/* 062C3C 8006203C 01A02025 */   move  $a0, $t5
/* 062C40 80062040 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 062C44 80062044 44812000 */  mtc1  $at, $f4
/* 062C48 80062048 C628001C */  lwc1  $f8, 0x1c($s1)
/* 062C4C 8006204C 860E0AE8 */  lh    $t6, 0xae8($s0)
/* 062C50 80062050 46040182 */  mul.s $f6, $f0, $f4
/* 062C54 80062054 46083280 */  add.s $f10, $f6, $f8
/* 062C58 80062058 E60A0AD0 */  swc1  $f10, 0xad0($s0)
/* 062C5C 8006205C 862F002E */  lh    $t7, 0x2e($s1)
/* 062C60 80062060 863900C0 */  lh    $t9, 0xc0($s1)
/* 062C64 80062064 01CFC023 */  subu  $t8, $t6, $t7
/* 062C68 80062068 03192023 */  subu  $a0, $t8, $t9
/* 062C6C 8006206C 308BFFFF */  andi  $t3, $a0, 0xffff
/* 062C70 80062070 0C0AE006 */  jal   func_802B8018
/* 062C74 80062074 01602025 */   move  $a0, $t3
/* 062C78 80062078 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 062C7C 8006207C 44818000 */  mtc1  $at, $f16
/* 062C80 80062080 C6240014 */  lwc1  $f4, 0x14($s1)
/* 062C84 80062084 46100482 */  mul.s $f18, $f0, $f16
/* 062C88 80062088 46049180 */  add.s $f6, $f18, $f4
/* 062C8C 8006208C 10000046 */  b     .L800621A8
/* 062C90 80062090 E6060AC8 */   swc1  $f6, 0xac8($s0)
.L80062094:
/* 062C94 80062094 24030048 */  li    $v1, 72
.L80062098:
/* 062C98 80062098 02030019 */  multu $s0, $v1
/* 062C9C 8006209C 00006012 */  mflo  $t4
/* 062CA0 800620A0 022C6821 */  addu  $t5, $s1, $t4
/* 062CA4 800620A4 85AE0AE6 */  lh    $t6, 0xae6($t5)
/* 062CA8 800620A8 59C00040 */  blezl $t6, .L800621AC
/* 062CAC 800620AC 8FBF002C */   lw    $ra, 0x2c($sp)
/* 062CB0 800620B0 01430019 */  multu $t2, $v1
/* 062CB4 800620B4 44800000 */  mtc1  $zero, $f0
/* 062CB8 800620B8 44071000 */  mfc1  $a3, $f2
/* 062CBC 800620BC 02202025 */  move  $a0, $s1
/* 062CC0 800620C0 44060000 */  mfc1  $a2, $f0
/* 062CC4 800620C4 AFA80014 */  sw    $t0, 0x14($sp)
/* 062CC8 800620C8 AFA90018 */  sw    $t1, 0x18($sp)
/* 062CCC 800620CC E7A00010 */  swc1  $f0, 0x10($sp)
/* 062CD0 800620D0 00007812 */  mflo  $t7
/* 062CD4 800620D4 022F8021 */  addu  $s0, $s1, $t7
/* 062CD8 800620D8 26050AC8 */  addiu $a1, $s0, 0xac8
/* 062CDC 800620DC 0C0175E5 */  jal   func_8005D794
/* 062CE0 800620E0 AFA50030 */   sw    $a1, 0x30($sp)
/* 062CE4 800620E4 8FA40030 */  lw    $a0, 0x30($sp)
/* 062CE8 800620E8 24050003 */  li    $a1, 3
/* 062CEC 800620EC 0C0175F6 */  jal   func_8005D7D8
/* 062CF0 800620F0 3C063F00 */   lui   $a2, 0x3f00
/* 062CF4 800620F4 3C0500FF */  lui   $a1, (0x00FFFFFF >> 16) # lui $a1, 0xff
/* 062CF8 800620F8 34A5FFFF */  ori   $a1, (0x00FFFFFF & 0xFFFF) # ori $a1, $a1, 0xffff
/* 062CFC 800620FC 8FA40030 */  lw    $a0, 0x30($sp)
/* 062D00 80062100 0C017600 */  jal   func_8005D800
/* 062D04 80062104 24060060 */   li    $a2, 96
/* 062D08 80062108 96180AD8 */  lhu   $t8, 0xad8($s0)
/* 062D0C 8006210C 24010001 */  li    $at, 1
/* 062D10 80062110 A6000AE8 */  sh    $zero, 0xae8($s0)
/* 062D14 80062114 57010006 */  bnel  $t8, $at, .L80062130
/* 062D18 80062118 860C0AE8 */   lh    $t4, 0xae8($s0)
/* 062D1C 8006211C 86190AE8 */  lh    $t9, 0xae8($s0)
/* 062D20 80062120 272B0888 */  addiu $t3, $t9, 0x888
/* 062D24 80062124 10000004 */  b     .L80062138
/* 062D28 80062128 A60B0AE8 */   sh    $t3, 0xae8($s0)
/* 062D2C 8006212C 860C0AE8 */  lh    $t4, 0xae8($s0)
.L80062130:
/* 062D30 80062130 258DF778 */  addiu $t5, $t4, -0x888
/* 062D34 80062134 A60D0AE8 */  sh    $t5, 0xae8($s0)
.L80062138:
/* 062D38 80062138 860E0AE8 */  lh    $t6, 0xae8($s0)
/* 062D3C 8006213C 862F002E */  lh    $t7, 0x2e($s1)
/* 062D40 80062140 863900C0 */  lh    $t9, 0xc0($s1)
/* 062D44 80062144 01CFC023 */  subu  $t8, $t6, $t7
/* 062D48 80062148 03192023 */  subu  $a0, $t8, $t9
/* 062D4C 8006214C 308BFFFF */  andi  $t3, $a0, 0xffff
/* 062D50 80062150 0C0AE00E */  jal   func_802B8038
/* 062D54 80062154 01602025 */   move  $a0, $t3
/* 062D58 80062158 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 062D5C 8006215C 44814000 */  mtc1  $at, $f8
/* 062D60 80062160 C630001C */  lwc1  $f16, 0x1c($s1)
/* 062D64 80062164 860C0AE8 */  lh    $t4, 0xae8($s0)
/* 062D68 80062168 46080282 */  mul.s $f10, $f0, $f8
/* 062D6C 8006216C 46105480 */  add.s $f18, $f10, $f16
/* 062D70 80062170 E6120AD0 */  swc1  $f18, 0xad0($s0)
/* 062D74 80062174 862D002E */  lh    $t5, 0x2e($s1)
/* 062D78 80062178 862F00C0 */  lh    $t7, 0xc0($s1)
/* 062D7C 8006217C 018D7023 */  subu  $t6, $t4, $t5
/* 062D80 80062180 01CF2023 */  subu  $a0, $t6, $t7
/* 062D84 80062184 3098FFFF */  andi  $t8, $a0, 0xffff
/* 062D88 80062188 0C0AE006 */  jal   func_802B8018
/* 062D8C 8006218C 03002025 */   move  $a0, $t8
/* 062D90 80062190 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 062D94 80062194 44812000 */  mtc1  $at, $f4
/* 062D98 80062198 C6280014 */  lwc1  $f8, 0x14($s1)
/* 062D9C 8006219C 46040182 */  mul.s $f6, $f0, $f4
/* 062DA0 800621A0 46083280 */  add.s $f10, $f6, $f8
/* 062DA4 800621A4 E60A0AC8 */  swc1  $f10, 0xac8($s0)
.L800621A8:
/* 062DA8 800621A8 8FBF002C */  lw    $ra, 0x2c($sp)
.L800621AC:
/* 062DAC 800621AC 8FB00024 */  lw    $s0, 0x24($sp)
/* 062DB0 800621B0 8FB10028 */  lw    $s1, 0x28($sp)
/* 062DB4 800621B4 03E00008 */  jr    $ra
/* 062DB8 800621B8 27BD0050 */   addiu $sp, $sp, 0x50
