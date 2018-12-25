#include<iostream>
using namespace std;
int MaxSubIncArr(int *arr, int length){
    int maxSubLen = 1;
    int index_s=0, index_e=1;
    for(int index_e=1; index_e<length; index_e++){
        if(arr[index_e-1] < arr[index_e]){
            if(maxSubLen < (index_e-index_s+1)){
                maxSubLen = index_e-index_s+1;
            }
        }else{
            index_s = index_e;
        }
    }
    return maxSubLen;
}

int main(void){
    int arr[30];
    int maxSubLen;
    int lens;
    cout<<"insert arr len"<<endl;
    cin>>lens;
    for(int i=0; i<lens; i++){
        cin>>arr[i];
    }
    maxSubLen = MaxSubIncArr(arr, lens);
    cout<<maxSubLen<<endl;
    return 0;
}
