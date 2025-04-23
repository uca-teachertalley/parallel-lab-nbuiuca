Prime number count parallelism exercise
1)
the average time for ten runs of the serial version of the code is 0.2867678 
2)
the average time for ten runs of the parallel version of the code is 0.07924219
3)
the speedup of the parallel version is 72.38%, also the parallel version is over three times faster.So that means the parallel code 
significantly faster than the serial code
4) OpenMP used 12 threads to process an array of 1,000,000 elements 
and Each thread printed that it was assigned for approximately 83,333 elements
5) the serial version average runtime: 0.001167 seconds
   the parallel version average runtime: 0.000258 seconds
   The parallel version was significantly faster than the serial version by 4.52 times and 77.88% faster
- This code counts the number of primes in an array without parallelism
- Your goal is to add parallelism with OpenMP!
- The project should be configured properly, but you can add OpenMP to 
  Visual Studio project by going to Project Properties-C/C++-Language.
  Set the Open MP Support option to "Yes"