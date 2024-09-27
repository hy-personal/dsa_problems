// K Sized Subarray Maximum
/*
Given an array arr[] and an integer k. Find the maximum for each and every contiguous subarray of size k.

Example1:
    Input: k = 3, arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]
    Output: [3, 3, 4, 5, 5, 5, 6] 
    Explanation: 
        1st contiguous subarray = [1 2 3] max = 3
        2nd contiguous subarray = [2 3 1] max = 3
        3rd contiguous subarray = [3 1 4] max = 4
        4th contiguous subarray = [1 4 5] max = 5
        5th contiguous subarray = [4 5 2] max = 5
        6th contiguous subarray = [5 2 3] max = 5
        7th contiguous subarray = [2 3 6] max = 6

Example2:
    Input: k = 4, arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
    Output: [10, 10, 10, 15, 15, 90, 90]
    Explanation: 
        1st contiguous subarray = [8 5 10 7], max = 10
        2nd contiguous subarray = [5 10 7 9], max = 10
        3rd contiguous subarray = [10 7 9 4], max = 10
        4th contiguous subarray = [7 9 4 15], max = 15
        5th contiguous subarray = [9 4 15 12], max = 15
        6th contiguous subarray = [4 15 12 90], max = 90
        7th contiguous subarray = {15 12 90 13}, max = 90

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(k)

Constraints:
    1 ≤ sizeof(arr) ≤ 10^6
    1 ≤ k ≤ sizeof(arr)
    0 ≤ arr[i] ≤ 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        deque<int> dq;
        int n = arr.size();
        vector<int> res(n-k+1);
        for(int i = 0; i < n; ++i) {
            while(!dq.empty() && dq.back() < arr[i])
                dq.pop_back();
            dq.push_back(arr[i]);
            if(i >= k-1) {
                res[i-k+1] = dq.front();
                if(!dq.empty() && dq.front() == arr[i-k+1])
                    dq.pop_front();
            }
        }
        return res;   
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
