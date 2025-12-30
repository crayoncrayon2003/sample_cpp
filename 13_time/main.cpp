#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

/// YYYYMMDDhhmmss → std::tm
std::tm parseTime(const std::string& s)
{
    std::tm tm{};
    std::istringstream iss(s);
    iss >> std::get_time(&tm, "%Y%m%d%H%M%S");
    tm.tm_isdst = -1;  // 夏時間自動判定
    return tm;
}

/// 現在時刻 → YYYYMMDDhhmmss
std::string nowTimeString()
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d%H%M%S");
    return oss.str();
}

int main()
{
    // ① 現在時刻を取得
    std::string now = nowTimeString();

    // ② 任意の時刻文字列
    std::string time1 = "20200320104100";
    std::string time2 = "20200320094100";

    // ③ 文字列 → tm
    std::tm tm1 = parseTime(time1);
    std::tm tm2 = parseTime(time2);

    // ④ tm → time_t
    std::time_t t1 = std::mktime(&tm1);
    std::time_t t2 = std::mktime(&tm2);

    // ⑤ 時刻差（秒）
    double diff_sec = std::difftime(t1, t2);

    // 出力
    std::cout << "now      : " << now << "\n";
    std::cout << "time1    : " << time1 << "\n";
    std::cout << "time2    : " << time2 << "\n";
    std::cout << "diff(sec): " << diff_sec << std::endl;

    return 0;
}
