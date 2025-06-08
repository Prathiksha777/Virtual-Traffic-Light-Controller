# Virtual-Traffic-Light-Controller
An intelligent, flexible, and fully simulated Virtual Traffic Light Control System designed for traffic flow optimization and smart city integration. This project models real-world traffic intersection management using programmable logic, timing control, and vehicle.

---

## Project Structure

```plaintext
CODE/
│
├── Documentation/
│   └── Code_Documentation.docx                  # Functional documentation of all source files
│
├── include/
│   ├── Config.h                                 # Signal timing configuration structure
│   ├── Enums.h                                  # Enumerations for signal directions and states
│   ├── RequestState.h                           # State structure for emergency/pedestrian requests
│   ├── Timer.h                                  # Timer utility for simulating delays
│   └── TrafficController.h                      # Header for traffic control logic
│
├── src/
│   ├── Timer.cpp                                # Implements timer utilities
│   ├── TrafficController.cpp                    # Core logic for signal switching and events
│   └── main.cpp                                 # Simulation entry point, threads, signal flow
│
├── Makefile                                     # Standard build configuration
│
├── HLD/
│   ├── High Level Design of Normal Traffic Signal System/
│   │   └── VTLC_HLD.docx                        # Architectural overview and major modules
│   ├── LLD/
│   │   ├── Low_level_Design_VTLC.pdf            # LLD - PDF version
│   │   └── Low_level_design_VTLC.docx           # LLD - Editable version
│
├── Project_Task_Checklist.xlsx                  # Task planning and progress tracking
├── Requirements_Analysis_VTLC_Ver.docx          # Functional and non-functional requirements
└── README.md                                     # This file
```

---

## Build Instructions

### Prerequisites

Ensure the following are installed on your system:

- A POSIX-compatible operating system (Linux, macOS, WSL)
- g++ with C++17 support
- make utility
- pthread library (comes with most Linux distros)

### Build the Project

From inside the CODE directory, run:

```bash
make all
```

This command will:

- Compile all C++ source files in the src directory
- Use headers from the include directory
- Link against pthreads
- Generate an executable: traffic_signal_system

If you prefer to compile manually, run:

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/Timer.cpp src/TrafficController.cpp -lpthread -o traffic_signal_system
```

### Run the Simulation

Once built, run the program with:

```bash
./traffic_signal_system
```

The system runs a real-time simulation with two threads:
- One managing vehicle and pedestrian signal cycles
- Another periodically generating simulated button press events
- Note that you need to modify main code to simulate the emergency and pedastrian button

---


## Contributing

If you want to contribute to the project, contributions should follow these guidelines:

- Feature branches should follow the format name-action-feature-xyz.
- Code should follow C++ Core Guidelines.
- Submit pull requests with clear descriptions of changes.

---

## Contact

For technical queries, project coordination, or documentation updates:
work-mail@example.com

If you have questions, suggestions, or feedback, feel free to open an issue or contact us at:
your-email@example.com

---

## License
This project does not include License. You are free to use, modify, and distribute this software, provided that proper credit is given.

