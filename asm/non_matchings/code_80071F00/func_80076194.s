glabel func_80076194
/* 076D94 80076194 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 076D98 80076198 AFA60020 */  sw    $a2, 0x20($sp)
/* 076D9C 8007619C 00A03025 */  move  $a2, $a1
/* 076DA0 800761A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 076DA4 800761A4 AFA5001C */  sw    $a1, 0x1c($sp)
/* 076DA8 800761A8 AFA40018 */  sw    $a0, 0x18($sp)
/* 076DAC 800761AC AFA70024 */  sw    $a3, 0x24($sp)
/* 076DB0 800761B0 AFA6001C */  sw    $a2, 0x1c($sp)
/* 076DB4 800761B4 0C01C8E9 */  jal   func_800723A4
/* 076DB8 800761B8 00002825 */   move  $a1, $zero
/* 076DBC 800761BC 8FAE0018 */  lw    $t6, 0x18($sp)
/* 076DC0 800761C0 3C188016 */  lui   $t8, %hi(D_80165C18) # $t8, 0x8016
/* 076DC4 800761C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 076DC8 800761C8 000E78C0 */  sll   $t7, $t6, 3
/* 076DCC 800761CC 01EE7823 */  subu  $t7, $t7, $t6
/* 076DD0 800761D0 44812000 */  mtc1  $at, $f4
/* 076DD4 800761D4 000F7940 */  sll   $t7, $t7, 5
/* 076DD8 800761D8 27185C18 */  addiu $t8, %lo(D_80165C18) # addiu $t8, $t8, 0x5c18
/* 076DDC 800761DC 8FA6001C */  lw    $a2, 0x1c($sp)
/* 076DE0 800761E0 01F81021 */  addu  $v0, $t7, $t8
/* 076DE4 800761E4 24190004 */  li    $t9, 4
/* 076DE8 800761E8 A05900D5 */  sb    $t9, 0xd5($v0)
/* 076DEC 800761EC E4440000 */  swc1  $f4, ($v0)
/* 076DF0 800761F0 C4C60000 */  lwc1  $f6, ($a2)
/* 076DF4 800761F4 24080C00 */  li    $t0, 3072
/* 076DF8 800761F8 24092100 */  li    $t1, 8448
/* 076DFC 800761FC E4460010 */  swc1  $f6, 0x10($v0)
/* 076E00 80076200 C4C80004 */  lwc1  $f8, 4($a2)
/* 076E04 80076204 3C0A800E */  lui   $t2, %hi(gIsMirrorMode) # $t2, 0x800e
/* 076E08 80076208 252CC000 */  addiu $t4, $t1, -0x4000
/* 076E0C 8007620C E4480014 */  swc1  $f8, 0x14($v0)
/* 076E10 80076210 C4CA0008 */  lwc1  $f10, 8($a2)
/* 076E14 80076214 A44800BE */  sh    $t0, 0xbe($v0)
/* 076E18 80076218 A44000C2 */  sh    $zero, 0xc2($v0)
/* 076E1C 8007621C A44900C0 */  sh    $t1, 0xc0($v0)
/* 076E20 80076220 E44A0018 */  swc1  $f10, 0x18($v0)
/* 076E24 80076224 8D4AC604 */  lw    $t2, %lo(gIsMirrorMode)($t2)
/* 076E28 80076228 3C014020 */  li    $at, 0x40200000 # 2.500000
/* 076E2C 8007622C 51400003 */  beql  $t2, $zero, .L8007623C
/* 076E30 80076230 C7B00020 */   lwc1  $f16, 0x20($sp)
/* 076E34 80076234 A44C00C0 */  sh    $t4, 0xc0($v0)
/* 076E38 80076238 C7B00020 */  lwc1  $f16, 0x20($sp)
.L8007623C:
/* 076E3C 8007623C 44812800 */  mtc1  $at, $f5
/* 076E40 80076240 44802000 */  mtc1  $zero, $f4
/* 076E44 80076244 460084A1 */  cvt.d.s $f18, $f16
/* 076E48 80076248 8FAD0024 */  lw    $t5, 0x24($sp)
/* 076E4C 8007624C 46249182 */  mul.d $f6, $f18, $f4
/* 076E50 80076250 8FBF0014 */  lw    $ra, 0x14($sp)
/* 076E54 80076254 240300FF */  li    $v1, 255
/* 076E58 80076258 000D7040 */  sll   $t6, $t5, 1
/* 076E5C 8007625C A44300A4 */  sh    $v1, 0xa4($v0)
/* 076E60 80076260 A44300A2 */  sh    $v1, 0xa2($v0)
/* 076E64 80076264 AC4E0048 */  sw    $t6, 0x48($v0)
/* 076E68 80076268 27BD0018 */  addiu $sp, $sp, 0x18
/* 076E6C 8007626C 46203220 */  cvt.s.d $f8, $f6
/* 076E70 80076270 03E00008 */  jr    $ra
/* 076E74 80076274 E4480034 */   swc1  $f8, 0x34($v0)
