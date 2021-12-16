#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
vector<bool> s;
int ans = 0, i;
int read(int cnt){
    if (cnt == 1) return s[i++];
    int cur = s[i++] * (1 << (cnt - 1)); return cur + read(cnt - 1);
}
void go(){
    int version = read(3);
    int type = read(3);
    if (type == 4){
        int val = 0;
        bool again = 1;
        while (again){
            again &= read(1);
            val = val * 16 + read(4);
        }
    }
    else{
        int lengthtype = read(1);
        if (lengthtype == 0){
            int len = read(15);
            int stop = i + len;
            while (i < stop){
                go();
            }
        }
        if (lengthtype == 1){
            int num = read(11);
            while (num--){
                go();
            }
        }
    }
    ans += version;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen(file.c_str(), "r", stdin);
    string t; cin >> t;
    for (char c : t){
        int x;
        if (c >= '0' && c <= '9') x = c - '0';
        else x = c - 'A' + 10;
        for (int i = 3; i >= 0; --i){
            s.push_back(x & (1 << i));
        }
    }
    N = s.size();
    go();
    cout << ans << '\n';
}
