#include<stdio.h>

int main()
{
  int nilai,a,matriksA[3],infoA=0,matriksB[3],infoB=0,matriksC[3],infoC=0;
  for(a=0; a<9 ; a++)
    {
     scanf("%d",&nilai);
     
     if(a % 3 ==0)
       {
        matriksA[infoA] = nilai;
        infoA++;    
       }
     
     else if(a % 3 ==1)
       {
        matriksB[infoB] = nilai;
        infoB++;      
       }
     
     else
       {
        matriksC[infoC] = nilai;
        infoC++;      
       }  
               
    }
      
      for(a=0 ; a < 3 ; a++)
         {
          if(a < 2)
           {
             printf("%d ",matriksA[a]);
           }
          else
            {
              printf("%d\n",matriksA[a]);          
            } 
              
         }

       for(a=0 ; a < 3 ; a++)
         {
          if(a < 2)
           {     
          printf("%d ",matriksB[a]);    
           }
          
          else
            {
              printf("%d\n",matriksB[a]);          
            } 
          
                   
         }
        
        
       for(a=0 ; a < 3 ; a++)
         {
           if(a < 2)
           {    
          printf("%d ",matriksC[a]);    
           }
           
           else
            {
              printf("%d\n",matriksC[a]);          
            } 
          
         
         }  
      
        return 0; 
}
