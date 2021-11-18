#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
}


int Player::draw(int n) { //push hand to the list at n place
count = n + count; //renew count
    return count; //return count
}

void Player::return_zero(){
    count = 0; //set count to be 0
}

void Player::set_Coins(int n) {
    m_Coins = n; //set m_Coins to be 0
}

int Player::return_coins(){
 return m_Coins; //return m_coins
}

int Player::return_count(){
    return count; //return count
}

void Player::coin_Change(int n){
    m_Coins = m_Coins + n; //rew m_Coins to be m_Coins + n
}