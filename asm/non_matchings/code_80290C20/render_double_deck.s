glabel render_double_deck
/* 0FE83C 8029522C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FE840 80295230 AFA40018 */  sw    $a0, 0x18($sp)
/* 0FE844 80295234 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0FE848 80295238 3C04800E */  lui   $a0, %hi(D_800DC610) # $a0, 0x800e
/* 0FE84C 8029523C 3C05802C */  lui   $a1, %hi(D_802B87D4) # $a1, 0x802c
/* 0FE850 80295240 84A587D4 */  lh    $a1, %lo(D_802B87D4)($a1)
/* 0FE854 80295244 2484C610 */  addiu $a0, %lo(D_800DC610) # addiu $a0, $a0, -0x39f0
/* 0FE858 80295248 00003025 */  move  $a2, $zero
/* 0FE85C 8029524C 0C0AD759 */  jal   func_802B5D64
/* 0FE860 80295250 24070001 */   li    $a3, 1
/* 0FE864 80295254 3C038015 */  lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 0FE868 80295258 24630298 */  addiu $v1, %lo(gDisplayListHead) # addiu $v1, $v1, 0x298
/* 0FE86C 8029525C 8C620000 */  lw    $v0, ($v1)
/* 0FE870 80295260 3C0FBB00 */  lui   $t7, (0xBB000001 >> 16) # lui $t7, 0xbb00
/* 0FE874 80295264 35EF0001 */  ori   $t7, (0xBB000001 & 0xFFFF) # ori $t7, $t7, 1
/* 0FE878 80295268 244E0008 */  addiu $t6, $v0, 8
/* 0FE87C 8029526C AC6E0000 */  sw    $t6, ($v1)
/* 0FE880 80295270 2418FFFF */  li    $t8, -1
/* 0FE884 80295274 AC580004 */  sw    $t8, 4($v0)
/* 0FE888 80295278 AC4F0000 */  sw    $t7, ($v0)
/* 0FE88C 8029527C 8C620000 */  lw    $v0, ($v1)
/* 0FE890 80295280 3C0AB700 */  lui   $t2, 0xb700
/* 0FE894 80295284 240D0200 */  li    $t5, 512
/* 0FE898 80295288 24590008 */  addiu $t9, $v0, 8
/* 0FE89C 8029528C AC790000 */  sw    $t9, ($v1)
/* 0FE8A0 80295290 AC4D0004 */  sw    $t5, 4($v0)
/* 0FE8A4 80295294 AC4A0000 */  sw    $t2, ($v0)
/* 0FE8A8 80295298 8C620000 */  lw    $v0, ($v1)
/* 0FE8AC 8029529C 3C0BB600 */  lui   $t3, 0xb600
/* 0FE8B0 802952A0 3C0F0002 */  lui   $t7, 2
/* 0FE8B4 802952A4 244E0008 */  addiu $t6, $v0, 8
/* 0FE8B8 802952A8 AC6E0000 */  sw    $t6, ($v1)
/* 0FE8BC 802952AC AC4F0004 */  sw    $t7, 4($v0)
/* 0FE8C0 802952B0 AC4B0000 */  sw    $t3, ($v0)
/* 0FE8C4 802952B4 8C620000 */  lw    $v0, ($v1)
/* 0FE8C8 802952B8 240C2000 */  li    $t4, 8192
/* 0FE8CC 802952BC 3C0E0700 */  lui   $t6, (0x07000738 >> 16) # lui $t6, 0x700
/* 0FE8D0 802952C0 24580008 */  addiu $t8, $v0, 8
/* 0FE8D4 802952C4 AC780000 */  sw    $t8, ($v1)
/* 0FE8D8 802952C8 AC4C0004 */  sw    $t4, 4($v0)
/* 0FE8DC 802952CC AC4B0000 */  sw    $t3, ($v0)
/* 0FE8E0 802952D0 8C620000 */  lw    $v0, ($v1)
/* 0FE8E4 802952D4 35CE0738 */  ori   $t6, (0x07000738 & 0xFFFF) # ori $t6, $t6, 0x738
/* 0FE8E8 802952D8 3C0D0600 */  lui   $t5, 0x600
/* 0FE8EC 802952DC 24590008 */  addiu $t9, $v0, 8
/* 0FE8F0 802952E0 AC790000 */  sw    $t9, ($v1)
/* 0FE8F4 802952E4 AC4E0004 */  sw    $t6, 4($v0)
/* 0FE8F8 802952E8 AC4D0000 */  sw    $t5, ($v0)
/* 0FE8FC 802952EC 8C620000 */  lw    $v0, ($v1)
/* 0FE900 802952F0 244F0008 */  addiu $t7, $v0, 8
/* 0FE904 802952F4 AC6F0000 */  sw    $t7, ($v1)
/* 0FE908 802952F8 AC4C0004 */  sw    $t4, 4($v0)
/* 0FE90C 802952FC AC4A0000 */  sw    $t2, ($v0)
/* 0FE910 80295300 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0FE914 80295304 27BD0018 */  addiu $sp, $sp, 0x18
/* 0FE918 80295308 03E00008 */  jr    $ra
/* 0FE91C 8029530C 00000000 */   nop   
