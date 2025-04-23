/*-- prime_count_serial.cpp-----------------------------------------------------------
   This file implements a program that fills an arry with numbers and 
   then counts the prime numbers in the array
-------------------------------------------------------------------------*/

#include <iostream>
#include <chrono>
#include <cmath>
#include <omp.h>

using namespace std;

// gen_numbers
// This function adds numbers to an array
void gen_numbers(long int numbers[], long int how_many)
{
#pragma omp parallel for
	for (int i = 0; i < how_many; i++)
	{
		numbers[i] = i;
	}
}

// This function determines if a number is a prime number
bool is_prime(long int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// This function walks through an array and counts the prime numbers
int count_prime_parallel(long int numbers[], long int how_many)
{
	int count = 0;
#pragma omp parallel
	{
#pragma omp critical
		{
			cout << "Thread number " << omp_get_thread_num() << endl;
			cout << "TOTAL THREAD " << omp_get_num_threads() << endl;
			cout << "The number of the elements is " << how_many / omp_get_num_threads() << endl;
		}
#pragma omp for reduction(+:count)
			for (int i = 0; i < how_many; i++)
			{
				if (is_prime(numbers[i]))
					count++;
			}
		
	}
	return count;
}


// This is the entrypoint into the program
int main() {
	long int n = 1000000;
	long int* numbers = new long int[n];

	cout << "Generating numbers..." << endl;
	// Generate numbers first
	gen_numbers(numbers, n);

	cout << "Counting primes..." << endl;
	// Count primes, use chrono to time the function
	auto start = chrono::steady_clock::now();
	gen_numbers(numbers, n);
	//int count = count_prime_parallel(numbers, n);
	auto end = chrono::steady_clock::now();

	// Print results
	double compute_time = chrono::duration<double>(end - start).count();
	//cout << "Total number of primes = " << count << endl;
	cout << "Total computation time = " << compute_time << endl;

	return 0;
}





