/*
** EPITECH PROJECT, 2021
** AbstractVM
** File description:
** Tools.cpp
*/

#include "../include/IOperand.hpp"

bool is_empty(std::vector<IOperand*> &operand)
{
    if (operand.size() != 0)
        return false;
    else
        return true;
}

bool is_exit_exist(std::vector<std::string> &str)
{
    for (int i = 0;i < str.size(); i++) {
        if (str[i] == "exit")
            return true;
    }
    return false;
}

bool menos_dos(std::vector<IOperand*> &operand)
{
    if (operand.size() <= 1)
        return true;
    else
        return false;
}