#ifndef SIM_H
#define SIM_H
#include "mac_interface.h"
class Simulation{
    public:
    void Run(MacInterface& mac_task);
};
#endif