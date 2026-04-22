#include "Contact.hpp"

static std::string getInput(const std::string &prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty())
            return input;
        std::cout << "Field cannot be empty!\n";
    }
}

void Contact::setContact() {
    first_name = getInput("First name: ");
    last_name = getInput("Last name: ");
    nickname = getInput("Nickname: ");
    phone_number = getInput("Phone number: ");
    darkest_secret = getInput("Darkest secret: ");
}

static void format(std::string str) {
    if (str.length() > 10) {
        str = str.substr(0, 9);
        str += ".";
    }
    std::cout << std::setw(10) << str;
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|";
    format(first_name);
    std::cout << "|";
    format(last_name);
    std::cout << "|";
    format(nickname);
    std::cout << std::endl;
}

void Contact::displayFull() const {
    std::cout << first_name << std::endl;
    std::cout << last_name << std::endl;
    std::cout << nickname << std::endl;
    std::cout << phone_number << std::endl;
    std::cout << darkest_secret << std::endl;
}