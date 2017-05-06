#include<stdio.h>
#include<iostream>

#include<bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<long long,long long> &a,
              const pair<long long,long long> &b)
{
    return (a.second < b.second);
}

long long result(vector< pair<long long,long long> > a,long long n,long long m){
  long long max = a[0].second;
  long long pos = 0;
  for(long long i=0;i<=n;i++){
    if(a[i].second>max){
      max = a[i].second;
      pos = i;
    }
  }
  long long ans = 0;
  sort(a.begin(),a.end(),sortbysec);

  long long min = -1;
  for(long long i=1;i<n;i++){
    if(a[i].first > a[i+1].first){
      long long diff = 0;
      //a[i+1].second >= a[i].second
      if(min == -1){
        min = a[i+1].second - a[i].second;
      }
      if(min > (diff = a[i+1].second-a[i].second)){
        min = diff;
      }
    }
  }

  if(max > (m-min)){
    return max;
  }else return m-min;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    vector< pair<long long,long long> > a;
    long long n,m;
    cin>>n>>m;
    a.push_back(make_pair(0,0));
    for(long long i=1;i<=n;i++){
      long long data;
      cin>>data;
      data = data + a[i-1].second;
      if(data > m){
        data = data%m;
      }
      a.push_back(make_pair(i,data));

    }



    cout<<result(a,n,m)<<endl;
  }
}
