/******************************************************
** Program: animal.h
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Header file for animal class
** Input: 
** Output: 
******************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Animal {
    protected:
        string animal;
        int age;
        float cost;
        int n_babies;
        float revenue;
        float food_cost;
        bool sick;
        bool pregnant;
    public:
        Animal();
        Animal(int);
        string get_animal();
        int get_age();
        float get_cost();
        float get_n_babies();
        float get_revenue();
        float get_food_cost();
        bool get_sick();
        bool get_pregnant();
        void set_food_cost(float);
        void set_sick(bool);
        void set_pregnant(bool);
        void age_animal();
        void advance_age(int);
        float get_sickness_cost();
        //Animal add_animal(Animal*, int, Animal);
};
#endif