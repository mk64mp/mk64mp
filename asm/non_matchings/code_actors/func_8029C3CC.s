glabel func_8029C3CC
/* 1059DC 8029C3CC 3C0E800E */  lui   $t6, %hi(camera1) # $t6, 0x800e
/* 1059E0 8029C3D0 8DCEDB40 */  lw    $t6, %lo(camera1)($t6)
/* 1059E4 8029C3D4 240100B8 */  li    $at, 184
/* 1059E8 8029C3D8 27BDFE98 */  addiu $sp, $sp, -0x168
/* 1059EC 8029C3DC 008E7823 */  subu  $t7, $a0, $t6
/* 1059F0 8029C3E0 01E1001A */  div   $zero, $t7, $at
/* 1059F4 8029C3E4 0000C012 */  mflo  $t8
/* 1059F8 8029C3E8 0018C880 */  sll   $t9, $t8, 2
/* 1059FC 8029C3EC 3C018015 */  lui   $at, %hi(D_80150130)
/* 105A00 8029C3F0 00390821 */  addu  $at, $at, $t9
/* 105A04 8029C3F4 C4240130 */  lwc1  $f4, %lo(D_80150130)($at)
/* 105A08 8029C3F8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 105A0C 8029C3FC AFB00020 */  sw    $s0, 0x20($sp)
/* 105A10 8029C400 AFA5016C */  sw    $a1, 0x16c($sp)
/* 105A14 8029C404 3C01802C */  lui   $at, %hi(D_802B9740) # $at, 0x802c
/* 105A18 8029C408 C4269740 */  lwc1  $f6, %lo(D_802B9740)($at)
/* 105A1C 8029C40C 94860026 */  lhu   $a2, 0x26($a0)
/* 105A20 8029C410 24A50018 */  addiu $a1, $a1, 0x18
/* 105A24 8029C414 3C0744FD */  lui   $a3, (0x44FD2000 >> 16) # lui $a3, 0x44fd
/* 105A28 8029C418 34E72000 */  ori   $a3, (0x44FD2000 & 0xFFFF) # ori $a3, $a3, 0x2000
/* 105A2C 8029C41C AFA5002C */  sw    $a1, 0x2c($sp)
/* 105A30 8029C420 E7A40010 */  swc1  $f4, 0x10($sp)
/* 105A34 8029C424 0C0AE034 */  jal   func_802B80D0
/* 105A38 8029C428 E7A60014 */   swc1  $f6, 0x14($sp)
/* 105A3C 8029C42C 44804000 */  mtc1  $zero, $f8
/* 105A40 8029C430 3C108015 */  lui   $s0, %hi(gDisplayListHead) # $s0, 0x8015
/* 105A44 8029C434 8FA5002C */  lw    $a1, 0x2c($sp)
/* 105A48 8029C438 4608003C */  c.lt.s $f0, $f8
/* 105A4C 8029C43C 46000086 */  mov.s $f2, $f0
/* 105A50 8029C440 26100298 */  addiu $s0, %lo(gDisplayListHead) # addiu $s0, $s0, 0x298
/* 105A54 8029C444 3C09B600 */  lui   $t1, 0xb600
/* 105A58 8029C448 4503018D */  bc1tl .L8029CA80
/* 105A5C 8029C44C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105A60 8029C450 8E020000 */  lw    $v0, ($s0)
/* 105A64 8029C454 3C0A0002 */  lui   $t2, 2
/* 105A68 8029C458 27A40128 */  addiu $a0, $sp, 0x128
/* 105A6C 8029C45C 24480008 */  addiu $t0, $v0, 8
/* 105A70 8029C460 AE080000 */  sw    $t0, ($s0)
/* 105A74 8029C464 AC4A0004 */  sw    $t2, 4($v0)
/* 105A78 8029C468 AC490000 */  sw    $t1, ($v0)
/* 105A7C 8029C46C 8FA6016C */  lw    $a2, 0x16c($sp)
/* 105A80 8029C470 E7A20098 */  swc1  $f2, 0x98($sp)
/* 105A84 8029C474 0C0AD7DD */  jal   func_802B5F74
/* 105A88 8029C478 24C60010 */   addiu $a2, $a2, 0x10
/* 105A8C 8029C47C 27A40128 */  addiu $a0, $sp, 0x128
/* 105A90 8029C480 0C0AD3FE */  jal   func_802B4FF8
/* 105A94 8029C484 00002825 */   move  $a1, $zero
/* 105A98 8029C488 1040017C */  beqz  $v0, .L8029CA7C
/* 105A9C 8029C48C C7A20098 */   lwc1  $f2, 0x98($sp)
/* 105AA0 8029C490 3C01802C */  lui   $at, %hi(D_802B9744) # $at, 0x802c
/* 105AA4 8029C494 C42A9744 */  lwc1  $f10, %lo(D_802B9744)($at)
/* 105AA8 8029C498 3C070600 */  lui   $a3, 0x600
/* 105AAC 8029C49C 3C01802C */  lui   $at, %hi(D_802B9748) # $at, 0x802c
/* 105AB0 8029C4A0 460A103C */  c.lt.s $f2, $f10
/* 105AB4 8029C4A4 00000000 */  nop   
/* 105AB8 8029C4A8 45000010 */  bc1f  .L8029C4EC
/* 105ABC 8029C4AC 00000000 */   nop   
/* 105AC0 8029C4B0 8E020000 */  lw    $v0, ($s0)
/* 105AC4 8029C4B4 3C0C0602 */  lui   $t4, %hi(D_06020A20) # $t4, 0x602
/* 105AC8 8029C4B8 258C0A20 */  addiu $t4, %lo(D_06020A20) # addiu $t4, $t4, 0xa20
/* 105ACC 8029C4BC 244B0008 */  addiu $t3, $v0, 8
/* 105AD0 8029C4C0 AE0B0000 */  sw    $t3, ($s0)
/* 105AD4 8029C4C4 AC4C0004 */  sw    $t4, 4($v0)
/* 105AD8 8029C4C8 AC470000 */  sw    $a3, ($v0)
/* 105ADC 8029C4CC 8E020000 */  lw    $v0, ($s0)
/* 105AE0 8029C4D0 3C0E0602 */  lui   $t6, %hi(D_06020A08) # $t6, 0x602
/* 105AE4 8029C4D4 25CE0A08 */  addiu $t6, %lo(D_06020A08) # addiu $t6, $t6, 0xa08
/* 105AE8 8029C4D8 244D0008 */  addiu $t5, $v0, 8
/* 105AEC 8029C4DC AE0D0000 */  sw    $t5, ($s0)
/* 105AF0 8029C4E0 AC4E0004 */  sw    $t6, 4($v0)
/* 105AF4 8029C4E4 10000027 */  b     .L8029C584
/* 105AF8 8029C4E8 AC470000 */   sw    $a3, ($v0)
.L8029C4EC:
/* 105AFC 8029C4EC C4309748 */  lwc1  $f16, %lo(D_802B9748)($at)
/* 105B00 8029C4F0 3C190602 */  lui   $t9, %hi(D_06021550) # $t9, 0x602
/* 105B04 8029C4F4 3C0D0602 */  lui   $t5, %hi(D_06021C90) # $t5, 0x602
/* 105B08 8029C4F8 4610103C */  c.lt.s $f2, $f16
/* 105B0C 8029C4FC 27391550 */  addiu $t9, %lo(D_06021550) # addiu $t9, $t9, 0x1550
/* 105B10 8029C500 3C180600 */  lui   $t8, 0x600
/* 105B14 8029C504 25AD1C90 */  addiu $t5, %lo(D_06021C90) # addiu $t5, $t5, 0x1c90
/* 105B18 8029C508 45000010 */  bc1f  .L8029C54C
/* 105B1C 8029C50C 3C0C0600 */   lui   $t4, 0x600
/* 105B20 8029C510 8E020000 */  lw    $v0, ($s0)
/* 105B24 8029C514 3C0A0602 */  lui   $t2, %hi(D_06021220) # $t2, 0x602
/* 105B28 8029C518 254A1220 */  addiu $t2, %lo(D_06021220) # addiu $t2, $t2, 0x1220
/* 105B2C 8029C51C 244F0008 */  addiu $t7, $v0, 8
/* 105B30 8029C520 AE0F0000 */  sw    $t7, ($s0)
/* 105B34 8029C524 AC590004 */  sw    $t9, 4($v0)
/* 105B38 8029C528 AC580000 */  sw    $t8, ($v0)
/* 105B3C 8029C52C 8E020000 */  lw    $v0, ($s0)
/* 105B40 8029C530 3C090600 */  lui   $t1, 0x600
/* 105B44 8029C534 3C070600 */  lui   $a3, 0x600
/* 105B48 8029C538 24480008 */  addiu $t0, $v0, 8
/* 105B4C 8029C53C AE080000 */  sw    $t0, ($s0)
/* 105B50 8029C540 AC4A0004 */  sw    $t2, 4($v0)
/* 105B54 8029C544 1000000F */  b     .L8029C584
/* 105B58 8029C548 AC490000 */   sw    $t1, ($v0)
.L8029C54C:
/* 105B5C 8029C54C 8E020000 */  lw    $v0, ($s0)
/* 105B60 8029C550 3C180602 */  lui   $t8, %hi(D_06021A80) # $t8, 0x602
/* 105B64 8029C554 27181A80 */  addiu $t8, %lo(D_06021A80) # addiu $t8, $t8, 0x1a80
/* 105B68 8029C558 244B0008 */  addiu $t3, $v0, 8
/* 105B6C 8029C55C AE0B0000 */  sw    $t3, ($s0)
/* 105B70 8029C560 AC4D0004 */  sw    $t5, 4($v0)
/* 105B74 8029C564 AC4C0000 */  sw    $t4, ($v0)
/* 105B78 8029C568 8E020000 */  lw    $v0, ($s0)
/* 105B7C 8029C56C 3C0F0600 */  lui   $t7, 0x600
/* 105B80 8029C570 3C070600 */  lui   $a3, 0x600
/* 105B84 8029C574 244E0008 */  addiu $t6, $v0, 8
/* 105B88 8029C578 AE0E0000 */  sw    $t6, ($s0)
/* 105B8C 8029C57C AC580004 */  sw    $t8, 4($v0)
/* 105B90 8029C580 AC4F0000 */  sw    $t7, ($v0)
.L8029C584:
/* 105B94 8029C584 3C01802C */  lui   $at, %hi(D_802B974C) # $at, 0x802c
/* 105B98 8029C588 C432974C */  lwc1  $f18, %lo(D_802B974C)($at)
/* 105B9C 8029C58C 4602903C */  c.lt.s $f18, $f2
/* 105BA0 8029C590 00000000 */  nop   
/* 105BA4 8029C594 4503013A */  bc1tl .L8029CA80
/* 105BA8 8029C598 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105BAC 8029C59C 8E020000 */  lw    $v0, ($s0)
/* 105BB0 8029C5A0 3C08B600 */  lui   $t0, 0xb600
/* 105BB4 8029C5A4 24092000 */  li    $t1, 8192
/* 105BB8 8029C5A8 24590008 */  addiu $t9, $v0, 8
/* 105BBC 8029C5AC AE190000 */  sw    $t9, ($s0)
/* 105BC0 8029C5B0 AC490004 */  sw    $t1, 4($v0)
/* 105BC4 8029C5B4 AC480000 */  sw    $t0, ($v0)
/* 105BC8 8029C5B8 8E020000 */  lw    $v0, ($s0)
/* 105BCC 8029C5BC 3C0B0602 */  lui   $t3, %hi(D_06022D28) # $t3, 0x602
/* 105BD0 8029C5C0 256B2D28 */  addiu $t3, %lo(D_06022D28) # addiu $t3, $t3, 0x2d28
/* 105BD4 8029C5C4 244A0008 */  addiu $t2, $v0, 8
/* 105BD8 8029C5C8 AE0A0000 */  sw    $t2, ($s0)
/* 105BDC 8029C5CC AC4B0004 */  sw    $t3, 4($v0)
/* 105BE0 8029C5D0 AC470000 */  sw    $a3, ($v0)
/* 105BE4 8029C5D4 8FAC016C */  lw    $t4, 0x16c($sp)
/* 105BE8 8029C5D8 27A40128 */  addiu $a0, $sp, 0x128
/* 105BEC 8029C5DC 0C0AD677 */  jal   func_802B59DC
/* 105BF0 8029C5E0 85850006 */   lh    $a1, 6($t4)
/* 105BF4 8029C5E4 27A4011C */  addiu $a0, $sp, 0x11c
/* 105BF8 8029C5E8 3C054188 */  lui   $a1, 0x4188
/* 105BFC 8029C5EC 3C0640C0 */  lui   $a2, 0x40c0
/* 105C00 8029C5F0 0C0AD4A7 */  jal   load_giant_egg
/* 105C04 8029C5F4 3C0741E0 */   lui   $a3, 0x41e0
/* 105C08 8029C5F8 27A400DC */  addiu $a0, $sp, 0xdc
/* 105C0C 8029C5FC 0C0AD548 */  jal   func_802B5520
/* 105C10 8029C600 27A5011C */   addiu $a1, $sp, 0x11c
/* 105C14 8029C604 27A4009C */  addiu $a0, $sp, 0x9c
/* 105C18 8029C608 27A50128 */  addiu $a1, $sp, 0x128
/* 105C1C 8029C60C 0C0ADC73 */  jal   func_802B71CC
/* 105C20 8029C610 27A600DC */   addiu $a2, $sp, 0xdc
/* 105C24 8029C614 27A4009C */  addiu $a0, $sp, 0x9c
/* 105C28 8029C618 0C0AD3FE */  jal   func_802B4FF8
/* 105C2C 8029C61C 24050003 */   li    $a1, 3
/* 105C30 8029C620 10400116 */  beqz  $v0, .L8029CA7C
/* 105C34 8029C624 3C0E0600 */   lui   $t6, 0x600
/* 105C38 8029C628 8E020000 */  lw    $v0, ($s0)
/* 105C3C 8029C62C 3C070602 */  lui   $a3, %hi(D_06022DB8) # $a3, 0x602
/* 105C40 8029C630 24E72DB8 */  addiu $a3, %lo(D_06022DB8) # addiu $a3, $a3, 0x2db8
/* 105C44 8029C634 244D0008 */  addiu $t5, $v0, 8
/* 105C48 8029C638 AE0D0000 */  sw    $t5, ($s0)
/* 105C4C 8029C63C AC470004 */  sw    $a3, 4($v0)
/* 105C50 8029C640 AC4E0000 */  sw    $t6, ($v0)
/* 105C54 8029C644 8E020000 */  lw    $v0, ($s0)
/* 105C58 8029C648 3C18BD00 */  lui   $t8, 0xbd00
/* 105C5C 8029C64C 27A40128 */  addiu $a0, $sp, 0x128
/* 105C60 8029C650 244F0008 */  addiu $t7, $v0, 8
/* 105C64 8029C654 AE0F0000 */  sw    $t7, ($s0)
/* 105C68 8029C658 AC400004 */  sw    $zero, 4($v0)
/* 105C6C 8029C65C AC580000 */  sw    $t8, ($v0)
/* 105C70 8029C660 8FB9016C */  lw    $t9, 0x16c($sp)
/* 105C74 8029C664 87250006 */  lh    $a1, 6($t9)
/* 105C78 8029C668 0C0AD677 */  jal   func_802B59DC
/* 105C7C 8029C66C AFA7002C */   sw    $a3, 0x2c($sp)
/* 105C80 8029C670 27A4011C */  addiu $a0, $sp, 0x11c
/* 105C84 8029C674 3C05C188 */  lui   $a1, 0xc188
/* 105C88 8029C678 3C0640C0 */  lui   $a2, 0x40c0
/* 105C8C 8029C67C 0C0AD4A7 */  jal   load_giant_egg
/* 105C90 8029C680 3C0741E0 */   lui   $a3, 0x41e0
/* 105C94 8029C684 27A400DC */  addiu $a0, $sp, 0xdc
/* 105C98 8029C688 0C0AD548 */  jal   func_802B5520
/* 105C9C 8029C68C 27A5011C */   addiu $a1, $sp, 0x11c
/* 105CA0 8029C690 27A4009C */  addiu $a0, $sp, 0x9c
/* 105CA4 8029C694 27A50128 */  addiu $a1, $sp, 0x128
/* 105CA8 8029C698 0C0ADC73 */  jal   func_802B71CC
/* 105CAC 8029C69C 27A600DC */   addiu $a2, $sp, 0xdc
/* 105CB0 8029C6A0 27A4009C */  addiu $a0, $sp, 0x9c
/* 105CB4 8029C6A4 0C0AD3FE */  jal   func_802B4FF8
/* 105CB8 8029C6A8 24050003 */   li    $a1, 3
/* 105CBC 8029C6AC 504000F4 */  beql  $v0, $zero, .L8029CA80
/* 105CC0 8029C6B0 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105CC4 8029C6B4 8E020000 */  lw    $v0, ($s0)
/* 105CC8 8029C6B8 3C090600 */  lui   $t1, 0x600
/* 105CCC 8029C6BC 3C0CBD00 */  lui   $t4, 0xbd00
/* 105CD0 8029C6C0 24480008 */  addiu $t0, $v0, 8
/* 105CD4 8029C6C4 AE080000 */  sw    $t0, ($s0)
/* 105CD8 8029C6C8 AC490000 */  sw    $t1, ($v0)
/* 105CDC 8029C6CC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 105CE0 8029C6D0 27A40128 */  addiu $a0, $sp, 0x128
/* 105CE4 8029C6D4 AC4A0004 */  sw    $t2, 4($v0)
/* 105CE8 8029C6D8 8E020000 */  lw    $v0, ($s0)
/* 105CEC 8029C6DC 244B0008 */  addiu $t3, $v0, 8
/* 105CF0 8029C6E0 AE0B0000 */  sw    $t3, ($s0)
/* 105CF4 8029C6E4 AC400004 */  sw    $zero, 4($v0)
/* 105CF8 8029C6E8 AC4C0000 */  sw    $t4, ($v0)
/* 105CFC 8029C6EC 8FAD016C */  lw    $t5, 0x16c($sp)
/* 105D00 8029C6F0 85A50006 */  lh    $a1, 6($t5)
/* 105D04 8029C6F4 24A50222 */  addiu $a1, $a1, 0x222
/* 105D08 8029C6F8 00057400 */  sll   $t6, $a1, 0x10
/* 105D0C 8029C6FC 0C0AD677 */  jal   func_802B59DC
/* 105D10 8029C700 000E2C03 */   sra   $a1, $t6, 0x10
/* 105D14 8029C704 27A4011C */  addiu $a0, $sp, 0x11c
/* 105D18 8029C708 3C054188 */  lui   $a1, 0x4188
/* 105D1C 8029C70C 3C0640C0 */  lui   $a2, 0x40c0
/* 105D20 8029C710 0C0AD4A7 */  jal   load_giant_egg
/* 105D24 8029C714 3C074140 */   lui   $a3, 0x4140
/* 105D28 8029C718 27A400DC */  addiu $a0, $sp, 0xdc
/* 105D2C 8029C71C 0C0AD548 */  jal   func_802B5520
/* 105D30 8029C720 27A5011C */   addiu $a1, $sp, 0x11c
/* 105D34 8029C724 27A4009C */  addiu $a0, $sp, 0x9c
/* 105D38 8029C728 27A50128 */  addiu $a1, $sp, 0x128
/* 105D3C 8029C72C 0C0ADC73 */  jal   func_802B71CC
/* 105D40 8029C730 27A600DC */   addiu $a2, $sp, 0xdc
/* 105D44 8029C734 27A4009C */  addiu $a0, $sp, 0x9c
/* 105D48 8029C738 0C0AD3FE */  jal   func_802B4FF8
/* 105D4C 8029C73C 24050003 */   li    $a1, 3
/* 105D50 8029C740 504000CF */  beql  $v0, $zero, .L8029CA80
/* 105D54 8029C744 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105D58 8029C748 8E020000 */  lw    $v0, ($s0)
/* 105D5C 8029C74C 3C190600 */  lui   $t9, 0x600
/* 105D60 8029C750 3C0ABD00 */  lui   $t2, 0xbd00
/* 105D64 8029C754 24580008 */  addiu $t8, $v0, 8
/* 105D68 8029C758 AE180000 */  sw    $t8, ($s0)
/* 105D6C 8029C75C AC590000 */  sw    $t9, ($v0)
/* 105D70 8029C760 8FA8002C */  lw    $t0, 0x2c($sp)
/* 105D74 8029C764 27A40128 */  addiu $a0, $sp, 0x128
/* 105D78 8029C768 AC480004 */  sw    $t0, 4($v0)
/* 105D7C 8029C76C 8E020000 */  lw    $v0, ($s0)
/* 105D80 8029C770 24490008 */  addiu $t1, $v0, 8
/* 105D84 8029C774 AE090000 */  sw    $t1, ($s0)
/* 105D88 8029C778 AC400004 */  sw    $zero, 4($v0)
/* 105D8C 8029C77C AC4A0000 */  sw    $t2, ($v0)
/* 105D90 8029C780 8FAB016C */  lw    $t3, 0x16c($sp)
/* 105D94 8029C784 85650006 */  lh    $a1, 6($t3)
/* 105D98 8029C788 24A50222 */  addiu $a1, $a1, 0x222
/* 105D9C 8029C78C 00056400 */  sll   $t4, $a1, 0x10
/* 105DA0 8029C790 0C0AD677 */  jal   func_802B59DC
/* 105DA4 8029C794 000C2C03 */   sra   $a1, $t4, 0x10
/* 105DA8 8029C798 27A4011C */  addiu $a0, $sp, 0x11c
/* 105DAC 8029C79C 3C05C188 */  lui   $a1, 0xc188
/* 105DB0 8029C7A0 3C0640C0 */  lui   $a2, 0x40c0
/* 105DB4 8029C7A4 0C0AD4A7 */  jal   load_giant_egg
/* 105DB8 8029C7A8 3C074140 */   lui   $a3, 0x4140
/* 105DBC 8029C7AC 27A400DC */  addiu $a0, $sp, 0xdc
/* 105DC0 8029C7B0 0C0AD548 */  jal   func_802B5520
/* 105DC4 8029C7B4 27A5011C */   addiu $a1, $sp, 0x11c
/* 105DC8 8029C7B8 27A4009C */  addiu $a0, $sp, 0x9c
/* 105DCC 8029C7BC 27A50128 */  addiu $a1, $sp, 0x128
/* 105DD0 8029C7C0 0C0ADC73 */  jal   func_802B71CC
/* 105DD4 8029C7C4 27A600DC */   addiu $a2, $sp, 0xdc
/* 105DD8 8029C7C8 27A4009C */  addiu $a0, $sp, 0x9c
/* 105DDC 8029C7CC 0C0AD3FE */  jal   func_802B4FF8
/* 105DE0 8029C7D0 24050003 */   li    $a1, 3
/* 105DE4 8029C7D4 504000AA */  beql  $v0, $zero, .L8029CA80
/* 105DE8 8029C7D8 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105DEC 8029C7DC 8E020000 */  lw    $v0, ($s0)
/* 105DF0 8029C7E0 3C0F0600 */  lui   $t7, 0x600
/* 105DF4 8029C7E4 3C08BD00 */  lui   $t0, 0xbd00
/* 105DF8 8029C7E8 244E0008 */  addiu $t6, $v0, 8
/* 105DFC 8029C7EC AE0E0000 */  sw    $t6, ($s0)
/* 105E00 8029C7F0 AC4F0000 */  sw    $t7, ($v0)
/* 105E04 8029C7F4 8FB8002C */  lw    $t8, 0x2c($sp)
/* 105E08 8029C7F8 27A40128 */  addiu $a0, $sp, 0x128
/* 105E0C 8029C7FC AC580004 */  sw    $t8, 4($v0)
/* 105E10 8029C800 8E020000 */  lw    $v0, ($s0)
/* 105E14 8029C804 24590008 */  addiu $t9, $v0, 8
/* 105E18 8029C808 AE190000 */  sw    $t9, ($s0)
/* 105E1C 8029C80C AC400004 */  sw    $zero, 4($v0)
/* 105E20 8029C810 AC480000 */  sw    $t0, ($v0)
/* 105E24 8029C814 8FA9016C */  lw    $t1, 0x16c($sp)
/* 105E28 8029C818 85250006 */  lh    $a1, 6($t1)
/* 105E2C 8029C81C 24A505B0 */  addiu $a1, $a1, 0x5b0
/* 105E30 8029C820 00055400 */  sll   $t2, $a1, 0x10
/* 105E34 8029C824 0C0AD677 */  jal   func_802B59DC
/* 105E38 8029C828 000A2C03 */   sra   $a1, $t2, 0x10
/* 105E3C 8029C82C 27A4011C */  addiu $a0, $sp, 0x11c
/* 105E40 8029C830 3C054188 */  lui   $a1, 0x4188
/* 105E44 8029C834 3C0640C0 */  lui   $a2, 0x40c0
/* 105E48 8029C838 0C0AD4A7 */  jal   load_giant_egg
/* 105E4C 8029C83C 3C07C100 */   lui   $a3, 0xc100
/* 105E50 8029C840 27A400DC */  addiu $a0, $sp, 0xdc
/* 105E54 8029C844 0C0AD548 */  jal   func_802B5520
/* 105E58 8029C848 27A5011C */   addiu $a1, $sp, 0x11c
/* 105E5C 8029C84C 27A4009C */  addiu $a0, $sp, 0x9c
/* 105E60 8029C850 27A50128 */  addiu $a1, $sp, 0x128
/* 105E64 8029C854 0C0ADC73 */  jal   func_802B71CC
/* 105E68 8029C858 27A600DC */   addiu $a2, $sp, 0xdc
/* 105E6C 8029C85C 27A4009C */  addiu $a0, $sp, 0x9c
/* 105E70 8029C860 0C0AD3FE */  jal   func_802B4FF8
/* 105E74 8029C864 24050003 */   li    $a1, 3
/* 105E78 8029C868 50400085 */  beql  $v0, $zero, .L8029CA80
/* 105E7C 8029C86C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105E80 8029C870 8E020000 */  lw    $v0, ($s0)
/* 105E84 8029C874 3C0D0600 */  lui   $t5, 0x600
/* 105E88 8029C878 3C18BD00 */  lui   $t8, 0xbd00
/* 105E8C 8029C87C 244C0008 */  addiu $t4, $v0, 8
/* 105E90 8029C880 AE0C0000 */  sw    $t4, ($s0)
/* 105E94 8029C884 AC4D0000 */  sw    $t5, ($v0)
/* 105E98 8029C888 8FAE002C */  lw    $t6, 0x2c($sp)
/* 105E9C 8029C88C 27A40128 */  addiu $a0, $sp, 0x128
/* 105EA0 8029C890 AC4E0004 */  sw    $t6, 4($v0)
/* 105EA4 8029C894 8E020000 */  lw    $v0, ($s0)
/* 105EA8 8029C898 244F0008 */  addiu $t7, $v0, 8
/* 105EAC 8029C89C AE0F0000 */  sw    $t7, ($s0)
/* 105EB0 8029C8A0 AC400004 */  sw    $zero, 4($v0)
/* 105EB4 8029C8A4 AC580000 */  sw    $t8, ($v0)
/* 105EB8 8029C8A8 8FB9016C */  lw    $t9, 0x16c($sp)
/* 105EBC 8029C8AC 87250006 */  lh    $a1, 6($t9)
/* 105EC0 8029C8B0 24A505B0 */  addiu $a1, $a1, 0x5b0
/* 105EC4 8029C8B4 00054400 */  sll   $t0, $a1, 0x10
/* 105EC8 8029C8B8 0C0AD677 */  jal   func_802B59DC
/* 105ECC 8029C8BC 00082C03 */   sra   $a1, $t0, 0x10
/* 105ED0 8029C8C0 27A4011C */  addiu $a0, $sp, 0x11c
/* 105ED4 8029C8C4 3C05C188 */  lui   $a1, 0xc188
/* 105ED8 8029C8C8 3C0640C0 */  lui   $a2, 0x40c0
/* 105EDC 8029C8CC 0C0AD4A7 */  jal   load_giant_egg
/* 105EE0 8029C8D0 3C07C100 */   lui   $a3, 0xc100
/* 105EE4 8029C8D4 27A400DC */  addiu $a0, $sp, 0xdc
/* 105EE8 8029C8D8 0C0AD548 */  jal   func_802B5520
/* 105EEC 8029C8DC 27A5011C */   addiu $a1, $sp, 0x11c
/* 105EF0 8029C8E0 27A4009C */  addiu $a0, $sp, 0x9c
/* 105EF4 8029C8E4 27A50128 */  addiu $a1, $sp, 0x128
/* 105EF8 8029C8E8 0C0ADC73 */  jal   func_802B71CC
/* 105EFC 8029C8EC 27A600DC */   addiu $a2, $sp, 0xdc
/* 105F00 8029C8F0 27A4009C */  addiu $a0, $sp, 0x9c
/* 105F04 8029C8F4 0C0AD3FE */  jal   func_802B4FF8
/* 105F08 8029C8F8 24050003 */   li    $a1, 3
/* 105F0C 8029C8FC 50400060 */  beql  $v0, $zero, .L8029CA80
/* 105F10 8029C900 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105F14 8029C904 8E020000 */  lw    $v0, ($s0)
/* 105F18 8029C908 3C0B0600 */  lui   $t3, 0x600
/* 105F1C 8029C90C 3C0EBD00 */  lui   $t6, 0xbd00
/* 105F20 8029C910 244A0008 */  addiu $t2, $v0, 8
/* 105F24 8029C914 AE0A0000 */  sw    $t2, ($s0)
/* 105F28 8029C918 AC4B0000 */  sw    $t3, ($v0)
/* 105F2C 8029C91C 8FAC002C */  lw    $t4, 0x2c($sp)
/* 105F30 8029C920 27A40128 */  addiu $a0, $sp, 0x128
/* 105F34 8029C924 AC4C0004 */  sw    $t4, 4($v0)
/* 105F38 8029C928 8E020000 */  lw    $v0, ($s0)
/* 105F3C 8029C92C 244D0008 */  addiu $t5, $v0, 8
/* 105F40 8029C930 AE0D0000 */  sw    $t5, ($s0)
/* 105F44 8029C934 AC400004 */  sw    $zero, 4($v0)
/* 105F48 8029C938 AC4E0000 */  sw    $t6, ($v0)
/* 105F4C 8029C93C 8FAF016C */  lw    $t7, 0x16c($sp)
/* 105F50 8029C940 85E50006 */  lh    $a1, 6($t7)
/* 105F54 8029C944 24A5016C */  addiu $a1, $a1, 0x16c
/* 105F58 8029C948 0005C400 */  sll   $t8, $a1, 0x10
/* 105F5C 8029C94C 0C0AD677 */  jal   func_802B59DC
/* 105F60 8029C950 00182C03 */   sra   $a1, $t8, 0x10
/* 105F64 8029C954 27A4011C */  addiu $a0, $sp, 0x11c
/* 105F68 8029C958 3C054188 */  lui   $a1, 0x4188
/* 105F6C 8029C95C 3C0640C0 */  lui   $a2, 0x40c0
/* 105F70 8029C960 0C0AD4A7 */  jal   load_giant_egg
/* 105F74 8029C964 3C07C1C0 */   lui   $a3, 0xc1c0
/* 105F78 8029C968 27A400DC */  addiu $a0, $sp, 0xdc
/* 105F7C 8029C96C 0C0AD548 */  jal   func_802B5520
/* 105F80 8029C970 27A5011C */   addiu $a1, $sp, 0x11c
/* 105F84 8029C974 27A4009C */  addiu $a0, $sp, 0x9c
/* 105F88 8029C978 27A50128 */  addiu $a1, $sp, 0x128
/* 105F8C 8029C97C 0C0ADC73 */  jal   func_802B71CC
/* 105F90 8029C980 27A600DC */   addiu $a2, $sp, 0xdc
/* 105F94 8029C984 27A4009C */  addiu $a0, $sp, 0x9c
/* 105F98 8029C988 0C0AD3FE */  jal   func_802B4FF8
/* 105F9C 8029C98C 24050003 */   li    $a1, 3
/* 105FA0 8029C990 5040003B */  beql  $v0, $zero, .L8029CA80
/* 105FA4 8029C994 8FBF0024 */   lw    $ra, 0x24($sp)
/* 105FA8 8029C998 8E020000 */  lw    $v0, ($s0)
/* 105FAC 8029C99C 3C090600 */  lui   $t1, 0x600
/* 105FB0 8029C9A0 3C0CBD00 */  lui   $t4, 0xbd00
/* 105FB4 8029C9A4 24480008 */  addiu $t0, $v0, 8
/* 105FB8 8029C9A8 AE080000 */  sw    $t0, ($s0)
/* 105FBC 8029C9AC AC490000 */  sw    $t1, ($v0)
/* 105FC0 8029C9B0 8FAA002C */  lw    $t2, 0x2c($sp)
/* 105FC4 8029C9B4 27A40128 */  addiu $a0, $sp, 0x128
/* 105FC8 8029C9B8 AC4A0004 */  sw    $t2, 4($v0)
/* 105FCC 8029C9BC 8E020000 */  lw    $v0, ($s0)
/* 105FD0 8029C9C0 244B0008 */  addiu $t3, $v0, 8
/* 105FD4 8029C9C4 AE0B0000 */  sw    $t3, ($s0)
/* 105FD8 8029C9C8 AC400004 */  sw    $zero, 4($v0)
/* 105FDC 8029C9CC AC4C0000 */  sw    $t4, ($v0)
/* 105FE0 8029C9D0 8FAD016C */  lw    $t5, 0x16c($sp)
/* 105FE4 8029C9D4 85A50006 */  lh    $a1, 6($t5)
/* 105FE8 8029C9D8 24A5016C */  addiu $a1, $a1, 0x16c
/* 105FEC 8029C9DC 00057400 */  sll   $t6, $a1, 0x10
/* 105FF0 8029C9E0 0C0AD677 */  jal   func_802B59DC
/* 105FF4 8029C9E4 000E2C03 */   sra   $a1, $t6, 0x10
/* 105FF8 8029C9E8 27A4011C */  addiu $a0, $sp, 0x11c
/* 105FFC 8029C9EC 3C05C188 */  lui   $a1, 0xc188
/* 106000 8029C9F0 3C0640C0 */  lui   $a2, 0x40c0
/* 106004 8029C9F4 0C0AD4A7 */  jal   load_giant_egg
/* 106008 8029C9F8 3C07C1C0 */   lui   $a3, 0xc1c0
/* 10600C 8029C9FC 27A400DC */  addiu $a0, $sp, 0xdc
/* 106010 8029CA00 0C0AD548 */  jal   func_802B5520
/* 106014 8029CA04 27A5011C */   addiu $a1, $sp, 0x11c
/* 106018 8029CA08 27A4009C */  addiu $a0, $sp, 0x9c
/* 10601C 8029CA0C 27A50128 */  addiu $a1, $sp, 0x128
/* 106020 8029CA10 0C0ADC73 */  jal   func_802B71CC
/* 106024 8029CA14 27A600DC */   addiu $a2, $sp, 0xdc
/* 106028 8029CA18 27A4009C */  addiu $a0, $sp, 0x9c
/* 10602C 8029CA1C 0C0AD3FE */  jal   func_802B4FF8
/* 106030 8029CA20 24050003 */   li    $a1, 3
/* 106034 8029CA24 50400016 */  beql  $v0, $zero, .L8029CA80
/* 106038 8029CA28 8FBF0024 */   lw    $ra, 0x24($sp)
/* 10603C 8029CA2C 8E020000 */  lw    $v0, ($s0)
/* 106040 8029CA30 3C190600 */  lui   $t9, 0x600
/* 106044 8029CA34 3C0ABD00 */  lui   $t2, 0xbd00
/* 106048 8029CA38 24580008 */  addiu $t8, $v0, 8
/* 10604C 8029CA3C AE180000 */  sw    $t8, ($s0)
/* 106050 8029CA40 AC590000 */  sw    $t9, ($v0)
/* 106054 8029CA44 8FA8002C */  lw    $t0, 0x2c($sp)
/* 106058 8029CA48 3C0CB700 */  lui   $t4, 0xb700
/* 10605C 8029CA4C 240D2000 */  li    $t5, 8192
/* 106060 8029CA50 AC480004 */  sw    $t0, 4($v0)
/* 106064 8029CA54 8E020000 */  lw    $v0, ($s0)
/* 106068 8029CA58 24490008 */  addiu $t1, $v0, 8
/* 10606C 8029CA5C AE090000 */  sw    $t1, ($s0)
/* 106070 8029CA60 AC400004 */  sw    $zero, 4($v0)
/* 106074 8029CA64 AC4A0000 */  sw    $t2, ($v0)
/* 106078 8029CA68 8E020000 */  lw    $v0, ($s0)
/* 10607C 8029CA6C 244B0008 */  addiu $t3, $v0, 8
/* 106080 8029CA70 AE0B0000 */  sw    $t3, ($s0)
/* 106084 8029CA74 AC4D0004 */  sw    $t5, 4($v0)
/* 106088 8029CA78 AC4C0000 */  sw    $t4, ($v0)
.L8029CA7C:
/* 10608C 8029CA7C 8FBF0024 */  lw    $ra, 0x24($sp)
.L8029CA80:
/* 106090 8029CA80 8FB00020 */  lw    $s0, 0x20($sp)
/* 106094 8029CA84 27BD0168 */  addiu $sp, $sp, 0x168
/* 106098 8029CA88 03E00008 */  jr    $ra
/* 10609C 8029CA8C 00000000 */   nop   
