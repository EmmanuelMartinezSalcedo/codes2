#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long long int n,DP[50][300][300], price, coinreal[50], coinit[50];
int solve(int id, int changereal, int changeit){
    long long int preco = changereal * changereal +  changeit * changeit;
    if(preco == price) return 0;
    if(id == n || preco > price) return INF;
    long long int &value = DP[id][changereal][changeit];
    if(value != -1) return value;
    return value = min(solve(id+1,changereal, changeit), solve(id, changereal + coinreal[id], changeit + coinit[id]) + 1 );
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> price;
        price = price*price;
        for(int i = 0; i < n; i++)
            cin >> coinreal[i] >> coinit[i];
        memset(DP, -1, sizeof DP);
        long long int ans = solve(0,0,0);
        if(ans >= INF) cout << "not possible" << endl;
        else cout << ans << endl;
    }    
}