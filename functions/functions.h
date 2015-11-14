#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

    #include "../main.h"

    namespace cmd {
        bool getPos( int& x, int& y );
        void setPos(SHORT x, SHORT y);
    }
    char intToChar(char n);
    unsigned long long int pow10(int i);
    std::string intToString(signed long long int n);
#endif // FUNCTIONS_H_INCLUDED
