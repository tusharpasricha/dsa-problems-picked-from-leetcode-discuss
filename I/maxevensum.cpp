#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxsum(vector<int> arr) {
    int sum = 0;
    int smallestOdd = INT_MAX;  // To track the smallest odd number

    // Calculate the sum of all positive elements and track the smallest odd number
    for (int num : arr) {
        if (num > 0) {
            sum += num;
        }
        // Track the smallest odd number (positive or negative)
        if (num % 2 != 0) {
            smallestOdd = min(smallestOdd, abs(num));
        }
    }

    // If the sum is even, return it
    if (sum % 2 == 0) {
        return sum;
    }
    
    // If the sum is odd, subtract the smallest odd number to make it even
    return sum - smallestOdd;
}

int main() {
    vector<int> arr = {2, 3, 6, -5, 10, 1, 1};
    cout << maxsum(arr) << endl;  // Expected output: 22
    return 0;
}
