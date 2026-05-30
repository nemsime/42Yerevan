#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed {
public:
    static int process(const std::string& filename, const std::string& s1, const std::string& s2);
};

#endif
