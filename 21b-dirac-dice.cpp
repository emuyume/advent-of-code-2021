#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 25; int N;
const string file = "test.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }
ll dp[50][50][11][11][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int sp1 = 4, sp2 = 5;
    dp[0][0][sp1][sp2][0] = 1;
    ll win1 = 0, win2 = 0;
    for (int s1 = 0; s1 <= 30; ++s1){
        for (int s2 = 0; s2 <= 30; ++s2){
            for (int p1 = 1; p1 <= 10; ++p1){
                for (int p2 = 1; p2 <= 10; ++p2){
                    if (s1 >= 21 && s2 < 21) win1 += dp[s1][s2][p1][p2][1];
                    else if (s2 >= 21 && s1 < 21) win2 += dp[s1][s2][p1][p2][0];
                    else{
                        for (int r1 = 1; r1 <= 3; ++r1){
                            for (int r2 = 1; r2 <= 3; ++r2){
                                for (int r3 = 1; r3 <= 3; ++r3){
                                    int roll = r1 + r2 + r3;
                                    int np1 = (p1 + roll - 1) % 10 + 1;
                                    dp[s1 + np1][s2][np1][p2][1] += dp[s1][s2][p1][p2][0];
                                    int np2 = (p2 + roll - 1) % 10 + 1;
                                    dp[s1][s2 + np2][p1][np2][0] += dp[s1][s2][p1][p2][1];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << max(win1, win2) << '\n';
}
