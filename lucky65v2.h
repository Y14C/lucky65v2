/* Copyright (C) 2023 Westberry Technology Corp., Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#ifdef MULTIMODE_ENABLE
#    include "multimode.h"
#endif

#ifdef RGB_MATRIX_BLINK_ENABLE
#    include "rgb_matrix_blink.h"
#endif

#ifdef IMMOBILE_ENABLE
#    include "immobile.h"
#endif

#ifdef SPLIT_KEYBOARD
#include "transactions.h"

typedef struct _master_to_slave_t {
    uint8_t cmd;
    uint8_t body[4];
} master_to_slave_t;

typedef struct _slave_to_master_t {
    uint8_t resp;
    uint8_t body[4];
} slave_to_master_t;

#endif

#define ___ KC_NO

// clang-format on
#define LAYOUT( \
   k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k4c, k4e,\
   k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k4d, \
   k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
   k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
   k40, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b \
) \
{ \
   {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, ___}, \
   {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, ___}, \
   {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, ___}, \
   {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, ___}, \
   {k40, ___, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d, k4e}  \
}

enum safe_key {
  MM_SHIFT = IM_USER,
  MM_FC,
  MM_GUI,
  MM_VAI,
  MM_VAD,
  US_TS1,
  US_TS2,
  US_TS3,
  US_STOP,
  MM_WTAB,
 NUM_TOF1 = 0x7E08   ,
};

