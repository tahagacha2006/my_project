#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Question 2.1 : Algorithme naïf (teste la divisibilité de chaque nombre)
bool is_prime_naive(int k) {
    if (k < 2) return false;
    for (int i = 2; i < k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}

int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime_naive(i)) {
            count++;
        }
    }
    return count;
}

// Question 2.2 : Algorithme efficace 
int count_primes_sieve(int n) {
    if (n <= 2) return 0;

    // Tableau de booléens initialisé à true (1)
    bool *is_prime = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    // Élimination des multiples
    for (int p = 2; p * p < n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Comptage des nombres premiers restant
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    free(is_prime);
    return count;
}

// Question 2.4 : Comparaison des temps d'exécution
int main() {
    int n = 100000; 
    // Mesure de l'algorithme naïf
    clock_t start_naive = clock();
    int count_naive = count_primes_naive(n);
    clock_t end_naive = clock();
    double time_naive = (double)(end_naive - start_naive) / CLOCKS_PER_SEC;

    // Mesure du Crible d'Ératosthène
    clock_t start_sieve = clock();
    int count_sieve = count_primes_sieve(n);
    clock_t end_sieve = clock();
    double time_sieve = (double)(end_sieve - start_sieve) / CLOCKS_PER_SEC;

    printf("Naif   (n = %d) : %d premiers | Temps : %f s\n", n, count_naive, time_naive);
    printf("Crible (n = %d) : %d premiers | Temps : %f s\n", n, count_sieve, time_sieve);

    return 0;
}