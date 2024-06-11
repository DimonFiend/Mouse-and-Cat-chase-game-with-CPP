#pragma once

#include <string>

class Observer {
public:
    virtual void switchState(const std::string& buttonText) = 0;
    virtual ~Observer() = default;
};