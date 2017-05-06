#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int pickLeast(int end[1000],int n){
  //returns the least finishing time

  int least = INT_MAX;
  int pos = -1;
  for(int i=0;i<n;i++){
    if(end[i]<least){
      least = end[i];
      pos = i;
    }
  }

  return pos;
}

int main(){
  int t;
  cin>>t;
  while(t){
    int n;
    cin>>n;
    int start[1000],end[1000];
    for(int i=0;i<n;i++){
      cin>>start[i]>>end[i];
    }

    int count = 0;
    int k = 0;
    while(k<n){
      int next = pickLeast(end,n);
      if(next != -1){
        count++;
      }else{
        k++;
        continue;
      }

      int con_start[1000],con_end[1000],con_i[1000];
      int c = 0;
      for(int i=0;i<n;i++){
        if(i!=next){
          if(start[i]>=start[next] && end[i]<=end[next]){
            con_start[c] = start[i];
            con_end[c] = end[i];
            con_i[c] = i;
            c++;
          }else if(start[i]<=start[next] && end[i]>=end[next]){
            con_start[c] = start[i];
            con_end[c] = end[i];
            con_i[c] = i;
            c++;
          }else if((start[i]>=start[next] && start[i]<=end[next]) || (start[next]>=start[i] && start[next]<=end[i])){
            con_start[c] = start[i];
            con_end[c] = end[i];
            con_i[c] = i;
            c++;
          }
        }
      }

      if(c>=1){
        int allow = pickLeast(con_end,c);
        for(int i=0;i<c;i++){
          if(i!=allow){
            start[con_i[i]] = INT_MAX;
            end[con_i[i]] = INT_MAX;
          }
        }
      }

      start[next] = end[next] = INT_MAX;
      k++;
    }

    cout<<count<<endl;
    t--;
  }
}
