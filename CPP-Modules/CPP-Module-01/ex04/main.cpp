#include <iostream>
#include "Sed.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <file> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    int rc = Sed::process(filename, s1, s2);
    if (rc != 0)
    {
        std::cerr << "replace: error (code " << rc << ")" << std::endl;
        return rc;
    }
    return 0;
}