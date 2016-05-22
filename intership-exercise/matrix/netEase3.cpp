#include<stdio.h>
#include<stdlib.h>
/*在N*M的草地上,提莫种了K个蘑菇,蘑菇爆炸的威力极大,兰博不想贸然去闯,而且蘑菇是隐形的.只 有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇,
于是他回了一趟战争学院,买了2个扫描透镜,一个 扫描透镜可以扫描出(3*3)方格中所有的蘑菇,然后兰博就可以清理掉一些隐形的蘑菇. 问:兰博最多可以清理多少个蘑菇?

输入描述:
第一行三个整数:N,M,K,(1≤N,M≤20,K≤100),N,M代表了草地的大小;
接下来K行,每行两个整数x,y(1≤x≤N,1≤y≤M).代表(x,y)处提莫种了一个蘑菇.
一个方格可以种无穷个蘑菇.


输出描述:
输出一行,在这一行输出一个整数,代表兰博最多可以清理多少个蘑菇.*/
#define LENGTH 20
int count_in_three_matrix(int matrix[][LENGTH],const int,const int);

int main(){

	int N, M, K;
	int x = 0, y = 0;

	scanf_s("%d%d%d", &N, &M, &K);
	if (N<1 || M>20 || K>100)
		exit(0);
	
	int matrix[LENGTH][LENGTH];
	//matrix=(int**)malloc(N*M*sizeof(int));

	int j = 0, i = 0;
	for (; i < 20; i++)
		for (j=0; j<20; j++)//此处j 若是不初始化，则导致只循环执行20次
			matrix[i][j] = 0;
			
	
	

	for (; K>0; --K){
		scanf_s("%d %d", &x, &y);
		if (x<1 || x>N || y<1 || y>M)
			exit(0);

		++matrix[x - 1][y - 1];
	}


	int max = count_in_three_matrix(matrix, N, M);
	printf("%d", max);
	
	system("PAUSE");
	return 0;
}
//int count_in_three_matrix(int matrix[][LENGTH], const int n,const int m){ //此处将导致在 引发访问 matrix时出现未经处理异常
int count_in_three_matrix(int matrix[][LENGTH], const int n,const int m){//在引用二维数组时，需要告知函数最内围以外数组大小
	int i = 0, j = 0;
	int max1 = 0, max2 = 0;
	int result = 0;




	//
	for (i=0; i<n; ++i)
	for (j=0; j<m; ++j){
		int x = 0, y = 0;
		int temp1 = 0;


		// find the max sum vaule of 3*3 son matrix
		for (x=0;( x < 3)&&(x+i<n); ++x)
			for (y=0; (y < 3) && (j + y < m); ++y)
				temp1 += matrix[i + x][j + y];//此语句 发生有未经处理异常错误，由于matrix 错误传递引发的

		max1 = max1>temp1 ? max1 : temp1;
		printf("======>  max1 = %d\n", max1);



		// find the second max sum value of 3*3 son matrix
		int k = 0, t = 0;
		for (k=0; k<n; ++k)
		for (t=0; t<m; ++t){

			int temp = 0;
			int a = 0, b = 0;

			for (a=0; a < 3 && k + a<n; ++a)
				for (b = 0; b < 3 && t + b<m; ++b){
					// eliminate the value of first max sum matrix
					if (k + a <= i + x&&t + b <= j + y)
						continue;

					temp += matrix[k + a][t + b];
				}

				max2 = max2>temp ? max2 : temp;
		}


		//  count the max bashrooms
		result = result>(max1 + max2) ? result : (max1 + max2);

	}

	return result;
}



