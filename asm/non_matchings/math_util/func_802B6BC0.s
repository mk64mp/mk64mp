glabel func_802B6BC0
/* 1201D0 802B6BC0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 1201D4 802B6BC4 44867000 */  mtc1  $a2, $f14
/* 1201D8 802B6BC8 00803025 */  move  $a2, $a0
/* 1201DC 802B6BCC AFA40040 */  sw    $a0, 0x40($sp)
/* 1201E0 802B6BD0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1201E4 802B6BD4 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 1201E8 802B6BD8 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 1201EC 802B6BDC AFA50044 */  sw    $a1, 0x44($sp)
/* 1201F0 802B6BE0 AFA7004C */  sw    $a3, 0x4c($sp)
/* 1201F4 802B6BE4 AFA4002C */  sw    $a0, 0x2c($sp)
/* 1201F8 802B6BE8 AFA60040 */  sw    $a2, 0x40($sp)
/* 1201FC 802B6BEC 0C0AE006 */  jal   func_802B8018
/* 120200 802B6BF0 E7AE0048 */   swc1  $f14, 0x48($sp)
/* 120204 802B6BF4 8FA4002C */  lw    $a0, 0x2c($sp)
/* 120208 802B6BF8 0C0AE00E */  jal   func_802B8038
/* 12020C 802B6BFC E7A0003C */   swc1  $f0, 0x3c($sp)
/* 120210 802B6C00 C7AE0048 */  lwc1  $f14, 0x48($sp)
/* 120214 802B6C04 C7B40050 */  lwc1  $f20, 0x50($sp)
/* 120218 802B6C08 46000486 */  mov.s $f18, $f0
/* 12021C 802B6C0C 460E7102 */  mul.s $f4, $f14, $f14
/* 120220 802B6C10 44801000 */  mtc1  $zero, $f2
/* 120224 802B6C14 8FA60040 */  lw    $a2, 0x40($sp)
/* 120228 802B6C18 4614A182 */  mul.s $f6, $f20, $f20
/* 12022C 802B6C1C C7B0003C */  lwc1  $f16, 0x3c($sp)
/* 120230 802B6C20 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 120234 802B6C24 46062000 */  add.s $f0, $f4, $f6
/* 120238 802B6C28 46000004 */  sqrt.s $f0, $f0
/* 12023C 802B6C2C 46020032 */  c.eq.s $f0, $f2
/* 120240 802B6C30 00000000 */  nop   
/* 120244 802B6C34 45030039 */  bc1tl .L802B6D1C
/* 120248 802B6C38 44810000 */   mtc1  $at, $f0
/* 12024C 802B6C3C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 120250 802B6C40 44814000 */  mtc1  $at, $f8
/* 120254 802B6C44 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 120258 802B6C48 4600A287 */  neg.s $f10, $f20
/* 12025C 802B6C4C 46004303 */  div.s $f12, $f8, $f0
/* 120260 802B6C50 E7AA002C */  swc1  $f10, 0x2c($sp)
/* 120264 802B6C54 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 120268 802B6C58 46048182 */  mul.s $f6, $f16, $f4
/* 12026C 802B6C5C E7A60028 */  swc1  $f6, 0x28($sp)
/* 120270 802B6C60 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 120274 802B6C64 46124282 */  mul.s $f10, $f8, $f18
/* 120278 802B6C68 E7AC0030 */  swc1  $f12, 0x30($sp)
/* 12027C 802B6C6C 460E2182 */  mul.s $f6, $f4, $f14
/* 120280 802B6C70 46065201 */  sub.s $f8, $f10, $f6
/* 120284 802B6C74 460C4102 */  mul.s $f4, $f8, $f12
/* 120288 802B6C78 E4C40000 */  swc1  $f4, ($a2)
/* 12028C 802B6C7C C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 120290 802B6C80 460A9182 */  mul.s $f6, $f18, $f10
/* 120294 802B6C84 E7A60024 */  swc1  $f6, 0x24($sp)
/* 120298 802B6C88 4610A202 */  mul.s $f8, $f20, $f16
/* 12029C 802B6C8C C7A40024 */  lwc1  $f4, 0x24($sp)
/* 1202A0 802B6C90 460E2282 */  mul.s $f10, $f4, $f14
/* 1202A4 802B6C94 460A4181 */  sub.s $f6, $f8, $f10
/* 1202A8 802B6C98 46007207 */  neg.s $f8, $f14
/* 1202AC 802B6C9C 460C3102 */  mul.s $f4, $f6, $f12
/* 1202B0 802B6CA0 E4C80018 */  swc1  $f8, 0x18($a2)
/* 1202B4 802B6CA4 46008282 */  mul.s $f10, $f16, $f0
/* 1202B8 802B6CA8 00000000 */  nop   
/* 1202BC 802B6CAC 46009182 */  mul.s $f6, $f18, $f0
/* 1202C0 802B6CB0 E4C4000C */  swc1  $f4, 0xc($a2)
/* 1202C4 802B6CB4 E4CA0004 */  swc1  $f10, 4($a2)
/* 1202C8 802B6CB8 460E9282 */  mul.s $f10, $f18, $f14
/* 1202CC 802B6CBC E4C60010 */  swc1  $f6, 0x10($a2)
/* 1202D0 802B6CC0 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 1202D4 802B6CC4 C7A00030 */  lwc1  $f0, 0x30($sp)
/* 1202D8 802B6CC8 46002207 */  neg.s $f8, $f4
/* 1202DC 802B6CCC E4C8001C */  swc1  $f8, 0x1c($a2)
/* 1202E0 802B6CD0 C7A60028 */  lwc1  $f6, 0x28($sp)
/* 1202E4 802B6CD4 46143102 */  mul.s $f4, $f6, $f20
/* 1202E8 802B6CD8 46045201 */  sub.s $f8, $f10, $f4
/* 1202EC 802B6CDC 46008287 */  neg.s $f10, $f16
/* 1202F0 802B6CE0 46004182 */  mul.s $f6, $f8, $f0
/* 1202F4 802B6CE4 E4C60008 */  swc1  $f6, 8($a2)
/* 1202F8 802B6CE8 460E5102 */  mul.s $f4, $f10, $f14
/* 1202FC 802B6CEC C7A80024 */  lwc1  $f8, 0x24($sp)
/* 120300 802B6CF0 46144182 */  mul.s $f6, $f8, $f20
/* 120304 802B6CF4 46062281 */  sub.s $f10, $f4, $f6
/* 120308 802B6CF8 46005202 */  mul.s $f8, $f10, $f0
/* 12030C 802B6CFC E4C80014 */  swc1  $f8, 0x14($a2)
/* 120310 802B6D00 C7A4002C */  lwc1  $f4, 0x2c($sp)
/* 120314 802B6D04 E4C2000C */  swc1  $f2, 0xc($a2)
/* 120318 802B6D08 E4C20018 */  swc1  $f2, 0x18($a2)
/* 12031C 802B6D0C E4C20024 */  swc1  $f2, 0x24($a2)
/* 120320 802B6D10 1000000C */  b     .L802B6D44
/* 120324 802B6D14 E4C40020 */   swc1  $f4, 0x20($a2)
/* 120328 802B6D18 44810000 */  mtc1  $at, $f0
.L802B6D1C:
/* 12032C 802B6D1C E4C20004 */  swc1  $f2, 4($a2)
/* 120330 802B6D20 E4C2001C */  swc1  $f2, 0x1c($a2)
/* 120334 802B6D24 E4C20008 */  swc1  $f2, 8($a2)
/* 120338 802B6D28 E4C20014 */  swc1  $f2, 0x14($a2)
/* 12033C 802B6D2C E4C2000C */  swc1  $f2, 0xc($a2)
/* 120340 802B6D30 E4C20018 */  swc1  $f2, 0x18($a2)
/* 120344 802B6D34 E4C20024 */  swc1  $f2, 0x24($a2)
/* 120348 802B6D38 E4C00000 */  swc1  $f0, ($a2)
/* 12034C 802B6D3C E4C00010 */  swc1  $f0, 0x10($a2)
/* 120350 802B6D40 E4C00020 */  swc1  $f0, 0x20($a2)
.L802B6D44:
/* 120354 802B6D44 8FBF001C */  lw    $ra, 0x1c($sp)
/* 120358 802B6D48 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 12035C 802B6D4C 27BD0040 */  addiu $sp, $sp, 0x40
/* 120360 802B6D50 03E00008 */  jr    $ra
/* 120364 802B6D54 00000000 */   nop   
