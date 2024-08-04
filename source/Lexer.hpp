#pragma once
#include <vector>
#include <string>

enum class TokenType
{
    VAR_INIT,
    IF_OP,
    THEN_OP,

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
void NewToken(std::string &buffer);
TokenType ParseBufferStr(const std::string &buffer);
TokenType ParseBufferCh(const char ch);