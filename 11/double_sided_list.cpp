#include <iostream>
#include <ctime>
using namespace std;

struct List
{
	char* value;
	List* next;
	List* prev;
};

List* make_list(int size, char* elem)
{
	if (size < 1)
	{
		perror("Unable to create list of size smaller than 1");
		exit(0);
	}
	char** ptr = &elem;
	List* first, * p;
	p = new List;
	first = p;
	p->value = *ptr;
	p->next = NULL;
	p->prev = NULL;
	for (int i = 1; i < size; i++)
	{
		ptr++;
		List* n = new List;
		p->next = n;
		n->value = *ptr;
		n->prev = p;
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
	char* elem = new char[6];
	for (int i = 0; i < 5; i++)
	{
		elem[i] = rand() % 61 + 65;
	}
	elem[5] = '\0';
	p->value = elem;
	p->next = NULL;
	p->prev = NULL;
	for (int i = 1; i < size; i++)
	{
		char* elem = new char[6];
		for (int i = 0; i < 5; i++)
		{
			elem[i] = rand() % 61 + 65;
		}
		elem[5] = '\0';
		List* n = new List;
		p->next = n;
		n->value = elem;
		n->prev = p;
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
	List* next = list;
	while (next != NULL)
	{
		list = next;
		next = list->next;
		delete list->value;
		delete list;
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
	char* elem = new char[5];
	int index;
	cout << "Enter element to insert: ";
	cin >> elem;
	cout << "Enter its index: ";
	cin >> index;
	List* p = s;
	for (int i = 1; i < index; i++)
	{
		p = p->next;
	}
	List* l = new List;
	l->value = elem;
	l->next = p->next;
	l->prev = p;
	p->next->prev = l;
	p->next = l;
	print_list(s);
	delete_list(s);
	cin >> n;
}
