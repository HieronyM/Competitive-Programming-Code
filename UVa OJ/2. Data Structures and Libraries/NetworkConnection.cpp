// ----- Bipartite Graph Check Using Adjacency List (Unweighted) ---//

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define REP(a,n) for((a) = 0; (a) < n; a++)
#define pb push_back
#define vi vector <int>

vi pset; 		// To Hold the parent Idx of the set

void initSet(int N)
{
	 pset.assign(N+1,0); 	// To Assign the Vector size and the value
	 for(int i = 1; i <= N; i++) pset[i] = i;	
}

// This is using to Find Parent of the set, using to when union the set
int findSet(int i)
 {
 	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
 }

// To check whether the Parent of the set is same
bool isSameSet(int i,int j)
 {
 	return findSet(i) == findSet(j);
 }
 
// To union a set to another set
void unionSet (int i, int j)
{
	pset[findSet(i)] = findSet(j);
} 

int dataset;
int main()
 {
 	int a;
 	int nSet;
	scanf("%d",&dataset);
	
	char oper;
	string s;				// Operation that done
	int s1,s2;
	int nSuccess,nUnsuccess;
	REP(a,dataset)
	{
		nSuccess = nUnsuccess = 0;
		
		scanf("\n%d\n",&nSet);
		initSet(nSet);
		
		while(1)
		{
			
			if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&oper,&s1,&s2);       // The magic io.
            
			if(oper == 'c') unionSet(s1,s2);
			else if(oper == 'q')
			{
				isSameSet(s1,s2) ? nSuccess++ : nUnsuccess++;
			} 
		}
		
		if(a!=0) printf("\n");
		printf("%d,%d\n",nSuccess,nUnsuccess);
		
	}
	return 0;
 }
