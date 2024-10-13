//good question I took some time and finally taken minute help from GPT

class Solution {
public:
    int sum(int x, set<pair<int,int>> &s) {
        int ans = 0;
        auto it = s.rbegin();
        for (int i = 0; i < x && it != s.rend(); i++, ++it) {
            ans += (it->first * it->second);
        }
        return ans;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> m;
        set<pair<int, int>> s;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            if (m.find(nums[i]) != m.end()) {
                s.erase({m[nums[i]], nums[i]});  // Erase old frequency
            }
            m[nums[i]]++;  // Increment frequency
            s.insert({m[nums[i]], nums[i]});  // Insert updated frequency
        }

        vector<int> ans;
        ans.push_back(sum(x, s));  // Calculate x-sum for the first window

        int n = nums.size();

        // Sliding window process
        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            if (m[nums[i - k]] > 0) {
                s.erase({m[nums[i - k]], nums[i - k]});  // Erase old frequency
                m[nums[i - k]]--;  // Decrement frequency
                if (m[nums[i - k]] > 0) {
                    s.insert({m[nums[i - k]], nums[i - k]});  // Reinsert with updated frequency
                }
            }

            // Add the new element coming into the window
            if (m[nums[i]] > 0) {
                s.erase({m[nums[i]], nums[i]});  // Erase old frequency
            }
            m[nums[i]]++;
            s.insert({m[nums[i]], nums[i]});  // Insert new frequency

            // Calculate x-sum for the current window
            ans.push_back(sum(x, s));
        }

        return ans;
    }
};