#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1 << 25;

int main() {
    vector<int> coins(6);
    vector<int> values = {5, 10, 20, 50, 100, 200};
    char c;
    int a, b;

    while (true) {
        bool ok = false;
        for (int i = 0; i < 6; ++i) {
            cin >> coins[i];
            if (coins[i] > 0) ok = true;
        }

        if (!ok) break;

        cin >> a >> c >> b;
        int sum = a * 100 + b;

        vector<int> dp(1001, INF);
        dp[0] = 0;

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < min(coins[i], 1 + 1000 / values[i]); ++j) {
                for (int k = 1000; k >= 0; --k) {
                    if (k + values[i] < 1001) {
                        dp[k + values[i]] = min(dp[k + values[i]], 1 + dp[k]);
                    }
                }
            }
        }

        vector<int> dp2(1001, INF);
        dp2[0] = 0;

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 1 + 1000 / values[i]; ++j) {
                for (int k = 1000; k >= 0; --k) {
                    if (k + values[i] < 1001) {
                        dp2[k + values[i]] = min(dp2[k + values[i]], 1 + dp2[k]);
                    }
                }
            }
        }

        int result = dp[sum];
        for (int i = sum + 5; i < 1001; i += 5) {
            if (dp[i] + dp2[i - sum] < result) {
                result = dp[i] + dp2[i - sum];
            }
        }

        cout << setw(3) << result << endl;
    }

    return 0;
}