import java.io.*;
import java.util.*;
class puz {
    public static void main(String[] args) {
        try{
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int A=Integer.parseInt(bf.readLine());
        int B=Integer.parseInt(bf.readLine());
        int V=Integer.parseInt(bf.readLine());
        int x=0;
        for(int height=0;height<=V;){
            x++;
            height=height+A;
            if(height>=V){
                System.out.println(x);
                break;
            }
            height=height-B;
        }
    }catch(IOException v){}
    }

}