#include "../helper.h"

void insertion_sort(vector<int> &vec) {
    for (int i = 0; i != vec.size(); ++i) {
        for (int j = i; j > 0 && vec[j - 1] > vec[j]; j--) {
            swap(vec[j], vec[j - 1]);
        }
    }
}
void test_insertion_sort(bool flag) {
    if (!flag) return ;
    vector<int> v1{9, 8, 6, 7, 3, 2, 5, 1, 2, 10};
    printVector(v1);
    insertion_sort(v1);
    printVector(v1);
}
int linear_search(vector<int> &vec, int val) {
    for (int i = 0; i != vec.size(); ++i) {
        if (vec[i] == val) {
            return i;
        }
    }
    return -1;
}
void test_linear_search(bool flag) {
    if (!flag) return ;
    vector<int> v1{1, 2, 3, 4, 5, 100, 1000};
    cout << "linear_search(v1, 100)" << linear_search(v1, 100) << endl;
    cout <<  "linear_search(v1, 102)" << linear_search(v1, 102) << endl;
}


/*
XOR 不进位之和
AND 进位和  需要左移一
递归当进位和为0时结束，此时答案为不进位和XOR
*/
int binary_add(int a, int b) {
    if(a == 0) return b;
    int XOR = a ^ b;
    int AND = a & b;
    return binary_add(AND << 1, XOR);
}

void test_binary_add(bool flag) {
    if (!flag) return ;
    int a, b;
    while (cin >> a >> b) {
        cout << a << " + " << b << " = " << binary_add(a, b) << endl;
    }
    cout << "END!!!" << endl;
}
int main()
{
    test_insertion_sort(0);
    test_linear_search(0);
    test_binary_add(0);
    return 0;
}