#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();  // ✅ Use full size
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 4, 4, 1, 1};

    cout << "Before bubble sort:\n";
    for (int num : nums) cout << num << " ";
    cout << "\n";

    vector<int> sorted = sol.bubbleSort(nums);

    cout << "After bubble sort:\n";
    for (int num : sorted) cout << num << " ";
    cout << "\n";

    return 0;
}
