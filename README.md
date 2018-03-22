# divergence-distance-stats
Repository for scripts related to the calculation of genomic divergence and distance statistics

## tableFstPi
Usage:  
```
$ cat genotypes_table | tableFstPi n pop1 pop2
```
This is a C script (we compiled the provided executable on an Ubuntu system) that takes a specific input file giving the genotype of each individual (genotypes_table) and requires you to specify "n", the total number of individuals in the input file and provide two files that denote the samples in each population (pop1 and pop2).  
  
The script's output consists of four tab-separated values:  
π<sub>Within</sub> population 1  
π<sub>Within</sub> population 2  
π<sub>Between</sub> populations 1 and 2  
_F<sub>ST</sub>_ between populations 1 and 2  
  
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
π<sub>Within</sub> the population  
π<sub>Within</sub> population 2  
π<sub>Between</sub> populations 1 and 2  
_F<sub>ST</sub>_ between populations 1 and 2  
  
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

 {\displaystyle {{\hat {\theta }}_{w}}} {{\hat  \theta }_{w}}

## Citing the repository
### Authorship
Code author: Jeffrey D. Wall  
README.md author: <a href="https://orcid.org/0000-0002-0210-7261" target="orcid.widget" rel="noopener noreferrer" style="vertical-align:top;"><img src="https://orcid.org/sites/default/files/images/orcid_16x16.png" style="width:1em;margin-right:.5em;" alt="ORCID iD icon">Zachary R. Hanna</a> . 

Please cite this repository as follows (replace XXXX with the version used):  
Wall JD, <a href="https://orcid.org/0000-0002-0210-7261" target="orcid.widget" rel="noopener noreferrer" style="vertical-align:top;"><img src="https://orcid.org/sites/default/files/images/orcid_16x16.png" style="width:1em;margin-right:.5em;" alt="ORCID iD icon">Hanna ZR</a>. 2018. divergence-distance-stats. Version XXXX. _Zenodo_. DOI:  
