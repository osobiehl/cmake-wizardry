#include "simulation.h"
#include <thread>

#include <iostream>
#include <unistd.h>
#include <sstream>

void SendTask(MacInterface* mac_task, int start){
    while(1){
        std::string to_send ("hello! ");
            
        for(int i =start ; i < start + 100; i++){
            std::ostringstream s;
            s<< "hello "<<i<<" \n";
           mac_task->Send(std::string(s.str()));
           sleep(1);
        }
        sleep(5);  
    }
}

void Simulation::Run(MacInterface& mac_task){
            mac_task.OnSendComplete([](bool a){
            std::cout<<"sent!";
        });
        mac_task.OnReceive([](std::string s){
            std::cout<<"receive: "<<s<<std::endl;
        });

        auto x = std::thread(SendTask, &mac_task, 0);
        auto y = std::thread(SendTask, &mac_task, 100);


        while(true){
                mac_task.Receive();
        }
}




