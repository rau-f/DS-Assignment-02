#include "Stack.hpp"


// Task # 03: Reverse stack using recursion
void StackArray::Reverse()
{
    if (IsEmpty())
        return;
    
    int temp = Pop();

    Reverse();
    InsertAtBottom(temp);
}

void StackArray::InsertAtBottom(int value)
{
    if (IsEmpty())
    {
        Push(value);
        return;
    }

    int temp = Pop();

    InsertAtBottom(value);
    Push(temp);
}


// Task # 04: Sort stack using recursion
void StackArray::SortStack()
{
    if (IsEmpty())
        return;

    int temp = Pop();

    SortStack();

    InsertSorted(temp);
}

void StackArray::InsertSorted(int value)
{
    if (IsEmpty() || value >= Peek())
    {
        Push(value);
        return;
    }

    int temp = Pop();

    InsertSorted(value);

    Push(temp);
}


// Task # 05: Delete middle element of stack without using another data structure
void StackArray::RemoveMiddle(int bottom)
{
    if (bottom >= m_Top)
    {
        Pop();
        return;
    }

    int temp = Pop();

    RemoveMiddle(bottom + 1);

    Push(temp);
}


// Task # 06: Balanced Parenthesis
bool StackArray::CheckParenthesis(int curr)
{
}


// Task # 07: Next Greater Element
int* StackArray::NextGreater(int* array, int size)
{
    StackArray stack(size);
    int result[size];

    for (int i = size - 1; i >= 0; i--)
    {
        while (!stack.IsEmpty() && stack.Peek() <= array[i])
            stack.Pop();

        if (stack.IsEmpty())
            result[i] = -1;
        else
            result[i] = stack.Peek();

        stack.Push(array[i]);        
    }

    return result;
}


// Task # 08: Palindrome
bool StackArray::CheckPalindrome()
{
    int top = m_Top;
    StackArray topHalf(m_Size / 2);

    for (int i = 0; i < m_Size / 2; i++)
        topHalf.Push(Pop());

    if (m_Size % 2 == 1)
        Pop();

    for (int i = 0; i < m_Size / 2; i++)
        if (Pop() != topHalf.Pop())
            return false;

    m_Top = top;
    return true;
}