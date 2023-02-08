#include "communication_locator_interface.h"
#include "queue.hpp"

class RtosLocator: public CommunicationLocatorInterface {
    public:
    virtual QueueInterface<std::string>& MacQueue() final {
        static rtos::Queue<std::string> queue {};
        return queue;
    }
};

CommunicationLocatorInterface& CommunicationLocator(){
    static RtosLocator r {};
    return r;
}