#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits.h>
using namespace std;


int main(){
  int n,k;
  cin>>n>>k;
  vector<long> v;

  for(int i=0;i<n;i++){
    int data;
    cin>>data;
    v.push_back(data);
  }

  sort(v.begin(),v.end());
  long long min = INT_MAX;
  for(int i=0;i<=n-k;i++){
    if(min > (v[i+k-1] - v[i])){
       min = v[i+k-1] - v[i];
    }
  }

  cout<<min;
}
