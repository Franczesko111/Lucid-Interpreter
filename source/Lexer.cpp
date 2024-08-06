#include "Lexer.hpp"

std::vector<Token> Lexer(const std::string &source_code)
{
    tokens.clear();
    std::string buffer;
    char let;

    for(LUCID_LOOP_SIZE i = 0; i < source_code.size(); i++)
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

        if(isdigit(let))
        {
            while(isdigit(let)) {
                buffer += let;
                let = source_code[++i];
            }
            i--;
            NewToken(buffer, TokenType::NUMBER);
            continue;
        }

        buffer += let;
    }
    
    if(buffer.size() > 0)
        NewToken(buffer);
    return tokens;
}

void NewToken(std::string &buffer, const TokenType bckp_type)
{
    // Declaring the type
    TokenType type;
    if(bckp_type == TokenType::ERROR) {
        if(buffer.size() > 1) type = ParseBufferStr(buffer);
        else type = ParseBufferCh(buffer[0]);
    }
    else type = bckp_type;

    type = SwitchTokenType(type);

    if(SpecialToken(type)) buffer.clear();
    tokens.push_back( {.type = type, .value = buffer} );

    buffer.clear();
}

TokenType ParseBufferStr(const std::string &buffer)
{
    if(buffer == "var") return TokenType::VAR_INIT;
    else if(buffer == "if") return TokenType::IF_OP;
    else if(buffer == "then") return TokenType::THEN_OP;
    else return TokenType::VAR_NAME;
}

TokenType ParseBufferCh(const char ch)
{
    switch(ch)
    {
        case '=': return TokenType::EQUALS; break;
        case ';': return TokenType::SEMICOLON; break;
        case '$': return TokenType::VAR_GET; break;
        case '+': return TokenType::PLUS_SYM; break;
        case '-': return TokenType::MINUS_SYM; break;
        default:  return TokenType::ERROR;
    }
}

bool SpecialToken(const TokenType type)
{
    return !(type == TokenType::NUMBER ||
            type == TokenType::VAR_NAME);
}

TokenType SwitchTokenType(TokenType type)
{
    LUCID_LOOP_SIZE id = tokens.size();
    if(id < 1) return type;
    switch(tokens[id-1].type)
    {
        case TokenType::VAR_INIT:
            return TokenType::VAR_NAME; break;

        case TokenType::VAR_GET:
            return TokenType::VAR_NAME; break;
        
        default:
            return type;
    }
}