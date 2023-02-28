#include "../helper.h"

 
int partition(vector<int> &vec, int left, int right) {
    int pivot = vec[right - 1];
    int i = left - 1;
    for (int j = left; j < right - 1; ++j) {
        if (vec[j] <= pivot) {
            i = i + 1;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[right - 1]);
    return i + 1;
}

int randomized_partition(vector<int> &vec, int left, int right) {
    int p = rand()%(right - left) + left;
    swap(vec[p], vec[right - 1]);
    return partition(vec, left, right);
}

void quick_sort(vector<int> &vec, int left, int right) {
    if(left >= right - 1) return ;
    int p = partition(vec, left, right);
    quick_sort(vec, left, p);
    quick_sort(vec, p, right);
}
void randomize_quickSort(vector<int> &vec, int left, int right) {
    if(left >= right - 1) return ;
    int p = randomized_partition(vec, left, right);
    randomize_quickSort(vec, left, p);
    randomize_quickSort(vec, p, right);
}
void test(bool flag) {
    if(!flag) return ;
    vector<int> vec = VECTOR;
    cout << "quickSort!!!"<< endl;
    printVector(VECTOR);
    quick_sort(VECTOR, 0, VECTOR.size());
    printVector(VECTOR);
    cout << "RRRandomize_quickSort!!!"<< endl;
    printVector(vec);
    quick_sort(vec, 0, vec.size());
    printVector(vec);

}
int main() {
    srand(time(0));
    test(1);
    return 0;
}