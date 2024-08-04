#pragma once
#include <vector>
#include <string>

enum class TokenType
{
    VAR_INIT,
    VAR_NAME,
    IF_OP,
    THEN_OP,
    NUMBER,

    EQUALS,
    SEMICOLON,

    ERROR
};

struct Token
{
    TokenType type;
    std::string value;
};

inline std::vector<Token> tokens;

std::vector<Token> Lexer(const std::string &source_code);
void NewToken(std::string &buffer, const TokenType bckp_type = TokenType::ERROR);
TokenType ParseBufferStr(const std::string &buffer);
TokenType ParseBufferCh(const char ch);
TokenType SwitchTokenType(TokenType type);
bool SpecialToken(const TokenType type);