glabel func_800A940C
/* 0AA00C 800A940C 8C83000C */  lw    $v1, 0xc($a0)
/* 0AA010 800A9410 240E00C8 */  li    $t6, 200
/* 0AA014 800A9414 00A31023 */  subu  $v0, $a1, $v1
/* 0AA018 800A9418 10400029 */  beqz  $v0, .L800A94C0
/* 0AA01C 800A941C 00000000 */   nop   
/* 0AA020 800A9420 01C2001A */  div   $zero, $t6, $v0
/* 0AA024 800A9424 14400002 */  bnez  $v0, .L800A9430
/* 0AA028 800A9428 00000000 */   nop   
/* 0AA02C 800A942C 0007000D */  break 7
.L800A9430:
/* 0AA030 800A9430 2401FFFF */  li    $at, -1
/* 0AA034 800A9434 14410004 */  bne   $v0, $at, .L800A9448
/* 0AA038 800A9438 3C018000 */   lui   $at, 0x8000
/* 0AA03C 800A943C 15C10002 */  bne   $t6, $at, .L800A9448
/* 0AA040 800A9440 00000000 */   nop   
/* 0AA044 800A9444 0006000D */  break 6
.L800A9448:
/* 0AA048 800A9448 00001012 */  mflo  $v0
/* 0AA04C 800A944C 2841FFE8 */  slti  $at, $v0, -0x18
/* 0AA050 800A9450 1840000F */  blez  $v0, .L800A9490
/* 0AA054 800A9454 00000000 */   nop   
/* 0AA058 800A9458 28410019 */  slti  $at, $v0, 0x19
/* 0AA05C 800A945C 54200003 */  bnel  $at, $zero, .L800A946C
/* 0AA060 800A9460 28410010 */   slti  $at, $v0, 0x10
/* 0AA064 800A9464 24020018 */  li    $v0, 24
/* 0AA068 800A9468 28410010 */  slti  $at, $v0, 0x10
.L800A946C:
/* 0AA06C 800A946C 50200003 */  beql  $at, $zero, .L800A947C
/* 0AA070 800A9470 00627821 */   addu  $t7, $v1, $v0
/* 0AA074 800A9474 24020010 */  li    $v0, 16
/* 0AA078 800A9478 00627821 */  addu  $t7, $v1, $v0
.L800A947C:
/* 0AA07C 800A947C 00AF082A */  slt   $at, $a1, $t7
/* 0AA080 800A9480 1020000F */  beqz  $at, .L800A94C0
/* 0AA084 800A9484 AC8F000C */   sw    $t7, 0xc($a0)
/* 0AA088 800A9488 03E00008 */  jr    $ra
/* 0AA08C 800A948C AC85000C */   sw    $a1, 0xc($a0)

.L800A9490:
/* 0AA090 800A9490 50200003 */  beql  $at, $zero, .L800A94A0
/* 0AA094 800A9494 2841FFF1 */   slti  $at, $v0, -0xf
/* 0AA098 800A9498 2402FFE8 */  li    $v0, -24
/* 0AA09C 800A949C 2841FFF1 */  slti  $at, $v0, -0xf
.L800A94A0:
/* 0AA0A0 800A94A0 54200003 */  bnel  $at, $zero, .L800A94B0
/* 0AA0A4 800A94A4 0062C821 */   addu  $t9, $v1, $v0
/* 0AA0A8 800A94A8 2402FFF0 */  li    $v0, -16
/* 0AA0AC 800A94AC 0062C821 */  addu  $t9, $v1, $v0
.L800A94B0:
/* 0AA0B0 800A94B0 0325082A */  slt   $at, $t9, $a1
/* 0AA0B4 800A94B4 10200002 */  beqz  $at, .L800A94C0
/* 0AA0B8 800A94B8 AC99000C */   sw    $t9, 0xc($a0)
/* 0AA0BC 800A94BC AC85000C */  sw    $a1, 0xc($a0)
.L800A94C0:
/* 0AA0C0 800A94C0 03E00008 */  jr    $ra
/* 0AA0C4 800A94C4 00000000 */   nop   
