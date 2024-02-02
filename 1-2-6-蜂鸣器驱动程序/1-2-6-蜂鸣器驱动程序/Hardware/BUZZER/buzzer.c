

/*
//杜洋工作室出品
//洋桃系列开发板应用程序
//关注微信公众号：洋桃电子
//洋桃开发板资料下载 www.DoYoung.net/YT
//即可免费看所有教学视频，下载技术资料，技术疑难提问
//更多内容尽在 杜洋工作室主页 www.doyoung.net
*/

/*
《修改日志》
1-201709012309 创建。


*/

#include "buzzer.h"
#include "delay.h"

void BUZZER_Init(void)
{ // 蜂鸣器的接口初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = BUZZER;			  // 选择端口号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 选择IO接口工作方式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置IO接口速度（2/10/50MHz）
	GPIO_Init(BUZZERPORT, &GPIO_InitStructure);

	GPIO_WriteBit(BUZZERPORT, BUZZER, (BitAction)(1)); // 蜂鸣器接口输出高电平1,高电平断开,保护蜂鸣器
}

void BUZZER_BEEP1(void) //! 还可以自定义其它的函数,来发出不同长度、音调的提示音,放在主程序的不同位置
{						// 蜂鸣器响一声
	u16 i;
	for (i = 0; i < 200; i++) //! 修改循环次数来控制声音时长
	{
		GPIO_WriteBit(BUZZERPORT, BUZZER, (BitAction)(0)); // 蜂鸣器接口输出0
		delay_us(500);									   // 延时		//! 可以通过修改延时的时间改变周期的时间和音调
		GPIO_WriteBit(BUZZERPORT, BUZZER, (BitAction)(1)); // 蜂鸣器接口输出高电平1 //!以输出高电平为结束
		delay_us(500);									   // 延时		//!这里一个周期的时间是1000us
	}
}

/*********************************************************************************************
 * 杜洋工作室 www.DoYoung.net
 * 洋桃电子 www.DoYoung.net/YT
 *********************************************************************************************/

/*
选择IO接口工作方式：
GPIO_Mode_AIN 模拟输入
GPIO_Mode_IN_FLOATING 浮空输入
GPIO_Mode_IPD 下拉输入
GPIO_Mode_IPU 上拉输入
GPIO_Mode_Out_PP 推挽输出
GPIO_Mode_Out_OD 开漏输出
GPIO_Mode_AF_PP 复用推挽输出
GPIO_Mode_AF_OD 复用开漏输出
*/
