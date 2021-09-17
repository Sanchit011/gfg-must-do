#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
#define vi vector<int>

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}

void solve()
{
    ll n, m, c;
    cin >> n >> m >> c;
    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    ll ans = LLONG_MAX;
    ll val;
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            dp[i][j] = arr[i][j] + c*i + c*j;
            if(i<n-1) dp[i][j] = min(dp[i][j], dp[i+1][j]);
            if(j<m-1) dp[i][j] = min(dp[i][j], dp[i][j+1]);
            if(i<n-1 && j<m-1){
                ans = min(ans, arr[i][j] - c*(i + j) + dp[i+1][j+1]);
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = m-1; j>=0; j--){
            dp[i][j] = arr[i][j] - c*i + c*j;
            if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j<m-1) dp[i][j] = min(dp[i][j], dp[i][j+1]);
            if(i>0 && j<m-1){
                ans = min(ans, arr[i][j] + c*i - c*j + dp[i-1][j+1]);
            }
        }
    }
    for(int row = 0; row<n; row++){
        val = LLONG_MAX;
        for(int i = 0; i<m; i++){
            if(i>0){
                ans = min(ans, arr[row][i] + c*i + val);
            }
            val = min(val, arr[row][i] - c*i);
        }
    }
    for(int col = 0; col<m; col++){
        val = LLONG_MAX;
        for(int i = 0; i<n; i++){
            if(i>0){
                ans = min(ans, arr[i][col] + c*i + val);
            }
            val = min(val, arr[i][col] - c*i);
        }
    }
    cout << ans << endl;
}