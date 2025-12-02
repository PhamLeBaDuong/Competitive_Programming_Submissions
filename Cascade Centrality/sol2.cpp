#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm> // For std::swap

using namespace std;

const double EPSILON = 1e-9;

// Function to perform Gaussian elimination to find the inverse of a matrix
vector<vector<double>> inverse(const vector<vector<double>>& A, int n) {
    vector<vector<double>> M = A;
    vector<vector<double>> B(n, vector<double>(n, 0.0));
    
    // Initialize B as the Identity matrix
    for (int i = 0; i < n; ++i) B[i][i] = 1.0;

    // Forward elimination
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(M[j][i]) > abs(M[pivot][i])) pivot = j;
        }
        
        // Check for singularity
        if (abs(M[pivot][i]) < EPSILON) return {}; 

        swap(M[i], M[pivot]);
        swap(B[i], B[pivot]);

        // Normalize the pivot row
        double div = M[i][i];
        for (int j = i; j < n; ++j) M[i][j] /= div;
        for (int j = 0; j < n; ++j) B[i][j] /= div;

        // Eliminate other rows
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double mult = M[j][i];
                for (int k = i; k < n; ++k) M[j][k] -= mult * M[i][k];
                for (int k = 0; k < n; ++k) B[j][k] -= mult * B[i][k];
            }
        }
    }
    return B;
}

// Function to perform matrix multiplication C = A * B
vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B, int n) {
    vector<vector<double>> C(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N_nodes, M_edges;
    // Check if reading N and M is successful
    if (!(cin >> N_nodes >> M_edges)) return 0;
    
    int n = N_nodes; 

    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);

    // Read edges and compute degrees
    for (int i = 0; i < M_edges; ++i) {
        int u, v;
        // Ensure that edge reading loop is robust
        if (!(cin >> u >> v)) return 0; 
        u--, v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int s_1based;
    // Check if reading the starting node s is successful
    if (!(cin >> s_1based)) return 0; 
    int s = s_1based - 1; 

    // 1. Construct the Transition Matrix T
    vector<vector<double>> T(n, vector<double>(n, 0.0));
    for (int u = 0; u < n; ++u) {
        if (degree[u] == 0) continue; 
        for (int v : adj[u]) {
            T[u][v] = 1.0 / degree[v]; 
        }
    }

    // 2. Construct the (I - T) matrix
    vector<vector<double>> I_minus_T(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            I_minus_T[i][j] = (i == j ? 1.0 : 0.0) - T[i][j];
        }
    }

    // 3. Compute the Inverse: Inv = (I - T)^-1
    vector<vector<double>> Inv = inverse(I_minus_T, n);
    if (Inv.empty()) {
        // If the matrix is singular, print a special error or 0.0, 
        // but for the sample this path is not taken.
        return 1; 
    }

    // 4. Compute the Total Contribution Matrix: C_total = T * Inv
    vector<vector<double>> C_total = multiply(T, Inv, n);

    // 5. Calculate the Centrality C(s) = (Sum of row s) - C_total[s][s]
    double cascade_centrality = 0.0;
    
    // Sum the entire row s
    for (int t = 0; t < n; ++t) {
        cascade_centrality += C_total[s][t];
    }
    
    // Subtract the contribution for t=s (the diagonal element)
    cascade_centrality -= C_total[s][s];

    // 6. Output the result rounded to one decimal place
    cout << fixed << setprecision(1) << cascade_centrality << endl;

    return 0;
}