#pragma once
#include <string>

class HelloService {
public:
    static std::string GetGreeting();
    static std::string GetCustomGreeting(const std::string& name);
};
