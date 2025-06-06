#include <thread>
#include <chrono>
#include <string> 

using namespace std;
using namespace chrono;

int main() {
   TrafficController controller;

    thread trafficThread([&controller]() {
        controller.runController();
    });

    // Add TEST CASES here
    trafficThread.join();
    return 0;
}

