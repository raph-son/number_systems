/**
    An implementation of binary addition
 
    bin_add.cpp
    @author raph-son
*/

#include <iostream>
#include <string>
using namespace std;

/*
    Perform adding binary characters

    @params bool - set if the current addition has remainder
        char - binary characters to be added together
    @return char - the result of the operation
*/
char do_add(bool& carry, char left, char right);

// Program's entry point
int main(int c, char* argv[]) {
    if(c < 3) {
        cout << "Usage: enter two binary to add" << endl;
        return 1;
    }

    bool carry_switch;
    char add_begins_left = argv[1][strlen(argv[1]) - 1];
    char add_begins_right = argv[2][strlen(argv[2]) - 1];

    string result;

    for(int i = strlen(argv[1]); i != 0; i--) {
        result.insert(0, 1, do_add(carry_switch, argv[1][i - 1], argv[2][i - 1]));
    }
    // If last operation has a carry, just add one the the beginning
    if(carry_switch) result.insert(0, 1, '1');
    cout << result << endl;

    return 0;
}



// Determin if a binary addition involve carring or not
char do_add(bool& carry, char left, char right) {
    if(carry == false) { 

        if(left == '0' && right == '0') {
            carry = false;
            return '0';
        }
        if( (left == '0' && right == '1') || (left == '1' && right == '0') ) {
            carry = false;
            return '1';
        }
        if(left == '1' && right == '1') {
            carry = true;
            return '0';
        }
    }
    
    if(left == '0' && right == '0') {
        carry = false;
        return '1';
    }
    if( (left == '0' && right == '1') || (left == '1' && right == '0') ) {
        carry = true;
        return '0';
    }
    if(left == '1' && right == '1') {
        carry = true;
        return '1';
    }

    return ' ';
}
