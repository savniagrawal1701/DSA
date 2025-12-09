#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
int findmaxindex(vector<vector<int>>& mat,int n ,int m ,int col){
    int maxval=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxval){
            maxval=mat[i][col];
            index=i;
        }
    }
    return index;
}
vector<int> findpeakgrid(vector<vector<int>> &mat){
    int n=mat.size();
    int m =mat[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid =low+high/2;
        int maxrowindex=findmaxindex(mat,n,m,mid);
        int left=mid-1>=0?mat[maxrowindex][mid-1]:-1;
        int right =mid+1<m?mat[maxrowindex][mid+1]:-1;
         if (mat[maxrowindex][mid] > left && mat[maxrowindex][mid] > right) {
                  return {maxrowindex, mid};
              } 
              else if (left > mat[maxrowindex][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid+ 1;
              }
          }
  
          return {-1, -1};
        
    }
};
  
  int main() {
      // Example usage
      vector<vector<int>> mat = {
          {4, 2, 5, 1, 4, 5},
          {2, 9, 3, 2, 3, 2},
          {1, 7, 6, 0, 1, 3},
          {3, 6, 2, 3, 7, 2}
      };
  
      solution sol;
  
     
      vector<int> peak = sol.findpeakgrid(mat);
      cout << "The row of peak element is " << peak[0]
           << " and column of the peak element is " << peak[1] << endl;
  
      return 0;
  }
