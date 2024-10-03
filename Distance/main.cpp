#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include "dictance.h"
int main() {
    /// ���������� ������� (x, y)
    setlocale(LC_ALL, "RU");
    std::vector<std::pair<double, double>> cities = {
        {0, 0},  // ����� A
        {1, 3},  // ����� B
        {4, 3},  // ����� C
        {6, 1}   // ����� D
    };

    travelingSalesman(cities); // Correct call
    return 0;
}