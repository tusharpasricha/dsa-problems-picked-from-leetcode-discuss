#include <iostream>
#include <string>

using namespace std;

string encryptString(const string &input) {
    string result;
    int n = input.length();
    int i = 0;

    while (i < n) {
        char currentChar = input[i];
        int count = 1;

        // Count consecutive characters
        while (i + 1 < n && input[i + 1] == currentChar) {
            count++;
            i++;
        }

        // Handle the encryption rules
        if (count > 1) {
            result += currentChar; // Always add the character once
            result += to_string(count); // Add the count if it's 4 or more
        } else {
            result += string(count, currentChar); // Append the characters as they are
        }

        i++; // Move to the next character
    }

    return result;
}

int main() {
    string input;
    cout << "Enter the string to encrypt: ";
    getline(cin, input); // Read the input string

    string encrypted = encryptString(input);
    cout << "Encrypted string: " << encrypted << endl;

    return 0;
}
