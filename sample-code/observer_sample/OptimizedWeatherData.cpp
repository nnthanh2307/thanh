//
// Created by shan on 4/7/17.
//

#include "OptimizedWeatherData.hpp"

void OptimizedWeatherData::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void OptimizedWeatherData::removeObserver(Observer *observer) {
    // find the observer
    auto iterator = std::find(observers.begin(), observers.end(), observer);

    if (iterator != observers.end()) { // observer found
        observers.erase(iterator); // remove the observer
    }
}

void OptimizedWeatherData::notifyObservers() {
    for (Observer *observer : observers) { // notify all observers
        observer->update(temp, humidity, pressure);
        observer->updateOnTarget();
    }
}

void OptimizedWeatherData::startChange()
{
    m_changeCount++;
}
void OptimizedWeatherData::finishChange()
{
    m_changeCount--;
    if( m_changeCount == 0 )
    {
        notifyObservers();
    }
}


void OptimizedWeatherData::setState(float temp, float humidity, float pressure) {
#ifdef OPTIMIZED
    this->startChange();
#endif
    this->setStateTemp(temp);
    this->setStateHumidity(humidity);
    this->setStatePressure(pressure);
#ifdef OPTIMIZED
    this->finishChange();
#else
    notifyObservers();
#endif
}


void OptimizedWeatherData::setStateTemp(float temp){
#ifdef OPTIMIZED
    this->startChange();
#endif
    // Set temp
    this->temp = temp;

#ifdef OPTIMIZED
    this->finishChange();
#else
    notifyObservers();
#endif
}

void OptimizedWeatherData::setStateHumidity(float humidity){
#ifdef OPTIMIZED
    this->startChange();
#endif
    // Set humidity
    this->humidity = humidity;

#ifdef OPTIMIZED
    this->finishChange();
#else
    notifyObservers();
#endif
}

void OptimizedWeatherData::setStatePressure(float pressure){
#ifdef OPTIMIZED
    this->startChange();
#endif
    // Set pressure
    this->pressure = pressure;

#ifdef OPTIMIZED
    this->finishChange();
#else
    notifyObservers();
#endif
}


float OptimizedWeatherData::getStateTemp() {
    return temp;
}

float OptimizedWeatherData::getStateHumidity() {
    return temp;
}

float OptimizedWeatherData::getStatePressure() {
    return temp;
}
