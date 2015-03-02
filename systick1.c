
/*****************************************************************************
* Copyright &copy; 2013, Aaron Schmocker.
* All rights reserved.
*
* ##### GNU GENERAL PUBLIC LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
* MA 02110-1301, USA.
*
*****************************************************************************/
#include "stm32f4_discovery.h"

#define INT_PER_SEC 1000    
#if(INT_PER_SEC <= 10)
    #error "INT_PER_SEC value to low."
#endif

volatile unsigned int systick_cnt; 

void TimingDelay_Decrement(void)
{
    systick_cnt--;
}

void delay(unsigned int systicks)
{
    systick_cnt = systicks;
    
    while(systick_cnt > 0){
        ;
    }
}

void SysTick_Handler(void)
{
    TimingDelay_Decrement();
}

int main(void)
{
    SysTick_Config(SystemCoreClock/INT_PER_SEC);

    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_LEDInit(LED6);
    STM_EVAL_LEDOff(LED3);
    STM_EVAL_LEDOff(LED4);
    STM_EVAL_LEDOff(LED5);
    STM_EVAL_LEDOff(LED6);
    
    while(1) {
        delay(500); // 500ms
        STM_EVAL_LEDToggle(LED3);
        STM_EVAL_LEDToggle(LED4);
        STM_EVAL_LEDToggle(LED5);
        STM_EVAL_LEDToggle(LED6);
    }

    return 0;
}
