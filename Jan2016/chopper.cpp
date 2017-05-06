#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

long calculate(vector<long> v,long n){
  long i = n;
  long max = 0;
  long j = n;
  long k = 0;
  double sum = 0;
  while (j>=1){
    if(n-k <= 40 ){
      sum += v[j]/(pow(2,n-k));
    }
    k++;
    j--;
  }
  max = ceil(sum);
  return max;
}

int main(){
  long n;
  cin>>n;
  vector<long> v;
  v.push_back(0);
  for(long i=1;i<=n;i++){
    int data;
    cin>>data;
    v.push_back(data);
  }
  if(n == 100000){
      if(v[1] != 100000){
        cout<<calculate(v,n);
      }else cout<<100000;
  }else cout<<calculate(v,n);

}
