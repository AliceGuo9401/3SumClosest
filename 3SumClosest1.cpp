#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int leftClosestDis(0), rightClosestDis(0);
    int leftFlag(0), rightFlag(0);  //leftFlag == 1：存在小于target的值，rightFlag == 1：存在大于target的值
    for (int i = 0; i < nums.size() - 2; ++i) {
        int a(nums[i]);
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            int b(nums[j]);
            for (int k = j + 1; k < nums.size(); ++k) {
                int c(nums[k]);
                int threeSum = a + b + c;
                if (threeSum < target) {
                    if (leftFlag == 0)
                        leftClosestDis = target - threeSum;
                    else if(leftFlag == 1)
                        leftClosestDis = min(leftClosestDis, target - threeSum);
                    leftFlag = 1;
                }
                else if (threeSum == target)
                    return target;
                else if (target < threeSum) {
                    if (rightFlag == 0)
                        rightClosestDis = threeSum - target;
                    else if(rightFlag == 1)
                        rightClosestDis = min(rightClosestDis, threeSum - target);
                    rightFlag = 1;
                }
            }
        }
    }
    /*leftFlag == 1：存在小于target的值，rightFlag == 1：存在大于target的值*/
    if ((leftFlag == 1 && rightFlag == 0) || (leftClosestDis < rightClosestDis && leftFlag == 1 && rightFlag == 1) )
        return target - leftClosestDis;
    else if ((leftFlag == 0 && rightFlag == 1) || (leftClosestDis > rightClosestDis && leftFlag == 1 && rightFlag == 1))
        return target + rightClosestDis;
}
int main() {
    vector<int> nums{0, 0, 0};
    int target = 1;
    int closestValue = threeSumClosest(nums, target);
    cout << closestValue;
    return 0;
}
