//
// Created by shan on 4/7/17.
//

#ifndef OBSERVER_PATTERN_CLIENT_1_HPP
#define OBSERVER_PATTERN_CLIENT_1_HPP

#include <iostream>

#include "Observer.hpp"

/**
 * a client that implements the Observer interface
 */
class Client : public Observer {

    int id;

public:

    Client(int id);
    virtual ~Client() {}

    virtual void update(float temp, float humidity, float pressure) override;
    virtual void updateOnTarget() override;
};


#endif //OBSERVER_PATTERN_CLIENT_1_HPP
