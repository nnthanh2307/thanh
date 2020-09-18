#ifndef OBSERVER_PATTERN_CLIENT_TEMP_HPP
#define OBSERVER_PATTERN_CLIENT_TEMP_HPP

#include <iostream>

#include "Observer.hpp"
#include "WeatherData.hpp"

/**
 * a client that implements the Observer interface
 */
class ClientTemp : public Observer {
 private:
  std::string message_from_subject_;
  WeatherData *_subject;

public:

    ClientTemp(WeatherData * t_subject) {
        _subject = t_subject;
    }
    virtual ~ClientTemp() {}

    virtual void update(float temp, float humidity, float pressure) override;
    virtual void updateOnTarget() override;

};


#endif //OBSERVER_PATTERN_CLIENT_TEMP_HPP
