#include "Lexer.hpp"

std::vector<Token> Lexer(const std::string &source_code)
{
    tokens.clear();
    std::string buffer;
    char let;

    for(uint16_t i = 0; i < source_code.size(); i++)
    {
        let = source_code[i];

        if(isspace(let))
        {
            if(buffer.size() > 0)
                NewToken(buffer);
            continue;
        }

        buffer += let;
    }
    
    NewToken(buffer);
    return tokens;
}

void NewToken(std::string &buffer)
{
    TokenType type = ParseBuffer(buffer);
    tokens.push_back( {.type = type} );
    buffer.clear();
}

TokenType ParseBuffer(const std::string &buffer)
{
    if(buffer == "var") return TokenType::VAR_INIT;
    else if(buffer == "if") return TokenType::IF_OP;
    else if(buffer == "then") return TokenType::THEN_OP;
    else return TokenType::ERROR;
}