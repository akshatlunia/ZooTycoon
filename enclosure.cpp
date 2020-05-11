/******************************************************
** Program: enclosure.cpp
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Contains functions for enclosure class
** Input: 
** Output: 
******************************************************/
#include "./enclosure.h"
#include <cstdlib>
/*
** Constructor for enclosure class
*/
Enclosure::Enclosure(){
    num_animals = 0;
    animals = new Animal[num_animals];
}
/*
** Constructor for enclosure class with num_animals as a parameter
*/
Enclosure::Enclosure(int x){
    num_animals = x;
}
/*
** Destructor for Enclosure class
*/
Enclosure::~Enclosure(){
    delete [] animals;
    animals = NULL;
}
/*
** Function: get_num_animals()
** Description: getter for the number of animals num_animals
*/
int Enclosure::get_num_animals(){
    return num_animals;
}
/*
** Function: set_num_animals()
** Description: setter for the number of animals num_animals
*/
void Enclosure::set_num_animals(int x){
    num_animals = x;
}
/*
** Function: get_total_food_cost()
** Description: function to calculate the food cost per each enclosure of animal type
*/
float Enclosure::get_total_food_cost(){
    float food_cost;
    for(int i=0;i<num_animals;i++){
        food_cost+=animals[i].get_food_cost();
    }
    return food_cost;
}
/*
** Function: calc_revenue()
** Description: calculates the revenue each animal makes, taking into account the age of the animal as this
** effects revenue
*/
float Enclosure::calc_revenue(){
    float revenue;
    for(int i=0;i<num_animals;i++){
        if(animals[i].get_age() < 6){
            revenue+=(animals[i].get_revenue()*2);
        }
        else{
            revenue+=animals[i].get_revenue();
        }
    }
    return revenue;
}
/*
** Function: set_animal_sick()
** Description: sets a random animal with the "sick" flag
*/
int Enclosure::set_animal_sick(){
    srand(time(NULL));
    int random_animal = rand() % get_num_animals();
    // cout << "Animal that has been chosen sick number is: " << random_animal << " Out of " << get_num_animals() << " animals " << endl;
    animals[random_animal].set_sick(true);
    //cout << "Animal that has been chosen sick is " << animals[random_animal].get_animal() << endl;

/*     for(int i=0;i<num_animals;i++){
        cout << "Animal status sick is: " << animals[i].get_sick() << endl;
    } */

    return random_animal;
}
/*
** Function: set_animal_healthy
** Description: sets a "sick" animal from sick=true to sick=false
*/
void Enclosure::set_animal_healthy(int i_animal){
    animals[i_animal].set_sick(false);
}
/*
** Function: get_animal_type
** Description: gets one specific animal from an enclosure's type
*/
string Enclosure::get_animal_type(int i_animal){
    return animals[i_animal].get_animal();
}
/*
** Function: get_animal_cost()
** Description: gets specific animal's cost to purchase
*/
float Enclosure::get_animal_cost(int i_animal){
    return animals[i_animal].get_cost();
}
/*
** Function: get_sickness_cost()
** Description: gets the cost of sickness for an animal
*/
float Enclosure::get_sickness_cost(int i_animal){
    return animals[i_animal].get_sickness_cost();
}
/*
** Function:set_animal_pregnant
** Description: gives random animal in enclosure the "pregnant" flag pregnant = true
*/
int Enclosure::set_animal_pregnant(){
    srand(time(NULL));
    int random_animal = rand() % get_num_animals();
    animals[random_animal].set_pregnant(true);
    //cout << "Animal that has been chosen pregnant is " << animals[random_animal].get_animal() << endl;
    return random_animal;
}
/*
** Function: set_animal_not_pregnant
** Description: changes "pregnant" flag from pregnant = true to pregnant = false
*/
void Enclosure::set_animal_not_pregnant(int x){
    animals[x].set_pregnant(false);
}
/*
** Function: kill_sick_animal
** Description: resizes array to one less, then fills smaller array with unsick animals
** "killing" the sick animal
*/
void Enclosure::kill_sick_animal(){
    Animal *temp;
    //cout << "Number of Animals is : " << num_animals << endl;
    temp = new Animal[num_animals];
    for (int i=0; i<num_animals; i++){
        //cout << " Inside Enclosure:Kill Sick_animal: 1st For Loop as it is: " << animals[i].get_sick() << endl;
        temp[i] = animals[i];
    }
    delete [] animals;
    animals = new Animal[num_animals-1];
    int j=0;
    for (int i=0;i<num_animals;i++){
        //cout << " Inside Enclosure:Kill Sick_animal:2nd For Loop as it is: " << temp[i].get_sick() << endl;
        if(temp[i].get_sick() == false){
            animals[j] = temp[i];
            j++;
            //cout << " Inside Enclosure:Kill Sick_animal:2nd For Loop: If Statement\n";
        }
    }
    num_animals --;
/*     cout << "Number of Animals is : " << num_animals << endl;
    cout << "First Animals is : " << animals[0].get_animal() << endl;
    cout << "First Animals is : " << temp[0].get_animal() << endl; */
    delete [] temp;
    temp = NULL;
}
/*
** Function: change_base_food_cost()
** Description: changes the cost of food for each animal in a given enclosure to a random amount
*/
void Enclosure::change_base_food_cost(){
    srand(time(NULL));
    for(int i=0;i<num_animals;i++){
        int random_int = (rand() % 41 + 80);
        float rand_number = (float)random_int/100;
        //cout << "The random number is " << rand_number << " and rand int is " << random_int << endl;
        animals[i].set_food_cost(animals[i].get_food_cost()*rand_number);
    }
}
/*
** Function: advance_age()
** Description: advances the age of every animal in a given enclosure
*/
void Enclosure::advance_age(int months){
    for(int i=0;i<num_animals;i++){
        animals[i].advance_age(months);
    }
}
/*
** Function: add_animal()
** Description: makes a larger array, then adds the new_animal of a given type to the larger array
*/
void Enclosure::add_animal(Animal new_animal){
    //cout << "increasing array size to " << &animals  << endl;
    Animal *tempAnimals;
    tempAnimals = new Animal[num_animals];
    for (int i=0; i<num_animals; i++){
        //cout << "temp created, instantiating larger array" << animals[i].get_animal() << endl;
        tempAnimals[i] = animals[i];
    }
    //cout << "outside temp created, instantiating larger array\n";
    //delete [] animals;
    animals = new Animal[num_animals+1];
    //cout << "instantiated larger array, filling larger array\n";
    for(int i=0;i<num_animals;i++){
        animals[i] = tempAnimals[i];
        //cout << "filled larger array" << animals[i].get_animal() << endl;
    }
    num_animals++;
    //cout << "the number of animals is " << num_animals << endl;
    animals[num_animals-1] = new_animal;
/*     for(int i=0; i<num_animals; i++){
        cout << "newest added animal is " << animals[i].get_animal() << endl;
    } */
    delete [] tempAnimals;
    tempAnimals = NULL;
}