class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq;

        // Insert all stones into the max-heap
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }

        // Smash the two heaviest stones
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            // If weights differ, push the difference back
            if (a != b) {
                pq.push(a - b);
            }
        }

        // Return the remaining stone's weight
        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};