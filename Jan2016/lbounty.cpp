#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n;
  cin>>k;

  vector<int> v;

  long sum = 0;
  for(int i=0;i<n;i++){
    int data;
    cin>>data;
    v.push_back(data);
    sum += data;
  }
  sort(v.begin(),v.end());
  int i = 0;
  while(k-- && (v[i]<=v[n-1-i])){
    sum -= v[i];
    v[i] = v[n-1-i]-v[i];
    sum += v[i];
    i++;
  }

  cout<<sum;

}
