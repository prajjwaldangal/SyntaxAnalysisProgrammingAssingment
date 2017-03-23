//
//  main.c
//  syntax_analysis_prog_assign
//
//  Created by Prajjwal Dangal on 3/18/17.
//  Copyright © 2017 Prajjwal Dangal. All rights reserved.
//

/*
Make a single program in the C language by augmenting and integrating the example C code in Section 4.2
and 4.4.1 on the textbook. The program is supposed to read a text file line by line. For each line, it produces
the output similar to what's shown on Page 178 and 179. If a syntax error is found, it should print an error
message indicating where the error occurs in the line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int charClass;
char lexeme[100];
char nextChar;
char * line = NULL;
int lexLen;
int token;
int nextToken;
int line_ind;

void addChar();
void getChar();
void expr();
void term();
void factor();
int lookup(char ch);
int lex();
void error();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
#define TERM_CHAR 55

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

/* file path: 
    "/Users/prajjwaldangal/Documents/cs/spring17/structures of programming languages/syntax_analysis_prog_assign/syntax_analysis_prog_assign/input.txt"
*/

FILE *fp; /*, *fopen();*/

int main(int argc, const char * argv[]) {
    ssize_t read;
    size_t len = 0;
    printf("%s", argv[1]);
    if ((fp = fopen(argv[1], "r")) == NULL)
        printf("Error - cannot open input.txt\n");
    else {
        while ((read = getline(&line, &len, fp)) != -1) {
            // printf("")
            line_ind = 0;
            getChar();
           do {
               lex();
               expr();
           } while ( nextToken != EOF );
       }
       fclose(fp);
       if (line)
           free(line);
       exit(EXIT_SUCCESS);
//        printf("Hello world\n");
    }
    return 0;
}

/* sets nextChar and charClass */
void getChar() {
    if ((nextChar = line[line_ind]) != '\0') {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
        line_ind++;
    } else
        charClass = EOF;
}

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
            case '\n':
                addChar();
                nextToken = '\n';
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

/* tackle space */
void getNonBlank() {
    while (isspace(nextChar))
        getChar();
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

/*
    Parser for arithmetic exprsn:
    <expr>    -->  <term>   {(+ | -) <term>}
    <term>    -->  <factor> {(* | /) <factor>}
    <factor>  -->  id | int_constant | (<expr>)
*/

void expr() {
    printf("Enter <expr>\n");
    term();
    
    while (nextToken == ADD_OP || nextToken == SUB_OP) {
        lex ();
        term ();
    }
    printf("Exit <expr>\n");
    /* End of function expr */
}

void term() {
    printf("Enter <term>\n");
    factor();
    
    while (nextToken == MULT_OP || nextToken == DIV_OP) {
        lex();
        factor();
    }
    printf("Exit <term>\n");
}

void error() {
    printf("Error parsing %d\n", nextToken);
}

void factor() {
    printf("Enter <factor>\n");
    if (nextToken == IDENT || nextToken == INT_LIT)
        lex();
    else {
        if (nextToken == LEFT_PAREN) {
            lex();
            expr();
            if (nextToken == RIGHT_PAREN) {
                lex();
            } else
                error();
        }
        else
            error();
    }
}
