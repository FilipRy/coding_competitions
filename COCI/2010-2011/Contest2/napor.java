import java.io.*;
class napor {
    public static void main(String[] args) {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        try{
            int N=Integer.parseInt(bf.readLine());
            String pole[]=new String[500];
            int y=0;
            for(int a=0;a<500;a++){
                pole[a]="";
            }
            for(int a=0;a<N;a++){
                String vstup=bf.readLine();
                for(int i=0;i<vstup.length();i++){
                    if(vstup.charAt(i)>47&&vstup.charAt(i)<58){
                        while(vstup.charAt(i)>47&&vstup.charAt(i)<58){
                            pole[y]=pole[y]+Character.toString(vstup.charAt(i));
                            i++;
                            if(i==vstup.length()){break;}
                        }y++;
                    }
                }
            }
            for(int a=0;a<y;a++){
                int xx=0;
                boolean n=false;
                while(pole[a].charAt(xx)=='0'){
                    xx++;
                    if(xx==pole[a].length()){
                        pole[a]="0";
                        n=true;
                        break;
                    }
                }
                if(!n){
                    pole[a]=pole[a].substring(xx);
                }
            }
            int index=0;
            for(int i=0;i<y;i++){
                String min="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
                for(int ii=i;ii<y;ii++){
                    if(pole[ii].length()<min.length()){min=pole[ii];index=ii;}
                    else if(pole[ii].length()==min.length()){
                        for(int a=0;a<min.length();a++){
                            if(min.charAt(a)<pole[ii].charAt(a)){
                                break;
                            }
                            if(min.charAt(a)>pole[ii].charAt(a)){
                                min=pole[ii];
                                index=ii;
                                break;
                            }
                        }
                    }
                }
                String tmp=pole[i];
                pole[i]=pole[index];
                pole[index]=tmp;
                int xx=0;
                boolean n=false;
                System.out.println(min);
            }
        }catch(IOException v){}
    }
}