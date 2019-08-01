#include "MyLinkedList.h"
#include <iostream>

MyLinkedList::MyLinkedList() {
	head = nullptr;

}
void MyLinkedList::PushFront(TYPE newValue)
{

	Node* newNode = new Node();
	newNode->value = newValue;
	newNode->pNext = head;
	head = newNode;
}

void MyLinkedList::PopFront()
{
	Node* tempPtr;
	tempPtr = head->pNext;
	delete head;
	head = tempPtr;
}

void MyLinkedList::PushBack(TYPE newValue)
{
	Node* newNode = new Node();
	newNode->value = newValue;
	newNode->pNext = nullptr;

	Node* ptr;
	ptr = head;
	if (head != nullptr) {
		while (ptr->pNext != nullptr)
		{
			ptr = ptr->pNext;
		}
		if (ptr->pNext == nullptr) ptr->pNext = newNode;
	}
	else head = newNode;

}

void MyLinkedList::PopBack()
{
	Node* ptr;
	ptr = head;
	while (ptr->pNext->pNext != nullptr)
	{
		ptr = ptr->pNext;
	}
	if (ptr->pNext->pNext == nullptr) {
		delete ptr->pNext;
		ptr->pNext = nullptr;
	}

}

void MyLinkedList::Insert(int index, TYPE newValue)
{
	Node* newNode = new Node();
	Node* ptr;
	newNode->value = newValue;
	ptr = head; 
	for (int i = 0; ptr != nullptr; i++) 
	{
		if (i == index) 
		{
			newNode->pNext = ptr->pNext;
			ptr->pNext = newNode;
		}
		ptr = ptr->pNext;
	}

}

void MyLinkedList::RemoveByValue(TYPE newValue)
{
	Node* ptr;
	Node* prevPtr;
	prevPtr = head;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->value == newValue)
		{
			if (ptr == head) 
			{
				head = ptr->pNext;
				delete ptr;
				return;
			}

			while (prevPtr != nullptr)
			{
				if (prevPtr->pNext->pNext == nullptr)
				{
					prevPtr->pNext = nullptr;
					delete ptr;
					return;
				}
				if (prevPtr->pNext == ptr)
				{
					prevPtr->pNext = ptr->pNext;
					delete ptr;
					return;
				}
				prevPtr = prevPtr->pNext;


			}

		}
		ptr = ptr->pNext;
	}
}
TYPE MyLinkedList::Get(int index) const
{
	Node* ptr;
	if (head != nullptr)
	{
		ptr = head;
		for (int i = 0; ptr != nullptr; i++)
		{
			if (i == index) {
				return ptr->value;
			}
			ptr = ptr->pNext;
		}
	}
	else std::cout << "list is empty";
}

void MyLinkedList::Display() const
{
	 Node* ptr;
	ptr = head;
	while (ptr != nullptr) 
	{
		std::cout << ptr->value << " ";
		ptr = ptr->pNext;
	}
	std::cout << std::endl;

}

bool MyLinkedList::isHeadEmpty() const
{
	if (head == nullptr) {
		return true;
	}
	else return false;
}
