class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int firstIdx = -1;
        int lastIdx = -1;

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        // Minimum distance
        int mind = INT_MAX;
        // Previous critical point
        int f = -1;
        // Current critical point
        int s = -1;
        while (c != NULL) {
            // Check whether b is a critical point
            // Local maximum OR local minimum
            if ((b->val > a->val && b->val > c->val) ||
                (b->val < a->val && b->val < c->val)) {

                // First critical point
                if (firstIdx == -1) {
                    firstIdx = idx;
                }
                else {
                    // This is another critical point
                    lastIdx = idx;
                }
                // Calculate minimum distance
                f = s;
                s = idx;

                if (f != -1) {
                    int d = s - f;
                    mind = min(mind, d);
                }
            }
            // Move the three pointers
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }

        // Fewer than two critical points
        if (lastIdx == -1) {
            return {-1, -1};
        }
        // Maximum distance = last critical - first critical
        int maxd = lastIdx - firstIdx;

        return {mind, maxd};
    }
};