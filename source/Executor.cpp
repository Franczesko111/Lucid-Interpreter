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