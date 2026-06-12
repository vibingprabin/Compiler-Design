#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

const string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

bool isKeyword(const string& str) {
    for (const string& keyword : keywords) {
        if (str == keyword) {
            return true;
        }
    }
    return false;
}

bool isOperator(char ch) {
    string operators = "+-*/%=<>!&|";
    return operators.find(ch) != string::npos;
}

bool isDelimiter(char ch) {
    string delimiters = " \t\n\r,;(){}[]\"'";
    return delimiters.find(ch) != string::npos;
}

int main() {
    ifstream inputFile("File.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file 'File.txt'." << endl;
        return 1;
    }

    vector<string> storedKeywords;
    vector<string> storedIdentifiers;
    vector<string> storedNumbers;
    vector<char> storedOperators;
    vector<char> storedDelimiters;

    char ch;
    string buffer = "";

    cout << "--- Token Extraction Process ---" << endl;

    while (inputFile.get(ch)) {
        if (isOperator(ch)) {
            if (!buffer.empty()) {
                if (isKeyword(buffer)) {
                    storedKeywords.push_back(buffer);
                } else if (isdigit(buffer[0])) {
                    storedNumbers.push_back(buffer);
                } else {
                    storedIdentifiers.push_back(buffer);
                }
                buffer = "";
            }
            storedOperators.push_back(ch);
        }
        else if (isDelimiter(ch)) {
            if (!buffer.empty()) {
                if (isKeyword(buffer)) {
                    storedKeywords.push_back(buffer);
                } else if (isdigit(buffer[0])) {
                    storedNumbers.push_back(buffer);
                } else {
                    storedIdentifiers.push_back(buffer);
                }
                buffer = "";
            }
            if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
                storedDelimiters.push_back(ch);
            }
        }
        else {
            buffer += ch;
        }
    }

    inputFile.close();

    cout << "\n1. Keywords: ";
    for (const string& kw : storedKeywords) cout << kw << " ";
    
    cout << "\n2. Identifiers: ";
    for (const string& id : storedIdentifiers) cout << id << " ";
    
    cout << "\n3. Numbers: ";
    for (const string& num : storedNumbers) cout << num << " ";
    
    cout << "\n4. Operators: ";
    for (char op : storedOperators) cout << op << " ";
    
    cout << "\n5. Delimiters: ";
    for (char del : storedDelimiters) cout << del << " ";
    
    cout << "\n\nTokens successfully generated and stored in vectors!" << endl;

    return 0;
}
