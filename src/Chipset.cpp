/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** Chipset.cpp
*/

#include "../include/Chipset.hpp"
#include <fstream>

Chipset::Chipset(/* args */)
{
    _file = false;
    _exits = false;
}

Chipset::~Chipset()
{
}

size_t Chipset::get_command(std::string line, size_t i)
{
    for (; i < line.length(); i++){
        if (line[i] == ' ') {
            for (;line[i] == ' '; i++);
            i--;
            break;
        }
        this->_command += line[i];
    }
    i++;
    return i;
}

eOperandType Chipset::identify_type(std::string type)
{
    std::string type_tab[6] = {"int8", "int16", "int32", "float", "double", "bigdecimal"};
    eOperandType enum_tab[6] = {oInt8, oInt16, oInt32, oFloat, oDouble, oBigDecimal};
    for(size_t i = 0; i < type.length(); i++){
        type[i] = tolower(type[i]);
    }
    for (int i = 0; i < 6; i++){
        if (type == type_tab[i])
            return enum_tab[i];
    }
    Error("Bad Type", 84);
}

size_t Chipset::get_type(std::string line, size_t i)
{
    std::string temp;
    for (; i < line.length(); i++){
        if (line[i] == '(')
            break;
        temp += line[i];
    }
    i++;
    this->_type = identify_type(temp);
    return i;
}

bool IsNumberValid(std::string val)
{
    if (val.find_first_not_of("0123456789.-") == std::string::npos){
        return true;
    } else {
        return false;
    }    
}
size_t Chipset::get_value(std::string line, size_t i)
{
    for (; i < line.length() - 1; i++){
        if (line[i] == ')')
            break;
        this->_value += line[i];
    }
    if (!IsNumberValid(_value))
        Error("Not valid number", 84);
    return i;
}

bool Chipset::getCommandLine(std::string line)
{
    if (!strcmp(line.c_str(), ";;")) {
        if (_exits == false)
            Error("stop but not exit", 84);
        else
            exit(0);
    }
    if (line[0] == ';')
        return false;
    size_t i = 0;
    i = get_command(line, i);
    if (this->_command == "push" || this->_command == "assert" ||
    this->_command == "load" || this->_command == "store"){
        i = get_type(line, i);
        i = get_value(line, i);
    }
    return true;
}

void Chipset::push()
{
    _stack.push(Factory::createOperand(_type, _value));
}

void Chipset::dump()
{
    _stack.dump();
}

void Chipset::pop()
{
    _stack.pop();
}

void Chipset::clear()
{
    _stack.clear();
}

void Chipset::dup()
{
    _stack.dup();
}

void Chipset::swap()
{
    _stack.swap();
}

void Chipset::asert()
{
    _stack.asert(Factory::createOperand(_type, _value));
}
void Chipset::add()
{
    _stack.add();
}
void Chipset::sub()
{
    _stack.sub();
}
void Chipset::mul()
{
    _stack.mul();
}
void Chipset::div()
{
    _stack.div();
}
void Chipset::mod()
{
    _stack.mod();
}
void Chipset::mexit()
{
    _exits = true;
    _stack.mexit();
}
void Chipset::mPrint()
{
    _stack.mPrint();
}
void Chipset::load()
{
    _stack.load(Factory::createOperand(_type, _value));
}
void Chipset::store()
{
    _stack.store(Factory::createOperand(_type, _value));
}

void Chipset::exec_cmd()
{
    if (!strcmp(_command.c_str(), "push"))
        Chipset::push();
    else if (!strcmp(_command.c_str(), "dump"))
        Chipset::dump();
    else if (!strcmp(_command.c_str(), "pop"))
        Chipset::pop();
    else if (!strcmp(_command.c_str(), "clear"))
        Chipset::clear();
    else if (!strcmp(_command.c_str(), "dup"))
        Chipset::dup();
    else if (!strcmp(_command.c_str(), "swap"))
        Chipset::swap();
    else if (!strcmp(_command.c_str(), "assert"))
        Chipset::asert();
    else if (!strcmp(_command.c_str(), "add"))
        Chipset::add();
    else if (!strcmp(_command.c_str(), "sub"))
        Chipset::sub();
    else if (!strcmp(_command.c_str(), "mul"))
        Chipset::mul();
    else if (!strcmp(_command.c_str(), "div"))
        Chipset::div();
    else if (!strcmp(_command.c_str(), "mod"))
        Chipset::mod();
    else if (!strcmp(_command.c_str(), "exit"))
        Chipset::mexit();
    else if (!strcmp(_command.c_str(), "print"))
        Chipset::mPrint();
    else if(!strcmp(_command.c_str(), "load"))
        Chipset::load();
    else if (!strcmp(_command.c_str(), "store"))
        Chipset::store();
    else
        Error("Unknow Command", 84);
}

void Chipset::init_all()
{
    _command = "\0";
    _value = "\0";
}

void Chipset::checkComments(std::string line)
{
}

void Chipset::handle_input()
{
    std::string line("");
    _file = false;
    while (1) {
        Chipset::init_all();
        std::getline(std::cin, line);
        if (Chipset::getCommandLine(line))
            Chipset::exec_cmd();
        line.clear();
    }
}


void Chipset::readFile(std::istream *stream)
{
    std::string line("");
    _file = true;
    while (std::getline(*stream, line)) {
        Chipset::init_all();
        if (Chipset::getCommandLine(line))
            Chipset::exec_cmd();
        line.clear();
    }
}

int main(int ac, char **av)
{
    Chipset *core = new Chipset;
    std::ifstream file;
    if (ac == 2) {
        std::ifstream file;
        file.open(av[1]);
        core->readFile(&file);
    } else {
        core->handle_input();
    }
}