//problem name:  Smallest Range Covering Elements from K Lists
//problem link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists
class node{
public:
    int data;
    int row;
    int col;
    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
  public:
    bool operator()(node* a,node*b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int start,end;
        int mini=INT_MAX,maxi=INT_MIN;
        node* tmp;
        int len=nums.size();
        priority_queue<node*,vector<node*>,compare> mp;
        for(int i=0;i<len;i++){
            mp.push(new node(nums[i][0],i,0));
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);
        }
        start=mini,end=maxi;
        while(!mp.empty()){
            tmp=mp.top();
            mp.pop();
            mini=tmp->data;
            if(maxi-mini < end-start){
                start=mini;
                end=maxi;
            }
            if(tmp->col+1<nums[tmp->row].size()){
                maxi=max(maxi,nums[tmp->row][tmp->col+1]);
                mp.push(new node(nums[tmp->row][tmp->col+1],tmp->row,tmp->col+1));
            }
            else{
                break;
            }
        }
        return {start,end};
    }
};
