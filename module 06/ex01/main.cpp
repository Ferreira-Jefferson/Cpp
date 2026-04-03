#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    char *err;

    if (argc != 3) {
        std::cout << "./serializer <string> <int>" << std::endl;
        return 0;
    }
    long value = std::strtol(argv[2], &err, 10);
    if (*err != '\0'){
        std::cout << "./serializer <string> <int>" << std::endl;
        return 0;
    }

    Data data;
    data.name = argv[1];
    data.value = static_cast<int>(value);

    std::cout << "---------- DATA ----------" << std::endl;
    std::cout << data.name << std::endl;
    std::cout << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "---------- raw ----------" << std::endl;
    std::cout << raw << std::endl;

    Data *other_data = Serializer::deserialize(raw);
    std::cout << "---------- Other Data ----------" << std::endl;
    std::cout << other_data->name << std::endl;
    std::cout << other_data->value << std::endl;

    return 0;
}