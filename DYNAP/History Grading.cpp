#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n, i, j, flag, order;
    vector<int> x(20), y(20);

    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> order;
        order--;
        x[order] = i;
    }

    while (true) {
        flag = 0;

        for (i = 0; i < n; i++) {
            if (!(cin >> order)) {
                flag = 1;
                break;
            }
            order--;
            y[order] = i;
        }

        if (flag) break;

        vector<vector<int>> dp(25, vector<int>(25, 0));

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        cout << dp[n][n] << endl;
    }

    return 0;
}
/*
4
4 2 3 1
1 3 2 4
3 2 1 4
2 3 4 1
10
3 1 2 4 9 5 10 6 8 7
1 2 3 4 5 6 7 8 9 10
4 7 2 3 10 6 9 1 5 8
3 1 2 4 9 5 10 6 8 7
2 10 1 3 8 4 9 5 7 6
*/