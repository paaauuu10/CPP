#include "Serializer.hpp"

int main() 
{
    // Step 1: Store Data 
    Data* original = new Data();
    original->n1 = 101;
    original->s1 = "Working on deserialize";
    original->s2 = "Will it work?";
    original->n2 = 42;

    // Printing Data object
    std::cout << "Original Data object:\n";
    std::cout << "N1: " << original->n1 << ", N2: " << original->n2 << ", s1: " << original->s1 << ", s2: " << original->s2 << "\n";

    // Step 2: Serialize && print serialized uintptr_t (raw)
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "\nSerialized uintptr_t: " << raw << "\n";

    // Step 3: Deserialize
    Data* deserialized = Serializer::deserialize(raw);

    // Print deserialized Data object
    std::cout << "\nDeserialized Data object:\n";
    std::cout << "N1: " << deserialized->n1 << ", N2: " << deserialized->n2 <<", s1: " << deserialized->s1 << ", s2: " << deserialized->s2 << "\n";

    // Step 4: Comparing original and deserialized pointers
    if (original == deserialized) {
        std::cout << "\nBoth pointers match!\n";
    } else {
        std::cout << "\nPointers do not match.\n";
    }
	
    delete original;
    return 0;
}