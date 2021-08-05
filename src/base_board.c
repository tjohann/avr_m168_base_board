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
#include "usart.h"

void __attribute__((noinline)) init_hw(void)
{
	init_usart();

	LED_DDR |= (1 << LED);
}

void init_base_board(void)
{
	LED_PORT |= (1 << LED);

	send_string("Press 1 for LED on");
	send_string("Press 0 for LED off");
	send_string("All other keys toggle the LED");

	_delay_ms(1000);
}

int __attribute__((OS_main)) main(void)
{
	init_hw();
	init_base_board();

	uint8_t ret = 0;
	while (1) {
		ret = recv_byte();

		if (ret == '1') {
			LED_PORT |= (1 << LED);
			send_string("LED on");
		} else if (ret == '0') {
			LED_PORT &= ~(1 << LED);
			send_string("LED off");
		} else {
			LED_PORT ^= (1 << LED);
			send_string("toggle LED");
		}
	}
}
