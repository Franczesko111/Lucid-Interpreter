#include "Executor.hpp"

// REMEMBER - Tokens are global!!!

void Execute()
{
    for(LUCID_LOOP_SIZE i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].type == TokenType::SEMICOLON) continue;

        switch(tokens[i].type)
        {
            case TokenType::VAR_INIT:
                f_InitVariable(i); break;
            
            case TokenType::VAR_GET:
                f_GetSetVariable(i); break;
            
            case TokenType::VAR_NAME:
            {
                if(FindVariable(tokens[i--].value) == UINT16_MAX)
                    f_InitVariable(i);
                else
                    f_GetSetVariable(i);
            }
            break;
            
            default: break;
        }
    }
}

void f_InitVariable(LUCID_LOOP_SIZE &i)
{
    Variable var;
    var.name = tokens[++i].value;
    if(tokens[++i].type == TokenType::EQUALS)
        UpdateValue(var.value, i);
    else
        i--;

    variables.push_back(var);
}

void f_GetSetVariable(LUCID_LOOP_SIZE &i)
{
    LUCID_LOOP_SIZE var_id;
    bool var_error = false;
    i++;
    var_id = FindVariable(tokens[i].value);
    if(var_id == UINT16_MAX) var_error = true;

    if(var_error) {
        printf("A variable \"%s\" does not exist.\n", tokens[i].value.c_str());
        return;
    }

    if(tokens[++i].type == TokenType::EQUALS)
        UpdateValue(variables[var_id].value, i);
}

void UpdateValue(std::string &var, LUCID_LOOP_SIZE &i)
{
    LUCID_DATA_SIZE temp_1 = 0, temp_2 = 0;
    std::string result;
    i++;

    while(i < tokens.size() && MathLoop(tokens[i].type))
    {
        switch(tokens[i].type)
        {
            case TokenType::NUMBER: break;

            case TokenType::PLUS_SYM: {
                MathUpdateTokens(i, MathAdd);
                i--;
            } break;

            case TokenType::MINUS_SYM: {
                MathUpdateTokens(i, MathSubtract);
                i--;
            } break;

            case TokenType::MULTIPLY_SYM: {
                MathUpdateTokens(i, MathMultiply);
                i--;
            } break;

            case TokenType::DIVIDE_SYM: {
                MathUpdateTokens(i, MathDivide);
                i--;
            } break;

            default: break;
        }
        i++;
    }

    var = tokens[--i].value;
}

LUCID_LOOP_SIZE FindVariable(const std::string &var)
{
    for(LUCID_LOOP_SIZE i = 0; i < variables.size(); i++) {
        if(variables[i].name == var) {
            return i;
        }
    }
    return UINT16_MAX;
}

void MathUpdateTokens(const LUCID_LOOP_SIZE i, LUCID_DATA_SIZE(*func)(LUCID_DATA_SIZE, LUCID_DATA_SIZE))
{
    LUCID_DATA_SIZE temp_1 = stoi(tokens[i-1].value);
    LUCID_DATA_SIZE temp_2 = stoi(tokens[i+1].value);
    tokens[i-1] = { .type = TokenType::NUMBER, .value = std::to_string(func(temp_1, temp_2)) };
    tokens.erase(tokens.begin()+i);
    tokens.erase(tokens.begin()+i);
}

bool MathLoop(TokenType type)
{
    switch(type)
    {
        case TokenType::NUMBER: return true;
        case TokenType::PLUS_SYM: return true;
        case TokenType::MINUS_SYM: return true;
        case TokenType::MULTIPLY_SYM: return true;
        case TokenType::DIVIDE_SYM: return true;
        default: return false;
    }
}

LUCID_DATA_SIZE MathAdd(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b) { return a + b; }
LUCID_DATA_SIZE MathSubtract(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b) { return a - b; }
LUCID_DATA_SIZE MathMultiply(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b) { return a * b; }
LUCID_DATA_SIZE MathDivide(LUCID_DATA_SIZE a, LUCID_DATA_SIZE b) { return a / b; }