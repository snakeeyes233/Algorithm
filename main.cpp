// Insertionsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sort.h"
#include <unistd.h>
#include <sys/time.h>
#include "random_generator.h"
#include "timer.h"
#include <string.h>

using namespace std;
int main(int argc, char* argv[])
{
	int D1 = 1;
	int D2 = 0;
	int Direction = 0;

	if (argc > 1)
	{
		D1 = atoi(argv[1]);
		D1 = max(D1, 1);
	}
	else
	{
		cout << "hw1: [m] [n] [direction]" << endl;
		cout << "[m]              size of the random integer vector array" << endl;
		cout << "[n]              dimension of integer vector array" << endl;
		cout << "[direction]      0: random" << endl;
		cout << "                 1: sorted" << endl;
		cout << "                 -1: reverse sorted" << endl;
		cout << endl;
		return 0;
	}

	if (argc > 2)
	{
		D2 = atoi(argv[2]);
		D2 = max(D2, 0);
	}

	if (argc > 3)
		Direction = atoi(argv[3]);

    random_generator rg;
    timer t;

    int** input_array;

    t.start();
    if (Direction == 0)
        input_array = sort::create_random_ivector(D2, D1, true);
    else
    {
        if (Direction < 0)
            input_array = sort::create_reverse_sorted_ivector(D2, D1);
        else
            input_array = sort::create_sorted_ivector(D2, D1);
    }
    t.stop();

    cout << "Timer (generate): " << t << endl;

/*
 * output the first 20 elements for debugging purposes
 */
    for (int i = 0; (i < D1) && (i < 20); i++)
    {
        cout << "[ ";
        for (int j = 0; j < D2; j++)
            cout << input_array[i][j] << " ";
        cout << "]" << endl;
    }
    cout << endl;

/*
 * Do naiv insertion sort
 */
    cout << "Running insertion sort algorithm: " << endl;
    t.start();
	//sort::insertion_sort(input_array, D2, 0, D1-1);
	//sort::insertion_sort_im(input_array, D2, 0, D1-1);
        sort::merge_sort(input_array, D1,D2);
    t.stop();

    cout << "Timer (sort): " << t << endl;

/*
 * check whether or not the algorithm sorted the array
 */
    if (sort::check_sorted(input_array, D2, 0, D1-1))
        cout << "The output is sorted!" << endl;
    else
        cout << "ERROR: The output is not sorted!" << endl;

/*
 * output the first 20 elements for debugging purposes
 */
    for (int i = 0; (i < D1) && (i < 20); i++)
    {
        cout << "[ ";
        for (int j = 0; j < D2; j++)
            cout << input_array[i][j] << " ";
        cout << "]" << endl;
    }
    cout << endl;

/*
 * free the allocated storage
 */
	sort::remove_ivector(input_array, D1);

    return 0;


//int main()
//{

   // int D1 = 2500000;
   // int D2 = 10;
//
   // int imT = 10;
    //int** pAA = sort::create_random_ivector(D2, D1,true);	
  	//int** pAA = sort::create_sorted_ivector(D2, D1);
  	//int** pAA = sort::create_reverse_sorted_ivector(D2, D1); 
    
		
   // struct timeval beforeNaive;
   // gettimeofday(&beforeNaive,NULL);

   // for (int i = 0; i < imT; ++i)
  //  {
	  
        
//
//	sort::insertion_sort(pAA, D2, 0, D1 - 1);
	//  sort::merge_sort(pAA,D1,D2);
	// 	
   // }

   // struct timeval afterNaive;
   // gettimeofday(&afterNaive,NULL);

   // double time = (afterNaive.tv_sec*1000 + afterNaive.tv_usec/1000) - (beforeNaive.tv_sec*1000 + beforeNaive.tv_usec/1000);
   // printf("Naive Isort - Time: %.2f ms. D1: %d. D2: %d.\n", time / imT, D1, D2);
   // printf("Merge Isort - Time: %.2f ms. D1: %d. D2: %d.\n", time / imT, D1, D2);
    
   //sort::remove_ivector(pAA,D1);
	
//    /////////////////////////////

    //int** pIM = sort::create_random_ivector(D2, D1, true);
    //int** pIM = sort::create_sorted_ivector(D2, D1);
   // int** pIM = sort::create_reverse_sorted_ivector(D2, D1);
   // struct timeval beforeIM;
   // gettimeofday(&beforeIM, NULL);

   // for (int i = 0; i < imT; ++i)
  //  {
     //   sort::insertion_sort_im(pIM, D2, 0, D1 - 1);
   // }

   // struct timeval afterIM;
   // gettimeofday(&afterIM, NULL);

   // double timeIM = (afterIM.tv_sec * 1000 + afterIM.tv_usec / 1000) - (beforeIM.tv_sec * 1000 + beforeIM.tv_usec / 1000);
   // printf("im Isort - Time: %.2f ms. D1: %d. D2: %d.\n", timeIM / imT, D1, D2);
   
//
}











