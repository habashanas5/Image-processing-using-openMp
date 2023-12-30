Code Structure:
The code first reads the kernel and image data from the input files.
OpenMP directives are then used to parallelize the convolution operation. The parallel region is controlled using #pragma omp parallel num_threads(num_threads), and a reduction is applied to the sum variable to avoid race conditions.
Timing information is collected to measure the execution time of the parallelized code.

Parallelization Strategy:
The convolution operation is parallelized using nested OpenMP parallelism. The outer two loops iterate over the result image dimensions, and the inner two loops perform the convolution. The reduction(+:sum) clause ensures correct accumulation of partial sums from different threads.
The number of threads is set using omp_set_num_threads.

Timing Data:
The code records the start and end times of the parallel region using clock() functions.
The execution time is calculated and printed to the console.

Speedup Calculation:
Speedup is calculated by comparing the execution time of the parallel code to the execution time of the equivalent serial code.
Speedup = Serial Execution Time / Parallel Execution Time.

Usage:
The code is executed from the command line with the following format:
 ./parallelized_code oimage.txt edge.txt output2.txt 5
 
Results and Conclusion:
The timing data and speedup values provide insights into the efficiency of the parallel implementation. The speedup should ideally increase with the number of threads, demonstrating the benefits of parallelism.
The user can experiment with different thread counts to observe the impact on performance.
