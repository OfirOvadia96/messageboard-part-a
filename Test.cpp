#include "doctest.h"
#include "Board.hpp"
using ariel::Board;
using ariel::Direction;

 /*
 Auxiliary function:
 get int -ad length
 get int -ad length
 return - random string
 */
const int MAX_SIZE = 88;

string random_string(unsigned int n){
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

Direction random_type(){
    vector<Direction> type = {Direction::Horizontal,Direction::Vertical};
    return type.at(rand()%2);
}
//Tests:

TEST_CASE("post >>Horizontal"){
    Board board1;
    for(int i=0; i<500; i++){
        unsigned int column = rand()%1000;
        unsigned int row = rand()%1000;
         unsigned int ad_length = rand() %1000;
         string ad = random_string(ad_length);
         Direction ad_type = random_type();
        board1.post(column , row ,ad_type,ad);
        CHECK(board1.read(column ,row ,ad_type, ad_length) == ad);
    }
}

// TEST_CASE("post >>Vertical"){
//     Board board2;
//     for(int i=0; i<500; i++){
//         unsigned int column1 = rand()%1000;
//         unsigned int row1 = rand()%1000;
//          unsigned int ad_length1 = rand() %1000;
//          string ad1 = random_string(ad_length1);
//         board2.post(column1 , row1 ,Direction::Vertical,ad1);
//         CHECK(board2.read(column1 ,row1 ,Direction::Vertical, ad_length1) == ad1);
//     }
// }