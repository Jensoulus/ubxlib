/*
 * Copyright 2020 u-blox Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _U_CFG_OS_PLATFORM_SPECIFIC_H_
#define _U_CFG_OS_PLATFORM_SPECIFIC_H_

/* No #includes allowed here */

/** @file
 * @brief This header file contains OS configuration information for
 * an STM32F4 processor.
 */

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR STM32F4: OS GENERIC
 * -------------------------------------------------------------- */

#ifndef U_CFG_OS_PRIORITY_MIN
/** The minimum task priority. cmsis-os defines osPriorityIdle
 * as 1 (priority 0 is "undefined priority").
 */
# define U_CFG_OS_PRIORITY_MIN 1
#endif

#ifndef U_CFG_OS_PRIORITY_MAX
/** The maximum task priority, should be less than or
 * equal to configMAX_PRIORITIES defined in FreeRTOSConfig.h,
 * which is set to 15. cmsis-os defines osPriorityISR
 * as 56 but when this is mapped to FreeRTOS, as it is on
 * this platform, the range gets squished.
 */
# define U_CFG_OS_PRIORITY_MAX 15
#endif

#ifndef U_CFG_OS_YIELD_MS
/** The amount of time to block for to ensure that a yield
 * occurs. This set to 1 ms as the STM32F4 platform has a
 * 1 ms tick.
 */
# define U_CFG_OS_YIELD_MS 1
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR STM32F4: STACK SIZES/PRIORITIES
 * -------------------------------------------------------------- */

/** How much stack the task running all the examples/tests needs in
 * bytes.
 */
#define U_CFG_OS_APP_TASK_STACK_SIZE_BYTES (1024 * 4)

/** The priority of the task running the examples/tests: should be
 * low.
 */
#define U_CFG_OS_APP_TASK_PRIORITY (U_CFG_OS_PRIORITY_MIN + 1)

#endif // _U_CFG_OS_PLATFORM_SPECIFIC_H_

// End of file