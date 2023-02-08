#include "injection_mac.h"


MacInjection::MacInjection(QueueInterface<std::string>& queue) : queue_ {queue} {}

void MacInjection::Send( std::string&& s) {
    queue_.Post(s);
    if (on_tx_.has_value()){
        (*on_tx_)(true);
    }
}
void MacInjection::OnSendComplete(std::function<void(bool)> const& f)  {
    on_tx_ = f;
}; 
void MacInjection::OnReceive(std::function<void(std::string)> const& f)  {
    on_rx_ = f;
}

void MacInjection::Receive(){
    std::string s = queue_.Pend();
    if (on_rx_.has_value()){
        (*on_rx_)(s);
    }
}

