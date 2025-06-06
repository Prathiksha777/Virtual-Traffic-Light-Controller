#include "Timer.h"
#include <thread>
using namespace std::chrono_literals;
using namespace std;

void Timer::wait(int seconds) {
    this_thread::sleep_for(seconds * 1s);
}

