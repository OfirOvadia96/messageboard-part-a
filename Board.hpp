#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Board{
        private:
        vector<vector<string>> board;
        public:
            Board(){ //constructor

         }
            void post(unsigned int column , unsigned int row, Direction Direct , const string & ad);

            string read(unsigned int column, unsigned int row , Direction Direct, unsigned int num_char);

            void show();
    };
}