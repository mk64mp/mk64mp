glabel func_8007401C
/* 074C1C 8007401C 000470C0 */  sll   $t6, $a0, 3
/* 074C20 80074020 01C47023 */  subu  $t6, $t6, $a0
/* 074C24 80074024 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 074C28 80074028 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 074C2C 8007402C 000E7140 */  sll   $t6, $t6, 5
/* 074C30 80074030 01CF1021 */  addu  $v0, $t6, $t7
/* 074C34 80074034 805800CD */  lb    $t8, 0xcd($v0)
/* 074C38 80074038 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 074C3C 8007403C 44866000 */  mtc1  $a2, $f12
/* 074C40 80074040 44877000 */  mtc1  $a3, $f14
/* 074C44 80074044 00A03025 */  move  $a2, $a1
/* 074C48 80074048 AFBF0014 */  sw    $ra, 0x14($sp)
/* 074C4C 8007404C AFA50024 */  sw    $a1, 0x24($sp)
/* 074C50 80074050 1700000B */  bnez  $t8, .L80074080
/* 074C54 80074054 00003825 */   move  $a3, $zero
/* 074C58 80074058 E4AC0000 */  swc1  $f12, ($a1)
/* 074C5C 8007405C 8FB90034 */  lw    $t9, 0x34($sp)
/* 074C60 80074060 8FA80038 */  lw    $t0, 0x38($sp)
/* 074C64 80074064 AFA0001C */  sw    $zero, 0x1c($sp)
/* 074C68 80074068 24050001 */  li    $a1, 1
/* 074C6C 8007406C A45900AA */  sh    $t9, 0xaa($v0)
/* 074C70 80074070 0C01CFE4 */  jal   func_80073F90
/* 074C74 80074074 A04800CE */   sb    $t0, 0xce($v0)
/* 074C78 80074078 10000022 */  b     .L80074104
/* 074C7C 8007407C 8FA7001C */   lw    $a3, 0x1c($sp)
.L80074080:
/* 074C80 80074080 844900AA */  lh    $t1, 0xaa($v0)
/* 074C84 80074084 252AFFFF */  addiu $t2, $t1, -1
/* 074C88 80074088 A44A00AA */  sh    $t2, 0xaa($v0)
/* 074C8C 8007408C 844B00AA */  lh    $t3, 0xaa($v0)
/* 074C90 80074090 8FAC0034 */  lw    $t4, 0x34($sp)
/* 074C94 80074094 0563001C */  bgezl $t3, .L80074108
/* 074C98 80074098 8FBF0014 */   lw    $ra, 0x14($sp)
/* 074C9C 8007409C A44C00AA */  sh    $t4, 0xaa($v0)
/* 074CA0 800740A0 C4C40000 */  lwc1  $f4, ($a2)
/* 074CA4 800740A4 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 074CA8 800740A8 46062200 */  add.s $f8, $f4, $f6
/* 074CAC 800740AC E4C80000 */  swc1  $f8, ($a2)
/* 074CB0 800740B0 C4CA0000 */  lwc1  $f10, ($a2)
/* 074CB4 800740B4 460A703C */  c.lt.s $f14, $f10
/* 074CB8 800740B8 00000000 */  nop   
/* 074CBC 800740BC 45020012 */  bc1fl .L80074108
/* 074CC0 800740C0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 074CC4 800740C4 804300CE */  lb    $v1, 0xce($v0)
/* 074CC8 800740C8 00002825 */  move  $a1, $zero
/* 074CCC 800740CC 18600003 */  blez  $v1, .L800740DC
/* 074CD0 800740D0 246DFFFF */   addiu $t5, $v1, -1
/* 074CD4 800740D4 A04D00CE */  sb    $t5, 0xce($v0)
/* 074CD8 800740D8 804300CE */  lb    $v1, 0xce($v0)
.L800740DC:
/* 074CDC 800740DC 54600009 */  bnel  $v1, $zero, .L80074104
/* 074CE0 800740E0 E4CC0000 */   swc1  $f12, ($a2)
/* 074CE4 800740E4 E4CE0000 */  swc1  $f14, ($a2)
/* 074CE8 800740E8 0C01CFE4 */  jal   func_80073F90
/* 074CEC 800740EC AFA40020 */   sw    $a0, 0x20($sp)
/* 074CF0 800740F0 0C01CFEB */  jal   func_80073FAC
/* 074CF4 800740F4 8FA40020 */   lw    $a0, 0x20($sp)
/* 074CF8 800740F8 10000002 */  b     .L80074104
/* 074CFC 800740FC 24070001 */   li    $a3, 1
/* 074D00 80074100 E4CC0000 */  swc1  $f12, ($a2)
.L80074104:
/* 074D04 80074104 8FBF0014 */  lw    $ra, 0x14($sp)
.L80074108:
/* 074D08 80074108 27BD0020 */  addiu $sp, $sp, 0x20
/* 074D0C 8007410C 00E01025 */  move  $v0, $a3
/* 074D10 80074110 03E00008 */  jr    $ra
/* 074D14 80074114 00000000 */   nop   
