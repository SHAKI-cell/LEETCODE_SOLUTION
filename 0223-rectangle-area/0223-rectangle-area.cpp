class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int weidth=max(0,min(ax2,bx2)-max(ax1,bx1));
        int height=max(0,min(ay2,by2)-max(ay1,by1));
        int total=weidth*height;
        int t1=(ax2-ax1)*(ay2-ay1);
        int t2=(bx2-bx1)*(by2-by1);
        int r=t1+t2-total;
        return r;
     }
};