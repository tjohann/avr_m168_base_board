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

#include "base_board.h"

void __attribute__((noinline)) init_base_board(void)
{
	LED_DDR  |= (1 << LED);
	LED_PORT |= (1 << LED);

	_delay_ms(1000);
}

int __attribute__((OS_main)) main(void)
{
	init_base_board();

	while (1) {
		LED_PORT ^= (1 << LED);
		_delay_ms(1000);
	}
}
