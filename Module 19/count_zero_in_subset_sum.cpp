#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int subset_sum(int n, int a[], int s)
{
  if(n==0)
  {
    if(s==0) 
    return 1;
    else 
    return 0;
  }
  if(dp[n][s] != -1) return dp[n][s];
  if(a[n-1] <= s)
  {
    int op1 = subset_sum(n - 1, a,s-a[n-1]);
    int op2 = subset_sum(n-1,a,s);
    return dp[n][s] = op1 + op2;
  }
  else{
    return dp[n][s] = subset_sum(n-1, a, s);
  }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    int s;
    cin>>s;
    // for(int j=0;j<=s;j++)
    // {
    //   for(int j=0; j<=s; j++)
    //   {
    //     dp[i][j] = -1;
    //   }
    // }
    // cout<<subset_sum(n,a,s);
     int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }

    int s;
    cin>>s;
    bool dp[n+1][s+1];
    dp[0][0]=true;
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=s;j++)
      {
        if(j==0)
           dp[i][j]=1;
        else if(i==0)
           dp[i][j]=0;
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=s;j++)
      {
        if(a[i-1]<=j)
        {
        //   bool op1 = dp[i-1][j-a[i-1]];
        // bool op2 =dp[i-1][j];
        // dp[i][j]=op1 || op2;
        dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    for(int i=0; i<=n; i++)
    {
      for (int j=0; j<=s; j++)
      {
        cout << endl;
      }
    }
    return 0;
}