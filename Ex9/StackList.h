#pragma once
#include "Stack.h"
#include "List.h"

class StackList : public Stack
{
	List data;
public:
	StackList();

	// Inherited via Stack
	void push(int value) override;
	int pop() override;
	int top() override;
	bool isEmpty() const override;
	void clear() override;
};
