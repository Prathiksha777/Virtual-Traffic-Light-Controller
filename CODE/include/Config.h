#pragma once

struct SignalTimingConfig {
    int greenDuration = 10;
    int yellowDuration = 3;
    int pedestrianDuration = 30;
    int pedestrianCooldown = 120;
    int emergencyGreenDurationIfRed = 25;
    int emergencyGreenDurationIfGreen = 20;
};

