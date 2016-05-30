#include <stdio.h>
#include <stdlib.h>

// Fake boolean values
#define TRUE    (1)
#define FALSE   (0)

// Candidates used at every recursive call
#define MAX_CANDIDATES 2

// Define the "bool" type using "short int"
typedef short int bool;
static bool finished = FALSE;

bool reject(int* curr_sol, int curr_sol_size, int input) {
    return FALSE; // EMPTY for now
}

bool accept(int* curr_sol, int curr_sol_size, int input) {
    return (curr_sol_size == input);
}

void output(int* curr_sol, int curr_sol_size, int input) {
    static int i;
    printf("[ ");
    for ( i = 0; i < input; ++i ) {
        printf("%d ", curr_sol[i]);
    }
    printf("]\n");
}

void extend_solution(int* curr_sol, int curr_sol_size, int input, int* candidates, int* num_candidates) {
    // Only 2 possibilities: the element is take or not taken
//    candidates[0] = TRUE;
//    candidates[1] = FALSE;
    *num_candidates = input - curr_sol_size;
}


void revert(int *curr_sol, int curr_sol_size, int input) {
    int temp = curr_sol[curr_sol_size];
    curr_sol[curr_sol_size]  = curr_sol[input];
    curr_sol[input] = temp;
    // EMPTY for now
}

void try(int *curr_sol, int curr_sol_size, int input) {
    revert(curr_sol, curr_sol_size, input);
}
void backtrack(int *curr_sol, int curr_sol_size, int input) {
    int candidates[MAX_CANDIDATES];
    int num_candidates;
    int i;

    printf("backtrack(%d %d);",curr_sol_size, input);

    if ( reject(curr_sol, curr_sol_size, input) ) {
        return; // Not worth completing
    }

    if ( accept(curr_sol, curr_sol_size, input) ) {
        output(curr_sol, curr_sol_size, input); // Found! Print it
    } else {
        ++curr_sol_size; // Increase solution size

        // Generate solution extension
        extend_solution(curr_sol, curr_sol_size, input, candidates, &num_candidates);
        // Try every candidates just generated
        for ( i = curr_sol_size; i <=num_candidates; ++i ) {
 //           curr_sol[curr_sol_size] = candidates[i];
	    printf("swapping %d %d\n",curr_sol[curr_sol_size],curr_sol[i]);
            try(curr_sol, curr_sol_size-1, i);
            backtrack(curr_sol, curr_sol_size, input);
            revert(curr_sol, curr_sol_size-1, i);

            if ( finished ) return; // Early termination
        }
    }
}

void print_all_subset_from_1_to(int n) {
    int *sol;
    sol = malloc(n * sizeof(int));
    for (int i=0;i<n;i++) {
	sol[i] = i+1;
    }
    backtrack(sol, 0, n);
    free (sol);
}

int main(int argc, char** argv) {
    int input;
    if ( argc == 2 ) input = atoi(argv[1]); else return (EXIT_FAILURE);

    print_all_subset_from_1_to(input);
}
