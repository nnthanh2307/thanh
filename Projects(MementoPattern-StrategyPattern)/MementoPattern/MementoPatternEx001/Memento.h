#ifndef MEMENTO_H
#define MEMENTO_H


//class Memento
//{
//public:
//    Memento();
//};

// Badprog.com

//#include "Memento.h"
#include "Originator.h"

class Memento {
    friend class Originator;

public:
    ~Memento();

private:
    Memento(Originator originator);
    void setOriginator(Originator originator);
    Originator getOriginator();

private:
    Originator _originator;

};

#endif // MEMENTO_H
