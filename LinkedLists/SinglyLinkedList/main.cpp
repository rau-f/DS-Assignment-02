#include "SLL.hpp"
#include "cstdlib"


// Task # 06: Add Two Numbers (Linked Lists)
SLL* AddNumbers(SLL &list1, SLL &lsit2);


int main()
{
    SLL list;
    const int size = 7;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        list.Append(rand() % 8);

    // Task # 01: Reverse Singly Linkedlist
    // {
    //     list.Reverse();
    //     list.Print();
    // }

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

    // Task # 03: Middle of the Linked List
    // {
    //     list.Print();
    //     std::cout << "Middle Node: " << list.FindMiddleNode()->data << std::endl;
    // }

    // Task # 04: Remove Nth Node from End
    // {
    //     list.Print();
    //     int n;
    //     std::cout << "Enter nth node to remove from end: ";
    //     std::cin >> n;
    //     list.RemoveNodeFromEnd(n);
    // }

    // Task # 05: Linked List Cycle Detection
    // {
    //     list.Print();
    //     std::cout << (list.DetectCycle() ? "True" : "False") << std::endl;
    // }

    // Task # 06: Add Two Numbers
    // {
    //     SLL l1;
    //     l1.Append(5);
    //     l1.Append(8);
    //     l1.Append(9);
    //     SLL l2;
    //     l2.Append(3);   
    //     l2.Append(9);
    //     l2.Append(9);
    //     l2.Append(5);
    //     AddNumbers(l1, l2)->Print();
    // }

    // Task # 07: Reorder List
    // {
    //     list.Print();
    //     list.Reorder();
    //     list.Print();
    // }

    // Task # 08: Remove Duplicates from Sorted Linked List
    // {
    //     list.Sort();
    //     list.Print();
    //     list.RemoveDupFromSortedList();
    //     list.Print();
    // }

    // Task # 09: Reverse Nodes in k-Group
    // {
    //     list.Print();
    //     int k;
    //     std::cout << "Enter k: ";
    //     std::cin >> k;
    //     list.ReverseKElem(k);
    //     list.Print();
    // }
}


// Task # 06: Add Two Numbers (Linked Lists)
SLL* AddNumbers(SLL &list1, SLL &list2)
{
    SLL* sumList = new SLL();

    int sum = 0;
    bool CF = false;
    
    Node* h1 = list1.GetHead();
    Node* h2 = list2.GetHead();

    while (h1 || h2)
    {
        if (h1 && h2)
            sum = h1->data + h2->data + (CF ? 1 : 0);
        else if (h1)
            sum = h1->data + (CF ? 1 : 0);
        else if (h2)
            sum = h2->data + (CF ? 1 : 0);

        if (sum > 9)
        {
            sumList->Append(sum % 10);
            CF = true;
        }
        else
        {
            sumList->Append(sum);
            CF = false;
        }

        if (h1) h1 = h1->next;
        if (h2) h2 = h2->next;
    }

    if (CF) sumList->Append(1);

    return sumList;
}