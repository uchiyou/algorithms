#include <iostream>
using namespace std;
 //13130110075 zhouyou
bool check(int s[], int C, int k, int x[]){
    int sum = 0;
    for(int i=0; i<=k; i++){
        if(x[i] == 1)
            sum += s[i];
    }
    if(sum > C)
        return false;
    else
        return true;
     
}
void KNAPSACK(int v[], int s[], int C, int n){
    int x[5] = {-1, -1, -1, -1, -1}, X[5] = {0};
    int k = 0;
    int V = 0, sum = 0;
    while(k>-1){
        while(x[k] < 1){
            x[k]++;
            if(check(s, C, k, x)==true && k==n-1){
                for(int i=0; i<n; i++){
                    if(x[i] == 1)
                        sum += v[i];
                }
                if(V < sum){
                    for(int i=0; i<n; i++)
                        X[i] = x[i];
                    V = sum;
                    sum = 0;        
                }
            }
            else if(check(s, C, k, x)==true){
                k++;
            }
        }
        x[k] = -1;
        k--;
    }
    
    
    
    
    // printf the information of result
    int temp=0, temp1=0;
    cout << "choice ";
    for(int i=0; i<n; i++){
        if(X[i] == 1){
            temp += v[i];
            temp1 += s[i];
            cout << " the " << i+1 << " items ";
            cout<< "and ";
        }
    }
    cout << "\n the total capacity is " << temp1 << ",the total value is" << temp << "¡£" << endl; 
}
int main(int argc, char** argv) {
    int s[] = {2,6,8,13,15};
    int v[] = {3,4,6,11,19};
    KNAPSACK(v, s, 11, 5);
    return 0;
}
