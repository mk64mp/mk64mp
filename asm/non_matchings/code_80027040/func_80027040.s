glabel func_80027040
/* 027C40 80027040 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 027C44 80027044 AFBF002C */  sw    $ra, 0x2c($sp)
/* 027C48 80027048 AFB10028 */  sw    $s1, 0x28($sp)
/* 027C4C 8002704C AFB00024 */  sw    $s0, 0x24($sp)
/* 027C50 80027050 AFA5003C */  sw    $a1, 0x3c($sp)
/* 027C54 80027054 AFA60040 */  sw    $a2, 0x40($sp)
/* 027C58 80027058 AFA70044 */  sw    $a3, 0x44($sp)
/* 027C5C 8002705C 8C8200BC */  lw    $v0, 0xbc($a0)
/* 027C60 80027060 00077600 */  sll   $t6, $a3, 0x18
/* 027C64 80027064 24010080 */  li    $at, 128
/* 027C68 80027068 30580080 */  andi  $t8, $v0, 0x80
/* 027C6C 8002706C 000E3E03 */  sra   $a3, $t6, 0x18
/* 027C70 80027070 13010014 */  beq   $t8, $at, .L800270C4
/* 027C74 80027074 00808825 */   move  $s1, $a0
/* 027C78 80027078 30590040 */  andi  $t9, $v0, 0x40
/* 027C7C 8002707C 24010040 */  li    $at, 64
/* 027C80 80027080 13210010 */  beq   $t9, $at, .L800270C4
/* 027C84 80027084 3C030008 */   lui   $v1, 8
/* 027C88 80027088 00434024 */  and   $t0, $v0, $v1
/* 027C8C 8002708C 1068000D */  beq   $v1, $t0, .L800270C4
/* 027C90 80027090 3C030080 */   lui   $v1, 0x80
/* 027C94 80027094 00434824 */  and   $t1, $v0, $v1
/* 027C98 80027098 1069000A */  beq   $v1, $t1, .L800270C4
/* 027C9C 8002709C 3C030002 */   lui   $v1, 2
/* 027CA0 800270A0 00435024 */  and   $t2, $v0, $v1
/* 027CA4 800270A4 506A0008 */  beql  $v1, $t2, .L800270C8
/* 027CA8 800270A8 83AD0043 */   lb    $t5, 0x43($sp)
/* 027CAC 800270AC 848B0044 */  lh    $t3, 0x44($a0)
/* 027CB0 800270B0 30480400 */  andi  $t0, $v0, 0x400
/* 027CB4 800270B4 24010400 */  li    $at, 1024
/* 027CB8 800270B8 316C0800 */  andi  $t4, $t3, 0x800
/* 027CBC 800270BC 11800096 */  beqz  $t4, .L80027318
/* 027CC0 800270C0 00000000 */   nop   
.L800270C4:
/* 027CC4 800270C4 83AD0043 */  lb    $t5, 0x43($sp)
.L800270C8:
/* 027CC8 800270C8 83AC004B */  lb    $t4, 0x4b($sp)
/* 027CCC 800270CC 3C19802E */  lui   $t9, %hi(D_802DFB80) # 0x802e
/* 027CD0 800270D0 000D7040 */  sll   $t6, $t5, 1
/* 027CD4 800270D4 022E1821 */  addu  $v1, $s1, $t6
/* 027CD8 800270D8 946F0244 */  lhu   $t7, 0x244($v1)
/* 027CDC 800270DC 000C58C0 */  sll   $t3, $t4, 3
/* 027CE0 800270E0 016C5821 */  addu  $t3, $t3, $t4
/* 027CE4 800270E4 11E00049 */  beqz  $t7, .L8002720C
/* 027CE8 800270E8 000B58C0 */   sll   $t3, $t3, 3
/* 027CEC 800270EC 83B8004B */  lb    $t8, 0x4b($sp)
/* 027CF0 800270F0 83AA003F */  lb    $t2, 0x3f($sp)
/* 027CF4 800270F4 000740C0 */  sll   $t0, $a3, 3
/* 027CF8 800270F8 0018C8C0 */  sll   $t9, $t8, 3
/* 027CFC 800270FC 01074021 */  addu  $t0, $t0, $a3
/* 027D00 80027100 0338C821 */  addu  $t9, $t9, $t8
/* 027D04 80027104 000A58C0 */  sll   $t3, $t2, 3
/* 027D08 80027108 0019C8C0 */  sll   $t9, $t9, 3
/* 027D0C 8002710C 000840C0 */  sll   $t0, $t0, 3
/* 027D10 80027110 016A5821 */  addu  $t3, $t3, $t2
/* 027D14 80027114 962E0254 */  lhu   $t6, 0x254($s1)
/* 027D18 80027118 000B58C0 */  sll   $t3, $t3, 3
/* 027D1C 8002711C 01074021 */  addu  $t0, $t0, $a3
/* 027D20 80027120 0338C821 */  addu  $t9, $t9, $t8
/* 027D24 80027124 0019CA40 */  sll   $t9, $t9, 9
/* 027D28 80027128 00084200 */  sll   $t0, $t0, 8
/* 027D2C 8002712C 016A5821 */  addu  $t3, $t3, $t2
/* 027D30 80027130 000B5940 */  sll   $t3, $t3, 5
/* 027D34 80027134 03284821 */  addu  $t1, $t9, $t0
/* 027D38 80027138 3C0D802E */  lui   $t5, %hi(D_802DFB80) # $t5, 0x802e
/* 027D3C 8002713C 25ADFB80 */  addiu $t5, %lo(D_802DFB80) # addiu $t5, $t5, -0x480
/* 027D40 80027140 012B6021 */  addu  $t4, $t1, $t3
/* 027D44 80027144 3C05800E */  lui   $a1, %hi(D_800DDEB0)
/* 027D48 80027148 000E7840 */  sll   $t7, $t6, 1
/* 027D4C 8002714C 00AF2821 */  addu  $a1, $a1, $t7
/* 027D50 80027150 018D8021 */  addu  $s0, $t4, $t5
/* 027D54 80027154 02002025 */  move  $a0, $s0
/* 027D58 80027158 94A5DEB0 */  lhu   $a1, %lo(D_800DDEB0)($a1)
/* 027D5C 8002715C 0C0336E0 */  jal   osInvalDCache
/* 027D60 80027160 AFA30030 */   sw    $v1, 0x30($sp)
/* 027D64 80027164 96220254 */  lhu   $v0, 0x254($s1)
/* 027D68 80027168 8FA30030 */  lw    $v1, 0x30($sp)
/* 027D6C 8002716C 3C19800E */  lui   $t9, %hi(gKartTextureTable1)
/* 027D70 80027170 0002C080 */  sll   $t8, $v0, 2
/* 027D74 80027174 9468024C */  lhu   $t0, 0x24c($v1)
/* 027D78 80027178 0338C821 */  addu  $t9, $t9, $t8
/* 027D7C 8002717C 8F391F00 */  lw    $t9, %lo(gKartTextureTable1)($t9)
/* 027D80 80027180 00085080 */  sll   $t2, $t0, 2
/* 027D84 80027184 946C0244 */  lhu   $t4, 0x244($v1)
/* 027D88 80027188 032A4821 */  addu  $t1, $t9, $t2
/* 027D8C 8002718C 8D2B0000 */  lw    $t3, ($t1)
/* 027D90 80027190 000C6880 */  sll   $t5, $t4, 2
/* 027D94 80027194 3C0A800E */  lui   $t2, %hi(D_800DDEB0)
/* 027D98 80027198 016D7021 */  addu  $t6, $t3, $t5
/* 027D9C 8002719C 8DCF0000 */  lw    $t7, ($t6)
/* 027DA0 800271A0 0002C840 */  sll   $t9, $v0, 1
/* 027DA4 800271A4 01595021 */  addu  $t2, $t2, $t9
/* 027DA8 800271A8 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 027DAC 800271AC 954ADEB0 */  lhu   $t2, %lo(D_800DDEB0)($t2)
/* 027DB0 800271B0 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 027DB4 800271B4 3C098015 */  lui   $t1, %hi(gDmaMesgQueue) # $t1, 0x8015
/* 027DB8 800271B8 3C080014 */  lui   $t0, %hi(_kart_texturesSegmentRomStart) # $t0, 0x14
/* 027DBC 800271BC 25085470 */  addiu $t0, %lo(_kart_texturesSegmentRomStart) # addiu $t0, $t0, 0x5470
/* 027DC0 800271C0 2529EF58 */  addiu $t1, %lo(gDmaMesgQueue) # addiu $t1, $t1, -0x10a8
/* 027DC4 800271C4 3C048015 */  lui   $a0, %hi(gDmaIoMesg) # $a0, 0x8015
/* 027DC8 800271C8 01E1C024 */  and   $t8, $t7, $at
/* 027DCC 800271CC 03083821 */  addu  $a3, $t8, $t0
/* 027DD0 800271D0 2484F0A0 */  addiu $a0, %lo(gDmaIoMesg) # addiu $a0, $a0, -0xf60
/* 027DD4 800271D4 AFA90018 */  sw    $t1, 0x18($sp)
/* 027DD8 800271D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 027DDC 800271DC 00002825 */  move  $a1, $zero
/* 027DE0 800271E0 00003025 */  move  $a2, $zero
/* 027DE4 800271E4 0C03370C */  jal   osPiStartDma
/* 027DE8 800271E8 AFAA0014 */   sw    $t2, 0x14($sp)
/* 027DEC 800271EC 3C048015 */  lui   $a0, %hi(gDmaMesgQueue) # $a0, 0x8015
/* 027DF0 800271F0 3C058015 */  lui   $a1, %hi(gMainReceivedMesg) # $a1, 0x8015
/* 027DF4 800271F4 24A5F098 */  addiu $a1, %lo(gMainReceivedMesg) # addiu $a1, $a1, -0xf68
/* 027DF8 800271F8 2484EF58 */  addiu $a0, %lo(gDmaMesgQueue) # addiu $a0, $a0, -0x10a8
/* 027DFC 800271FC 0C0335D4 */  jal   osRecvMesg
/* 027E00 80027200 24060001 */   li    $a2, 1
/* 027E04 80027204 100000D2 */  b     .L80027550
/* 027E08 80027208 8FBF002C */   lw    $ra, 0x2c($sp)
.L8002720C:
/* 027E0C 8002720C 83AF003F */  lb    $t7, 0x3f($sp)
/* 027E10 80027210 000768C0 */  sll   $t5, $a3, 3
/* 027E14 80027214 01A76821 */  addu  $t5, $t5, $a3
/* 027E18 80027218 000FC0C0 */  sll   $t8, $t7, 3
/* 027E1C 8002721C 000D68C0 */  sll   $t5, $t5, 3
/* 027E20 80027220 030FC021 */  addu  $t8, $t8, $t7
/* 027E24 80027224 962A0254 */  lhu   $t2, 0x254($s1)
/* 027E28 80027228 0018C0C0 */  sll   $t8, $t8, 3
/* 027E2C 8002722C 01A76821 */  addu  $t5, $t5, $a3
/* 027E30 80027230 016C5821 */  addu  $t3, $t3, $t4
/* 027E34 80027234 000B5A40 */  sll   $t3, $t3, 9
/* 027E38 80027238 000D6A00 */  sll   $t5, $t5, 8
/* 027E3C 8002723C 030FC021 */  addu  $t8, $t8, $t7
/* 027E40 80027240 0018C140 */  sll   $t8, $t8, 5
/* 027E44 80027244 016D7021 */  addu  $t6, $t3, $t5
/* 027E48 80027248 01D84021 */  addu  $t0, $t6, $t8
/* 027E4C 8002724C 2739FB80 */  addiu $t9, $t9, %lo(D_802DFB80) # -0x480
/* 027E50 80027250 3C05800E */  lui   $a1, %hi(D_800DDEB0)
/* 027E54 80027254 000A4840 */  sll   $t1, $t2, 1
/* 027E58 80027258 00A92821 */  addu  $a1, $a1, $t1
/* 027E5C 8002725C 01198021 */  addu  $s0, $t0, $t9
/* 027E60 80027260 02002025 */  move  $a0, $s0
/* 027E64 80027264 94A5DEB0 */  lhu   $a1, %lo(D_800DDEB0)($a1)
/* 027E68 80027268 0C0336E0 */  jal   osInvalDCache
/* 027E6C 8002726C AFA30030 */   sw    $v1, 0x30($sp)
/* 027E70 80027270 96220254 */  lhu   $v0, 0x254($s1)
/* 027E74 80027274 8FA30030 */  lw    $v1, 0x30($sp)
/* 027E78 80027278 3C0B800E */  lui   $t3, %hi(gKartTextureTable0)
/* 027E7C 8002727C 00026080 */  sll   $t4, $v0, 2
/* 027E80 80027280 946D024C */  lhu   $t5, 0x24c($v1)
/* 027E84 80027284 016C5821 */  addu  $t3, $t3, $t4
/* 027E88 80027288 8D6B1EE0 */  lw    $t3, %lo(gKartTextureTable0)($t3)
/* 027E8C 8002728C 000D7880 */  sll   $t7, $t5, 2
/* 027E90 80027290 94680244 */  lhu   $t0, 0x244($v1)
/* 027E94 80027294 016F7021 */  addu  $t6, $t3, $t7
/* 027E98 80027298 8DD80000 */  lw    $t8, ($t6)
/* 027E9C 8002729C 0008C880 */  sll   $t9, $t0, 2
/* 027EA0 800272A0 3C0F800E */  lui   $t7, %hi(D_800DDEB0)
/* 027EA4 800272A4 03195021 */  addu  $t2, $t8, $t9
/* 027EA8 800272A8 8D490000 */  lw    $t1, ($t2)
/* 027EAC 800272AC 00025840 */  sll   $t3, $v0, 1
/* 027EB0 800272B0 01EB7821 */  addu  $t7, $t7, $t3
/* 027EB4 800272B4 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 027EB8 800272B8 95EFDEB0 */  lhu   $t7, %lo(D_800DDEB0)($t7)
/* 027EBC 800272BC 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 027EC0 800272C0 3C0E8015 */  lui   $t6, %hi(gDmaMesgQueue) # $t6, 0x8015
/* 027EC4 800272C4 3C0D0014 */  lui   $t5, %hi(_kart_texturesSegmentRomStart) # $t5, 0x14
/* 027EC8 800272C8 25AD5470 */  addiu $t5, %lo(_kart_texturesSegmentRomStart) # addiu $t5, $t5, 0x5470
/* 027ECC 800272CC 25CEEF58 */  addiu $t6, %lo(gDmaMesgQueue) # addiu $t6, $t6, -0x10a8
/* 027ED0 800272D0 3C048015 */  lui   $a0, %hi(gDmaIoMesg) # $a0, 0x8015
/* 027ED4 800272D4 01216024 */  and   $t4, $t1, $at
/* 027ED8 800272D8 018D3821 */  addu  $a3, $t4, $t5
/* 027EDC 800272DC 2484F0A0 */  addiu $a0, %lo(gDmaIoMesg) # addiu $a0, $a0, -0xf60
/* 027EE0 800272E0 AFAE0018 */  sw    $t6, 0x18($sp)
/* 027EE4 800272E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 027EE8 800272E8 00002825 */  move  $a1, $zero
/* 027EEC 800272EC 00003025 */  move  $a2, $zero
/* 027EF0 800272F0 0C03370C */  jal   osPiStartDma
/* 027EF4 800272F4 AFAF0014 */   sw    $t7, 0x14($sp)
/* 027EF8 800272F8 3C048015 */  lui   $a0, %hi(gDmaMesgQueue) # $a0, 0x8015
/* 027EFC 800272FC 3C058015 */  lui   $a1, %hi(gMainReceivedMesg) # $a1, 0x8015
/* 027F00 80027300 24A5F098 */  addiu $a1, %lo(gMainReceivedMesg) # addiu $a1, $a1, -0xf68
/* 027F04 80027304 2484EF58 */  addiu $a0, %lo(gDmaMesgQueue) # addiu $a0, $a0, -0x10a8
/* 027F08 80027308 0C0335D4 */  jal   osRecvMesg
/* 027F0C 8002730C 24060001 */   li    $a2, 1
/* 027F10 80027310 1000008F */  b     .L80027550
/* 027F14 80027314 8FBF002C */   lw    $ra, 0x2c($sp)
.L80027318:
/* 027F18 80027318 1101000A */  beq   $t0, $at, .L80027344
/* 027F1C 8002731C 3C030100 */   lui   $v1, 0x100
/* 027F20 80027320 0043C024 */  and   $t8, $v0, $v1
/* 027F24 80027324 10780007 */  beq   $v1, $t8, .L80027344
/* 027F28 80027328 3C030200 */   lui   $v1, 0x200
/* 027F2C 8002732C 0043C824 */  and   $t9, $v0, $v1
/* 027F30 80027330 10790004 */  beq   $v1, $t9, .L80027344
/* 027F34 80027334 3C030001 */   lui   $v1, 1
/* 027F38 80027338 00435024 */  and   $t2, $v0, $v1
/* 027F3C 8002733C 146A003D */  bne   $v1, $t2, .L80027434
/* 027F40 80027340 83AC004B */   lb    $t4, 0x4b($sp)
.L80027344:
/* 027F44 80027344 83A9004B */  lb    $t1, 0x4b($sp)
/* 027F48 80027348 83AF003F */  lb    $t7, 0x3f($sp)
/* 027F4C 8002734C 000768C0 */  sll   $t5, $a3, 3
/* 027F50 80027350 000960C0 */  sll   $t4, $t1, 3
/* 027F54 80027354 01A76821 */  addu  $t5, $t5, $a3
/* 027F58 80027358 01896021 */  addu  $t4, $t4, $t1
/* 027F5C 8002735C 000F70C0 */  sll   $t6, $t7, 3
/* 027F60 80027360 000C60C0 */  sll   $t4, $t4, 3
/* 027F64 80027364 000D68C0 */  sll   $t5, $t5, 3
/* 027F68 80027368 01CF7021 */  addu  $t6, $t6, $t7
/* 027F6C 8002736C 000E70C0 */  sll   $t6, $t6, 3
/* 027F70 80027370 01A76821 */  addu  $t5, $t5, $a3
/* 027F74 80027374 01896021 */  addu  $t4, $t4, $t1
/* 027F78 80027378 000C6240 */  sll   $t4, $t4, 9
/* 027F7C 8002737C 000D6A00 */  sll   $t5, $t5, 8
/* 027F80 80027380 01CF7021 */  addu  $t6, $t6, $t7
/* 027F84 80027384 000E7140 */  sll   $t6, $t6, 5
/* 027F88 80027388 018D5821 */  addu  $t3, $t4, $t5
/* 027F8C 8002738C 3C18802E */  lui   $t8, %hi(D_802DFB80) # $t8, 0x802e
/* 027F90 80027390 2718FB80 */  addiu $t8, %lo(D_802DFB80) # addiu $t8, $t8, -0x480
/* 027F94 80027394 016E4021 */  addu  $t0, $t3, $t6
/* 027F98 80027398 01188021 */  addu  $s0, $t0, $t8
/* 027F9C 8002739C 02002025 */  move  $a0, $s0
/* 027FA0 800273A0 0C0336E0 */  jal   osInvalDCache
/* 027FA4 800273A4 24050780 */   li    $a1, 1920
/* 027FA8 800273A8 96390254 */  lhu   $t9, 0x254($s1)
/* 027FAC 800273AC 862C00A8 */  lh    $t4, 0xa8($s1)
/* 027FB0 800273B0 3C09800E */  lui   $t1, %hi(gKartTextureGroup18s)
/* 027FB4 800273B4 00195080 */  sll   $t2, $t9, 2
/* 027FB8 800273B8 012A4821 */  addu  $t1, $t1, $t2
/* 027FBC 800273BC 8D292320 */  lw    $t1, %lo(gKartTextureGroup18s)($t1)
/* 027FC0 800273C0 000C6A03 */  sra   $t5, $t4, 8
/* 027FC4 800273C4 000D7880 */  sll   $t7, $t5, 2
/* 027FC8 800273C8 012F5821 */  addu  $t3, $t1, $t7
/* 027FCC 800273CC 8D6E0000 */  lw    $t6, ($t3)
/* 027FD0 800273D0 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 027FD4 800273D4 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 027FD8 800273D8 3C0A8015 */  lui   $t2, %hi(gDmaMesgQueue) # $t2, 0x8015
/* 027FDC 800273DC 3C180014 */  lui   $t8, %hi(_kart_texturesSegmentRomStart) # $t8, 0x14
/* 027FE0 800273E0 27185470 */  addiu $t8, %lo(_kart_texturesSegmentRomStart) # addiu $t8, $t8, 0x5470
/* 027FE4 800273E4 254AEF58 */  addiu $t2, %lo(gDmaMesgQueue) # addiu $t2, $t2, -0x10a8
/* 027FE8 800273E8 24190900 */  li    $t9, 2304
/* 027FEC 800273EC 3C048015 */  lui   $a0, %hi(gDmaIoMesg) # $a0, 0x8015
/* 027FF0 800273F0 01C14024 */  and   $t0, $t6, $at
/* 027FF4 800273F4 01183821 */  addu  $a3, $t0, $t8
/* 027FF8 800273F8 2484F0A0 */  addiu $a0, %lo(gDmaIoMesg) # addiu $a0, $a0, -0xf60
/* 027FFC 800273FC AFB90014 */  sw    $t9, 0x14($sp)
/* 028000 80027400 AFAA0018 */  sw    $t2, 0x18($sp)
/* 028004 80027404 AFB00010 */  sw    $s0, 0x10($sp)
/* 028008 80027408 00002825 */  move  $a1, $zero
/* 02800C 8002740C 0C03370C */  jal   osPiStartDma
/* 028010 80027410 00003025 */   move  $a2, $zero
/* 028014 80027414 3C048015 */  lui   $a0, %hi(gDmaMesgQueue) # $a0, 0x8015
/* 028018 80027418 3C058015 */  lui   $a1, %hi(gMainReceivedMesg) # $a1, 0x8015
/* 02801C 8002741C 24A5F098 */  addiu $a1, %lo(gMainReceivedMesg) # addiu $a1, $a1, -0xf68
/* 028020 80027420 2484EF58 */  addiu $a0, %lo(gDmaMesgQueue) # addiu $a0, $a0, -0x10a8
/* 028024 80027424 0C0335D4 */  jal   osRecvMesg
/* 028028 80027428 24060001 */   li    $a2, 1
/* 02802C 8002742C 10000048 */  b     .L80027550
/* 028030 80027430 8FBF002C */   lw    $ra, 0x2c($sp)
.L80027434:
/* 028034 80027434 83AB003F */  lb    $t3, 0x3f($sp)
/* 028038 80027438 000C68C0 */  sll   $t5, $t4, 3
/* 02803C 8002743C 000748C0 */  sll   $t1, $a3, 3
/* 028040 80027440 01274821 */  addu  $t1, $t1, $a3
/* 028044 80027444 01AC6821 */  addu  $t5, $t5, $t4
/* 028048 80027448 000B70C0 */  sll   $t6, $t3, 3
/* 02804C 8002744C 000D68C0 */  sll   $t5, $t5, 3
/* 028050 80027450 000948C0 */  sll   $t1, $t1, 3
/* 028054 80027454 01CB7021 */  addu  $t6, $t6, $t3
/* 028058 80027458 96390254 */  lhu   $t9, 0x254($s1)
/* 02805C 8002745C 000E70C0 */  sll   $t6, $t6, 3
/* 028060 80027460 01274821 */  addu  $t1, $t1, $a3
/* 028064 80027464 01AC6821 */  addu  $t5, $t5, $t4
/* 028068 80027468 000D6A40 */  sll   $t5, $t5, 9
/* 02806C 8002746C 00094A00 */  sll   $t1, $t1, 8
/* 028070 80027470 01CB7021 */  addu  $t6, $t6, $t3
/* 028074 80027474 000E7140 */  sll   $t6, $t6, 5
/* 028078 80027478 01A97821 */  addu  $t7, $t5, $t1
/* 02807C 8002747C 3C18802E */  lui   $t8, %hi(D_802DFB80) # $t8, 0x802e
/* 028080 80027480 2718FB80 */  addiu $t8, %lo(D_802DFB80) # addiu $t8, $t8, -0x480
/* 028084 80027484 01EE4021 */  addu  $t0, $t7, $t6
/* 028088 80027488 3C05800E */  lui   $a1, %hi(D_800DDEB0)
/* 02808C 8002748C 00195040 */  sll   $t2, $t9, 1
/* 028090 80027490 00AA2821 */  addu  $a1, $a1, $t2
/* 028094 80027494 01188021 */  addu  $s0, $t0, $t8
/* 028098 80027498 02002025 */  move  $a0, $s0
/* 02809C 8002749C 0C0336E0 */  jal   osInvalDCache
/* 0280A0 800274A0 94A5DEB0 */   lhu   $a1, %lo(D_800DDEB0)($a1)
/* 0280A4 800274A4 83AC0043 */  lb    $t4, 0x43($sp)
/* 0280A8 800274A8 96220254 */  lhu   $v0, 0x254($s1)
/* 0280AC 800274AC 3C0B800E */  lui   $t3, %hi(gKartTextureTable0)
/* 0280B0 800274B0 000C6840 */  sll   $t5, $t4, 1
/* 0280B4 800274B4 022D1821 */  addu  $v1, $s1, $t5
/* 0280B8 800274B8 00024880 */  sll   $t1, $v0, 2
/* 0280BC 800274BC 946F024C */  lhu   $t7, 0x24c($v1)
/* 0280C0 800274C0 01695821 */  addu  $t3, $t3, $t1
/* 0280C4 800274C4 8D6B1EE0 */  lw    $t3, %lo(gKartTextureTable0)($t3)
/* 0280C8 800274C8 000F7080 */  sll   $t6, $t7, 2
/* 0280CC 800274CC 94790244 */  lhu   $t9, 0x244($v1)
/* 0280D0 800274D0 016E4021 */  addu  $t0, $t3, $t6
/* 0280D4 800274D4 8D180000 */  lw    $t8, ($t0)
/* 0280D8 800274D8 00195080 */  sll   $t2, $t9, 2
/* 0280DC 800274DC 3C0E800E */  lui   $t6, %hi(D_800DDEB0)
/* 0280E0 800274E0 030A6021 */  addu  $t4, $t8, $t2
/* 0280E4 800274E4 8D8D0000 */  lw    $t5, ($t4)
/* 0280E8 800274E8 00025840 */  sll   $t3, $v0, 1
/* 0280EC 800274EC 01CB7021 */  addu  $t6, $t6, $t3
/* 0280F0 800274F0 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0280F4 800274F4 95CEDEB0 */  lhu   $t6, %lo(D_800DDEB0)($t6)
/* 0280F8 800274F8 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0280FC 800274FC 3C088015 */  lui   $t0, %hi(gDmaMesgQueue) # $t0, 0x8015
/* 028100 80027500 3C0F0014 */  lui   $t7, %hi(_kart_texturesSegmentRomStart) # $t7, 0x14
/* 028104 80027504 25EF5470 */  addiu $t7, %lo(_kart_texturesSegmentRomStart) # addiu $t7, $t7, 0x5470
/* 028108 80027508 2508EF58 */  addiu $t0, %lo(gDmaMesgQueue) # addiu $t0, $t0, -0x10a8
/* 02810C 8002750C 3C048015 */  lui   $a0, %hi(gDmaIoMesg) # $a0, 0x8015
/* 028110 80027510 01A14824 */  and   $t1, $t5, $at
/* 028114 80027514 012F3821 */  addu  $a3, $t1, $t7
/* 028118 80027518 2484F0A0 */  addiu $a0, %lo(gDmaIoMesg) # addiu $a0, $a0, -0xf60
/* 02811C 8002751C AFA80018 */  sw    $t0, 0x18($sp)
/* 028120 80027520 AFB00010 */  sw    $s0, 0x10($sp)
/* 028124 80027524 00002825 */  move  $a1, $zero
/* 028128 80027528 00003025 */  move  $a2, $zero
/* 02812C 8002752C 0C03370C */  jal   osPiStartDma
/* 028130 80027530 AFAE0014 */   sw    $t6, 0x14($sp)
/* 028134 80027534 3C048015 */  lui   $a0, %hi(gDmaMesgQueue) # $a0, 0x8015
/* 028138 80027538 3C058015 */  lui   $a1, %hi(gMainReceivedMesg) # $a1, 0x8015
/* 02813C 8002753C 24A5F098 */  addiu $a1, %lo(gMainReceivedMesg) # addiu $a1, $a1, -0xf68
/* 028140 80027540 2484EF58 */  addiu $a0, %lo(gDmaMesgQueue) # addiu $a0, $a0, -0x10a8
/* 028144 80027544 0C0335D4 */  jal   osRecvMesg
/* 028148 80027548 24060001 */   li    $a2, 1
/* 02814C 8002754C 8FBF002C */  lw    $ra, 0x2c($sp)
.L80027550:
/* 028150 80027550 8FB00024 */  lw    $s0, 0x24($sp)
/* 028154 80027554 8FB10028 */  lw    $s1, 0x28($sp)
/* 028158 80027558 03E00008 */  jr    $ra
/* 02815C 8002755C 27BD0038 */   addiu $sp, $sp, 0x38
