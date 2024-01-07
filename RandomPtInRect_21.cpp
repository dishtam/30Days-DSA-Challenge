class Solution {
    int num_of_pts;
    vector<vector<int>> rects;
    vector<int> cumulative_pts_sum;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        num_of_pts=0;
        for(auto rect:rects){
            num_of_pts += (rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
            cumulative_pts_sum.push_back(num_of_pts);
        }
    }
    
    vector<int> pick() {
        // int n = cumulative_pts_sum.size();
        int rand_pt = rand()%num_of_pts; // choosing a random point from total points  
        int idx = upper_bound(cumulative_pts_sum.begin(),cumulative_pts_sum.end(),rand_pt)-cumulative_pts_sum.begin();
        vector<int>& rect = rects[idx];
        int width_x = rect[2]-rect[0]+1;
        int height_y = rect[3]-rect[1]+1;
        int pt_at_idx =  (rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
        int pt_st = cumulative_pts_sum[idx]-pt_at_idx;
        int offset = rand_pt-pt_st;
        int x = rect[0]+offset%width_x;
        int y = rect[1]+offset/width_x;
        
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
