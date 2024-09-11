#pragma once
#include <string>

class HelloService {
public:
    static std::string get_greeting();
    static std::string get_custom_greeting(const std::string& name);
};
