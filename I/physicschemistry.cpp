#include <iostream>
#include <string>
using namespace std;

// Function to check if substr can be placed at a given index in word
bool canPlace(const string& word, const string& substr, int index) {
    for (int i = 0; i < substr.length(); ++i) {
        if (word[index + i] != '?' && word[index + i] != substr[i]) {
            return false; // Conflict found, cannot place substr here
        }
    }
    return true;
}

// Function to replace '?' with the substr and then fill remaining '?' with 'a'
string replaceAndFill(string word, const string& substr, int index) {
    // Replace '?' with corresponding characters from substr
    for (int i = 0; i < substr.length(); ++i) {
        word[index + i] = substr[i];
    }
    
    // Replace all remaining '?' with 'a'
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == '?') {
            word[i] = 'a';
        }
    }
    
    return word;
}

string findSmallestLexicographicalString(string word, const string& substr) {
    int wordLen = word.length();
    int subLen = substr.length();
    
    // Try placing substr at every valid position in word
    for (int i = 0; i <= wordLen - subLen; ++i) {
        if (canPlace(word, substr, i)) {
            return replaceAndFill(word, substr, i);
        }
    }
    
    // If no valid placement is found, return "-1"
    return "-1";
}

int main() {
    string word1 = "??aba???ac";
    string substr1 = "abab";
    cout << "Output: " << findSmallestLexicographicalString(word1, substr1) << endl; // Expected: "aaababaaac"

    string word2 = "??ac???ac?";
    string substr2 = "acb";
    cout << "Output: " << findSmallestLexicographicalString(word2, substr2) << endl; // Expected: "aaacaaaacb"

    return 0;
}
