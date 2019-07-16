
/**
    An implementation of octal to binary conversion

    oct_binary_conv.cpp
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
string oct_to_bin_map(char oct);

// Program's entry point
int main(int c, char* argv[]) {
    if(c < 2) {
        cout << "Usage: Type octal number after program's name" << endl;
        return 1;
    }
    char* oct_value = argv[1];
    string oct_result;
    for(int i=0; i<strlen(oct_value); i++) {
        oct_result.append(oct_to_bin_map(oct_value[i]));
    }
    cout << oct_result  << endl;
    return 0;
}

string oct_to_bin_map(char oct) {
    // Map an octal character to four binary bits
    switch(oct) {
        case '0': return "000";
        case '1': return "001";
        case '2': return "010";
        case '3': return "011";
        case '4': return "100";
        case '5': return "101";
        case '6': return "110";
        case '7': return "111";
        default: return "";
    }
}
