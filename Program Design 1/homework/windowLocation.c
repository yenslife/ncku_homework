#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* protocol;
    char* host;
    char* pathname;
    char* search;
    char* hash;
    int port;
} Location;

Location* parse_url(char* url);

int main() {
    char url[500] = "";
    fgets(url, 500, stdin);  // Get url string
    Location* l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname,
           l->search, l->hash);
    return 0;
}

Location tmp = {.protocol = "",
                .host = "",
                .port = 0,
                .pathname = "",
                .search = "",
                .hash = ""};

Location* parse_url(char* url) {
    static char protocol[100] = "";
    static char host[1000] = "";
    static char pathname[10000] = "";
    static char search[10000] = "";
    static char hash[10000] = "";
    // int slashNum = 0;
    int i = 0;
    for (; i < 10000; i++) {
        protocol[i] = url[i];
        if (protocol[i] == ':') {
            protocol[i] = '\0';
            i += 3;
            break;
        }
    }
    tmp.protocol = protocol;
    for (int j = 0; i < 10000; i++, j++) {
        host[j] = url[i];
        if (host[j] == ':' || host[j] == '\0' || host[j] == '/') {
            if (host[j] == '\0') {
                tmp.host = host;
                host[j - 1] = '\0';
                // return &tmp;
            }
            host[j] = '\0';
            i += 1;
            break;
        }
    }
    // i + 1= index on :
    tmp.host = host;
    const char* port = ":";
    char* tmpPort = "";
    url = url + i - 1;
    int portMark = 0;
    int slashMark = 0;
    int pathnameMark = 0;
    int searchMark = 0;
    int hashMark = 0;
    i = 0;
    for (int j = 0; j < 1000; j++) {
        i++;
        if (url[j] == ':') {
            portMark = 1;
        } else if (url[j] == '/' && portMark != 0) {
            pathnameMark = 1;
            tmp.port = atoi(url + 1);
            url = url + i;
            break;
            // 以上是有 port 的處理方法
        } else if (url[j] == '/' && portMark == 0) {
            url = url + i;
            pathnameMark = 1;
            break;
        } else if (url[j] == '?' && portMark == 0) {
            url = url + i;
            searchMark = 1;
        } else if (url[j] == '#' && portMark == 0) {
            url = url + i;
            hashMark = 1;
        }
    }
    i = 0;
    // printf("%s\n", url);
    if (pathnameMark == 1) {
        for (int j = 0; j < 1000; j++) {
            i++;
            if (url[j] == '?' || url[j] == '#' || url[j + 1] == '\0') {
                break;
            }
            pathname[j] = url[j];
        }
        tmp.pathname = pathname;
        url = url + i - 1;
    }
    // printf("url == %s\n", url);
    i = 0;
    if (url[0] == '?') {
        url += 1;
        for (int j = 0; j < 10000; j++) {
            i++;
            if (url[j] == '#' || url[j + 1] == '\0')
                break;
            search[j] = url[j];
        }
        // printf("search = %s\n", search);
        tmp.search = search;
        url = url + i - 1;
        // printf("url is now = %s\n", url);
    } else if (url[0] == '#') {
        for (int j = 0; j < 10000; j++) {
            if (url[j] == '\0')
                break;
            hash[j] = url[j];
        }
        tmp.hash = hash;
    }
    i = 0;
    if (url[0] == '#') {
        url += 1;
        for (int j = 0; j < 10000; j++) {
            i++;
            if (url[j] == '\0')
                break;
            hash[j] = url[j];
        }
        memset(hash + i - 2, 0, 1000);
        tmp.hash = hash;
    }
    return &tmp;
}
// https://www.abc.com:80/user/12345/photo?from=20180101&to=20201231#favorite
// hash = /problems/RS_5xkB0PF-1

/*
ip://193.55.28.30

*/