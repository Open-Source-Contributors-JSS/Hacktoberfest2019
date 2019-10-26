/*
  @author diogoneiss
  writes the hex number, from an inserted b10 one

*/


#include <iostream>

void Dec2Hex(int no){
    int hex=0;
    if(!no)
        //quit function when no number is provided
        return;
    else {
        hex = no%16;
        Dec2Hex (no/16) ;
    }
    if(hex>9)
        printf("%c",'A'+(hex-10));
    else
        printf("%d",hex);
    }

int main()
{
    int k=0;
    std::cout << "Enter number, in base 10, to be converted to hex: ";
    std::cin >> k;
    std::cout << "Number, in hex, is: ";
    Dec2Hex(k);
    std::cout << std::endl;

    return 0;
}
