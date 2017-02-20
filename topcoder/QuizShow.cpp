#include <iostream>
using namespace std;

int delta[2] = {-1, 1};
int score[3];
int w1, w2;

int wager(int *score, int wager1, int wager2){

	int answer = 0, best = 0;
		
	for(int i = 0; i <= score[0]; ++i){

		int local_best = 0;

		for(int j = 0; j < 8; ++j)
			if(score[0] + delta[j&1]*i > score[1] + delta[j&2]*wager1 and 
			   score[0] + delta[j&1]*i > score[1] + delta[j&4]*wager2) 
			local_best += 1;

		if(local_best > best) best = local_best, answer = i;
	}

	return answer;
}


int main(){

	for(int i = 0; i < 3; ++i) scanf("%d", score+i);	
	scanf("%d %d", &w1, &w2);

	printf("%d\n", wager(score, w1, w2));

	return 0;
}
