#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j]) {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}

int main() {
    vector<int> nums = {5, 2, 4, 6, 1, 3};

    cout << "Original vector: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    insertion_sort(nums);

    cout << "Sorted vector:   ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
