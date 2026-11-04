#include<iostream>
#include<climits>
using namespace  std;
int main(){
   int nums[] = {12,67,89,32};
   int size = 4;
   int largest = INT_MIN;
   for(int i = 0;i<size;i++){
   if(largest<nums[i]){//smallest = min(nums[i],smallest);
    largest = nums[i];
   }
   cout<<"largest number is="<<largest;
   }
}