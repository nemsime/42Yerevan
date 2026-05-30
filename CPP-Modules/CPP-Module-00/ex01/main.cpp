#include "PhoneBook.hpp"
#include <iostream>


int main() {

    PhoneBook pb;
    std::string command;

    while (true) {

        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD") {
            pb.addContact();
        } else if (command == "SEARCH") {
           pb.searchContact();
        } else if(command == "EXIT") {
            std::cout << "Exiting the program... Goodbye! :)" << '\n';
            break;
        } else if (!command.empty()) {
            std::cout << "Unknown command: " << command << std::endl;
        }
    }
}