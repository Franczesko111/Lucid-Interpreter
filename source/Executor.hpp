#pragma once
#include "Lexer.hpp"

void Execute();
void f_InitVariable(uint16_t &i);
void f_GetSetVariable(uint16_t &i);
void UpdateValue(std::string &var, uint16_t & i);
uint16_t FindVariable(const std::string &var);