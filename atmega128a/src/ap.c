#include "ap.h"
#include "driver/led.h"
#include "driver/button.h"
#include "driver/pwm16.h"
#include "driver/uart0.h"
#include "driver/ultrasonic.h"

 void apInit()
 {
    
 }


 void apMain(void)
{




    DDRA = 0xff;
    // LED led;
    // led.port = &PORTB;
    // led.pin = 0;
    // ledInit(&led);

//     Button btnOn;
//     Button btnOff;
//     Button btnTog;

//     buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
//     buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
//     buttonInit(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);

//     pwm8Init();

 
 
    
    //pwm16Init();    // PWM 초기화-------------



    uart0Init();  // uart0 초기화
    //출력 스트림 설정 <stdio.h> 에 있는 표준 입출력임
    FILE OUTPUT = FDEV_SETUP_STREAM(uart0Transmit_wrapper, NULL, _FDEV_SETUP_WRITE); 

    stdout = &OUTPUT;
    extern char rxBuff[100]; 
    extern volatile uint8_t rxFlag;

    sei();

    //LCD 글자출력
    // LCD_Init();
    // LCD_WriteStringXY(0,0, "Hello ATmega128a");
    // uint16_t count = 0;
    // uint8_t buff[30];

    //초음파 
    timerInit();
    uint8_t distance;

    while(1)
    {
        //초음파센서 거리측정
        triggerPin();
        distance = meanDistance();
        printf("distance : %d cm\r\n", distance);
        _delay_ms(500);

        //LCD count표시
        // sprintf(buff, "count: %-5d", count++);
        // LCD_WriteStringXY(1, 0, "                "); // 기존 데이터 지움
        // LCD_WriteStringXY(1, 0, buff); // 새 데이터 출력
        // _delay_ms(100);




        if(rxFlag == 1) //문자열 수신이 완료되면
        {
            rxFlag = 0; // 문자열 수신 플래그 초기화

            uart0Print(rxBuff);

            //printf(rxBuff); // 수신된 문자열 출력

        }



        // //uart0Transmit(uart0Receive());  // 받아짐글자
   
        // char receivedByte = uart0Receive();  // 시리얼로부터 받은 데이터

        // // 시리얼에서 숫자 'a'을 입력하면 서보모터를 0도 위치로 설정
        // if (receivedByte == 'a') 
        // {
        
        //     OCR3A = 115;
        //     _delay_ms(100);
        //     ledOn(&led);
        //     uart0Transmit('L');  // 'L'은 LED ON을 알리는 문자
        //     uart0Transmit('E');
        //     uart0Transmit('D');
        //     uart0Transmit(' ');
        //     uart0Transmit('O');
        //     uart0Transmit('N');
        //     uart0Transmit('\n'); // LED ON 메시지 출력
        // }
        // // 시리얼에서 숫자 'b'를 입력하면 서보모터를 180도 위치로 설정
        // else if (receivedByte == 'b') 
        // {
        //      OCR3A = 625;
        //     _delay_ms(100);
        //     ledOff(&led);
        //    uart0Transmit('L');  // 'L'은 LED OFF를 알리는 문자
        //    uart0Transmit('E');
        //    uart0Transmit('D');
        //    uart0Transmit(' ');
        //    uart0Transmit('O');
        //    uart0Transmit('F');
        //    uart0Transmit('F');
        //    uart0Transmit('\n'); // LED OFF 메시지 출력
        // }

        // OCR3A = 115;
        // _delay_ms(1000);

        // OCR3A = 625;
        // _delay_ms(1000);



        // if(buttonGetState(&btnOn) == ACT_RELEASED)
        // {
        //     ledOn(&led);
        //     pwm8Run(250);
        // }

        // if(buttonGetState(&btnOff)==ACT_RELEASED)
        // {
        //     ledOff(&led);
        //     pwm8Run(0);
        // }

        // // if(buttonGetState(&btnTog)== ACT_RELEASED)
        // // {
            
        // // }
    }

}  

    
