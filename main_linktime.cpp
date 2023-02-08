#include <thread>

#include <iostream>
#include <unistd.h>
#include "linktime_mac.h"
#include "simulation.h"

int main(){
    //linktime substitution just works ... ?
    Simulation s {};
    MacLinkTime mac {};
    s.Run(mac);


}