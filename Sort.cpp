//
// Created by Liming Shao on 2018/5/22.
//

#include <iostream>
#include "Sort.h"

void Sort::test() {
    Sort ins;
    vector<int> backup = {58, 62, 69, 20, 14, 70, 62, 31, 21, 7, 34};
    vector<int> vec = backup;
    vector<int> exp = {7, 14, 20, 21, 31, 34, 58, 62, 62, 69, 70};
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;

    ins.InsertSort(vec);
    if(vec == exp)
        cout << "InsertSort Pass\n";
    else
        cout << "InsertSort Failed\n";

    vec = backup;
    ins.ShellSort(vec);
    if(vec == exp)
        cout << "ShellSort Pass\n";
    else
        cout << "ShellSort Failed\n";

    vec = backup;
    ins.SelectSort(vec);
    if(vec == exp)
        cout << "SelectSort Pass\n";
    else
        cout << "SelectSort Failed\n";

    vec = backup;
    ins.HeapSort(vec);
    if(vec == exp)
        cout << "HeapSort Pass\n";
    else
        cout << "HeapSort Failed\n";

    vec = backup;
    ins.BubbleSort(vec);
    if(vec == exp)
        cout << "BubbleSort Pass\n";
    else
        cout << "BubbleSort Failed\n";

    vec = backup;
    ins.QuickSort(vec);
    if(vec == exp)
        cout << "QuickSort Pass\n";
    else
        cout << "QuickSort Failed\n";

    vec = backup;
    ins.MergeSort(vec);
    if(vec == exp)
        cout << "MergeSort Pass\n";
    else
        cout << "MergeSort Failed\n";

    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;

}

// O(N^2)
void Sort::InsertSort(vector<int> &vec) {
    int i, j;
    int t;
    for (i = 1; i < vec.size(); ++i) {
        t = vec[i];
        for (j = i; j > 0 && vec[j-1] > t; --j) {
                vec[j] = vec[j-1];
        }
        vec[j] = t;
    }
}

// O(N^2)
void Sort::ShellSort(vector<int> &vec) {
    int i, j, inc;
    int t;
    for (inc = (int)vec.size()/2;  inc > 0; inc /= 2) {
        for (i = inc; i < vec.size(); ++i){
            t = vec[i];
            for (j = i; j >= inc && vec[j-inc] > t; j -= inc){
                    vec[j] = vec[j-inc];
            }
            vec[j] = t;
        }
    }
}

void Sort::SelectSort(vector<int> &vec) {
    int min;
    for (int i = 0; i < vec.size(); ++i) {
        min = i;
        for (int j = i+1; j < vec.size(); ++j) {
            if (vec[j] < vec[min])
                min = j;
        }
        if (min != i)
            swap(vec[i], vec[min]);
    }
}

void Sort::HeapSort(vector<int> &vec) {


}

void Sort::BubbleSort(vector<int> &vec) {

}

void Sort::QuickSort(vector<int> &vec) {

}

void Sort::MergeSort(vector<int> &vec) {

}




