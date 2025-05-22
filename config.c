#include "config.h"

// ȫ�ֱ�������
unsigned char g_duty = MAX_DUTY;    // ��ǰPWMռ�ձ�ֵ
bit g_direction = 0;                // ���ȱ仯����
unsigned char g_mode = 0;         // ����ģʽ��
                                 // 0-����ģʽ
                                 // 1-������ģʽ
                                 // 2-����ģʽ
                                 // 3-����+����ģʽ
                                 // 4-������+����ģʽ
bit g_button_previous = 1;          // ����ǰһ״̬
unsigned char FreqSelect = 0, MusicSelect = 0;



// ϵͳ��ʼ������
void initSystem(void)
{
    // LED���ų�ʼ�� (P3.2)
    P3M0 |= 0x04;
    P3M1 &= ~0x04;
    
    // �������ų�ʼ�� (P5.5)
    P5M0 &= ~0x20;
    P5M1 &= ~0x20;
    
    // ���������ų�ʼ�� (P3.3)
    P3M1 &= ~(1<<3);
    P3M0 |= (1<<3);
    BUZZER = 0;
    
    // ��ʼ����ʱ��
    Timer0Init();  // ���ڷ�����
    Timer1Init();  // ����LED PWM
    
    // �������ж�
    EA = 1;
}

// Timer0 ��ʼ�� (���ڷ�����)
void Timer0Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TL0 = 0x18;
    TH0 = 0xFC;
    TF0 = 0;
    TR0 = 0;        // ��ʼֹͣ��ʱ��0
    ET0 = 1;        // ʹ�ܶ�ʱ��0�ж�
    PT0 = 0;
}

// Timer1 ��ʼ�� (����LED PWM)
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

// ������ʱ����
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned char j;
    for(i = ms; i > 0; i--)
        for(j = 110; j > 0; j--);
}