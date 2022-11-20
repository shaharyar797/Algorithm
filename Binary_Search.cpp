#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int index, first = 0;
        int n = nums.size();
        int last = n-1;
        cout << "Size of Array: " << n << "\n" << endl;
        
        for(int i=0; i<=n; i++){
            cout << "\nIteration " << i+1 << " Stats:" << endl;
            int mid = (first + last)/2;
            cout << "\t\t\tFirst Index: " << first << "\t\tNums[first]: " << nums[first] << endl;
            cout << "\t\t\t Last Index: " << first << "\t\t Nums[last]: " << nums[last] << endl;
            cout << "\t\t\t  Mid Index: " << first << "\t\t  Nums[mid]: " << nums[mid] << endl;
            
            if(first > last) {
            	cout << "\t--> First index's value is greater then Last index's value" << endl;
            	index = -1; 
            	break;
            }
            if(target == nums[mid]) {
                cout << "\t--> Target " << target << " is equal to Mid index's value " << nums[mid] << endl;
                index = mid;
                break;
            }
            else if(target < nums[mid]) {
                cout << "\t--> Target " << target << " is less than Mid index's value " << nums[mid] << endl;
                last = mid-1;
            }
            else if(target > nums[mid]){
                cout << "\t--> Target " << target << " is greater than Mid index's value " << nums[mid] << endl;
                first = mid + 1;
            }
            cout<<"\t--> New_First: " << first << "\t\tNew_Last: " << last << "\t\tNew_Mid: " << mid << endl;
        }
        return index;
    }

int main()
{
    vector<int> arr = {-1, 1, 2, 4, 5, 6};
    int key = 3;
    
    cout << "Array: [";
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    cout << "Target: " << key << endl;
    
    int found = search(arr,key);
    
    if(found == -1)
    	cout << "\n\n\t\t\tKey " << key << " is not found in the given array." << endl;
    else
    	cout << "\n\n\t\t\tKey " << key << " is found at Index " << found << endl;

    return 0;
}
