//This file is entirely for your test purposes. 
//This will not be evaluated, you can change it and experiment with it as you want.
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include "the1.h"

//the1.h only contains declaration of the function sillySort  and crossMergeSort which are:
//int sillySort(int* arr, long &comparison, long & swap, int size) ;
//int crossMergeSort(int *arr, long &comparison, int size);

using namespace std;

void randomFill(int*& arr, int size, int minval, int interval)
{
    int array[256] ={3977,
21668,
27290,
5656,
13295,
36,
22088,
24519,
10998,
12309,
21410,
23408,
2840,
2972,
28044,
10101,
31740,
21326,
31636,
12606,
6464,
18665,
15061,
31370,
29301,
16194,
28186,
18690,
19563,
26239,
18759,
29716,
1967,
10374,
11253,
17662,
20563,
10678,
28509,
7465,
31469,
16852,
19319,
22201,
13026,
328,
5987,
4962,
24037,
5769,
26887,
28029,
22714,
10198,
22522,
16219,
28992,
29991,
26528,
29913,
16814,
22115,
23703,
6964,
20765,
27091,
338,
8991,
7495,
1751,
7684,
2323,
29070,
18647,
10176,
22503,
12096,
18045,
27358,
14752,
27417,
18721,
13472,
2698,
1033,
6277,
16406,
8840,
5944,
11971,
27198,
18600,
30024,
26755,
29040,
1274,
31962,
1393,
17401,
17571,
32339,
3311,
8711,
1069,
3296,
27398,
5829,
29729,
24759,
22947,
3270,
19416,
11936,
27136,
423,
16014,
6324,
16992,
7408,
18104,
7269,
25599,
11836,
15255,
8639,
3401,
22170,
25870,
4078,
3146,
24882,
433,
2815,
5478,
3884,
29470,
16107,
29258,
23245,
1168,
23505,
7458,
30179,
32689,
10115,
7180,
1892,
944,
18500,
12493,
27730,
21140,
11472,
12484,
32737,
2256,
13725,
6428,
11996,
29463,
865,
13125,
23109,
30321,
3796,
23972,
19772,
16015,
28087,
19593,
18977,
9819,
26901,
22370,
29437,
3796,
18633,
9775,
4382,
6169,
30784,
21302,
2,
28867,
26752,
21752,
16247,
12152,
21353,
17507,
28927,
27326,
17467,
21321,
17529,
780,
2393,
1809,
6142,
21287,
29517,
2989,
20234,
15020,
1291,
13004,
9436,
14056,
31098,
29520,
32287,
32240,
16944,
32002,
32201,
20462,
25469,
13444,
24900,
29370,
20908,
11144,
26572,
2986,
13189,
26944,
18712,
19370,
11799,
5909,
32572,
8591,
7604,
26012,
26574,
26280,
24636,
15814,
71,
14742,
5279,
4695,
16813,
31582,
29597,
26009,
24431,
8893,
9680,
22353,
28049,
22972,
15085,
20210,
12808,
6531};	
	arr = new int [256];
	for (int i=0; i <256; i++)
	{
		arr[i] = array[i];
	}
}

void print_to_file(int* arr, int size)
{
	ofstream ofile;
	ofile.open("sorted.txt");
	for(int i=0;i<size; i++) 
		ofile<<arr[i]<<endl;
}

void read_from_file(int*& arr, int& size)
{

	char addr[]= "input01.txt";
	ifstream infile (addr);
	
	if (!infile.is_open())
	{
		cout << "File \'"<< addr 
			<< "\' can not be opened. Make sure that this file exists." <<endl;
		return;
	}
	infile >> size;
	arr = new int [size];
	
	for (int i=0; i<size;i++) {
		
		infile >> arr[i];
	}
	
}
	

void test()
{
	
	clock_t begin, end;
	double duration;
	
	//data generation and initialization- you may test with your own data
	long comparison=0;
	long swap=0;
	int num_of_calls;
	int size= 1 << 11;	 // maximum 2^11 for sillySort and 2^16 ( 1 << 16) for crossMergeSort 
	int minval=0;
	int interval= size*2; // you can try to minimize interval for data generation to make your code test more equality conditions
	int *arr;
	
	//Randomly generate initial array:
	randomFill(arr, size, minval, interval);
	
	//Read the test inputs. input01.txt through input04.txt exists.
	//read_from_file(arr, size);
	
	//data generation or read end
	
	if ((begin = clock() ) ==-1) 
		cerr << "clock error" << endl;
	
	//Function call for the solution
	
	num_of_calls=sillySort(arr, comparison, swap, 256) ;
	
	//num_of_calls=crossMergeSort(arr, comparison, 256);
	
	//Function end
	
	if ((end = clock() ) ==-1) 
		cerr << "clock error" << endl;
	
	//Calculate duration and print output
	
	duration = ((double) end - begin) / CLOCKS_PER_SEC;
	cout << "Duration: " << duration << " seconds." <<endl;
	for(int i=0;i<8;i++){
	    cout << "Array:" << arr[i] <<endl;
	}
	cout<<"Number of Comparisons: " << comparison <<endl;
	cout<<"Number of sillySort or crossMergeSort calls: " << num_of_calls <<endl;
	cout<<"Number of Swaps(0 for crossMergeSort): " << swap <<endl;
	print_to_file(arr,size);
	//Calculation and output end
	
}

int main()
{
	srandom(time(0));
	test();
	return 0;
}
	
	