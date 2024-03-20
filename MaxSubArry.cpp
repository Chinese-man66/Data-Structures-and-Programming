#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, int, int> max_crossing_subarray(const vector<int>& nums, int low, int mid, int high) 
{
    int left_sum = -1e9;
    int sum = 0;
    int max_left = mid;
    for (int i = mid; i >= low; --i) 
    {
        sum += nums[i];
        if (sum > left_sum) 
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -1e9;
    sum = 0;
    int max_right = mid + 1;
    for (int j = mid + 1; j <= high; ++j) 
    {
        sum += nums[j];
        if (sum > right_sum) 
        {
            right_sum = sum;
            max_right = j;
        }
    }

    return make_tuple(max_left, max_right, left_sum + right_sum);
}

tuple<int, int, int> max_subarray(const vector<int>& nums, int low, int high) 
{
    if (low == high)
        return make_tuple(low, high, nums[low]);

    int mid = (low + high) / 2;

    auto [left_low, left_high, left_sum] = max_subarray(nums, low, mid);
    auto [right_low, right_high, right_sum] = max_subarray(nums, mid + 1, high);
    auto [cross_low, cross_high, cross_sum] = max_crossing_subarray(nums, low, mid, high);

    if (left_sum >= right_sum && left_sum >= cross_sum)
        return make_tuple(left_low, left_high, left_sum);
    else if (right_sum >= left_sum && right_sum >= cross_sum)
        return make_tuple(right_low, right_high, right_sum);
    else
        return make_tuple(cross_low, cross_high, cross_sum);
}

tuple<int, int, int> find_max_subarray(const vector<int>& nums) 
{
    return max_subarray(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto [left, right, sum] = find_max_subarray(nums);
    cout << "最大子數組的左下標: " << left << endl;
    cout << "最大子數組的右下標: " << right << endl;
    cout << "最大子數組的和: " << sum << endl;

    return 0;
}
