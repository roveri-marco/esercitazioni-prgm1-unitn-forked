#ifndef STACK_H
#define STACK_H

struct node {
    long val;
    node *next;
};
typedef node *stack;
enum retval { FALSE = 0, TRUE = 1 };

void   init(stack& s);
void   deinit(stack& s);
retval shrink(stack& s);
void   add(stack& s,
           long val);
retval first(const stack& s,
             long     & result);
void   print(const stack& s);
retval empty(const stack& s);

#endif // STACK_H
