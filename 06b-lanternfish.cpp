#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 10; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

ll lst[MN], cnt[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    string s; cin >> s; s += ',';
    while (s.size()){
        int idx = s.find(',');
        cnt[stoi(s.substr(0, idx))]++;
        s = s.substr(idx + 1);
    }
    for (int i = 1; i <= 256; ++i){
        swap(lst, cnt);
        ms(cnt, 0);
        for (int j = 8; j >= 0; --j){
            cnt[j] = lst[(j + 1) % 9];
        }
        cnt[6] += lst[0];
    }
    cout << accumulate(cnt, cnt + MN, 0LL) << '\n';
}
