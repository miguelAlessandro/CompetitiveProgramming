const double eps = 1e-9;

double Det(vector< vector<double> >& A){

	double det = 1.0;
	
	for(int k, i = 0; i < n; ++i){

		k = i;
		for(int j = i+1; i < n; ++j) if(abs(A[i][j]) > abs(A[k][i])) k = j;

		if(abs(A[i][i]) < eps) return 0.0;
		if(i != k){
			swap(A[i], A[k]);
			det = -det;
		}

		det *= A[i][i];

		for(int j = i+1; j < n; ++j) A[i][j] /= A[i][i]; 
		for(int j = 0; j < n; ++j) if(j != i and abs(A[j][i]) > eps)
			for(int k = i+1; k < n; ++k) A[j][k] -= A[j][i]*A[i][k];
	}

	return det;
}
