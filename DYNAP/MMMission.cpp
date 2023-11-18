#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int mod = 1e9 + 7;

int n;
int x[MAXN], y[20], vis[MAXN];
LL f[MAXN];
char str[20];

void dfs1(int u) {
    if (x[u] != 0) return;
    for (int i = 1; i <= n; i++) {
        if ((u & (1 << (i - 1))) == 0) continue;
        dfs1(u ^ (1 << (i - 1)));
        x[u] = x[u ^ (1 << (i - 1))] | y[i];
    }
}

void dfs2(int u) {
    if (vis[u] != 0) return;
    vis[u] = 1;
    for (int i = 1; i <= n; i++) {
        if ((u & (1 << (i - 1))) == 0) continue;
        if ((x[u ^ (1 << (i - 1))] & (1 << (i - 1))) != 0) {
            dfs2(u ^ (1 << (i - 1)));
            f[u] += f[u ^ (1 << (i - 1))];
        }
    }
}

int main() {
    int aa, cas = 1; scanf("%d", &aa);
    while (aa--) {
        scanf("%d", &n);
        memset(y, 0, sizeof(y));
        memset(x, 0, sizeof(x));
        for (int i = 0; i <= n; i++) {
            scanf(" %s", str + 1);
            int bas = 1;
            for (int j = 1; j <= n; j++) {
                y[i] += bas*(str[j] - '0');
                bas *= 2;
            }
        }
        x[0] = y[0];
        dfs1((1 << n) - 1);
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        f[0] = 1;
        dfs2((1 << n) - 1);
        printf("Case %d: %lld\n", cas++, f[(1 << n) - 1]);
    }
    return 0;
}