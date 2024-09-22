#include <iostream>
#include <cctype>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    char lower = tolower(ch);
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

// Function to check if a word is valid
bool isValidWord(const string& word) {
    if (word.length() < 3) return false;

    bool hasVowel = false;
    bool hasConsonant = false;

    for (char ch : word) {
        if (!isalnum(ch)) {
            return false; // Word contains non-alphanumeric character
        }
        if (isVowel(ch)) {
            hasVowel = true;
        } else if (isalpha(ch)) {
            hasConsonant = true;
        }
    }

    return hasVowel && hasConsonant; // Valid if it has at least one vowel and one consonant
}

// Function to count valid words in the sentence
int countValidWords(const string& sentence) {
    string word = "";
    int validWordCount = 0;

    for (char ch : sentence) {
        if (isspace(ch)) {
            if (!word.empty() && isValidWord(word)) {
                validWordCount++;
            }
            word = "";  // Reset word for the next one
        } else {
            word += ch;  // Build the word
        }
    }

    // Check the last word after the loop (in case there's no space at the end)
    if (!word.empty() && isValidWord(word)) {
        validWordCount++;
    }

    return validWordCount;
}

int main() {
    // Example input
    string sentence = "This is a valid stateme$nt test";

    // Count valid words
    int result = countValidWords(sentence);

    // Output the result
    cout << "Number of valid words: " << result << endl;

    return 0;
}


// Problem1: Return number of valid word on string.
// A word is valid if it’s length at least 3 and contain alphanumeric character and at least one vowel and one consonant.

// Input: “This is a valid stateme$nt test”
// Output: 3