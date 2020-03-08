#pragma once
#include "Class_Eta.h"
#include <iostream>

struct Node
{
	Node *next;
	Eta e;
};

class List
{
	Node *head;
public:
	List() { head = NULL; }
	void Add_new_Node(Eta _e);
	void Delete_last_Node();
	void Delete_List() { while (head != NULL) this->Delete_last_Node(); }
	Eta Get_last_Node();
	bool IsEmpty() { return (head == NULL); }
};