#include <iostream>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int res = 0, x = 0;
    vector<int> l(256, -1);
    for(int i=0; i<n; i++) {
        x = max(x, l[s[i]] + 1);
        res = max(res, i - x + 1);
        l[s[i]] = i;
    }
    return res;
}