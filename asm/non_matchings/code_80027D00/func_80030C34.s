glabel func_80030C34
/* 031834 80030C34 3C0E800E */  lui   $t6, %hi(D_800DC4DC) # $t6, 0x800e
/* 031838 80030C38 8DCEC4DC */  lw    $t6, %lo(D_800DC4DC)($t6)
/* 03183C 80030C3C 27BDFFF8 */  addiu $sp, $sp, -8
/* 031840 80030C40 3C0F800E */  lui   $t7, %hi(D_800DC4E0) # $t7, 0x800e
/* 031844 80030C44 148E0002 */  bne   $a0, $t6, .L80030C50
/* 031848 80030C48 3C18800E */   lui   $t8, %hi(D_800DC4E4) # $t8, 0x800e
/* 03184C 80030C4C AFA00004 */  sw    $zero, 4($sp)
.L80030C50:
/* 031850 80030C50 8DEFC4E0 */  lw    $t7, %lo(D_800DC4E0)($t7)
/* 031854 80030C54 8FA20004 */  lw    $v0, 4($sp)
/* 031858 80030C58 3C19800E */  lui   $t9, %hi(D_800DC4E8) # $t9, 0x800e
/* 03185C 80030C5C 148F0002 */  bne   $a0, $t7, .L80030C68
/* 031860 80030C60 3C09800E */   lui   $t1, %hi(D_800DC4EC) # $t1, 0x800e
/* 031864 80030C64 24020001 */  li    $v0, 1
.L80030C68:
/* 031868 80030C68 8F18C4E4 */  lw    $t8, %lo(D_800DC4E4)($t8)
/* 03186C 80030C6C 3C0A800E */  lui   $t2, %hi(D_800DC4F0) # $t2, 0x800e
/* 031870 80030C70 3C0B800E */  lui   $t3, %hi(D_800DC4F4) # $t3, 0x800e
/* 031874 80030C74 14980002 */  bne   $a0, $t8, .L80030C80
/* 031878 80030C78 3C0C800E */   lui   $t4, %hi(D_800DC4F8) # $t4, 0x800e
/* 03187C 80030C7C 24020002 */  li    $v0, 2
.L80030C80:
/* 031880 80030C80 8F39C4E8 */  lw    $t9, %lo(D_800DC4E8)($t9)
/* 031884 80030C84 3C0D8016 */  lui   $t5, %hi(D_80165460) # $t5, 0x8016
/* 031888 80030C88 25AD5460 */  addiu $t5, %lo(D_80165460) # addiu $t5, $t5, 0x5460
/* 03188C 80030C8C 14990002 */  bne   $a0, $t9, .L80030C98
/* 031890 80030C90 00000000 */   nop   
/* 031894 80030C94 24020003 */  li    $v0, 3
.L80030C98:
/* 031898 80030C98 8D29C4EC */  lw    $t1, %lo(D_800DC4EC)($t1)
/* 03189C 80030C9C 3C0F8016 */  lui   $t7, %hi(D_801653E0) # $t7, 0x8016
/* 0318A0 80030CA0 25EF53E0 */  addiu $t7, %lo(D_801653E0) # addiu $t7, $t7, 0x53e0
/* 0318A4 80030CA4 14890002 */  bne   $a0, $t1, .L80030CB0
/* 0318A8 80030CA8 00000000 */   nop   
/* 0318AC 80030CAC 24020004 */  li    $v0, 4
.L80030CB0:
/* 0318B0 80030CB0 8D4AC4F0 */  lw    $t2, %lo(D_800DC4F0)($t2)
/* 0318B4 80030CB4 3C098016 */  lui   $t1, %hi(D_80165420) # $t1, 0x8016
/* 0318B8 80030CB8 25295420 */  addiu $t1, %lo(D_80165420) # addiu $t1, $t1, 0x5420
/* 0318BC 80030CBC 148A0002 */  bne   $a0, $t2, .L80030CC8
/* 0318C0 80030CC0 00000000 */   nop   
/* 0318C4 80030CC4 24020005 */  li    $v0, 5
.L80030CC8:
/* 0318C8 80030CC8 8D6BC4F4 */  lw    $t3, %lo(D_800DC4F4)($t3)
/* 0318CC 80030CCC 148B0002 */  bne   $a0, $t3, .L80030CD8
/* 0318D0 80030CD0 00000000 */   nop   
/* 0318D4 80030CD4 24020006 */  li    $v0, 6
.L80030CD8:
/* 0318D8 80030CD8 8D8CC4F8 */  lw    $t4, %lo(D_800DC4F8)($t4)
/* 0318DC 80030CDC 3C0B8016 */  lui   $t3, %hi(D_80165480) # $t3, 0x8016
/* 0318E0 80030CE0 256B5480 */  addiu $t3, %lo(D_80165480) # addiu $t3, $t3, 0x5480
/* 0318E4 80030CE4 548C0003 */  bnel  $a0, $t4, .L80030CF4
/* 0318E8 80030CE8 00021880 */   sll   $v1, $v0, 2
/* 0318EC 80030CEC 24020007 */  li    $v0, 7
/* 0318F0 80030CF0 00021880 */  sll   $v1, $v0, 2
.L80030CF4:
/* 0318F4 80030CF4 006D2021 */  addu  $a0, $v1, $t5
/* 0318F8 80030CF8 8C8E0000 */  lw    $t6, ($a0)
/* 0318FC 80030CFC 3C0C8016 */  lui   $t4, %hi(D_80165440) # $t4, 0x8016
/* 031900 80030D00 258C5440 */  addiu $t4, %lo(D_80165440) # addiu $t4, $t4, 0x5440
/* 031904 80030D04 15C00037 */  bnez  $t6, .L80030DE4
/* 031908 80030D08 006B1021 */   addu  $v0, $v1, $t3
/* 03190C 80030D0C 006F1021 */  addu  $v0, $v1, $t7
/* 031910 80030D10 8C580000 */  lw    $t8, ($v0)
/* 031914 80030D14 24080001 */  li    $t0, 1
/* 031918 80030D18 3C198016 */  lui   $t9, %hi(D_80165420) # $t9, 0x8016
/* 03191C 80030D1C 1518000E */  bne   $t0, $t8, .L80030D58
/* 031920 80030D20 27395420 */   addiu $t9, %lo(D_80165420) # addiu $t9, $t9, 0x5420
/* 031924 80030D24 00792821 */  addu  $a1, $v1, $t9
/* 031928 80030D28 8CA60000 */  lw    $a2, ($a1)
/* 03192C 80030D2C 28C10002 */  slti  $at, $a2, 2
/* 031930 80030D30 14200002 */  bnez  $at, .L80030D3C
/* 031934 80030D34 28C10009 */   slti  $at, $a2, 9
/* 031938 80030D38 14200003 */  bnez  $at, .L80030D48
.L80030D3C:
/* 03193C 80030D3C 3C018016 */   lui   $at, %hi(D_80165440) # 0x8016
/* 031940 80030D40 00230821 */  addu  $at, $at, $v1
/* 031944 80030D44 AC205440 */  sw    $zero, %lo(D_80165440)($at) # 0x5440($at)
.L80030D48:
/* 031948 80030D48 3C018016 */  lui   $at, %hi(D_80165400) # 0x8016
/* 03194C 80030D4C ACA00000 */  sw    $zero, ($a1)
/* 031950 80030D50 00230821 */  addu  $at, $at, $v1
/* 031954 80030D54 AC205400 */  sw    $zero, %lo(D_80165400)($at) # 0x5400($at)
.L80030D58:
/* 031958 80030D58 00692821 */  addu  $a1, $v1, $t1
/* 03195C 80030D5C 8CAA0000 */  lw    $t2, ($a1)
/* 031960 80030D60 AC400000 */  sw    $zero, ($v0)
/* 031964 80030D64 006C3821 */  addu  $a3, $v1, $t4
/* 031968 80030D68 25460001 */  addiu $a2, $t2, 1
/* 03196C 80030D6C 28C10009 */  slti  $at, $a2, 9
/* 031970 80030D70 14200003 */  bnez  $at, .L80030D80
/* 031974 80030D74 ACA60000 */   sw    $a2, ($a1)
/* 031978 80030D78 24060009 */  li    $a2, 9
/* 03197C 80030D7C ACA60000 */  sw    $a2, ($a1)
.L80030D80:
/* 031980 80030D80 28C10002 */  slti  $at, $a2, 2
/* 031984 80030D84 1420000D */  bnez  $at, .L80030DBC
/* 031988 80030D88 240A0078 */   li    $t2, 120
/* 03198C 80030D8C 28C10009 */  slti  $at, $a2, 9
/* 031990 80030D90 1020000A */  beqz  $at, .L80030DBC
/* 031994 80030D94 3C0E8016 */   lui   $t6, %hi(D_80165400) # $t6, 0x8016
/* 031998 80030D98 25CE5400 */  addiu $t6, %lo(D_80165400) # addiu $t6, $t6, 0x5400
/* 03199C 80030D9C 006E1021 */  addu  $v0, $v1, $t6
/* 0319A0 80030DA0 8C4F0000 */  lw    $t7, ($v0)
/* 0319A4 80030DA4 55E00005 */  bnel  $t7, $zero, .L80030DBC
/* 0319A8 80030DA8 AC480000 */   sw    $t0, ($v0)
/* 0319AC 80030DAC 8CF80000 */  lw    $t8, ($a3)
/* 0319B0 80030DB0 27190001 */  addiu $t9, $t8, 1
/* 0319B4 80030DB4 ACF90000 */  sw    $t9, ($a3)
/* 0319B8 80030DB8 AC480000 */  sw    $t0, ($v0)
.L80030DBC:
/* 0319BC 80030DBC 8CE90000 */  lw    $t1, ($a3)
/* 0319C0 80030DC0 24010005 */  li    $at, 5
/* 0319C4 80030DC4 1521000C */  bne   $t1, $at, .L80030DF8
/* 0319C8 80030DC8 3C018016 */   lui   $at, %hi(D_80165480) # 0x8016
/* 0319CC 80030DCC AC880000 */  sw    $t0, ($a0)
/* 0319D0 80030DD0 00230821 */  addu  $at, $at, $v1
/* 0319D4 80030DD4 AC2A5480 */  sw    $t2, %lo(D_80165480)($at) # 0x5480($at)
/* 0319D8 80030DD8 ACE00000 */  sw    $zero, ($a3)
/* 0319DC 80030DDC 10000006 */  b     .L80030DF8
/* 0319E0 80030DE0 ACA00000 */   sw    $zero, ($a1)
.L80030DE4:
/* 0319E4 80030DE4 8C4C0000 */  lw    $t4, ($v0)
/* 0319E8 80030DE8 258DFFFF */  addiu $t5, $t4, -1
/* 0319EC 80030DEC 1DA00002 */  bgtz  $t5, .L80030DF8
/* 0319F0 80030DF0 AC4D0000 */   sw    $t5, ($v0)
/* 0319F4 80030DF4 AC800000 */  sw    $zero, ($a0)
.L80030DF8:
/* 0319F8 80030DF8 03E00008 */  jr    $ra
/* 0319FC 80030DFC 27BD0008 */   addiu $sp, $sp, 8
