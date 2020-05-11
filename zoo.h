/******************************************************
** Program: zoo.h
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Header file for zoo class
** Input: 
** Output: 
******************************************************/
#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <string>
#include "./bear.h"
#include "./sealion.h"
#include "./tiger.h"
#include "./animal.h"
#include "./enclosure.h"

using namespace std;

class Zoo{
    private:
/*         int num_bears;
        int num_sealions;
        int num_tigers; */
        float money;
        int attendance;
        int month;
        Enclosure bears;
        Enclosure sealions;
        Enclosure tigers;
        Enclosure choose_random_animal();
        void sick_animal();
        void birth_animal();
        void random_event();
        void attendance_boom();
    public:
        Zoo();
        float get_money();
        float get_num_bears();
        float get_num_sealions();
        float get_num_tigers();
        void Game();
        void buy_animal();
        bool buy_bear();
        bool buy_sealion();
        bool buy_tiger();
        void subtract_money(float);
        void add_money(float);
        bool check_payment_ability(float);
        bool feed_animals();
        void advance_time();
        int game_over();
        int end_game();
        //void add_animal(Animal*, int&, Animal);
        //void add_bear(Animal*);
};
#endif