#ifndef LINKTIME_MAC_H
#define LINKTIME_MAC_H
#include "mac_interface.h"
#include "queue_interface.h"
#include <optional>

class MacInjection: public MacInterface {
public:
    MacInjection(QueueInterface<std::string>& queue);
    void Send( std::string&& s) final ;
    void OnSendComplete(std::function<void(bool)> const& f) final;
    void OnReceive(std::function<void(std::string)> const& f) final;
    void Receive();
private:
    QueueInterface<std::string>& queue_;
    std::optional< std::function<void(bool)>  > on_tx_;
    std::optional< std::function<void(std::string)>  > on_rx_;

};
#endif //LINKTIME_MAC_H