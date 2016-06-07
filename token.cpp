//
//  token.cpp
//  PE_93 (arithmetic expressions)
//
//  Created by Neil Marshall on 02/05/2016.
//  Copyright © 2016 Neil Marshall. All rights reserved.
//

#include "token.hpp"

double calculate(string& input_string) {
    int location = 0;
    return expression(input_string, location);
}

Token::Token (char ch) {
    kind = ch;
}

Token::Token (char ch, double n) {
    kind = ch;
    value = n;
}

Token read_next_token(string& S, int& location) {
    char ch;
    ch = S[location];
    switch (ch) {
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            int val = ch - '0';
            return Token(number, val);
            break;
        }
        default:
            return Token(ch);
    }
}
    
double expression(string& S, int& location) {
    double left = term(S, location);
    while (true) {
        Token t = read_next_token(S, location);
        switch(t.kind) {
            case '+':
                left += term(S, ++location);
                break;
            case '-':
                left -= term(S, ++location);
                break;
            case ')':
                ++location;
            default:
                return left;
        }
    }
}

double term(string& S, int& location) {
    double left = primary(S, location);
    while (true) {
        Token t = read_next_token(S, location);
        switch(t.kind) {
            case '*':
                left *= primary(S, ++location);
                break;
            case '/':
                left /= primary(S, ++location);
                break;
            default:
                return left;
        }
    }
}

double primary(string& S, int& location) {
    if (location >= S.size()) return 0;
    Token t = read_next_token(S, location);
    ++location;
    switch(t.kind) {
    case '(':
        {
            double d = expression(S, location);
            return d;
            break;
        }
    case number:
        return t.value;
        break;
    default:
        return t.value;
    }
}