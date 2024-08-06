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
        UpdateValue(var.name, i);
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
        variables[var_id].value = tokens[++i].value;
}

void UpdateValue(std::string &var, LUCID_LOOP_SIZE & i)
{
    var = tokens[++i].value;
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