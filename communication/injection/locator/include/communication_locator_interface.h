#ifndef COMMUNICATION_LOCATOR_H
#define COMMUNICATION_LOCATOR_H
#include "queue_interface.h"
#include <string>
class CommunicationLocatorInterface{
    public:
    virtual QueueInterface<std::string>& MacQueue() =0;
};

CommunicationLocatorInterface& CommunicationLocator();

#endif // COMMUNICATION_LOCATOR_H