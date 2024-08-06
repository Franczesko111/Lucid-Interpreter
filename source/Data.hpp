#pragma once
#include <vector>
#include <string>

typedef uint16_t LUCID_LOOP_SIZE;
typedef int16_t LUCID_DATA_SIZE;

// Tokens
enum class TokenType
{
    VAR_INIT,
    VAR_NAME,
    VAR_GET,
    IF_OP,
    THEN_OP,
    NUMBER,

    PLUS_SYM,
    MINUS_SYM,
    MULTIPLY_SYM,
    DIVIDE_SYM,

    EQUALS,
    SEMICOLON,
    AT_SYM,

    ERROR
};

struct Token
{
    TokenType type;
    std::string value;
};

inline std::vector<Token> tokens;


// Variables
struct Variable
{
    std::string name;
    std::string value;
};

inline std::vector<Variable> variables;


// Special arguments
enum SpecialArgs
{
    FAST_MATH
};

inline bool special_arguments[1] = {false};