#ifndef IOBSERVER_H
#define IOBSERVER_H


class IObserver
{
public:
    virtual void Update(float price) = 0;
};

#endif // IOBSERVER_H
