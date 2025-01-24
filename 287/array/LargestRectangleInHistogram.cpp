#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int largestRectangleArea(vector<int> & heights){
        int area,maxArea,height,maxHeight,len,maxLen;
        vector<int> ans;
        for(int i =0;i<heights.size();i++){



            area = 1*heights[i];
            horiArea = 
            
            if(area>maxArea){
                maxArea = area;
            }

                        

            if(heights[i]>height){
                height = heights[i];
            }
            if(maxHeight<height){
                maxHeight = height;
            }



        }
        return maxArea;
    }
};

int main(){

    vector<int> heights = {2,1,5,6,2,3};
    Solution obj;
    cout<<obj.largestRectangleArea(heights);
    return 0;
}