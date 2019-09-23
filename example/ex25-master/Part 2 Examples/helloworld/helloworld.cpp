#include <stdlib.h>
#include <openacc.h>

// On CCV:
// module load pgi/16.7

// Compile for multi-core:
// export MP_BIND=no
// Compile for multi-core: pgc++ -acc -Minfo=accel -ta=multicore helloworld.cpp -o helloworld

// Compile for GPU:
// Compile for GPU: pgc++ -acc -Minfo=accel -ta=tesla helloworld.cpp -o helloworld

void foo(int n, double a, double * x, double *restrict y)
{
  #pragma acc kernels
  for (int i = 0; i < n; ++i)
    y[i] = a * x[i] + y[i];
}

int main(int argc, char* argv[])
{

  int N = 1 << 20;

  if (argc > 1)
    N = atoi(argv[1]);

  double *x = new double[N];
  double *y = new double[N];

  for (int i = 0; i < N; ++i) {
    x[i] = 2.0;
    y[i] = 1.0;
  }

  foo(N, 3.0, x, y);

  return 0;

}
