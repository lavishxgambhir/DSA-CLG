class Solution{
    public:
    vector<int>arr;
    int count=0;

    void heapify_up(vector<int>&arr,int ind){
        int parent=(ind-1)/2;
        if(ind>0){
            if(arr[ind]>arr[parent]){
                swap(arr[ind],arr[parent]);
                heapify_up(arr,parent);
            }
        }
    }

    void heapify_down(vector<int>&arr,int ind){
        int largest=ind;
        int lchild=2*ind+1;
        int rchild=2*ind+2;

        if(lchild<arr.size() && arr[lchild]>arr[largest]){
            largest=lchild;
        }
        if(rchild<arr.size() && arr[rchild]>arr[largest]){
            largest=rchild;
        }

        if(largest!=ind){
            swap(arr[ind],arr[largest]);
            heapify_down(arr,largest);
        }
        return;
    }

        void initializeHeap(){
            arr.clear();
            count=0;
        }

        void insert(int key){
            arr.push_back(key);
            heapify_up(arr,arr.size()-1);
        }

        void changeKey(int index, int new_val){
            if(arr[index]<new_val){
                arr[index]=new_val;
                heapify_up(arr,index);
            }
            else{
                arr[index]=new_val;
                heapify_down(arr,index);
            }
        }

        void extractMax(){
            int el=arr[0];
            swap(arr[0],arr[arr.size()-1]);
            arr.pop_back();
            heapify_down(arr,0);
        }

        bool isEmpty(){
            return arr.size()==0;
        }

        int getMax(){
            return arr[0];
        }

        int heapSize(){
            return arr.size();
        }
};
