#include <iostream>  
#include <vector>  
using namespace std;  
int main ()  
{  
 vector<int> value;  
 vector<int> volume;  
 vector<int> DP;  
 int N,V;  
 while ( cin >> N >> V )  
 {  
  value.resize(N+1);  
  volume.resize(V+1);  
  DP.clear();  
  DP.resize(V+1);  
  for ( int i = 1; i <= N; i++ )  
  {  
   cin >> volume[i] >> value[i];  
  }  
  for ( int v = V; v >= 1; v-- )  
  {  
      cout<<v; 
  }  
  cout<<endl;  
  for ( int i = 1; i <= N; i++ )  
  {  
   for ( int v = V; v >= 1; v-- )  
   {  
    if ( v >= volume[i] )  
    {  
     if ( DP[v-volume[i]] + value[i] >= DP[v] )  
     {  
            DP[v] = DP[v-volume[i]] + value[i];  
     }  
    }  
    cout<<DP[v];  
   }  
   cout<<endl;  
  }  
  cout << DP[V] << endl;  
 }  
 return 0;  
}  

