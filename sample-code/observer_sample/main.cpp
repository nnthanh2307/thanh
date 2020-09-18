
#include <iostream>
#include "WeatherData.hpp"
#include "OptimizedWeatherData.hpp"
#include "Client.hpp"
#include "ClientTemp.hpp"

#define PROBLEM2 // About avoid redundant notification
//#define PROBLEM1 // About pull model

int main() {
    float temp, humidity, pressure;
    WeatherData weatherStation;

#ifdef PROBLEM2
    OptimizedWeatherData optimizedWeatherStation;
    Client one(1);

    optimizedWeatherStation.registerObserver(&one);

    std::cout << "4. Enter Temperature, Humidity, Pressure (seperated by spaces) << " << std::endl;
    std::cin >> temp >> humidity >> pressure;
    optimizedWeatherStation.setState(temp,humidity,pressure);

#elif defined PROBLEM1 // Improvement PULL mechanism
    ClientTemp tempClient(&weatherStation);
    Client one(1);

    weatherStation.registerObserver(&one);
    weatherStation.registerObserver(&tempClient);

    std::cout << "3. Enter Temperature, Humidity, Pressure (seperated by spaces) << " << std::endl;
    std::cin >> temp >> humidity >> pressure;
    weatherStation.setState(temp,humidity,pressure);

#else  // normal case
    Client one(1), two(2), three(3);

    weatherStation.registerObserver(&one);
    weatherStation.registerObserver(&two);
    weatherStation.registerObserver(&three);

    std::cout << "1. Enter Temperature, Humidity, Pressure (seperated by spaces) << " << std::endl;
    std::cin >> temp >> humidity >> pressure;
    weatherStation.setState(temp,humidity,pressure);

    weatherStation.removeObserver(&two);

    std::cout << "\n\n2. Enter Temperature, Humidity, Pressure (seperated by spaces) << ";
    std::cin >> temp >> humidity >> pressure;
    weatherStation.setState(temp,humidity,pressure);

    return 0;
#endif
}
