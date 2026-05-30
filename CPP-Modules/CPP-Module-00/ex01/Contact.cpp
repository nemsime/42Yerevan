#include "Contact.hpp"

void Contact::setFirstName(const std::string& name) {
    this->firstName = name;
}

void Contact::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& number) {
    this->phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string& secret) {
    this->darkestSecret = secret;
}

const std::string& Contact::getFirstName() const {
    return this->firstName;
}

const std::string& Contact::getLastName() const {
    return this->lastName;
}

const std::string& Contact::getNickname() const {
    return this->nickname;
}

const std::string& Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

const std::string& Contact::getDarkestSecret() const {
    return this->darkestSecret;
}       