#include <stdio.h>
#include <string.h>
   
main()
{
    int b,k,i,j,l,n;
    char * pch;
    char papan[101][101],tmp2[101],tmp[101],dm, kata[101][101], ket[101];
    scanf("%d %d",&b,&k);
    for (i=0;i<=(b-1);i++)
    {
      j = 0;
      while (j <= (k-1))
      {
        dm = getchar();
        if ((dm != '\n') && (dm != ' '))
        {
          papan[i][j] = dm;
          j++;
        }
      }
    }
    scanf("%d",&n);
    for (i=0;i<=(n-1);i++)
      scanf("%s",&kata[i]);
    for (i=0;i<=(n-1);i++)
      ket[i]='T';
    //horizontal
    for (i=0;i<=(b-1);i++)
    {
      memset(tmp,'\0',strlen(tmp));
      for (j=0;j<=(k-1);j++)
      {
        tmp[j] = papan[i][j];
      }
      for (j=0;j<=(n-1);j++)
      {
        pch = strstr (tmp,kata[j]);
        if (pch != NULL)
           ket[j]='Y';
      }
       
      for (j=0;j<=(n-1);j++)
      {
        memset(tmp2,'\0',strlen(tmp2));
        for (l=(strlen(kata[j])-1);l>=0;l--)
        {
          tmp2[(strlen(kata[j])-1)-l] = kata[j][l];
        }  
        pch = strstr (tmp,tmp2);
        if (pch != NULL)
           ket[j]='Y'; 
      }
    }
     
     
    //vertikal
    for (i=0;i<=(k-1);i++)
    {
      memset(tmp,'\0',strlen(tmp));
      for (j=0;j<=(b-1);j++)
      {
        tmp[j] = papan[j][i];     
      }   
      for (j=0;j<=(n-1);j++)
      {
        pch = strstr(tmp,kata[j]);
        if (pch != NULL)
          ket[j]='Y';   
      }
      for (j=0;j<=(n-1);j++)
      {
        memset(tmp2,'\0',strlen(tmp2));
        for (l=(strlen(kata[j])-1);l>=0;l--)
        {
          tmp2[strlen(kata[j])-1-l] = kata[j][l];
        }  
        pch = strstr (tmp,tmp2);
        if (pch != NULL)
           ket[j]='Y'; 
      }
    }
     
    //diagonal kiriatas
    for (i=(k-1);i>=0;i--)
    {
      j = 0;
      memset(tmp,'\0',strlen(tmp));
      while (((i+j) < k) && (j < b))
      {
        tmp[j] = papan[j][i+j];
        j++;
      }
      for (j=0;j<=(n-1);j++)
      {
        pch = strstr(tmp,kata[j]);
        if (pch != NULL)
          ket[j]='Y';   
      }
      for (j=0;j<=(n-1);j++)
      {
        memset(tmp2,'\0',strlen(tmp2));
        for (l=(strlen(kata[j])-1);l>=0;l--)
        {
          tmp2[strlen(kata[j])-1-l] = kata[j][l];
        }  
        pch = strstr (tmp,tmp2);
        if (pch != NULL)
           ket[j]='Y'; 
      }
    }
     
    //diagonal kiriatas2
    for (i=1;i<=(b-1);i++)
    {
      j = 0;
      memset(tmp,'\0',strlen(tmp));
      while ((j < k) && ((i+j) < b))
      {
        tmp[j] = papan[j+i][j];
        j++;
      }
      for (j=0;j<=(n-1);j++)
      {
        pch = strstr(tmp,kata[j]);
        if (pch != NULL)
          ket[j]='Y';   
      }
      for (j=0;j<=(n-1);j++)
      {
        memset(tmp2,'\0',strlen(tmp2));
        for (l=(strlen(kata[j])-1);l>=0;l--)
        {
          tmp2[strlen(kata[j])-1-l] = kata[j][l];
        }  
        pch = strstr (tmp,tmp2);
        if (pch != NULL)
           ket[j]='Y'; 
      }
    }
     
    //diagonal kananatas
    for (i=0;i<=(k-1);i++)
    {
      j = 0;
      memset(tmp,'\0',strlen(tmp));
      while (((i-j) >= 0) && (j < b))
      {
        tmp[j] = papan[j][i-j];
        j++;
      }
      for (j=0;j<=(n-1);j++)
      {
        pch = strstr(tmp,kata[j]);
        if (pch != NULL)
          ket[j]='Y';   
      }
      for (j=0;j<=(n-1);j++)
      {
        memset(tmp2,'\0',strlen(tmp2));
        for (l=(strlen(kata[j])-1);l>=0;l--)
        {
          tmp2[strlen(kata[j])-1-l] = kata[j][l];
        }  
        pch = strstr (tmp,tmp2);
        if (pch != NULL)
           ket[j]='Y'; 
      }
    }
     
     
    //diagonal kananatas2
    for (i=1;i<=(b-1);i++)
    {
      j = 0;
      memset(tmp,'\0',strlen(tmp));
      while (((i+j) < b) && ((k-1-j) >= 0))
      {
        tmp[j] = papan[i+j][k-1-j];
        j++;
      }
      for (j=0;j<=(n-1);j++)
      {
        pch = strstr(tmp,kata[j]);
        if (pch != NULL)
          ket[j]='Y';   
      }
      for (j=0;j<=(n-1);j++)
      {
        memset(tmp2,'\0',strlen(tmp2));
        for (l=(strlen(kata[j])-1);l>=0;l--)
        {
          tmp2[strlen(kata[j])-1-l] = kata[j][l];
        }  
        pch = strstr (tmp,tmp2);
        if (pch != NULL)
           ket[j]='Y'; 
      }
    }
    for (i=0;i<=(n-1);i++)
    {
      printf("%s %c\n",kata[i],ket[i]);   
    }
}
