/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** __Memory__
*/

#ifndef __Memory__
#define __Memory__

#include "Factory.hpp"

class Stack
{
private:
    std::vector<IOperand*> _stack;
    std::vector<IOperand*> _register;
public:
	void push(IOperand*);
	void pop();
	void clear();
    void dump();
    void dup();
    void swap();
    void asert(IOperand*);
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void mexit();
    void mPrint();
    void load(IOperand*);
    void store(IOperand*);
    Stack(/* args */);
    ~Stack();
};

#endif //__Memory__


//NO EXIT 84
//SI 0$

// push double(3.132947123847)
// push double(2.3294823)