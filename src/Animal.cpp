//
// Created by yaroslav fedchenko on 17.11.2019.
//
#include "Animal.h"
Animal::Animal(std::vector<int> _genome,int genome_size)
    {
        if (_genome.empty() == false){
            genome = _genome;
        }
        else {
            generate_genome(genome_size);
        }
    }
void Animal::input_genome() {
        int n;
        std::cout<<"\nInput n=";
        std::cin>>n;
        std::vector<int> new_genome(n);
        std::string buffer = "";
        for(int i = 0; i < n; i++){
            std::cout<<"\ngenome["<<i<<"]";
            std::cin>>buffer;
            new_genome[i]=atoi(buffer.c_str());

        }
        genome = new_genome;
    }

void Animal::output_genome()
    {
        std::cout << "Genome:" << std::endl;
        for (int i = 0; i < genome.size(); i++) {
            std::cout << genome[i] << " ";
        }
        std::cout << std::endl;
    }

void Animal::output_genome_to_file(std::string filename){
        std::ofstream fout;
        fout.open(filename);
        std::string out = "";
        for (int i = 0; i < genome.size(); i++) {
            out += std::to_string(genome[i]) + " ";
        }
        fout << out ;
        fout.close();
    }
void Animal::input_genome_from_file(std::string filename){
        genome.clear();
        std::ifstream fin(filename);
        std::string str;
        std::getline(fin,str);
        std::stringstream s(str);
        std::string el;
        while (s >> el)
            genome.push_back(stoi(el));
    }

void Animal::mutate(int n){
    for(int i = 0; i < n; i++){
        int randindx = rand()%genome.size();
        genome[randindx] = rand()%100;
    }

}

void Animal::generate_genome(int genome_size){
        genome.clear();
        for(int i = 0; i < genome_size; i++){
            int el = rand()%100;
            genome.push_back(el);
        }
    }
Animal Animal::breed(Animal x){
        std::vector<int> empty_vector;
        int new_genome_size = std::min(genome.size(), x.genome.size());
        Animal new_an(empty_vector, new_genome_size);
        for(int i = 0; i < new_genome_size; i++){
            new_an.genome[i] = (genome[i] + x.genome[i]) / 2;
        }
        return new_an;
    }

double Animal::fitness(FitnessFunction f) {
    double res = f.fitFun(genome);
    return res;
}