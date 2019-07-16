/**
    An implementation of decimal to binary conversion
 
    dec_binary_conv.cpp
    @author raph-son
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/**
    Convert a decimal number to decimal

    @param int the integer to convert to binary
    @return string a string containing the converted binaries
*/
string dec_to_bin(int num);

/**
    Decide which symbol between 0 and 1 to return based on the number
        given

    @param int an even or odd number
    @return char symbol 0 or 1 
*/
char is_even(int num);

/**
    Insert a symbol to the back of other symbols

    @params string, char a string containing symbols where new symbol will
        be added to. char the symbol to add to other symbol
    @return void
*/
void to_back(string& str, char chr);

// Program's entry point
int main(int c, char* argv[]) {
    if(c < 2) {
        cout << "Usage: Type decimal number after programs's name" << endl;
        return 1;
    }
    string conversion = dec_to_bin(atoi(argv[1]));
    cout <<  conversion  << endl;
    return 0;
}

string dec_to_bin(int num) {
    // Convert decimal number to binary
    int number = num;
    int quotient = number / 2;
    string bin;
    bin.append(sizeof(char), is_even(number));
    while(quotient != 0) {

        to_back(bin, is_even(quotient));
        number = quotient;
        quotient = number / 2;

    }
    // Algorithm completed
    return bin;
}

char is_even(int num) {
    // Return O if num is even
    // return 1 if not
    if(num % 2 == 0) {
        return '0';
    }
    return '1';
}

void to_back(string& str, char chr) {
    // Add a char to the back of string
    if(str.length() > 0) { 
        str.insert(0 ,1, chr);
    }
    else {
        str = chr;
    }
}
