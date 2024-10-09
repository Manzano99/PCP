// Realiza la transpuesta de A y la guarda en At
void MyTrans(int m, int n, double *A, double *At)
{
	for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                        At[i+j*m] = A[j+i*m];
}
