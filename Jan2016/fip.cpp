//Fill it up
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


long n;
long max_i(vector<long long> v,long i,long j){

  long long max = v[i];
  long pos = i;
  for(long m = i+1;m<j;m++){
    if(v[m]>max){
      max = v[m];
      pos = m;
    }
  }

  return pos;
}

long long summation(vector<long long int> v,long i,long j,long long answer,long max_pos){
  if(i >= j){
    return answer;
  }
  long max_left=-1,max_right=j;
  //LEFT
  if(i==0){
    max_left = max_i(v,i,max_pos);
    answer += v[max_left]*(max_pos-max_left);
  }

  //RIGHT
  if(j==n){
    if(max_pos<n-1){
      max_right = max_i(v,max_pos+1,j);
      answer += v[max_right]*(max_right-max_pos);
    }
  }

  if(max_left >= i){
    answer += summation(v,i,max_left,0,max_left);
  }
  if(max_right < j){
    answer += summation(v,max_right+1,j,0,max_right);
    cout<<answer<<endl;
  }

  return answer;
}

int main(){

  cin>>n;

  std::vector<long long int> v;

  for(long i=0;i<n;i++){
    long long data;
    cin>>data;
    v.push_back(data);
  }
  long max_start = max_i(v,0,n);
  cout<<summation(v,0,n,0,max_start);
}
