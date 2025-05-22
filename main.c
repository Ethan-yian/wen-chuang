#include <STC8G.H>
#include "music_defs.h"
#include "config.h"

// Timer0 �жϷ����� (����������)
void Timer0_Routine() interrupt 1
{
    if(FreqTable[FreqSelect])    //���������ֹ��
    {
        TL0 = FreqTable[FreqSelect]%256;        //���ö�ʱ��ֵ
        TH0 = FreqTable[FreqSelect]/256;        //���ö�ʱ��ֵ
        BUZZER=!BUZZER;    //��ת������IO��
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
    unsigned int musicPart = 0;  // ���ڼ�¼���ֲ��ŵĲ���
    unsigned char code *currentMusic = Music1; // ��ǰ���ŵ���������ָ��
    
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
                        musicPart = 0;    // �������ֲ���
                        currentMusic = Music1; // ���õ���һ������
                        TR0 = 1;  // ������������ʱ��
                        break;

                    case 3:  // ����ģʽ3��ѭ�����ŵ�5-8������
                        g_duty = MAX_DUTY;  // LED����
                        MusicSelect = 0;  // �������ֲ���λ��
                        musicPart = 4;    // �ӵ�5�ο�ʼ
                        currentMusic = Music5; // �ӵ�5�����ֿ�ʼ
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
            
            case 2:  // ������ģʽ
                g_duty = MAX_DUTY;  // ����LED����

                // ���ֲ����߼�
                if(currentMusic[MusicSelect] != 0xFF)
                {
                    FreqSelect = currentMusic[MusicSelect];
                    MusicSelect++;
                    
                    Delay_ms(SPEED_1/4*currentMusic[MusicSelect]);
                    MusicSelect++;
                    
                    TR0 = 0;
                    Delay_ms(5);
                    TR0 = 1;
                }
                else
                {
                    // �л����ֶ���
                    musicPart++;
                    MusicSelect = 0;
                    
                    switch(musicPart)
                    {
                        case 1:
                            currentMusic = Music2;
                            break;
                        case 2:
                            currentMusic = Music3;
                            break;
                        case 3:
                            currentMusic = Music4;
                            break;
                        default:
                            currentMusic = Music1;
                            musicPart = 0;
                            break;
                    }
                }
                break;

            case 3:  
                g_duty = MAX_DUTY;  // ����LED����

                // ���ֲ����߼�
                if(currentMusic[MusicSelect] != 0xFF)
                {
                    FreqSelect = currentMusic[MusicSelect];
                    MusicSelect++;
                    
                    Delay_ms(SPEED_2/4*currentMusic[MusicSelect]);
                    MusicSelect++;
                    
                    TR0 = 0;
                    Delay_ms(5);
                    TR0 = 1;
                }
                else
                {
                    // �л����ֶ���
                    musicPart++;
                    MusicSelect = 0;
                    
                    switch(musicPart)
                    {
                        case 5:
                            currentMusic = Music6;
                            break;
                        case 6:
                            currentMusic = Music7;
                            break;
                        case 7:
                            currentMusic = Music8;
                            break;
                        default:
                            currentMusic = Music5;
                            musicPart = 4;
                            break;
                    }
                }
                break;
        }
    }
}