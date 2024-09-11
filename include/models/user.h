#pragma once
#include <string>

class User {
public:
    User(int id, const std::string& name);
    int get_id() const;
    std::string get_name() const;

private:
    int id;
    std::string name;
};
