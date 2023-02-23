#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;

// Define character sets for password generation
const string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
const string digits = "0123456789";
const string specialCharacters = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
const string allCharacters = uppercaseLetters + lowercaseLetters + digits + specialCharacters;

// Function to generate a password of the specified length
string generatePassword(int length) {
    // Seed the random number generator with the current time
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    
    // Create a distribution for the character index
    uniform_int_distribution<int> distribution(0, allCharacters.length() - 1);

    // Initialize the password with one character from each character set
    string password = "";
    password += uppercaseLetters[distribution(generator)];
    password += lowercaseLetters[distribution(generator)];
    password += digits[distribution(generator)];
    password += specialCharacters[distribution(generator)];

    // Add random characters to the password
    for (int i = 4; i < length; i++) {
        password += allCharacters[distribution(generator)];
    }

    // Shuffle the password to make it more secure
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
