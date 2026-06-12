#include <iostream>
#include <string>

using namespace std;

bool checkValid(const string& str) {
    int len = str.length();

    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b' && str[i] != 'e') {
            return false;
        }
    }

    if (len == 1 && str[0] == 'e') {
        return false;
    }

    if (len < 2) {
        return false;
    }

    char start = str[0];
    char end = str[len - 1];

    if ((start == 'a' && end == 'b') || (start == 'b' && end == 'a')) {
        return true;
    }

    return false;
}

int main() {
    string str;

    cout << "Enter string: ";
    cin >> str;

    if (checkValid(str)) {
        cout << "VALID\n";
    } else {
        cout << "INVALID\n";
    }

    return 0;
}
