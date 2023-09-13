class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, pair<int, vector<int>>> m;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++)
        {
            m[groupSizes[i]].first++;
            m[groupSizes[i]].second.push_back(i);
        }

        vector<vector<int>> answer;

        for(auto x: m)
        {
            vector<int> temp;
            for(auto idx: m[x.first].second)
            {
                temp.push_back(idx);
                if(temp.size() == x.first)
                {
                answer.push_back(temp);
                temp.clear();
                }
            }
        }

        return answer;

    }
};