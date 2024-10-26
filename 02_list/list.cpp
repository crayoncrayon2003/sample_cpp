#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<int> mylistInt;
    mylistInt.push_back(0);
    mylistInt.push_back(10);
    mylistInt.push_back(20);

    for (auto iter = mylistInt.begin(); iter != mylistInt.end(); iter++) {
        std::cout << *iter << std::endl;;
    }

    std::list<std::string> mylistString;
    mylistString.push_back("Hello");
    mylistString.push_back("World!");

    for (auto iter = mylistString.begin(); iter != mylistString.end(); iter++) {
        std::cout << *iter << std::endl;;
    }

    for (const auto& iter : mylistString) {
        std::cout << iter  << std::endl;
    };

    return 0;
}