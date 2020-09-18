#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

using namespace std;

//Responsible for the storage of the internal state of the Originator object, and can prevent other objects outside of the Originator Memento access memo.
//The memo has two interfaces, Caretaker can only see the narrow interface memos, it can only be transferred to other objects memorandum. Originator can see a wide interface, allowing it access to all the data needed to return to the previous state.
class Memento
{
private:
    //The Originator friend class, can access the internal information, but other classes cannot access
    friend class Originator;
    Memento(const string& state);
    ~Memento();
    void SetState(const string& state);
    string GetState();
    string _state;
};

//Responsible for creating a memo, Memento, is used to record the moment of its internal state, and can be used to restore the internal state of the memorandum
class Originator
{
public:
    Originator();
    Originator(const string& state);
    ~Originator();
    void RestoreToMemento(Memento* pMemento);
    Memento* CreateMemento();
    void SetState(const string& state);
    string GetState();
    void show();
protected:
private:
    string _state;
};

//Responsible for the preservation of the memo Memento, not on the memo content operation or inspection
class Caretaker
{
public:
    Caretaker();
    ~Caretaker();
    void SetMemento(Memento*);
    Memento* GetMemento();
private:
    Memento* _memento;
};

#endif // MEMENTO_H
