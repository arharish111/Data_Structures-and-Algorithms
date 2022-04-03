#include <bits/stdc++.h>
using namespace std;

int no_attack(vector<int>& data,int r){
    int r1 = r;
    int c1 = data[r];
    for(int c=0;c<r;c++){
        int r2 = c;
        int c2 = data[c];
        if(r1==r2){
            return 0;
        }
        else if(c1==c2){
            return 0;
        }
        else if(abs(r1-r2)==abs(c1-c2)){
            return 0;
        }
    }
    return 1;
}

void printBoard(vector<int>& data){
    cout << "Board:" << endl;
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data.size();j++){
         if(data[i]==j){
             cout << " Q ";
         }
         else
            cout << " 0 ";
        }
        cout << endl;
    }
}

void queens(int r,vector<int>& data,int N){
    if(r>=N){
        printBoard(data);
        return;
    }
    for(int c=0;c<N;c++){
        data[r] = c;
        if(no_attack(data,r)==1){
            queens(r+1,data,N);
        }
    }
}

int main(){
    int N = 4;
    vector<int> data(N,-1);
    queens(0,data,N);
    return 0;
}