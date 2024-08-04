#pragma once
#include "Lexer.hpp"

struct Variable
{
    std::string name;
    std::string value;
};

inline std::vector<Variable> variables;

void Execute();
void f_InitVariable(uint16_t &i);