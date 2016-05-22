package homework;
import java.util.*;
public class Scheduleing{
//zhouyou 13130110075
	public static void main(String[]args)
	{
		int []a={15,8,3,10};
		Schedul(a);
	}
	static void Schedul(int []a)
	{  int []sum=new int [a.length+1];
       int []temp=new int[a.length+1];
       System.out.println("执行顺序为:");
       temp[0]=0;
       int sumoftime=0;
       for(int i=0;i<a.length;i++)
           temp[i+1]=a[i];
       Arrays.sort(temp);
       sum[0]=temp[1];
       for(int i=1;i<temp.length;i++)
       {    
            sum[i]=sum[i-1]+temp[i];    
            int x=search(a,temp[i])+1;
            System.out.println("j"+x+" ");
       }
       for(int i=1;i<sum.length;i++)
    	   sumoftime=sumoftime+sum[i];
       System.out.println("平均周转时间为:"+sumoftime/(sum.length-1));
	}
	static int search(int []a,int b)
    {   int m=0;
    	for(int i=0;i<a.length;i++)
    	{
    		if(a[i]==b)
    			m=i;
    	}
    	return m;
    }
}