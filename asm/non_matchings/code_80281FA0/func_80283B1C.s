glabel func_80283B1C
/* 12715C 80283B1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 127160 80283B20 AFA40018 */  sw    $a0, 0x18($sp)
/* 127164 80283B24 AFBF0014 */  sw    $ra, 0x14($sp)
/* 127168 80283B28 3C044900 */  lui   $a0, (0x49008022 >> 16) # lui $a0, 0x4900
/* 12716C 80283B2C 0C032384 */  jal   play_sound2
/* 127170 80283B30 34848022 */   ori   $a0, (0x49008022 & 0xFFFF) # ori $a0, $a0, 0x8022
/* 127174 80283B34 8FBF0014 */  lw    $ra, 0x14($sp)
/* 127178 80283B38 27BD0018 */  addiu $sp, $sp, 0x18
/* 12717C 80283B3C 03E00008 */  jr    $ra
/* 127180 80283B40 00000000 */   nop   
