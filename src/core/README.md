# Core

This folder contains the core engine logic and object management that this simulation uses to run.

### Files

- `simulation.hpp/.cpp` — Controls the main simulation update loop, manages time steps, and updates all the simulation objects.
- `object_manager.hpp/.cpp` — Stores and manages all simulation objects in the simulation (e.g., planets, orbiting bodies).
- `sim_object.hpp` — Abstract base class that all simulation objects inherit from. This would be the core interface with functions like update() or render().
- `integrator.hpp/.cpp` — Implements numerical integration methods (e.g., Euler, Runge-Kutta) used to update motion each frame.