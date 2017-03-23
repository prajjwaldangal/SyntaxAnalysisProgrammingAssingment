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
int char_ind;

void addChar();
void expr();
void term();
void factor();

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
    if ((nextChar = ) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    } else
        charClass = EOF;
}

char * getCharHelper() {
    char c;
    if ((c = getc(fp)) == NULL) {
        return NULL;
    }
    int line_count = 1;
    while (c != '\n') {
        c = getc(fp);
        line_count ++;
    }
    char line[line_count+2];
    // char * line = malloc(sizeof(char) * line_count+1);
    rewind(fp);
    c = getc(fp);
    int i = 0;
    while (c != '\n') {
        line[i] = c;
        c = getc(fp);
        i ++;
    }
    line[line_count] = '\n';
    line[line_count+1] = line_count;
    return line;
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
            } // else
                //error();
                
        }
        // else
            //error();
            
    }
}

//void getChar2(char arr[]) {
//    if ((nextChar = ))
//}

int main(int argc, const char * argv[]) {
    ssize_t read;
    size_t len = 0;
    if ((fp = fopen("/Users/prajjwaldangal/Documents/cs/spring17/structures of programming languages/syntax_analysis_prog_assign/syntax_analysis_prog_assign/input.txt", "r")) == NULL)
        printf("Error - cannot open input.txt\n");
    else {
        while ((read = getline(&line, &len, fp)) != -1) {
            
        }
        
        fclose(fp);
        if (line)
            free(line);
        exit(EXIT_SUCCESS);
    // getchar();
    //        do {
    //            lex();
    //        } while (nextToken != EOF);
            printf("Hello world\n");
    }
    return 0;
}
