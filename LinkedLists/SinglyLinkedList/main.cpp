#include "SLL.hpp"
#include "cstdlib"

int main()
{
    SLL list;
    const int size = 4;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        list.Append(rand() % 8);

    // Task # 01: Reverse Singly Linkedlist
    // list.Reverse();
    
    // Task # 02: Merge Two Sorted Lists
    // {
    //     SLL list2;
    //     list2.Append(1);
    //     list2.Append(5);
    //     list2.Append(8);
    //     list2.Append(4);

    //     list.Print();
    //     list2.Print();

    //     SLL newList;
    //     newList.SetHead(list.Merge(list2.GetHead()));
    //     newList.Print();
    // }

    // Task
    
    list.Print();
}