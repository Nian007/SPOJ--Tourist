#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e2+5;
int dp[maxn][maxn][maxn];
char grid[maxn][maxn];
int n,m;
int dx1[4] = { 1, 1, 0, 0 };
int dy1[4] = { 0, 0, 1, 1 };
int dx2[4] = { 1, 0, 1, 0 };
int dy2[4] = { 0, 1, 0, 1 };
int maxNumberOfInterestingLocations(int x1,int y1, int x2, int y2){
    if(x1>n || y1>m || x2>n || y2>m || grid[x1][y1]=='#' || grid[x2][y2]=='#')
        return INT_MIN;
    if ( x1 == n && y1 == m)
        return (grid[x1][y1]=='*');
    if(dp[x1][y1][x2]!=-1)
        return dp[x1][y1][x2];
    int ret = INT_MIN;
    for(int i=0;i<4;i++){
        ret = max(ret, maxNumberOfInterestingLocations(x1+dx1[i], y1+dy1[i], x2+dx2[i], y2+dy2[i]));
    }
    ret += (grid[x1][y1]=='*');
    ret += (grid[x2][y2]=='*');
    if(x1==x2&&y1==y2&&grid[x1][y1]=='*')
        ret--;
    dp[x1][y1][x2]=ret;
    return ret;
}
void solve(){
    cin>>m>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m; j++){
            cin>>grid[i][j];
        }
    }
    cout<<maxNumberOfInterestingLocations(1,1,1,1)<<"\n";
}
int32_t main(){
	ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
