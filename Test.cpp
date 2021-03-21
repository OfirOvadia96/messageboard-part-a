#include "doctest.h"
#include "Board.hpp"
using ariel::Board;
using ariel::Direction;

//Unit tests for Board class:

 /*
 Auxiliary function:
 get int - ad length
 get int - ad length
 return - random string
 */
string random_string(unsigned int n){
    const int MAX_SIZE = 88;
    char letters[MAX_SIZE] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j'
    ,'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F'
    ,'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ',
    '!','?','.','#','$','%','^','&','*','(',')','-','+','=','/','*','\\','[',']','{','}',';','<','>',','};
    string ran = "";
    for (int i=0; i<n; i++){ 
        ran=ran + letters[rand() % MAX_SIZE];
    }
    return ran;
}
/*
 Auxiliary function:
 return - random Direction: Horizontal OR Vertical
 */
Direction random_type(){
    vector<Direction> type = {Direction::Horizontal,Direction::Vertical};
    return type.at(rand()%2);
}

//Tests:

TEST_CASE("empty board"){
    Board board;
    for(int i=0; i<50; i++){
        Direction ad_type = random_type();
        unsigned int column = rand()%1000;
        unsigned int row = rand()%1000;
        board.post(column ,row ,ad_type, "");
        CHECK(board.read(column ,row ,ad_type, 0) == "");
    }
}

TEST_CASE("worng_Direction - post/read"){
    Board board1;
    for(int i=0; i<10; i++){
        unsigned int column = rand()%1000;
        unsigned int row = rand()%1000;
         unsigned int ad_length = rand() %1000; 
         string ad1 = random_string(ad_length);
        board1.post(column , row ,Direction::Horizontal,ad1); //post Horizontal
        CHECK_THROWS(board1.read(column ,row ,Direction::Vertical, ad_length)); //try read Vertical
    }

    Board board2;
    for(int i=0; i<10; i++){
        unsigned int column = rand()%1000;
        unsigned int row = rand()%1000;
         unsigned int ad_length = rand() %1000; 
         string ad2 = random_string(ad_length);
        board2.post(column , row ,Direction::Vertical,ad2); //post Vertical
        CHECK_THROWS(board2.read(column ,row ,Direction::Horizontal, ad_length)); //try read Horizontal
    }
}

TEST_CASE("post_read - Good"){
    Board board;
    for(int i=0; i<500; i++){ //checks 500 times for random ad in random places
        unsigned int column = rand()%1000; //choose random column
        unsigned int row = rand()%1000; //choose random row
         unsigned int ad_length = rand() %1000; //choose random ad length
         string ad = random_string(ad_length); //choose random ad
         Direction ad_type = random_type(); //choose random Direction
        board.post(column , row ,ad_type,ad); // post the ad on board
        CHECK(board.read(column ,row ,ad_type, ad_length) == ad); //checks if post == what we read
    }
}