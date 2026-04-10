#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

void print_json_format(Data data) {
    std::cout << "{" << std::endl;
    std::cout << "  name: " << data.name << std::endl;
    std::cout << "  value: " << data.value << std::endl;
    std::cout << "}" << std::endl;
}

int main(int argc, char *argv[]) {
    char *err;

    if (argc != 3) {
        std::cout << "./serializer <string_name> <int_value>" << std::endl;
        return 0;
    }
    long value = std::strtol(argv[2], &err, 10);
    if (*err != '\0'){
        std::cout << "./serializer <string_name> <int_value>" << std::endl;
        return 0;
    }

    Data data;
    data.name = argv[1];
    data.value = static_cast<int>(value);

    std::cout << "---------- DATA ----------" << std::endl;
    print_json_format(data);
    std::cout << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "---------- raw ----------" << std::endl;
    std::cout << raw << std::endl;
    std::cout << std::endl;

    Data *other_data = Serializer::deserialize(raw);
    std::cout << "---------- Other Data ----------" << std::endl;
    print_json_format(*other_data);

    return 0;
}