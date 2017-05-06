#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
  char a[5001];
  char b[5001];

  cin>>a;
  cin>>b;

  int n = strlen(a);

  vector< vector<int> > v;

  v.resize(n+1);
  for(int i=0;i<=n;i++){
    v[i].resize(n+1);
  }

  for(int i=0;i<=n;i++){
    v[0][i] = 0;
    v[i][0] = 0;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(a[i-1] == b[j-1]){
        v[i][j] = v[i-1][j-1] + 1;
      }else if(a[i-1] != b[j-1]){
        int x = v[i-1][j];
        int y = v[i][j-1];
        if(x>=y){
          v[i][j] = x;
        }else v[i][j] = y;
      }
    }
  }

  cout<<v[n][n];

}


/*
int counter(char a[],char b[],int i,int j,int n,int count,int &max){

  if(i == n || j == n){
    if(count>max){
      max = count;
      return count;
    }else return max;
  }

  for(int k = i;k<n;k++){
    for(int m = j;m<n;m++){
      if(a[k] == b[m]){
        //cout<<a[k]<<" "<<b[m]<<" "<<count<<" "<<max<<endl;
        max = counter(a,b,k+1,m+1,n,count+1,max);
      }
      //cout<<k<<"  "<<m<<" "<<"  "<<count<<" "<<max<<endl;
    }
  }

  return max>count?max:count;
}
*/
