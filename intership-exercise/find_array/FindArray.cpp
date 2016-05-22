#include<vector>
using namespace std;
#include"FindArray.h"

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        
        int size=array.size();
        
        if(array[0][0]>target)
            return false;
        //int head=0,tail=size-1;
        int head_board=0,tail_board=size-1;
        if(FindBoard(array,target,0,head_board)) return true;
        if(FindBoard(array,target,size-1,tail_board)) return true;
        
        int i=0;
        for(i=tail_board;i<head_board;++i)
            if(FindOnce(array[i],target))
            return true;
        
        
        
        
         return false;
    }
    
    
    bool FindBoard(vector<vector<int> > array,int target,int board,int &middle){
        int size=array.size();
         int low=0,hight=size-1;
        
        while(hight>low){            
               (middle)=(low+hight)/2;
              if(array[(middle)][board]==target) return true;
              else if(array[middle][board]>target) {
                  hight=middle-1;                  
              }else{
                  low=middle+1;                  
              }
        }
        if(array[low][board]==(target)) return true;
        
        return false;
        
    }
    
    
    bool FindOnce(vector<int> array,int target){
        
        
        int size=array.size();
        if(array[0]>target||array[size-1]<target) return false;
       
        int low=0,hight=size-1;
         int middle=0;
        
        while(hight>low){            
               middle=(low+hight)/2;
              if(array[middle]==target) return true;
              else if(array[middle]>target) {
                  hight=middle-1;                  
              }else{
                  low=middle+1;                  
              }
        }
        if(array[low]==target) return true;
        return false;
        
    }
};
