glabel func_8008F494
/* 090094 8008F494 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 090098 8008F498 AFBF0014 */  sw    $ra, 0x14($sp)
/* 09009C 8008F49C AFA5001C */  sw    $a1, 0x1c($sp)
/* 0900A0 8008F4A0 8C8200BC */  lw    $v0, 0xbc($a0)
/* 0900A4 8008F4A4 00803025 */  move  $a2, $a0
/* 0900A8 8008F4A8 00C02025 */  move  $a0, $a2
/* 0900AC 8008F4AC 304E0080 */  andi  $t6, $v0, 0x80
/* 0900B0 8008F4B0 15C00008 */  bnez  $t6, .L8008F4D4
/* 0900B4 8008F4B4 304F0040 */   andi  $t7, $v0, 0x40
/* 0900B8 8008F4B8 15E00006 */  bnez  $t7, .L8008F4D4
/* 0900BC 8008F4BC 0002C1C0 */   sll   $t8, $v0, 7
/* 0900C0 8008F4C0 07000004 */  bltz  $t8, .L8008F4D4
/* 0900C4 8008F4C4 0002C980 */   sll   $t9, $v0, 6
/* 0900C8 8008F4C8 07200002 */  bltz  $t9, .L8008F4D4
/* 0900CC 8008F4CC 30480400 */   andi  $t0, $v0, 0x400
/* 0900D0 8008F4D0 11000008 */  beqz  $t0, .L8008F4F4
.L8008F4D4:
/* 0900D4 8008F4D4 3C09800E */   lui   $t1, %hi(gModeSelection) # $t1, 0x800e
/* 0900D8 8008F4D8 8D29C53C */  lw    $t1, %lo(gModeSelection)($t1)
/* 0900DC 8008F4DC 24010003 */  li    $at, 3
/* 0900E0 8008F4E0 55210005 */  bnel  $t1, $at, .L8008F4F8
/* 0900E4 8008F4E4 83A5001F */   lb    $a1, 0x1f($sp)
/* 0900E8 8008F4E8 84CA0044 */  lh    $t2, 0x44($a2)
/* 0900EC 8008F4EC 354B8000 */  ori   $t3, $t2, 0x8000
/* 0900F0 8008F4F0 A4CB0044 */  sh    $t3, 0x44($a2)
.L8008F4F4:
/* 0900F4 8008F4F4 83A5001F */  lb    $a1, 0x1f($sp)
.L8008F4F8:
/* 0900F8 8008F4F8 0C0230D5 */  jal   func_8008C354
/* 0900FC 8008F4FC AFA60018 */   sw    $a2, 0x18($sp)
/* 090100 8008F500 8FA40018 */  lw    $a0, 0x18($sp)
/* 090104 8008F504 0C023E1B */  jal   func_8008F86C
/* 090108 8008F508 83A5001F */   lb    $a1, 0x1f($sp)
/* 09010C 8008F50C 8FA60018 */  lw    $a2, 0x18($sp)
/* 090110 8008F510 3C010001 */  lui   $at, 1
/* 090114 8008F514 2418001E */  li    $t8, 30
/* 090118 8008F518 8CCC00BC */  lw    $t4, 0xbc($a2)
/* 09011C 8008F51C 94C20000 */  lhu   $v0, ($a2)
/* 090120 8008F520 A4C000A8 */  sh    $zero, 0xa8($a2)
/* 090124 8008F524 01816825 */  or    $t5, $t4, $at
/* 090128 8008F528 2401FFEF */  li    $at, -17
/* 09012C 8008F52C 01A17824 */  and   $t7, $t5, $at
/* 090130 8008F530 ACCD00BC */  sw    $t5, 0xbc($a2)
/* 090134 8008F534 30594000 */  andi  $t9, $v0, 0x4000
/* 090138 8008F538 ACCF00BC */  sw    $t7, 0xbc($a2)
/* 09013C 8008F53C A4D80236 */  sh    $t8, 0x236($a2)
/* 090140 8008F540 13200014 */  beqz  $t9, .L8008F594
/* 090144 8008F544 A4C00042 */   sh    $zero, 0x42($a2)
/* 090148 8008F548 30480100 */  andi  $t0, $v0, 0x100
/* 09014C 8008F54C 55000012 */  bnel  $t0, $zero, .L8008F598
/* 090150 8008F550 8FBF0014 */   lw    $ra, 0x14($sp)
/* 090154 8008F554 84C900CA */  lh    $t1, 0xca($a2)
/* 090158 8008F558 312A0002 */  andi  $t2, $t1, 2
/* 09015C 8008F55C 5540000E */  bnel  $t2, $zero, .L8008F598
/* 090160 8008F560 8FBF0014 */   lw    $ra, 0x14($sp)
/* 090164 8008F564 94C200DE */  lhu   $v0, 0xde($a2)
/* 090168 8008F568 304B0001 */  andi  $t3, $v0, 1
/* 09016C 8008F56C 15600009 */  bnez  $t3, .L8008F594
/* 090170 8008F570 304C0002 */   andi  $t4, $v0, 2
/* 090174 8008F574 15800007 */  bnez  $t4, .L8008F594
/* 090178 8008F578 93A4001F */   lbu   $a0, 0x1f($sp)
/* 09017C 8008F57C 94C50254 */  lhu   $a1, 0x254($a2)
/* 090180 8008F580 3C012900 */  lui   $at, (0x29008004 >> 16) # lui $at, 0x2900
/* 090184 8008F584 34218004 */  ori   $at, (0x29008004 & 0xFFFF) # ori $at, $at, 0x8004
/* 090188 8008F588 00056900 */  sll   $t5, $a1, 4
/* 09018C 8008F58C 0C03243D */  jal   func_800C90F4
/* 090190 8008F590 01A12821 */   addu  $a1, $t5, $at
.L8008F594:
/* 090194 8008F594 8FBF0014 */  lw    $ra, 0x14($sp)
.L8008F598:
/* 090198 8008F598 27BD0018 */  addiu $sp, $sp, 0x18
/* 09019C 8008F59C 03E00008 */  jr    $ra
/* 0901A0 8008F5A0 00000000 */   nop   
