#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <STC8G.H>

// PWM 配置参数定义
#define BREATH_STEP     1       // 亮度渐变步进值
#define MIN_DUTY        0       // 最小亮度(0-255)
#define MAX_DUTY        255     // 最大亮度(0-255)
#define BREATH_DELAY    50      // 每次改变亮度的延时(ms)
#define HOLD_TIME       1500    // 在最亮和最暗处停留的时间(ms)

// 引脚定义
sbit BUZZER = P3^3;            // 蜂鸣器引脚

// 全局变量声明
extern unsigned char g_duty;    // 当前PWM占空比值
extern bit g_direction;         // 亮度变化方向
extern unsigned char g_mode;    // 工作模式：0-常亮模式，1-呼吸灯模式，2-音乐模式
extern bit g_button_previous;   // 按键前一状态
extern unsigned char FreqSelect, MusicSelect;

// 函数声明
void Timer0Init(void);          // 定时器0初始化（用于蜂鸣器）
void Timer1Init(void);          // 定时器1初始化（用于LED PWM）
void Delay_ms(unsigned int ms); // 毫秒延时函数
void initSystem(void);          // 系统初始化

#endif