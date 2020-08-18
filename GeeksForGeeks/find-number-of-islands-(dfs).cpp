/*
THIS IS BASICALLY A DFS PROBLEM
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void dfs(vector<int> A[], bool visited[101][101], int r, int c, int N, int M) {
    if (visited[r][c]) return;
    // if not valid row/column
    if (r<0 or r>=N or c<0 or c>=M) return;
    // mark visited only if it is 1
    if (A[r][c] == 1) visited[r][c] = true;
    else return;
    // all 8 neighboring cells and mark them visited if they are 1
    dfs(A, visited, r-1, c-1, N, M);
    dfs(A, visited, r-1, c, N, M);
    dfs(A, visited, r-1, c+1, N, M);
    dfs(A, visited, r, c-1, N, M);
    dfs(A, visited, r, c+1, N, M);
    dfs(A, visited, r+1, c-1, N, M);
    dfs(A, visited, r+1, c, N, M);
    dfs(A, visited, r+1, c+1, N, M);
}

int findIslands(vector<int> A[], int N, int M) {
    int count=0;
    bool visited[101][101];
    memset(visited, false, sizeof(visited));
    // no of times we need to call dfs is the number of islands
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (A[i][j] == 1 && visited[i][j]==false) {
                count++;
                dfs(A, visited, i, j, N, M);
            }
        }
    }
    return count;
}