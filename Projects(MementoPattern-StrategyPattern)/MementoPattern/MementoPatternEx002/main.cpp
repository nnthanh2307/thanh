#include <QCoreApplication>
#include "Memento.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Initialize the object, state“Old”
    Originator* o = new Originator("Old");
    o->show();

    //Establish and maintain Memento
    Caretaker* pTaker = new Caretaker();
    pTaker->SetMemento(o->CreateMemento());

    //Change state
    o->SetState("New");
    o->show();

    //Restoration of state
    o->RestoreToMemento(pTaker->GetMemento());
    o->show();


    return a.exec();
}
