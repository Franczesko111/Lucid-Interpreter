#include "Executor.hpp"

// REMEMBER - Tokens are global!!!

void Execute()
{
    for(uint16_t i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].type == TokenType::SEMICOLON) continue;

        switch(tokens[i].type)
        {
            case TokenType::VAR_INIT:
                f_InitVariable(i); break;
            
            case TokenType::VAR_GET:
                f_GetSetVariable(i); break;
            
            default: break;
        }
    }
}

void f_InitVariable(uint16_t &i)
{
    Variable var;
    var.name = tokens[++i].value;
    if(tokens[++i].type == TokenType::EQUALS)
        var.value = tokens[++i].value;

    variables.push_back(var);
}

void f_GetSetVariable(uint16_t &i)
{
    uint16_t var_id;
    bool var_error = true;
    i++;
    for(var_id = 0; i < variables.size(); var_id++) {
        if(variables[var_id].name == tokens[i].value) {
            var_error = false;
            break;
        }
    }

    if(var_error) {
        printf("A variable \"%s\" does not exist.\n", tokens[i].value.c_str());
        return;
    }

    if(tokens[++i].type == TokenType::EQUALS)
        variables[var_id].value = tokens[++i].value;
}