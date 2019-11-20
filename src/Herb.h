//
// Created by yaroslav fedchenko on 17.11.2019.
//

#ifndef EVOLUTION___HERB_H
#define EVOLUTION___HERB_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include "FitnessFunction.h"
#include "Animal.h"
class Herb{
    public:
        Herb(size_t _n);

        int add(Animal animal);

        int add(Animal animal, int count);

        int selection(size_t m);

        void crossover(size_t m);

        int select();

        void output_herb();

        void output_in_file(std::string filename);

    private:
        size_t n;
        std::vector<Animal> animals;
};


#endif //EVOLUTION___HERB_H
