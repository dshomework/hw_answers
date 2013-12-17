#include <cstdio>
#include <cstdlib>

using namespace std;

int S[102];
int n;

int main() {

    while (scanf("%d", &n) != -1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &S[i]);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            bool less = true;
            for (int j = 0; j < i; j++) {
                less &= (S[j] < S[i]);
            }
            if (!less)
                continue;

            bool bigger = true;
            for (int j = i + 1; j < n; j++) {
                bigger &= (S[i] < S[j]);
            }
            if (!bigger)
                continue;

            cnt++;
        }

        printf("%d\n", cnt);
    }
    return 0;
}                                 
