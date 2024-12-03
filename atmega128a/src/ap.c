#include "ap.h"
#include "driver/led.h"
#include "driver/button.h"
#include "driver/pwm8.h"
#include "driver/uart0.h"
#include "driver/i2c.h"
#include "driver/i2c_lcd.h"
#include <avr/interrupt.h>
#include <driver/pwm16.h>
char buff[50];  // buff를 uint8_t*에서 char*로 수정

void apInit() {
   // UART0_init(9600); // UART 초기화 (9600bps)
   // UART1_init(9600); // 9600bps로 UART1 초기화
   // sei();            // 전역 인터럽트 활성화

}

void apMain() {
    // LCD 초기화 및 초기 메시지 표시
    LCD_Init();
    LCD_WriteStringXY(0, 0, "Hello ATmega128a");
    
    uint16_t count = 0;
  //  uint8_t buff[30];

    while (1) {
    sprintf(buff, "count : %-5d", count++);
    LCD_WriteStringXY(1, 0, buff);
    _delay_ms(100);
        // 메인 루프는 인터럽트에서 처리
    }
}