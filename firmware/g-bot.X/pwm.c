
#include "pwm.h"

int PWM_Max_Duty() {    
    return (_XTAL_FREQ / (freq * TMR2PRESCALE);
}

void PWM1_Init(long fre) {
    PR2 = (_XTAL_FREQ / (fre * 4 * TMR2PRESCALE)) - 1;
    freq = fre;
}

void PWM2_Init(long fre) {
    PR2 = (_XTAL_FREQ / (fre * 4 * TMR2PRESCALE)) - 1;
    freq = fre;
}

void PWM1_Duty(unsigned int duty) {
    if (duty < 1024) {
        duty = ((float) duty / 1023) * PWM_Max_Duty();
        CCP1X = duty & 2;
        CCP1Y = duty & 1;
        CCPR1L = duty >> 2;
    }
}

void PWM2_Duty(unsigned int duty) {
    if (duty < 1024) {
        duty = ((float) duty / 1023) * PWM_Max_Duty();
        CCP2X = duty & 2;
        CCP2Y = duty & 1;
        CCPR2L = duty >> 2;
    }
}

void PWM1_Start() {

    CCP1M3 = 1;
    CCP1M2 = 1;
    
#if TMR2PRESCALAR == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALAR == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#elif TMR2PRESCALAR == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1;
    TRISC2 = 0;
}

void PWM1_Stop() {
    CCP1M3 = 0;
    CCP1M2 = 0;
}

void PWM2_Start() {
    CCP2M3 = 1;
    CCP2M2 = 1;
#if TMR2PRESCALE == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1;
    TRISC1 = 0;
}

void PWM2_Stop() {
    CCP2M3 = 0;
    CCP2M2 = 0;
}