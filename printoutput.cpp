//
//  printoutput.cpp
//  PE_93 (arithmetic expressions)
//
//  Created by Neil Marshall on 02/05/2016.
//  Copyright © 2016 Neil Marshall. All rights reserved.
//

#include "token.hpp"

void fnPrintResults(const int& a, const int& b, const int& c, const int& d) {
    ofstream OutputFile("OutputFile.txt");
    const int ASCII = 48;
    string temp_expression1;
    string temp_expression2;
    double temp_double;
    int temp_integer;
    char ints[4];
    ints[0] = a + ASCII;
    ints[1] = b + ASCII;
    ints[2] = c + ASCII;
    ints[3] = d + ASCII;
    char chars[4] = {'+', '-', '*', '/'};
    for (int iw = 0; iw < 4; ++iw) {
        for (int ix = 0; ix < 4; ++ix) {
            for (int iy = 0; iy < 4; ++iy) {
                for (int iz = 0; iz < 4; ++iz) {
                    for (int cw = 0; cw < 4; ++cw) {
                        for (int cx = 0; cx < 4; ++cx) {
                            for (int cy = 0; cy < 4; ++cy) {
                                if (iw != ix && iw != iy && iw != iz && ix != iy && ix != iz && iy != iz) {
                                    //Construct string of the form 'int oper int oper int oper int'
                                    temp_expression1 = ints[iw];
                                    temp_expression1 = temp_expression1 + chars[cw] + ints[ix] + chars[cx] + ints[iy] + chars[cy] + ints[iz];
                                    temp_double = calculate(temp_expression1);
                                    temp_integer = int(temp_double);
                                    if (temp_double - temp_integer == 0) {
                                        OutputFile << temp_expression1 << ": " << temp_integer;
                                    }
                                    //Construct string of the form '(int oper int oper int) oper int'
                                    temp_expression2 = '(' + temp_expression1.substr(0, 5) + ')' + temp_expression1.substr(5, 2);
                                    temp_double = calculate(temp_expression2);
                                    temp_integer = int(temp_double);
                                    if (temp_double - temp_integer == 0) {
                                        OutputFile << temp_expression1 << ": " << temp_integer;
                                    }
                                    //Construct string of the form '(int oper int) oper int oper int'
                                    temp_expression2 = '(' + temp_expression1.substr(0, 3) + ')' + temp_expression1.substr(3, 4);
                                    temp_double = calculate(temp_expression2);
                                    temp_integer = int(temp_double);
                                    if (temp_double - temp_integer == 0) {
                                        OutputFile << temp_expression1 << ": " << temp_integer;
                                    }
                                    //Construct string of the form '((int oper int) oper int) oper int'
                                    temp_expression2 = '(' + temp_expression2.substr(0, 7) + ')' + temp_expression2.substr(6, 2);
                                    temp_double = calculate(temp_expression2);
                                    temp_integer = int(temp_double);
                                    if (temp_double - temp_integer == 0) {
                                        OutputFile << temp_expression1 << ": " << temp_integer;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}