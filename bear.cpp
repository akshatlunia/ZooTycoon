/******************************************************
** Program: bear.cpp
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Contains functions for bear class
** Input: 
** Output: 
******************************************************/
#include "./bear.h"
/*
** Constructor for Bear with inheritance of Animal class traits
*/
Bear::Bear() : Animal(){
    animal = "Black Bear";
    age = 0;
    cost = 6000;
    n_babies = 2;
    revenue = 600;
    sick = false;
}
/*
** Function: Constructor for Bear with inheritence of Animal class traits
*/
Bear::Bear(int x) : Animal(){
    animal = "Black Bear";
    age = x;
    cost = 6000;
    n_babies = 2;
    revenue = 600;
    sick = false;
}