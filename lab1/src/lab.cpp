#include <iostream>
#include <chrono>
#include <math.h>

#define EPS 1e-17


long double dummy_asin(double x);

int main() {
    auto start_time = std::chrono::steady_clock::now();

    dummy_asin(0.98);

    auto end_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    std::cout << "Время работы программы: " << elapsed_seconds.count() << " секунд" << std::endl;
    return 0;
}

long double dummy_asin(double x) {
    long double sum = x;
    long double term = x;

    for (int n = 0; fabs(term) > EPS; n++) {
      term = x * x * term * (2 * n + 1) * (2 * n + 1) * (2 * n + 2) /
             (4 * (n + 1) * (n + 1) * (2 * n + 3));
      sum += term;
    }
    sum = (double)sum;

    return sum;
}
