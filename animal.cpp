/******************************************************
** Program: animal.cpp
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Contains functions for animal class
** Input: 
** Output: 
******************************************************/
#include "./animal.h"

Animal::Animal(){
    animal = "";
    age = 0;
    cost = 0;
    n_babies = 0;
    revenue = 0;
    food_cost = 80;
    sick = false;
    pregnant = false;
}

Animal::Animal(int x){
    age = x;
}

void Animal::advance_age(int months){
    age+=months;
}

void Animal::set_food_cost(float new_cost){
    //cout << "new cost is " << new_cost << endl;
    food_cost = new_cost;
}

string Animal::get_animal(){
    return animal;
}

int Animal::get_age(){
    return age;
}

float Animal::get_cost(){
    return cost;
}

float Animal::get_n_babies(){
    return n_babies;
}

float Animal::get_revenue(){
    return revenue;
}

float Animal::get_food_cost(){
    return food_cost;
}

bool Animal::get_sick(){
    return sick;
}

void Animal::set_sick(bool x){
    //cout << "Setting animal sick to: " << x << endl;
    sick = x;
}

bool Animal::get_pregnant(){
    return pregnant;
}

void Animal::set_pregnant(bool x){
    pregnant = x;
}

void Animal::age_animal(){
    age++;
}

float Animal::get_sickness_cost(){
    if (age < 6){
        cout << "Double charge for sick baby\n";
        return cost;
    }
    else {
        return cost/2;
    }
}