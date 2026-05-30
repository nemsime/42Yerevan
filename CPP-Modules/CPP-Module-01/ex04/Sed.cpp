#include "Sed.hpp"
#include <fstream>
#include <iterator>

int Sed::process(const std::string& filename, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return 1;

    std::ifstream infile(filename.c_str());
    if (!infile)
        return 2;

    std::string content;
    content.assign(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
    infile.close();

    std::string outputFilename = filename + ".replace";
    std::ofstream outfile(outputFilename.c_str());
    if (!outfile)
        return 3;

    std::string result;
    std::size_t pos = 0;
    std::size_t found = content.find(s1, pos);

    while (found != std::string::npos)
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
        found = content.find(s1, pos);
    }
    result.append(content, pos, content.length() - pos);

    outfile << result;
    outfile.close();
    return 0;
}
