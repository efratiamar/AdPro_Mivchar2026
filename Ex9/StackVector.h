#pragma once
#include "Stack.h"
#include "Vector.h"

class StackVector : public Stack
{
	Vector data;
public:
	StackVector(int capacity);

	// Inherited via Stack
	void push(int value) override;
	int pop() override;
	int top() override;
	bool isEmpty() const override;
	void clear() override;
};
