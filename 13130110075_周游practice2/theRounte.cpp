class Visit {
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        // write code here
        vector<int> manager,client;//save the info of location
        int i=0,j=0;
        int flag=0;
        
        for(i=0;i<n;++i){
            if(flag==2) break;
            for(j=0;j<m;++j){                
                if(map[i][j]==1){
                    manager.push_back(i);
                    manager.push_back(j);
                    ++flag;
                }
                if(map[i][j]==2){
                    client.push_back(i);
                    client.push_back(j);
                    ++flag;
                }
            }
        }
        i=manager[0];
        j=manager[1];
        int upf=manager[0]<client[0]?1:0;
        int rlf=manager[1]<client[1]?1:0;
        int count=0;
        
        
        flag=0;// mark for is or not pop
        vector<int> temp;
        temp.push_back(i);
        temp.push_back(j);
        vector<vector<int>> stack;
        stack.push_back(temp);
        while(!stack.empty()){
            stack.pop_back();
            //--------------------j
            while(j!=client[1]){
            j=rlf==1?++j:--j;            
            if(map[i][j]==0){
                 vector<int> temp;
                 temp.push_back(i);
                 temp.push_back(j);
                 stack.push_back(temp);
            }else if(map[i][j]==-1){                
                j=rlf==1?--j:++j;
                flag=1;
                break;
            }else{
                ++count;
                //back last
            }
            }
            
            //--------------------------------i
          while(i!=client[0]){
            i=upf==1?++i:--i;            
            if(map[i][j]==0){
                 vector<int> temp;
                 temp.push_back(i);
                 temp.push_back(j);
                 stack.push_back(temp);
                flag=0;
                break;
            }else if(map[i][j]==-1){
                i=rlf==1?--i:++i;
                if(flag==1){
                    vector<int> temp=stack.back();
                    stack.pop_back(); 
                }
                break;
            }else{
                ++count;
                //back last
            }
            }
            
            
        }
        
        
    }
};
