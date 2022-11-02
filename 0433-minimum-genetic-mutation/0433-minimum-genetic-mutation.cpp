class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,bool> used;
        for (auto& b : bank) used[b] = false;

        string choices = "ACGT";
        int n = start.size(), m = choices.size();

        queue<string> q;
        q.push(start);
        int ans = 0;
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                auto gene = q.front();
                q.pop();

                if(gene == end)
                    return ans;

                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < m; jj++) {
                        char original = gene[ii];
                        gene[ii] = choices[jj];
                        if (used.find(gene) != used.end() and !used[gene]) {
                            used[gene] = true;
                            q.push(gene);
                        }
                        gene[ii] = original;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};