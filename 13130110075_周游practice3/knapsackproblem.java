package homework;
import java.util.*;
//zhouyou 13130110075
public class Fknapsackproblem
{
	public static void main(String[]args)
	{
	int[] weight={50,30,45,25,5};
	int[] value={200,180,225,200,50};//50+200+180+200
    System.out.println("最大价值为:"+MaxValue(weight,value,100));
    }



    static double MaxValue(int[] w,int [] v,int maxweigth)
    {   double Max=0;
    	double []vpw=new double[w.length];
    	for(int i=0;i<w.length;i++)
        {
        	vpw[i]=v[i]/w[i];//4 6 5 8 10 
        }
        double []v2=new double[vpw.length];//建立一个新的数组存储单位质量的价值
        for(int i=0;i<vpw.length;i++)
        	v2[i]=vpw[i];
        Arrays.sort(v2);// 4 5 6 8 10  对新数组进行排序
        int weight=maxweigth;//定义weight为剩余容量
        for(int n=v2.length-1;n>=0;n--)//倒序从最大单位价值的物品开始装
        {
        	int m=search(vpw,v2[n]);//找到当前单位价值对应的下标
        	if(weight>0)           //判断此时剩余容量是否为0
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