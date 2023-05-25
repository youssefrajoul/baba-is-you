#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>

class Observable;

class Observer {
public:
    Observer() = default;
    virtual void update(Observable* observable) = 0;
    ~Observer() = default;
};

class Observable {
    std::vector<Observer*> observers;

public:
    Observable() = default;

    void attach(Observer* observer){
        observers.push_back(observer);
    }

    void notifyObserver(){
        for (Observer* observer : observers) {
            observer->update(this);
        }
    }
    ~Observable() {}
};



#endif // OBSERVER_H
