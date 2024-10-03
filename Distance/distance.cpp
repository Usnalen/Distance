#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <numeric>

// ������� ��� ���������� ���������� ����� ����� ��������
double calculateDistance(const std::pair<double, double>& city1, const std::pair<double, double>& city2) {
    return std::sqrt(std::pow(city1.first - city2.first, 2) + std::pow(city1.second - city2.second, 2));
}

// ������� ��� ���������� ������ ���������� ��������
double totalDistance(const std::vector<int>& route, const std::vector<std::pair<double, double>>& cities) {
    double distance = 0.0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        distance += calculateDistance(cities[route[i]], cities[route[i + 1]]);
    }
    distance += calculateDistance(cities[route.back()], cities[route.front()]); // ������������ � ��������� �����
    return distance;
}

// �������� ������� ��� ������� ������ ������������
void travelingSalesman(const std::vector<std::pair<double, double>>& cities) {
    if (cities.size() < 2) {
        std::cout << "Not enough cities to form a route." << std::endl;
        return;
    }

    int n = cities.size();
    std::vector<int> route(n);
    iota(route.begin(), route.end(), 0); // ��������� ������� �������� �������

    double minDistance = std::numeric_limits<double>::infinity();
    std::vector<int> bestRoute;

    do {
        double currentDistance = totalDistance(route, cities);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute = route;
        }
    } while (std::next_permutation(route.begin(), route.end())); // ������ ������� �������

    // ������� ���������
    std::cout << "������ �������: ";
    for (int city : bestRoute) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    std::cout << "����������� ����������: " << minDistance << std::endl;
}
