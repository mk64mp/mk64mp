glabel func_8008F650
/* 090250 8008F650 3C01800E */  lui   $at, %hi(gCourseTimer) # $at, 0x800e
/* 090254 8008F654 C424C598 */  lwc1  $f4, %lo(gCourseTimer)($at)
/* 090258 8008F658 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 09025C 8008F65C AFA5002C */  sw    $a1, 0x2c($sp)
/* 090260 8008F660 4600218D */  trunc.w.s $f6, $f4
/* 090264 8008F664 00057600 */  sll   $t6, $a1, 0x18
/* 090268 8008F668 000E2E03 */  sra   $a1, $t6, 0x18
/* 09026C 8008F66C 3C188019 */  lui   $t8, %hi(D_8018D930) # $t8, 0x8019
/* 090270 8008F670 2718D930 */  addiu $t8, %lo(D_8018D930) # addiu $t8, $t8, -0x26d0
/* 090274 8008F674 00053080 */  sll   $a2, $a1, 2
/* 090278 8008F678 00D83821 */  addu  $a3, $a2, $t8
/* 09027C 8008F67C 8CEA0000 */  lw    $t2, ($a3)
/* 090280 8008F680 44093000 */  mfc1  $t1, $f6
/* 090284 8008F684 AFBF0014 */  sw    $ra, 0x14($sp)
/* 090288 8008F688 AFA40028 */  sw    $a0, 0x28($sp)
/* 09028C 8008F68C 012A1823 */  subu  $v1, $t1, $t2
/* 090290 8008F690 28610009 */  slti  $at, $v1, 9
/* 090294 8008F694 1420002D */  bnez  $at, .L8008F74C
/* 090298 8008F698 24080001 */   li    $t0, 1
/* 09029C 8008F69C 3C0B8019 */  lui   $t3, %hi(D_8018D900) # $t3, 0x8019
/* 0902A0 8008F6A0 256BD900 */  addiu $t3, %lo(D_8018D900) # addiu $t3, $t3, -0x2700
/* 0902A4 8008F6A4 00CB1021 */  addu  $v0, $a2, $t3
/* 0902A8 8008F6A8 AC480000 */  sw    $t0, ($v0)
/* 0902AC 8008F6AC 94840000 */  lhu   $a0, ($a0)
/* 0902B0 8008F6B0 24014000 */  li    $at, 16384
/* 0902B4 8008F6B4 308D4000 */  andi  $t5, $a0, 0x4000
/* 0902B8 8008F6B8 15A10013 */  bne   $t5, $at, .L8008F708
/* 0902BC 8008F6BC 308E0100 */   andi  $t6, $a0, 0x100
/* 0902C0 8008F6C0 24010100 */  li    $at, 256
/* 0902C4 8008F6C4 51C10011 */  beql  $t6, $at, .L8008F70C
/* 0902C8 8008F6C8 8C4A0000 */   lw    $t2, ($v0)
/* 0902CC 8008F6CC 1508001F */  bne   $t0, $t0, .L8008F74C
/* 0902D0 8008F6D0 30A400FF */   andi  $a0, $a1, 0xff
/* 0902D4 8008F6D4 AFA20018 */  sw    $v0, 0x18($sp)
/* 0902D8 8008F6D8 0C0329CC */  jal   func_800CA730
/* 0902DC 8008F6DC AFA70020 */   sw    $a3, 0x20($sp)
/* 0902E0 8008F6E0 8FA20018 */  lw    $v0, 0x18($sp)
/* 0902E4 8008F6E4 3C01800E */  lui   $at, %hi(gCourseTimer) # $at, 0x800e
/* 0902E8 8008F6E8 8FA70020 */  lw    $a3, 0x20($sp)
/* 0902EC 8008F6EC AC400000 */  sw    $zero, ($v0)
/* 0902F0 8008F6F0 C428C598 */  lwc1  $f8, %lo(gCourseTimer)($at)
/* 0902F4 8008F6F4 8CE90000 */  lw    $t1, ($a3)
/* 0902F8 8008F6F8 4600428D */  trunc.w.s $f10, $f8
/* 0902FC 8008F6FC 44195000 */  mfc1  $t9, $f10
/* 090300 8008F700 10000012 */  b     .L8008F74C
/* 090304 8008F704 03291823 */   subu  $v1, $t9, $t1
.L8008F708:
/* 090308 8008F708 8C4A0000 */  lw    $t2, ($v0)
.L8008F70C:
/* 09030C 8008F70C 30A400FF */  andi  $a0, $a1, 0xff
/* 090310 8008F710 550A000F */  bnel  $t0, $t2, .L8008F750
/* 090314 8008F714 2861000A */   slti  $at, $v1, 0xa
/* 090318 8008F718 AFA20018 */  sw    $v0, 0x18($sp)
/* 09031C 8008F71C 0C032AB3 */  jal   func_800CAACC
/* 090320 8008F720 AFA70020 */   sw    $a3, 0x20($sp)
/* 090324 8008F724 8FA20018 */  lw    $v0, 0x18($sp)
/* 090328 8008F728 3C01800E */  lui   $at, %hi(gCourseTimer) # $at, 0x800e
/* 09032C 8008F72C 8FA70020 */  lw    $a3, 0x20($sp)
/* 090330 8008F730 AC400000 */  sw    $zero, ($v0)
/* 090334 8008F734 C430C598 */  lwc1  $f16, %lo(gCourseTimer)($at)
/* 090338 8008F738 8CED0000 */  lw    $t5, ($a3)
/* 09033C 8008F73C 4600848D */  trunc.w.s $f18, $f16
/* 090340 8008F740 440C9000 */  mfc1  $t4, $f18
/* 090344 8008F744 00000000 */  nop   
/* 090348 8008F748 018D1823 */  subu  $v1, $t4, $t5
.L8008F74C:
/* 09034C 8008F74C 2861000A */  slti  $at, $v1, 0xa
.L8008F750:
/* 090350 8008F750 14200005 */  bnez  $at, .L8008F768
/* 090354 8008F754 8FAE0028 */   lw    $t6, 0x28($sp)
/* 090358 8008F758 8DCF00BC */  lw    $t7, 0xbc($t6)
/* 09035C 8008F75C 2401FDFF */  li    $at, -513
/* 090360 8008F760 01E1C024 */  and   $t8, $t7, $at
/* 090364 8008F764 ADD800BC */  sw    $t8, 0xbc($t6)
.L8008F768:
/* 090368 8008F768 8FBF0014 */  lw    $ra, 0x14($sp)
/* 09036C 8008F76C 27BD0028 */  addiu $sp, $sp, 0x28
/* 090370 8008F770 03E00008 */  jr    $ra
/* 090374 8008F774 00000000 */   nop   
