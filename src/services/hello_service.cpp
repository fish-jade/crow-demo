#include "services/hello_service.h"

std::string HelloService::get_greeting() {
    return "Hello, World from Conan!";
}

std::string HelloService::get_custom_greeting(const std::string& name) {
    return "Hello, " + name + "!";
}
