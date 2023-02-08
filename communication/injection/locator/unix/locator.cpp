#include "communication_locator_interface.h"
#include "unix_queue.hpp"

class UnixLocator: public CommunicationLocatorInterface {
    public:
    virtual QueueInterface<std::string>& MacQueue() final {
        static unix::Queue<std::string> queue {};
        return queue;
    }
};

CommunicationLocatorInterface& CommunicationLocator(){
    static UnixLocator r {};
    return r;
}