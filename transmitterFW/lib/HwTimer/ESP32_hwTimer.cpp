#include "hwTimer.h"

void (*hwTimer::callbackFunc)() = nullptr;

volatile bool hwTimer::running = false;
volatile uint32_t hwTimer::HWtimerIntervalUS = TimerIntervalUSDefault;

// Internal implementation specific variables
static hw_timer_t *timer = NULL;
static portMUX_TYPE isrMutex = portMUX_INITIALIZER_UNLOCKED;

#define HWTIMER_FREQUENCY 1000000 // 1 MHz

void ICACHE_RAM_ATTR hwTimer::init(void (*callbackf)())
{
    if (!timer)
    {
        hwTimer::callbackFunc = callbackf;
        timer = timerBegin(HWTIMER_FREQUENCY);
        timerStop(timer);
        timerAttachInterrupt(timer, hwTimer::callback);
    }
}

void ICACHE_RAM_ATTR hwTimer::stop()
{
    if (timer && running)
    {
        running = false;
        timerStop(timer);
    }
}

void ICACHE_RAM_ATTR hwTimer::resume()
{
    if (timer && !running)
    {
        // The timer must be restarted so that the new period is set.
        timerStart(timer);
        running = true;
        timerAlarm(timer, HWtimerIntervalUS, true, 0);
    }
}

void ICACHE_RAM_ATTR hwTimer::updateIntervalUS(uint32_t timeUS)
{
    // timer should not be running when updateIntervalUS() is called
    HWtimerIntervalUS = timeUS;
    if (timer)
    {
        timerAlarm(timer, HWtimerIntervalUS, true, 0);
    }
}

void ICACHE_RAM_ATTR hwTimer::callback(void)
{
    if (running)
    {
        portENTER_CRITICAL_ISR(&isrMutex);
        callbackFunc();
        portEXIT_CRITICAL_ISR(&isrMutex);
    }
}
