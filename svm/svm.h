#ifndef SVM_H
#define SVM_H

#include <vector>

class SVM {
private:
    std::vector<std::vector<double>> X; // Training data
    std::vector<int> y; // Labels
    std::vector<double> alphas; // Lagrange multipliers
    double C; // Regularization parameter

    void train();
    double kernel(const std::vector<double>& x1, const std::vector<double>& x2) const;

public:
    SVM(const std::vector<std::vector<double>>& X, const std::vector<int>& y, double C);
    std::vector<int> predict(const std::vector<std::vector<double>>& X_test) const;
};

#endif // SVM_H
