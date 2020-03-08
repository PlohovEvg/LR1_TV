#include "List.h"

void List::Add_new_Node(Eta _e)
{
	Node *n = new Node;

	n->e = _e;
	n->next = NULL;

	if (head == NULL)
	{
		head = n;
		return;
	}
	else
	{
		if (n->e > head->e)
		{
			n->next = head;
			head = n;
			return;
		}
		else
		{
			Node *p = head;

			if (p->e == n->e)
			{
				p->e.IncNi();
				delete n;
				return;
			}
			else
			{
				while (p != NULL)
				{
					if (p->e == n->e)
					{
						p->e.IncNi();
						delete n;
						return;
					}
					if ((n->e < p->e) && (n->e > p->next->e))
					{
						n->next = p->next;
						p->next = n;
						return;
					}
					p = p->next;
				}
				p = n;
			}
		}
	}

}

void List::Delete_last_Node()
{
	if (head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		Node *p = head;
		while (p->next->next != NULL)
		{
			p = p->next;
		}	
		p->next = NULL;
	}
}

Eta List::Get_last_Node()
{
	Node *p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p->e;
}