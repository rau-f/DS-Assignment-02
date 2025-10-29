#include "ArrayList.hpp"


int main()
{
    ArrayList list(8);

    for (int i = 0; i < 8; i++)
        list.Insert(i, 8 - i);

    list.UpdateCapacity(10);

    for (int i = 8; i < 10; i++)
        list.Insert(i, i+1);

    std::cout << "List: " << list << std::endl << std::endl;

    list.Sort();

    std::cout << "List: " << list << std::endl;
}