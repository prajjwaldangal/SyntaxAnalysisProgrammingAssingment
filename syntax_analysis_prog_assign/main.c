//
//  main.c
//  syntax_analysis_prog_assign
//
//  Created by Prajjwal Dangal on 3/18/17.
//  Copyright © 2017 Prajjwal Dangal. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int nextToken;

void addChar();
void getChar();
void getNonBlank();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

void getChar() {
    if (()
}

void getNonBlank() {
    while (isspace(nextChar))
        getchar();
}

int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        case LETTER:
            addChar();
            getChar();
            while (
    }
}

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
