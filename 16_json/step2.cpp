#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    std::ifstream ifs("data.json");
    if (!ifs) {
        std::cerr << "file open error" << std::endl;
        return 1;
    }

    json j;
    ifs >> j;
    ifs.close();

    // インデントを維持して出力
    std::cout << j.dump(4) << std::endl;

    return 0;
}
