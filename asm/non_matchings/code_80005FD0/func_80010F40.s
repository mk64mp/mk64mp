glabel func_80010F40
/* 011B40 80010F40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 011B44 80010F44 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 011B48 80010F48 3C0144FA */  li    $at, 0x44FA0000 # 2000.000000
/* 011B4C 80010F4C AFBF001C */  sw    $ra, 0x1c($sp)
/* 011B50 80010F50 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 011B54 80010F54 44817000 */  mtc1  $at, $f14
/* 011B58 80010F58 AFA60028 */  sw    $a2, 0x28($sp)
/* 011B5C 80010F5C AFA7002C */  sw    $a3, 0x2c($sp)
/* 011B60 80010F60 0C0AB870 */  jal   func_802AE1C0
/* 011B64 80010F64 C7AC0020 */   lwc1  $f12, 0x20($sp)
/* 011B68 80010F68 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 011B6C 80010F6C 3C048016 */  lui   $a0, %hi(D_80162E70) # $a0, 0x8016
/* 011B70 80010F70 44070000 */  mfc1  $a3, $f0
/* 011B74 80010F74 E7A00024 */  swc1  $f0, 0x24($sp)
/* 011B78 80010F78 24842E70 */  addiu $a0, %lo(D_80162E70) # addiu $a0, $a0, 0x2e70
/* 011B7C 80010F7C 3C053F80 */  lui   $a1, 0x3f80
/* 011B80 80010F80 8FA60020 */  lw    $a2, 0x20($sp)
/* 011B84 80010F84 0C0AB772 */  jal   func_802ADDC8
/* 011B88 80010F88 E7A40010 */   swc1  $f4, 0x10($sp)
/* 011B8C 80010F8C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 011B90 80010F90 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 011B94 80010F94 27BD0020 */  addiu $sp, $sp, 0x20
/* 011B98 80010F98 03E00008 */  jr    $ra
/* 011B9C 80010F9C 00000000 */   nop   
