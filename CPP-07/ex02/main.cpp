#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
    //STEP 1: Creating array
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    //STEP 2: Filling the array with random numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // STEP 3: Trying copy constructor
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    
    //STEP 4: Checking MIRROR vs NUMBERS and printing NUMBERS
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    //STEP 4: Checking MIRROR vs TMP and printing TMP
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (tmp[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        std::cout << tmp[i] << " ";
    }

    //STEP 5: Trying to acces out of bounds
    std::cout << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;
    return 0;
}

/*int main()
{
    //STEP 1: Creating array
    Array<std::string> string(5);

    //STEP 2: Filling the array with random numbers
    string[0] = "Hi";
    string[1] = "How are you"; 
    string[2] = "My name is pau";
    string[3] = "That's all";
    string[4] = "See you soon";

    //STEP 3: Printing all strings from the array
    for (size_t i = 0; i < string.size(); i++)
    {
        std::cout << string[i] << std::endl;
    }

    try
    {
        //STEP 5: Trying to acces out of bounds
        std::cout << string[-1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}*/
