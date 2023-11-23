#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <regex>
#include <map>

int tests(){
    std::cout<<ULLONG_MAX<<'\n';
    std::string binary = std::bitset<64>(ULLONG_MAX).to_string();
    unsigned long long coutlong = std::bitset<64>(binary).to_ullong();
    std::cout<<"Binary is: "<<binary<<'\n'<<"Unsigned Long Long is: "<<coutlong<<"\n\n";
    return 0;
}

//The Godly Movereader
std::regex chessmove("([A-Z])*([a-h][1-8]|[a-h]|[1-8])*(x)*([a-h][1-8]|O-O-O|O-O)+(=[A-Z])*(#)*(\\+)*");

//

void printboard(std::string board){
    std::string retstr = "";
    for (unsigned long long i = 0; i < board.length();i++){
        retstr += board[i];
        if ((i != 0) && (i+1)%8==0) retstr += '\n';
    }
    retstr += "\n\n";
    std::cout<< retstr;
}

std::string STARTING_WHITE_PAWNS =    "0000000000000000000000000000000000000000000000001111111100000000";
std::string STARTING_WHITE_ROOKS =    "0000000000000000000000000000000000000000000000000000000010000001";
std::string STARTING_WHITE_KNIGHTS =  "0000000000000000000000000000000000000000000000000000000001000010";
std::string STARTING_WHITE_BISHOPS =  "0000000000000000000000000000000000000000000000000000000000100100";
std::string STARTING_WHITE_QUEEN =    "0000000000000000000000000000000000000000000000000000000000010000";
std::string STARTING_WHITE_KING =     "0000000000000000000000000000000000000000000000000000000000001000";

std::string STARTING_BLACK_PAWNS =    "0000000011111111000000000000000000000000000000000000000000000000";
std::string STARTING_BLACK_ROOKS =    "1000000100000000000000000000000000000000000000000000000000000000";
std::string STARTING_BLACK_KNIGHTS =  "0100001000000000000000000000000000000000000000000000000000000000";
std::string STARTING_BLACK_BISHOPS =  "0010010000000000000000000000000000000000000000000000000000000000";
std::string STARTING_BLACK_QUEEN =    "0001000000000000000000000000000000000000000000000000000000000000";
std::string STARTING_BLACK_KING =     "0000100000000000000000000000000000000000000000000000000000000000";

std::vector<std::string> ALL_BOARDS = {STARTING_WHITE_PAWNS, STARTING_WHITE_ROOKS, STARTING_WHITE_KNIGHTS, STARTING_WHITE_BISHOPS, STARTING_WHITE_QUEEN, STARTING_WHITE_KING, 
                                       STARTING_BLACK_PAWNS, STARTING_BLACK_ROOKS, STARTING_BLACK_KNIGHTS, STARTING_BLACK_BISHOPS ,STARTING_BLACK_QUEEN, STARTING_BLACK_KING};

void printallboards(){
    for (size_t i = 0; i < ALL_BOARDS.size();i++) printboard(ALL_BOARDS[i]);
}

std::string addallboards(){
    unsigned long long intretboard=0; 
    for (size_t i = 0; i< ALL_BOARDS.size();i++) intretboard |= std::bitset<64>(ALL_BOARDS[i]).to_ullong();
    std::string retboard = std::bitset<64>(intretboard).to_string();
    printboard(retboard);
    return retboard;
}

void removeallboards(std::string board){
    unsigned long long tempboard = std::bitset<64>(board).to_ullong();
    for (size_t i = 0;i<ALL_BOARDS.size();i++) tempboard &= ~std::bitset<64>(ALL_BOARDS[i]).to_ullong();
    printboard(std::bitset<64>(tempboard).to_string());
}

std::string announcemove(std::string move){
    //Some changing strings for return value.
    std::string piece = "Pawn"
    //Set default to pawn

    //setting up regex
    std::smatch matches;
    std::string::const_iterator searchStart(move.cbegin());
    std::regex_search(move, matches, chessmove);
        //0 is full move
        //1 is piece moving, if not pawn
        //2 is potential starting square
        //3 is potential captures
        //4 is ending square, or castle
        //5 is potential promotion
        //6 is potential mate
        //7 is potential check


    if (matches[4]=="O-O-O") return "Long Castle.";
    else if (matches[4]=="O-O") return "Castle.";
        //Basically skip all the hullabaloo if it's a castle.
    return "WIP";
}

int main(){
    std::cout<<announcemove("O-O-O");
    return 0;
};