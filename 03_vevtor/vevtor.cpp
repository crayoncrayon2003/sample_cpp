#include <iostream>
#include <vector>
#include <string>

int main(void) {
    std::vector<int>myVectorInt;
    myVectorInt.push_back(0);
    myVectorInt.push_back(10);
    myVectorInt.push_back(20);

    for (auto iter = myVectorInt.begin(); iter != myVectorInt.end(); iter++) {
        std::cout << *iter << std::endl;;
    }


    std::vector<std::pair<std::string, std::string>> myVectorString;
    myVectorString.push_back({"a", "x"});
    myVectorString.push_back({"b", "y"});
    myVectorString.push_back({"c", "z"});

    for (auto iter = myVectorString.begin(); iter != myVectorString.end(); iter++) {
        std::cout << iter->first << ", " << iter->second << std::endl;
    }


    for (const auto& pair : myVectorString) {
        std::cout << pair.first << ", " << pair.second << std::endl;
    };

    return 0;
}