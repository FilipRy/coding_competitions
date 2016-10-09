import java.io.*;
public class avion {
    public static void main(String[] args) {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        try{
            boolean found=false;
            for(int f=0;f<5;f++){
                String vstup=bf.readLine();
                for(int i=0;i<vstup.length();i++){
                    if(vstup.charAt(i)=='F'&&i<vstup.length()-2){
                        if(vstup.charAt(i+1)=='B'&&vstup.charAt(i+2)=='I'){
                            found=true;
                            System.out.println(f+1);
                        }
                    }
                }  
            }if(found==false){System.out.println("HE GOT AWAY!");}
        }catch(IOException v){}
    }

}