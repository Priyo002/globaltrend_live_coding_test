#include<bits/stdc++.h>
using namespace std;


int knapsack(vector<int>& weight,vector<int>& value,vector<vector<int>>& dp,int i,int curr_Weight,int maxCapacity){

    if(i==(int)value.size()) return 0;

    if(dp[i][curr_Weight]!=-1) return dp[i][curr_Weight];

    int ans = knapsack(weight,value,dp,i+1,curr_Weight,maxCapacity);//don't take
    
    if(curr_Weight+weight[i] <= maxCapacity){//take
        ans = max(ans,value[i] + knapsack(weight,value,dp,i+1,curr_Weight+weight[i],maxCapacity));
    }

    return dp[i][curr_Weight] = ans;

}

int main(){

    int n;//number of items
    cin >> n;

    vector<int> value(n), weight(n);

    for(int i=0;i<n;i++) cin >> weight[i];
    for(int i=0;i<n;i++) cin >> value[i];

    int maxCapacity;
    cin >> maxCapacity;

    vector<vector<int>> dp(n+1,vector<int>(maxCapacity+1,-1));


    cout << knapsack(weight,value,dp,0,0,maxCapacity);

    return 0;
}