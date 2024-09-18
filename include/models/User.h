#pragma once
#include <string>

class User {
public:
    User(int id, const std::string& name);
    int GetId() const;
    std::string GetName() const;

private:
    int m_id;
    std::string m_name;
};
