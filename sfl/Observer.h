#pragma once

namespace sfl {

template <typename T>
class Observer {
public:
    virtual void notify(T) = 0;
};

}
