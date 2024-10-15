#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include<unordered_set>
#include<set>
#include<list>
using namespace std;

#define ll long long

vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adjacency(V);
        for(auto a: edges){
            adjacency[a.first].push_back(a.second);
            adjacency[a.second].push_back(a.first);
        }
        return adjacency;
}
int main(){
    
    return 0;
}