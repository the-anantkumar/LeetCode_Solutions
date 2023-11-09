class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        vector<pair<int, char>> need;

        for(auto x: s)
        {
            m[x]++;
        }

        for(auto x: s)
        {
            need.push_back({m[x], x});
        }

        sort(need.rbegin(), need.rend());

        string answer = "";

        for(auto x: need)
        {
            answer += x.second;
        }

        return answer;
    }
};