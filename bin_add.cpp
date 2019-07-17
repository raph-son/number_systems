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

/*
    Prefix the operand with less bit with 0's

    @param string - operands
    @return void
*/
void zero_prefix(string& left_operand, string& right_operand);

// Program's entry point
int main(int c, char* argv[]) {
    if(c < 3) {
        cout << "Usage: enter two binary to add" << endl;
        return 1;
    }

    bool carry_switch;
    string left_operand = argv[1];
    string right_operand = argv[2];

    // Add as much zero beind the operand with less bit where needed
    zero_prefix(left_operand, right_operand);

    char add_begins_left = left_operand[left_operand.length() - 1];
    char add_begins_right = right_operand[right_operand.length() - 1];

    string result;
    // Since both side have equal length now, we can use either side 
    for(int i = add_begins_left; i != 0; i--) {
        result.insert(0, 1, do_add(carry_switch, left_operand[i - 1], right_operand[i - 1]));
    }
    // If last operation has a carry, just add one the the beginning
    if(carry_switch) result.insert(0, 1, '1');
    cout << result << endl;

    return 0;
}

// Prefix the operand with less characters with 0 to equal other length
void zero_prefix(string& left_operand, string& right_operand) {
    if(left_operand.length() > right_operand.length()) {
        int zero_length_to_prefix = left_operand.length() \
                                    - right_operand.length();
        for(int i = zero_length_to_prefix; i != 0; i--) {
            right_operand.insert(0, 1, '0');
        }
    }

    if(left_operand.length() < right_operand.length()) {
        int zero_length_to_prefix = right_operand.length() \
                                    - left_operand.length();
        for(int i = zero_length_to_prefix; i != 0; i--) {
            left_operand.insert(0, 1, '0');
        }
    }
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
