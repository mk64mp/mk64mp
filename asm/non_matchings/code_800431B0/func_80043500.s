glabel func_80043500
/* 044100 80043500 44866000 */  mtc1  $a2, $f12
/* 044104 80043504 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 044108 80043508 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04410C 8004350C 44066000 */  mfc1  $a2, $f12
/* 044110 80043510 0C010B80 */  jal   func_80042E00
/* 044114 80043514 AFA70024 */   sw    $a3, 0x24($sp)
/* 044118 80043518 3C038015 */  lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 04411C 8004351C 24630298 */  addiu $v1, %lo(gDisplayListHead) # addiu $v1, $v1, 0x298
/* 044120 80043520 8C620000 */  lw    $v0, ($v1)
/* 044124 80043524 3C0F0D00 */  lui   $t7, %hi(D_0D007850) # $t7, 0xd00
/* 044128 80043528 3C080600 */  lui   $t0, 0x600
/* 04412C 8004352C 244E0008 */  addiu $t6, $v0, 8
/* 044130 80043530 AC6E0000 */  sw    $t6, ($v1)
/* 044134 80043534 25EF7850 */  addiu $t7, %lo(D_0D007850) # addiu $t7, $t7, 0x7850
/* 044138 80043538 AC4F0004 */  sw    $t7, 4($v0)
/* 04413C 8004353C AC480000 */  sw    $t0, ($v0)
/* 044140 80043540 8C620000 */  lw    $v0, ($v1)
/* 044144 80043544 3C19B600 */  lui   $t9, 0xb600
/* 044148 80043548 24093000 */  li    $t1, 12288
/* 04414C 8004354C 24580008 */  addiu $t8, $v0, 8
/* 044150 80043550 AC780000 */  sw    $t8, ($v1)
/* 044154 80043554 AC490004 */  sw    $t1, 4($v0)
/* 044158 80043558 AC590000 */  sw    $t9, ($v0)
/* 04415C 8004355C 8C620000 */  lw    $v0, ($v1)
/* 044160 80043560 240E2000 */  li    $t6, 8192
/* 044164 80043564 3C0DB700 */  lui   $t5, 0xb700
/* 044168 80043568 244A0008 */  addiu $t2, $v0, 8
/* 04416C 8004356C AC6A0000 */  sw    $t2, ($v1)
/* 044170 80043570 AC480000 */  sw    $t0, ($v0)
/* 044174 80043574 8FAB0024 */  lw    $t3, 0x24($sp)
/* 044178 80043578 AC4B0004 */  sw    $t3, 4($v0)
/* 04417C 8004357C 8C620000 */  lw    $v0, ($v1)
/* 044180 80043580 244C0008 */  addiu $t4, $v0, 8
/* 044184 80043584 AC6C0000 */  sw    $t4, ($v1)
/* 044188 80043588 AC4E0004 */  sw    $t6, 4($v0)
/* 04418C 8004358C AC4D0000 */  sw    $t5, ($v0)
/* 044190 80043590 8FBF0014 */  lw    $ra, 0x14($sp)
/* 044194 80043594 27BD0018 */  addiu $sp, $sp, 0x18
/* 044198 80043598 03E00008 */  jr    $ra
/* 04419C 8004359C 00000000 */   nop   
