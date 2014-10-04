#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

int n, m, as[200055], bs[200055];

const ll ps[10] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181};

ll hash(int x, int i) {
    if (i == 0) return x * x * x * ps[i] * ps[i + 3];
    if (i == 1) return x * x * ps[i] * ps[i + 3];
    if (i == 2) return x * ps[i] * ps[i + 3];
}


int main () {
    int i, j, tcc, tc = 1 << 28;
    for (tcc = 0; tcc < tc; tcc++) {
        n = getint(), m = getint();
        int p = getint();
        for (i = 0; i < n; i++) as[i] = getint();
        for (i = 0; i < m; i++) bs[i] = getint();
        vector<int> res;
        ll g1 = 0, g2 = 0, g3 = 0;
        for (i = 0; i < m; i++) {
            g1 += hash(bs[i], 0);
            g2 += hash(bs[i], 1);
            g3 += hash(bs[i], 2);
        }
        // cout << g1 << ' ' << g2 << ' ' << g3 << endl;
        for (int q = 0; q < p; q++) {
            ll h1 = 0, h2 = 0, h3 = 0;
            int fail = 0;
            for (i = 0; i < m - 1; i++) {
                if (q + p * i >= n - 1) { fail = 0; break; }
                h1 += hash(as[q + p * i], 0);
                h2 += hash(as[q + p * i], 1);
                h3 += hash(as[q + p * i], 2);
            }
            if (fail) continue;
            for (ll ii = q + (ll)(m - 1) * p; ii < n; ii += p) {
                i = ii;
                h1 += hash(as[i], 0);
                h2 += hash(as[i], 1);
                h3 += hash(as[i], 2);
                // cout << h1 << ' ' << h2 << ' ' << h3 << endl;
                if (h1 == g1 and h2 == g2 and h3 == g3) res.push_back(i - (m - 1) * p);
                h1 -= hash(as[i - (m - 1) * p], 0);
                h2 -= hash(as[i - (m - 1) * p], 1);
                h3 -= hash(as[i - (m - 1) * p], 2);
            }
        }
        cout << res.size() << endl;
        sort(res.begin(), res.end());
        for (i = 0; i < res.size(); i++) cout << res[i] + 1 << ' '; puts("");
    }
    return 0;
}
