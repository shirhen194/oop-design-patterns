#include <string>
#include <iostream>

using namespace std;

//interface
template<class Comparable> class Sorter{
public:
    virtual void sort(Comparable* comparables, int size) = 0;
    //virtual void createEnemy(const Position &pos) = 0;
};

//abstract class
template<class Comparable> class BubbleSorter : public Sorter<Comparable> {
public:
    void sort(Comparable* comparables, int size) override {
        int i, j;
        for (i = 0; i < size-1; i++) {
            for (j = i + 1; j < size - 1; j++) {
                if (comparables[i+1] < comparables[i]){
                    Comparable* tmp = comparables[i];
                    comparables[i] = comparables[i + 1];
                    comparables[i + 1] = tmp;
                }
            }
        }
    };
};

////bubble sort class
//class intBubbleSorter : public Sorter<int> {
//public:
//    void sort(int** numbers) override {
//        int i, j, temp;
//        for (i = 0; i < 10; i++) {
//            for (j = i + 1; j < 10; j++) {
//                if (numbers[j] < numbers[i]) {
//                    temp = numbers[i];
//                    numbers[i] = numbers[j];
//                    numbers[j] = numbers;
//                }
//            }
//        }
//    };
//    //virtual void createEnemy(const Position &pos) = 0;
//};