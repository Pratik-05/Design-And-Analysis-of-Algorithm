#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int knapsackfun(int wt[],int val[],int ind,int W,int dp[][7])
{
    //Base-Condition
    if(ind==0)
    {
        if(wt[0]<=W)
        {
            return val[0];
        }
        else return 0;
    }
    
    //Check whether answer is already calculated 
    //If yes then we need to return the value of dp array
    if(dp[ind][W]!=-1)
    {
        return dp[ind][W];
    }
    
    int notTaken=0+knapsackfun(wt,val,ind-1,W,dp);
    int taken=INT_MIN;
    
    if(wt[ind]<=W)
    {
        taken=val[ind]+knapsackfun(wt,val,ind-1,W-wt[ind],dp);
    }
    return dp[ind][W]=max(notTaken,taken);
}

int knapsack(int wt[],int val[],int n,int W)
{
    //Create Dp array
    int dp[n][7];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            dp[i][j]=-1;
        }
    }
    return knapsackfun(wt,val,n-1,W,dp);
}

int main()
{
    int W=8;
    int n=4;
    int wt[4];
    int val[4];
    int x;
    int y;
    cout<<"Enter the Weight Values: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter the Values in the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    
    cout<<"The Maximum Value of items,thief can steal is: "<<knapsack(wt,val,n,W);
    return 0;
}
// /*Output-1:
// Enter the Weight Values:
// 1 2 4 5
// Enter the Values in the array:
// 5 4 8 6
// The Maximum Value of items,thief can steal is: 13
// Output-2:
// Enter the Weight Values:
// 2 3 4 5
// Enter the Values in the array:
// 1 2 5 6
// The Maximum Value of items,thief can steal is: 8
// Output-3:
// Enter the Weight Values:
// 1 2 3
// Enter the Values in the array:
// 10 15 40
// The Maximum Value of items,thief can steal is: 65
// */
