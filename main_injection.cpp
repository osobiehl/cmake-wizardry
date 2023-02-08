#include <thread>

#include <iostream>
#include <unistd.h>
#include "injection_mac.h"
#include "simulation.h"
#include "communication_locator_interface.h"

int main(){
    //linktime substitution just works ... ?
    Simulation s {};
    MacInjection mac {CommunicationLocator().MacQueue()};
    s.Run(mac);


}