glabel func_800148C4
/* 0154C4 800148C4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0154C8 800148C8 3C014148 */  li    $at, 0x41480000 # 12.500000
/* 0154CC 800148CC 44812000 */  mtc1  $at, $f4
/* 0154D0 800148D0 3C0F5101 */  lui   $t7, (0x51018003 >> 16) # lui $t7, 0x5101
/* 0154D4 800148D4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0154D8 800148D8 35EF8003 */  ori   $t7, (0x51018003 & 0xFFFF) # ori $t7, $t7, 0x8003
/* 0154DC 800148DC 3C068016 */  lui   $a2, %hi(D_80163818) # $a2, 0x8016
/* 0154E0 800148E0 240E0007 */  li    $t6, 7
/* 0154E4 800148E4 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0154E8 800148E8 24C63818 */  addiu $a2, %lo(D_80163818) # addiu $a2, $a2, 0x3818
/* 0154EC 800148EC AFAF0018 */  sw    $t7, 0x18($sp)
/* 0154F0 800148F0 3C07425C */  lui   $a3, 0x425c
/* 0154F4 800148F4 0C004FDF */  jal   func_80013F7C
/* 0154F8 800148F8 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0154FC 800148FC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 015500 80014900 27BD0028 */  addiu $sp, $sp, 0x28
/* 015504 80014904 03E00008 */  jr    $ra
/* 015508 80014908 00000000 */   nop   
