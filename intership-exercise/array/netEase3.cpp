#include<stdio.h>
#include<stdlib.h>
/*��N*M�Ĳݵ���,��Ī����K��Ģ��,Ģ����ը����������,��������óȻȥ��,����Ģ�������ε�.ֻ ��һ�ֽ���ɨ��͸������Ʒ����ɨ������ε�Ģ��,
����������һ��ս��ѧԺ,����2��ɨ��͸��,һ�� ɨ��͸������ɨ���(3*3)���������е�Ģ��,Ȼ�������Ϳ��������һЩ���ε�Ģ��. ��:����������������ٸ�Ģ��?

��������:
��һ����������:N,M,K,(1��N,M��20,K��100),N,M�����˲ݵصĴ�С;
������K��,ÿ����������x,y(1��x��N,1��y��M).����(x,y)����Ī����һ��Ģ��.
һ����������������Ģ��.


�������:
���һ��,����һ�����һ������,��������������������ٸ�Ģ��.*/
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
		for (j=0; j<20; j++)//�˴�j ���ǲ���ʼ��������ֻѭ��ִ��20��
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
//int count_in_three_matrix(int matrix[][LENGTH], const int n,const int m){ //�˴��������� �������� matrixʱ����δ�������쳣
int count_in_three_matrix(int matrix[][LENGTH], const int n,const int m){//�����ö�ά����ʱ����Ҫ��֪��������Χ���������С
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
				temp1 += matrix[i + x][j + y];//����� ������δ�������쳣��������matrix ���󴫵�������

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



