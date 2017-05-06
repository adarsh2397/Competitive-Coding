//Longest Common Subsequence
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  long n;
  long long k;
  vector<int> v;
  cin>>n>>k;

  for(long i=0;i<n;i++){
    long long data;
    cin>>data;
    v.push_back(data);
  }
  long long count = 0;
  long long max = 0;
  for(long i=1;i<n;i++){
    if(abs(v[i]-v[i-1]) <= k){
      count++;
    }else{
      if(count>max){
        max = count;
      }
      count = 0;
    }
  }
  if(count>max){
    max = count;
  }
  count = 0;
  cout<<max+1;
}
