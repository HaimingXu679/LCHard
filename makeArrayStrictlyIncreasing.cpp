// https://leetcode.com/problems/make-array-strictly-increasing/

// Altered knapsack with memoization

class Solution {
public:
    set<int> all;
    map<long long, int> mem;
    const long long LARGE = 100000000;
    
    int knap(vector<int>& arr1, vector<int>& arr2, int i, int prev, int counter) {
        set<int>::iterator it;
        bool del = all.find(prev) == all.end();
        all.insert(prev);
        it = all.find(prev);
        it++;
        bool temp = it != all.end();
        long long val = temp ? *(it) : 0x7fffffff;
        if (del)
            all.erase(prev);
        if (arr1[i] <= prev) {
            if (i == arr1.size() - 1) {
                mem[i * LARGE + prev] = temp ? counter + 1 : 0x7fffffff;
                return mem[i * LARGE + prev];
            }
            int temp2 = mem[(i + 1) * LARGE + val] > 0 ? 
                mem[(i + 1) * LARGE + val] : knap(arr1, arr2, i + 1, val, counter + 1);
            mem[i * LARGE + prev] = temp ? temp2 : 0x7fffffff;
            return temp ? temp2 : 0x7fffffff;
        }
        if (i == arr1.size() - 1) {
            mem[i * LARGE + prev] = counter;
            return counter;
        }
        int temp2 = mem[(i + 1) * LARGE + arr1[i]] > 0 ? mem[(i + 1) * LARGE + (long long) arr1[i]] : 
            knap(arr1, arr2, i + 1, arr1[i], counter), temp3 = mem[(i + 1) * LARGE + val] > 0 ? 
                mem[(i + 1) * LARGE + val] : knap(arr1, arr2, i + 1, val, counter + 1);
        mem[i * LARGE + prev] = min(temp2, temp3);
        return mem[i * LARGE + prev];
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < arr2.size(); i++)
            all.insert(arr2[i]);
        int temp = knap(arr1, arr2, 0, -1, 0);
        return temp == 0x7fffffff ? -1 : temp;
    }
};
