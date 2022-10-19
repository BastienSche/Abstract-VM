/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** __Chipset__
*/

#ifndef __Chipset__
#define __Chipset__

#include "Factory.hpp"
#include "Memory.hpp"

class Chipset
{
private:
    std::string _command;
    eOperandType _type;
    std::string _value;
    Stack _stack;
    bool _file;
    bool _exits;
public:
    Chipset(/* args */);
    ~Chipset();
    void parser(char**);
    size_t get_command(std::string line, size_t i);
    size_t get_type(std::string line, size_t i);
    size_t get_value(std::string line, size_t i);
    void handle_input();
    void error_managment(std::string);
    void exec_cmd();
    bool getCommandLine(std::string line);
    eOperandType identify_type(std::string type);
    void init_all();
    void push();
	void pop();
	void clear();
    void dump();
    void dup();
    void swap();
    void asert();
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void readFile(std::istream *stream);
    void mPrint();
    void checkComments(std::string line);
    void load();
    // //void sqrt();
    // void load(std::unique_ptr<IOperand>);
    void store();
    void mexit();
};
//typedef void* (Chipset::* cmdPtr)(const std::string& value);

#endif //__Chipset__