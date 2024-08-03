#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "svm.h"

// Function to generate random data
void generate_data(std::vector<std::vector<double>>& X, std::vector<int>& y, size_t num_points, bool add_labels = true) {
    X.resize(num_points);
    y.resize(num_points);

    for (size_t i = 0; i < num_points; ++i) {
        X[i].resize(100); // Assuming 100 features
        X[i][0] = (rand() % 100) / 10.0; // Random float between 0 and 10
        X[i][1] = (rand() % 100) / 10.0; // Random float between 0 and 10
        if (add_labels) {
            y[i] = (rand() % 2 == 0 ? 1 : -1); // Random label (1 or -1)
        }
    }
}

// Function to split data into training and testing sets
void split_data(const std::vector<std::vector<double>>& X, const std::vector<int>& y, 
                 std::vector<std::vector<double>>& X_train, std::vector<int>& y_train, 
                 std::vector<std::vector<double>>& X_test, std::vector<int>& y_test, 
                 size_t train_size) {
    X_train.assign(X.begin(), X.begin() + train_size);
    y_train.assign(y.begin(), y.begin() + train_size);
    X_test.assign(X.begin() + train_size, X.end());
    y_test.assign(y.begin() + train_size, y.end());
}

int main() {
    std::srand(std::time(nullptr)); // Seed for random number generation

    // Generate data
    std::vector<std::vector<double>> X;
    std::vector<int> y;
    size_t num_train = 5000;
    size_t num_test = 100;
    generate_data(X, y, num_train + num_test); // Generate all data

    // Split data into training and testing sets
    std::vector<std::vector<double>> X_train, X_test;
    std::vector<int> y_train, y_test;
    split_data(X, y, X_train, y_train, X_test, y_test, num_train);

    // Train SVM
    double C = 1.0;
    SVM svm(X_train, y_train, C);

    // Predict on test data
    std::vector<int> predictions = svm.predict(X_test);

    

    return 0;
}
