#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>

const int SIZE = 500009;

struct Node {
    long long val;
    struct Node* next;

    Node() {
        val = 0;
        next = NULL;
    }

    Node(long long val) {
        this->val = val;
        this->next = NULL;
    }
};

int n,m;
Node* hash[SIZE];

bool queryHash(char* ip) {
    long long num = inet_network(ip);
    int key = num % SIZE;

    Node* now = hash[key];
    while (now != NULL) {
        if (now->val == num)
            return true;
        now = now->next;
    }
    return false;
}

void insertHash(char* ip) {
    long long num = inet_network(ip);
    int key = num % SIZE;

    if (NULL == hash[key]) {
        hash[key] = new Node(num);
    } else {
        Node* now = new Node(num);
        now->next = hash[key];
        hash[key] = now;
    }
}

int main() {
    char* ip;
    ip = (char*)malloc(sizeof(char) * 16);
    memset(hash, 0x00, sizeof(hash));
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ip);
        insertHash(ip);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", ip);
        if (queryHash(ip)) {
            printf("FILTER\n");
        } else {
            printf("PASS\n");
        }
    }

    return 0;
}
