///=======================================================================
/// \file Observer.h
/// 
/// This file contains the abstract Observer class.
/// responsible for updating the state of the game window.

#pragma once

#include <string>

class Observer {
public:
    virtual void switchState(const std::string& buttonText) = 0;
    virtual ~Observer() = default;
};