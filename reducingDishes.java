// https://leetcode.com/problems/reducing-dishes/

// Really simple problem... just reverse the list

// O(NlogN), beats 65%

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        int ans = 0, temp = 0, counter = 0;
        Arrays.sort(satisfaction);
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            counter += satisfaction[i];
            temp += counter;
            ans = Math.max(ans, temp);
        }
        return ans;
    }
}
