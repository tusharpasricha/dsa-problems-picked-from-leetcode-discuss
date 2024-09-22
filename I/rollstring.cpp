#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to roll characters backward or forward
void rollString(string &s, int start, int end, char direction) {
    for (int i = start; i <= end; ++i) {
        if (direction == 'L') {
            // Roll backward
            if (s[i] == 'a') {
                s[i] = 'z';
            } else {
                s[i]--;
            }
        } else if (direction == 'R') {
            // Roll forward
            if (s[i] == 'z') {
                s[i] = 'a';
            } else {
                s[i]++;
            }
        }
    }
}

// Function to parse and perform operations
void performOperations(string &str, const vector<string> &operations) {
    for (const string &op : operations) {
        // Extracting start, end, and direction manually
        int start = op[0] - '0'; // Convert character to integer
        int end = op[2] - '0';   // Convert character to integer
        char direction = op[4];  // Get the direction character

        // Perform the rolling operation
        rollString(str, start, end, direction);
    }
}

int main() {
    string str = "abc"; // Input string
    vector<string> operations = {"0 0 L", "2 2 L", "0 2 R"}; // Operations

    // Perform the operations on the string
    performOperations(str, operations);

    // Output the final result
    cout << str << endl; // Output: 'acc'

    return 0;
}


// Problem2: On a given string perform following operations. If operation is roll backward(L) then shift all character to one backward over given substring(‘b’ -> ‘a’, ‘a’ -> ‘z’). If operation is roll forward(L) then shift all character to one forward over given substring(‘b’ -> ‘c’, ‘z’ -> ‘a’).

// Input: ‘abc’, [‘0 0 L’, ‘2 2 L’, ’0 2 R’]
// Output : ‘acc’
// Explain :
// After ‘0 0 L’ ‘abc’ -> ‘zbc’
// After ‘2 2 L’ ‘zbc’ -> ‘zbb’
// After ‘0 2 R’ ‘zbb’ -> ‘acc’