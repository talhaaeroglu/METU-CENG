You are asked to sort the given array $arr$ with Radix Sort ascending or descending depending on the boolean variable $ascending$ and return the number of iterations done in the loops of the Counting Sort algorithm (you need to use Counting Sort as a subroutine in the Radix Sort). $n$ is the number of elements. You are expected to use Counting Sort for $l$ digits at each time.

IMPORTANT: Different than the algorithm for Counting Sort in your book, initialize count array as int* C = new int[k] and use the fourth loop for copying the array back. Otherwise the return value of the function (as the number of iterations) will not be evaluated as correct.

Constraints:
Maximum array size will be 1000000. 
Array elements will be strings each of which can contain only the characters as uppercase English letters (i.e. from 'A' to 'Z').
For the sake of simplicity, it is guaranteed that the strings in the array will always have the same length. This length can be at most 12.
$l$ may take values 1,2,3,4 or 6.
Evaluation:

After your exam, black box evaluation will be carried out. You will get full points if you fill the $arr$ variable as stated and return the number of iterations correctly for the cases that will be tested.
Example IO:

1) Given array arr = {"AAA", "ABC", "ABA", "CCB"}, size = 4,  l = 1, ascending = true:

fill arr = { "AAA",  "ABA",  "ABC", "CCB" }
return 114
2) Given array arr = {"BAAA", "AABC", "CDBA", "CACB", "ABAB", "ACAB", "CBCB"}, size = 7  l = 1, ascending = true:

fill arr = { "AABC", "ABAB", "ACAB", "BAAA", "CACB", "CBCB", "CDBA" }
return 188
3) Given array arr = {"BAAA", "AABC", "CDBA", "CACB", "ABAB", "ACAB", "CBCB"}, size = 7  l = 2, ascending = true:

fill arr = { "AABC", "ABAB", "ACAB", "BAAA", "CACB", "CBCB", "CDBA"}
return 1394
4) Given array arr = {"BAAA", "AABC", "CDBA", "CACB", "ABAB", "ACAB", "CBCB"}, size = 7,  l = 3, ascending = false:

fill arr = { "CDBA", "CBCB", "CACB", "BAAA", "ACAB", "ABAB", "AABC" }
return 17644
5) Given array arr = { "NWLRBBMQBHCD", "ARZOWKKYHIDD", "QSCDXRJMOWFR", "XSJYBLDBEFSA", "RCBYNECDYGGX", "XPKLORELLNMP", "APQFWKHOPKMC", "OQHNWNKUEWHS", "QMGBBUQCLJJI", "VSWMDKQTBXIX" }, size = 10,  l = 3, ascending = true:

fill arr = { "APQFWKHOPKMC", "ARZOWKKYHIDD", "NWLRBBMQBHCD", "OQHNWNKUEWHS", "QMGBBUQCLJJI", "QSCDXRJMOWFR", "RCBYNECDYGGX", "VSWMDKQTBXIX", "XPKLORELLNMP", "XSJYBLDBEFSA" }
return 70424 