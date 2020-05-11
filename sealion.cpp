/******************************************************
** Program: sealion.cpp
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Contains functions for sealion class
** Input: 
** Output: 
******************************************************/
#include "./sealion.h"
/*
** Function: Constructor for Sealion with inheritence of Animal class traits
*/
Sealion::Sealion() : Animal(){
    animal = "Sea Lion";
    age = 0;
    cost = 800;
    n_babies = 1;
    revenue = 160;
    sick = false;
}
/*
** Function: Constructor for Sealion with inheritence of Animal class traits
*/
Sealion::Sealion(int x) : Animal(){
    animal = "Sea Lion";
    age = x;
    cost = 800;
    n_babies = 1;
    revenue = 160;
    sick = false;
}