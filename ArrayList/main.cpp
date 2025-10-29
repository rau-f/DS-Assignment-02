#include "ArrayList.hpp"
#include <cstdlib>


// Run with command: g++ main.cpp ArrayList.cpp Tasks.cpp -o main && ./main


int main()
{
    srand(time(NULL));

    #if __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif

    unsigned int size = 8;
    ArrayList list(size);

    for (int i = 0; i < size; i++)
        list.Insert(i, rand() % 10);
    
    std::cout << "\t(-: ARRAY LIST :-)\n" << std::endl;
    
    // Task # 01
    // std::cout << "Task # 01: Remove Duplicates (Sorted Array)" << std::endl;
    // list.Sort();
    // std::cout << "List: " << list << std::endl;
    // list.RemoveDuplicates();
    // std::cout << "Unique list: " << list << std::endl;

    // Task # 02
    // std::cout << "Task # 02: Longest Consecutive Sequence" << std::endl;
    // std::cout << "List: " << list << std::endl;
    // list.PrintLongestSeq();

    // Task # 03
    std::cout << "Task # 03: 3Sum" << std::endl;
    std::cout << "List: " << list << std::endl;
    list.PrintTriplets(); 
}