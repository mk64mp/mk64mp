glabel func_80283D2C
/* 12736C 80283D2C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 127370 80283D30 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 127374 80283D34 44812000 */  mtc1  $at, $f4
/* 127378 80283D38 AFB00014 */  sw    $s0, 0x14($sp)
/* 12737C 80283D3C 00808025 */  move  $s0, $a0
/* 127380 80283D40 AFBF001C */  sw    $ra, 0x1c($sp)
/* 127384 80283D44 3C018028 */  lui   $at, %hi(D_802856B8) # $at, 0x8028
/* 127388 80283D48 3C048028 */  lui   $a0, %hi(D_80283CA8) # $a0, 0x8028
/* 12738C 80283D4C AFB10018 */  sw    $s1, 0x18($sp)
/* 127390 80283D50 24843CA8 */  addiu $a0, %lo(D_80283CA8) # addiu $a0, $a0, 0x3ca8
/* 127394 80283D54 02002825 */  move  $a1, $s0
/* 127398 80283D58 00003025 */  move  $a2, $zero
/* 12739C 80283D5C 00003825 */  move  $a3, $zero
/* 1273A0 80283D60 0C0A0CB1 */  jal   func_802832C4
/* 1273A4 80283D64 E42456B8 */   swc1  $f4, %lo(D_802856B8)($at)
/* 1273A8 80283D68 3C048028 */  lui   $a0, %hi(D_80283A34) # $a0, 0x8028
/* 1273AC 80283D6C 24843A34 */  addiu $a0, %lo(D_80283A34) # addiu $a0, $a0, 0x3a34
/* 1273B0 80283D70 02002825 */  move  $a1, $s0
/* 1273B4 80283D74 24060001 */  li    $a2, 1
/* 1273B8 80283D78 0C0A0CB1 */  jal   func_802832C4
/* 1273BC 80283D7C 24070001 */   li    $a3, 1
/* 1273C0 80283D80 3C048028 */  lui   $a0, %hi(D_80283BF0) # $a0, 0x8028
/* 1273C4 80283D84 24843BF0 */  addiu $a0, %lo(D_80283BF0) # addiu $a0, $a0, 0x3bf0
/* 1273C8 80283D88 02002825 */  move  $a1, $s0
/* 1273CC 80283D8C 00003025 */  move  $a2, $zero
/* 1273D0 80283D90 0C0A0CB1 */  jal   func_802832C4
/* 1273D4 80283D94 00003825 */   move  $a3, $zero
/* 1273D8 80283D98 3C118028 */  lui   $s1, %hi(D_80283A7C) # $s1, 0x8028
/* 1273DC 80283D9C 26313A7C */  addiu $s1, %lo(D_80283A7C) # addiu $s1, $s1, 0x3a7c
/* 1273E0 80283DA0 02202025 */  move  $a0, $s1
/* 1273E4 80283DA4 02002825 */  move  $a1, $s0
/* 1273E8 80283DA8 2406002D */  li    $a2, 45
/* 1273EC 80283DAC 0C0A0CB1 */  jal   func_802832C4
/* 1273F0 80283DB0 2407002D */   li    $a3, 45
/* 1273F4 80283DB4 02202025 */  move  $a0, $s1
/* 1273F8 80283DB8 02002825 */  move  $a1, $s0
/* 1273FC 80283DBC 24060041 */  li    $a2, 65
/* 127400 80283DC0 0C0A0CB1 */  jal   func_802832C4
/* 127404 80283DC4 24070041 */   li    $a3, 65
/* 127408 80283DC8 02202025 */  move  $a0, $s1
/* 12740C 80283DCC 02002825 */  move  $a1, $s0
/* 127410 80283DD0 24060046 */  li    $a2, 70
/* 127414 80283DD4 0C0A0CB1 */  jal   func_802832C4
/* 127418 80283DD8 24070046 */   li    $a3, 70
/* 12741C 80283DDC 02202025 */  move  $a0, $s1
/* 127420 80283DE0 02002825 */  move  $a1, $s0
/* 127424 80283DE4 2406005E */  li    $a2, 94
/* 127428 80283DE8 0C0A0CB1 */  jal   func_802832C4
/* 12742C 80283DEC 2407005E */   li    $a3, 94
/* 127430 80283DF0 02202025 */  move  $a0, $s1
/* 127434 80283DF4 02002825 */  move  $a1, $s0
/* 127438 80283DF8 2406006E */  li    $a2, 110
/* 12743C 80283DFC 0C0A0CB1 */  jal   func_802832C4
/* 127440 80283E00 2407006E */   li    $a3, 110
/* 127444 80283E04 02202025 */  move  $a0, $s1
/* 127448 80283E08 02002825 */  move  $a1, $s0
/* 12744C 80283E0C 24060082 */  li    $a2, 130
/* 127450 80283E10 0C0A0CB1 */  jal   func_802832C4
/* 127454 80283E14 24070082 */   li    $a3, 130
/* 127458 80283E18 02202025 */  move  $a0, $s1
/* 12745C 80283E1C 02002825 */  move  $a1, $s0
/* 127460 80283E20 24060098 */  li    $a2, 152
/* 127464 80283E24 0C0A0CB1 */  jal   func_802832C4
/* 127468 80283E28 24070098 */   li    $a3, 152
/* 12746C 80283E2C 02202025 */  move  $a0, $s1
/* 127470 80283E30 02002825 */  move  $a1, $s0
/* 127474 80283E34 240600A0 */  li    $a2, 160
/* 127478 80283E38 0C0A0CB1 */  jal   func_802832C4
/* 12747C 80283E3C 240700A0 */   li    $a3, 160
/* 127480 80283E40 3C068028 */  lui   $a2, %hi(D_80285D14) # $a2, 0x8028
/* 127484 80283E44 84C65D14 */  lh    $a2, %lo(D_80285D14)($a2)
/* 127488 80283E48 3C048028 */  lui   $a0, %hi(D_80283994) # $a0, 0x8028
/* 12748C 80283E4C 24843994 */  addiu $a0, %lo(D_80283994) # addiu $a0, $a0, 0x3994
/* 127490 80283E50 24C6FFC4 */  addiu $a2, -0x3c
/* 127494 80283E54 00067400 */  sll   $t6, $a2, 0x10
/* 127498 80283E58 000E3403 */  sra   $a2, $t6, 0x10
/* 12749C 80283E5C 00063C00 */  sll   $a3, $a2, 0x10
/* 1274A0 80283E60 0007C403 */  sra   $t8, $a3, 0x10
/* 1274A4 80283E64 03003825 */  move  $a3, $t8
/* 1274A8 80283E68 0C0A0CB1 */  jal   func_802832C4
/* 1274AC 80283E6C 02002825 */   move  $a1, $s0
/* 1274B0 80283E70 3C058028 */  lui   $a1, %hi(D_802856DC) # $a1, 0x8028
/* 1274B4 80283E74 3C068028 */  lui   $a2, %hi(D_80285718) # $a2, 0x8028
/* 1274B8 80283E78 24C65718 */  addiu $a2, %lo(D_80285718) # addiu $a2, $a2, 0x5718
/* 1274BC 80283E7C 24A556DC */  addiu $a1, %lo(D_802856DC) # addiu $a1, $a1, 0x56dc
/* 1274C0 80283E80 02002025 */  move  $a0, $s0
/* 1274C4 80283E84 0C0A0B64 */  jal   func_80282D90
/* 1274C8 80283E88 00003825 */   move  $a3, $zero
/* 1274CC 80283E8C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1274D0 80283E90 8FB00014 */  lw    $s0, 0x14($sp)
/* 1274D4 80283E94 8FB10018 */  lw    $s1, 0x18($sp)
/* 1274D8 80283E98 03E00008 */  jr    $ra
/* 1274DC 80283E9C 27BD0020 */   addiu $sp, $sp, 0x20
