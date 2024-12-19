#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string str) 
    string filtered = "";
    for (char c : str) {
        if (isalnum(c)) { 
            filtered += tolower(c);
        }
    }

    int n = filtered.length();
    for (int i = 0; i < n / 2; i++) {
        if (filtered[i] != filtered[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The string is a palindrome!" << endl;
    } else {
        cout << "The string is not a palindrome!" << endl;
    }

    return 0;
}
