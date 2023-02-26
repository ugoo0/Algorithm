#include "../helper.h"

pair<int, int> tow_sum(vector<int> &vec, int sum) {
    map<int, int> val_idx;
    for (int i = 0; i != vec.size(); ++i) {
        if (val_idx.find(vec[i]) != val_idx.end()) {
            return {val_idx[vec[i]], i};
        }
        val_idx.insert({sum - vec[i], i});
    }
    return {-1, -1};
}
void test1(bool flag) // 两数之和 nlg(n)
{
    if (!flag) return ;
    vector<int> v{1, 3, 4, 7, 11, 24, 12, 13, 44, 100};
    int sum = 0;
    while (cin >> sum) {
        pair<int, int> pr = tow_sum(v, sum);
        cout << pr.first << " , " << pr.second << endl;
    }

}

void merge(vector<int> &vec, int left, int middle, int right, int& rvsCnt) {
    vector<int> tmp(right - left);
    int k = 0, i = left, j = middle;
    while(i < middle && j < right) {
        if(vec[i] <= vec[j]) {
            tmp[k++] = vec[i++]; 
        }
        else {
            tmp[k++] = vec[j++];
            rvsCnt += middle - i;
        }
    }
    while(i < middle) {
        tmp[k++] = vec[i++];
    }
    while(j < right) {
        tmp[k++] = vec[j++];
    }
    for(i = 0, k = left; k < right; ++i, ++k) {
        vec[k] = tmp[i];
    }
}

void reversed_order(vector<int> &vec, int left, int right, int &rvsCnt) {
    if (left >= right - 1) return;
    int middle = left + ((right - left) >> 1);
    reversed_order(vec, left, middle, rvsCnt);
    reversed_order(vec, middle, right, rvsCnt);
    merge(vec, left, middle, right, rvsCnt);
}

void test2(bool flag) // 逆序对 nlg(n)
{
    if(!flag) return ;
    vector<int> v1{5, 4, 3, 2, 1};
    vector<int> v2{1, 2, 3, 4, 5};
    vector<int> v3{1, 3, 5, 2, 4, 6};
    vector<vector<int>> vv;
    vv.push_back(v1), vv.push_back(v2), vv.push_back(v3);
    cout << "begin!!" << endl;
    for(auto &v : vv) {
        printVector(v);
        int rvsCnt = 0;
        reversed_order(v, 0, v.size(), rvsCnt);
        cout << "rvsCnt = " << rvsCnt << endl;
        printVector(v);
    }
    cout << "end!!!" << endl;
}

int main()
{
    test1(0);
    test2(1);
    return 0;
}