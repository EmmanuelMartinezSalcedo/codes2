#include <iostream>
#include <vector>
using namespace std;

vector<char> LCS(vector<char> X, vector<char> Y)
{
    X.insert(X.begin(), '_');
    Y.insert(Y.begin(), '_');
    int N = X.size();
    int M = Y.size();
    vector<vector<int>> solutionMatrix(N + 1, vector<int>(M + 1));
    vector<char> solution;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            if (i==0 || j==0)
            {
                solutionMatrix[i][j]=0;
            }
            else if (X[i] == Y[j])
            {
                solutionMatrix[i][j]=solutionMatrix[i-1][j-1] +1;
            }
            else
            {
                solutionMatrix[i][j]=max(solutionMatrix[i-1][j], solutionMatrix[i][j-1]);
            }
        }
    }
    int j=M;
    int i=N;
    while (i > 0 && j > 0) 
    {
        if (X[i] == Y[j]) 
        {
            solution.push_back(X[i]);
            i--;
            j--;
        } 
        else if (solutionMatrix[i - 1][j] > solutionMatrix[i][j - 1]) 
        {
            i--;
        } 
        else 
        {
            j--;
        }
    }
    return solution;
}
int main(){
    vector<char> X = {'a' , 'b', 'c', 'b'};
    vector<char> Y = {'b', 'd', 'c', 'a','b'};
    vector<char> solution = LCS(X,Y);
    for (int i=0;i<solution.size();i++)
    {
        cout<<solution[i]<<' ';
    }
}