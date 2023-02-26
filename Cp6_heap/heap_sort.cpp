#include "../helper.h"

void heapify(vector<int> &vec, int idx, int size) {
    if(idx >= size) return ;
    int nextIdx = idx;
    if(idx*2 + 1 < size && vec[idx*2 + 1] > vec[nextIdx]) {
        nextIdx = idx*2 + 1;
    }
    if(idx*2 + 2 < size && vec[idx*2 + 2] > vec[nextIdx]) {
        nextIdx = idx*2 + 2;
    }
    if (idx != nextIdx) {
        swap(vec[idx], vec[nextIdx]);
        heapify(vec, nextIdx, size);
    }
    
}

void build_max_heap(vector<int> &vec) {
    for(int i = vec.size() / 2; i >= 0; --i) {
        heapify(vec, i, vec.size());
    }
}

void heap_sort(vector<int> &vec) {
    build_max_heap(vec);
    printVector(vec);
    int size = vec.size();
    for(int i = vec.size() - 1; i >= 0; --i) {
        swap(vec[0], vec[i]);
        heapify(vec, 0, --size);
    }
}

void test_heap_sort(bool flag) {
    if(!flag) return ;
    printVector(VECTOR);
    heap_sort(VECTOR);
    printVector(VECTOR);
}

int main() {
    test_heap_sort(1);
    return 0;
}


