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

        if(ispunct(let))
        {
            if(buffer.size() > 0)
                NewToken(buffer);
            buffer = let;
            NewToken(buffer);
            continue;
        }

        buffer += let;
    }
    
    if(buffer.size() > 0)
        NewToken(buffer);
    return tokens;
}

void NewToken(std::string &buffer)
{
    TokenType type = (buffer.size() > 1) ? ParseBufferStr(buffer) : ParseBufferCh(buffer[0]);
    tokens.push_back( {.type = type} );
    buffer.clear();
}

TokenType ParseBufferStr(const std::string &buffer)
{
    if(buffer == "var") return TokenType::VAR_INIT;
    else if(buffer == "if") return TokenType::IF_OP;
    else if(buffer == "then") return TokenType::THEN_OP;
    else return TokenType::ERROR;
}

TokenType ParseBufferCh(const char ch)
{
    switch(ch)
    {
        case '=':
            return TokenType::EQUALS; break;
        
        case ';':
            return TokenType::SEMICOLON; break;
        
        default:
            return TokenType::ERROR;
    }
}