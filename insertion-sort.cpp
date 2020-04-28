#include <iostream>
#include <vector>
using namespace std;

class InsertionSort{
    
    public:
    
    void sort(vector<int>& input){
        
        for(int j=1;j<input.size();j++){
        int key = input[j];
        int i = j-1;
        while(i>=0 && input[i]>key){
            input[i+1] = input[i];
            i = i - 1;
        }
        input[i+1] = key;
        }
    }
};

int main()
{
    vector<int> input = {1,4,6,3,2,0};
    InsertionSort ob;
    ob.sort(input);
    for(int i=0;i<input.size();i++){
        cout << input[i] << endl;
    }
    return 0;
}