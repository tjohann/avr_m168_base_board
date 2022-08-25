/*
  GPL
  (c) 2021, thorsten.johannvorderbrueggen@t-online.de

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/

#include <avr/io.h>
#include <util/setbaud.h>
#include <string.h>

#ifndef BAUD
#  error "BAUD rate not defined!"
#endif

void init_usart(void);

void send_byte(uint8_t data);
uint8_t recv_byte(void);

void send_string(const char str[]);
void recv_string(char str[], uint8_t len);
