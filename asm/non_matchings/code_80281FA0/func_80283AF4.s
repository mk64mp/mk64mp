glabel func_80283AF4
/* 127134 80283AF4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 127138 80283AF8 AFA40018 */  sw    $a0, 0x18($sp)
/* 12713C 80283AFC AFBF0014 */  sw    $ra, 0x14($sp)
/* 127140 80283B00 3C044900 */  lui   $a0, (0x49008021 >> 16) # lui $a0, 0x4900
/* 127144 80283B04 0C032384 */  jal   play_sound2
/* 127148 80283B08 34848021 */   ori   $a0, (0x49008021 & 0xFFFF) # ori $a0, $a0, 0x8021
/* 12714C 80283B0C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 127150 80283B10 27BD0018 */  addiu $sp, $sp, 0x18
/* 127154 80283B14 03E00008 */  jr    $ra
/* 127158 80283B18 00000000 */   nop   
