#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

template <typename T>
class MaxSubarrayFinder {
public:
    tuple<int, int, T> findMaxSubarray(const vector<T>& nums) {
        return maxSubarray(nums, 0, nums.size() - 1);
    }

private:
    tuple<int, int, T> maxCrossingSubarray(const vector<T>& nums, int low, int mid, int high) {
        T left_sum = numeric_limits<T>::lowest();
        T sum = 0;
        int max_left = mid;
        for (int i = mid; i >= low; --i) {
            sum += nums[i];
            if (sum > left_sum) {
                left_sum = sum;
                max_left = i;
            }
        }

        T right_sum = numeric_limits<T>::lowest();
        sum = 0;
        int max_right = mid + 1;
        for (int j = mid + 1; j <= high; ++j) {
            sum += nums[j];
            if (sum > right_sum) {
                right_sum = sum;
                max_right = j;
            }
        }
        return make_tuple(max_left, max_right, left_sum + right_sum);
    }

    tuple<int, int, T> maxSubarray(const vector<T>& nums, int low, int high) {
        if (low == high)
            return make_tuple(low, high, nums[low]);

        int mid = (low + high) / 2;
        auto [left_low, left_high, left_sum] = maxSubarray(nums, low, mid);
        auto [right_low, right_high, right_sum] = maxSubarray(nums, mid + 1, high);
        auto [cross_low, cross_high, cross_sum] = maxCrossingSubarray(nums, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum)
            return make_tuple(left_low, left_high, left_sum);
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return make_tuple(right_low, right_high, right_sum);
        else
            return make_tuple(cross_low, cross_high, cross_sum);
    }
};

int main() {
    cout << "2125120058 申顺琦" << endl;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 3, -6, 5, 6, -4, 1, -2, 4, -1, -2, 7};
    vector<double> nums2 = {1.5, -2.3, 3.0, -4.5, 5.2, 6.1, -7.8, 8.9, -9.0, 0.2, -1.1, 2.2, -3.3, 4.4, -5.5, 6.6, -7.7, 8.8, 9.9};

    MaxSubarrayFinder<int> finder1;
    auto [left1, right1, sum1] = finder1.findMaxSubarray(nums);
    cout << "整数数组nums最大子数组的左下标: " << left1 << endl;
    cout << "整数数组nums最大子数组的右下标: " << right1 << endl;
    cout << "整数数组nums最大子数组的和: " << sum1 << endl;

    MaxSubarrayFinder<double> finder2;
    auto [left2, right2, sum2] = finder2.findMaxSubarray(nums2);
    cout << "浮点数数组nums2最大子数组的左下标: " << left2 << endl;
    cout << "浮点数数组nums2最大子数组的右下标: " << right2 << endl;
    cout << "浮点数数组nums2最大子数组的和: " << sum2 << endl;

    return 0;
}