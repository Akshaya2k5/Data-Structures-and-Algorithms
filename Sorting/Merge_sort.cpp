#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
     vector<int>res;
     int i=0,j=0;
     
     while(i<left.size() && j<right.size()){
         if(left[i]<=right[j]){
             res.push_back(left[i++]);
         }
         else{
             res.push_back(right[j++]);
         }
     }
     
     while(i<left.size()){
         res.push_back(left[i++]);
     }
     while(j<right.size()){
         res.push_back(right[j++]);
     }
     return res;
 }
 
 vector<int> mergeSort(vector<int>& nums) {
    if(nums.size()<=1)
        return nums;
    int mid=nums.size()/2;
    vector<int>left(nums.begin(),nums.begin()+mid);
    vector<int>right(nums.begin()+mid,nums.end());
    
    left=mergeSort(left);
    right=mergeSort(right);
    
    return merge(left,right);
 }
 
 int main() {
    vector<int> nums = {5, 2, 4, 7, 1, 3};
    vector<int> sorted = mergeSort(nums);

    cout << "Sorted array: ";
    for (int num : sorted)
        cout << num << " ";
    cout << endl;

    return 0;
}
