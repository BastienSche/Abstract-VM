/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** Type.cpp
*/

#include "../include/Type.hpp"
#include "../include/Factory.hpp"

//FINIR CONSTRUCTEUR POUR TOUS

void Error(std::string error, int ret)
{
    std::cerr << "Error : " << error << std::endl;
    exit(ret);
}

eOperandType getBestType(eOperandType type1, eOperandType type2)
{
    if (type1 < type2)
        return type2;
    else
        return type1;
}

//////////////////////////// INT 8 /////////////////////////////////

Int8::Int8(std::string const &str) : _str(str)
{
    long nb;
    try {
        nb = std::stol(str);
    } catch (std::out_of_range& e) {
        Error("overflow float", 84);
    } catch(std::invalid_argument& e){
        Error("value", 84);
    }
    if (nb < -127 || nb > 126)
        Error("overflow or underflow on a value", 84);
    _int8 = nb;
}

Int8::~Int8()
{

}

std::string Int8::toString() const
{
    return _str;
}

eOperandType Int8::getType() const
{
    return (eOperandType::oInt8);
}

IOperand *Int8::operator+(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb + secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int8::operator-(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb - secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int8::operator*(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb * secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int8::operator/(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    long int result = firstNb / secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int8::operator%(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    long int result = firstNb % secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

//////////////////////////// INT 16 /////////////////////////////////

Int16::Int16(std::string const &str) : _str(str)
{
    long nb;
    try {
        nb = std::stol(str);
    } catch (std::out_of_range& e) {
        Error("overflow float", 84);
    } catch(std::invalid_argument& e){
        Error("value", 84);
    }
    if (nb < -32767 || nb > 32766)
        Error("overflow or underflow on a value", 84);
    _int16 = nb;
}

Int16::~Int16()
{

}

std::string Int16::toString() const
{
    return _str;
}

eOperandType Int16::getType() const
{
    return eOperandType::oInt16;
}
 
IOperand *Int16::operator+(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb + secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int16::operator-(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb - secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int16::operator*(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb * secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int16::operator/(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    long int result = firstNb / secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Int16::operator%(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    long int result = firstNb % secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

//////////////////////////// INT 32 /////////////////////////////////

Int32::Int32(std::string const &str) : _str(str)
{
    long nb;
    try {
        nb = std::stol(str);
    } catch (std::out_of_range& e) {
        Error("overflow float", 84);
    } catch(std::invalid_argument& e){
        Error("value", 84);
    }
    if (nb < -2147483646 || nb > 2147483647)
        Error("overflow or underflow on a value", 84);
    _int32 = nb;
}

Int32::~Int32()
{

}

std::string Int32::toString() const
{
    return _str;
}

eOperandType Int32::getType() const
{
    return eOperandType::oInt32;
}

IOperand *Int32::operator+(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb + secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Int32::operator-(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb - secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Int32::operator*(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    long int result = firstNb * secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Int32::operator/(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    long int result = firstNb / secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Int32::operator%(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    long int firstNb = std::stol(this->toString().c_str());
    long int secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    long int result = firstNb % secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

//////////////////////////// Float /////////////////////////////////

Float::Float(std::string const &str) : _str(str)
{
    try {
        _float = std::stof(str);
    } catch (std::out_of_range& e) {
        Error("overflow float", 84);
    } catch(std::invalid_argument& e){
        Error("value", 84);
    }
}

Float::~Float()
{

}

std::string Float::toString() const
{
    return _str;
}

eOperandType Float::getType() const
{
    return eOperandType::oInt32;
}

IOperand *Float::operator+(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    float firstNb = std::stol(this->toString().c_str());
    float secondNb = std::stol(rhs.toString().c_str());
    float result = firstNb + secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Float::operator-(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    float firstNb = std::stol(this->toString().c_str());
    float secondNb = std::stol(rhs.toString().c_str());
    float result = firstNb - secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Float::operator*(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    float firstNb = std::stol(this->toString().c_str());
    float secondNb = std::stol(rhs.toString().c_str());
    float result = firstNb * secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Float::operator/(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    float firstNb = std::stol(this->toString().c_str());
    float secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    float result = firstNb / secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}
IOperand *Float::operator%(const IOperand &rhs) const
{
    // eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    // float firstNb = std::stol(this->toString().c_str());
    // float secondNb = std::stol(rhs.toString().c_str());
    // float result = firstNb % secondNb;
    // return (Factory::createOperand(Ttype, std::to_string(result)));
    Error ("Modulo a Float", 84);
}

//////////////////////////// Double /////////////////////////////////

Double::Double(std::string const &str) : _str(str)
{
    try {
        _double = std::stod(str);
    } catch (std::out_of_range& e) {
        Error("overflow float", 84);
    } catch(std::invalid_argument& e){
        Error("value", 84);
    }
}

Double::~Double()
{

}

std::string Double::toString() const
{
    return _str;
}

eOperandType Double::getType() const
{
    return eOperandType::oDouble;
}

IOperand *Double::operator+(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    double firstNb = std::stol(this->toString().c_str());
    double secondNb = std::stol(rhs.toString().c_str());
    double result = firstNb + secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Double::operator-(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    double firstNb = std::stol(this->toString().c_str());
    double secondNb = std::stol(rhs.toString().c_str());
    double result = firstNb - secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Double::operator*(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    double firstNb = std::stol(this->toString().c_str());
    double secondNb = std::stol(rhs.toString().c_str());
    double result = firstNb * secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Double::operator/(const IOperand &rhs) const
{
    eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    double firstNb = std::stol(this->toString().c_str());
    double secondNb = std::stol(rhs.toString().c_str());
    if (secondNb == 0)
        Error("Modulo by zero.", 84);
    double result = firstNb / secondNb;
    return (Factory::createOperand(Ttype, std::to_string(result)));
}

IOperand *Double::operator%(const IOperand &rhs) const
{
    // eOperandType Ttype = getBestType(this->getType(), rhs.getType());
    // double firstNb = std::stol(this->toString().c_str());
    // double secondNb = std::stol(rhs.toString().c_str());
    // double result = firstNb % secondNb;
    // return (Factory::createOperand(Ttype, std::to_string(result)));
    Error("Modulo a Double", 84);
}

//////////////////////////// BigDecimal /////////////////////////////////

BigDecimal::BigDecimal(std::string const &str) : _str(str)
{
    _bigdecimal = str;
}

BigDecimal::~BigDecimal()
{

}

std::string BigDecimal::toString() const
{
    return _str;
}

eOperandType BigDecimal::getType() const
{
    return eOperandType::oDouble;
}

IOperand *BigDecimal::operator+(const IOperand &rhs) const
{
}
IOperand *BigDecimal::operator-(const IOperand &rhs) const
{
}
IOperand *BigDecimal::operator*(const IOperand &rhs) const
{
}
IOperand *BigDecimal::operator/(const IOperand &rhs) const
{
}
IOperand *BigDecimal::operator%(const IOperand &rhs) const
{
    Error("Bigdecimal error", 84);
}