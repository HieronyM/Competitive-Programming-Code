#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;
     
#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())
     
vector<int> data;
vector<int> lisIdx;
vector<int> lisPar;

// Binary Search Function
// --> Untuk mencari Posisi / Idx data yang baru akan dimasukkan.
int bs(int x) 
  {
	int aw, ak, piv;
    aw = 0;
    ak = SZ(lisIdx);
     
    printf("--- x : %d ---\n ",x); 
    while(aw < ak) 
	{
    	piv = (aw + ak) / 2;
    	printf("data[lisIdx[piv]] : %d\n",data[lisIdx[piv]]);
    	if (data[lisIdx[piv]] < x) aw = piv + 1;
    	else ak = piv;
    }
    
	return ak;
 }
    
int main() 
  {
    int bil;
    while(scanf("%d", &bil) != EOF) data.PB(bil);
   
    // Set parentnya -1 dlu.  
    REP(i, SZ(data)) lisPar.PB(-1);
     
    REP(i, SZ(data)) {
    	int idx = bs(data[i]);
    	if (idx == SZ(lisIdx)) lisIdx.PB(i);			// Jika posisi dia dimasukkan di akhir (bisa ditambahi)
    	else lisIdx[idx] = i;							// Greedy Strategy
    	if (idx != 0) lisPar[i] = lisIdx[idx-1];		// Tampung parentnya disini.
  	}
     
	vector<int> ans;
	//int ulang = 0;
    int curr = lisIdx.back();
    while(curr != -1) 
	{
		//printf("Curr di Ulang [%d] : %d\n",ulang,curr);
		ans.PB(curr);
		curr = lisPar[curr];
		//ulang++;	
	}
	
    reverse(ans.begin(), ans.end());
     
    printf("%d\n", SZ(lisIdx));								// Maximum Length 
    puts("-");
    REP(i, SZ(lisIdx)) printf("%d\n", data[ans[i]]);
    return 0;
 }
     
