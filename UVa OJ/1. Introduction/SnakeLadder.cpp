#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

pair<int,int> nSnakeLadder[100];
int player[1000000],dieRolls[1000000];
int TC,nPlayer,nSnakeOrLadder,nRolls;
int a,b,c;
int status;

int main()
 {
 	scanf("%d",&TC);
 	for(a = 0; a < TC; a++)
 	{
 		scanf("%d %d %d",&nPlayer,&nSnakeOrLadder,&nRolls);
 		
 		// Set Posisi awal semua pemain
 		for(b = 0; b < nPlayer; b++)	player[b] = 1;
 		
 		// Nampung Snake and Ladder Condition
		for(b = 0; b < nSnakeOrLadder; b++)
 		{
 			scanf("%d %d",&nSnakeLadder[b].first,&nSnakeLadder[b].second);
 		}
 		
 		// Nampung nilai pelemparan dadu
 		//printf("nRolls Dadu : %d\n",nRolls);
 		for(b = 0; b < nRolls; b++)  scanf("%d",&dieRolls[b]);
 		
 		// Pemrosesan (Simulasikan)
 		for(b = 0; b < nRolls; b++)
 		{
 			//printf("--Sebelum Diproses-- Nilai di player[%d] : %d\n",b,player[b % nPlayer]);
 			player[b % nPlayer] = player[b % nPlayer] +  dieRolls[b];
 			
			 // Jika sudah melewati 100, sudah menang. set jadi 100 dan break
			 if(player[b % nPlayer] >= 100)
 			 {
 			 	player[b % nPlayer] = 100;
 			 	break;
 			 }
 			
 			// Cari apakah ada Snake / Ladder yang ada di kotak itu
			 for(c = 0; c < nSnakeOrLadder; c++)
 			{
 				if(player[b % nPlayer] == nSnakeLadder[c].first) 
				 {
				 	player[b % nPlayer] = nSnakeLadder[c].second;
				}
 			}
 			
 			if(player[b % nPlayer] >= 100)
 			 	{
 			 		player[b % nPlayer] = 100;
 			 		break;
 			 	}
 			//printf("Nilai di player[%d] : %d\n",b,player[b % nPlayer]);
 		}
 			
 			// Cetak hasil akhir
 		for(b = 0; b < nPlayer; b++)
 		{
 			printf("Position of player %d is %d.\n",((b%nPlayer)+1),player[b % nPlayer]);
 		}	
 	}	return 0;
 }
