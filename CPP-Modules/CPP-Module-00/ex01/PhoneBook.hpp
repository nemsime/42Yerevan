#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook {
    private:
        static const int MAX_CONTACTS = 8;
        Contact contacts[MAX_CONTACTS];
        int index;
        int size;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};

#endif