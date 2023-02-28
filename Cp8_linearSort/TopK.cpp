#include "helper.h"

pair<int, int> find_max_min(vector<int>& vec) {
    if(vec.empty()) return {-1, -1};
    if(vec.size() == 1) return {vec[0], vec[0]};
    int MIN = INT32_MAX, MAX = INT32_MIN;
    for(int i = 0, j = 1; j < vec.size(); i += 2, j += 2) {
        if(vec[i] < vec[j]) {
            MIN = vec[i] < MIN ? vec[i] : MIN;
            MAX = vec[j] > MAX ? vec[j] : MAX;
        }
        else {
            MIN = vec[j] < MIN ? vec[j] : MIN;
            MAX = vec[i] > MAX ? vec[i] : MAX;
        }
    }
    return {MIN, MAX};
}
void test_max_min(bool flag) {
    if(!flag) return ;
    printVector(VECTOR);
    auto res = find_max_min(VECTOR);
    cout << "MIN = " << res.first << " MAX = " << res.second << endl;
}

int randomize_partition(vector<int> &vec, int left, int right) {
    int rp = rand() % (right - left) + left;
    swap(vec[rp], vec[right - 1]);
    int i = left - 1;
    for(int j = left; j < right - 1; ++j) {
        if(vec[j] <= vec[right - 1]) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[right - 1]);
    return i + 1;
}

int TopK(vector<int> &vec, int left, int right, int k) {
    if(left >= right - 1) return vec[left];
    int p = randomize_partition(vec, left, right);
    if(right - p >= k) {
        return TopK(vec, p, right, k);
    }
    else {
        return TopK(vec, left, p, k - (right - p));
    }
}

void test_TopK(bool flag) {
    if(!flag) return ;
    
    while(true) {
        int k = 0;
        vector<int> tmp = VECTOR;
        printVector(tmp);
        cin >> k;
        cout << "top k is " << TopK(tmp, 0, tmp.size(), k) << endl;
        heap_sort(tmp);
        printVector(tmp);
    }
}
int main(int argc, char **argv) {
    RandomVector(VECTOR);
    test_max_min(0);
    test_TopK(1);
    return 0;
}