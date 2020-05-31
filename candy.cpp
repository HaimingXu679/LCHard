// https://leetcode.com/problems/candy/

// Ad-hoc

// O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int number = ratings.size(), big = 0, i;
        int *c = new int[number], *b = new int[number];
        for (i = 0; i < number; i++) 
	    c[i] = 1;
        for (i = 0; i < number; i++) 
	    b[i] = 1;
        for (i = 1; i < number; i++) 
            if (ratings[i - 1] < ratings[i]) 
 	        c[i] = c[i - 1] + 1;
        for (i = number - 2; i >= 0; i--) 
            if (ratings[i + 1] < ratings[i]) 
  	        b[i] = b[i + 1] + 1;
        for (i = 0; i < number; i++)
 	    c[i] = max(c[i], b[i]);
        for (i = 0; i < number; i++) 
            big += c[i];
        return big;
    }
};
