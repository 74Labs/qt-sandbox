#pragma once

#include <set>
#include "Observer.h"

namespace sfl {

template <typename T>
class Observable {
private:
	std::set<Observer<T> *> observers;
protected:
    void notifyObservers(T event);
public:
	void registerObserver(Observer<T> *observer);
    void unregisterObserver(Observer<T> *observer);
};

template <typename T>
void Observable<T>::registerObserver(Observer<T> *observer) {
	this->observers.insert(observer);
}

template <typename T>
void Observable<T>::unregisterObserver(Observer<T> *observer) {
    this->observers.erase(observer);
}

template <typename T>
void Observable<T>::notifyObservers(T event) {
	typename std::set<Observer<T> *>::iterator it;
	for(it = this->observers.begin(); it != this->observers.end(); it++) {
		(*it)->notify(static_cast<T>(event));
	}
}

}
