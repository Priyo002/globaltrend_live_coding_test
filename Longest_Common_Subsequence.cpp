#include<bits/stdc++.h>
using namespace std;

int getLengthOfLCS(string &str1,string &str2,vector<vector<int>>& dp,int i,int j){

    if(i==(int)str1.size() || j==(int)str2.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(str1[i]==str2[j]){
        ans = max(ans,1+getLengthOfLCS(str1,str2,dp,i+1,j+1));
    }
    else{
        ans = max(ans,getLengthOfLCS(str1,str2,dp,i+1,j));
        ans = max(ans,getLengthOfLCS(str1,str2,dp,i,j+1));
    }

    return dp[i][j] = ans;
}

int main(){

    string str1,str2;
    cin >> str1 >> str2;

    int n = str1.size(), m = str2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    cout << getLengthOfLCS(str1,str2,dp,0,0);


    return 0;
}