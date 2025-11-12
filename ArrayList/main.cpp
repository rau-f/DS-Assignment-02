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
        list.Insert(i, rand() % 3);
    
    std::cout << "\t(-: ARRAY LIST :-)\n" << std::endl;

    
    // Task # 01
    // std::cout << "\nTask # 01: Remove Duplicates (Sorted Array)" << std::endl;
    // list.Sort();
    // std::cout << "List: " << list << std::endl;
    // list.RemoveDuplicates();
    // std::cout << "Unique list: " << list << std::endl;


    // Task # 02
    // std::cout << "\nTask # 02: Longest Consecutive Sequence" << std::endl;
    // std::cout << "List: " << list << std::endl;
    // list.PrintLongestSeq();


    // Task # 03
    // std::cout << "\nTask # 03: 3Sum" << std::endl;
    // for (int i = 0; i < size; i++)
    //     list.Insert(i, (rand() % 10) - 5);
    // std::cout << "List: " << list << std::endl;
    // list.PrintTriplets();


    // Task # 04
    // std::cout << "\nTask # 04: Move Zeros To End" << std::endl;
    // std::cout << "List: " << list << std::endl;
    // list.MoveZeros();
    // std::cout << "Zeros moved: " << list << std::endl;


    // Task # 05: Majority Element (appearence > n/2)
    // std::cout << "\nTask # 05: Majority Element (appearence > n/2)" << std::endl;
    // std::cout << "List: " << list << std::endl;
    // int majorityElem = list.FindMajorityElem();
    // if (majorityElem == -1)
    //     std::cout << "No majority element exists!" << std::endl;
    // else
    //     std::cout << "Majority Element: " << majorityElem << std::endl;


    // Task # 06: Sub Array Sum = k
    // std::cout << "\nTask # 06: Sub Array Sum = k" << std::endl;
    // std::cout << "Enter k: ";
    // {
    //     int k;
    //     std::cin >> k;

    //     list.UpdateCapacity(3);
    //     list.Clear();
    //     list.Insert(0, 1);
    //     list.Insert(1, 1);
    //     list.Insert(2, 1);
    //     std::cout << "List: " << list << std::endl;

    //     std::cout << "Subarrays: " << list.CountSubArrSum(k) << std::endl;
    // }


    // Task # 07: Longest Subarray with Sum ≤ K
    std::cout << "\nTask # 07: Longest Subarray with Sum ≤ k" << std::endl;
    std::cout << "Enter k: ";
    {
        int k;
        std::cin >> k;

        list.UpdateCapacity(6);
        list.Clear();
        list.Insert(0,  2);
        list.Insert(1, -1);
        list.Insert(2,  2);
        list.Insert(3,  3);
        list.Insert(4, -4);
        list.Insert(5,  2);
        std::cout << "List: " << list << std::endl;

        std::cout << "Longest subarray: " << list.GetLongestSubArrayLen(k) << std::endl;
    }
}
