#include <iostream>
#include <ctime>
using namespace std;
struct Stack
{
  int data;
  Stack *next;
};
Stack * create_stack (int n)
{
  Stack *start = new Stack;
  start->data = n;
  start->next = NULL;
  Stack *s = start;
  return start;
}

void push (Stack * s, int n)
{
  Stack *to_add = new Stack;
  to_add->data = s->data;
  to_add->next = s->next;
  s->data = n;
  s->next = to_add;
} 
int pop (Stack * s)
{
  int data = s->data;
  Stack *to_pop = new Stack;
  to_pop->data = s->data;
  if (s->next != NULL)
    {
      s->data = s->next->data;
      s->next = s->next->next;
    }
  else
    {
      s->data = NULL;
    }
  delete to_pop;
  return data;
}

int top (Stack * s)
{
  return s->data;
}

int main ()
{
    srand (time (nullptr));
    Stack *s = create_stack (rand() % 200 - 100);
    for (int i = 0; i < 20; i++)
    {
      push (s, rand() % 200 - 100);
    }
    int elem = pop(s);
    cout << elem << ' ';
    Stack *tmp = create_stack (elem);
    while (top (s) != NULL)
    {
        elem = pop(s);
        cout << elem << ' ';
        push (tmp, elem);
    }
    while (top (tmp) != NULL)
    {
        push (s, pop(tmp));
    }
    while (top (s) != NULL)
    {
      push (tmp, pop (s));
    }
    bool flag = false;
    while (top (tmp) != NULL)
    {
      int elem = pop (tmp);
      if (flag || (elem % 2) != 0)
	  {
	        push (s, elem);
	  }
      else
	  {
	    flag = true;
	  }
    }
    cout << endl;
    while (top (s) != NULL)
    {
        int elem = pop(s);
        cout << elem << ' ';
        push (tmp, elem);
    }
    while (top (tmp) != NULL)
    {
        push (s, pop(tmp));
    }
}
