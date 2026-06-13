class Solution {
public:
    vector<int> nse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = n;      // IMPORTANT
            } else {
                res[i] = st.top();
            }

            st.push(i);
        }

        return res;
    }

    vector<int> pse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = -1;     // IMPORTANT
            } else {
                res[i] = st.top();
            }

            st.push(i);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> right = nse(heights);
        vector<int> left = pse(heights);

        int max_area = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            max_area = max(max_area, area);
        }

        return max_area;
    }
};