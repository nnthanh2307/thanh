#include "ClientTemp.hpp"

void ClientTemp::updateOnTarget() {
    // print the changed values
    std::cout << "---Temp Client Data---\tTemperature: " << _subject->getStateTemp() << std::endl;
}


void ClientTemp::update(float temp=0, float humidity=0, float pressure=0) {
    // Don't use
}
