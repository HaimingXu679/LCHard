class Solution {
public:
    int getDistance(char letter1, char letter2, unordered_map<char, pair<int, int> >& coordinates) {
        return letter2 > 'Z' ? 0 : abs(coordinates[letter1].first - coordinates[letter2].first) + abs(coordinates[letter1].second - coordinates[letter2].second);
    }

    int minimumDistance(string word) {
        unordered_map<char, pair<int, int> > coordinates;
        long long dp[27][27][300], ans = 0x7fffffff;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 6; j++) coordinates['A' + i * 6 + j] = make_pair(i, j);
        for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) for (int k = 0; k < word.length(); k++) dp[i][j][k] = 0x7fffffff;
        dp[word[0] - 'A'][26][0] = dp[26][word[0] - 'A'][0] = 0;
        for(int i = 1; i < word.length(); i++) {
            for (int j = 0; j < 27; j++) {
                for (int k = 0; k < 27; k++) {
                    dp[word[i] - 'A'][k][i] = min(dp[word[i] - 'A'][k][i], dp[j][k][i - 1] + getDistance(word[i], 'A' + j, coordinates));
                    dp[j][word[i] - 'A'][i] = min(dp[j][word[i] - 'A'][i], dp[j][k][i - 1] + getDistance(word[i], 'A' + k, coordinates));
                    ans = i == word.length() - 1 ? min(ans, min(dp[word[i] - 'A'][k][i], dp[j][word[i] - 'A'][i])) : ans;
                }
            }
        }
        return ans;
    }
};
