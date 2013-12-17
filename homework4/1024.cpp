#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, k;
int x, y, d;

struct Node {
    int y, d;		// same as "int linknode, distance;"
    struct Node* next;
    Node(int yy, int dd) {
        y = yy;
        d = dd;
        next = NULL;
    }
};

struct Edge {
    Node* head;
    int x;
    Edge(int i) {
        x = i;
        head = NULL;
    }
};

Edge* a[10001];
bool vis[10001];
int result;

void dfs(int src, int length) {
    Node* now = a[src]->head;
    while (now != NULL) {
        if (!vis[now->y]) {
            vis[now->y] = true;
            dfs(now->y, length + now->d);
            vis[now->y] = false;
        }
        now = now->next;
    }
		// No need to store the path, 
		// just use length to record the path length.
    if (length > result) {
        result = length;
    }
}

int main() {
    while (cin >> n) {
        cin >> k;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= n; i++) {
            if (a[i])
                delete a[i];
            a[i] = new Edge(i);
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y >> d;
						// Build the while graph first.
            Node* now = new Node(y, d);
            now->next = a[x]->head;
            a[x]->head = now;

            now = new Node(x, d);
            now->next = a[y]->head;
            a[y]->head = now;
        }

				// Initiallization
        result = 0;
        vis[k] = true;
        
        dfs(k, 0);

        printf("%d\n", result);
    }
}                                 
