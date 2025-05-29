// Selction Sort Cpp code

#include <iostream>
#include <vector>
using namespace std;

// Selection Sort Function
vector<int> selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[mini])
                mini = j;
        }
        swap(nums[mini], nums[i]);
    }
    return nums;
}

// Main Function
int main() {
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    cout << "Before selection sort:\n";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\n";

    vector<int> sorted = selectionSort(nums);

    cout << "After selection sort:\n";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
