/*
 * Non-deterministic Random Number Generator for Multi-Process
 * Usage in scenarios requiring randomness across processes.
 */

/* Include files */
#include <stdio.h>
#include <stdlib.h>     // For rand() and srand()
#include <time.h>       // For high-resolution time
#include <unistd.h>     // For getpid()

/* Function Definitions */

// Initializes the random number generator with high entropy
void initialize_random() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts); // High-resolution time
    unsigned int seed = (unsigned int)(ts.tv_nsec ^ ts.tv_sec ^ getpid());
    srand(seed); // Seed with combined entropy
}

void b_rand(double varargin_1, double varargin_2, double r_data[], int r_size[2]) {
    int i;
    int k;
    r_size[0] = (int)varargin_1;
    r_size[1] = (int)varargin_2;
    i = (int)varargin_1 * (int)varargin_2;
    initialize_random(); // Initialize random number generator
    for (k = 0; k < i; k++) {
        // printf("DEBUG:Random Number: %f\n", (double)rand() / RAND_MAX); // Debugging: Print random number
        // fflush(stdout);
        r_data[k] = (double)rand() / RAND_MAX; // Normalize to [0, 1]
    }
}

double c_rand(void)
{
    initialize_random(); // Initialize random number generator
    return (double)rand() / RAND_MAX; // Generate a random double in [0, 1]
}

void d_rand(const double varargin_1[2], double r_data[], int r_size[2])
{
    int i;
    int k;
    r_size[0] = 1;
    i = (int)varargin_1[1];
    r_size[1] = (int)varargin_1[1];
    initialize_random(); // Initialize random number generator
    for (k = 0; k < i; k++) {
        r_data[k] = (double)rand() / RAND_MAX; // Normalize to [0, 1]
    }
}

/* End of code generation */
