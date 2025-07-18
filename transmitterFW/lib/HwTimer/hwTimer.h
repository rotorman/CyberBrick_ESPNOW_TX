#pragma once

#include "common.h"
#include <stdio.h>

#define TimerIntervalUSDefault 20000

/**
 * @brief Hardware abstraction for the hardware timer to provide precise timing.
 *
 * The timer provides a callback.
 */
class hwTimer
{
public:
    /**
     * @brief Initialise the timer with the specified callback function.
     *
     * The timer is initialised in the stopped state and must be started with resume().
     */
    static void init(void (*callbackf)());

    /**
     * @brief Stop the timer.
     *
     * The timer is stopped and no more callbacks are performed.
     */
    static void stop();

    /**
     * @brief Resume the timer.
     *
     * The timer is started from this instant, callbacks will be called.
     * The timer fires a callback immediately after it is resumed.
     */
    static void resume();

    /**
     * @brief Change the interval between callbacks.
     * The timer should not be running when updateIntervalUS() is called.
     *
     * @param time in microseconds.
     */
    static void updateIntervalUS(uint32_t timeUS = TimerIntervalUSDefault);

    static volatile bool running;

private:
    static void callback();

    static void (*callbackFunc)();

    static volatile uint32_t HWtimerIntervalUS;
};
