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

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

// clang-format off

#undef ___
#define ___ NO_LED

led_config_t g_led_config = {
    LAYOUT(
        66,  65,  64,  63,  62,  61,  60,  59,  58,  57,  56,  55,  54,  53,  52,___,
        37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,
        36,  35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,       24,  23,
        4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,       16,  17,
        3,   2,   1,               ___,   0,     ___,             18,  19,  20, 21,  22
    ), {
    {  89 , 64 },  // 0
    {  38 , 64 },  // 1
    {  20 , 64 },  // 2
    {   2 , 64 },  // 3
    {   9 , 48 },  // 4
    {  33 , 48 },  // 5
    {  47 , 48 },  // 6
    {  61 , 48 },  // 7
    {  76 , 48 },  // 8
    {  90 , 48 },  // 9
    { 105 , 48 },  // 10
    { 119 , 48 },  // 11
    { 134 , 48 },  // 12
    { 148 , 48 },  // 13
    { 163 , 48 },  // 14
    { 179 , 48 },  // 15
    { 195 , 48 },  // 16
    { 210 , 48 },  // 17

    { 137 , 64 },  // 18
    { 152 , 64 },  // 19
    { 166 , 64 },  // 20
    { 181 , 64 },  // 21
    { 195 , 64 },  // 22
    { 210 , 32 },  // 23
    { 190 , 32 },  // 24
    { 170 , 32 },  // 25
    { 155 , 32 },  // 26
    { 141 , 32 },  // 27
    { 126 , 32 },  // 28
    { 112 , 32 },  // 29
    {  98 , 32 },  // 30
    {  83 , 32 },  // 31
    {  69 , 32 },  // 32
    {  54 , 32 },  // 33
    {  40 , 32 },  // 34
    {  25 , 32 },  // 35
    {   5 , 32 },  // 36
    {   4 , 16 },  // 37
    {  22 , 16 },  // 38
    {  36 , 16 },  // 39
    {  51 , 16 },  // 40
    {  65 , 16 },  // 41
    {  79 , 16 },  // 42
    {  94 , 16 },  // 43
    { 108 , 16 },  // 44
    { 123 , 16 },  // 45
    { 137 , 16 },  // 46
    { 152 , 16 },  // 47
    { 166 , 16 },  // 48
    { 181 , 16 },  // 49
    { 195 , 16 },  // 50
    { 210 , 16 },  // 51
    { 210 ,  0 },  // 52
    { 191 ,  0 },  // 53
    { 173 ,  0 },  // 54
    { 159 ,  0 },  // 55
    { 145 ,  0 },  // 56
    { 130 ,  0 },  // 57
    { 116 ,  0 },  // 58
    { 101 ,  0 },  // 59
    {  87 ,  0 },  // 60
    {  72 ,  0 },  // 61
    {  58 ,  0 },  // 62
    {  43 ,  0 },  // 63
    {  29 ,  0 },  // 64
    {  14 ,  0 },  // 65
    {   0 ,  0 },  // 66

}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4
}};

// clang-format on
#endif
