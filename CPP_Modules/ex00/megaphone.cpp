#include <iostream>
#include <cctype>

int main(int argc, char **argv){
    if(argc == 1)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        argv++;
        while(*argv)
        {
            char *str = *argv;
            while(*str)
            {
                std::cout << (char)std::toupper(*str);
                str++;
            }
            if(*(argv + 1))
                std::cout << " ";
            argv++;
        }
    }
    std::cout << std::endl;
    return 0;
}