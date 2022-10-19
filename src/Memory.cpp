/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** Memory.cpp
*/

#include "../include/Memory.hpp"
#include <algorithm>

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}

void Stack::push(IOperand *operand)
{
    _stack.push_back(operand);
}


void Stack::dump()
{
    for(int i = (_stack.size() - 1); i >= 0; i--){
        std::cout << _stack[i]->toString() << std::endl;
    }
}

void Stack::pop()
{
    if (is_empty(_stack))
        Error("Empty stack", 84);
    _stack.pop_back();
}

void Stack::clear()
{
    if (is_empty(_stack))
        Error("Empty stack, can't clear", 84);
    _stack.clear();
}

void Stack::dup()
{
    if (is_empty(_stack))
        Error("Empty stack", 84);
    _stack.push_back(_stack[_stack.size() -1]);
}

void Stack::swap()
{
    if (menos_dos(_stack))
        Error("Cannot swap with less than 2 value in stack", 84);
    IOperand* op1 = _stack[_stack.size() - 1];
    IOperand* op2 = _stack[_stack.size() - 2];
    _stack.pop_back();
    _stack.pop_back();
    _stack.push_back(op1);
    _stack.push_back(op2);
}

void Stack::asert(IOperand* operand)
{
    if (is_empty(_stack))
        Error("Empty stack", 84);
    if (operand->getType() != _stack[_stack.size() - 1]->getType() || operand->toString() != _stack[_stack.size() - 1]->toString()) {
        std::cerr << "ERROR 1" << std::endl;
        exit(84);
    }
}
void Stack::add()
{
    if (menos_dos(_stack))
        Error("Cannot add with less than 2 value in stack", 84);
    IOperand *result = _stack[_stack.size() - 2]->operator+(*_stack[_stack.size() - 1]);
    this->pop();
    this->pop();
    this->_stack.push_back(result);

}
void Stack::sub()
{
    if (menos_dos(_stack))
        Error("Cannot sub with less than 2 value in stack", 84);
    IOperand *result = _stack[_stack.size() - 2]->operator-(*_stack[_stack.size() - 1]);
    this->pop();
    this->pop();
    this->_stack.push_back(result);

}
void Stack::mul()
{
    if (menos_dos(_stack))
        Error("Cannot mul with less than 2 value in stack", 84);
    IOperand *result = _stack[_stack.size() - 2]->operator*(*_stack[_stack.size() - 1]);
    this->pop();
    this->pop();
    this->_stack.push_back(result);
}
void Stack::div()
{
    if (menos_dos(_stack))
        Error("Cannot div with less than 2 value in stack", 84);
    IOperand *result = _stack[_stack.size() - 2]->operator/(*_stack[_stack.size() - 1]);
    this->pop();
    this->pop();
    std::string temp = result->toString();
    eOperandType types = result->getType();
    std::reverse(temp.begin(), temp.end());
    for (int len = 0; temp[len] == '0'; len++) {
        temp[len] = '\0';
    }
    std::reverse(temp.begin(), temp.end());
    this->_stack.push_back(Factory::createOperand(types, temp));

}
void Stack::mod()
{
    if (menos_dos(_stack))
        Error("Cannot mod with less than 2 value in stack", 84);
    IOperand *result = _stack[_stack.size() - 2]->operator%(*_stack[_stack.size() - 1]);
    this->pop();
    this->pop();
    this->_stack.push_back(result);
}

void Stack::mexit()
{
}

void Stack::load(IOperand* operand)
{
    if (_register.size() < 1)
        Error("Load on empty register.", 84);
}

void Stack::store(IOperand* operand)
{
    if (_stack.size() < 1)
        Error("Too small stack for store.", 84);
    if (_register.size() >= 16)
        Error("Register is full.", 84);
    _register.push_back(_stack[0]);
    this->pop();
}

void Stack::mPrint()
{
    if (is_empty(_stack))
        Error("Print but empty stack", 84);
    if (_stack[_stack.size() - 1]->getType() != oInt8)
        Error("Not INT8 for print", 84);
    int ref = std::stoi(_stack[_stack.size() - 1]->toString());
    char mess = static_cast<char>(ref);
    std::cout << mess << std::endl;
}