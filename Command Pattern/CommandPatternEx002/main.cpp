#include <QCoreApplication>
#include<Command.cpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Receiver
    Light *light = new Light;
    Fan *fan = new Fan;

    // concrete Command objects
    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);
    FanOnCommand *fanOn = new FanOnCommand(fan);
    FanOffCommand *fanOff = new FanOffCommand(fan);
    NullCommand *nullOn = new NullCommand();
    NullCommand *nullOff = new NullCommand();

    // invoker objects
    RemoteControl *control = new RemoteControl;

    // execute
    control->setCommand(LIGHT, lightOn, lightOff);
    control->onButtonPressed(LIGHT);
    control->offButtonPressed(LIGHT);

    control->setCommand(FAN, fanOn, fanOff);
    control->onButtonPressed(FAN);
    control->offButtonPressed(FAN);

    control->setCommand(NONE, nullOn, nullOff);
    control->onButtonPressed(NONE);

    delete light, lightOn, lightOff;
    delete fan, fanOn, fanOff;
    delete control;

    return a.exec();
}
