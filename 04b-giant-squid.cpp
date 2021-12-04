#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 100; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

struct Board{
    int a[5][5];
    void insert(int x){
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                if (a[i][j] == x) a[i][j] = -a[i][j] - 1;
            }
        }
    }
    bool win(){
        for (int i = 0; i < 5; ++i){
            bool winr = 1;
            bool winc = 1;
            for (int j = 0; j < 5; ++j){
                winr &= a[i][j] < 0;
                winc &= a[j][i] < 0;
            }
            if (winr || winc) return 1;
        }
        return 0;
    }
    int score(){
        int ret = 0;
        for (int i = 0; i < 5; ++i){
            for (int j = 0; j < 5; ++j){
                if (a[i][j] >= 0) ret += a[i][j];
            }
        }
        return ret;
    }
} boards[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    N = (N - 1) / 6;
    string calls; cin >> calls;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 5; ++j){
            for (int k = 0; k < 5; ++k){
                cin >> boards[i].a[j][k];
            }
        }
    }
    int left = N;
    while (true){
        int idx = calls.find(',');
        int num = stoi(calls.substr(0, idx));
        for (int i = 0; i < N; ++i){
            if (boards[i].win()) continue;
            boards[i].insert(num);
            if (boards[i].win()){
                left--;
                if (left == 0){
                    cout << boards[i].score() * num << '\n';
                    return 0;
                }
            }
        }
        calls = calls.substr(idx + 1);
    }
}
