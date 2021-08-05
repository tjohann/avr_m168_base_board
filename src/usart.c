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

#include "usart.h"

void init_usart(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

#if USE_2X
	UCSR0A |= (1 << U2X0);
#else
	UCSR0A &= ~(1 << U2X0);
#endif
	UCSR0B = (1 << TXEN0)  | (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  /* 8N1 */
}

void send_byte(uint8_t data)
{
	/* block until UDRE0 (Data Register Empty) is set */
	while (!(UCSR0A & (1 << UDRE0)))
		;

	UDR0 = data;
}

uint8_t recv_byte(void)
{
	/* block until RXC0 (Receive Complete) is set */
	while (!(UCSR0A & (1 << RXC0)))
		;

	return UDR0;
}

void send_string(const char str[])
{
	uint8_t i = 0;

	while(str[i])
		send_byte(str[i++]);
}

void recv_string(char str[], uint8_t len)
{
	uint8_t i = 0;
	char ret = 0;

	memset(0, str, len);
	while (i < len) {
		ret = recv_byte();
		if (ret == '\r')
			break;

		str[i] = ret;
		i++;
	}
}
