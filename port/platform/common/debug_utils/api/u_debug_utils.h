/*
 * Copyright 2022 u-blox
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

#ifndef _U_DEBUG_UTILS_H_
#define _U_DEBUG_UTILS_H_

/* No #includes allowed here. */

/** @file
 * @brief Various debug utilities
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

#ifndef U_DEBUG_UTILS_INACTIVITY_TASK_CHECK_PERIOD_SEC
/** The period the inactivity task will use for checking
 * for inactivity by calling the uDebugUtilsCheckInactivity_t
 * callback.
 */
# define U_DEBUG_UTILS_INACTIVITY_TASK_CHECK_PERIOD_SEC 60
#endif

/* ----------------------------------------------------------------
 * TYPES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * FUNCTIONS
 * -------------------------------------------------------------- */

/** Initialise the inactivity detector
 *
 * This is mainly intended for our test system to detect deadlocks
 * and starvation. It will start an inactivity task that will check
 * that the value pActivityCounter points at changes each
 * U_DEBUG_UTILS_INACTIVITY_TASK_CHECK_PERIOD_SEC second.
 * If this value has not changed within this period a message will
 * be printed and if U_DEBUG_UTILS_DUMP_THREADS is enabled all task
 * will be dumped.
 *
 * @param[in] pActivityCounter  a pointer to a value that should be
 *                              checked for inactivity. The detector will
 *                              only check that the value in the pointer
 *                              destination changes so it doesn't matter
 *                              if it increase, decrease, wrap etc. Any
 *                              change is regarded as activity.
 * @return zero on success else negative error code.
 */
int32_t uDebugUtilsInitInactivityDetector(volatile int32_t *pActivityCounter);

#ifdef U_DEBUG_UTILS_DUMP_THREADS

/** Dump all current threads.
 *
 * This will print out name and state (if available) for each
 * thread together with a PC backtrace. The PC based backtrace
 * can be converted to a real backtrace by using addr2line.
 *
 * Example output:
 *   ### Dumping threads ###
 *     timerEvent (pending): bottom: 200064e0, top: 20006ce0, sp: 20006bd8
 *       Backtrace: 0x00050e16 0x0004e68a 0x0005c910 0x0005a1b6 0x0005a196 0x0005a196 0x0005d724
 *     sysworkq (pending): bottom: 200289a0, top: 200291a0, sp: 20029120
 *       Backtrace: 0x00050e16 0x000525d4 0x0004fe8c 0x0005d724
 */
void uDebugUtilsDumpThreads(void);


#endif

#ifdef __cplusplus
}
#endif

#endif // _U_DEBUG_UTILS_H_

// End of file