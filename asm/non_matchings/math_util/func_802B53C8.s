glabel func_802B53C8
/* 11E9D8 802B53C8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 11E9DC 802B53CC 00801825 */  move  $v1, $a0
/* 11E9E0 802B53D0 44810000 */  mtc1  $at, $f0
/* 11E9E4 802B53D4 44801000 */  mtc1  $zero, $f2
/* 11E9E8 802B53D8 24040001 */  li    $a0, 1
/* 11E9EC 802B53DC 00001025 */  move  $v0, $zero
/* 11E9F0 802B53E0 24070004 */  li    $a3, 4
/* 11E9F4 802B53E4 24060003 */  li    $a2, 3
/* 11E9F8 802B53E8 24050002 */  li    $a1, 2
.L802B53EC:
/* 11E9FC 802B53EC 54400004 */  bnel  $v0, $zero, .L802B5400
/* 11EA00 802B53F0 E4620000 */   swc1  $f2, ($v1)
/* 11EA04 802B53F4 10000002 */  b     .L802B5400
/* 11EA08 802B53F8 E4600000 */   swc1  $f0, ($v1)
/* 11EA0C 802B53FC E4620000 */  swc1  $f2, ($v1)
.L802B5400:
/* 11EA10 802B5400 54440004 */  bnel  $v0, $a0, .L802B5414
/* 11EA14 802B5404 E4620004 */   swc1  $f2, 4($v1)
/* 11EA18 802B5408 10000002 */  b     .L802B5414
/* 11EA1C 802B540C E4600004 */   swc1  $f0, 4($v1)
/* 11EA20 802B5410 E4620004 */  swc1  $f2, 4($v1)
.L802B5414:
/* 11EA24 802B5414 54450004 */  bnel  $v0, $a1, .L802B5428
/* 11EA28 802B5418 E4620008 */   swc1  $f2, 8($v1)
/* 11EA2C 802B541C 10000002 */  b     .L802B5428
/* 11EA30 802B5420 E4600008 */   swc1  $f0, 8($v1)
/* 11EA34 802B5424 E4620008 */  swc1  $f2, 8($v1)
.L802B5428:
/* 11EA38 802B5428 54460004 */  bnel  $v0, $a2, .L802B543C
/* 11EA3C 802B542C E462000C */   swc1  $f2, 0xc($v1)
/* 11EA40 802B5430 10000002 */  b     .L802B543C
/* 11EA44 802B5434 E460000C */   swc1  $f0, 0xc($v1)
/* 11EA48 802B5438 E462000C */  swc1  $f2, 0xc($v1)
.L802B543C:
/* 11EA4C 802B543C 24420001 */  addiu $v0, $v0, 1
/* 11EA50 802B5440 1447FFEA */  bne   $v0, $a3, .L802B53EC
/* 11EA54 802B5444 24630010 */   addiu $v1, $v1, 0x10
/* 11EA58 802B5448 03E00008 */  jr    $ra
/* 11EA5C 802B544C 00000000 */   nop   
