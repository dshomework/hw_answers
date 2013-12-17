#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    bool isDial;
    bool ban;
    struct Node* next[10];

    Node() {
        this->ban = false;
        memset(this->next, 0x00, sizeof(this->next));
    }
};

int n, m, ans;
Node* root;

void buildTrie(char* dial) {
    char* pos = dial;
    Node* now = root;

    while (*pos != 0x00) {
        int num = *pos - 48;
        if (NULL == now->next[num]) 
            now->next[num] = new Node();
        now = now->next[num];    

        if (now->ban)
            return;
        pos++;
    }

    now->ban = true;
    ans++;
}

int main() {
    root = new Node();
    ans = 0;
    char* dial;
    dial = (char*)malloc(sizeof(char) * 100);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", dial);    
        buildTrie(dial);
    }

    printf("%d\n", ans);
    return 0;
}
