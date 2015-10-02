
// Template by Hierony
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <queue>

using namespace std;

typedef pair<int,int> pii;

#define REP(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define mp make_pair
#define sI(val) scanf("%d",&val)
#define sID(val,val2) scanf("%d %d",&val,&val2)
#define INF 2123123123

int R,C;					// Row and Column
int peta[105][105];			// nyimpan petanya

int y1[4] = {-1,1,0,0};				// Nyimpan pattern 4 arah
int x1[4] = {0,0,-1,1};				// Atas,Bawah,Kiri,kanan

int cek(int rPos, int cPos)
{
	if(rPos == 1 || rPos == R || cPos == 1 || cPos == C) return 1;
	else return 0;
}

int bfs(int rPos, int cPos)
{
	int layer = 1;					// ini kayak sequence lah kubilang, susah jelasin dalam kata-kata :D
	if(cek(rPos,cPos)) return layer;
	
	queue < pair<int,int> > Q;       //  Pair nya buat nyimpan koordinat y,x;
 	Q.push( mp(rPos,cPos) );		// Nampung Posisi awal buat diproses / Ditraverse terlebih dahulu
 	peta[rPos][cPos] = 2;			// Tandai Posisi itu, biar jangan dimasukkan lagi ke Queue, Asumsi 2 == telah ditandai
 	
 	while(!Q.empty())			// Selama Queue belum kosong, Proses :D
 	{
 		layer++;
 		int size = Q.size();	// Nyimpan banyaknya yang mau diproses di layer itu :D
 		REP(j,size)
 		{
 			pii temp = Q.front();			// Ambil dari Queue
 			Q.pop();						// Keluarkan dari Queue, 
 			
 			int rTemp,cTemp;
 			REP(k,4)						// cek 4 arah (tetangga koordinatnya)
 			{
 				rTemp = temp.first + y1[k];			// Akses tipe data pair (pasangan), dengan menggunakan .first dan .second
 				cTemp = temp.second + x1[k];
				
				if(peta[rTemp][cTemp] == 0)			// Bisa dilalui, masukan ke Queue dan tandai
				{
					if(cek(rTemp,cTemp))
					{
						return layer;				// Telah didapat jalan keluar
					}  
					
					Q.push( mp(rTemp,cTemp) );				//
					peta[rTemp][cTemp] = 2;
				}	
 			}
 		}
 	}
 	
}

int main()
{
	sID(R,C);
	
	for(int a = 1; a <= R; a++)					// Kita nyimpan mulai index 1 (based 1 - Indexing)
	{
		for(int b = 1; b <= C; b++)			
		{
			int val;
			sI(val);
			peta[a][b] = val;
		}
	}
	
	int rPos,cPos;			// Nyimpan Posisi Awal Mr.Groovy
	sID(rPos,cPos);
	
	printf("%d\n",bfs(rPos,cPos));
	return 0;
}
