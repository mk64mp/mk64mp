glabel func_80283BA4
/* 1271E4 80283BA4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1271E8 80283BA8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1271EC 80283BAC 0C03282E */  jal   func_800CA0B8
/* 1271F0 80283BB0 AFA40018 */   sw    $a0, 0x18($sp)
/* 1271F4 80283BB4 3C0E800E */  lui   $t6, %hi(D_800DC4E8) # $t6, 0x800e
/* 1271F8 80283BB8 8DCEC4E8 */  lw    $t6, %lo(D_800DC4E8)($t6)
/* 1271FC 80283BBC 3C012900 */  lui   $at, (0x29008004 >> 16) # lui $at, 0x2900
/* 127200 80283BC0 34218004 */  ori   $at, (0x29008004 & 0xFFFF) # ori $at, $at, 0x8004
/* 127204 80283BC4 95C50254 */  lhu   $a1, 0x254($t6)
/* 127208 80283BC8 00002025 */  move  $a0, $zero
/* 12720C 80283BCC 00057900 */  sll   $t7, $a1, 4
/* 127210 80283BD0 0C03243D */  jal   func_800C90F4
/* 127214 80283BD4 01E12821 */   addu  $a1, $t7, $at
/* 127218 80283BD8 0C032828 */  jal   func_800CA0A0
/* 12721C 80283BDC 00000000 */   nop   
/* 127220 80283BE0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 127224 80283BE4 27BD0018 */  addiu $sp, $sp, 0x18
/* 127228 80283BE8 03E00008 */  jr    $ra
/* 12722C 80283BEC 00000000 */   nop   
