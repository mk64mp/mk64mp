glabel func_802994D4
/* 102AE4 802994D4 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 102AE8 802994D8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 102AEC 802994DC AFB00020 */  sw    $s0, 0x20($sp)
/* 102AF0 802994E0 AFA50054 */  sw    $a1, 0x54($sp)
/* 102AF4 802994E4 84C20002 */  lh    $v0, 2($a2)
/* 102AF8 802994E8 00C08025 */  move  $s0, $a2
/* 102AFC 802994EC 24C50018 */  addiu $a1, $a2, 0x18
/* 102B00 802994F0 304E0800 */  andi  $t6, $v0, 0x800
/* 102B04 802994F4 15C00064 */  bnez  $t6, .L80299688
/* 102B08 802994F8 24070000 */   li    $a3, 0
/* 102B0C 802994FC 3C0F800E */  lui   $t7, %hi(camera1) # $t7, 0x800e
/* 102B10 80299500 8DEFDB40 */  lw    $t7, %lo(camera1)($t7)
/* 102B14 80299504 240100B8 */  li    $at, 184
/* 102B18 80299508 94860026 */  lhu   $a2, 0x26($a0)
/* 102B1C 8029950C 008FC023 */  subu  $t8, $a0, $t7
/* 102B20 80299510 0301001A */  div   $zero, $t8, $at
/* 102B24 80299514 0000C812 */  mflo  $t9
/* 102B28 80299518 00195880 */  sll   $t3, $t9, 2
/* 102B2C 8029951C 3C018015 */  lui   $at, %hi(D_80150130)
/* 102B30 80299520 002B0821 */  addu  $at, $at, $t3
/* 102B34 80299524 C4240130 */  lwc1  $f4, %lo(D_80150130)($at)
/* 102B38 80299528 3C01802C */  lui   $at, %hi(D_802B9668) # $at, 0x802c
/* 102B3C 8029952C C4269668 */  lwc1  $f6, %lo(D_802B9668)($at)
/* 102B40 80299530 AFA50028 */  sw    $a1, 0x28($sp)
/* 102B44 80299534 A7A2004A */  sh    $v0, 0x4a($sp)
/* 102B48 80299538 E7A40010 */  swc1  $f4, 0x10($sp)
/* 102B4C 8029953C 0C0AE034 */  jal   func_802B80D0
/* 102B50 80299540 E7A60014 */   swc1  $f6, 0x14($sp)
/* 102B54 80299544 44804000 */  mtc1  $zero, $f8
/* 102B58 80299548 87A2004A */  lh    $v0, 0x4a($sp)
/* 102B5C 8029954C 8FA70054 */  lw    $a3, 0x54($sp)
/* 102B60 80299550 4608003C */  c.lt.s $f0, $f8
/* 102B64 80299554 304C0400 */  andi  $t4, $v0, 0x400
/* 102B68 80299558 4503004C */  bc1tl .L8029968C
/* 102B6C 8029955C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 102B70 80299560 1580000B */  bnez  $t4, .L80299590
/* 102B74 80299564 3C01802C */   lui   $at, %hi(D_802B966C) # $at, 0x802c
/* 102B78 80299568 C42A966C */  lwc1  $f10, %lo(D_802B966C)($at)
/* 102B7C 8029956C 8FA40028 */  lw    $a0, 0x28($sp)
/* 102B80 80299570 26050010 */  addiu $a1, $s0, 0x10
/* 102B84 80299574 460A003C */  c.lt.s $f0, $f10
/* 102B88 80299578 3C064033 */  lui   $a2, (0x40333333 >> 16) # lui $a2, 0x4033
/* 102B8C 8029957C 45020005 */  bc1fl .L80299594
/* 102B90 80299580 C6100018 */   lwc1  $f16, 0x18($s0)
/* 102B94 80299584 0C0A5E53 */  jal   func_8029794C
/* 102B98 80299588 34C63333 */   ori   $a2, (0x40333333 & 0xFFFF) # ori $a2, $a2, 0x3333
/* 102B9C 8029958C 8FA70054 */  lw    $a3, 0x54($sp)
.L80299590:
/* 102BA0 80299590 C6100018 */  lwc1  $f16, 0x18($s0)
.L80299594:
/* 102BA4 80299594 00E02025 */  move  $a0, $a3
/* 102BA8 80299598 00002825 */  move  $a1, $zero
/* 102BAC 8029959C E4F00030 */  swc1  $f16, 0x30($a3)
/* 102BB0 802995A0 C612001C */  lwc1  $f18, 0x1c($s0)
/* 102BB4 802995A4 E4F20034 */  swc1  $f18, 0x34($a3)
/* 102BB8 802995A8 C6040020 */  lwc1  $f4, 0x20($s0)
/* 102BBC 802995AC 0C0AD3FE */  jal   func_802B4FF8
/* 102BC0 802995B0 E4E40038 */   swc1  $f4, 0x38($a3)
/* 102BC4 802995B4 10400034 */  beqz  $v0, .L80299688
/* 102BC8 802995B8 3C038015 */   lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 102BCC 802995BC 24630298 */  addiu $v1, %lo(gDisplayListHead) # addiu $v1, $v1, 0x298
/* 102BD0 802995C0 8C620000 */  lw    $v0, ($v1)
/* 102BD4 802995C4 3C0F0D00 */  lui   $t7, %hi(D_0D004C68) # $t7, 0xd00
/* 102BD8 802995C8 25EF4C68 */  addiu $t7, %lo(D_0D004C68) # addiu $t7, $t7, 0x4c68
/* 102BDC 802995CC 244D0008 */  addiu $t5, $v0, 8
/* 102BE0 802995D0 AC6D0000 */  sw    $t5, ($v1)
/* 102BE4 802995D4 3C0EFD10 */  lui   $t6, 0xfd10
/* 102BE8 802995D8 AC4E0000 */  sw    $t6, ($v0)
/* 102BEC 802995DC AC4F0004 */  sw    $t7, 4($v0)
/* 102BF0 802995E0 8C620000 */  lw    $v0, ($v1)
/* 102BF4 802995E4 3C19E800 */  lui   $t9, 0xe800
/* 102BF8 802995E8 3C0CF500 */  lui   $t4, (0xF5000100 >> 16) # lui $t4, 0xf500
/* 102BFC 802995EC 24580008 */  addiu $t8, $v0, 8
/* 102C00 802995F0 AC780000 */  sw    $t8, ($v1)
/* 102C04 802995F4 AC400004 */  sw    $zero, 4($v0)
/* 102C08 802995F8 AC590000 */  sw    $t9, ($v0)
/* 102C0C 802995FC 8C620000 */  lw    $v0, ($v1)
/* 102C10 80299600 358C0100 */  ori   $t4, (0xF5000100 & 0xFFFF) # ori $t4, $t4, 0x100
/* 102C14 80299604 3C0D0700 */  lui   $t5, 0x700
/* 102C18 80299608 244B0008 */  addiu $t3, $v0, 8
/* 102C1C 8029960C AC6B0000 */  sw    $t3, ($v1)
/* 102C20 80299610 AC4D0004 */  sw    $t5, 4($v0)
/* 102C24 80299614 AC4C0000 */  sw    $t4, ($v0)
/* 102C28 80299618 8C620000 */  lw    $v0, ($v1)
/* 102C2C 8029961C 3C0FE600 */  lui   $t7, 0xe600
/* 102C30 80299620 3C0B073F */  lui   $t3, (0x073FC000 >> 16) # lui $t3, 0x73f
/* 102C34 80299624 244E0008 */  addiu $t6, $v0, 8
/* 102C38 80299628 AC6E0000 */  sw    $t6, ($v1)
/* 102C3C 8029962C AC400004 */  sw    $zero, 4($v0)
/* 102C40 80299630 AC4F0000 */  sw    $t7, ($v0)
/* 102C44 80299634 8C620000 */  lw    $v0, ($v1)
/* 102C48 80299638 356BC000 */  ori   $t3, (0x073FC000 & 0xFFFF) # ori $t3, $t3, 0xc000
/* 102C4C 8029963C 3C19F000 */  lui   $t9, 0xf000
/* 102C50 80299640 24580008 */  addiu $t8, $v0, 8
/* 102C54 80299644 AC780000 */  sw    $t8, ($v1)
/* 102C58 80299648 AC4B0004 */  sw    $t3, 4($v0)
/* 102C5C 8029964C AC590000 */  sw    $t9, ($v0)
/* 102C60 80299650 8C620000 */  lw    $v0, ($v1)
/* 102C64 80299654 3C0DE700 */  lui   $t5, 0xe700
/* 102C68 80299658 3C180601 */  lui   $t8, %hi(D_0600D4A0) # $t8, 0x601
/* 102C6C 8029965C 244C0008 */  addiu $t4, $v0, 8
/* 102C70 80299660 AC6C0000 */  sw    $t4, ($v1)
/* 102C74 80299664 AC400004 */  sw    $zero, 4($v0)
/* 102C78 80299668 AC4D0000 */  sw    $t5, ($v0)
/* 102C7C 8029966C 8C620000 */  lw    $v0, ($v1)
/* 102C80 80299670 2718D4A0 */  addiu $t8, %lo(D_0600D4A0) # addiu $t8, $t8, -0x2b60
/* 102C84 80299674 3C0F0600 */  lui   $t7, 0x600
/* 102C88 80299678 244E0008 */  addiu $t6, $v0, 8
/* 102C8C 8029967C AC6E0000 */  sw    $t6, ($v1)
/* 102C90 80299680 AC580004 */  sw    $t8, 4($v0)
/* 102C94 80299684 AC4F0000 */  sw    $t7, ($v0)
.L80299688:
/* 102C98 80299688 8FBF0024 */  lw    $ra, 0x24($sp)
.L8029968C:
/* 102C9C 8029968C 8FB00020 */  lw    $s0, 0x20($sp)
/* 102CA0 80299690 27BD0050 */  addiu $sp, $sp, 0x50
/* 102CA4 80299694 03E00008 */  jr    $ra
/* 102CA8 80299698 00000000 */   nop   
