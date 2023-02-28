#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;
vector<int> VECTOR{4, 3, 2, 6, 5, 7, 8, 10, 1, 9};




void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printVector(vector<int> &vec) {
    for(auto &elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

void RandomVector(vector<int> &vec) {
    for(int i = 0; i < 20; ++i) {
        vec.push_back(rand() % 100);
    }
}


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


// vector<int> VECTOR;
// RandomVector(VECTOR);