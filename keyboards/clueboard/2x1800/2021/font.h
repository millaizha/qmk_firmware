/* 5x8 Font for Clueboard 2x1800.
 *
 * Copyright (c) 2021 Zach White <skullydazed@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * This permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

// Top row of keyboard, when shift held
#define CHR_TILDE      {0b00110000, 0b01000000, 0b00110000, 0b00001000, 0b00110000, 0b00000000}
#define CHR_BANG       {0b00000000, 0b00000000, 0b11111010, 0b10000000, 0b00000000, 0b00000000}
#define CHR_AT         {0b01001100, 0b10010010, 0b10011110, 0b10000010, 0b01111100, 0b00000000}
#define CHR_POUND      {0b00101000, 0b11111110, 0b00101000, 0b11111110, 0b00101000, 0b00000000}
#define CHR_DOLLAR     {0b00100100, 0b01010100, 0b11111110, 0b10101010, 0b01001000, 0b00000000}
#define CHR_PERCENT    {0b11000010, 0b11000100, 0b00010000, 0b00100110, 0b01000110, 0b00000000}
#define CHR_CARET      {0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000, 0b00000000}
#define CHR_AMPERSAND  {0b01101100, 0b10010010, 0b10101010, 0b01000100, 0b00001010, 0b00000000}
#define CHR_ASTERISK   {0b00101000, 0b00010000, 0b01111100, 0b00010000, 0b00101000, 0b00000000}
#define CHR_LPAREN     {0b00000000, 0b00111000, 0b01000100, 0b10000010, 0b00000000, 0b00000000}
#define CHR_RPAREN     {0b00000000, 0b10000010, 0b01000100, 0b00111000, 0b00000000, 0b00000000}
#define CHR_UNDERSCORE {0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000000}
#define CHR_PLUS       {0b00010000, 0b00010000, 0b01111100, 0b00010000, 0b00010000, 0b00000000}

// Top row of keyboard, without shift
#define CHR_BACKTICK {0b00000000, 0b11000000, 0b01100000, 0b10000000, 0b00000000, 0b00000000}
#define CHR_1        {0b00100000, 0b01000010, 0b11111110, 0b00000010, 0b00000010, 0b00000000}
#define CHR_2        {0b01000010, 0b10000110, 0b10001010, 0b10010010, 0b01100010, 0b00000000}
#define CHR_3        {0b10000100, 0b10000010, 0b10100010, 0b11010010, 0b10001100, 0b00000000}
#define CHR_4        {0b00011000, 0b00101000, 0b01001000, 0b11111110, 0b00001000, 0b00000000}
#define CHR_5        {0b11100100, 0b10100010, 0b10100010, 0b10100010, 0b10011100, 0b00000000}
#define CHR_6        {0b00111100, 0b01010010, 0b10010010, 0b10010010, 0b00001100, 0b00000000}
#define CHR_7        {0b11000000, 0b10001110, 0b10010000, 0b10100000, 0b11000000, 0b00000000}
#define CHR_8        {0b01101100, 0b10010010, 0b10010010, 0b10010010, 0b01101100, 0b00000000}
#define CHR_9        {0b01100000, 0b10010010, 0b10010010, 0b10010010, 0b01111000, 0b00000000}
#define CHR_0        {0b01111100, 0b10001010, 0b10010010, 0b10100010, 0b01111100, 0b00000000}
#define CHR_DASH     {0b00000000, 0b00010000, 0b00010000, 0b00010000, 0b00000000, 0b00000000}
#define CHR_EQUAL    {0b00000000, 0b00101000, 0b00101000, 0b00101000, 0b00000000, 0b00000000}

// Letters
#define CHR_A {0b01111110, 0b10001000, 0b10001000, 0b10001000, 0b01111110, 0b00000000}
#define CHR_B {0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b01101100, 0b00000000}
#define CHR_C {0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01000100, 0b00000000}
#define CHR_D {0b11111110, 0b10000010, 0b10000010, 0b10000010, 0b01111100, 0b00000000}
#define CHR_E {0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10000010, 0b00000000}
#define CHR_F {0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b10000000, 0b00000000}
#define CHR_G {0b01111100, 0b10000010, 0b10010010, 0b10010010, 0b01011100, 0b00000000}
#define CHR_H {0b11111110, 0b00010000, 0b00010000, 0b00010000, 0b11111110, 0b00000000}
#define CHR_I {0b00000000, 0b10000010, 0b11111110, 0b10000010, 0b00000000, 0b00000000}
#define CHR_J {0b00000100, 0b00000010, 0b10000010, 0b11111100, 0b10000000, 0b00000000}
#define CHR_K {0b11111110, 0b00010000, 0b00101000, 0b01000100, 0b10000010, 0b00000000}
#define CHR_L {0b00000000, 0b11111110, 0b00000010, 0b00000010, 0b00000010, 0b00000000}
#define CHR_M {0b11111110, 0b01000000, 0b00110000, 0b01000000, 0b11111110, 0b00000000}
#define CHR_N {0b11111110, 0b01100000, 0b00010000, 0b00001100, 0b11111110, 0b00000000}
#define CHR_O {0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01111100, 0b00000000}
#define CHR_P {0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b01100000, 0b00000000}
#define CHR_Q {0b01111100, 0b10000010, 0b10001010, 0b10000100, 0b01111010, 0b00000000}
#define CHR_R {0b11111110, 0b10010000, 0b10011000, 0b10010100, 0b01100010, 0b00000000}
#define CHR_S {0b01100100, 0b10010010, 0b10010010, 0b10010010, 0b01001100, 0b00000000}
#define CHR_T {0b10000000, 0b10000000, 0b11111110, 0b10000000, 0b10000000, 0b00000000}
#define CHR_U {0b11111100, 0b00000010, 0b00000010, 0b00000010, 0b11111100, 0b00000000}
#define CHR_V {0b11111000, 0b00000100, 0b00000010, 0b00000100, 0b11111000, 0b00000000}
#define CHR_W {0b11111100, 0b00000010, 0b00011100, 0b00000010, 0b11111110, 0b00000000}
#define CHR_X {0b11000110, 0b00101000, 0b00010000, 0b00101000, 0b11000110, 0b00000000}
#define CHR_Y {0b11100000, 0b00010000, 0b00001110, 0b00010000, 0b11100000, 0b00000000}
#define CHR_Z {0b10000110, 0b10001010, 0b10010010, 0b10100010, 0b11000010, 0b00000000}

#define CHR_a {0b00000100, 0b00101010, 0b00101010, 0b00101010, 0b00011110, 0b00000000}
#define CHR_b {0b11111110, 0b00010010, 0b00100010, 0b00100010, 0b00011100, 0b00000000}
#define CHR_c {0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00000100, 0b00000000}
#define CHR_d {0b00011100, 0b00100010, 0b00100010, 0b00010010, 0b11111110, 0b00000000}
#define CHR_e {0b00011100, 0b00101010, 0b00101010, 0b00101010, 0b00011000, 0b00000000}
#define CHR_f {0b00000000, 0b00010000, 0b01111110, 0b10010000, 0b10000000, 0b01000000}
#define CHR_g {0b00011000, 0b00100101, 0b00100101, 0b00100101, 0b00111110, 0b00000000}
#define CHR_h {0b11111110, 0b00010000, 0b00100000, 0b00100000, 0b00011110, 0b00000000}
#define CHR_i {0b00000000, 0b00010010, 0b10111110, 0b00000010, 0b00000000, 0b00000000}
#define CHR_j {0b00000100, 0b00000010, 0b00100010, 0b10111100, 0b00000000, 0b00000000}
#define CHR_k {0b11111110, 0b00001000, 0b00010100, 0b00100010, 0b00000000, 0b00000000}
#define CHR_l {0b00000000, 0b10000010, 0b11111110, 0b00000010, 0b00000000, 0b00000000}
#define CHR_m {0b00111110, 0b00100000, 0b00111110, 0b00100000, 0b00111110, 0b00000000}
#define CHR_n {0b00111110, 0b00010000, 0b00100000, 0b00100000, 0b00011110, 0b00000000}
#define CHR_o {0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00011100, 0b00000000}
#define CHR_p {0b00111111, 0b00100100, 0b00100100, 0b00100100, 0b00011000, 0b00000000}
#define CHR_q {0b00011000, 0b00100100, 0b00100100, 0b00011000, 0b00111111, 0b00000000}
#define CHR_r {0b00111110, 0b00010000, 0b00100000, 0b00100000, 0b00010000, 0b00000000}
#define CHR_s {0b00010010, 0b00101010, 0b00101010, 0b00101010, 0b00000100, 0b00000000}
#define CHR_t {0b00100000, 0b11111100, 0b00100010, 0b00000010, 0b00000100, 0b00000000}
#define CHR_u {0b00111100, 0b00000010, 0b00000010, 0b00000100, 0b00111110, 0b00000000}
#define CHR_v {0b00111000, 0b00000100, 0b00000010, 0b00000100, 0b00111000, 0b00000000}
#define CHR_w {0b00111100, 0b00000010, 0b00111100, 0b00000010, 0b00111100, 0b00000000}
#define CHR_x {0b00100010, 0b00010100, 0b00001000, 0b00010100, 0b00100010, 0b00000000}
#define CHR_y {0b00111000, 0b00000101, 0b00000101, 0b00000101, 0b00111110, 0b00000000}
#define CHR_z {0b00100010, 0b00100110, 0b00101010, 0b00110010, 0b00100010, 0b00000000}

// Punctuation
#define CHR_LCURLY       {0b00000000, 0b00010000, 0b01101100, 0b10000010, 0b00000000, 0b00000000}
#define CHR_RCURLY       {0b00000000, 0b10000010, 0b01101100, 0b00010000, 0b00000000, 0b00000000}
#define CHR_PIPE         {0b00000000, 0b00000000, 0b11101110, 0b00000000, 0b00000000, 0b00000000}
#define CHR_COLON        {0b00000000, 0b00000000, 0b01101100, 0b01101100, 0b00000000, 0b00000000}
#define CHR_QUOTE        {0b00000000, 0b01110000, 0b00000000, 0b01110000, 0b00000000, 0b00000000}
#define CHR_LESSTHAN     {0b00010000, 0b00101000, 0b01000100, 0b10000010, 0b00000000, 0b00000000}
#define CHR_GREATERTHAN  {0b10000010, 0b01000100, 0b00101000, 0b00010000, 0b00000000, 0b00000000}
#define CHR_QUESTIONMARK {0b01000000, 0b10000000, 0b10001010, 0b10010000, 0b01100000, 0b00000000}
#define CHR_INTERROBANG  {0b01100000, 0b10000000, 0b11101010, 0b10010000, 0b01100000, 0b00000000}
#define CHR_LBRACKET     {0b00000000, 0b11111110, 0b10000010, 0b10000010, 0b00000000, 0b00000000}
#define CHR_RBRACKET     {0b00000000, 0b10000010, 0b10000010, 0b11111110, 0b00000000, 0b00000000}
#define CHR_BACKSLASH    {0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000000}
#define CHR_SEMICOLON    {0b00000000, 0b00000000, 0b01101010, 0b01101100, 0b00000000, 0b00000000}
#define CHR_APOSTROPHE   {0b00000000, 0b00000000, 0b01110000, 0b00000000, 0b00000000, 0b00000000}
#define CHR_COMMA        {0b00000000, 0b00000000, 0b00001010, 0b00001100, 0b00000000, 0b00000000}
#define CHR_PERIOD       {0b00000000, 0b00000000, 0b00000110, 0b00000110, 0b00000000, 0b00000000}
#define CHR_SLASH        {0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b00000000}
#define CHR_SPACE        {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
#define CHR_DEGREES      {0b11000000, 0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}

// Graphics
#define CHR_CENT         {0b00111000, 0b01000100, 0b11111110, 0b01000100, 0b00101000, 0b00000000}
#define CHR_DEGREES_C    {0b11000000, 0b11001100, 0b00010010, 0b00010010, 0b00000000, 0b00000000}
#define CHR_DEGREES_F    {0b11000000, 0b11011110, 0b00010100, 0b00010000, 0b00000000, 0b00000000}
#define CHR_DIVISION     {0b00010000, 0b00010000, 0b01010100, 0b00010000, 0b00010000, 0b00000000}
#define CHR_LEFT_ARROW   {0b00010000, 0b00111000, 0b01010100, 0b00010000, 0b00010000, 0b00000000}
#define CHR_RIGHT_ARROW  {0b00010000, 0b00010000, 0b01010100, 0b00111000, 0b00010000, 0b00000000}
#define CHR_UP_ARROW     {0b00010000, 0b00100000, 0b01111110, 0b00100000, 0b00010000, 0b00000000}
#define CHR_DOWN_ARROW   {0b00001000, 0b00000100, 0b01111110, 0b00000100, 0b00001000, 0b00000000}
#define CHR_PI           {0b00100010, 0b00111100, 0b00100000, 0b00111110, 0b00100010, 0b00000000}
#define CHR_PSI          {0b01111000, 0b00001000, 0b01111110, 0b00001000, 0b01111000, 0b00000000}

// Predefined messages
#define MSG_FONTTEST {CHR_TILDE, CHR_BANG, CHR_AT, CHR_POUND, CHR_PERCENT, CHR_CARET, CHR_AMPERSAND, CHR_LPAREN, CHR_RPAREN, CHR_UNDERSCORE, CHR_PLUS, CHR_BACKTICK, CHR_1, CHR_2, CHR_3, CHR_4, CHR_5, CHR_6, CHR_7, CHR_8, CHR_9, CHR_0, CHR_DASH, CHR_EQUAL, CHR_A, CHR_B, CHR_C, CHR_D, CHR_E, CHR_F, CHR_G, CHR_H, CHR_I, CHR_J, CHR_K, CHR_L, CHR_M, CHR_N, CHR_O, CHR_P, CHR_Q, CHR_R, CHR_S, CHR_T, CHR_U, CHR_V, CHR_W, CHR_X, CHR_Y, CHR_Z, CHR_a, CHR_b, CHR_c, CHR_d, CHR_e, CHR_f, CHR_g, CHR_h, CHR_i, CHR_j, CHR_k, CHR_l, CHR_m, CHR_n, CHR_o, CHR_p, CHR_q, CHR_r, CHR_s, CHR_t, CHR_u, CHR_v, CHR_w, CHR_x, CHR_y, CHR_z, CHR_LCURLY, CHR_RCURLY, CHR_PIPE, CHR_COLON, CHR_QUOTE, CHR_LESSTHAN, CHR_GREATERTHAN, CHR_QUESTIONMARK, CHR_INTERROBANG, CHR_LBRACKET, CHR_RBRACKET, CHR_BACKSLASH, CHR_SEMICOLON, CHR_APOSTROPHE, CHR_COMMA, CHR_PERIOD, CHR_SLASH, CHR_CENT, CHR_DEGREES, CHR_DEGREES_C, CHR_DEGREES_F, CHR_DIVISION, CHR_LEFT_ARROW, CHR_RIGHT_ARROW, CHR_UP_ARROW, CHR_DOWN_ARROW, CHR_PI, CHR_PSI}
#define MSG_FONTTEST_LEN 104

#define MSG_CLUEBOARD {CHR_INTERROBANG, CHR_C, CHR_l, CHR_u, CHR_e, CHR_b, CHR_o, CHR_a, CHR_r, CHR_d}
#define MSG_CLUEBOARD_LEN 10

#define MSG_KONAMI {CHR_UP_ARROW, CHR_SPACE, CHR_UP_ARROW, CHR_SPACE, CHR_DOWN_ARROW, CHR_SPACE, CHR_DOWN_ARROW, CHR_SPACE, CHR_LEFT_ARROW, CHR_SPACE, CHR_RIGHT_ARROW, CHR_SPACE, CHR_LEFT_ARROW, CHR_SPACE, CHR_RIGHT_ARROW, CHR_SPACE, CHR_B, CHR_SPACE, CHR_A, CHR_SPACE, CHR_LESSTHAN, CHR_S, CHR_E, CHR_L, CHR_E, CHR_C, CHR_T, CHR_GREATERTHAN, CHR_SPACE, CHR_LESSTHAN, CHR_S, CHR_T, CHR_A, CHR_R, CHR_T, CHR_GREATERTHAN}
#define MSG_KONAMI_LEN 36

#define MSG_QMK_POWERED {CHR_PSI, CHR_P, CHR_o, CHR_w, CHR_e, CHR_r, CHR_e, CHR_d, CHR_SPACE, CHR_b, CHR_y, CHR_SPACE, CHR_Q, CHR_M, CHR_K}
#define MSG_QMK_POWERED_LEN 15
