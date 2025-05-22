#include "config.h"

// 全局变量定义
unsigned char g_duty = MAX_DUTY;    // 当前PWM占空比值
bit g_direction = 0;                // 亮度变化方向
unsigned char g_mode = 0;         // 工作模式：
                                 // 0-常亮模式
                                 // 1-呼吸灯模式
                                 // 2-音乐模式
                                 // 3-常亮+音乐模式
                                 // 4-呼吸灯+音乐模式
bit g_button_previous = 1;          // 按键前一状态
unsigned char FreqSelect = 0, MusicSelect = 0;



// 系统初始化函数
void initSystem(void)
{
    // LED引脚初始化 (P3.2)
    P3M0 |= 0x04;
    P3M1 &= ~0x04;
    
    // 按键引脚初始化 (P5.5)
    P5M0 &= ~0x20;
    P5M1 &= ~0x20;
    
    // 蜂鸣器引脚初始化 (P3.3)
    P3M1 &= ~(1<<3);
    P3M0 |= (1<<3);
    BUZZER = 0;
    
    // 初始化定时器
    Timer0Init();  // 用于蜂鸣器
    Timer1Init();  // 用于LED PWM
    
    // 开启总中断
    EA = 1;
}

// Timer0 初始化 (用于蜂鸣器)
void Timer0Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TL0 = 0x18;
    TH0 = 0xFC;
    TF0 = 0;
    TR0 = 0;        // 初始停止定时器0
    ET0 = 1;        // 使能定时器0中断
    PT0 = 0;
}

// Timer1 初始化 (用于LED PWM)
void Timer1Init(void)
{
    AUXR &= 0xBF;
    TMOD &= 0x0F;
    TMOD |= 0x00;
    TL1 = 0xF0;
    TH1 = 0xFF;
    TF1 = 0;
    TR1 = 1;
    ET1 = 1;
}

// 毫秒延时函数
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned char j;
    for(i = ms; i > 0; i--)
        for(j = 110; j > 0; j--);
}