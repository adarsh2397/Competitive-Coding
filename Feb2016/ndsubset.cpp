#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
  return a>b?a:b;
}

int main(){
  int n,k;
  cin>>n>>k;

  std::vector<long long> a;
  std::vector<int> c;
  a.resize(n);
  c.resize(k);

  for(int i=0;i<k;i++){
    c[i] = 0;
  }

  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i] = a[i]%k;
    c[a[i]]++;
  }
  int count;
  if(c[0]){
    count = 1;
  }else count = 0;

  for(int i=1;i<(k+1)/2;i++){
    count += max(c[i],c[k-i]);
  }
  if(k%2 == 0 && c[k/2]){
    count += 1;
  }

  cout<<count<<endl;

}
