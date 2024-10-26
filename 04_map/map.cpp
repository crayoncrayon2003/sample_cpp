#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main(void) {
    std::map<int, int> myMapIntInt{
        {1 , 10},
        {2 , 20},
        {3 , 30}
    };

    for (auto iter = myMapIntInt.begin(); iter != myMapIntInt.end(); iter++) {
        std::cout << iter->first << " -> " << iter->second << std::endl;
    };

    std::map<int, std::vector<std::string>> myMapIntVec{
        {1 , {"a","xxxx"}},
        {2 , {"b","yyyy"}},
        {3 , {"c","zzzz"}},
    };
    for (const auto& pair : myMapIntVec) {
        std::cout << "Key: " << pair.first << " -> Values: ";
        for (const auto& str : pair.second) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    };

    return 0;
}