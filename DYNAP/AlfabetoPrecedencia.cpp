#include <iostream>
#include <vector>

using namespace std;

bool precedes(const char& u, const char& v, const string& orderString) {
    int n = orderString.size();
    vector<vector<bool>> order(n, vector<bool>(n, false));

    for (int i = 0; i < n - 1; ++i) {
        int x = orderString[i] - 'a';
        int y = orderString[i + 1] - 'a';
        order[x][y] = true;
    }

    int i = u - 'a';
    int j = v - 'a';

    return order[i][j];
}

int main() {
    string alphabet = "abcd";
    char u='a';
    char v='c';

    cout<<precedes(u, v, alphabet);

    return 0;
}