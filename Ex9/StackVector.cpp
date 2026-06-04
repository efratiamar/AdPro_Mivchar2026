#include "StackVector.h"

StackVector::StackVector(int capacity)
    : Stack(), data(capacity)
{
}

void StackVector::push(int value)
{
    data.addLast(value);
}

int StackVector::pop()
{
    return data.removeLast();
}

int StackVector::top()
{
    return data.lastValue();
}

bool StackVector::isEmpty() const
{
    return data.isEmpty();
}

void StackVector::clear()
{
    data.clear();
}
