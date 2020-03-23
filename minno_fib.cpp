//PRANAV_JAGADEESH_1BM18CS071_ADA 
//to find minimum 
// number of jumps to reach 
// Destination 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1e9 
  
// Function that returns the min 
// number of jump to reach the 
// destination 
int minJumps(int arr[], int N) 
{ 
    // We consider only those Fibonacci 
    // numbers which are less than n, 
    // where we can consider fib[30] 
    // to be the upper bound as this 
    // will cross 10^5 
    int fib[30]; 
    fib[0] = 0; 
    fib[1] = 1; 
    for (int i = 2; i < 30; i++) 
        fib[i] = fib[i - 1] + fib[i - 2]; 
  
    // DP[i] will be storing the minimum 
    // number of jumps required for 
    // the position i. So DP[N+1] will 
    // have the result we consider 0 
    // as source and N+1 as the destination 
    int DP[N + 2]; 
  
    // Base case (Steps to reach source is) 
    DP[0] = 0; 
  
    // Initialize all table values as Infinite 
    for (int i = 1; i <= N + 1; i++) 
        DP[i] = MAX; 
  
    // Compute minimum jumps required 
    // considering each Fibonacci 
    // numbers one by one. 
  
    // Go through each positions 
    // till destination. 
    for (int i = 1; i <= N + 1; i++) { 
  
        // Calculate the minimum of that 
        // position if all the Fibonacci 
        // numbers are considered 
        for (int j = 1; j < 30; j++) { 
  
            // If the position is safe 
            // or the position is the 
            // destination then only we 
            // calculate the minimum 
            // otherwise the cost is 
            // MAX as default 
            if ((arr[i - 1] == 1 
                 || i == N + 1) 
                && i - fib[j] >= 0) 
                DP[i] = min(DP[i], 
                            1 + DP[i - fib[j]]); 
        } 
    } 
  
    // -1 denotes if there is 
    // no path possible 
    if (DP[N + 1] != MAX) 
        return DP[N + 1]; 
    else
        return -1; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << minJumps(arr, n); 
    return 0; 
} 
