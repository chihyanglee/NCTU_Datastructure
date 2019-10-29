/*
    Knuth-Morris-Pratt Pattern Matching Substring Search
    https://www.youtube.com/watch?v=BXCEFAzhxGY
    https://www.youtube.com/watch?v=dgPabAsTFa8
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getPrefixTable(const string& p) {
    int length = int(p.size());
    vector<int> prefixTable;
    prefixTable.push_back(-1);
    prefixTable.push_back(0);
    int previousIndex, currentIndex = 1;
    while (currentIndex < length - 1) {
        previousIndex = currentIndex - 1;
        int previousTableValue = prefixTable[previousIndex + 1];
        if (p[currentIndex] == p[previousTableValue]) {
            prefixTable.push_back(previousTableValue + 1);
            currentIndex += 1;
            continue;
        }
        currentIndex += 1;
        prefixTable.push_back(0);
    }
    return prefixTable;
}

void kmp_search(const string& s, const string& p) {
    auto prefixTable = getPrefixTable(p);
    int pLength = int(p.size());
    int sLength = int(s.size());
    int i = 0, j = 0;
    while (true) {
        if (i + pLength > sLength) {
            cout << "search over" << endl;
            break;
        }
        if (s[i] == p[j]) {
            i++, j++;
            if (j == pLength) {
                cout << "pattern found! " << endl
                    << "index at " << i - pLength << endl;
            }
            continue;
        }
        j = prefixTable[j];
        if (s[i] != p[j]) {
            i++, j++;
        }
    }
}
int main() {
    string T = "acbbbababbabbabcbaba";
    string p = "ababbab";
    kmp_search(T, p);
}