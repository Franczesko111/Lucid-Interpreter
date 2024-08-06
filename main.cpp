#include <sstream>
// Timer.hpp has the ffstream library inside
#include "source/Timer.hpp"
// Executor.hpp has Lexer.hpp inside
#include "source/Executor.hpp"

// Vector of tokens is global

void PrintTokens();

int main()
{
    std::string source_code;
    {
        std::ifstream file("main.lc");
        std::stringstream buffer;
        buffer << file.rdbuf();
        source_code = buffer.str();
    }

    printf("%s\n\n", source_code.c_str());
    Lexer(source_code);

    PrintTokens();
    printf("\n\n");
    Execute();
    PrintTokens();

    printf("\n\nVariables:\n");

    for(Variable var: variables) {
        printf("%s: %s\n", var.name.c_str(), var.value.c_str());
    }

    return 0;
}

void PrintTokens()
{
    for(Token token: tokens)
    {
        switch(token.type)
        {
            case TokenType::VAR_INIT:
                printf("VAR_INIT"); break;

            case TokenType::IF_OP:
                printf("IF_OP"); break;

            case TokenType::THEN_OP:
                printf("THEN_OP"); break;
            
            case TokenType::EQUALS:
                printf("EQUALS"); break;

            case TokenType::SEMICOLON:
                printf("SEMICOLON"); break;

            case TokenType::NUMBER:
                printf("NUMBER"); break;
            
            case TokenType::VAR_NAME:
                printf("VAR_NAME"); break;
            
            case TokenType::VAR_GET:
                printf("VAR_GET"); break;

            case TokenType::PLUS_SYM:
                printf("PLUS_SYM"); break;
            
            case TokenType::MINUS_SYM:
                printf("MINUS_SYM"); break;
            
            case TokenType::MULTIPLY_SYM:
                printf("MULTIPLY_SYM"); break;
            
            case TokenType::DIVIDE_SYM:
                printf("DIVIDE_SYM"); break;

            case TokenType::AT_SYM:
                printf("AT_SYM"); break;
            
            default:
                printf("ERROR");
        }

        if(token.value.size() > 0)
            printf(": %s\n", token.value.c_str());
        else
            printf("\n");
    }
}