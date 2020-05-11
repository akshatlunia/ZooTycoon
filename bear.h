/******************************************************
** Program: bear.h
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: header file for bear class
** Input: 
** Output: 
******************************************************/
#ifndef BEAR_H
#define BEAR_H
#include "./animal.h"

class Bear : public Animal{
    public:
        Bear();
        Bear(int);
};
#endif