#include "../helper.h"

int findMax(vector<int> &vec) {
    int res = INT32_MIN;
    for(auto &e : vec) {
        res = e > res ? e : res; 
    }
    return res + 1;
}
void countingSort(vector<int> &vec) {
    int size = vec.size();
    int MAX = findMax(vec);
    cout << MAX << endl;
    vector<int> count(MAX);
    vector<int> res(size);
    for(auto &e : vec) {
        count[e]++;
    }
    for(int i = 1; i < MAX; ++i) {

        count[i] += count[i - 1];
    }
    printVector(count);
    for(int i = size - 1; i >= 0; --i) {
        res[count[vec[i]] - 1] = vec[i];
        count[vec[i]] = count[vec[i]] - 1;
    }
    vec = res;
}
void test(bool flag) {
    if(!flag) return ;
    printVector(VECTOR);
    countingSort(VECTOR);
    printVector(VECTOR);
}
int main() {
    test(1);
    return 0;
}