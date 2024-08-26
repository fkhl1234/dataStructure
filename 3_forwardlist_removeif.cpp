#include <iostream>
#include <string>
#include <forward_list>

struct citizen {
    std::string name;
    int age;
};

std::ostream &operator<<(std::ostream &os, const citizen &c) {
    return (os << "[" << c.name << "," << c.age << "]");
}

int main() {
    std::forward_list<citizen> citizens = { 
        {"KIM", 22}, {"CHOI", 32}
    };

    auto citizens_copy = citizens;

    
}