#include<bits/stdc++.h>

using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index  >1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    //max-heap ki property satisfy nhi hogi
                    swap(arr[parent],arr[index]);
                    index = parent;

                }
                else{
                    return;
                }
            }

        }

        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void deleteFromHeap(){
            int idx = size;
            size--;
            arr[1] = arr[idx];
            int i = 1;

            while(i < size){
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if(leftIndex < size && arr[leftIndex] > arr[i]){
                    swap(arr[leftIndex],arr[i]);
                    i = leftIndex;

                }
                else if(rightIndex < size && arr[rightIndex] > arr[i]){
                    swap(arr[rightIndex],arr[i]);
                    i = rightIndex;
                }
                else{
                    return;
                }
            }            
        }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<n && arr[largest] < arr[left]){
        largest = left;
    }
    else if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    // heap hs;
    // cout<<"heap statrted"<<endl;
    // hs.insert(60);
    // hs.insert(50);
    // hs.insert(40);
    // hs.insert(30);
    // hs.insert(20);
    // hs.insert(10);

    // hs.print();

    // hs.insert(55);
    // hs.print();
    // hs.deleteFromHeap();
    // hs.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing the array now "<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}