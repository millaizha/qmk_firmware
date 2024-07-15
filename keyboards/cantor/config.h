// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

// Tap hold configurations
#define TAPPING_TERM 350
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

