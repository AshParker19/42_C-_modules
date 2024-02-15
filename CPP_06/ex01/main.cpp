#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    uintptr_t serialized = Serializer::serialize(data);
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Original: " << data << std::endl;
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << "Deserialized: " << deserialized << std::endl;
    deserialized->n = 42;
    std::cout << "Deserialized->n: " << deserialized->n << std::endl;

    delete data;
}