class Solution {
public:

void heapify_down(vector<int>&nums,int ind,int heapsize){
    int largest=ind;
    int lchild=2*ind+1;
    int rchild=2*ind+2;

    if(lchild<heapsize && nums[lchild]>nums[largest]){
        largest=lchild;
    }
    if(rchild<heapsize && nums[rchild]>nums[largest]){
        largest=rchild;
    }
    if(largest!=ind){
        swap(nums[ind],nums[largest]);
        heapify_down(nums,largest,heapsize);
    }
}

void buildMaxheap(vector<int>&nums){
    int n=nums.size();
    for(int ind=n/2-1;ind>=0;ind--){
        heapify_down(nums,ind,nums.size());
    }
}

    void heapSort(vector<int>&nums) {
        buildMaxheap(nums);

        int last=nums.size()-1;

        while(last>0){
            swap(nums[0],nums[last]);
            heapify_down(nums,0,last);
            last--;
        }
    }
};
