glabel func_80092C90
/* 093890 80092C90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 093894 80092C94 AFBF0014 */  sw    $ra, 0x14($sp)
/* 093898 80092C98 80820000 */  lb    $v0, ($a0)
/* 09389C 80092C9C 00802825 */  move  $a1, $a0
/* 0938A0 80092CA0 24030001 */  li    $v1, 1
/* 0938A4 80092CA4 28410061 */  slti  $at, $v0, 0x61
/* 0938A8 80092CA8 14200005 */  bnez  $at, .L80092CC0
/* 0938AC 80092CAC 2841007B */   slti  $at, $v0, 0x7b
/* 0938B0 80092CB0 50200004 */  beql  $at, $zero, .L80092CC4
/* 0938B4 80092CB4 28410041 */   slti  $at, $v0, 0x41
/* 0938B8 80092CB8 1000004A */  b     .L80092DE4
/* 0938BC 80092CBC 2443FF9F */   addiu $v1, $v0, -0x61
.L80092CC0:
/* 0938C0 80092CC0 28410041 */  slti  $at, $v0, 0x41
.L80092CC4:
/* 0938C4 80092CC4 14200005 */  bnez  $at, .L80092CDC
/* 0938C8 80092CC8 2841005B */   slti  $at, $v0, 0x5b
/* 0938CC 80092CCC 50200004 */  beql  $at, $zero, .L80092CE0
/* 0938D0 80092CD0 28410030 */   slti  $at, $v0, 0x30
/* 0938D4 80092CD4 10000043 */  b     .L80092DE4
/* 0938D8 80092CD8 2443FFBF */   addiu $v1, $v0, -0x41
.L80092CDC:
/* 0938DC 80092CDC 28410030 */  slti  $at, $v0, 0x30
.L80092CE0:
/* 0938E0 80092CE0 14200005 */  bnez  $at, .L80092CF8
/* 0938E4 80092CE4 2841003A */   slti  $at, $v0, 0x3a
/* 0938E8 80092CE8 50200004 */  beql  $at, $zero, .L80092CFC
/* 0938EC 80092CEC 24010020 */   li    $at, 32
/* 0938F0 80092CF0 1000003C */  b     .L80092DE4
/* 0938F4 80092CF4 2443FFF0 */   addiu $v1, $v0, -0x10
.L80092CF8:
/* 0938F8 80092CF8 24010020 */  li    $at, 32
.L80092CFC:
/* 0938FC 80092CFC 14410003 */  bne   $v0, $at, .L80092D0C
/* 093900 80092D00 00000000 */   nop   
/* 093904 80092D04 10000037 */  b     .L80092DE4
/* 093908 80092D08 2403FFFF */   li    $v1, -1
.L80092D0C:
/* 09390C 80092D0C 04410016 */  bgez  $v0, .L80092D68
/* 093910 80092D10 244FFFDF */   addiu $t7, $v0, -0x21
/* 093914 80092D14 244E005F */  addiu $t6, $v0, 0x5f
/* 093918 80092D18 2DC1000B */  sltiu $at, $t6, 0xb
/* 09391C 80092D1C 10200031 */  beqz  $at, .L80092DE4
/* 093920 80092D20 000E7080 */   sll   $t6, $t6, 2
/* 093924 80092D24 3C01800F */  lui   $at, %hi(jpt_800F0D24)
/* 093928 80092D28 002E0821 */  addu  $at, $at, $t6
/* 09392C 80092D2C 8C2E0D24 */  lw    $t6, %lo(jpt_800F0D24)($at)
/* 093930 80092D30 01C00008 */  jr    $t6
/* 093934 80092D34 00000000 */   nop   
glabel L80092D38
/* 093938 80092D38 0C024B87 */  jal   func_80092E1C
/* 09393C 80092D3C 24A40001 */   addiu $a0, $a1, 1
/* 093940 80092D40 10000028 */  b     .L80092DE4
/* 093944 80092D44 00401825 */   move  $v1, $v0
glabel L80092D48
/* 093948 80092D48 0C024B7E */  jal   func_80092DF8
/* 09394C 80092D4C 24A40001 */   addiu $a0, $a1, 1
/* 093950 80092D50 10000024 */  b     .L80092DE4
/* 093954 80092D54 00401825 */   move  $v1, $v0
glabel L80092D58
/* 093958 80092D58 0C024BB9 */  jal   func_80092EE4
/* 09395C 80092D5C 00A02025 */   move  $a0, $a1
/* 093960 80092D60 10000020 */  b     .L80092DE4
/* 093964 80092D64 00401825 */   move  $v1, $v0
.L80092D68:
/* 093968 80092D68 2DE1001F */  sltiu $at, $t7, 0x1f
/* 09396C 80092D6C 1020001C */  beqz  $at, .L80092DE0
/* 093970 80092D70 000F7880 */   sll   $t7, $t7, 2
/* 093974 80092D74 3C01800F */  lui   $at, %hi(jpt_800F0D50)
/* 093978 80092D78 002F0821 */  addu  $at, $at, $t7
/* 09397C 80092D7C 8C2F0D50 */  lw    $t7, %lo(jpt_800F0D50)($at)
/* 093980 80092D80 01E00008 */  jr    $t7
/* 093984 80092D84 00000000 */   nop   
glabel L80092D88
/* 093988 80092D88 10000016 */  b     .L80092DE4
/* 09398C 80092D8C 2403001A */   li    $v1, 26
glabel L80092D90
/* 093990 80092D90 10000014 */  b     .L80092DE4
/* 093994 80092D94 2403001B */   li    $v1, 27
glabel L80092D98
/* 093998 80092D98 10000012 */  b     .L80092DE4
/* 09399C 80092D9C 2403001C */   li    $v1, 28
glabel L80092DA0
/* 0939A0 80092DA0 10000010 */  b     .L80092DE4
/* 0939A4 80092DA4 2403001D */   li    $v1, 29
glabel L80092DA8
/* 0939A8 80092DA8 1000000E */  b     .L80092DE4
/* 0939AC 80092DAC 2403001E */   li    $v1, 30
glabel L80092DB0
/* 0939B0 80092DB0 1000000C */  b     .L80092DE4
/* 0939B4 80092DB4 2403001F */   li    $v1, 31
glabel L80092DB8
/* 0939B8 80092DB8 1000000A */  b     .L80092DE4
/* 0939BC 80092DBC 2403002A */   li    $v1, 42
glabel L80092DC0
/* 0939C0 80092DC0 10000008 */  b     .L80092DE4
/* 0939C4 80092DC4 2403002B */   li    $v1, 43
glabel L80092DC8
/* 0939C8 80092DC8 10000006 */  b     .L80092DE4
/* 0939CC 80092DCC 2403002C */   li    $v1, 44
glabel L80092DD0
/* 0939D0 80092DD0 10000004 */  b     .L80092DE4
/* 0939D4 80092DD4 2403002D */   li    $v1, 45
glabel L80092DD8
/* 0939D8 80092DD8 10000002 */  b     .L80092DE4
/* 0939DC 80092DDC 2403002E */   li    $v1, 46
.L80092DE0:
glabel L80092DE0
/* 0939E0 80092DE0 2403FFFE */  li    $v1, -2
.L80092DE4:
glabel L80092DE4
/* 0939E4 80092DE4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0939E8 80092DE8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0939EC 80092DEC 00601025 */  move  $v0, $v1
/* 0939F0 80092DF0 03E00008 */  jr    $ra
/* 0939F4 80092DF4 00000000 */   nop   
