#include <iostream>

using namespace std;

char encryptDecryptCharacter(char ch, int key, bool isEncrypting) {
    if (isupper(ch)) {
        int newIndex = ch + (isEncrypting ? key : -key);
        if (newIndex > 'Z') {
            newIndex -= 26;
        } else if (newIndex < 'A') {
            newIndex += 26;
        }
        return (char)newIndex;
    } else {
        return ch;
    }
}

string encryptDecryptString(string str, int key, bool isEncrypting) {
    string result;
    for (char ch : str) {
        result += encryptDecryptCharacter(ch, key, isEncrypting);
    }
    return result;
}

int main() {
    int key;
    string str;
    char flag;

    cout << "Enter the key (1-5): ";
    cin >> key;

    cout << "Enter the text (capital letters only): ";
    cin >> str;

    cout << "Encrypt (encrypt) or decrypt (decrypt): ";
    cin >> flag;

    string result = encryptDecryptString(str, key, flag == 'e');
    cout << "Result: " << result << endl;

    return 0;
}

