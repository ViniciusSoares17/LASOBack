/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#include <sal/types.h>

static const sal_uInt16 idx[] = {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 1000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 2000
    0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 3000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 4000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 5000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 6000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 7000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 8000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 9000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // a000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // b000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // c000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // d000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // e000
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0100,  // f000
};

static const sal_Unicode syllable[] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3000
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3010
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3020
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3030
    0x3040, 0x3042, 0x3042, 0x3044, 0x3044, 0x3046, 0x3046, 0x3048, 0x3048, 0x304a, 0x304a, 0x304b, 0x304b, 0x304d, 0x304d, 0x304f,  // 3040
    0x304f, 0x3051, 0x3051, 0x3053, 0x3053, 0x3055, 0x3055, 0x3057, 0x3057, 0x3059, 0x3059, 0x305b, 0x305b, 0x305d, 0x305d, 0x305f,  // 3050
    0x305f, 0x3061, 0x3061, 0x3064, 0x3064, 0x3064, 0x3066, 0x3066, 0x3068, 0x3068, 0x306a, 0x306b, 0x306c, 0x306d, 0x306e, 0x306f,  // 3060
    0x306f, 0x306f, 0x3072, 0x3072, 0x3072, 0x3075, 0x3075, 0x3075, 0x3078, 0x3078, 0x3078, 0x307b, 0x307b, 0x307b, 0x307E, 0x307F,  // 3070
    0x3080, 0x3081, 0x3082, 0x3084, 0x3084, 0x3086, 0x3086, 0x3088, 0x3088, 0x3089, 0x308a, 0x308b, 0x308c, 0x308d, 0x308f, 0x308f,  // 3080
    0x3090, 0x3091, 0x3092, 0x3093, 0x3046, 0x304b, 0x3051, 0x3097, 0x3098, 0x3099, 0x309a, 0x309b, 0x309c, 0x309d, 0x309e, 0x309f,  // 3090
    0x30a0, 0x3042, 0x3042, 0x3044, 0x3044, 0x3046, 0x3046, 0x3048, 0x3048, 0x304a, 0x304a, 0x304b, 0x304b, 0x304d, 0x304d, 0x304f,  // 30A0
    0x304f, 0x3051, 0x3051, 0x3053, 0x3053, 0x3055, 0x3055, 0x3057, 0x3057, 0x3059, 0x3059, 0x305b, 0x305b, 0x305d, 0x305d, 0x305f,  // 30B0
    0x305f, 0x3061, 0x3061, 0x3064, 0x3064, 0x3064, 0x3066, 0x3066, 0x3068, 0x3068, 0x306a, 0x306b, 0x306c, 0x306d, 0x306e, 0x306f,  // 30C0
    0x306f, 0x306f, 0x3072, 0x3072, 0x3072, 0x3075, 0x3075, 0x3075, 0x3078, 0x3078, 0x3078, 0x307b, 0x307b, 0x307b, 0x307e, 0x307f,  // 30D0
    0x3080, 0x3081, 0x3082, 0x3084, 0x3084, 0x3086, 0x3086, 0x3088, 0x3088, 0x3089, 0x308a, 0x308b, 0x308c, 0x308d, 0x308f, 0x308f,  // 30E0
    0x3090, 0x3091, 0x3092, 0x3093, 0x3046, 0x304b, 0x3051, 0x308f, 0x3090, 0x3091, 0x3092, 0x30FB, 0x30FC, 0x30FE, 0x30FE, 0x30FF,  // 30F0

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF00
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF10
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF20
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF30
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF40
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF50
    0xFF60, 0xFF61, 0xFF62, 0xFF63, 0xFF64, 0xFF65, 0x3092, 0x3042, 0x3044, 0x3046, 0x3048, 0x304A, 0x3084, 0x3086, 0x3088, 0x3064,  // FF60
    0xFF70, 0x3042, 0x3044, 0x3046, 0x3048, 0x304A, 0x304B, 0x304D, 0x304F, 0x3051, 0x3053, 0x3055, 0x3057, 0x3059, 0x305B, 0x305D,  // FF70
    0x305F, 0x3061, 0x3064, 0x3066, 0x3068, 0x306A, 0x306B, 0x306C, 0x306D, 0x306E, 0x306F, 0x3072, 0x3075, 0x3078, 0x307B, 0x307E,  // FF80
    0x307F, 0x3080, 0x3081, 0x3082, 0x3084, 0x3086, 0x3088, 0x3089, 0x308A, 0x308B, 0x308C, 0x308D, 0x308F, 0x3093, 0xFF9E, 0xFF9F,  // FF90
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFA0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFB0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFC0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFD0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFE0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000   // FFF0
};


static const sal_Unicode consonant[] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3000
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3010
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3020
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // 3030
    0x3040, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x304B, 0x304B, 0x304B, 0x304B, 0x304B,  // 3040
    0x304B, 0x304B, 0x304B, 0x304B, 0x304B, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x305F,  // 3050
    0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x306A, 0x306A, 0x306A, 0x306A, 0x306A, 0x306F,  // 3060
    0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x307E, 0x307E,  // 3070
    0x307E, 0x307E, 0x307E, 0x3084, 0x3084, 0x3084, 0x3084, 0x3084, 0x3084, 0x3089, 0x3089, 0x3089, 0x3089, 0x3089, 0x308F, 0x308F,  // 3080
    0x308F, 0x308F, 0x308F, 0x308F, 0x3042, 0x304B, 0x304B, 0x3097, 0x3098, 0x3099, 0x309A, 0x309B, 0x309C, 0x309D, 0x309E, 0x309F,  // 3090
    0x30a0, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x304B, 0x304B, 0x304B, 0x304B, 0x304B,  // 30A0
    0x304B, 0x304B, 0x304B, 0x304B, 0x304B, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055, 0x305F,  // 30B0
    0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x306A, 0x306A, 0x306A, 0x306A, 0x306A, 0x306F,  // 30C0
    0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x307E, 0x307E,  // 30D0
    0x307E, 0x307E, 0x307E, 0x3084, 0x3084, 0x3084, 0x3084, 0x3084, 0x3084, 0x3089, 0x3089, 0x3089, 0x3089, 0x3089, 0x308F, 0x308F,  // 30E0
    0x308F, 0x308F, 0x308F, 0x308F, 0x3042, 0x304B, 0x304B, 0x308F, 0x308F, 0x308F, 0x308F, 0x30FB, 0x30FC, 0x30FD, 0x30FE, 0x30FF,  // 30F0

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF00
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF10
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF20
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF30
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF40
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FF50
    0xFF60, 0xFF61, 0xFF62, 0xFF63, 0xFF64, 0xFF65, 0x308F, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3084, 0x3084, 0x3084, 0x305F,  // FF60
    0xFF70, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x304B, 0x304B, 0x304B, 0x304B, 0x304B, 0x3055, 0x3055, 0x3055, 0x3055, 0x3055,  // FF70
    0x305F, 0x305F, 0x305F, 0x305F, 0x305F, 0x306A, 0x306A, 0x306A, 0x306A, 0x306A, 0x306F, 0x306F, 0x306F, 0x306F, 0x306F, 0x307E,  // FF80
    0x307E, 0x307E, 0x307E, 0x307E, 0x3084, 0x3084, 0x3084, 0x3089, 0x3089, 0x3089, 0x3089, 0x3089, 0x308F, 0x308F, 0xFF9E, 0xFF9F,  // FF90
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFA0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFB0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFC0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFD0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,  // FFE0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000   // FFF0
};

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
