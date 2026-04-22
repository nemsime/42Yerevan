#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
    count = 0;
}

void PhoneBook::addContact() {
    contacts[index].setContact();

    index = (index + 1) % 8;
    if (count < 8)
        count++;
}

void PhoneBook::searchContact() const {
    if (count == 0) {
        std::cout << "PhoneBook is empty\n";
        return;
    }

    for (int i = 0; i < count; i++)
        contacts[i].displayShort(i);

    std::cout << "Enter index: ";

    int i;
    std::cin >> i;
    std::cin.ignore();

    if (i < 0 || i >= count) {
        std::cout << "Invalid index\n";
        return;
    }

    contacts[i].displayFull();
}