//
// Created by yaroslav fedchenko on 17.11.2019.
//
#include "Herb.h"
int standard_genome_size = 5;
Herb::Herb(size_t _n){
        n = _n;
    }
int Herb::add(Animal animal){
        animals.push_back(animal);
        return 0;
    }
int Herb::add(Animal animal, int count) {
        for (int i = 0; i < count; i++) {
            animals.push_back(animal);
        }
        return 0;
    }
int Herb::selection(size_t m) {
    std::vector<Animal> new_herb;
    for (int i = 0; i < m; i++) {
        std::vector<int> v(animals[0].genome.size(), 1);
        FitnessFunction standard(v);
        Animal min = animals[0];
        double min_ftns = min.fitness(standard);
        int indx = 0;
        for (int j = 0; j < animals.size(); j++) {
            std::vector<int> v(animals[j].genome.size(), 1);
            FitnessFunction standard(v);
            if ((min_ftns) > animals[j].fitness(standard)) {
                min = animals[j];
                min_ftns = min.fitness(standard);
                indx = j;
            }
        }
        new_herb.push_back(min);
        animals.erase(animals.begin() + indx);
    }
    animals = new_herb;
    return 0;
}
 void Herb::crossover(size_t m) {
     std::vector<Animal> new_herb;
     Animal min = animals[0];
     int indx = 0;
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < animals.size(); j++) {
             std::vector<int> v(animals[j].genome.size(), 1);
             FitnessFunction standard(v);
             if (min.fitness(standard) > animals[j].fitness(standard)) {
                 min = animals[j];
                 indx = j;
             }
             new_herb.push_back(min);
         }
         for (int i = 0; i < new_herb.size(); i++) {
             int random_animal_indx = rand() % animals.size();
             Animal new_animal = new_herb[i].breed(animals[random_animal_indx]);
             animals.push_back(new_animal);
         }
     }
 }
int Herb::select() {
    std::vector<Animal> new_herb;
    for (int i = 0; i < n; i++) {
        std::vector<int> v(animals[0].genome.size(), 1);
        FitnessFunction standard(v);
        Animal min = animals[0];
        double min_ftns = min.fitness(standard);
        int indx = 0;
        for (int j = 0; j < animals.size(); j++) {
            std::vector<int> v(animals[j].genome.size(), 1);
            FitnessFunction standard(v);
            if ((min_ftns) > animals[j].fitness(standard)) {
                min = animals[j];
                min_ftns = min.fitness(standard);
                indx = j;
            }
        }
        new_herb.push_back(min);
        animals.erase(animals.begin() + indx);
    }
    animals = new_herb;
    return 0;

}
void Herb::output_herb(){
        for(int i = 0; i < animals.size(); i++){
            animals[i].output_genome();
        }
    }
void Herb::output_in_file(std::string filename){
        std::ofstream fout;
        fout.open(filename);
        for(int i = 0; i < animals.size(); i++) {
            std::string out = "";
            for (int j = 0; j < animals[i].genome.size(); j++) {
                out += std::to_string(animals[i].genome[j]) + " ";
            }
            fout << out << std::endl;
        }
        fout.close();
    }
