//
//  token.hpp
//  PE_93 (arithmetic expressions)
//
//  Created by Neil Marshall on 02/05/2016.
//  Copyright © 2016 Neil Marshall. All rights reserved.
//

#ifndef token_hpp
#define token_hpp

#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

#endif /* token_hpp */

const char number = '8';

class Token {
    public:
        Token (char);
        Token (char, double);
        char kind;
        int value;
        Token read_next_token(string&, int&);
};

double expression(string&, int&);
double term(string&, int&);
double primary(string&, int&);
double calculate(string&);

int fnSequentialIntegers(const int&, const int&, const int&, const int&);
void fnPrintResults(const int&, const int&, const int&, const int&);