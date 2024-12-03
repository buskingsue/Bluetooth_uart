#include "common/def.h"

void UART0_init(uint16_t baudrate);
void UART1_init(uint16_t baudrate);
void UART0_transmit(char data);
void UART1_transmit(char data);
void UART0_transmit_string(const char *str);
void UART1_transmit_string(const char *str);
ISR(USART0_RX_vect);
ISR(USART1_RX_vect);