package homework;
// zhouyou 13130110075
public class DynamicKnapSack {  
    private int[] v;  
    private int[] w;  
    private int[][] c;  
    private int weight;  
  
    public DynamicKnapSack(int length, int weight, int[] vin, int[] win) {  
        v = new int[length + 1];  
        w = new int[length + 1];  
        c = new int[length + 1][weight + 1];  
        this.weight = weight;  
        for(int i = 0; i < length + 1; i++) {
            v[i] = vin[i];  
            w[i] = win[i];  
        }  
    }  
  
    public void solve() {  
       for(int i = 1; i < v.length; i++) {  //物品的数量
            for(int k = 1; k <= weight; k++) { // 背包的容量
                if(w[i] <= k) {  
                    //   
                    if(v[i] + c[i - 1][k - w[i]] > c[i - 1][k])  
                        c[i][k] = v[i] + c[i - 1][k - w[i]];  
                    else  
                        c[i][k] = c[i - 1][k];  
                } else  
                    c[i][k] = c[i - 1][k];  
            }  
        }  
    }  
  
    public void printResult() {  
        for(int i = 0; i < v. length; i++) {  
            for(int j = 0; j <= weight; j++)  
                System.out.print(c[i][j] + " ");  
            System.out.println();  
        }  
    }  
      
    public static void main(String[] args) {  
        int[] v = {0, 200,180,225,200,50};  
        int[] w = {0, 50,30,45,25,5};  
        int weight = 50;  
        DynamicKnapSack knapsack = new DynamicKnapSack(3, weight, v, w);  
        knapsack.solve();  
        knapsack.printResult();  
    }  
}  