glabel func_80072B48
/* 073748 80072B48 000470C0 */  sll   $t6, $a0, 3
/* 07374C 80072B4C 01C47023 */  subu  $t6, $t6, $a0
/* 073750 80072B50 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 073754 80072B54 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 073758 80072B58 000E7140 */  sll   $t6, $t6, 5
/* 07375C 80072B5C 01CF1021 */  addu  $v0, $t6, $t7
/* 073760 80072B60 805800CB */  lb    $t8, 0xcb($v0)
/* 073764 80072B64 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 073768 80072B68 AFB00018 */  sw    $s0, 0x18($sp)
/* 07376C 80072B6C 00808025 */  move  $s0, $a0
/* 073770 80072B70 AFBF001C */  sw    $ra, 0x1c($sp)
/* 073774 80072B74 AFA5002C */  sw    $a1, 0x2c($sp)
/* 073778 80072B78 1700000F */  bnez  $t8, .L80072BB8
/* 07377C 80072B7C 00001825 */   move  $v1, $zero
/* 073780 80072B80 24050001 */  li    $a1, 1
/* 073784 80072B84 AFA20020 */  sw    $v0, 0x20($sp)
/* 073788 80072B88 0C01C8E2 */  jal   func_80072388
/* 07378C 80072B8C AFA00024 */   sw    $zero, 0x24($sp)
/* 073790 80072B90 02002025 */  move  $a0, $s0
/* 073794 80072B94 0C01C870 */  jal   func_800721C0
/* 073798 80072B98 3C050008 */   lui   $a1, 8
/* 07379C 80072B9C 8FA20020 */  lw    $v0, 0x20($sp)
/* 0737A0 80072BA0 3C198019 */  lui   $t9, %hi(D_8018D140) # $t9, 0x8019
/* 0737A4 80072BA4 8F39D140 */  lw    $t9, %lo(D_8018D140)($t9)
/* 0737A8 80072BA8 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0737AC 80072BAC 8FA30024 */  lw    $v1, 0x24($sp)
/* 0737B0 80072BB0 A05900D2 */  sb    $t9, 0xd2($v0)
/* 0737B4 80072BB4 AC480050 */  sw    $t0, 0x50($v0)
.L80072BB8:
/* 0737B8 80072BB8 8C490050 */  lw    $t1, 0x50($v0)
/* 0737BC 80072BBC 02002025 */  move  $a0, $s0
/* 0737C0 80072BC0 252AFFFF */  addiu $t2, $t1, -1
/* 0737C4 80072BC4 05410009 */  bgez  $t2, .L80072BEC
/* 0737C8 80072BC8 AC4A0050 */   sw    $t2, 0x50($v0)
/* 0737CC 80072BCC 0C01C87A */  jal   func_800721E8
/* 0737D0 80072BD0 3C050008 */   lui   $a1, 8
/* 0737D4 80072BD4 02002025 */  move  $a0, $s0
/* 0737D8 80072BD8 0C01C8E2 */  jal   func_80072388
/* 0737DC 80072BDC 00002825 */   move  $a1, $zero
/* 0737E0 80072BE0 0C01C922 */  jal   func_80072488
/* 0737E4 80072BE4 02002025 */   move  $a0, $s0
/* 0737E8 80072BE8 24030001 */  li    $v1, 1
.L80072BEC:
/* 0737EC 80072BEC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0737F0 80072BF0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0737F4 80072BF4 27BD0028 */  addiu $sp, $sp, 0x28
/* 0737F8 80072BF8 03E00008 */  jr    $ra
/* 0737FC 80072BFC 00601025 */   move  $v0, $v1
