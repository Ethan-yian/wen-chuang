#include <STC8G.H>
#include "music_defs.h"
#include "config.h"

// Timer0 �жϷ����� (����������)
void Timer0_Routine() interrupt 1
{
    if(FreqTable[FreqSelect])
    {
        TL0 = FreqTable[FreqSelect]%256;
        TH0 = FreqTable[FreqSelect]/256;
        BUZZER = !BUZZER;
    }
}

// Timer1 �жϷ����� (LED PWM����)
void Timer1_ISR() interrupt 3
{
    static unsigned char count = 0;
    
    if(count < g_duty)
    {
        P3 |= 0x04;     // LED����
    }
    else
    {
        P3 &= ~0x04;    // LEDϨ��
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
    
    initSystem();  // ��ʼ��ϵͳ
    
    while(1)
    {
        // ��������ģʽ�л�����������
        if ((P5 & 0x20) == 0)  // ����������
        {
            if (g_button_previous == 1)
            {
                g_mode = (g_mode + 1) % 4;  // ������ģʽ��ѭ��
                
                // ģʽ�л�����
                switch(g_mode)
                {
                    case 0:  // ����ģʽ
                        g_duty = MAX_DUTY;
                        TR0 = 0;  // ֹͣ��������ʱ��
                        BUZZER = 0;
                        break;
                    
                    case 1:  // ������ģʽ
                        TR0 = 0;  // ֹͣ��������ʱ��
                        BUZZER = 0;
                        break;
                    
                    case 2:  // ����+����ģʽ
                        g_duty = MAX_DUTY;  // LED����
                        MusicSelect = 0;  // �������ֲ���λ��
                        TR0 = 1;  // ������������ʱ��
                        break;

                    case 3:  // ������ģʽ
                        g_duty = 0;  // LED�ر�
                        MusicSelect = 0;  // �������ֲ���λ��
                        TR0 = 1;  // ������������ʱ��
                        break;
                }
            }
            g_button_previous = 0;
        }
        else
        {
            g_button_previous = 1;
        }
        
        // ģʽ�����߼�
        switch(g_mode)
        {
            case 0:  // ����ģʽ
                g_duty = MAX_DUTY;
                break;
            
            case 1:  // ������ģʽ
                // �����������ͣ��
                if(g_duty == MAX_DUTY || g_duty == MIN_DUTY)
                {
                    for(hold_count = 0; hold_count < HOLD_TIME; hold_count++)
                    {
                        Delay_ms(1);
                    }
                }
                
                // ��������ֵ
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
            
            case 2:  // ����+����ģʽ
                g_duty = MAX_DUTY;  // ����LED����
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
                    MusicSelect = 0;  // ѭ����������
                }
                break;

            case 3:  // ������ģʽ
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
                    MusicSelect = 0;  // ѭ����������
                }
                break;
        }
    }
}