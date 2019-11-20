//
// Created by yaroslav fedchecko on 17.11.2019.
//
#include "../src/Animal.h"
#include "../src/Herb.h"
#include "../src/FitnessFunction.h"
std::vector<int> empty_vector;
void input_animal(){
    Animal animal(empty_vector, 5);
    animal.input_genome();
    animal.output_genome();
}

void input_file_animal(){
    Animal animal(empty_vector, 5);
    animal.input_genome_from_file("test_genome");
    animal.output_genome_to_file("genome");
}

void generate_genome(){
    Animal animal(empty_vector, 5);
    animal.generate_genome(10);
    animal.output_genome();
}

void breed(){
    Animal animal1(empty_vector, 5);
    Animal animal2(empty_vector, 5);
    Animal animal3 = animal1.breed(animal2);
    animal1.output_genome();
    animal2.output_genome();
    animal3.output_genome();
}

void mutate(){
    Animal animal(empty_vector, 5);
    animal.output_genome();
    animal.mutate(2);
    animal.output_genome();
}

/* Animal test */
void test_Animal(){
    std::cout<<"\nChoices:\n11-input from console\n12-input from file";
    std::cout<<"\n13-generate genome\n14-mutate";
    std::cout<<"\n15-breed\n10-exit";
    int k;
    while(k!=10){
        std::cout<<"\nChoice:";
        std::cin>>k;
        if(k==11) input_animal();
        if(k==12) input_file_animal();
        if(k==13) generate_genome();
        if(k==15) breed();
        if(k==14) mutate();
    }
}

Herb herb(2);
void input_herb(){
    int n;
    std::cout << "Enter number of animals:";
    std::cin>>n;
    for(int i = 0;i < n;i++){
        Animal animal(empty_vector, 5);
        animal.input_genome();
        herb.add(animal);
    }
}

void output_herb(){
    std::cout<<"Your Herb:"<<std::endl;
    herb.output_herb();
}

void add_one_animal(){
    Animal animal(empty_vector, 5);
    animal.input_genome();
    herb.add(animal);
}

void selection(){
    int n;
    std::cout<<"Enter n for selection:";
    std::cin>>n;
    std::cout<<"Before selection"<<std::endl;
    herb.output_herb();
    herb.selection(n);
    std::cout<<"After selection"<<std::endl;
    herb.output_herb();
}

void crossover(){
    int n;
    std::cout<<"Enter n for crossover";
    std::cin>>n;
    std::cout<<"Before crossover"<<std::endl;
    herb.output_herb();
    herb.crossover(n);
    std::cout<<"After crossover"<<std::endl;
    herb.output_herb();
}

void select(){
    std::cout<<"Before select"<<std::endl;
    herb.output_herb();
    herb.select();
    std::cout<<"After select"<<std::endl;
    herb.output_herb();
}

void output_herb_in_file(){
    herb.output_in_file("herb");
}

int test_Herb(){
    std::cout<<"\nChoices:\n21-input herb\n22-add one animal";
    std::cout<<"\n23-output herb\n24-selection";
    std::cout<<"\n25-crossover\n26-select";
    std::cout<<"\n27-output herb in file\n20-exit";
    int k;
    while(k!=20){
        std::cout<<"\nChoice:";
        std::cin>>k;
        if(k==21) input_herb();
        if(k==22) add_one_animal();
        if(k==23) output_herb();
        if(k==24) selection();
        if(k==25) crossover();
        if(k==26) select();
        if(k==27) output_herb_in_file();
    }
};
