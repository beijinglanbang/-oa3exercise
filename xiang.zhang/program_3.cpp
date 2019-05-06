#include<iostream>
#include<vector>
using namespace std;
#define MaxDistance 99999 
int GetTreeExceedKNumber(vector< vector<int> > tree_adjacency_matrix, int k){
    int ret = 0, n=tree_adjacency_matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
             for(int k=0; k<n; k++){
                 if(tree_adjacency_matrix[i][j] > tree_adjacency_matrix[i][k]+tree_adjacency_matrix[k][j]){
                     tree_adjacency_matrix[i][j] = tree_adjacency_matrix[i][k]+tree_adjacency_matrix[k][j];
                 }
             }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(tree_adjacency_matrix[i][j] < k){
                ++ret;
            }
        }
    }
    return ret;
}
void InputTreeNumAndK(int* n, int* k){
    cout<<"Input Tree Number And K: "<<ends;
    cin>>*n>>*k;
}
void InputTreeAdjacencyTable(vector<vector<int>> tree_adjacency_table, int n){
    cout<<"Input Tree Node :"<<endl;
    int node1, node2, k;
    for(int i=0; i<n-1; i++){
        cin>>node1>>node2>>k;
        vector<int> tree_node_lst;
        tree_node_lst.push_back(node1);
        tree_node_lst.push_back(node2);
        tree_node_lst.push_back(k);
        tree_adjacency_table.push_back(tree_node_lst);
    }
} 
void InitTreeAdjacencyMatrix(vector<vector<int>> tree_adjacency_matrix, int n){
    for(int i=0; i<n; i++){
        vector<int> tree_node_lst;
        for(int j=0; j<n; j++){
            tree_node_lst.push_back(MaxDistance);
        }
        tree_adjacency_matrix.push_back(tree_node_lst);
    }	
}
void CreateTreeAdjacencyMatrix(vector<vector<int>> tree_adjacency_table, vector<vector<int>> tree_adjacency_matrix, int n){
    InitTreeAdjacencyMatrix(tree_adjacency_matrix, n);
    for(int i=0; i < n; ++i){
        int l = tree_adjacency_table[i][0]-1;
	int r = tree_adjacency_table[i][1]-1;
	int val = tree_adjacency_table[i][2];
	tree_adjacency_matrix[l][r] = val;
    }
}
int main(void){
    int n, k;
    int ret;
    vector<vector<int>> tree_adjacency_table, tree_adjacency_matrix;
    InputTreeNumAndK(&n, &k);
    InputTreeAdjacencyTable(tree_adjacency_table, n);
    CreateTreeAdjacencyMatrix(tree_adjacency_table, tree_adjacency_matrix, n);
    ret = GetTreeExceedKNumber(tree_adjacency_matrix, k);  
    cout<<ret<<endl; 
    return 0;
}
