#ifndef MAC_INTERFACE_H
#define MAC_INTERFACE_H
#include <string>
#include <functional>
class MacInterface{
    public:
    virtual void Send( std::string&& s) =0;
    virtual void OnSendComplete(std::function<void(bool)> const& f) =0;
    virtual void OnReceive(std::function<void(std::string)> const& f) =0;
    virtual void Receive() =0;

};
#endif