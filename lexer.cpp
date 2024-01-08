
#pragma once
#include <iostream>
#include "token.cpp"

const int TOTAL_KEYWORDS = 8;
const char KEYWORDS[TOTAL_KEYWORDS] = {'>', '<', '[', ']', '+', '-', ',', '.'};


class Lexer
{

private:
    std::string code;
    std::vector<Token *> tokens;

    bool keyworkExists(char l);

public:
    Lexer(std::string code);
    std::vector<Token *> run();
};


Lexer::Lexer(std::string code)
{
    this->code = code;
}

bool Lexer::keyworkExists(char l)
{

    for (int i = 0; i < TOTAL_KEYWORDS; i++)
    {
        if (l == KEYWORDS[i])
            return true;
    }

    return false;
}

std::vector<Token *> Lexer::run()
{
    for (int i = 0; i < this->code.length(); i++)
    {
        if (!keyworkExists(this->code[i]))
            continue;
        this->tokens.push_back(new Token(this->code[i]));
    }
    return this->tokens;
}