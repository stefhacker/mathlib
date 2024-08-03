#include "svm.h"
#include <iostream>
#include <cmath>
#include <cassert>

SVM::SVM(const std::vector<std::vector<double>>& X, const std::vector<int>& y, double C)
    : X(X), y(y), C(C) {
    alphas.resize(X.size(), 0.0);
    train();
}

double SVM::kernel(const std::vector<double>& x1, const std::vector<double>& x2) const {
    assert(x1.size() == x2.size());
    double sum = 0.0;
    for (size_t i = 0; i < x1.size(); ++i) {
        sum += (x1[i] * x2[i] + 5) * (x1[i] * x2[i] + 5);
    }
    return sum; // Linear kernel
}

void SVM::train() {
    size_t n = X.size();
    // Simplified optimization
    for (size_t i = 0; i < n; ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < n; ++j) {
            sum += alphas[j] * y[j] * kernel(X[i], X[j]);
        }
        alphas[i] = std::max(0.0, std::min(C, sum)); // Dummy optimization
    }
}

std::vector<int> SVM::predict(const std::vector<std::vector<double>>& X_test) const {
    std::vector<int> predictions(X_test.size());
    for (size_t i = 0; i < X_test.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < X.size(); ++j) {
            sum += alphas[j] * y[j] * kernel(X_test[i], X[j]);
        }
        predictions[i] = sum > 0 ? 1 : -1;
    }
    return predictions;
}
