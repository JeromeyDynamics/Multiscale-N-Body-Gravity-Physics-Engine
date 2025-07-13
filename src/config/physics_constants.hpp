#pragma once

namespace config::physics {
    //gravitational constant
    inline constexpr float G = 6.674e-11f;

    //this is the scaling factor to turn real meters to pixels (may need to tweak)
    inline constexpr float distanceScale = 1e-6f;

    //mass scale
    inline constexpr float massScale = 1e20f;
}
