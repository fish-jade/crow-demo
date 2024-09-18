#include "models/User.h"

User::User(int id, const std::string& name) : m_id(id), m_name(name) {}
int User::GetId() const {
    return m_id;
}

std::string User::GetName() const {
    return m_name;
}
