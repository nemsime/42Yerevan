#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() {
    index = 0;
    size = 0;
}

bool isOnlySpaces(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]))
            return false;
    }
    return true;
}

bool isValidPhone(const std::string& s)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

std::string getInput(const std::string& prompt)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;

        if (!std::getline(std::cin, input))
            exit (0); 

        if (!input.empty() && !isOnlySpaces(input))
            return input;
    }
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string phone;

    newContact.setFirstName(getInput("Enter contact first name: "));
    newContact.setLastName(getInput("Enter contact last name: "));
    newContact.setNickname(getInput("Enter contact nickname: "));
    while (true)
    {
        phone = getInput("Enter contact phone number: ");
        if (isValidPhone(phone))
            break;
        std::cout << "Invalid phone number (digits only)\n";
    }
    newContact.setPhoneNumber(phone);
    newContact.setDarkestSecret(getInput("Enter contact darkest secret: "));

    contacts[index] = newContact;
    
    index = (index + 1) % 8;
    if (size < 8)
        size++;
}

std::string formatColumn(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContact()
{
    if (size == 0)
    {
        std::cout << "PhoneBook is empty\n";
        return;
    }

    std::cout << std::right;

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatColumn(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatColumn(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatColumn(contacts[i].getNickname())
                  << std::endl;
    }

    std::string input;
    std::cout << "Enter index: ";

    if (!std::getline(std::cin, input))
        return;

    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid index\n";
        return;
    }

    int idx = input[0] - '0';

    if (idx >= size)
    {
        std::cout << "Index out of range\n";
        return;
    }

    std::cout << "First name: " << contacts[idx].getFirstName() << "\n";
    std::cout << "Last name: " << contacts[idx].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[idx].getNickname() << "\n";
    std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << "\n";
}