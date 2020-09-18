#ifndef OBSERVER_PATTERN_OPTIMIZEDWEATHERDATA_HPP
#define OBSERVER_PATTERN_OPTIMIZEDWEATHERDATA_HPP

#include <vector>
#include <algorithm>
#include <iostream>

#include "Subject.hpp"
#include "Observer.hpp"

//#define OPTIMIZED
class ChangeTracker
{
    protected :
        uint32_t m_changeCount;
        virtual void startChange() = 0 ;
        virtual void finishChange() = 0;

        ChangeTracker() { m_changeCount = 0; }
        virtual ~ChangeTracker() {}
};

/**
 * A concrete implementation of the Subject interface
 */
class OptimizedWeatherData : public Subject, private ChangeTracker {
    std::vector<Observer *> observers; // observers

    float temp = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

public:
    OptimizedWeatherData() { }
    virtual ~OptimizedWeatherData() {}

    void registerObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notifyObservers() override;

    void startChange();
    void finishChange();
    /**
     * Set the new state of the weather station
     * @param temp new temperature
     * @param humidity new humidity
     * @param pressure new pressure
     */
    void setState(float temp, float humidity, float pressure);
    void setStateTemp(float temp);
    void setStateHumidity(float humidity);
    void setStatePressure(float pressure);

    float getStateTemp();
    float getStateHumidity();
    float getStatePressure();
};


#endif //OBSERVER_PATTERN_OPTIMIZEDWEATHERDATA_HPP
