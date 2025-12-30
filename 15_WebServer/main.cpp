#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int rsock;
    struct sockaddr_in addr{};

    // socket 作成
    rsock = socket(AF_INET, SOCK_STREAM, 0);
    if (rsock < 0) {
        perror("socket");
        return 1;
    }

    // 再起動時の bind エラー防止
    int opt = 1;
    setsockopt(rsock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // アドレス設定
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    // bind
    if (bind(rsock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // listen
    listen(rsock, 10);
    std::cout << "Web server running on port 8080..." << std::endl;

    while (true) {
        struct sockaddr_in client{};
        socklen_t len = sizeof(client);

        int wsock = accept(rsock, (struct sockaddr *)&client, &len);
        if (wsock < 0) {
            perror("accept");
            continue;
        }

        // リクエストは今回は読まない（最小構成）
        const char body[] = "Hello from persistent C++ server\n";
        char response[256];

        snprintf(response, sizeof(response),
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %zu\r\n"
            "\r\n"
            "%s",
            strlen(body), body
        );

        write(wsock, response, strlen(response));
        close(wsock);
    }

    // 実際には到達しない
    close(rsock);
    return 0;
}
