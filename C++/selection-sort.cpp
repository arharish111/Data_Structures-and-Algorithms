#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> input = {1,4,5,3,2,0};
    int minIndex;
    for(int j=0;j<input.size();j++){
        minIndex = j;
        for(int i=j+1;i<input.size();i++){
            if(input[i]<input[minIndex]){
                minIndex = i;
            }
        }
        int temp = input[j];
        input[j] = input[minIndex];
        input[minIndex] = temp;
    }
    for(int i=0;i<input.size();i++){
        cout << input[i] << endl;
    }
    return 0;
}