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
    int portInt = 0;
    char portChar[1000] = "";
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
    tmp.host = host;

    for (int j = 0; i < 10000; j++, i++) {
        portChar[j] = url[i];
        if (portChar[j] == '/' || portChar[j] == '\0' || portChar[j] == '#' ||
            portChar[j] == '?') {
            if (portChar[j] == '#')
                i--;
            if (portChar[j] == '\0') {
                portInt = atoi(portChar);
                tmp.port = portInt;
                // return &tmp;
            }
            portChar[j] = '\0';
            i++;
            break;
        }
    }
    portInt = atoi(portChar);
    tmp.port = portInt;
    for (int j = 0; i < 10000; i++, j++) {
        pathname[j] = url[i];
        if (pathname[j] == '?' || pathname[j] == '\0' || pathname[j] == '#') {
            if (pathname[j] == '#')
                i--;
            if (pathname[j] == '\0') {
                pathname[j - 1] = '\0';
                tmp.pathname = pathname;
                // return &tmp;
            }
            pathname[j] = '\0';
            i++;
            break;
        }
    }
    tmp.pathname = pathname;
    for (int j = 0; i < 10000; j++, i++) {
        search[j] = url[i];
        if (search[j] == '#' || search[j] == '\0') {
            if (search[j] == '\0') {
                search[j - 1] = '\0';
                tmp.search = search;
                // return &tmp;
            }
            search[j] = '\0';
            i++;
            break;
        }
    }
    tmp.search = search;
    for (int j = 0; i < 10000; j++, i++) {
        hash[j] = url[i];
        if (hash[j] == '\0') {
            hash[j - 1] = '\0';
            tmp.hash = hash;
            break;
        }
    }
    tmp.hash = hash;
    return &tmp;
}