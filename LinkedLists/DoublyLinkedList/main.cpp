#include <cstdlib>
#include "DLL.hpp"


int main()
{
    DLL list;
    const int size = 8;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        list.Append(rand() % 8);


    // Task # 01: Insert a Node in a Sorted Doubly Linked List
    // {
    //     list.Sort();
    //     list.Print();
    //     list.InsertInSortedList(10);
    //     list.InsertInSortedList(7);
    //     list.InsertInSortedList(4);
    //     list.InsertInSortedList(0);
    //     list.Print();
    // }
    
    // Task # 02: Delete All Occurrences of a Given Key
    // {
    //     list.Print();
    //     int key;
    //     std::cout << "Enter key: ";
    //     std::cin >> key;
    //     list.DelOuccKey(key);
    //     list.Print();
    // }

    // Task # 03: Find Pairs with a Given Sum
    // {
    //     list.Sort();
    //     list.Print();
    //     int sum;
    //     std::cout << "Enter sum: ";
    //     std::cin >> sum;
    //     list.PrintPairs(sum);
    // }

    // Task # 04: Rotate Doubly Linked List by N Nodes
    // {
    //     list.Print();
    //     int n;
    //     std::cout << "Enter n: ";
    //     std::cin >> n;
    //     list.RotateByN(n);
    //     list.Print();
    // }

    // Task # 05: Merge Two Sorted Doubly Linked Lists
    // {
    //     DLL list2;
    //     for (int i = 0; i < size; i++)
    //         list2.Append(rand() % 7);
    //     list.Sort();
    //     list2.Sort();
    //     list.Print();
    //     list2.Print();
    //     list.Merge(list2);
    //     list.Print();
    // }

    // Task # 06: Convert Binary Tree to Doubly Linked List
    // Pending till trees...

    // Task # 07: Find Triplets with Given Sum in a Sorted Doubly LinkedList
    // {
    //     list.Sort();
    //     list.Print();
    //     int k;
    //     std::cout << "Enter k: ";
    //     std::cin >> k;
    //     list.FindTripletsSumToK(k);
    // }

    // Task # 08: Merge K Sorted Doubly Linked Lists
    // {
    //     list.Print();
    //     int k;
    //     std::cout << "Enter k: ";
    //     std::cin >> k;
    //     list.MergeKSortedLists(k);
    //     list.Print();
    // }
    
    // Task # 09: Reverse Doubly Linked List in Groups of K
    // {
    //     list.Print();
    //     int k;
    //     std::cout << "Enter k: ";
    //     std::cin >> k;
    //     list.ReverseInGroups(k);
    //     list.Print();
    // }

    // Task # 10: Split a Circular Doubly Linked List into Two Halves
    {
        DLL list1;
        DLL list2;

        list.Print();
        list.MakeCircular();
        list.SplitCircularIntoHalves(list1, list2);

        list1.Print();
        list2.Print();
    }

    return 0;
}