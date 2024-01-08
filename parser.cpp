#pragma once
#include "lexer.cpp"

class Parser{

public:
    bool parse(std::vector<Token *> tokens){

        int brackets = 0;
        bool openingBrackFound = false;
        for (int i = 0; i < tokens.size(); i++)
        {

            if (brackets < 0)
                return true; // closing brackets have exceeded the opening brackets

            if (tokens[i]->token == LOOP_START)
            {
                brackets++;
            }
            else if (tokens[i]->token == LOOP_END)
            {
                brackets--;
            }
        }

        if (brackets != 0)
        {
            return true;
        }
        return false;
    }
};