#include "TrafficController.h"
#include "Timer.h"
#include "Enums.h"
#include <iostream>

using namespace std;
using namespace chrono;

// Constructor
TrafficController::TrafficController() {
signalSN = RED;
signalEW = GREEN;
lastPedestrianRequest = steady_clock::now() - minutes(3);
}

// Start the traffic signal controller loop
void TrafficController::runController() {
while (true) {
handleRequests();
normalCycle();
}
}

// External trigger for pedestrian
void TrafficController::pedestrianButtonPressed() {
auto now = steady_clock::now();
if (duration_cast<seconds>(now - lastPedestrianRequest).count() > config.pedestrianCooldown) {
request.pedestrianRequested = true;
lastPedestrianRequest = now;
cout << "[INFO] Pedestrian button pressed. Request accepted.\n";
} else {
cout << "[INFO] Pedestrian button pressed. Cooldown active.\n";
}
}

// External trigger for emergency
void TrafficController::emergencyButtonPressed(Direction dir) {
if (dir == SN) request.emergencySN = true;
else if (dir == EW) request.emergencyEW = true;
cout << "[INFO] Emergency button pressed from " << (dir == SN ? "SN" : "EW") << " lane.\n";
}

// Check and handle emergency and pedestrian requests
void TrafficController::handleRequests() {
if (request.emergencySN || request.emergencyEW) {
handleEmergency();
}
if (request.pedestrianRequested) {
handlePedestrian();
}
}

// Handle emergency request
void TrafficController::handleEmergency() {
if (request.emergencySN) {
serveEmergency(SN);
request.emergencySN = false;
}
if (request.emergencyEW) {
serveEmergency(EW);
request.emergencyEW = false;
}
}

// Emergency logic for specific direction
void TrafficController::serveEmergency(Direction dir) {
cout << "[STATE] Emergency Mode for " << (dir == SN ? "SN" : "EW") << " lane\n";
if (getSignal(dir) == GREEN) {
    setSignals(dir, GREEN);
    Timer::wait(config.emergencyGreenDurationIfGreen);
} else {
    setSignals(dir, GREEN);
    Timer::wait(config.emergencyGreenDurationIfRed);
}

setSignals(dir, YELLOW);
Timer::wait(config.yellowDuration);
setSignals(dir, RED);
}

// Handle pedestrian request logic
void TrafficController::handlePedestrian() {
cout << "[STATE] Pedestrian Mode\n";
setSignals(SN, RED);
setSignals(EW, RED);
cout << "[PEDESTRIAN] Pedestrian signals are GREEN for " << config.pedestrianDuration << " seconds\n";
Timer::wait(config.pedestrianDuration);
request.pedestrianRequested = false;
}

// Default traffic cycle
void TrafficController::normalCycle() {
cout << "[STATE] EW GREEN, SN RED\n";
setSignals(EW, GREEN);
setSignals(SN, RED);
Timer::wait(config.greenDuration);
setSignals(EW, YELLOW);
Timer::wait(config.yellowDuration);
setSignals(EW, RED);

cout << "[STATE] SN GREEN, EW RED\n";
setSignals(SN, GREEN);
setSignals(EW, RED);
Timer::wait(config.greenDuration);

setSignals(SN, YELLOW);
Timer::wait(config.yellowDuration);
setSignals(SN, RED);
}

// Set signal state for SN or EW
void TrafficController::setSignals(Direction dir, SignalState state) {
if (dir == SN) {
signalSN = state;
cout << "[SIGNAL] SN is now " << stateToString(state) << "\n";
} else {
signalEW = state;
cout << "[SIGNAL] EW is now " << stateToString(state) << "\n";
}
}

// Get signal state of SN or EW
SignalState TrafficController::getSignal(Direction dir) const {
return dir == SN ? signalSN : signalEW;
}

// Convert signal state to string
string TrafficController::stateToString(SignalState state) const {
switch (state) {
case RED: return "RED";
case GREEN: return "GREEN";
case YELLOW: return "YELLOW";
default: return "UNKNOWN";
}
}

