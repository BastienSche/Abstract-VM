/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** __Factory__
*/

#ifndef __Factory__
#define __Factory__

#include "IOperand.hpp"

class Factory
{
private:
    //METTTRE LES FONCTIONS EN PRIVATE
protected:

public:
    Factory(/* args */);
    ~Factory();
    IOperand* createInt8(const std::string& value);
    IOperand* createInt16(const std::string& value);
    IOperand* createInt32(const std::string& value);
    IOperand* createFloat(const std::string& value);
    IOperand* createDouble(const std::string& value);
    IOperand* createBigDecimal(const std::string& value);
    static IOperand* createOperand(eOperandType type, const std::string& value);
};

typedef IOperand* (Factory::* funcPtr)(const std::string& value);

#endif //__Factory__

//IOperand* (Factory::*function)(const std::string& value);