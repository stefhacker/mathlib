#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <cstdlib> 
#include <ctime>


namespace plt = matplotlibcpp;



const double PI = 3.14159265358979323846;

double normal_density(double x){
    double result = (1/std::sqrt(2 * PI)) * std::exp(-1/2 * (x * x));
    return result;
}



// to-do: do this with mersenne twister
double generateUniform() {
    return static_cast<double>(rand()) / RAND_MAX; 
}


//Metropolis-Hasting for uniform distribution as proposal distribution

std::vector<double> metropilis_hasting(int n_samples, double (*target_distribution)(double x) ){
    double initial_value = 0;
    std::vector<double> samples(n_samples);
    for(int i ; i < n_samples; i++){
        double candidate = generateUniform();
        double acceptence_prob = normal_density(candidate)/normal_density(initial_value);
        if(acceptence_prob >= 1){
            acceptence_prob = 1;
        }
        double u = generateUniform();
        if(u <= acceptence_prob){
            samples[i] = candidate;
            initial_value = candidate;
        }
        else{
            
            samples[i] = initial_value;
            
        }

    }
    return(samples);
}



int main(){
    std::vector<double> samples = metropilis_hasting(1000, normal_density);

     
    for (std::size_t i = 0; i < samples.size(); ++i) {
        std::cout << samples[i] << " ";
    }
    std::cout << std::endl;

    plt::plot(samples);
    plt::title("Simple Plot");
    plt::xlabel("X-axis");
    plt::ylabel("Y-axis");
    plt::show();
    

    return 0; 
}