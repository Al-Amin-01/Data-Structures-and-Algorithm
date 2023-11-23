#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

void generate(vector<int> &subset,int i,vector<int> &nums){

    if(i==nums.size()){
        subsets.push_back(subset);
        return;
    }

    //not included
    generate(subset,i+1,nums);
    //included
    subset.push_back(nums[i]);
    generate(subset,i+1,nums);
    subset.pop_back();
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin >> v[i];

    vector<int> emp;
    
    generate(emp,0,v);

    for(auto subset : subsets)
    {
        for(int x : subset) cout << x << " ";
        cout << endl;

    }
        

}