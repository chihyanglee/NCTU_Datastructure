/*
    Knuth-Morris-Pratt Pattern Matching Substring Search
    https://www.youtube.com/watch?v=BXCEFAzhxGY
    https://www.youtube.com/watch?v=dgPabAsTFa8
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void getPrefixTable(const string& p) {
    int length = int(p.size());
    vector<int> prefixTable;
    prefixTable.push_back(-1);
    prefixTable.push_back(0);
    int previousIndex, currentIndex = 1;
    while (currentIndex < length - 1) {
        previousIndex = currentIndex - 1;
        int previousTableValue = prefixTable[previousIndex];
        if (p[currentIndex] == p[previousTableValue]) {
            prefixTable.push_back(previousTableValue + 1);
            currentIndex += 1;
            continue;
        }
        currentIndex += 1;
        prefixTable.push_back(0);
    }
    for (auto s : prefixTable) {
        cout << s << " ";
    }
}
int main() {
    string T = "abaacababcac";
    string p = "ababbab";
    getPrefixTable(p);
}