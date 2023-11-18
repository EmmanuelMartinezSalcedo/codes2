#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Monedas(vector<int> c, int M) {
    c.insert(c.begin(), 0);
    int N = c.size() - 1;

    vector<vector<int>> solutionMatrix(N+1, vector<int>(M + 1));

    vector<int> solution;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (j == 0)
            {
                solutionMatrix[i][j] = 0;
            }
            else if (i == 0)
            {
                solutionMatrix[i][j] = INT_MAX;
            }
            else if (c[i] <= j)
            {
                solutionMatrix[i][j]=min(solutionMatrix[i-1][j],1 + solutionMatrix[i][j-c[i]]);
            }
            else
            {
                solutionMatrix[i][j]=solutionMatrix[i-1][j];
            }
        }
    }
    for (int i=0;i<N+1;i++)
    {
        solution.push_back(0);
    }
    int j=M;
    int i=N;
    while (i > 0 && j > 0)
    {
        if (solutionMatrix[i][j] == solutionMatrix[i-1][j])
        {
            i--;
        }
        else
        {
            solution[i]=solution[i]+1;
            j=j-c[i];
        }
    }
    solution.erase(solution.begin());
    return solution;
}

int main() {
    vector<int> c ={1,2,3,5,6,8,};
    int p=11;
    vector<int> solution = Monedas(c,p);
    for (int i=0;i<solution.size();i++)
    {
        cout<<solution[i]<<' ';
    }
}