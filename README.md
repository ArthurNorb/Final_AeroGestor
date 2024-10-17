# AeroGestor
---

## About the Project

AeroGestor is an aircraft management system developed in **C++** using the **Qt6** framework, following the **Model-View-Controller (MVC)** architecture. The system manages information on aircraft, mechanics, and administrators, and uses **JSON** files for data storage.

### Implementation
- **MVC Architecture**: Clear separation between Model (data), View (UI), and Controller (control logic).
- **Storage**: Mechanics and aircraft data are stored locally in **JSON** files.
- **Documentation**: Generated with **Doxygen**. [Access here](./docs/html/index.html).
  
### Planned API
- Initially designed to provide a RESTful interface for remote management.
- **Status**: Basic API structure defined, but endpoints and authentication are yet to be fully implemented.
- For more API details, [see this document](https://docs.google.com/document/d/1QfRXmrhm527KIgRMQcpzwKfkcdJByOkQUkyacGToiw4/edit?tab=t.0#heading=h.4f1mdlm).

## Build and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/ArthurNorb/final_AeroGestor.git

2. Build the project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
