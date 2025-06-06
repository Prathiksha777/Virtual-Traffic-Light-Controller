#ifndef TRAFFIC_CONTROLLER_H
#define TRAFFIC_CONTROLLER_H

#include "Config.h"
#include "RequestState.h"
#include "Enums.h"

#include <chrono>
#include <string>

class TrafficController {
private:
    SignalTimingConfig config;
    RequestState request;
    SignalState signalSN;
    SignalState signalEW;
    std::chrono::steady_clock::time_point lastPedestrianRequest;

    void handleRequests();
    void handleEmergency();
    void serveEmergency(Direction dir);
    void handlePedestrian();
    void normalCycle();
    void setSignals(Direction dir, SignalState state);
    SignalState getSignal(Direction dir) const;                   // <-- add const
    std::string stateToString(SignalState state) const;          // <-- add const

public:
    TrafficController();                                         // <-- add this
    void runController();
    void pedestrianButtonPressed();
    void emergencyButtonPressed(Direction dir);
};

#endif // TRAFFIC_CONTROLLER_H

