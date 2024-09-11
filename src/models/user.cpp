#include "models/user.h"

User::User(int id, const std::string& name) : id(id), name(name) {}

int User::get_id() const {
    return id;
}

std::string User::get_name() const {
    return name;
}
