//
// Created by Aditya Jain on 3/13/17.
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
    bool again = true;
    
    while(again==true){

        ofstream myfile;
        int i; //holds the length of the string (always a multiple of 3)
        int b, count, j=0, a;
        string word; //holds the string that the user enters
        int matr[1000]; //letters converted to numbers
        string againResp;

        int key[3][3]; //key
        float inv[3][3] = {0}; //inverse of the key

        int ciph[1000] = {0};  //cipher text

        system("clear");
        cout << "\t\t-------------------------------------------------" << endl;
        cout << "\t\t               Welcome to CiphCrypt              " << endl;
        cout << "\t\t                  Version 1.0                    " << endl;
        cout << "\t\t-------------------------------------------------" << endl;

        string resp;
        bool tryAgain = true;
        while(tryAgain){
            cout << "\n\nEncryption(1) or Decryption(2): ";
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

            whole(key, inv);

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

            myfile.open(filename);

            for (int y = 0; y < 3; ++y)
                for (int z = 0; z < 3; ++z)
                    myfile << inv[y][z] << endl;

            myfile << i << endl;
            matrixmult(key, i, matr, ciph);

            for (int d = 0; d < i; ++d) { //inserts the cipher text into encrypt.txt
                myfile << ciph[d] << endl;
            }
            myfile.close();

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


            //decryption:
        else if (resp == "2") {
            ifstream myfile2;
            myfile2.open(filename);
            j = 0;

            int ciph2[1000] = {0};
            int matr2[1000];
            int ikey[3][3];
            int y, z;
            for (y = 0; y < 3; ++y)
                for (z = 0; z < 3; ++z)
                    myfile2 >> ikey[y][z];

                
            char ans[1000];

            myfile2 >> i;
            for (int b = 0; b < i; ++b)
                myfile2 >> matr2[b];

            myfile2.close();

            matrixmult(ikey, i, matr2, ciph2);

            numtoletter(ciph2, ans, i);

            cout << "\n";
            
            for(int g = 0; g < i; ++g) 
                cout << ans[g];
        
            cout << "\n\t" << endl;
            tryAgain = true;
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
















