/******************************************************
** Program: enclosure.h
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Header file for enclosure class
** Input: 
** Output: 
******************************************************/
#ifndef ENCLOSURE_H
#define ENCLOSURE_H
#include "./animal.h"

class Enclosure{
    private:
        Animal *animals;
        int num_animals;
    public:
        Enclosure();
        Enclosure(int);
        ~Enclosure();
        void add_animal(Animal);
        int get_num_animals();
        void set_num_animals(int);
        float get_total_food_cost();
        void advance_age(int);
        void change_base_food_cost();
        float calc_revenue();
        int set_animal_sick();
        void set_animal_healthy(int);
        string get_animal_type(int);
        float get_animal_cost(int);
        int set_animal_pregnant();
        void set_animal_not_pregnant(int);
        void kill_sick_animal();
        float get_sickness_cost(int);
};
#endif