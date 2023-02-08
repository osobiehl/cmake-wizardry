#include "linktime_mac.h"


MacLinkTime::MacLinkTime() : queue_ {} {}

void MacLinkTime::Send( std::string&& s) {
    queue_.Post(s);
    if (on_tx_.has_value()){
        (*on_tx_)(true);
    }
}
void MacLinkTime::OnSendComplete(std::function<void(bool)> const& f)  {
    on_tx_ = f;
}; 
void MacLinkTime::OnReceive(std::function<void(std::string)> const& f)  {
    on_rx_ = f;
}

void MacLinkTime::Receive(){
    std::string s = queue_.Pend();
    if (on_rx_.has_value()){
        (*on_rx_)(s);
    }
}

