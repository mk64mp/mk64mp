glabel func_80281548
/* 124B88 80281548 3C018015 */  lui   $at, %hi(D_80150112) # $at, 0x8015
/* 124B8C 8028154C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 124B90 80281550 A4200112 */  sh    $zero, %lo(D_80150112)($at)
/* 124B94 80281554 AFBF0014 */  sw    $ra, 0x14($sp)
/* 124B98 80281558 3C018028 */  lui   $at, %hi(D_802874FC) # $at, 0x8028
/* 124B9C 8028155C 0C0A0584 */  jal   func_80281610
/* 124BA0 80281560 AC2074FC */   sw    $zero, %lo(D_802874FC)($at)
/* 124BA4 80281564 0C00A3DC */  jal   func_80028F70
/* 124BA8 80281568 00000000 */   nop   
/* 124BAC 8028156C 0C0089D1 */  jal   func_80022744
/* 124BB0 80281570 00000000 */   nop   
/* 124BB4 80281574 0C0166B2 */  jal   func_80059AC8
/* 124BB8 80281578 00000000 */   nop   
/* 124BBC 8028157C 0C0166B2 */  jal   func_80059AC8
/* 124BC0 80281580 00000000 */   nop   
/* 124BC4 80281584 0C01681C */  jal   func_8005A070
/* 124BC8 80281588 00000000 */   nop   
/* 124BCC 8028158C 3C0E8028 */  lui   $t6, %hi(D_802874F4) # $t6, 0x8028
/* 124BD0 80281590 81CE74F4 */  lb    $t6, %lo(D_802874F4)($t6)
/* 124BD4 80281594 11C00005 */  beqz  $t6, .L802815AC
/* 124BD8 80281598 00000000 */   nop   
/* 124BDC 8028159C 0C007053 */  jal   func_8001C14C
/* 124BE0 802815A0 00000000 */   nop   
/* 124BE4 802815A4 0C0025F8 */  jal   func_800097E0
/* 124BE8 802815A8 00000000 */   nop   
.L802815AC:
/* 124BEC 802815AC 0C0A0740 */  jal   func_80281D00
/* 124BF0 802815B0 00000000 */   nop   
/* 124BF4 802815B4 0C0A0550 */  jal   func_80281540
/* 124BF8 802815B8 00000000 */   nop   
/* 124BFC 802815BC 3C058015 */  lui   $a1, %hi(gDisplayListHead) # $a1, 0x8015
/* 124C00 802815C0 24A50298 */  addiu $a1, %lo(gDisplayListHead) # addiu $a1, $a1, 0x298
/* 124C04 802815C4 8CA20000 */  lw    $v0, ($a1)
/* 124C08 802815C8 3C18E900 */  lui   $t8, 0xe900
/* 124C0C 802815CC 3C08B800 */  lui   $t0, 0xb800
/* 124C10 802815D0 244F0008 */  addiu $t7, $v0, 8
/* 124C14 802815D4 ACAF0000 */  sw    $t7, ($a1)
/* 124C18 802815D8 AC400004 */  sw    $zero, 4($v0)
/* 124C1C 802815DC AC580000 */  sw    $t8, ($v0)
/* 124C20 802815E0 8CA20000 */  lw    $v0, ($a1)
/* 124C24 802815E4 24590008 */  addiu $t9, $v0, 8
/* 124C28 802815E8 ACB90000 */  sw    $t9, ($a1)
/* 124C2C 802815EC AC400004 */  sw    $zero, 4($v0)
/* 124C30 802815F0 AC480000 */  sw    $t0, ($v0)
/* 124C34 802815F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 124C38 802815F8 27BD0018 */  addiu $sp, $sp, 0x18
/* 124C3C 802815FC 03E00008 */  jr    $ra
/* 124C40 80281600 00000000 */   nop   

/* 124C44 80281604 00000000 */  nop   
/* 124C48 80281608 00000000 */  nop   
