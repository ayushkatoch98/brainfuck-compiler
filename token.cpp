

enum TOKENS
{

    INC_MEM_PTR, // >
    DEC_MEM_PTR, // <
    INC_VAL,     // +
    DEC_VAL,     // -
    INPUT_CHAR,  // ,
    PRINT_CHAR,  // .
    LOOP_START,  // [
    LOOP_END,    // ] while (value != 0)

};

class Token{

public:
    enum TOKENS token;
    char letter;

    Token(char letter);
};



Token::Token(char letter)
{
    this->letter = letter;

    if (letter == '>')
    {
        this->token = (TOKENS)INC_MEM_PTR;
    }
    else if (letter == '<')
    {
        this->token = (TOKENS)DEC_MEM_PTR;
    }
    else if (letter == '+')
    {
        this->token = (TOKENS)INC_VAL;
    }
    else if (letter == '-')
    {
        this->token = (TOKENS)DEC_VAL;
    }
    else if (letter == ',')
    {
        this->token = (TOKENS)INPUT_CHAR;
    }
    else if (letter == '.')
    {
        this->token = (TOKENS)PRINT_CHAR;
    }
    else if (letter == '[')
    {
        this->token = (TOKENS)LOOP_START;
    }
    else if (letter == ']')
    {
        this->token = (TOKENS)LOOP_END;
    }
}