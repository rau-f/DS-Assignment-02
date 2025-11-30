#include "Stack.hpp"


int main()
{
    StackArray stack(5);

    stack.Push('[');
    stack.Push('[');
    stack.Push('{');
    stack.Push('}');
    stack.Push(']');
    stack.Push(']');

    stack.Print();
    std::cout << "Balanced: " << stack.CheckParenthesis() << std::endl;
    stack.Print();
}