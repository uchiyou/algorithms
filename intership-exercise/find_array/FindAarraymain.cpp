#include <iostream>
using namespace std;

#include"FindArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	int init[][3]={{1,2,3},{4,6,7},{11,23,345}};
	size_t count=sizeof(init)/sizeof(int);
	vector<vector<int> > array(init,init+count);
	
	Solution s=new Solution;
	cout<< s.Find(array,6)<<endl;
	
	return 0;
}
