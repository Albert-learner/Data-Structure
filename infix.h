#pragma
#ifndef __INFIX_H__
#define __INFIX_H__

#include <iostream>
#include <string>

using namespace std;

void create_stack();
void push(char num);
int pop();
int prior(char num);
int isEmpty();
void eval(char *a, int b);

#endif 


