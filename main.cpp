// #pragma once
#include <iostream>
#include "parser.cpp"
#include <assert.h>
#include "lexer.cpp"
#define HEAP_SIZE 30000

// An attemp to write brainfuck compiler


int HEAP[HEAP_SIZE] = {0};
int heap_pointer = 0;


void printVec(std::vector<Token*> a){
    std::cout << "Running " << a.size() << std::endl;
    for(int i = 0; i < a.size(); i++){

        std::cout << a[i]->letter << std::endl;

    }

}


void incMemPtr(){

    assert (heap_pointer + 1 <= HEAP_SIZE);

    heap_pointer++;

}

void decMemPtr(){

    assert (heap_pointer - 1 >= 0);

    heap_pointer--;

}

void incVal(){
    HEAP[heap_pointer]++;
}

void decVal(){
    HEAP[heap_pointer]--;
}

void inputChar(){
    char a;
    std::cout << "Enter a char:" << std::endl;
    scanf("%c", &a);

    HEAP[heap_pointer] = a;

}

void printChar(){
    std::cout << ( (char)  HEAP[heap_pointer]); // << " Pointer " << heap_pointer << "-"<< std::endl;
}


int run(std::vector<Token*> tokens, int startIndex){

    int i;
    for( i = startIndex; i < tokens.size(); i++){

        if (tokens[i]->token == INC_MEM_PTR){
            incMemPtr();
        }

        else if (tokens[i]->token == DEC_MEM_PTR){
            decMemPtr();
        }
        else if (tokens[i]->token == INC_VAL){
            incVal();
        }
        else if (tokens[i]->token == DEC_VAL){
            decVal();
        }
        else if (tokens[i]->token == INPUT_CHAR){
            inputChar();
        }
        else if (tokens[i]->token == PRINT_CHAR){
            printChar();
        }
        else if (tokens[i]->token == LOOP_START){
            int x = i;
            while (HEAP[heap_pointer] > 0){
                x = run(tokens, i + 1);
            }
            
            i = x;
        }
        else if (tokens[i]->token == LOOP_END){
            // HEAP[heap_pointer] = 0;
            return i;
        }
        else{
            std::cout << "Undefined token " << tokens[i]->letter << std::endl;
        }

    }


    return i;
}


void printHeap(){

    std::cout << std::endl;
    for (int i = 0; i < 20; i++){
        std::cout << HEAP[i] << " | ";
    }

}

std::string code = "++++++++++[>+>+++++++>++++++++++>+++>+<<<<-]>>>-----.---.";



void increment(int &x){
    x = x + 1;
}

int main(){

    Lexer lexer(code);
    Parser parser;

    std::vector<Token*> tokens = lexer.run();


    if (parser.parse(tokens)){
        std::cout << "Bracket issue " << std::endl;
    }
    else {
        std::cout << "Bracket Check Pass " << std::endl;
    }

    run(tokens, 0);

    printHeap();
    return 0;
}