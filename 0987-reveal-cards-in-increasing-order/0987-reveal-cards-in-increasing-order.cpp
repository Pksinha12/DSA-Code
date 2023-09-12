class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        int n = deck.size();
        vector<int> ans(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }
        sort(deck.begin(), deck.end());
        for (int j = 0; j < n; j++)
        {
            ans[q.front()] = deck[j];
            q.pop();
            if (q.size() > 0) 
            {
                int frnt = q.front();
                q.pop();
                q.push(frnt); 
            }
        }
        return ans;
    }
};