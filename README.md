# diversity-divergence-stats
Repository for scripts related to the calculation of genomic diversity and divergence statistics

## tableFstPi
Usage:  
```
$ cat genotypes_table | tableFstPi n pop1 pop2
```
This is a C script (we compiled the provided executable on an Ubuntu system) that takes a specific input file giving the genotype of each individual (genotypes_table) and requires you to specify "n", the total number of individuals in the input file and provide two files that denote the samples in each population (pop1 and pop2).  
  
The script's output consists of four tab-separated values:  
π<sub>Within</sub> population 1 (Nei & Li, 1979)  
π<sub>Within</sub> population 2  
π<sub>Between</sub> populations 1 and 2 (Nei & Li, 1979)  
_F<sub>ST</sub>_ between populations 1 and 2 (Hudson, Slatkin & Maddison, 1992)  
  
The format of the genotypes_table file is as follows:  
Each line represents a separate biallelic variant.  
Each column represents a separate individual.  
Genotypes are coded as: 0 for homozygous reference, 1 for heterozygote, 2 for homozygous alternate, N for missing data.  
  
The format of the population files is as follows:  
Line 1: the number of individuals in this population  
Line 2: space-delimited sequence of numbers (1-based coordinates) corresponding to the columns of the samples in the population.  
  
We have provided a mock genotypes_table file and corresponding population files as an example.  
Usage example:  
```
$ cat example_table | tableFstPi 5 pop1 pop2
```

## tablePiTheta
Usage:  
```
$ cat genotypes_table | tablePiTheta n pop
```
This is a C script (we compiled the provided executable on an Ubuntu system) that takes a specific input file giving the genotype of each individual (genotypes_table) and requires you to specify "n", the total number of individuals in the input file and provide a file that denotes the samples in the population of interest (pop).  
  
The script's output consists of two tab-separated values:  
π<sub>Within</sub> the population (Nei & Li, 1979)  
Watterson's theta (Watterson, 1975)    
  
The format of the genotypes_table file is as follows:  
Each line represents a separate biallelic variant.  
Each column represents a separate individual.  
Genotypes are coded as: 0 for homozygous reference, 1 for heterozygote, 2 for homozygous alternate, N for missing data.  
  
The format of the population file is as follows:  
Line 1: the number of individuals in the population  
Line 2: space-delimited sequence of numbers (1-based coordinates) corresponding to the columns of the samples in the population.  
  
We have provided a mock genotypes_table file and population file as an example.  
Usage example:  
```
$ cat example_table | tableFstPi 5 pop1
```

## Citing the repository
### Authorship
Code author: Jeffrey D. Wall  
README.md author: <a href="https://orcid.org/0000-0002-0210-7261" target="orcid.widget" rel="noopener noreferrer" style="vertical-align:top;"><img src="https://orcid.org/sites/default/files/images/orcid_16x16.png" style="width:1em;margin-right:.5em;" alt="ORCID iD icon">Zachary R. Hanna</a> . 

Please cite this repository as follows (replace XXXX with the version used):  
Wall JD, <a href="https://orcid.org/0000-0002-0210-7261" target="orcid.widget" rel="noopener noreferrer" style="vertical-align:top;"><img src="https://orcid.org/sites/default/files/images/orcid_16x16.png" style="width:1em;margin-right:.5em;" alt="ORCID iD icon">Hanna ZR</a>. 2018. diversity-divergence-stats. Version XXXX. _Zenodo_. DOI: [![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.1205635.svg)](https://doi.org/10.5281/zenodo.1205635)  

## References
Hudson RR., Slatkin M., Maddison WP. 1992. Estimation of Levels of Gene Flow from DNA Sequence Data. _Genetics_ 132:583–589.  
  
Nei M., Li WH. 1979. Mathematical model for studying genetic variation in terms of restriction endonucleases. _Proceedings of the National Academy of Sciences of the United States of America_ 76:5269–5273.  
  
Watterson GA. 1975. On the number of segregating sites in genetical models without recombination. _Theoretical Population Biology_ 7:256–276. DOI: 10.1016/0040-5809(75)90020-9.  
