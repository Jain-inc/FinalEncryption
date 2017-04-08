//
// Created by Aditya Jain, Danielle Cui, and Avinash Kumar
//
// letter = (ascii + 16)^2-10000
// filler = 1

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>
#include "myheader.h"

using namespace std;


int main()
{
    srand(time(0));
    bool again = true;
    
    while(again==true){

        int i; //holds the length of the string (always a multiple of 3)
        int b, count, j=0, a;
        string word; //holds the string that the user enters
        int matr[1000]; //letters converted to numbers
        string againResp;

        int key[3][3]; //key
        float inv[3][3] = {0}; //inverse of the key

        int ciph[1000] = {0};  //cipher text

        system("clear");
        cout << "\t\t----------------------------------------------------" << endl;
        cout << "\t\t                Welcome to CiphCrypt                " << endl;
        cout << "\t\t                   Version 1.0                      " << endl;
        cout << "\t\t----------------------------------------------------\n" << endl;

        string resp;
        bool tryAgain = true;
        while(tryAgain){
            cout << "\nEncryption(1) or Decryption(2): ";
            cin >> resp;
            if(resp == "1" || resp == "2")
                tryAgain = false;
        }

        

        string filename;
        cout << "\nEnter filename: ";
        cin >> filename;

   
        //encryption:
        if(resp == "1") {
            cin.ignore();
            int determ;
            while(determ!=1) //makes the determinant a 1 so that the inverse is an integer
            {
                for (int y = 0; y < 3; ++y)
                    for (int z = 0; z < 3; ++z)
                        key[y][z] = rand()%100;

                determ = determinant(key);
            } //key

            invert(key, inv);

            cout << "\nEnter the string:" << endl;
            getline(cin, word);
            i = word.length();

            lettertonum(word, matr, i);


            if (i % 3 == 2) //add 1 0 to the end of the string to make it divisible by 3
            {
                matr[i] = 1;
                ++i; //increase length by 1
            } else if (i % 3 == 1) //add 2 zeroes to the end of the string to make it divisible by 3;
            {
                matr[i] = 1;
                matr[i + 1] = 1;
                i = i + 2; //increase the length by 2
            }

            ofstream outFile;
            outFile.open(filename);

            for (int y = 0; y < 3; ++y)
                for (int z = 0; z < 3; ++z)
                    outFile << inv[y][z] << endl; //inserts the inverse of the key into the file

            outFile << i << endl;
            matrixmult(key, i, matr, ciph);

            for (int d = 0; d < i; ++d) { //inserts the cipher text into the file
                outFile << ciph[d] << endl;
            }
            outFile.close();

            tryAgain = true;
            while(tryAgain){  //asks if the user wants to run the program again
                cout << "\nDo you wish to continue (Y/N)? ";
                cin >> againResp;

                if(againResp == "y" || againResp == "Y")
                {
                    again = true;
                    tryAgain = false;
                }
                else if (againResp == "N" || againResp == "n")
                {
                    again = false;
                    tryAgain = false;
                }
                else
                    tryAgain = true;
            }



        }


            //decryption:
        else if (resp == "2") {

            ifstream inFile;
            inFile.open(filename);

            // if the file cannot be found
            if(inFile.fail()){
                cout << "Error! File not found!" << endl;
            }

            int ciph2[1000] = {0};
            int matr2[1000]; 
            int ikey[3][3]; //inverse of the key
            int y, z;
            for (y = 0; y < 3; ++y)
                for (z = 0; z < 3; ++z)
                    inFile >> ikey[y][z];

                
            char ans[1000]; // holds the letters for the decrypted message

            inFile >> i;
            for (int b = 0; b < i; ++b)
                inFile >> matr2[b];

            inFile.close();

            matrixmult(ikey, i, matr2, ciph2);

            numtoletter(ciph2, ans, i); //converts the numbers back into letters

            cout << "\n";
            
            for(int g = 0; g < i; ++g) 
                cout << ans[g];
        
            cout << "\n\t" << endl;
            tryAgain = true;

            // allows the user to run the program again
            while(tryAgain){
                cout << "Do you wish to continue (Y/N)? ";
                cin >> againResp;

                if(againResp == "y" || againResp == "Y")
                {
                    again = true;
                    tryAgain = false;
                }
                else if (againResp == "N" || againResp == "n")
                {
                    again = false;
                    tryAgain = false;
                }
                else
                    tryAgain = true;
            }

        }
    }
}














