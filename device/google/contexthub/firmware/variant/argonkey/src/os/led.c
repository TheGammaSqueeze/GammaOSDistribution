/*
 * Copyright (C) 2017 STMicroelectronics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <leds_gpio.h>
#include <util.h>
#include <plat/gpio.h>

static uint32_t local_leds_array[] = {
    GPIO_PC(13), /* GPIO_LED0 */ \
    GPIO_PB(2)   /* GPIO_LED1 */
};

static struct LedsGpio local_leds = {
    .leds_array = local_leds_array,
    .num = ARRAY_SIZE(local_leds_array),
};

const struct LedsGpio *ledsGpioBoardCfg(void)
{
    return &local_leds;
}
