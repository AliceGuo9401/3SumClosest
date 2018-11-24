#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    vector<int> threeSum;
    vector<int> threeSum1;

    for (int i = 0; i < nums.size() - 2; ++i) {
        int temp = nums[i];
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            int temp1 = nums[j];
            for (int k = j + 1; k < nums.size(); ++k) {
                int temp3 = nums[k];
                int temp4 = temp + temp1 + temp3 - target;
                if (0 <= temp4)
                    threeSum.push_back(temp4);
                else if (temp4 < 0)
                    threeSum1.push_back(temp4);
            }
        }
    }
    if (!threeSum.empty())
        sort(threeSum.begin(), threeSum.end()); //sort
    if (!threeSum1.empty())
        sort(threeSum1.begin(), threeSum1.end());

    if (!threeSum.empty() && !threeSum1.empty()) {  //!*.empty()：*非空
        int threeSum1Size = threeSum1.size();
        if (threeSum[0] <= 0 - threeSum1[threeSum1Size - 1])  //负数的值越大，它的绝对值越小，离target越近
            return target + threeSum[0];
        else if (threeSum[0] > 0 - threeSum1[threeSum1Size - 1])
            return target + threeSum1[threeSum1Size - 1];
    }
    else if (!threeSum.empty() && threeSum1.empty())
        return target + threeSum[0];
    else if (threeSum.empty() && !threeSum1.empty()) {
        int threeSum1Size = threeSum1.size();
        return target + threeSum1[threeSum1Size - 1];
    }
}
int main() {
    vector<int> nums{1, 1, 1, 0};
    int target(100);
    int closetSum = threeSumClosest(nums, target);
    cout << closetSum;
    return 0;
}
