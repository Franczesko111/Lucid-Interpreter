#pragma once
#include "Lexer.hpp"

void Execute();
void f_InitVariable(LUCID_LOOP_SIZE &i);
void f_GetSetVariable(LUCID_LOOP_SIZE &i);
void UpdateValue(std::string &var, LUCID_LOOP_SIZE & i);
uint16_t FindVariable(const std::string &var);