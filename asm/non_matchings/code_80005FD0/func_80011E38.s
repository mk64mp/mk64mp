glabel func_80011E38
/* 012A38 80011E38 000470C0 */  sll   $t6, $a0, 3
/* 012A3C 80011E3C 01C47023 */  subu  $t6, $t6, $a0
/* 012A40 80011E40 000E7100 */  sll   $t6, $t6, 4
/* 012A44 80011E44 0004C040 */  sll   $t8, $a0, 1
/* 012A48 80011E48 3C028016 */  lui   $v0, %hi(D_801632E8) # 0x8016
/* 012A4C 80011E4C 01C47023 */  subu  $t6, $t6, $a0
/* 012A50 80011E50 00581021 */  addu  $v0, $v0, $t8
/* 012A54 80011E54 944232E8 */  lhu   $v0, %lo(D_801632E8)($v0) # 0x32e8($v0)
/* 012A58 80011E58 000E7080 */  sll   $t6, $t6, 2
/* 012A5C 80011E5C 3C0F800E */  lui   $t7, %hi(D_800DC4DC)
/* 012A60 80011E60 8DEFC4DC */  lw    $t7, %lo(D_800DC4DC)($t7)
/* 012A64 80011E64 01C47023 */  subu  $t6, $t6, $a0
/* 012A68 80011E68 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 012A6C 80011E6C 000E70C0 */  sll   $t6, $t6, 3
/* 012A70 80011E70 AFBF0014 */  sw    $ra, 0x14($sp)
/* 012A74 80011E74 1040000E */  beqz  $v0, .L80011EB0
/* 012A78 80011E78 01CF2821 */   addu  $a1, $t6, $t7
/* 012A7C 80011E7C 24010001 */  li    $at, 1
/* 012A80 80011E80 10410005 */  beq   $v0, $at, .L80011E98
/* 012A84 80011E84 24010002 */   li    $at, 2
/* 012A88 80011E88 10410007 */  beq   $v0, $at, .L80011EA8
/* 012A8C 80011E8C 00000000 */   nop   
/* 012A90 80011E90 10000008 */  b     .L80011EB4
/* 012A94 80011E94 8FBF0014 */   lw    $ra, 0x14($sp)
.L80011E98:
/* 012A98 80011E98 0C0046C5 */  jal   func_80011B14
/* 012A9C 80011E9C 00000000 */   nop   
/* 012AA0 80011EA0 10000004 */  b     .L80011EB4
/* 012AA4 80011EA4 8FBF0014 */   lw    $ra, 0x14($sp)
.L80011EA8:
/* 012AA8 80011EA8 0C004752 */  jal   func_80011D48
/* 012AAC 80011EAC 00000000 */   nop   
.L80011EB0:
/* 012AB0 80011EB0 8FBF0014 */  lw    $ra, 0x14($sp)
.L80011EB4:
/* 012AB4 80011EB4 27BD0018 */  addiu $sp, $sp, 0x18
/* 012AB8 80011EB8 03E00008 */  jr    $ra
/* 012ABC 80011EBC 00000000 */   nop   
