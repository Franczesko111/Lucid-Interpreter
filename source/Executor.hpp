#pragma once
#include "Lexer.hpp"

enum class MathOp
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

void Execute();
void f_InitVariable(LUCID_LOOP_SIZE &i);
void f_GetSetVariable(LUCID_LOOP_SIZE &i);
void UpdateValue(std::string &var, LUCID_LOOP_SIZE &i);
LUCID_LOOP_SIZE FindVariable(const std::string &var);
void MathUpdateTokens(const LUCID_LOOP_SIZE i, LUCID_DATA_SIZE(*func)(LUCID_DATA_SIZE, LUCID_DATA_SIZE));
bool MathLoop(TokenType type);

LUCID_DATA_SIZE MathAdd(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b);
LUCID_DATA_SIZE MathSubtract(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b);
LUCID_DATA_SIZE MathMultiply(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b);
LUCID_DATA_SIZE MathDivide(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b);