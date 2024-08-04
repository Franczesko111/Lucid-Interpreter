#pragma once
#include "Data.hpp"

std::vector<Token> Lexer(const std::string &source_code);
void NewToken(std::string &buffer, const TokenType bckp_type = TokenType::ERROR);
TokenType ParseBufferStr(const std::string &buffer);
TokenType ParseBufferCh(const char ch);
TokenType SwitchTokenType(TokenType type);
bool SpecialToken(const TokenType type);