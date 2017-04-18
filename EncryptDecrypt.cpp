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

    while(again){
        int length; //holds the length of the string (always a multiple of 3)
        int b, count, j=0, a;
        string word; //holds the string that the user enters
        int matr[1000]; //letters converted to numbers
        string againResp;

        int key[3][3];// = {7, 5, 7, 8, 6, 8, 6, 8, 4}; //key
        int inv[3][3] = {0}; //inverse of the key

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
            int determ = 0;
            while(determ != 1) //Ensures that the determinant is not a 0 so that the key is invertible
            {
                for (int y = 0; y < 3; ++y)
                    for (int z = 0; z < 3; ++z)
                        key[y][z] = ((rand())%100)+1;

                determ = determinant(key);
            } //key

            invert(key, inv); //puts the inverse of the key inside inv[][]

            cout << "\nEnter the message to be encrypted:" << endl;
            getline(cin, word);
            length = word.length();

            lettertonum(word, matr, length);

            addFiller(matr, length);

            ofstream outFile;
            outFile.open(filename);

            for (int y = 0; y < 3; ++y)
                for (int z = 0; z < 3; ++z)
                    outFile << inv[y][z] << endl; //inserts the inverse of the key into the file
                
            outFile << length << endl;
            matrixmult(key, length, matr, ciph);

            for (int d = 0; d < length; ++d) //inserts the cipher text into the file
                outFile << ciph[d] << endl;
            
            outFile.close();
        }


            //decryption:
        else if (resp == "2") {
            bool fileError = false;
            ifstream inFile;
            inFile.open(filename);

            // if the file cannot be found
            if(inFile.fail()){
                cout << "\nError! File not found!" << endl;
                fileError = true;
            }
            if(!fileError){   //if there isn't a file error
                int ciph2[1000] = {0};
                int matr2[1000];
                int ikey[3][3]; //inverse of the key
                int y, z;
                for (y = 0; y < 3; ++y)     //gets the inverse of the key from the text file
                    for (z = 0; z < 3; ++z)
                        inFile >> ikey[y][z];

                char ans[1000]; // holds the letters for the decrypted message

                inFile >> length;
                for (int b = 0; b < length; ++b)    //gets the cipher text from the file
                    inFile >> matr2[b];

                inFile.close();

                matrixmult(ikey, length, matr2, ciph2); 

                numtoletter(ciph2, ans, length); //converts the numbers back into letters

                cout << "\nDecrypted Message:\n\n";
                for(int g = 0; g < length; ++g)
                    cout << ans[g];
                
                cout << "\n";
            }
        }
        // allows the user to run the program again
        tryAgain = true;
        while(tryAgain){
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
}





    








