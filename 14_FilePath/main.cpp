#include <iostream>
#include <filesystem>
#include <unistd.h>     // readlink
#include <limits.h>     // PATH_MAX

namespace fs = std::filesystem;

/* 実行ファイルのフルパスを取得 */
fs::path getExecutableDir()
{
    char buf[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (len == -1) {
        throw std::runtime_error("readlink failed");
    }
    buf[len] = '\0';
    return fs::path(buf).parent_path();
}

int main()
{
    try {
        // 実行ファイルが存在するディレクトリ
        fs::path exeDir = getExecutableDir();

        std::cout << "Executable directory: "
                  << exeDir << std::endl;

        // 実行ファイルのあるディレクトリを走査
        for (const auto& entry : fs::directory_iterator(exeDir)) {
            std::cout
                << (entry.is_directory() ? "[DIR ] " : "[FILE] ")
                << entry.path().filename().string()
                << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
