#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // JSONデータ構造を生成
    json j;
    j["id"] = 100;
    j["name"] = "sample";
    j["active"] = true;

    j["items"] = json::array();
    j["items"].push_back({{"key", "A"}, {"value", 10}});
    j["items"].push_back({{"key", "B"}, {"value", 20}});

    // ファイルに保存（インデント4）
    std::ofstream ofs("data.json");
    if (!ofs) {
        std::cerr << "file open error" << std::endl;
        return 1;
    }

    ofs << j.dump(4);
    ofs.close();

    std::cout << "data.json written" << std::endl;
    return 0;
}
