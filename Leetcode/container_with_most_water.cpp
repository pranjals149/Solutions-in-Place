#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
        int min_height = height[0];
        int max_height = height[height.size() - 1];
        int min_idx = 0;
        int max_idx = height.size() - 1;
        
        if (max_height < min_height) {
            min_height = max_height;
            min_idx = max_idx;
            max_height = height[0];
            max_idx = 0;
        }
        
        int width = height.size() - 1;
        int max_area = min_height * width;
        
        while(width > 0) {
            int idx = min_idx;
            while (height[idx] <= min_height) {
                if (min_idx < max_idx) idx++;
                else idx--;
                width--;
                if (width < 1) break;
            }
            
            if (height[idx] > max_height) {
                min_height = max_height;
                min_idx = max_idx;
                max_idx = idx;
                max_height = height[idx];
            }
            
            else {
                min_idx = idx;
                min_height = height[idx];
            }
            
            max_area = max(max_area, width*min_height);
        }
        
        return max_area;
    }