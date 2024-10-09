#include "Prototipos.h"

double Ctimer(void)
{
  struct timeval tm;

  gettimeofday(&tm, NULL);

  return tm.tv_sec + tm.tv_usec/1.0E6;
}

// Realiza el núcleo computacional estándar
void dgemmE(int m, int n, int k, double alpha, double *A, int lda, double *B, int ldb, double beta, double *C, int ldc)
{
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) {
			double total = 0.0;
			for(int r = 0; r < k; r++){
				total += A[i+r*lda] * B[r+j*ldb];
			}
			C[i+j*ldc] = beta * C[i+j*ldc] + alpha * total;

		}
	}
}

// Realiza la transpuesta de A y la guarda en At
void transp(int m, int k, double *A, double *At)
{
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++)
			At[i+j*m] = A[j+i*m];
}

// Realiza el núcleo computacional, asumiendo que At ya es la transpuesta de A
void dgemmT(int m, int n, int k, double alpha, double *At, int ldat, double *B, int ldb, double beta, double *C, int ldc)
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n;j++){
			double total = 0.0;
			for(int r = 0; r < k; r++){
				total += At[r+ldat*i] * B[r+ldb*j];
			}
		C[i+ldc*j] = beta * C[i+ldc*j] + alpha * total;
		}
	}
}

double MyDGEMM(int tipo, int m, int n, int k, double alpha, double *A, int lda, double *B, int ldb, double beta, double *C, int ldc)
{
  double timeini, timefin;
  
  // Lo que el alumno necesite hacer
  switch (tipo)
  {
    case Normal:
      timeini=Ctimer();
      A = (double *) calloc (m * k, sizeof(double));
      B = (double *) calloc (k * n, sizeof(double));
      C = (double *) calloc (m * n, sizeof(double));
      // Llamada a la funcion del alumnado normal. Se simula con un timer (sleep)
      dgemmE(m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
      free(A);
      free(B);
      free(C);
      timefin=Ctimer()-timeini;
      break;
    case TransA:
      timeini=Ctimer();
      // Reservar memoria para la transpuesta
      A = (double *) calloc(k * m, sizeof(double));
      // Llamada a la funcion del alumnado que trabaja con la transpuesta. Se simula con un timer (sleep)
      dgemmT(m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
      // Liberar memoria de la transpuesta
      free(A);
      timefin=Ctimer()-timeini;
      break;
    default:
      timefin=-10;
  }
  return timefin;
}
