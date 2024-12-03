#include "common/def.h"


void uart0Init();
void uart0Transmit(char data);
int uart0Transmit_wrapper(char c, FILE *stream);
unsigned uart0Receive(void);
void uart0Print(const char *str);