#include <iostream>
#include "Sort.h"
#include "Tree.h"
#include "LinkedList.h"

class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        int ret = 0;

//        if (x > (1<<31)-1){
            printf("X = %d\n", x);
//        }

        if (x < 0) {
            flag = -1;
            x *= -1;
        }

        while (x / 10) {
            ret = (x%10)+10*ret;
            x = x/10;
        }


        ret = ret*10 + x;

        if (ret >> 31)
            return 0;


        ret *= flag;

        return ret;
    }
};

int main() {
    std::cout << "start." << std::endl;
//    Tree::testTree();
//    Sort::test();
//    LinkedList::test();

    Solution solution;
    std::cout << solution.reverse(-1234567890);
    return 0;
}