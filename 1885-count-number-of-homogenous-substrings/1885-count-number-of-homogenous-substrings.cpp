class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int curr = 0;

        int n = s.size();
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || s[i] == s[i - 1])
            curr++;
            else curr = 1;

            answer = (answer + curr) % mod;
        }

        return answer;
    }
};