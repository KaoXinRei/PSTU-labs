#include <iostream>
#include <ctime>
using namespace std;

struct Element
{
  char* data;
  Element *next;
};

struct Queue
{
    Element* start ;
    Element* end;
};



Queue* create_queue (char* n)
{
  Element *start = new Element;
  Element *end = start;
  start->data = n;
  start->next = NULL;
  Queue *q = new Queue;
  q->start = start;
  q->end = end;
  return q;
}

void push (Queue* s, char* n)
{
  Element *to_add = new Element;
  to_add->data = s->start->data;
  to_add->next = s->start->next;
  s->start->data = n;
  s->start->next = to_add;
} 
char* pop (Queue* s)
{
  char* data = s->end->data;
  Element *to_pop = new Element;
  to_pop->data = s->end->data;
  if (s->end->next != NULL)
    {
      s->end->data = s->end->next->data;
      s->end->next = s->end->next->next;
    }
  else
    {
      s->end->data = NULL;
    }
  delete to_pop;
  return data;
}

char* front(Queue* s)
{
  return s->start->data;
}

char* back(Queue* s)
{
  return s->end->data;
}

int main ()
{
    srand (time (nullptr));
    char* elem_to_add = new char[6];
	for (int i = 0; i < 5; i++)
	{
		elem_to_add[i] = rand() % 61 + 65;
    }
    elem_to_add[5] = '\0';
    Queue *s = create_queue(elem_to_add);
    for (int i = 0; i < 20; i++)
    {
        elem_to_add = new char[6];
        for (int i = 0; i < 5; i++)
	{
		elem_to_add[i] = rand() % 61 + 65;
    }
    elem_to_add[5] = '\0';
      push (s, elem_to_add);
    }
    char* elem = pop(s);
    cout << elem << ' ';
    Queue *tmp = create_queue (elem);
    while (front (s) != NULL)
    {
       
        
        push (tmp, pop(s));
    }
    while (front (tmp) != NULL)
    {
        elem = pop(tmp);
        cout << elem << ' ';
        push (s, elem);
    }
    int index;
    char *elem_to_add_second = new char[6];
    cout << endl << "What elemet to add? ";
    cin >> elem_to_add_second;
    cout << "To what position? ";
    cin >> index;
    while (front (s) != NULL)
    {
        push (tmp, pop(s));
    }
    int i = 0;
    while (front (tmp) != NULL)
    {
        if (i == index)
        {
            push(s, elem_to_add_second);
        }
        else
        {
            push(s, pop(tmp));
        }
        i++;
    }
    while (front (s) != NULL)
    {
        push (tmp, pop(s));
    }
    while (front (tmp) != NULL)
    {
        char *elem_to_print = pop(tmp);
        cout << elem_to_print << ' ';
        push (s, elem_to_print);
    }
}
