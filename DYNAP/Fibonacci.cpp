#include <iostream>
#include <vector>

using namespace std;
int fibonacci(int n)
{
    vector<int> memo(n + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; ++i) 
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main() {
    int n = 10;
    cout << fibonacci(n);
    return 0;
}
