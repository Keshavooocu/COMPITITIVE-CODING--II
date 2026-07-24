class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        int* prev_smaller = new int[n];
        int* next_smaller = new int[n];
        int* st = new int[n];
        int st_top = -1;
        
        for (int i = 0; i < n; ++i) {
            while (st_top >= 0 && heights[st[st_top]] >= heights[i]) {
                st_top--;
            }
            prev_smaller[i] = (st_top == -1) ? -1 : st[st_top];
            st[++st_top] = i;
        }
        st_top = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (st_top >= 0 && heights[st[st_top]] >= heights[i]) {
                st_top--;
            }
            next_smaller[i] = (st_top == -1) ? n : st[st_top];
            st[++st_top] = i;
        }
        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            int width = next_smaller[i] - prev_smaller[i] - 1;
            int area = heights[i] * width;
            if (area > max_area) {
                max_area = area;
            }
        }
        delete[] prev_smaller;
        delete[] next_smaller;
        delete[] st;

        return max_area;
    }
};