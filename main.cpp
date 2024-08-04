#include <fstream>
#include <sstream>
#include "source/Lexer.hpp"

// Vector of tokens is global

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
            
            default:
                printf("ERROR");
        }

        if(token.value.size() > 0)
            printf(": %s\n", token.value.c_str());
        else
            printf("\n");
    }

    return 0;
}