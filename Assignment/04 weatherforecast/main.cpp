/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 5/10/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <ranges>

// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template<typename T>
requires std::is_arithmetic_v<T> 
double convert_f_to_c(T temperature){
    return static_cast<double>((temperature - 32)* 5 / 9);
}


template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<double>> readings, Function fn) {
    // TODO: write get_forecast here!
    std::vector<double> res;
    for(auto &day: readings){
        res.push_back(fn(day));
    }
    return res; 
}

int main() {
    std::vector<std::vector<double>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };
    std::string file = R"(D:\code\code_vscode\cpp\CS106L\Assignment\04 weatherforecast\output.txt)";
    std::ofstream outputfile(file);
    // TODO: Convert temperatures to Celsius and output to output.txt
    outputfile << "1.Temperatures to Celsius: " << std::endl;
    for(const auto& days: readings){
        for(const auto& tmp: days){
            auto op = convert_f_to_c(tmp);
            outputfile << op << " ";
        }
        outputfile << std::endl;
    }
    outputfile << std::endl;
    // TODO: Find the maximum temperature for each day and output to output.txt
    auto max_tmp = get_forecast(readings,[](const std::vector<double>& wea) -> double{
        return *std::ranges::max_element(wea);
    });
    outputfile << "2.Max tempertaure of a day." << std::endl;
    for(const auto& tmp:max_tmp){
        outputfile << tmp << " ";
    }
    outputfile << std::endl << std::endl;
    // TODO: Find the minimum temperature for each day and output to output.txt
    auto min_tmp = get_forecast(readings,[](const std::vector<double>& wea) -> double{
        return *std::ranges::min_element(wea);
    });
    outputfile << "3.Min tempertaure of a day." << std::endl;
    for(const auto& tmp:min_tmp){
        outputfile << tmp << " ";
    }
    outputfile << std::endl << std::endl;
    // TODO: Find the average temperature for each day and output to output.txt
    auto avg_tmp = get_forecast(readings,[](const std::vector<double>& wea) -> double{
        return std::accumulate(wea.begin(),wea.end(),0) / wea.size();
    });
    outputfile << "4.Average tempertaure of a day." << std::endl;
    for(const auto& tmp:avg_tmp){
        outputfile << tmp << " ";
    }
    outputfile << std::endl << std::endl;
    return 0;
}