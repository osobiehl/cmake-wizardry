#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H
template <class T> class QueueInterface{
    public:
    virtual void Init() =0;
    virtual T Pend() = 0;
    virtual void Post(T) =0;

};
#endif