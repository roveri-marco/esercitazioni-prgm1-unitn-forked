#include <iostream>
#include "stack.h"
using namespace std;

void init(stack& s) {
    s = NULL;
}

void deinit(stack& s) {
    node *n = s;

    while (n != NULL) {
        node *tmp = n;
        n = n->next;
        delete tmp;
    }
    s = NULL;
}

retval empty(const stack& s) {
    return s == NULL ? TRUE : FALSE;
}

void add(stack& s, long val) {
    node *n = new node;

    n->val  = val;
    n->next = s;
    s       = n;
}

retval shrink(stack& s) {
    if (empty(s))return FALSE;

    node *first = s;
    s = s->next;
    delete first;

    return TRUE;
}

retval first(const stack& s, long& result) {
    if (empty(s))return FALSE;
    result = s->val;
    return TRUE;
}

void print(const stack& s) {
    node *n = s;

    while (n != NULL) {
        cout << n->val << "";
        n = n->next;
        cout << endl;
    }
}
