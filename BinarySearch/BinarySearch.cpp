// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int compare(T a, T b) {
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
}

template<typename T>
int binary_search(vector<T> list, T search_target, int (*c)(T, T)) {
    // assume the list is ordered.
    int left = 0;
    int right = int(list.size()) - 1;
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        switch (c(list[middle], search_target)) {
        case -1:
            left = middle + 1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle - 1;
        }
    }
}

void bubble_sort(vector<int>& v) {
    int size = int(v.size());
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (v[j - 1] > v[j])
                swap(v[j - 1], v[j]);
        }
    }
}
int main()
{
    vector<int> v = { 4, 6, 3, 9, 2, 1 };
    bubble_sort(v);
    int target = 9;
    int result = binary_search<int>(v, target, compare<int>);
    cout << "search result: " << result << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
