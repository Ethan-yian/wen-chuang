#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <STC8G.H>

// PWM ���ò�������
#define BREATH_STEP     1       // ���Ƚ��䲽��ֵ
#define MIN_DUTY        0       // ��С����(0-255)
#define MAX_DUTY        255     // �������(0-255)
#define BREATH_DELAY    50      // ÿ�θı����ȵ���ʱ(ms)
#define HOLD_TIME       1500    // �����������ͣ����ʱ��(ms)

// ���Ŷ���
sbit BUZZER = P3^3;            // ����������

// ȫ�ֱ�������
extern unsigned char g_duty;    // ��ǰPWMռ�ձ�ֵ
extern bit g_direction;         // ���ȱ仯����
extern unsigned char g_mode;    // ����ģʽ��0-����ģʽ��1-������ģʽ��2-����ģʽ
extern bit g_button_previous;   // ����ǰһ״̬
extern unsigned char FreqSelect, MusicSelect;

// ��������
void Timer0Init(void);          // ��ʱ��0��ʼ�������ڷ�������
void Timer1Init(void);          // ��ʱ��1��ʼ��������LED PWM��
void Delay_ms(unsigned int ms); // ������ʱ����
void initSystem(void);          // ϵͳ��ʼ��

#endif