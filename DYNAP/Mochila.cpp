#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mochila (vector<int> b, vector<int> p, int M)
{
    b.insert(b.begin(), 0);
    p.insert(p.begin(), 0);
    int N = b.size() - 1;
    vector<vector<int>> solutionMatrix(N + 1, vector<int>(M + 1));
    vector<int> solution;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0 || j == 0)
            {
                solutionMatrix[i][j] = 0;
            }
            else if (p[i] <= j)
            {
                solutionMatrix[i][j] = max( solutionMatrix[i-1][j], b[i]+solutionMatrix[i-1][j-p[i]]);
            }
            else
            {
                solutionMatrix[i][j]=solutionMatrix[i-1][j];
            }
        }
    }
    int j=M;
    for (int i = N;i>0;i--)
    {
        if (solutionMatrix[i][j] == solutionMatrix[i-1][j])
        {
            solution.push_back(0);
        }
        else
        {
            solution.push_back(1);
            j=j-p[i];
        }
    }
    reverse(solution.begin(),solution.end());
    return solution;
}
int main()
{
    vector<int> b = {12,3,7,4,3,8};
    vector<int> p = {3,7,4,2,1,6};
    int m=15;
    vector<int> solution = mochila(b,p,m);
    for (int i=0;i<solution.size();i++)
    {
        cout<<solution[i]<<' ';
    }
}