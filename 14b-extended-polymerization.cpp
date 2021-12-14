#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

map<string, ll> lst, cnt;
map<string, string> mp;
map<char, ll> letters;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    N -= 2;
    string s; cin >> s;
    letters[s[0]]++; letters[s.back()]++;
    for (int i = 1; i < s.size(); ++i){
        cnt[s.substr(i - 1, 2)]++;
    }
    getline(cin, s);
    getline(cin, s);
    for (int i = 1; i <= N; ++i){
        getline(cin, s);
        mp[s.substr(0, 2)] = s.substr(6);
    }
    for (int i = 1; i <= 40; ++i){
        swap(lst, cnt);
        cnt.clear();
        for (auto [s, c] : lst){
            cnt[s[0] + mp[s]] += c;
            cnt[mp[s] + s[1]] += c;
        }
    }
    for (auto [s, num] : cnt){
        for (char c : s){
            letters[c] += num;
        }
    }
    ll mn = LLONG_MAX, mx = 0;
    for (auto [s, c] : letters){
        c /= 2;
        mn = min(mn, c);
        mx = max(mx, c);
    }
    cout << mx - mn << '\n';
}
