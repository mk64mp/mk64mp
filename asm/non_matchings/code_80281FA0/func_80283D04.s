glabel func_80283D04
/* 127344 80283D04 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 127348 80283D08 AFA40018 */  sw    $a0, 0x18($sp)
/* 12734C 80283D0C AFBF0014 */  sw    $ra, 0x14($sp)
/* 127350 80283D10 3C044900 */  lui   $a0, (0x49008026 >> 16) # lui $a0, 0x4900
/* 127354 80283D14 0C032384 */  jal   play_sound2
/* 127358 80283D18 34848026 */   ori   $a0, (0x49008026 & 0xFFFF) # ori $a0, $a0, 0x8026
/* 12735C 80283D1C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 127360 80283D20 27BD0018 */  addiu $sp, $sp, 0x18
/* 127364 80283D24 03E00008 */  jr    $ra
/* 127368 80283D28 00000000 */   nop   
