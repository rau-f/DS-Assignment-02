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
        list.Insert(i, rand() % 7);
    
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
    // std::cout << "Task # 03: 3Sum" << std::endl;
    // for (int i = 0; i < size; i++)
    //     list.Insert(i, (rand() % 10) - 5);
    // std::cout << "List: " << list << std::endl;
    // list.PrintTriplets();

    // Task # 04
    // std::cout << "Task # 04: Move Zeros To End" << std::endl;
    // std::cout << "List: " << list << std::endl;
    // list.MoveZeros();
    // std::cout << "Zeros moved: " << list << std::endl;

    // Task # 05: Majority Element (appearence > n/2)
    
}