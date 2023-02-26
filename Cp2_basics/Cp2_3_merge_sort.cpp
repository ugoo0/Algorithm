#include "../helper.h"

void merge(vector<int> & vec, int left, int middle, int right) {
    vector<int> tmp(right - left);
    int k = 0, i = left, j = middle;
    while (i < middle && j < right) {
        if(vec[i] < vec[j]) {
            tmp[k++] = vec[i++];
        } else {
            tmp[k++] = vec[j++];
        }
    }
    while (i < middle) {
        tmp[k++] = vec[i++];
    }
    while (j < right) {
        tmp[k++] = vec[j++];
    }
    for (i = 0,k = left; k < right; ++k, ++i) {
        vec[k] = tmp[i];
    }
}

void merge_sort(vector<int> &vec, int left, int right) {
    if (left >= right - 1) return ;
    int middle = left + ((right - left) >> 1);
    merge_sort(vec, left, middle);
    merge_sort(vec, middle, right);
    merge(vec, left, middle, right);
}

void test_merge_sort(bool flag) {
    if (!flag) return ;
    printVector(VECTOR);
    merge_sort(VECTOR, 0, VECTOR.size());
    printVector(VECTOR);
}

int binary_search(vector<int> &vec, int left, int right, int val) {
    if (left >= right) return -1;
    int mid = left + ((right - left) >> 1);
    if (vec[mid] < val) {
        return binary_search(vec, mid + 1, right, val);
    } else if (vec[mid] > val) {
        return binary_search(vec, left, mid, val);
    }
    return mid;
}

void test_binary_search(bool flag) {
    if (!flag) return ;
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 13, 14, 17, 18, 22, 100, 150};
    int val = 0;
    while (cin >> val) {
        cout << "the index is " << binary_search(v1, 0, v1.size(), val) << endl;
    }
}

void insertion_sort(vector<int> &vec, int size) {
    if (size <= 1) return ;
    insertion_sort(vec, size - 1);
    for (int i = size - 1; i > 0; --i) {
        if (vec[i - 1] > vec[i]) {
            swap(vec[i], vec[i - 1]);
        }
    }
}
void test_insertion_sort(bool flag) {
    if (!flag) return ;
    printVector(VECTOR);
    insertion_sort(VECTOR, VECTOR.size());
    printVector(VECTOR);
}

int main()
{
    test_merge_sort(0);
    test_insertion_sort(0);
    test_binary_search(1);
    return 0;
}