#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    // Call the function and print the result
    int result = solution.singleNumber(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}
