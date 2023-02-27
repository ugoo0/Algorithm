#include <iostream>
#include <vector>
#include "../helper.h"
using namespace std;

vector<int> maximun_subarray(vector<int> vec) {
    if(vec.empty()) return {-1, -1, -1};
    int maxSum = INT32_MIN;
    int i = 0, j = 0;
    int left = 0, right = 0;
    int sum = vec[0];
    while(++j < vec.size()) {
        sum = sum + vec[j];
        if(sum > maxSum) {
            maxSum = sum;
            left = i, right = j;
        }
        while(i < j && sum < 0) {
            sum -= vec[i++];
            // if(sum > maxSum) {
            //     maxSum = sum;
            //     left = i, right = j;
            // }
        }
    }
    return {left, right, maxSum};
}
vector<int> midMaxSubarray(vector<int>& vec, int left, int mid, int right) {
    int left_sum = INT32_MIN;
    int sum = 0;
    int max_left = mid, max_right = mid;
    for(int i = mid - 1; i >= left; --i) {
        sum = sum + vec[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT32_MIN;
    sum = 0;
    for(int i = mid; i < right; ++i) {
        sum += vec[i];
        if(sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    return {max_left, max_right, left_sum + right_sum};
}

vector<int> maximumSubarray(vector<int> &vec, int left, int right) {
    if(left >= right - 1) return {left, right, vec[left]};
    int mid = left + ((right - left) >> 1);
    vector<int> low = maximumSubarray(vec, left, mid);
    vector<int> high = maximumSubarray(vec, mid, right);
    vector<int> mm = midMaxSubarray(vec, left, mid, right);
    if(low[2] >= high[2] && low[2] >= mm[2]) {
        return low;
    }
    else if(high[2] >= low[2] && high[2] >= mm[2]) {
        return high;
    }
    return mm;
}

void test1(bool flag) {
    if(!flag) return ;
    vector<int> vec{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    vector<int> res = maximumSubarray(vec, 0, vec.size());
    printVector(res);
}
void test2(bool flag) {
    if(!flag) return ;
    vector<int> vec{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    // vector<int> vec{1, -2, 1, 1, -1, 3, -2, 5, -4, 6, -9};
    vector<int> res = maximun_subarray(vec);
    printVector(res);
}

int main()
{
    test1(0);
    test2(1);
    return 0;
}