//
// Created by yaros on 17.11.2019.
//
#ifndef EVOLUTION___FITNESSFUNCTION_H
#define EVOLUTION___FITNESSFUNCTION_H
#include <iostream>
#include <vector>
class FitnessFunction{
    public:
        FitnessFunction(std::vector<int> v);
        double fitFun(std::vector<int> v);
    private:
        unsigned n;
        std::vector<int>f;
};
#endif //EVOLUTION___FITNESSFUNCTION_H
