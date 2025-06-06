#pragma once
#include <chrono>
#include <string>

using namespace std::chrono;

struct RequestState {
    bool pedestrianRequested = false;
    time_point<steady_clock> lastPedestrianRequest = steady_clock::now() - 3min;
    bool emergencySN = false;
    bool emergencyEW = false;
};

