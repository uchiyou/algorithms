package homework;
import java.util.*;
//zhouyou 13130110075
public class Fknapsackproblem
{
	public static void main(String[]args)
	{
	int[] weight={50,30,45,25,5};
	int[] value={200,180,225,200,50};//50+200+180+200
    System.out.println("����ֵΪ:"+MaxValue(weight,value,100));
    }



    static double MaxValue(int[] w,int [] v,int maxweigth)
    {   double Max=0;
    	double []vpw=new double[w.length];
    	for(int i=0;i<w.length;i++)
        {
        	vpw[i]=v[i]/w[i];//4 6 5 8 10 
        }
        double []v2=new double[vpw.length];//����һ���µ�����洢��λ�����ļ�ֵ
        for(int i=0;i<vpw.length;i++)
        	v2[i]=vpw[i];
        Arrays.sort(v2);// 4 5 6 8 10  ���������������
        int weight=maxweigth;//����weightΪʣ������
        for(int n=v2.length-1;n>=0;n--)//��������λ��ֵ����Ʒ��ʼװ
        {
        	int m=search(vpw,v2[n]);//�ҵ���ǰ��λ��ֵ��Ӧ���±�
        	if(weight>0)           //�жϴ�ʱʣ�������Ƿ�Ϊ0
        	{   
         	   if(w[m]<weight)     
        	   {  
        		weight=weight-w[m];
        		Max=Max+vpw[m]*w[m];
        	    }
        	  else          
        	   {
        		Max=Max+weight*vpw[m];//
        		weight=0;
        	   }
            }

        }
        return Max;
    }



    
    static int search(double []a,double b)
    {   int m=0;
    	for(int i=0;i<a.length;i++)
    	{
    		if(a[i]==b)
    			m=i;
    	}
    	return m;
    }
}