/*multiplication of matrices*/

#include <iostream> 
  
using namespace std; 
  
#define N 3 
  
/*multiply two matrix*/
void mul_mat(int mat1[][N],  
              int mat2[][N],  
              int ans[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            ans[i][j] = 0; 
            for (k = 0; k < N; k++) 
                ans[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
  
int 
main() 
{ 
    int i, j; 
    int ans[N][N]; 
    int mat1[N][N] = {{5, 5, 5}, 
                      {2, 2, 2}, 
                      {3, 3, 3}}; 
  
    int mat2[N][N] = {{5, 5, 5}, 
                      {2, 2, 2}, 
                      {3, 3, 3}}; 
  
    mul_mat(mat1, mat2, ans); 
  
    cout << "Result matrix is \n"; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        cout << ans[i][j] << " "; 
        cout << "\n"; 
    } 
  
    return 0; 
} 