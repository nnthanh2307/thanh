#include <QCoreApplication>
#include<Command.cpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Receiver
    Light *light = new Light;

    // concrete Command objects
    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);

    // invoker objects
    RemoteControl *control = new RemoteControl;

    // execute
    control->setCommand(lightOn);
    control->buttonPressed();
    control->setCommand(lightOff);
    control->buttonPressed();

    delete light, lightOn, lightOff, control;

    return a.exec();
}
