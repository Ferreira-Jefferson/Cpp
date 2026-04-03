#pragma once

#include <string>
#include <stdint.h>

struct Data {
    std::string name;
    int value;
};

class Serializer {
    private:
        Serializer(void);
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& copy);
        ~Serializer(void);
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};