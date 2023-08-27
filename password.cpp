#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

bool hasUpperCase(const std::string &password) {
    for (char c : password) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

bool hasLowerCase(const std::string &password) {
    for (char c : password) {
        if (std::islower(c)) {
            return true;
        }
    }
    return false;
}

bool hasNumber(const std::string &password) {
    for (char c : password) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool hasSpecialChar(const std::string &password) {
    for (char c : password) {
        if (!std::isalnum(c)) {
            return true;
        }
    }
    return false;
}

std::string checkPasswordStrength(const std::string &password) {
    if (password.length() >= 12 && hasUpperCase(password) && hasLowerCase(password) && hasNumber(password) && hasSpecialChar(password)) {
        return "Strong";
    }
    else if (password.length() > 8 && password.length() < 12 && hasUpperCase(password) && hasLowerCase(password) && hasNumber(password)) {
        return "Weak";
    }
    else {
        return "Invalid";
    }
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::cin >> password;

    std::string result = checkPasswordStrength(password);
    std::cout << "Password strength: " << result << std::endl;

    return 0;
}