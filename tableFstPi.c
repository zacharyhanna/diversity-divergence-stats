/* tableFstPi.c - Takes as input a .table file where each column is an 
individual.  Calculates Fst (cf. Hudson et al. 1992) between 2 populations
and pi for each.

Population membership is given in the files pop1 and pop2, which consist of
the number of individuals, followed by a list of column numbers for each
population.  n is the total sample size of the input file.  Usage:

tableFstPi n pop1 pop2
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int a, b, n, n1, n2, *poplist, s1, s2;
  char *geno;
  double piW1=0., piW2=0., piB=0.;
  FILE *pop1, *pop2;

  if (argc != 4) {
    printf("Usage: tableFstPi n pop1 pop2\n");
    exit(0);
  }
  n = atoi (argv[1]);

  poplist = (int *) malloc (n * sizeof (int));
  for (a=0; a<n; ++a)
    poplist[a] = 0;
  geno = (char *) malloc (n * sizeof (char));

  pop1 = fopen (argv[2], "r");
  pop2 = fopen (argv[3], "r");
  fscanf (pop1, "%d ", &n1);
  for (a=0; a<n1; ++a) {
    fscanf (pop1, "%d ", &b);
    poplist[b-1] = 1;
  }
  fscanf (pop2, "%d ", &n2);
  for (a=0; a<n2; ++a) {
    fscanf (pop2, "%d ", &b);
    poplist[b-1] = 2;
  }
  fclose (pop1);
  fclose (pop2);

  while (scanf ("%c ", &geno[0]) != EOF) {
    for (a=1; a<n; ++a)
      scanf ("%c ", &geno[a]);
    n1 = n2 = s1 = s2 = 0;
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
      else if (poplist[a] == 2) {
        if (geno[a] == '0')
          ++n2;
        else if (geno[a] == '1') {
          ++n2;
          ++s2;
        }
        else if (geno[a] == '2') {
          ++n2;
          s2 += 2;
        }
      }
    }
    if (n1>0 && n2>0) {
      piW1 += (double) s1 * (2*n1 - s1) / (n1 * (2*n1 - 1));
      piW2 += (double) s2 * (2*n2 - s2) / (n2 * (2*n2 - 1));
      piB += (double) (s1 * (2*n2-s2) + s2 * (2*n1-s1)) / (4 * n1 * n2);
    }
  }
  printf("%.3f\t%.3f\t%.3f\t%.4f\n", piW1, piW2, piB, 1. - (piW1+piW2)/(2*piB));
}
