#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class solution{

    public:

    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int> left(n, 0); //left smaller nearest
        vector<int> right(n, 0); //right smaller nearest
        stack<int> s;

        //right smallest
        for (int i=n-1; i>=0; i--){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        //left smallest
        for (int i=0; i<n; i++){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }

        return ans;
    }
};

int main (){
    solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    cout << obj.largestRectangleArea(heights);
    return 0;
}