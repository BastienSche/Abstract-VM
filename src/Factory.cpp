/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** Factory.cpp
*/

#include "../include/Factory.hpp"
#include "../include/Type.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand* Factory::createInt8(const std::string& value) {
    return new Int8(value);
}

IOperand* Factory::createInt16(const std::string& value) {
    return new Int16(value);
}

IOperand* Factory::createInt32(const std::string& value) {
    return new Int32(value);
}

IOperand* Factory::createFloat(const std::string& value) {
    return new Float(value);
}

IOperand* Factory::createDouble(const std::string& value) {
    return new Double(value);
}

IOperand* Factory::createBigDecimal(const std::string& value) {
    return new BigDecimal(value);
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value) {
    Factory *factory = new Factory(); //static donc je crée ma class ici ( pas au niveau de l'appelle)
    std::array<eOperandType, 6> arrayOfTypes = {oInt8, oInt16, oInt32, oFloat, oDouble, oBigDecimal};
    std::array<funcPtr, 6> arrayPtrFunctions = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble, &Factory::createBigDecimal};
    for (int i = 0;i < 6; i++) {
        if (type == arrayOfTypes[i]) {
            return (((*factory).*arrayPtrFunctions[i])(value));
        }
    }
}