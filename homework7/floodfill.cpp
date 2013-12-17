#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char high = '1';
const char low = '0';

int color, n, m;

int g[101][101];
bool a[101][101];

int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 0 && a[x][y]);
}

void floodfill(int x, int y) {
    g[x][y] = color;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];

        if (valid(xx, yy))
            floodfill(xx, yy);
    }

}

int main() {
    char ch;
    while (cin >> n) {
        cin >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> ch;
                if (high == ch)
                    a[i][j] = true;
                else
                    a[i][j] = false;
                g[i][j] = 0;
            }

        color = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (a[i][j] && g[i][j] == 0) {
                    floodfill(i, j);
                    color++;
                }

        cout << color - 1 << endl;
    }
    return 0;
}

