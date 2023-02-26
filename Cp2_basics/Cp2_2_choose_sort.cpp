#include "../helper.h"

void choose_sort (vector<int> &vec) {
    for (int i = 0; i != vec.size(); ++i) {
        int MinIdx = i;
        for (int j = i; j != vec.size(); ++j) {
            if (vec[MinIdx] > vec[j]) {
                MinIdx = j;
            }
        }
        swap(vec[MinIdx], vec[i]);
    }
}
void bubble_sort(vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        for(int j = 0; j < (vec.size() - i - 1); ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}
void test_bubble_sort(bool flag) {
    if (!flag) return ;
    printVector(VECTOR);
    bubble_sort(VECTOR);
    printVector(VECTOR);
}
void test_choose_sort(bool flag) {
    if (!flag) return ;
    printVector(VECTOR);
    choose_sort(VECTOR);
    printVector(VECTOR);
}

int main(int argc, char** argv) {
    test_choose_sort(0);
    test_bubble_sort(0);
    return 0;
}