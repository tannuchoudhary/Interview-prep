/*There are many sets of points on the horizontal axis of a co-ordinate plane. */


#include<bits/stdc++.h>
using namespace std;

int reduce(vector<vector<int>>& points) {

        vector<vector<int>> minimumPoints;
        sort(points.begin(), points.end());

        if(points.size() == 0)
            return 0;
        
        vector<int> temp =points[0];
        
        for(auto it: points){
            if(it[0]<=temp[1]){
                temp[1] = max(temp[1], it[1]);
            }
            else{
                minimumPoints.push_back(temp);
                temp = it;
            }
        }
        minimumPoints.push_back(temp);
        int ans = minimumPoints.size();
        return ans;
    }
    
int main(){
    int x;
    cin>>x;
    
    vector<vector<int>> v;
    
    for(int i=0; i<x; i++){
        vector<int> p;
        int a, b;
        cin>>a>>b;
        p.push_back(a);
        p.push_back(b);
        
        v.push_back(p);
    }
    
    int ans = reduce(v);
    cout<<ans;
    return 0;
}
