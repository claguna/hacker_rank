/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package amazon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author claguna
 */
public class Amazon {

    
   private static boolean checkNeighborhood(Integer[][] matrix, Integer x, Integer y, Integer maxdis){
       Integer target = matrix[x][y];
       Integer dimx = matrix.length;
       Integer dimy = matrix[0].length;
       for(int d = 1; d < maxdis; d++){
           for(int xt = x-d; xt<x+d+1; xt++){               
               if(xt>-1 && y-d > -1 && xt< dimx && y-d < dimy && matrix[xt][y-d]==target)
                   return true;
               if(xt>-1 && xt< dimx && y+d < dimy && matrix[xt][y+d]==target)
                   return true;
           }
           for(int yt = y-d; yt< y+d+1; yt++){
               if(yt>-1 && x-d > -1 && yt< dimy && x-d < dimx && matrix[x-d][yt]==target)
                   return true;
               if(yt>-1 && yt< dimy && x+d < dimx && matrix[x+d][yt]==target)
                   return true;
           }
       }              
       return false;
   }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            Integer dimx = Integer.valueOf(br.readLine());
            Integer dimy = dimx;
            Integer[][] matrix=null;
            Integer maxdis= 0;            
            for(int i = 0 ; i < dimx; i ++){
                StringTokenizer str = new StringTokenizer(br.readLine()," ");
                dimy = str.countTokens();
                if(i==0)
                   matrix = new Integer[dimx][dimy];
                for(int j = 0 ; j < dimy; j ++){                
                   matrix[i][j] = Integer.valueOf(str.nextToken());
                }
            }
            maxdis = Integer.valueOf(br.readLine());
            for(int i = 0 ; i < dimx; i ++){
                for(int j = 0 ; j < dimy; j ++){
                    if(checkNeighborhood(matrix, i, j, maxdis)){
                        System.out.println("YES");
                        return;
                    }                        
                    System.out.print(matrix[i][j]);
                }
                System.out.println();
            }
            System.out.println("NO");
        } catch (IOException ex) {
            Logger.getLogger(Amazon.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}
