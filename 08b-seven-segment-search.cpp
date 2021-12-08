#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
map<int, int> mp = {{119, 0}, {36, 1}, {93, 2}, {109, 3}, {46, 4}, {107, 5}, {123, 6}, {37, 7}, {127, 8}, {111, 9}};
vector<char> ord;

int calc(string s){
    int val = 0;
    for (char c : s) val += 1 << (find(ord.begin(), ord.end(), c) - ord.begin());
    if (mp.count(val)) return mp[val];
    else return -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = countlines(); freopen(file.c_str(), "r", stdin);
    int ans = 0;
    while (T--){
        ord = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        vector<string> v(10);
        for (string &s : v) cin >> s;
        do{
            set<int> seen;
            for (string s : v) seen.insert(calc(s));
            if (seen.size() == 10 && !seen.count(-1)) break;
        } while(next_permutation(ord.begin(), ord.end()));
        string s; cin >> s;
        int val = 0;
        for (int i = 1; i <= 4; ++i){
            cin >> s;
            val = (val * 10) + calc(s);
        }
        ans += val;
    }
    cout << ans << '\n';
}
