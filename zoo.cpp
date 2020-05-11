/******************************************************
** Program: zoo.cpp
** Author: Akshat Lunia
** Date: 5/10/2020
** Description: Contains functions for zoo class
** Input: 
** Output: 
******************************************************/
#include "./zoo.h"
#include "./animal.h"
/*
** Constructor for Zoo class
*/
Zoo::Zoo(){
    // num_bears = 0;
    // num_sealions = 0;
    // num_tigers = 0;
    //bears = new Animal[num_bears];
    // sealion = new Animal[num_sealions];
    // tiger = new Animal[num_tigers];
    money = 100000;
    month = 0;
    attendance = 0;
}
/*
** Function:add_money(float);
** Description:Adds money to account
*/
void Zoo::add_money(float x){
    money += x;
}
/*
** Function:subtract_money(float);
** Description:subtracts money from account
*/
void Zoo::subtract_money(float x){
    money -= x;
}
/*
** Function:get_money();
** Description:getter for amount of money
*/
float Zoo::get_money(){
    return money;
}
/*
** Function: get_num_bears();
** Description: getter for amount of animals in the bears enclosure
*/
float Zoo::get_num_bears(){
    return bears.get_num_animals();
}
/*
** Function: get_num_sealions();
** Description:  getter for number of animals in the sealions enclosure
*/
float Zoo::get_num_sealions(){
    return sealions.get_num_animals();
}
/*
** Function: get_num_tigers();
** Description: getter for number of animals in the tigers enclosure
*/
float Zoo::get_num_tigers(){
    return tigers.get_num_animals();
}
/*
** Function: check_payment_ability();
** Description: checker to see if user can pay for the desired object
*/
bool Zoo::check_payment_ability(float bill){
    if (bill > get_money()){
        cout << "You do not have enough money for this purchase. Exiting the transaction\n";
        return false;
    }
    else{return true;}
}
/*
** Function: buy_bear();
** Description: buys an adult bear by expanding the enclosure size and adding an animal in the enclosure
*/
bool Zoo::buy_bear(){
    cout << "How many Black Bears would you like to buy?\n1) 1\n2) 2\n";
    cout << "Please enter the corresponding number\n";
    cout << "You have " << get_money() << " dollars\n";
    int n_bears;
    cin >> n_bears;

    for(int i=0; i<n_bears; i++){
        Bear new_bear;
        new_bear = Bear(48);
        if(check_payment_ability(new_bear.get_cost()) == true){
            subtract_money(new_bear.get_cost());
            cout << "You now have " << get_money() << " dollars in your account\n";
            bears.add_animal(new_bear);
            // cout << "Exited function successfully\n";
        }
        else {return false;}
    }
    return true;
}
/*
** Function:buy_sealion();
** Description: buys an adult sea lion by the same way as bear
*/
bool Zoo::buy_sealion(){
    cout << "How many Sea Lions would you like to buy?\n1) 1\n2) 2\n";
    cout << "Please enter the corresponding number\n";
    cout << "You have " << get_money() << " dollars\n";
    int n_sealions;
    cin >> n_sealions;
    for(int i=0; i<n_sealions; i++){
        Sealion new_sealion;
        new_sealion = Sealion(48);
        if(check_payment_ability(new_sealion.get_cost()) == true){
            subtract_money(new_sealion.get_cost());
            cout << "You now have " << get_money() << " dollars in your account\n";
            sealions.add_animal(new_sealion);
            // cout << "Exited function successfully\n";
        }
        else {return false;}
    }
    return true;
}
/*
** Function:buy_tiger();
** Description: buys an adult tiger by the same way as bear
*/
bool Zoo::buy_tiger(){
    cout << "How many Tigers would you like to buy?\n1) 1\n2) 2\n";
    cout << "Please enter the corresponding number\n";
    cout << "You have " << get_money() << " dollars\n";
    int n_tigers;
    cin >> n_tigers;
    for(int i=0; i<n_tigers; i++){
        Tiger new_tiger;
        new_tiger = Tiger(48);
        if(check_payment_ability(new_tiger.get_cost()) == true){
            subtract_money(new_tiger.get_cost());
            cout << "You now have " << get_money() << " dollars in your account\n";
            tigers.add_animal(new_tiger);
            // cout << "Exited function successfully\n";
        }
        else{return false;}
    }
    return true;
}
/*
** Function: buy_animal()
** Description: Checks which animal is to be bought, then routes program to correct animal purchasing function
*/
void Zoo::buy_animal(){
    cout << "What animal would you like to buy?\n1)Black Bear\n2)Sea Lion\n3)Tiger\n";
    cout << "Black Bears cost $6,000" << endl;
    cout << "Sea Lions cost $800" << endl;
    cout << "Tigers cost $15000" << endl;
    cout << "Please enter the corresponding number\n";
    int choice;
    cin >> choice;
    if (choice == 1){
        buy_bear();
    }
    else if(choice == 2){
        buy_sealion();
    }
    else if(choice == 3){
        buy_tiger();
    }
}
/*
** Function: feed_animals();
** Description: checks if owner can pay for feeding animals, and then feeds them
*/
bool Zoo::feed_animals(){
    if(check_payment_ability(bears.get_total_food_cost()) == true){
        subtract_money(bears.get_total_food_cost());
    }
    else{return false;}
    if(check_payment_ability(sealions.get_total_food_cost()) == true){
        subtract_money(sealions.get_total_food_cost());
    }
    else{return false;}
    if(check_payment_ability(tigers.get_total_food_cost()) == true){
        subtract_money(tigers.get_total_food_cost());
    }
    else{return false;}
    return true;
}
/*
** Function: advance_time();
** Description: advances time by a month, age by a month, changes food costs for each animal, and calculates total revenue for the month
*/
void Zoo::advance_time(){
    bears.advance_age(1);
    sealions.advance_age(1);
    tigers.advance_age(1);
    month++;
    bears.change_base_food_cost();
    sealions.change_base_food_cost();
    tigers.change_base_food_cost();
    cout << "You now have " << get_money() << " dollars left\n";
    add_money(bears.calc_revenue());
    add_money(sealions.calc_revenue());
    add_money(tigers.calc_revenue());
}
/*
** Function:choose_random_animal()
** Description: selects a random animal to be used in special events. Checks if animals even exist in the
** zoo at all, and randomizes through animals that exist
*/
Enclosure Zoo::choose_random_animal(){
    srand(time(NULL));
    int random_animal;
    int num_valid_enclosures;
/*     cout << "Number of Bears: " << bears.get_num_animals() << endl;
    cout << "Number of Sealions: " << sealions.get_num_animals() << endl; 
    cout << "Number of Tigers: " << tigers.get_num_animals() << endl;
 */
    if (bears.get_num_animals() 
        + sealions.get_num_animals() 
        + tigers.get_num_animals() <= 0){
        cout << " There are no animals in the zoo: \n";
        Enclosure no_animals(-1);
        return no_animals;
    }
    do{
        random_animal = rand() % 3;
        //cout << " Random Animal Chosen is: " << random_animal << "\n";
        //random_animal = 1;
        if (random_animal == 0 && bears.get_num_animals()>0){
            return bears;
        }
        else if (random_animal == 1 && sealions.get_num_animals()>0){
            return sealions;
        }
        else if (random_animal == 2 && tigers.get_num_animals()>0){
            return tigers;
        }
    }while(true);
}
/*
** Function:sick_animal()
** Description:Makes an animal sick. Then it checks if the animal can be paid for and pays for it, otherwise it kills the animal
*/
void Zoo::sick_animal(){
    cout << "It seems that one of your animals has gotten sick\n";
    Enclosure sick_enclosure;
    int sick_animal;
    sick_enclosure = choose_random_animal();
    if(sick_enclosure.get_num_animals() < 0){
        cout << "There are no more animals in the zoo\n";
        return;
    }
    sick_animal = sick_enclosure.set_animal_sick();
    if(check_payment_ability((sick_enclosure.get_sickness_cost(sick_animal))/2) == true){
        cout << "You are able to pay for your sick animal\n";
        subtract_money((sick_enclosure.get_sickness_cost(sick_animal))/2);
        cout << "You now have " << get_money() << " dollars left\n";
        sick_enclosure.set_animal_healthy(sick_animal);
    }
    else{
        cout << "You don't have enough money to treat the " << sick_enclosure.get_animal_type(sick_animal) << "!\n";
        if (sick_enclosure.get_animal_type(sick_animal) == "Black Bear"){
                bears.kill_sick_animal();
            }
            else if (sick_enclosure.get_animal_type(sick_animal) == "Sea Lion"){
                sealions.kill_sick_animal();
            }
            else if (sick_enclosure.get_animal_type(sick_animal) == "Tiger"){
                cout << " Killing the sick tiger\n";
                tigers.kill_sick_animal();
            }        
        cout << "Your animal has died!\n";
    }
}
/*
** Function:birth_animal();
** Description:adds a baby animal to the correct enclosure
*/
void Zoo::birth_animal(){
    cout << "One of your animals is giving birth!\n";
    Enclosure birth_enclosure;
    int birth_animal;
    birth_enclosure = choose_random_animal();
    birth_animal = birth_enclosure.set_animal_pregnant();
    if (birth_enclosure.get_animal_type(birth_animal) == "Black Bear"){
        for(int i=0; i<2; i++){
            Bear baby_bear;
            baby_bear = Bear(0);
            bears.add_animal(baby_bear);
            cout << "Added baby bear\n";
        }
    }
    else if (birth_enclosure.get_animal_type(birth_animal) == "Sea Lion"){
        Sealion baby_sealion;
        baby_sealion = Sealion(0);
        sealions.add_animal(baby_sealion);
        cout << "Added baby sealion\n";
    }
    else if (birth_enclosure.get_animal_type(birth_animal) == "Tiger"){
        for(int i=0; i<3; i++){
            Tiger baby_tiger;
            baby_tiger = Tiger(0);
            tigers.add_animal(baby_tiger);
            cout << "Added baby tiger\n";
        }
    }
    birth_enclosure.set_animal_not_pregnant(birth_animal);
}
/*
** Function:attendance_boom()
** Description:creates a boom in attendance, and adds revenue for the correct number of sea lions
*/
void Zoo::attendance_boom(){
    srand(time(NULL));
    cout << "There's been an attendance boom! Your sea lions have generated an extra revenue!\n";
    float sealion_extra_revenue;
    sealion_extra_revenue = rand() % 251 + 150;
    sealion_extra_revenue = sealion_extra_revenue * sealions.get_num_animals();
    add_money(sealion_extra_revenue);
    cout << "An extra " << sealion_extra_revenue << " has been added to your account!\n";
}
/*
** Function: random_event()
** Description: picks a random "special" event to occur
*/
void Zoo::random_event(){
    srand(time(NULL));
    int random_number = rand() % 4;
    if(random_number == 0){
        sick_animal();
    }
    else if(random_number == 1){
        birth_animal();
    }
    else if(random_number == 2){
        attendance_boom();
    }
    else{
        return;
    }
}
/*
** Function: game_over()
** Description: If the player runs out of money, this will end the game
*/
int Zoo::game_over(){
    cout << "You ran out of money! Game over!\n";
    return 0;
}
/*
** Function:end_game()
** Description: Ends the game if the player wishes to do so
*/
int Zoo::end_game(){
    cout << "Thank you for playing Zoo Tycoon!\n";
    cout << "You had " << get_money() << " dollars\n";
    return 0;
}
/*
** Function: Game()
** Description: Plays the game Zoo Tycoon. It handles the direct input from the player and works accordingly
*/
void Zoo::Game(){
    cout << "Welcome to Zoo Tycoon! Let's start with purchasing your first animal\n";
    buy_animal();
    feed_animals();
    cout << "You now have " << get_money() << " dollars left\n";
    advance_time();
    cout << "You now have " << get_money() << " dollars left\n";
    int choice;
    do{
        cout << "Would you like to continue playing?\n1) Yes\n2) No\n";
        cin >> choice;
        if(choice == 1){
            random_event();
            cout << "Would you like to purchase another animal?\n1) Yes\n2) No\n";
            cout << "Please enter the corresponding number\n";
            int animal_choice;
            cin >> animal_choice;
            if (animal_choice ==1){
                cout << "Okay, you have " << get_money() << " dollars in your account\n";
                buy_animal();
            }
            cout << "Feeding your " << bears.get_num_animals() << " bears and your " << sealions.get_num_animals() <<
            " Sea Lions and your " << tigers.get_num_animals() << " tigers\n";
            feed_animals();
            cout << "You now have " << get_money() << " dollars left\n";
            advance_time();
            cout << "You now have " << get_money() << " dollars left\n";
            if(get_money()<0){
                cout << "You ran out of money!\n";
                game_over();
            }
        }
        else{
            end_game();
        }

    }while(choice == 1);
}