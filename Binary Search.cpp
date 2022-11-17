/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
        int mid,first=0,last,index;
        int n=nums.size();
        last = n-1;
        cout<<"Size of Array: "<<n<<endl;
        for(int i=0;i<=n;i++){
            cout<<"Iteration "<<i+1<<endl;
            mid = (first + last)/2;
            cout<<"\t\tfirst: "<<first<<"\t\tlast: "<<last<<"\t\t\tmid: "<<mid<<endl;
            cout<<"\t\tnums[first]: "<<nums[first]<<"\t\tnums[last]: "<<nums[last]<<"\t\tnums[mid]: "<<nums[mid]<<endl;
            
            if(first>last){
                cout<<"\tfirst index is greater then last index"<<endl;
               index = -1; 
               break;
            }
            
            if(target == nums[mid]){
                cout<<"\tTarget "<<target<<" equal to mid Index Value "<<nums[mid]<<endl;
                index=mid;
                break;
            }
            else if(target<nums[mid]){
                cout<<"\tTarget "<<target<<" less than mid Index Value "<<nums[mid]<<endl;
                last = mid-1;
            }
            else if(target>nums[mid]){
                cout<<"\tTarget "<<target<<" greater than mid Index Value "<<nums[mid]<<endl;
                first = mid + 1;
            }
            cout<<"\t\tnew_first: "<<first<<"\t\tnew_last: "<<last<<"\t\tnew_mid: "<<mid<<endl;
            
        }
        return index;
    }

int main()
{
    vector<int> arr;
    int key;
    arr = {-1};
    key =3;
    cout<<"Array = [ ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"target: "<<key<<endl;
    
    int found = search(arr,key);
    
    cout<<"\n"<<key<<" Found at "<<found<<" index";

    return 0;
}
