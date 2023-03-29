#include <utils.h>

#include <string>
#include <math.h>
#include <vector>
#include <spdlog/spdlog.h>

std::string add(std::vector<double> list){
    double sum{0};

    for(auto num : list){
        sum += num;
    }

    return std::to_string(sum);
}
std::string subtract(std::vector<double> list){
    double diff{0};
    bool is_set{false};
    
    for(auto num : list){
        if(!is_set){
            diff += num;
            is_set = true;
        }
        else{
            diff -= num;
        }
    }

    return std::to_string(diff); 
}
std::string multiply(std::vector<double> list){
    double prod{0};
    bool is_set{false};

    for(auto num : list){
        if(!is_set){
            prod += num;
            is_set = true;
        }
        else{
            prod *= num;
        }
    }

    return std::to_string(prod);
}
std::string divide(std::vector<double> list){
    double quotient{0};
    bool is_set{false};

    for(auto num : list){
        if(!is_set){
            quotient += num;
            is_set = true;
        }
        else{
            quotient /= num;
        }
    }

    return std::to_string(quotient);
}
