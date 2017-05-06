#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  std::vector<long long> a;
  long long p,q;
  long long min = 0;
  cin>>n;
  int i=0;

  for(i=0;i<n;i++){
    long long data;
    cin>>data;
    a.push_back(data);
  }
  a.push_back(q);
  cin>>p>>q;
  int start = -1;
  a.push_back(p);

  sort(a.begin(),a.end());
  long long ans;
  for(i=0;i<n+2;i++){
    if(a[i+1] >= p && a[i] <= q){
      if(start == -1){
        start = i;
      }
      if(a[i] == p || a[i+1] == q){
       if(abs(a[i]-a[i+1]) > min){
         if(a[i] == p){
           min = abs(a[i]-a[i+1]);
           ans = p;
         }else if(a[i+1] == q){
           min = abs(a[i]-a[i+1]);
           ans = q;
         }
       }
     }else if(abs(a[i] - a[i+1])/2 > min){
        min = abs(a[i]-a[i+1])/2;
        long long temp = (a[i+1] + a[i])/2;
        if(temp >= p && temp <= q)
          ans = temp;
      }
    }
  }

  cout<<ans<<endl;

}
