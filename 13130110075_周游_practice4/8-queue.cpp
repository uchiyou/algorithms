#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 1024 
   //13130110075 zhouyou
int is_conflict(int*,int);
void print_board(int*,int);
void init_board(int*,int);
int queen(int);
    int main(void) { 
        int n = 8; 
        int count = queen(n); 
        printf("%d queens problem has %d results\n",n,count); 
        return 0; 
    }
    int is_conflict(int *a, int n) { 
        int flag = 0; 
        int i; 
        for ( i = 0; i < n; i++ ) { 
            if ( a[i] == a[n] || a[i] - a[n] == n - i || a[n] - a[i] == n - i ) { 
                flag = 1; 
                break; 
            } 
        } 
        return flag; 
    } 
    
    void print_board(int *a, int n) { 
        int i, j; 
        for ( i = 0; i < n; i++ ) { 
            for ( j = 0; j < a[i]; j++ ) { 
                printf("| ");
            } 
            printf("Q"); 
            for ( j = a[i] + 1; j < n; j++ ) { 
                printf(" |"); 
            } 
            printf("\n"); 
        } 
        printf("---------------\n"); 
    } 
    
    void init_board(int *a, int n) { 
        int i; 
        for ( i = 0; i < n; i++ ) { 
            a[i] = 0; 
        } 
    } 
    
    int queen(int n) { 
        int count = 0; 
        int a[MAX_LENGTH]; 
        init_board(a, n); 
        int i = 0; 
        while ( 1 ) { 
            if ( a[i] < n ) { 
               
               
                if ( is_conflict(a, i) ) { 
                  
                    a[i]++; 
                    continue; 
                } 
                if ( i >= n - 1 ) { 
                   
                    count++; 
                    print_board(a, n); 
                    a[n-1]++; 
                    continue; 
                } 
                i++; 
                continue; 
            } 
            else {  
                a[i] = 0; 
                i--; 
                if ( i < 0 ) { 
                    return count; 
                } 
                a[i]++; 
                continue; 
            } 
        } 
    } 
