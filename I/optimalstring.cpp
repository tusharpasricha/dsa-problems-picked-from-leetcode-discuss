#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string maxOptimalString(int countA, int countB, int maxA, int maxB) {
    string result;
    
    // Continue until either 'A's or 'B's are exhausted
    while (countA > 0 || countB > 0) {
        if (countA > countB) {
            // Add 'A's first
            int addA = min(maxA, countA);
            result.append(addA, 'A');
            countA -= addA;

            // Add 'B's after 'A's if any left
            if (countB > 0) {
                int addB = min(maxB, countB);
                result.append(addB, 'B');
                countB -= addB;
            }
        } else {
            // Add 'B's first
            int addB = min(maxB, countB);
            result.append(addB, 'B');
            countB -= addB;

            // Add 'A's after 'B's if any left
            if (countA > 0) {
                int addA = min(maxA, countA);
                result.append(addA, 'A');
                countA -= addA;
            }
        }
    }
    
    return result;
}

int main() {
    // Example input
    int countA = 2;
    int countB = 4;
    int maxA = 2;
    int maxB = 1;

    // Get the optimal string
    string optimalString = maxOptimalString(countA, countB, maxA, maxB);

    // Print the result
    cout << "Optimal String: " << optimalString << endl;
    cout << "Length of Optimal String: " << optimalString.length() << endl;

    return 0;
}
