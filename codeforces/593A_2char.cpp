#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define N 105

using namespace::std;

string B;
vector<string> A;
int D[N];
int lmax = 0, n, m;
set<char> S[N]; 


int main( void )
{
	cin >> n;
	int m = 0;
	while(n--)
	{
		cin >> B;
		f(i, 0, B.length())
			S[m].insert(B[i]);
		if(S[m].size() <= 2)
		{
			A.push_back(B);
			m++;
		}		
		else
			S[m].clear();
	}
	
	int maxi;
	f(i, 0, m)
	{
		maxi = 0;
		D[i] = A[i].length();
		set<char>::iterator it = S[i].begin();
		f(j, 0, m)
		{
			if(i == j) continue;	
			set<char>::iterator jt = S[j].begin();
			if(S[i].size() == 2 && S[j].size() == 2)
			{
				if(*it == *jt)
				{
					it++; jt++;
					if(*it == *jt)
						D[i] += A[j].length();
					it--;
				}
			}
			else if(S[i].size() == 2 && S[j].size() == 1)
			{
				if(*it == *jt)
					D[i] += A[j].length();
				else
				{
					it++;
					if(*it == *jt)
						D[i] += A[j].length();
					it--;
				}
			}
			else if(S[i].size() == 1 && S[j].size() == 1)
			{
				if(*it == *jt)
					D[i] += A[j].length();
				else
				{
					int sum = A[i].length() + A[j].length();
					f(k, 0, m)
					{
							if(i == k) continue;
							if(j == k) continue;	
							set<char>::iterator kt = S[k].begin();
							if(S[k].size() == 2)
							{
								if(*it == *kt)
								{
									kt++;
									if(*jt == *kt)
										sum += A[k].length();
								}
								else if(*jt == *kt)
								{
									kt++;
									if(*it == *kt)
										sum += A[k].length();
								}
							}
							else
							{
								if(*it == *kt)
									sum += A[k].length();
								else if(*kt == *jt)
									sum += A[k].length();
							}
					}
					maxi = max(maxi, sum);
				}
			}
			else
			{
				bool b = false;
				if(*it == *jt)
					b = true;
				else	
				{
					jt++;
					if(*it == *jt)
						b = true;
					jt--;
				}
				if(b)
				{
					int sum2 = A[i].length() + A[j].length();
					f(k, 0, m)
					{
						if(i == k) continue;
						if(j == k) continue;	
						set<char>::iterator kt = S[k].begin();
						if(S[k].size() == 2)
						{
							if(*jt == *kt)
							{
								jt++;
								kt++;
								if(*jt == *kt)
									sum2 += A[k].length();
								jt--;
								kt--;
							}
						}
						else if(S[k].size() == 1)
						{
							if(*jt == *kt)
								sum2 += A[k].length();
							else 
							{
								jt++;
								if(*kt == *jt)
									sum2 += A[k].length();
								jt--;
							}
						}
					}
					maxi = max(maxi, sum2);
				}
			}
		}
		lmax = max(lmax, max(D[i], maxi));		
	}	
	cout << lmax << endl;

	return 0;
}
