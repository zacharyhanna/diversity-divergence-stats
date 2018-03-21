/* tablePiTheta.c - Takes as input a .table file where each column is an 
individual.  Calculates pi and thetaW.

Population membership is given in the file pop1, which consist of
the number of individuals, followed by a list of column numbers for each
population.  n is the total sample size of the input file.  Usage:

tablePiTheta n pop1
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int a, b, n, n1, n2, *poplist, s1, s2;
  char *geno;
  double piW1=0., piW2=0., piB=0., *denom, thetaW=0.;
  FILE *pop1, *pop2;

  if (argc != 3) {
    printf("Usage: tablePiTheta n pop1\n");
    exit(0);
  }
  n = atoi (argv[1]);

  poplist = (int *) malloc (n * sizeof (int));
  for (a=0; a<n; ++a)
    poplist[a] = 0;
  geno = (char *) malloc (n * sizeof (char));

  pop1 = fopen (argv[2], "r");
  fscanf (pop1, "%d ", &n1);
  for (a=0; a<n1; ++a) {
    fscanf (pop1, "%d ", &b);
    poplist[b-1] = 1;
  }
  fclose (pop1);

  denom = (double *) malloc ((2*n+1) * sizeof (double));
  denom[2] = 1.;
  for (a=3; a<=(2*n); ++a)
    denom[a] = denom[a-1] + (double) 1./(a-1);

  while (scanf ("%c ", &geno[0]) != EOF) {
    for (a=1; a<n; ++a)
      scanf ("%c ", &geno[a]);
    n1 = s1 = 0;
    for (a=0; a<n; ++a) {
      if (poplist[a] == 1) {
	if (geno[a] == '0') 
	  ++n1;
	else if (geno[a] == '1') {
	  ++n1;
	  ++s1;
	}
	else if (geno[a] == '2') {
	  ++n1;
	  s1 += 2;
	}
      }
    }

    if (n1>0 && s1>0 && s1<(2*n1)) {
      piW1 += (double) s1 * (2*n1 - s1) / (n1 * (2*n1 - 1));
      thetaW += (double) 1. / denom[2*n1];
    }
  }
  printf("%.3f\t%.3f\t\n", piW1, thetaW);
}
