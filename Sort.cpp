//
// Created by Liming Shao on 2018/5/22.
//

#include <iostream>
#include <algorithm>
#include "Sort.h"

void Sort::test() {
    Sort ins;
    vector<int> backup = {58, 62, 69, 20, 14, 70, 63, 31, 21, 7, 34};
    vector<int> vec = backup;
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;

    vec = backup;
    ins.InsertSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "InsertSort Pass\n";
    else
        cout << "InsertSort Failed\n";

    vec = backup;
    ins.ShellSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "ShellSort Pass\n";
    else
        cout << "ShellSort Failed\n";

    vec = backup;
    ins.SelectSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "SelectSort Pass\n";
    else
        cout << "SelectSort Failed\n";

    vec = backup;
    ins.BubbleSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "BubbleSort Pass\n";
    else
        cout << "BubbleSort Failed\n";

    vec = backup;
    ins.QuickSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "QuickSort Pass\n";
    else
        cout << "QuickSort Failed\n";

    vec = backup;
    ins.HeapSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "HeapSort Pass\n";
    else
        cout << "HeapSort Failed\n";

    vec = backup;
    ins.MergeSort(vec);
    if(is_sorted(vec.begin(), vec.end()))
        cout << "MergeSort Pass\n";
    else
        cout << "MergeSort Failed\n";
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

void Sort::BubbleSort(vector<int> &vec) {
    for (int i = 0; i < vec.size() -1; ++i) {
        for (int j = 1; j < vec.size() - i; ++j) {
            if (vec[j-1] > vec[j])
                swap(vec[j-1], vec[j]);
        }
    }
}

void Sort::QSort(vector<int> &vec, int left, int right){
    if (left >= right)
        return;

    int t = vec[left];
    int i = left;
    int j = right;
    while(i < j){
        while(vec[j] >= t && i < j)
            j--;

        while(vec[i] <= t && i < j)
            i++;

        if (i < j)
            swap(vec[i], vec[j]);
    }
    swap(vec[i], vec[left]);

    QSort(vec, left, i - 1);
    QSort(vec, i + 1, right);
}

// O(NlogN)
void Sort::QuickSort(vector<int> &vec) {
    QSort(vec, 0, (int)vec.size()-1);
}

void Sort::HeapSort(vector<int> &vec) {

}

void Sort::MergeSort(vector<int> &vec) {

}




