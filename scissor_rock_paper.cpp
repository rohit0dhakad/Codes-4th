#include <iostream>
#include <unistd.h>
using namespace std;

void candidate(int candidate_number, int number_of_games, int *PointArray)
{
    string opinion;
    string arr[candidate_number];
    for (int i = 0; i < candidate_number; i++)
    {
        cout << "Candidate number " <<i+1;
        opinion = getpass("Enter His option only (r,p,s): ");
        arr[i] = opinion;
        try
        {
            if (opinion != "r" && opinion != "p" && opinion != "s" && opinion != "R" && opinion != "P" && opinion != "S")
            {
                throw invalid_argument("Invalid option. Please enter only r, p, or s or R or P or S.");
            }
            arr[i] = opinion;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
            cout << "Please enter only r, p, or s." << endl;
            // Prompt user for input again
            i--;      // Revisit the current index
            continue; // Skip to the next iteration of the loop
        }
    }
    int rock = 0, paper = 0, ses = 0;
    cout << "Array is : ";
    for (int j = 0; j < candidate_number; j++)
    {
        cout << arr[j] << " ";
        if (arr[j] == "r" || arr[j] == "R")
            rock++;
        else if (arr[j] == "p" || arr[j] == "P")
            paper++;
        else
            ses++;
    }
    cout << endl;
    int ResultArray[candidate_number];

    for (int k = 0; k < candidate_number; k++)
    {
        if (arr[k] == "r" || arr[k] == "R")
        {
            ResultArray[k] = ses;
        }
        else if (arr[k] == "p" || arr[k] == "P")
        {
            ResultArray[k] = rock;
        }
        else
        {
            ResultArray[k] = paper;
        }
    }
    cout << "Result Table : ";
    for (int m = 0; m < candidate_number; m++)
    {
        cout << ResultArray[m] << " ";
        PointArray[m] += ResultArray[m];
    }
    cout << endl;
};

int main()
{
    int candidate_number;
    cout << "Enter Number of candidate : ";
    cin >> candidate_number;
    int number_of_games;
    cout << "Enter \"R\" or \"r\" For Rock\n"
         << "Enter \"S\" or \"s\" for scissors\n"
         << "Enter \"P or \"p\" For Paper " << endl;
    cout << "Enter Number of Games How many times You want to play : ";
    cin >> number_of_games;
    int *PointArray = new int[candidate_number];
    for (int n = 0; n < number_of_games; n++)
    {
        candidate(candidate_number, n, PointArray);
    }
    cout << "Final Result : ";

    for (int l = 0; l < candidate_number; l++)
    {
        cout << PointArray[l] << " ";
    }

    delete[] PointArray;
}