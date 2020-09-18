#ifndef CARETAKER_H
#define CARETAKER_H


//class Caretaker
//{
//public:
//    Caretaker();
//};
#include <list>

// Badprog.com

class Memento;

class Caretaker {
public:
    Caretaker();
    ~Caretaker();

    void setMemento(Memento *memento);
    Memento *getMemento();

private:
    std::list<Memento *> _listMemento;
    Memento *_lastElementInList;
};

#endif // CARETAKER_H
