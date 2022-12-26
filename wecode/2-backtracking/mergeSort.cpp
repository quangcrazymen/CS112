#include <iostream>

using namespace std;


void merge(int *array,int left,int mid,int right){
    // use different array
    int temp[100];
    int rightP = mid+1;
    int i=0;
    while(left<mid & rightP<right){
        if(array[left]>=array[rightP]){
            temp[i++]=array[rightP];
            rightP++;
        }
        else{
            temp[i++] = array[left];
            left++;
        }
    }
    // add the remaining elements
    for(int index=left;index<=mid;index++){
        temp[i++]=array[index];
    }
    for(int index=rightP;index<=right;index++){
        temp[i++]=array[index];
    }
    for(int index;index<right;index++){
        array[index]=temp[index];
    }
    
} 

void mergeSort(int *array,int left,int right){
    if(left>right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(array,left,mid);
    mergeSort(array,mid+1,right);
    merge(array,left,mid,right);
}
 

int main(){
    int array[100]{12,25,1,3,235,67,45,23,10,14,9};
    int toy[6]{12,23,46,1,2,3};
    merge(toy,0,2,6);
    mergeSort(array,0,11);
    for(int i=0;i<11;i++){
        cout<<array[i]<<endl;
    }
}