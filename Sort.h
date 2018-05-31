//
// Created by Liming Shao on 2018/5/22.
//

#ifndef DSAA_SORT_H
#define DSAA_SORT_H

#include <vector>
using namespace std;

class Sort {
public:
    static void test();

    void InsertSort(vector<int> &vec);
    void ShellSort(vector<int> &vec);
    void SelectSort(vector<int> &vec);
    void BubbleSort(vector<int> &vec);
    void QuickSort(vector<int> &vec);
    void HeapSort(vector<int> &vec);
    void MergeSort(vector<int> &vec);

private:
    void QSort(vector<int> &vec, int left, int right);

};


#endif //DSAA_SORT_H
