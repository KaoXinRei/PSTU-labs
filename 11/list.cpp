#include <iostream>
#include <ctime>
using namespace std;

struct List
{
	int value;
	List* next;
};

List* make_list(int size, ...)
{
	if (size < 1)
	{
		perror("Unable to create list of size smaller than 1");
		exit(0);
	}
	int* ptr = &size;
	ptr++;
	List* first, * p;
	p = new List;
	first = p;
	p->value = *ptr;
	p->next = NULL;
	for (int i = 1; i < size; i++)
	{
		ptr++;
		List* n = new List;
		p->next = n;
		n->value = *ptr;
		n->next = NULL;
		p = n;
	}
	return first;
}

List* make_random_list(int size)
{
	srand(time(nullptr));
	if (size < 1)
	{
		perror("Unable to create list of size smaller than 1");
		exit(0);
	}
	List* first, * p;
	p = new List;
	first = p;
	p->value = rand() % 20 - 10;
	p->next = NULL;
	for (int i = 1; i < size; i++)
	{
		List* n = new List;
		p->next = n;
		n->value = rand() % 20 - 10;
		n->next = NULL;
		p = n;
	}
	return first;
}

void print_list(List* list)
{
	cout << list->value << ' ';
	while (list->next != NULL)
	{
		list = list->next;
		cout << list->value << ' ';
	}
}

void delete_list(List* list)
{
	while (list != NULL)
	{
		List* next = list->next;
		delete list;
		list = next;
	}
}

int main()
{
	int n;
	cout << "Enter the size of the list: ";
	cin >> n;
	List* s = make_random_list(n);
	print_list(s);
	cout << endl;
	int index = -1;
	List* p = s;
	int i = 0;
	while (p != NULL)
	{
		if (p->value % 2 == 0)
		{
			index = i;
		}
		i++;
		p = p->next;
	}
	if (index == -1)
	{
		cout << "No even elements" << endl;
	}
	else
	{
		p = s;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		List* ptr = p->next;
		p->next = p->next->next;
		delete ptr;
	}
	print_list(s);
	delete_list(s);
}
