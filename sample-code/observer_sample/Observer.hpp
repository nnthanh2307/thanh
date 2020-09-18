//
// Created by shan on 4/7/17.
//

#ifndef OBSERVER_PATTERN_OBSERVER_HPP
#define OBSERVER_PATTERN_OBSERVER_HPP

/**
 * Interface for the Observer
 */
class Observer {

public:

    /**
     * Update the state of this observer
     * @param temp new temperaure
     * @param humidity new humidity
     * @param pressure new pressure
     */
    virtual ~Observer() {}
    virtual void update(float temp=0, float humidity=0, float pressure=0) = 0;
    virtual void updateOnTarget() = 0;

};


#endif //OBSERVER_PATTERN_OBSERVER_HPP
