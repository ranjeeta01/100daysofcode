#include <iostream>
#include <string>

int main() {
    int rows;
    
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cin.ignore(); // Consume newline character in the input buffer

    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin, name);

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i == rows && j == 1) {
                std::cout << name;
            } else {
                std::cout << "* ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
