The code
========

Some small overview of the code.


LED
---

Defines:

	LED PB0
	LED_DDR DDRB
	LED_PORT PORTB

Usart
-----

API:

	void init_usart(void);

	void send_byte(uint8_t data);
	uint8_t recv_byte(void);

	void send_string(const char str[]);
	void recv_string(char str[], uint8_t len);

