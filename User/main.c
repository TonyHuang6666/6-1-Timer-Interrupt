#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"

uint16_t Number=0;

int main(void)
{
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1, 1, "Number:");
	while(1)
	{
		OLED_ShowNum(1, 8, Number, 5);
	}
}
void TIM2_IRQHandler(void)
{
    //1.检查中断标志位
    if (TIM_GetITStatus(TIM2, TIM_IT_Update)==SET)
    {
        //执行用户代码
        Number++;
        //2.清除中断标志位
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
