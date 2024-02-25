#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <random>
// #include <algorithm>
#include <ctime>
using namespace std;
// Code For User Input Rock,Paper,Scissor And Check User Errors
void play_candidate(string ArrayofPoints[], int candidate_number)
{
    string opinion;
    for (int i = 0; i < candidate_number; i++)
    {
        opinion = getpass("Enter Your Choose Only (𝖗,𝖕,𝖘)(✊✋✌️): ");
        ArrayofPoints[i] = opinion;
        try // Try Catch Block For Input Errors
        {
            if (opinion != "r" && opinion != "p" && opinion != "s" && opinion != "R" && opinion != "P" && opinion != "S")
            {
                throw invalid_argument("Invalid option. Please enter only 𝖗, 𝖕, or 𝖘 or ℝ or ℙ or 𝕊.");
            }
            ArrayofPoints[i] = opinion;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
            cout << "Please enter only 𝖗, 𝕡, or 𝕤.";
            i--; // For Go Back -1 In Array or Loop For Re-input By User
            continue;
        }
    }
}
// Rules and Conditions For Game, Point Table and FinalPointTable
void condition(string ArrayofPoints[], int candidate_number, int *finalpointtable)
{

    int rock = 0, paper = 0, ses = 0;
    cout << "You And Other Chosse : ";
    for (int j = 0; j < candidate_number; j++) // loop Give Points to Rock,P,S
    {
        cout << ArrayofPoints[j] << " ";
        if (ArrayofPoints[j] == "r" || ArrayofPoints[j] == "R")
            rock++;
        else if (ArrayofPoints[j] == "p" || ArrayofPoints[j] == "P")
            paper++;
        else
            ses++;
    }
    cout << endl;
    int ResultArray[candidate_number];

    for (int k = 0; k < candidate_number; k++) // Loop for Put Values in PointTable
    {
        if (ArrayofPoints[k] == "r" || ArrayofPoints[k] == "R")
        {
            ResultArray[k] = ses;
        }
        else if (ArrayofPoints[k] == "p" || ArrayofPoints[k] == "P")
        {
            ResultArray[k] = rock;
        }
        else
        {
            ResultArray[k] = paper;
        }
    }
    cout << "This Game's Result Table : ";
    for (int m = 0; m < candidate_number; m++) // looop for Print PointTable
    {
        cout << ResultArray[m] << " ";
        finalpointtable[m] += ResultArray[m];
    }
    cout << endl
         << '\n';
}
// Function For Randamly Chosse value
void computer_game(string ArrayofPoints[], int candidate_number)
{
    srand(time(0));
    char choise[6] = {'p', 'r', 's'};
    for (int i = 1; i < candidate_number; i++)
    {
        int get_com = rand() % 3; // Rand() For choose A Index
        ArrayofPoints[i] = choise[get_com];
    }
}
// Function for Check Conditon That Play User or  With Computer
void play(string ArrayofPoints[], int candidate_number, int game_number, int *finalpointtable)
{
    int com_player;
    while (true)
    {
        try // Check User Input is Correct or Not
        {
            cout << "\nIf want to play with computer than write 𝟘\nif you want to play with user type 𝟙 : ";
            cin >> com_player;
            cout << endl;
            if (cin.fail()) // If User Type String or Else Then Show Error
            {
                throw invalid_argument("Invalid input. Please enter a valid integer.");
            }
            break; // If Remove Lower comments then Remove Break
            // if (com_player != 1 && com_player != 0)
            // {
            //     throw invalid_argument("Invalid option. Please enter only 0 or 1 ");
            // }
            // break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (com_player == 1) // For Play only user
    {
        for (int i = 0; i < game_number; i++)
        {
            play_candidate(ArrayofPoints, candidate_number);
            condition(ArrayofPoints, candidate_number, finalpointtable);
        }
    }
    if (com_player == 0) // For Play Compter or User
    {
        for (int j = 0; j < game_number; j++)
        {
            play_candidate(ArrayofPoints, 1);

            for (int i = 1; i < candidate_number; i++)
            {
                computer_game(ArrayofPoints, candidate_number);
            }
            condition(ArrayofPoints, candidate_number, finalpointtable);
        }
    }
}
// For Who Won the Match And Final Point Table
void findMax(int *finalpointtable,int candidate_number)  
{
    cout << "Final Result : ";
    for (int l = 0; l < candidate_number; l++)
    {
        cout << finalpointtable[l] << " ";
    }
    int maxVal = finalpointtable[0];
    for (int i = 1; i < candidate_number; ++i)
    {
        if (finalpointtable[i] > maxVal)
        {
            maxVal = finalpointtable[i];
        }
    }
    cout << "\nMax Value is : " << maxVal << endl;
    int count =0;
    int array[candidate_number];
    for (int j = 0; j < candidate_number; j++)
    {   
        if (finalpointtable[j] == maxVal)
        {
            cout << "\nPlayer Number  : " << j + 1 << "Won The Match";
            array[j]=maxVal;
            count++;
        }
    }
    if(count >1){
        cout<< "\nMatch Tie between  ";
        for(int i = 0; i<candidate_number;i++){
            if(array[i]==maxVal){
                cout<<"Player : "<<i+1<<" ";
            }
        }
    }
};
int main()
{
    int candidate_number;
    int game_number;
    cout << "Enter 'r' or 'R' For Rock(✊,🪨)\nEnter 'p' or 'P' For Paper(✋,📃)\nEnter 'r' or 'R' For Scissor(✌️,✂️)" << endl;
    while (true)
    {
        try
        {
            cout << "\nHow many players do you want to play the game : ";
            cin >> candidate_number;
            if (candidate_number <= 1)
            {
                throw invalid_argument("Number of players must be a integer More Than 1.");
            }
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << endl;

    while (true)
    {
        try
        {
            cout << "How many games do you want to play: ";
            cin >> game_number;
            if (game_number <= 0)
            {
                throw invalid_argument("Number of games must be a positive integer.");
            }
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    int *finalpointtable = new int[candidate_number]();
    string ArrayofPoints[candidate_number];
    play(ArrayofPoints, candidate_number, game_number, finalpointtable);

    findMax(finalpointtable,candidate_number);
    delete[] finalpointtable;
}
