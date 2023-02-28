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

// vector<int> VECTOR;
// RandomVector(VECTOR);