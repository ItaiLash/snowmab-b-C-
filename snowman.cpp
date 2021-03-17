#include "snowman.hpp"
using namespace std;

const int validInputLen = 8;

enum body 
{ 
    HEAD, NOSE, LEFT_EYE, RIGHT_EYE, LEFT_ARM, RIGHT_ARM, TORSO, BASE 
};

const vector<string> H = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> N = {",", ".", "_", " "};
const vector<string> L = {".", "o", "O", "-"};
const vector<string> R = {".", "o", "O", "-"};
const vector<string> X1 = {" ", "\\", " ", " "};
const vector<string> Y1 = {" ", "/", " ", " "};
const vector<string> X2 = {"<", " ", "/", " "};
const vector<string> Y2 = {">", " ", "\\", " "};
const vector<string> T = {" : ", "] [", "> <", "   "};
const vector<string> B = {" : ", "\" \"", "___", "   "};

/*
* @brief The metod converts a character ('1' - '4') to an integer representation (1 - 4)
*        and reduces 1 to match the integer to his index representation on the range of the array (0 - 3).
* @param Single char
* @return Numerical representation of the character minus 1
*/
int chatToInt(char c){
    return (c-'0')-1; 
}

/*
* @brief A method that checks the validity of the input
* @param a string representation of the correspond snowman
* @return 0 In case the input length is different from 8, 
*         a negative number in case the input does not consist of the numbers in rande 1-4, 
*         otherwise the method return a positive number
*/
int checkInput (std::string input ) {
    if (input.length() != validInputLen) {
    	return 0;
    }
    for (int i=0; i < validInputLen; i++) {
        if (input[i] < '1' || input[i] > '4') {
        	return -1;
        }
    }
    return 1;
}

namespace ariel{
    /*
    * @brief The method receives a number describing the snowman,
    *        if the input is correct, it will return a string corresponding 
    *        to the input received that represents the snowman.
    * @param A number consisting of 8 digits in the range 1-4.
    * @return String representing the appropriate snowman, 
    *         if the input is incorrect the method will throw an error.
    */
	string snowman(int number){
        string s = to_string(number);
        if(checkInput(s) == 0 ){
            throw invalid_argument{"ERROR: Invalid input, the input number must have exactly 8 digits\n"};
        }
        if(checkInput(s) < 0 ){
            throw invalid_argument{"ERROR: Invalid input, the digits must be in range 1-4\n"};
        }
        return H.at(chatToInt(s[HEAD])) + "\n"
            + X1.at(chatToInt(s[LEFT_ARM]))
            + "(" + L.at(chatToInt(s[LEFT_EYE]))
            + N.at(chatToInt(s[NOSE]))
            + R.at(chatToInt(s[RIGHT_EYE])) 
            + ")" + Y1.at(chatToInt(s[RIGHT_ARM])) + "\n"
            + X2.at(chatToInt(s[LEFT_ARM])) 
            + "(" + T.at(chatToInt(s[TORSO])) + ")" 
            + Y2.at(chatToInt(s[RIGHT_ARM])) + "\n"
            + " (" + B.at(chatToInt(s[BASE])) + ") ";  
    }
};