#include <cstddef>
#include <iostream>
#include <exception>
int main(int argc, char const *argv[])
{
    try
    {
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
