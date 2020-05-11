/******************************************************
** Program: tiger.cpp
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Contains functions for tiger class
** Input: 
** Output: 
******************************************************/
#include "./tiger.h"
/*
** Function: Constructor for Tiger with inheritence of Animal class traits
*/
Tiger::Tiger() : Animal(){
    animal = "Tiger";
    age = 0;
    cost = 15000;
    n_babies = 3;
    revenue = 1500;
    sick = false;
}
/*
** Function: Constructor for Tiger with inheritence of Animal class traits
*/
Tiger::Tiger(int x) : Animal(){
    animal = "Tiger";
    age = x;
    cost = 15000;
    n_babies = 3;
    revenue = 1500;
    sick = false;
}