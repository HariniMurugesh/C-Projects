/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <map>
#include <string>

class Dictionary {
private:
    std::map<std::string, std::string> germanToEnglish;
    std::map<std::string, std::string> englishToGerman;

public:
    void addWord(const std::string& german, const std::string& english) {
        germanToEnglish[german] = english;
        englishToGerman[english] = german;
    }

    std::string translateToEnglish(const std::string& german) {
        if (germanToEnglish.find(german) != germanToEnglish.end()) {
            return germanToEnglish[german];
        } else {
            return "";
        }
    }

    std::string translateToGerman(const std::string& english) {
        if (englishToGerman.find(english) != englishToGerman.end()) {
            return englishToGerman[english];
        } else {
            return "";
        }
    }

    void displayAll() {
        std::cout << "German to English Dictionary:\n";
        for (const auto& entry : germanToEnglish) {
            std::cout << entry.first << " -> " << entry.second << "\n";
        }

        std::cout << "\nEnglish to German Dictionary:\n";
        for (const auto& entry : englishToGerman) {
            std::cout << entry.first << " -> " << entry.second << "\n";
        }
    }
};

int main() {
    Dictionary dict;

    dict.addWord("Hallo", "Hello");
    dict.addWord("Tschüss", "Goodbye");
    dict.addWord("Danke", "Thank you");
    dict.addWord("Bitte", "Please");
    dict.addWord("Katze", "Cat");
    dict.addWord("Hund", "Dog");

    std::string input;
    int choice;

    while (true) {
        std::cout << "\nDictionary Menu:\n";
        std::cout << "1. Translate German to English\n";
        std::cout << "2. Translate English to German\n";
        std::cout << "3. Display all entries\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a German word: ";
                std::cin >> input;
                {
                    std::string translation = dict.translateToEnglish(input);
                    if (translation.empty()) {
                        std::cout << "Word not found in the dictionary. Please enter the English translation: ";
                        std::string english;
                        std::cin >> english;
                        dict.addWord(input, english);
                        std::cout << "Word added to the dictionary.\n";
                    } else {
                        std::cout << "English translation: " << translation << "\n";
                    }
                }
                break;
            case 2:
                std::cout << "Enter an English word: ";
                std::cin >> input;
                {
                    std::string translation = dict.translateToGerman(input);
                    if (translation.empty()) {
                        std::cout << "Word not found in the dictionary. Please enter the German translation: ";
                        std::string german;
                        std::cin >> german;
                        dict.addWord(german, input);
                        std::cout << "Word added to the dictionary.\n";
                    } else {
                        std::cout << "German translation: " << translation << "\n";
                    }
                }
                break;
            case 3:
                dict.displayAll();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
