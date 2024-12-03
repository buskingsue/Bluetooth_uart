#include "pwm16.h"
#include "uart0.h" 

void pwm16Init()
{
    DDRE |= (1<<PORTE3);    //OC3A past PWM output

    //63분주, past PWM, 비반전모드
    TCCR3A |= (1<<COM3A1) | (1<<WGM31);
    TCCR3B |= (1<<WGM33) | (1<<WGM32) | (1<< CS31) | (1<<CS30);

    ICR3 = 4999; //탑값
    OCR3A = 0;  //-- 초기 듀티사이클 0 (pwm출력을 0%로 설정)
}


// // PWM 듀티 사이클 설정 함수
// void setPWMDutyCycle(uint16_t dutyCycle)
// {
//     if (dutyCycle > 100) {
//         dutyCycle = 100;  // 듀티 사이클이 100을 초과하지 않도록 제한
//     }

//     // 듀티 사이클을 비율에 맞게 설정
//     OCR3A = (dutyCycle * ICR3) / 100;  // 듀티 사이클을 0~4999 범위로 설정
// }

// ---------------서보모터 각도 설정 함수 (0도에서 180도)
void setServoAngle(uint8_t angle) 
{
    uint16_t dutyCycle;

    // 서보모터 각도를 5%에서 10% 듀티 사이클로 변환
    // 0도 -> 5%, 180도 -> 10%
    dutyCycle = (angle * 5 / 180) + 5;

    // 듀티 사이클을 설정 (OCR3A 레지스터에 듀티 사이클 값 저장)
    OCR3A = (dutyCycle * ICR3) / 100;  // 0~100% 듀티 사이클에 맞게 OCR3A 값 설정
}