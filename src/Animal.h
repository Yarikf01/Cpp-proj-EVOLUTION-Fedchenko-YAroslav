//
// Created by yaros on 17.11.2019.
//

#ifndef EVOLUTION___ANIMAL_H
#define EVOLUTION___ANIMAL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <sstream>
#include "FitnessFunction.h"
class Animal {
    public:
        std::vector<int> genome;
        Animal(std::vector<int> _genome,int genome_size);

        void input_genome();

        void output_genome();

        void output_genome_to_file(std::string filename);

        void input_genome_from_file(std::string filename);

        void generate_genome(int genome_size);

        void mutate(int n);

        Animal breed(Animal x);

        double fitness(FitnessFunction f);
};


#endif //EVOLUTION___ANIMAL_H
