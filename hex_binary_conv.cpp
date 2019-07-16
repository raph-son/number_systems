/**
    An implementation of hexadecimal to binary conversion

    hex_binary_conv.cpp
    @author raph-son
*/

#include <iostream>
#include <string>
using namespace std;

/**
    Map a char to another base conversion

    @param char character to be mapped to another
    @return string a collection of four char representing new base
*/
string hex_to_bin_map(char hex);

// Program's entry point
int main(int c, char* argv[]) {
    if(c < 2) {
        cout << "Usage: Type hexadecimal number after program's name" << endl;
        return 1;
    }
    char* hex_value = argv[1];
    string hex_result;
    for(int i=0; i<strlen(hex_value); i++) {
        hex_result.append(hex_to_bin_map(hex_value[i]));
    }
    cout << hex_result  << endl;
    return 0;
}

string hex_to_bin_map(char hex) {
    // Map an hexadecimal character to four binary bits
    switch(hex) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A':
        case 'a': return "1010";
        case 'B':
        case 'b': return "1011";
        case 'C':
        case 'c': return "1100";
        case 'D':
        case 'd': return "1101";
        case 'E':
        case 'e': return "1110";
        case 'F':
        case 'f': return "1111";
        default: return "";
    }
}
