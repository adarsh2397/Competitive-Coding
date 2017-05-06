#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    string a,b;

    cin>>a;
    cin>>b;

    int na = a.size();
    int nb = b.size();

    int atr = 0, btr = 0;
    while(atr < na && btr <nb){
      if(a[atr] < b[btr]){
        cout<<a[atr];
        atr++;
      }else if(a[atr]>b[btr]){
        cout<<b[btr];
        btr++;
      }else{
        int ja = atr+1,jb = btr+1;
        int pos = atr;
        cout<<a[atr];
        while(ja<na && jb < nb){
          if(a[ja] == b[jb]){
            if(a[ja] <= a[pos] || (a[ja] < b[btr] && a[ja]>a[pos])){
              cout<<a[ja];
              pos = ja;
              ja++;
              jb++;
              if(a[ja] != b[jb]){
                atr = ja;
                if(a[ja]>a[atr]){
                  while(btr<=jb){
                    cout<<b[btr];
                    btr++;
                  }
                }
                break;
              }
              continue;
            }else{
              atr = ja;
              while(btr <= jb){
                cout<<b[btr];
                btr++;
              }
              break;
            }
          }else if(a[ja] > b[jb]){
            btr = jb;
            break;
          }else if(a[ja] < b[jb]){
            atr = ja;
            break;
          }
        }
        if(ja == na){
          atr = ja+1;
        }else if(jb == nb){
          btr = jb+1;
        }
      }
    }
    if(atr >= na){
      while(btr < nb){
        cout<<b[btr];
        btr++;
      }
    }else{
      while(atr < na){
        cout<<a[atr];
        atr++;
      }
    }
    cout<<endl;
  }
}
