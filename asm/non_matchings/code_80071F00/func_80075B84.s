glabel func_80075B84
/* 076784 80075B84 000470C0 */  sll   $t6, $a0, 3
/* 076788 80075B88 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 07678C 80075B8C 01C47023 */  subu  $t6, $t6, $a0
/* 076790 80075B90 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 076794 80075B94 AFB00024 */  sw    $s0, 0x24($sp)
/* 076798 80075B98 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 07679C 80075B9C 000E7140 */  sll   $t6, $t6, 5
/* 0767A0 80075BA0 01CF8021 */  addu  $s0, $t6, $t7
/* 0767A4 80075BA4 860200A6 */  lh    $v0, 0xa6($s0)
/* 0767A8 80075BA8 AFB10028 */  sw    $s1, 0x28($sp)
/* 0767AC 80075BAC 00808825 */  move  $s1, $a0
/* 0767B0 80075BB0 10400036 */  beqz  $v0, .L80075C8C
/* 0767B4 80075BB4 AFBF002C */   sw    $ra, 0x2c($sp)
/* 0767B8 80075BB8 24010001 */  li    $at, 1
/* 0767BC 80075BBC 10410007 */  beq   $v0, $at, .L80075BDC
/* 0767C0 80075BC0 24010002 */   li    $at, 2
/* 0767C4 80075BC4 10410009 */  beq   $v0, $at, .L80075BEC
/* 0767C8 80075BC8 24010003 */   li    $at, 3
/* 0767CC 80075BCC 1041002D */  beq   $v0, $at, .L80075C84
/* 0767D0 80075BD0 00000000 */   nop   
/* 0767D4 80075BD4 1000002D */  b     .L80075C8C
/* 0767D8 80075BD8 00000000 */   nop   
.L80075BDC:
/* 0767DC 80075BDC 0C01D6C2 */  jal   func_80075B08
/* 0767E0 80075BE0 02202025 */   move  $a0, $s1
/* 0767E4 80075BE4 10000029 */  b     .L80075C8C
/* 0767E8 80075BE8 00000000 */   nop   
.L80075BEC:
/* 0767EC 80075BEC C604003C */  lwc1  $f4, 0x3c($s0)
/* 0767F0 80075BF0 3C01800F */  lui   $at, %hi(D_800EEAE0)
/* 0767F4 80075BF4 D428EAE0 */  ldc1  $f8, %lo(D_800EEAE0)($at)
/* 0767F8 80075BF8 460021A1 */  cvt.d.s $f6, $f4
/* 0767FC 80075BFC 2604002C */  addiu $a0, $s0, 0x2c
/* 076800 80075C00 46283281 */  sub.d $f10, $f6, $f8
/* 076804 80075C04 3C0542C8 */  lui   $a1, 0x42c8
/* 076808 80075C08 46205420 */  cvt.s.d $f16, $f10
/* 07680C 80075C0C E610003C */  swc1  $f16, 0x3c($s0)
/* 076810 80075C10 0C0103B8 */  jal   func_80040EE0
/* 076814 80075C14 8E06003C */   lw    $a2, 0x3c($s0)
/* 076818 80075C18 3C01800F */  lui   $at, %hi(D_800EEAE8) # $at, 0x800f
/* 07681C 80075C1C C432EAE8 */  lwc1  $f18, %lo(D_800EEAE8)($at)
/* 076820 80075C20 3C063F0C */  lui   $a2, (0x3F0CCCCD >> 16) # lui $a2, 0x3f0c
/* 076824 80075C24 24180001 */  li    $t8, 1
/* 076828 80075C28 AFB80014 */  sw    $t8, 0x14($sp)
/* 07682C 80075C2C 34C6CCCD */  ori   $a2, (0x3F0CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 076830 80075C30 02202025 */  move  $a0, $s1
/* 076834 80075C34 02002825 */  move  $a1, $s0
/* 076838 80075C38 3C073F80 */  lui   $a3, 0x3f80
/* 07683C 80075C3C AFA00018 */  sw    $zero, 0x18($sp)
/* 076840 80075C40 0C01D057 */  jal   func_8007415C
/* 076844 80075C44 E7B20010 */   swc1  $f18, 0x10($sp)
/* 076848 80075C48 24190007 */  li    $t9, 7
/* 07684C 80075C4C AFB90010 */  sw    $t9, 0x10($sp)
/* 076850 80075C50 02202025 */  move  $a0, $s1
/* 076854 80075C54 260500A0 */  addiu $a1, $s0, 0xa0
/* 076858 80075C58 240600FF */  li    $a2, 255
/* 07685C 80075C5C 2407001E */  li    $a3, 30
/* 076860 80075C60 AFA00014 */  sw    $zero, 0x14($sp)
/* 076864 80075C64 0C01CEC0 */  jal   func_80073B00
/* 076868 80075C68 AFA00018 */   sw    $zero, 0x18($sp)
/* 07686C 80075C6C 10400007 */  beqz  $v0, .L80075C8C
/* 076870 80075C70 00000000 */   nop   
/* 076874 80075C74 0C01C922 */  jal   func_80072488
/* 076878 80075C78 02202025 */   move  $a0, $s1
/* 07687C 80075C7C 10000003 */  b     .L80075C8C
/* 076880 80075C80 00000000 */   nop   
.L80075C84:
/* 076884 80075C84 0C01C90A */  jal   func_80072428
/* 076888 80075C88 02202025 */   move  $a0, $s1
.L80075C8C:
/* 07688C 80075C8C 0C022FC6 */  jal   func_8008BF18
/* 076890 80075C90 02202025 */   move  $a0, $s1
/* 076894 80075C94 8FBF002C */  lw    $ra, 0x2c($sp)
/* 076898 80075C98 8FB00024 */  lw    $s0, 0x24($sp)
/* 07689C 80075C9C 8FB10028 */  lw    $s1, 0x28($sp)
/* 0768A0 80075CA0 03E00008 */  jr    $ra
/* 0768A4 80075CA4 27BD0030 */   addiu $sp, $sp, 0x30
