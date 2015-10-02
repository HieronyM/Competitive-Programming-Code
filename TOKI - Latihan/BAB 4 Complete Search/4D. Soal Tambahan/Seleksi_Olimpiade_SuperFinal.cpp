#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int sesi1[81],sesi2[81],sesi3[81];
long long total[81];
char id[81][7];

int main()
 {
 	int TC,nOrang,nlulus,a,b,c;
    char dicari[7];
    int orangKe,nChar,dapat;
    long long nilaiOrangKe;
    
	scanf("%d",&TC);
    
    int count;
 	for(a = 0; a < TC; a++)
    {
        scanf("%d %d",&nOrang,&nlulus);
        scanf("%s",&dicari);
        nChar = strlen(dicari);
        for(b = 0; b < nOrang; b++)
        {
            scanf("%s %d %d %d",&id[b],&sesi1[b],&sesi2[b],&sesi3[b]);
            total[b] = sesi1[b] * 1 + sesi2[b] * 501  + sesi3[b] * 501001;
        }
        
        for(b = 0; b < nOrang; b++)
        {
          dapat = 0;    
          for(c = 0 ; c < nChar; c++)
            {
                //printf("Dicari[%d] : %c id[%d][%d] : %c\n",c,dicari[c],b,c,id[b][c]);
                if(dicari[c] != id[b][c])
                  {
                    dapat = 1;
                    break;
                  }
            }
            if(dapat == 0)
            {
                orangKe = b;
                break;
            }
        }
        // Debugging
      //printf("Orang ke[%d] : %d\n",a,orangKe);
         
        
        nilaiOrangKe = total[orangKe];
        
        // debugging
	//	printf("nilaiOrangKe : %lld\n",nilaiOrangKe);
		sort(total, total + nOrang);
        
        count =0;
        for(b = nOrang - 1; b >= 0; b--)
        {	
        //	printf("Total[%d] : %lld\n",b,total[b]);
    	 	//printf("NilaiorangKe : %lld\n",nilaiOrangKe);
		 if(total[b] > nilaiOrangKe)
    	   {
    	  // 	printf("Masuk!\n");
    	   	count++;
    	   }
    	   else if(total[b] == nilaiOrangKe)
    	   {
    	  // 	printf("Masuk!\n");
    	   	count++;
    		break;
    	   }
		}
		
		//printf("Count[%d] : %d\n",a,count);
		// Penentuan;
		if(count > nlulus) printf("TIDAK\n");
		else	printf("YA\n");
	}
	
	return 0;
 }
