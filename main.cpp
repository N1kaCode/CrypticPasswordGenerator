#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

string generatePassword(int length) {
    const string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string specialCharacters = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    const string allCharacters = uppercaseLetters + lowercaseLetters + digits + specialCharacters;
    
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, allCharacters.length() - 1);

    string password = "";
    password += uppercaseLetters[distribution(generator)];
    password += lowercaseLetters[distribution(generator)];
    password += digits[distribution(generator)];
    password += specialCharacters[distribution(generator)];

    for (int i = 4; i < length; i++) {
        password += allCharacters[distribution(generator)];
    }

    shuffle(password.begin(), password.end(), generator);
    return password;
}

int main() {
    int length;
    cout << "Enter password length (must be at least 8 characters long): ";
    cin >> length;

    if (length < 8) {
        cout << "Password length must be at least 8 characters long." << endl;
        return 1;
    }

    string password = generatePassword(length);
    cout << "Generated password: " << password << endl;
    return 0;
}
