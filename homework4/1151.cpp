// Problem#: 1151
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int factory[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };
const int M = 50000; // 8! = 40320
const int N = 8;
int maxstep;
int len;
string src = "12348765";
string ans;
int input_arr[8];
string que[M];
string parent[M];
bool vis[M];
int path[M];
char exec[M];
//############################################
string S(int* m){
    string st = "";
    for(int i=0;i<8;i++){
        st.push_back((char)(m[i]+48));
    }
    return st;
}

string moveA(string st){
    string m = st;
    for (int i=0;i<4;i++){
        char temp = m[i];
        m[i] = m[i+4];
        m[i+4] = temp;
    }
    return m;
}

string moveB(string st){
    string m = st;
    char temp1 = m[3];
    char temp2 = m[7];
    for (int i=3;i>0;i--){
        m[i] = m[i-1];
        m[i+4] = m[i+4-1];
    }
    m[0] = temp1;
    m[4] = temp2;
    return m;
}

string moveC(string st){
    string m = st;
    int temp = m[1];
    m[1] = m[5];
    m[5] = m[6];
    m[6] = m[2];
    m[2] = temp;
    return m;
}

string move(int index, string now){
    switch(index){
        case 0: return moveA(now);break;
        case 1: return moveB(now);break;
        case 2: return moveC(now);break;
    }
}

inline bool finalAnswer(string st){
    return (st == ans);
}

int canter_encode(string str) {
    int i, j, counted;
    int result = 0;
    for (i=0;i<8;i++) {
        counted = 0;
        for(j=i+1;j<8;j++)
            if(str[i] > str[j])
                counted++;
        result = result + counted * factory[7 - i];
    }
    return result;
}

bool bfs() {
    int open = 0, closed = 0;
    int index = canter_encode(src);
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
    que[0] = src;
    path[index] = 0;
    exec[index] = ' ';
    parent[index] = "";
    vis[index] = true;

    if (finalAnswer(src)) {
        len = 0;
        return true;
    }

    while (open <= closed) {
        string now = que[open];
        int nowi = canter_encode(now);
        if (path[nowi] > maxstep) {
            open++;
            continue;
        }
        for (int i=0;i<3;i++) {
            string next = move(i, now);
            index = canter_encode(next);
            if (!vis[index]) {
                vis[index] = true;
                path[index] = path[nowi] + 1;
                parent[index] = now;
                exec[index] = (char)(65 + i);
                closed++;
                que[closed] = next;
            }
            if (finalAnswer(next)) {
                len = path[index];
                return true;
            }
        }
        open++;
    }
    return false;
}

void output() {
    if (len > maxstep) {
        cout << -1 << endl;
        return;
    }
    cout << len;
    if (len == 0){
        cout << endl;
        return;
    }
    cout << " ";
    string prt = ans;
    string mov = "";
    while (prt != "") {
        int index = canter_encode(prt);
        mov = exec[index] + mov;
        prt = parent[index];
    }
    cout << mov << endl;
    return;
}

int main(){
    while (cin >> maxstep && maxstep != -1){
        for (int i=0;i<8;i++) {
            cin >> input_arr[i];
        }
        ans = S(input_arr);
        bool result = bfs();
        if (!result){
            cout << -1 << endl;
            continue;
        }
        output();
    }
    return 0;
}                                 
