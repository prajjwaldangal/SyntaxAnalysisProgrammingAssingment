//
//  main.c
//  syntax_analysis_prog_assign
//
//  Created by Prajjwal Dangal on 3/18/17.
//  Copyright © 2017 Prajjwal Dangal. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;

void addChar();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

FILE *fp; /*, *fopen();*/

/*  */
int lookup(char ch) {
    switch (ch) {
            case '(':
                addChar();
                nextToken = LEFT_PAREN;
                break;
            case ')':
                addChar();
                nextToken = RIGHT_PAREN;
                break;
            case '+':
                addChar();
                nextToken = ADD_OP;
                break;
            case '-':
                addChar();
                nextToken = SUB_OP;
                break;
            case '*':
                addChar();
                nextToken = MULT_OP;
                break;
            case '/':
                addChar();
                nextToken = DIV_OP;
                break;
            default:
                addChar();
                nextToken = EOF;
                break;
    }
    return nextToken;
}

/* addChar - a function to add nextChar to lexeme */
void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("Error - lexeme is too long\n");
    }
}

/* sets nextChar and charClass */
void getChar() {
    if ((nextChar = getc(fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    } else
        charClass = EOF;
}

/* tackle space */
void getNonBlank() {
    while (isspace(nextChar))
        getchar();
}

/* lex - a simple lexical analyzer for arithemetic expressions */
int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;
        
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;
        
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    }
    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if ((fp = fopen("/Users/prajjwaldangal/Documents/cs/spring17/structures of programming languages/syntax_analysis_prog_assign/syntax_analysis_prog_assign/input.txt", "r")) == NULL)
        printf("Error - cannot open input.txt\n");
    else {
        getchar();
        printf("Hello world\n");
    }
    return 0;
}
