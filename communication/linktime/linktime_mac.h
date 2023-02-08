#ifndef LINKTIME_MAC_H
#define LINKTIME_MAC_H
#include "mac_interface.h"
#include "queue.hpp"
#include <optional>

class MacLinkTime: public MacInterface {
public:
    MacLinkTime();
    void Send( std::string&& s) final ;
    void OnSendComplete(std::function<void(bool)> const& f) final;
    void OnReceive(std::function<void(std::string)> const& f) final;
    void Receive();
private:
    rtos::Queue<std::string> queue_;
    std::optional< std::function<void(bool)>  > on_tx_;
    std::optional< std::function<void(std::string)>  > on_rx_;

};
#endif //LINKTIME_MAC_H