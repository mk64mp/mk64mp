glabel func_80061094
/* 061C94 80061094 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 061C98 80061098 AFA50034 */  sw    $a1, 0x34($sp)
/* 061C9C 8006109C 87AE0036 */  lh    $t6, 0x36($sp)
/* 061CA0 800610A0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 061CA4 800610A4 AFA60038 */  sw    $a2, 0x38($sp)
/* 061CA8 800610A8 15C0001D */  bnez  $t6, .L80061120
/* 061CAC 800610AC AFA7003C */   sw    $a3, 0x3c($sp)
/* 061CB0 800610B0 44800000 */  mtc1  $zero, $f0
/* 061CB4 800610B4 000E78C0 */  sll   $t7, $t6, 3
/* 061CB8 800610B8 01EE7821 */  addu  $t7, $t7, $t6
/* 061CBC 800610BC 000F78C0 */  sll   $t7, $t7, 3
/* 061CC0 800610C0 008F1021 */  addu  $v0, $a0, $t7
/* 061CC4 800610C4 24450258 */  addiu $a1, $v0, 0x258
/* 061CC8 800610C8 44060000 */  mfc1  $a2, $f0
/* 061CCC 800610CC 44070000 */  mfc1  $a3, $f0
/* 061CD0 800610D0 AFA50028 */  sw    $a1, 0x28($sp)
/* 061CD4 800610D4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 061CD8 800610D8 AFA00014 */  sw    $zero, 0x14($sp)
/* 061CDC 800610DC AFA00018 */  sw    $zero, 0x18($sp)
/* 061CE0 800610E0 0C0175E5 */  jal   func_8005D794
/* 061CE4 800610E4 E7A00010 */   swc1  $f0, 0x10($sp)
/* 061CE8 800610E8 3C064073 */  lui   $a2, (0x40733333 >> 16) # lui $a2, 0x4073
/* 061CEC 800610EC 34C63333 */  ori   $a2, (0x40733333 & 0xFFFF) # ori $a2, $a2, 0x3333
/* 061CF0 800610F0 8FA40028 */  lw    $a0, 0x28($sp)
/* 061CF4 800610F4 0C0175F6 */  jal   func_8005D7D8
/* 061CF8 800610F8 24050006 */   li    $a1, 6
/* 061CFC 800610FC 3C0500FF */  lui   $a1, (0x00FFFFFF >> 16) # lui $a1, 0xff
/* 061D00 80061100 34A5FFFF */  ori   $a1, (0x00FFFFFF & 0xFFFF) # ori $a1, $a1, 0xffff
/* 061D04 80061104 8FA40028 */  lw    $a0, 0x28($sp)
/* 061D08 80061108 0C017600 */  jal   func_8005D800
/* 061D0C 8006110C 240600FF */   li    $a2, 255
/* 061D10 80061110 8FA2002C */  lw    $v0, 0x2c($sp)
/* 061D14 80061114 A4400290 */  sh    $zero, 0x290($v0)
/* 061D18 80061118 A4400292 */  sh    $zero, 0x292($v0)
/* 061D1C 8006111C A4400294 */  sh    $zero, 0x294($v0)
.L80061120:
/* 061D20 80061120 8FBF0024 */  lw    $ra, 0x24($sp)
/* 061D24 80061124 27BD0030 */  addiu $sp, $sp, 0x30
/* 061D28 80061128 03E00008 */  jr    $ra
/* 061D2C 8006112C 00000000 */   nop   
