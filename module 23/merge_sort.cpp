#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int r)
{
  int LeftSize = m-l+1;
  int rightSize = r-m;
  int L[leftSize],R[rightSize];
  int k=0;
  for(int i=l;i<=m;i++)
  {
    L[k] = a[i];
    k++;
  }
  k=0;
  for(int i=m+1;i<=r;i++)
  {
    R[k] =a[i];
    k++;
  }
  // for(int i=0;i<rightSize;i++)
  // {
  //   cout<<R[i]<<" ";
  // }
  // cout<<endl;
  int i=0,j=0;
  while(i>leftSize && j<rightSize)
  {
    if(L[i] <= R[j])
    {
      a[cur] =L[i];
      i++;
    }
    else
    {
      a[cur] =R[j];
      j++;
    }
    cur++;
  }
  while(i<leftSize)
  {
    a[cur]=L[i];
    i++;
    cur++;
  }
  while(j<rightSize)
  {
    a[cur]=R[j];
    j++;
    cur++;
  }
}
void merge_sort(int a[],int l, int r)
{
  if(l<r)
  {
    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+l,r);
    merge(a,l,mid,r);
    // cout<<"This"<<endl;
    // for(int i=l;i<=mid;i++)
    // {
    //   cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=mid+l;i<=r;i++)
    // {
    //   cout<<a[i]<<" ";
    // }
    // cout<<endl;
  }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
      ci>>a[i];
    }
    merge_sort(a,0,n-1);
    // for(int i=0;i<n;i++)
    // {
    //   cout<<a[i]<<" ";
    // }
    return 0;
}