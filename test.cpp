// Name: Daniel Calderon
// Date: October 22,2015
// Takes text file and take average and declase who has the highest grade

#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include<string>
#include <iomanip>

using namespace std;

int main()
{
    char userFile[12];
    string firstName,lastName,name1;
    double s1,s2,s3,s4,s5,s6,average,highest = 0;
    ifstream fin;
    ofstream fout;
    
    cout << "Please enter the file name that you would like to use." << endl;
    cin >> userFile;

    fin.open(userFile);
    fout.open("results.txt");

    if(fin.fail())
    {
    cout << "Error on input file" << endl;
    exit(1);
    }
    if( fout.fail())
    {
    cout << "Error on output file" << endl;
    exit(1);
    }
    while(fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        fout.setf(ios::left);
        average=(s1+s2+s3+s4+s5+s6)/2;
        fout  << setw(10) << firstName << setw(10)  << lastName << setw(10)  << s1 << setw(10) << s2 << setw(10) << s3 << setw(10)<< s4 << setw(10) << s5 << setw(10) << s6 << setw(10) <<  average << setw(10) << endl ;
        
        if(average >= highest)
        {
        name1 = firstName + " " + lastName;
        highest = average;
        }
        else
        {
        highest = highest;
        }
    }

    fout <<"Highest score: " <<name1 << endl;
    
    fin.close();
    fout.close();
    

return 0;
}
