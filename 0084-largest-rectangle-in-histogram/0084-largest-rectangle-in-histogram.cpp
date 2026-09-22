class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        //array of previous smaller index
        int psi[n] ;
        psi[0] = -1;
        stack<int>st1;
        st1.push(0);
        for(int i=1 ; i<n;i++){
        while(st1.size()>0 && arr[st1.top()]>= arr[i]) st1.pop();
        if(st1.size() == 0) psi[i] = -1;
        else psi[i] = st1.top();
        st1.push(i);
        }

        //array of next smaller index
        int nsi[n] ;
        nsi[n-1] = n;
        stack<int>st2;
        st2.push(n-1);
        for(int i = n-2 ; i>=0;i--){
        while(st2.size()>0 && arr[st2.top()]>= arr[i]) st2.pop();
        if(st2.size() == 0) nsi[i] = n;
        else nsi[i] = st2.top();
        st2.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int height = arr[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area = breadth * height ;
            maxArea = max(maxArea , area);

        }
        return maxArea;
    }

};