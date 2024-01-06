class Solution {
public:
    int getX(int cx,int x1,int x2){
        if(cx<x1) return x1-cx;
        if(cx>x2) return cx-x2;
        return 0;
    }
    int getY(int cy,int y1,int y2){
        if(cy<y1) return y1-cy;
        if(cy>y2) return cy-y2;
        return 0;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int minDistX = getX(xCenter,x1,x2);
        int minDistY = getY(yCenter,y1,y2);

        int minDist = minDistX*minDistX + minDistY*minDistY;
        return minDist<=radius*radius;
    }
};
