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

int main(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

    TIM6->PSC   =   41999;
    TIM6->DIER  |=  TIM_DIER_UIE;
    TIM6->ARR   =   999;
    TIM6->CR1   |=  TIM_CR1_ARPE | TIM_CR1_CEN;
    TIM6->EGR   =   TIM_EGR_UG;
    TIM6->SR    &=  ~TIM_SR_UIF;

    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_LEDInit(LED6);

    STM_EVAL_LEDOff(LED3);
    STM_EVAL_LEDOff(LED4);
    STM_EVAL_LEDOff(LED5);
    STM_EVAL_LEDOff(LED6);
    
    while(1) {
        while((TIM6->SR & 0x1) == 0);
        TIM6->SR = 0;

        STM_EVAL_LEDToggle(LED3);
        STM_EVAL_LEDToggle(LED4);
        STM_EVAL_LEDToggle(LED5);
        STM_EVAL_LEDToggle(LED6);
    }

    return 0;
}
