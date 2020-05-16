//count subsets with 
// given sum. 
#include <bits/stdc++.h> 
using namespace std; 
  
// dp[i][j] is true if sum j is 
// possible with array 0 to i. 
bool** dp; 
  
void display(const vector<int>& v) 
{ 
    for (int i = 0; i < v.size(); ++i) 
        printf("%d ", v[i]); 
    printf("\n"); 
} 
  
//  recursive function to print  subsets with 
//  dp[][]. Vector p[] stores current subset. 
void printSubsetsRec(int arr[], int i, int sum, vector<int>& p) 
{ 
    // If end reached  and sum is non-zero. print 
    // p[] if arr[0] equal to sum OR dp[0][sum] 
    // is true. 
    if (i == 0 && sum != 0 && dp[0][sum]) 
    { 
        p.push_back(arr[i]); 
        display(p); 
        return; 
    } 
  
    // If sum is 0 
    if (i == 0 && sum == 0) 
    { 
        display(p); 
        return; 
    } 
  
    // If given sum can be achieved after ignoring 
    // current element. 
    if (dp[i-1][sum]) 
    { 
        // Create vector to store path 
        vector<int> b = p; 
        printSubsetsRec(arr, i-1, sum, b); 
    } 
  
    // If sum can be achieved considering 
    // current element. 
    if (sum >= arr[i] && dp[i-1][sum-arr[i]]) 
    { 
        p.push_back(arr[i]); 
        printSubsetsRec(arr, i-1, sum-arr[i], p); 
    } 
} 
  
// Prints all subsets of arr[0..n-1] with sum 0. 
void printAllSubsets(int arr[], int n, int sum) 
{ 
    if (n == 0 || sum < 0) 
       return; 
  
    // Sum 0 can always be achieved with 0 elements 
    dp = new bool*[n]; 
    for (int i=0; i<n; ++i) 
    { 
        dp[i] = new bool[sum + 1]; 
        dp[i][0] = true; 
    } 
  
    // Sum arr[0] can be achieved with single element 
    if (arr[0] <= sum) 
       dp[0][arr[0]] = true; 
  
    // Fill rest of the entries in dp[][] 
    for (int i = 1; i < n; ++i) 
        for (int j = 0; j < sum + 1; ++j) 
            dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || 
                                       dp[i-1][j-arr[i]] 
                                     : dp[i - 1][j]; 
    if (dp[n-1][sum] == false) 
    { 
        printf("There are no subsets with sum %d\n", sum); 
        return; 
    } 
  
    // Now recursively traverse dp[][] to find all 
    // paths from dp[n-1][sum] 
    vector<int> p; 
    printSubsetsRec(arr, n-1, sum, p); 
} 
  
 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 10; 
    printAllSubsets(arr, n, sum); 
    return 0; 
}
