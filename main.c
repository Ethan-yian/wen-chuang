#include <STC8G.H>
#include "music_defs.h"
#include "config.h"

// Timer0 中断服务函数 (蜂鸣器控制)
void Timer0_Routine() interrupt 1
{
    if(FreqTable[FreqSelect])
    {
        TL0 = FreqTable[FreqSelect]%256;
        TH0 = FreqTable[FreqSelect]/256;
        BUZZER = !BUZZER;
    }
}

// Timer1 中断服务函数 (LED PWM控制)
void Timer1_ISR() interrupt 3
{
    static unsigned char count = 0;
    
    if(count < g_duty)
    {
        P3 |= 0x04;     // LED点亮
    }
    else
    {
        P3 &= ~0x04;    // LED熄灭
    }
    
    count++;
    if(count >= 255)
    {
        count = 0;
    }
}

void main(void)
{
    unsigned int hold_count = 0;
    
    initSystem();  // 初始化系统
    
    while(1)
    {
        // 按键检测和模式切换（带消抖）
        if ((P5 & 0x20) == 0)  // 按键被按下
        {
            if (g_button_previous == 1)
            {
                g_mode = (g_mode + 1) % 4;  // 在四种模式间循环
                
                // 模式切换处理
                switch(g_mode)
                {
                    case 0:  // 常亮模式
                        g_duty = MAX_DUTY;
                        TR0 = 0;  // 停止蜂鸣器定时器
                        BUZZER = 0;
                        break;
                    
                    case 1:  // 呼吸灯模式
                        TR0 = 0;  // 停止蜂鸣器定时器
                        BUZZER = 0;
                        break;
                    
                    case 2:  // 常亮+音乐模式
                        g_duty = MAX_DUTY;  // LED常亮
                        MusicSelect = 0;  // 重置音乐播放位置
                        TR0 = 1;  // 启动蜂鸣器定时器
                        break;

                    case 3:  // 纯音乐模式
                        g_duty = 0;  // LED关闭
                        MusicSelect = 0;  // 重置音乐播放位置
                        TR0 = 1;  // 启动蜂鸣器定时器
                        break;
                }
            }
            g_button_previous = 0;
        }
        else
        {
            g_button_previous = 1;
        }
        
        // 模式运行逻辑
        switch(g_mode)
        {
            case 0:  // 常亮模式
                g_duty = MAX_DUTY;
                break;
            
            case 1:  // 呼吸灯模式
                // 在最亮或最暗处停留
                if(g_duty == MAX_DUTY || g_duty == MIN_DUTY)
                {
                    for(hold_count = 0; hold_count < HOLD_TIME; hold_count++)
                    {
                        Delay_ms(1);
                    }
                }
                
                // 更新亮度值
                if(g_direction == 0)
                {
                    g_duty += BREATH_STEP;
                    if(g_duty >= MAX_DUTY)
                    {
                        g_duty = MAX_DUTY;
                        g_direction = 1;
                    }
                }
                else
                {
                    if(g_duty > MIN_DUTY + BREATH_STEP)
                    {
                        g_duty -= BREATH_STEP;
                    }
                    else
                    {
                        g_duty = MIN_DUTY;
                        g_direction = 0;
                    }
                }
                Delay_ms(BREATH_DELAY);
                break;
            
            case 2:  // 常亮+音乐模式
                g_duty = MAX_DUTY;  // 保持LED常亮
                if(Music[MusicSelect] != 0xFF)
                {
                    FreqSelect = Music[MusicSelect];
                    MusicSelect++;
                    Delay_ms(SPEED/4*Music[MusicSelect]);
                    MusicSelect++;
                    TR0 = 0;
                    Delay_ms(5);
                    TR0 = 1;
                }
                else
                {
                    MusicSelect = 0;  // 循环播放音乐
                }
                break;

            case 3:  // 纯音乐模式
                if(Music[MusicSelect] != 0xFF)
                {
                    FreqSelect = Music[MusicSelect];
                    MusicSelect++;
                    Delay_ms(SPEED/4*Music[MusicSelect]);
                    MusicSelect++;
                    TR0 = 0;
                    Delay_ms(5);
                    TR0 = 1;
                }
                else
                {
                    MusicSelect = 0;  // 循环播放音乐
                }
                break;
        }
    }
}