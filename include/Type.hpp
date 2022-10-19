/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** __Type__
*/

#ifndef __Type__
#define __Type__n

#include "IOperand.hpp"

eOperandType getBestType(eOperandType type1, eOperandType type2);

class Int32 : public IOperand
{
private:
    long _int32;
    std::string _str;
public:
    Int32(std::string const &str);
    ~Int32();
    std::string toString() const override;
	eOperandType getType () const override;
    IOperand *operator+(const IOperand &rhs) const override; // sum
    IOperand *operator-(const IOperand &rhs) const override; // difference
    IOperand *operator*(const IOperand &rhs) const override; // product
    IOperand *operator/(const IOperand &rhs) const override; // quotient
    IOperand *operator%(const IOperand &rhs) const override; // modulo
};

class Int16 : public IOperand
{
private:
    long _int16;
    std::string _str;
public:
    Int16(std::string const &str);
    ~Int16();
    std::string toString() const override;
	eOperandType getType () const override;
    IOperand *operator+(const IOperand &rhs) const override; // sum
    IOperand *operator-(const IOperand &rhs) const override; // difference
    IOperand *operator*(const IOperand &rhs) const override; // product
    IOperand *operator/(const IOperand &rhs) const override; // quotient
    IOperand *operator%(const IOperand &rhs) const override; // modulo
};

class Int8 : public IOperand
{
private:
    long _int8;
    std::string _str;
public:
    Int8(std::string const &str);
    ~Int8();
    std::string toString() const override;
	eOperandType getType () const override;
    IOperand *operator+(const IOperand &rhs) const override; // sum
    IOperand *operator-(const IOperand &rhs) const override; // difference
    IOperand *operator*(const IOperand &rhs) const override; // product
    IOperand *operator/(const IOperand &rhs) const override; // quotient
    IOperand *operator%(const IOperand &rhs) const override; // modulo
};

class Float : public IOperand
{
private:
    float _float;
    std::string _str;
public:
    Float(std::string const &str);
    ~Float();
    std::string toString() const override;
	eOperandType getType () const override;
    IOperand *operator+(const IOperand &rhs) const override; // sum
    IOperand *operator-(const IOperand &rhs) const override; // difference
    IOperand *operator*(const IOperand &rhs) const override; // product
    IOperand *operator/(const IOperand &rhs) const override; // quotient
    IOperand *operator%(const IOperand &rhs) const override; // modulo
};

class Double : public IOperand
{
private:
    double _double;
    std::string _str;
public:
    Double(std::string const &str);
    ~Double();
    std::string toString() const override;
	eOperandType getType () const override;
    IOperand *operator+(const IOperand &rhs) const override; // sum
    IOperand *operator-(const IOperand &rhs) const override; // difference
    IOperand *operator*(const IOperand &rhs) const override; // product
    IOperand *operator/(const IOperand &rhs) const override; // quotient
    IOperand *operator%(const IOperand &rhs) const override; // modulo
};

class BigDecimal : public IOperand
{
private:
    std::string _bigdecimal;
    std::string _str;
public:
    BigDecimal(std::string const &str);
    ~BigDecimal();
    std::string toString() const override;
	eOperandType getType () const override;
    IOperand *operator+(const IOperand &rhs) const override; // sum
    IOperand *operator-(const IOperand &rhs) const override; // difference
    IOperand *operator*(const IOperand &rhs) const override; // product
    IOperand *operator/(const IOperand &rhs) const override; // quotient
    IOperand *operator%(const IOperand &rhs) const override; // modulo
};

#endif //__Type__