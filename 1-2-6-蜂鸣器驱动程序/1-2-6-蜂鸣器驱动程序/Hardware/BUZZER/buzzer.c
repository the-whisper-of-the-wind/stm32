

/*
//�������ҳ�Ʒ
//����ϵ�п�����Ӧ�ó���
//��ע΢�Ź��ںţ����ҵ���
//���ҿ������������� www.DoYoung.net/YT
//������ѿ����н�ѧ��Ƶ�����ؼ������ϣ�������������
//�������ݾ��� ����������ҳ www.doyoung.net
*/

/*
���޸���־��
1-201709012309 ������


*/

#include "buzzer.h"
#include "delay.h"

void BUZZER_Init(void)
{ // �������Ľӿڳ�ʼ��
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = BUZZER;			  // ѡ��˿ں�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // ѡ��IO�ӿڹ�����ʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // ����IO�ӿ��ٶȣ�2/10/50MHz��
	GPIO_Init(BUZZERPORT, &GPIO_InitStructure);

	GPIO_WriteBit(BUZZERPORT, BUZZER, (BitAction)(1)); // �������ӿ�����ߵ�ƽ1,�ߵ�ƽ�Ͽ�,����������
}

void BUZZER_BEEP1(void) //! �������Զ��������ĺ���,��������ͬ���ȡ���������ʾ��,����������Ĳ�ͬλ��
{						// ��������һ��
	u16 i;
	for (i = 0; i < 200; i++) //! �޸�ѭ����������������ʱ��
	{
		GPIO_WriteBit(BUZZERPORT, BUZZER, (BitAction)(0)); // �������ӿ����0
		delay_us(500);									   // ��ʱ		//! ����ͨ���޸���ʱ��ʱ��ı����ڵ�ʱ�������
		GPIO_WriteBit(BUZZERPORT, BUZZER, (BitAction)(1)); // �������ӿ�����ߵ�ƽ1 //!������ߵ�ƽΪ����
		delay_us(500);									   // ��ʱ		//!����һ�����ڵ�ʱ����1000us
	}
}

/*********************************************************************************************
 * �������� www.DoYoung.net
 * ���ҵ��� www.DoYoung.net/YT
 *********************************************************************************************/

/*
ѡ��IO�ӿڹ�����ʽ��
GPIO_Mode_AIN ģ������
GPIO_Mode_IN_FLOATING ��������
GPIO_Mode_IPD ��������
GPIO_Mode_IPU ��������
GPIO_Mode_Out_PP �������
GPIO_Mode_Out_OD ��©���
GPIO_Mode_AF_PP �����������
GPIO_Mode_AF_OD ���ÿ�©���
*/
