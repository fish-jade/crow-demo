#include "services/HelloService.h"

std::string HelloService::GetGreeting() {
    return "Hello, World from Conan!";
}

std::string HelloService::GetCustomGreeting(const std::string& name) {
    return "Hello, " + name + "!";
}
