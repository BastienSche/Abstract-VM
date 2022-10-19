/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** __IOperand__
*/

#ifndef __IOperand__
#define __IOperand__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdint>
#include <array>
#include <string>
#include <cstdlib>

typedef enum eOperandType {oInt8, oInt16, oInt32, oFloat, oDouble, oBigDecimal};

class IOperand
{
private:
    eOperandType type;
public:
    virtual std::string toString() const = 0; // string that represents the instance
    virtual eOperandType getType() const = 0; // returns the type of instance
    virtual IOperand* operator+(const IOperand &rhs) const = 0; // sum 
    virtual IOperand* operator-(const IOperand &rhs) const = 0; // difference 
    virtual IOperand* operator*(const IOperand &rhs) const = 0; // product 
    virtual IOperand* operator/(const IOperand &rhs) const = 0; // quotient 
    virtual IOperand* operator%(const IOperand &rhs) const = 0; // modulo
    virtual ~IOperand() {}
};

void Error(std::string error, int ret);
bool menos_dos(std::vector<IOperand*> &operand);
bool is_exit_exist(std::vector<std::string> &str);
bool is_empty(std::vector<IOperand*> &operand);
#endif //__IOperand__