// find_rank_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int get_pivot(vector<int>&, const int&, const int&);
void quick_sort(vector<int>&, const int&, const int&);
int quick_sort_partition(vector<int>&, const int&, const int&);

// sort all array and find rank
int find_n_largest_sln1(vector<int>, int);
int find_n_largest_sln2(vector<int>, int);
int main()
{
    //vector<int> v { 3, 5, 9, 2, 7, 4, 1, 0 };
    vector<int> v{ 2, 15, 7, 14, 6, 19, 8, 23, 9, 3, 1, 11, 5, 10 };
    auto copy = v;
    cout << "original array: ";
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;
    quick_sort(v, 0, int(v.size()) - 1);
    cout << "sorted array:   ";
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;
    cout << "find rank 3 of array: ";
    int rank = 3;
    int sln1 = find_n_largest_sln1(copy, rank);
    cout << sln1 << endl;
    cout << "find rank 3 of array: ";
    int sln2 = find_n_largest_sln2(copy, rank);
    cout << sln2 << endl;
}
// get middle of three numbers
int get_pivot(vector<int>& v, const int& low, const int& high) {
    // low -- mid -- high
    const int mid = (low + high) / 2;
    const int ml = v[mid] - v[low];
    const int hm = v[high] - v[mid];
    const int lh = v[low] - v[high];

    if (ml * hm > 0)
        return mid;
    if (ml * lh > 0)
        return low;
    return high;
}

void quick_sort(vector<int>& v, const int& low, const int& high) {
    if (low < high) {
        int partition_index = quick_sort_partition(v, low, high);
        quick_sort(v, low, partition_index - 1);
        quick_sort(v, partition_index + 1, high);
    }

}

int quick_sort_partition(vector<int>& v, const int& low, const int& high) {
    int pivot_index = get_pivot(v, low, high);
    const int pivot = v[pivot_index];
    // swap pivot to last position
    swap(v[pivot_index], v[high]);
    pivot_index = low;
    // v[high] is pivot
    for (int i = low; i < high; i++) {
        if (v[i] >= pivot) {
            swap(v[i], v[pivot_index]);
            pivot_index += 1;
        }
    }
    // swap pivot to pivot position
    swap(v[pivot_index], v[high]);
    return pivot_index;
}

int find_n_largest_sln1(vector<int> v, int n) {
    // rank n => index n - 1
    quick_sort(v, 0, int(v.size()) - 1);
    return v[n - 1];
}

int find_n_largest_sln2(vector<int> v, int n) {
    // rank n => index n - 1
    int rank_index = n - 1;
    quick_sort(v, 0, rank_index);
    int size = int(v.size());
    for (int i = n; i < size; i++) {
        if (v[i] > v[rank_index]) {
            swap(v[i], v[rank_index]);
            int j = rank_index;
            while (j != 0 && v[j] > v[j - 1]) {
                swap(v[j], v[j - 1]);
                j--;
            }
        }
    }
    return v[rank_index];
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
