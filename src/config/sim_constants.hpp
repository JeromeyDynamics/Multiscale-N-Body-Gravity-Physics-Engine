#pragma once

namespace config::sim {
    //the time step for each frame (set to 60 fps)
    inline constexpr float timeStep = 1.f / 60.f;

    //maximum simulation duration (don't want the sim to be running forever)
    inline constexpr float maxSimTime = 3600.f; // e.g., 1 hour
}