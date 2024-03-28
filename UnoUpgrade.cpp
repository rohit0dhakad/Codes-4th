#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class uno
{
public:
    vector<string> Pile_of_Cards;
    vector<string> DiscardArray;
    int NumPlayer;

    void Cards()
    {
        string ColorArray[] = {"Red", "Blue", "Green", "Yellow"};
        string NumberArray[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip", "Reverse", "Draw2"};
        string WildCard[] = {"WildDraw4", "WildColour"}; 

        for (int i = 0; i < sizeof(ColorArray) / sizeof(ColorArray[0]); ++i)
        {
            for (int j = 0; j < sizeof(NumberArray) / sizeof(NumberArray[0]); ++j)
            {
                Pile_of_Cards.push_back(ColorArray[i] + " " + NumberArray[j]);
                Pile_of_Cards.push_back(ColorArray[i] + " " + NumberArray[j]);
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < sizeof(WildCard) / sizeof(WildCard[0]); ++j)
            {
                Pile_of_Cards.push_back(WildCard[j]);
            }
        }
        for (int j = 0; j < sizeof(ColorArray) / sizeof(ColorArray[0]); ++j)
        {
            Pile_of_Cards.push_back(ColorArray[j] + " " + "0");
        }
    }
    void ShuffleCards()
    {
        srand(time(0));
        for (int i = Pile_of_Cards.size() - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            swap(Pile_of_Cards[i], Pile_of_Cards[j]);
        }
    }
    void Player()
    {
        while (true)
        {
            try
            {
                cout << "Enter Number of Players: ";
                cin >> NumPlayer;
                if (NumPlayer < 2 || NumPlayer > 10)
                {
                    throw invalid_argument("Enter Minimum 2 or More Players");
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
    }
    vector<vector<string> > Distribution()
    {
        vector<vector<string> > PlayerCards(NumPlayer);
        Player();
        cout << "Before edit: " << Pile_of_Cards.size() << endl;
        for (int j = 0; j < NumPlayer; j++)
        {
            for (int i = 0; i < 7; i++)
            {
                if (Pile_of_Cards.size() == 0)
                {
                    cout << "No more Cards to distribute!" << endl;
                    break;
                }
                PlayerCards[j].push_back(Pile_of_Cards[i]);
                Pile_of_Cards.erase(Pile_of_Cards.begin());
            }
        }
        cout << "After Edits: " << Pile_of_Cards.size() << endl;
        cout << "\nPlayer Cards:\n";
        for (int i = 0; i < NumPlayer; ++i)
        {
            cout << "Player " << i + 1 << ":\n";
            for (size_t j = 0; j < PlayerCards[i].size(); ++j)
            {
                cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
            }
        }
        return PlayerCards;
    }

    void Rules(vector<vector<string> > PlayerCards)
    {
        string playerArrays[NumPlayer];
        for (int i = 0; i < NumPlayer; ++i)
        {
            cout << "Enter name of player " << i + 1 << ": ";
            string playerName;
            cin >> playerName;
            playerArrays[i] = playerName;
        }
        bool reverseOrder = false;
        cout << "Game starts!" << endl;
        int i = 0;
        string LastCard;

        if (DiscardArray.size() == 0)
        {
            DiscardArray.push_back(Pile_of_Cards.at(0));
            Pile_of_Cards.erase(Pile_of_Cards.begin());
        }
        while (true)
        {
            if (i >= NumPlayer)
                i = 0;
            cout << "\nPlayer " << playerArrays[i] << "'s turn." << endl;
            int Card_indx;
            for (int j = 0; j < PlayerCards[i].size(); j++)
            {
                cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
            }
            cout << "Top Cards: ";
            if (DiscardArray.size() < 5)
            {
                for (int i = 0; i < DiscardArray.size(); i++)
                {
                    cout << DiscardArray[i] << " , ";
                }
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    cout << DiscardArray[j] << " , ";
                }
            }
            string lastColor = DiscardArray.at(0).substr(0, DiscardArray.at(0).find(" "));
            string lastValue = DiscardArray.at(0).substr(DiscardArray.at(0).find(" ") + 1);
            cout << "\nLast Color is: " << lastColor;
            cout << "\nLast Value is: " << lastValue;
             bool minusOneChosen = false;
            if (PlayerCards[i].empty())
            {
                cout << "Player " << playerArrays[i] << " has no cards left. Game over!" << endl;
                cout<<"<----GAME IS FINISH---->\nWinner Is Player Number : "<<playerArrays[i]<<"\n THANKS FOR PLAY";
                break;
            }

            if (LastCard == "Skip")
            {
                cout << "\n"<< playerArrays[i] << "'s turn Skipped! Last Card Is Skip Card" << endl;
                LastCard = " ";
                i++;
            }
            else if (LastCard == "Draw2")
            {
                if (Pile_of_Cards.size() < 2)
                {
                    cout << "Not enough cards in the pile to draw 2!" << endl;
                }else{
              cout << " Last Card is Wild Draw 2 Card, so added 2 cards" << endl;
                    for (int j = 0; j < 2; j++)
                    {
                        PlayerCards[i].push_back(Pile_of_Cards[0]);
                        Pile_of_Cards.erase(Pile_of_Cards.begin());
                    }
                    cout << "\nPlayer " << playerArrays[i] << "'s turn." << endl;
                    for (int j = 0; j < PlayerCards[i].size(); j++)
                    {
                        cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
                    }
                    LastCard = " ";
                    i++;
            }}
            else if (LastCard == "WildDraw4") // lastvalue is not draw 4
            {
                if (Pile_of_Cards.size() < 4)
                {
                    cout << "Not enough cards in the pile to draw 4!" << endl;
                }
                else
                {
                    cout << " Last Card is Wild Draw 4 Card, so added 4 cards" << endl;
                    for (int j = 0; j < 4; j++)
                    {
                        PlayerCards[i].push_back(Pile_of_Cards[0]);
                        Pile_of_Cards.erase(Pile_of_Cards.begin());
                    }
                    cout << "\nPlayer " << playerArrays[i] << "'s turn." << endl;
                    for (int j = 0; j < PlayerCards[i].size(); j++)
                    {
                        cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
                    }
                    LastCard = " ";
                    i++;
                }
            }
            else
            {
                while (true)
                {
               
                    try
                    {
                        cout << "\nEnter Your Card Index, if Not Have Card Type -1 and If yoou want to skip your turn enter -2: ";
                        cin >> Card_indx;
                        if (Card_indx == -1 && !minusOneChosen)
                        {
                            PlayerCards[i].push_back(Pile_of_Cards[0]);
                            Pile_of_Cards.erase(Pile_of_Cards.begin());
                            // cout << "\nPlayer " << playerArrays[i] << "'s turn." << endl;

                            // for (int j = 0; j < PlayerCards[i].size(); j++)
                            // {
                            //     cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
                            // }
                            minusOneChosen = true;
                        }
                        else if (Card_indx == -2 && minusOneChosen)
                        {
                            if (!minusOneChosen)
                            {
                                throw invalid_argument( "You must choose -1 at least once before choosing -2.");

                                // cout << "\nPlayer " << playerArrays[i] << "'s turn." << endl;
                                // for (int j = 0; j < PlayerCards[i].size(); j++)
                                // {
                                //     cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
                                // }
                            }
                            minusOneChosen = false;
                            i++;
                        }
                        else if (Card_indx != -1 && Card_indx <= PlayerCards[i].size())
                        {
                            string CurrentColor = PlayerCards.at(i).at(Card_indx - 1).substr(0, PlayerCards.at(i).at(Card_indx - 1).find(" "));
                            string CurrentValue = PlayerCards.at(i).at(Card_indx - 1).substr(PlayerCards.at(i).at(Card_indx - 1).find(" ") + 1);
                            cout << "\nCurrent Color is: " << CurrentColor;
                            cout << "\nCurrent Value is: " << CurrentValue;
                            if ((CurrentColor != lastColor && CurrentValue != lastValue) && CurrentColor != "WildColour" && CurrentColor != "WildDraw4")
                            {
                                throw invalid_argument("Please Check Top Card And Then Throw; You Threw the Wrong Card.");
                            }
                            break;
                        }
                        else
                        {
                            throw invalid_argument("You can only choose -1 once. Please choose a valid index.");
                        }
                        cout << "\nPlayer " << playerArrays[i] << "'s turn." << endl;
                        for (int j = 0; j < PlayerCards[i].size(); j++)
                        {
                            cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
                        }
                    }
                    catch (const invalid_argument &e)
                    {
                        cerr << "\nError: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                string CurrentColor = PlayerCards.at(i).at(Card_indx - 1).substr(0, PlayerCards.at(i).at(Card_indx - 1).find(" "));
                string CurrentValue = PlayerCards.at(i).at(Card_indx - 1).substr(PlayerCards.at(i).at(Card_indx - 1).find(" ") + 1);
                int color;

                string colorarray[] = {"Red", "Blue", "Green", "Yellow"};
                if (CurrentValue == "Reverse" /*&& CurrentColor == lastColor*/)
                {
                    cout << "\nYou Put Reverse Card" << endl;
                    string combinedElement = CurrentColor + " " + CurrentValue;
                    DiscardArray.insert(DiscardArray.begin(), combinedElement);
                    PlayerCards[i].erase(PlayerCards[i].begin() + Card_indx - 1);
                    reverseOrder = !reverseOrder;
                }
                else if (/*CurrentColor == lastColor &&*/ CurrentValue == "Skip") // Done
                {
                    cout << "\nYou Put Skip Card" << endl;
                    string combinedElement = CurrentColor + " " + CurrentValue;
                    DiscardArray.insert(DiscardArray.begin(), combinedElement);
                    PlayerCards[i].erase(PlayerCards[i].begin() + Card_indx - 1);
                    LastCard = "Skip";
                    i++;
                }
                else if (/*CurrentColor == lastColor &&*/ CurrentValue == "Draw2")
                {
                    cout << "\nYou Put Draw 2 Card" << endl;
                   DiscardArray.insert(DiscardArray.begin(), PlayerCards[i][Card_indx - 1]);
                    PlayerCards[i].erase(PlayerCards[i].begin() + Card_indx - 1);
                    LastCard = "Draw2";
                    i++;
                }
                else if (CurrentColor == "WildDraw4")
                {
                    cout << "\nYou Put Wild Draw 4" << endl;
                    DiscardArray.insert(DiscardArray.begin(), PlayerCards[i][Card_indx - 1]);
                    PlayerCards[i].erase(PlayerCards[i].begin() + Card_indx - 1);
                    cout << "\nEnter Color That You Choose {Red(1), Blue(2), Green(3), Yellow(4)}: ";
                    cin >> color;
                    cout << "\nNow New Color Is: " << colorarray[color - 1] << endl;
                    string combinedElement = colorarray[color - 1] + " " + CurrentValue;
                    DiscardArray.insert(DiscardArray.begin(), combinedElement);
                    LastCard = "WildDraw4";
                    i++;
                }
                else if (CurrentColor == lastColor || CurrentValue == lastValue) // Done
                {
                    DiscardArray.insert(DiscardArray.begin(), PlayerCards[i][Card_indx - 1]);
                    PlayerCards[i].erase(PlayerCards[i].begin() + Card_indx - 1);
                    i++;
                }
                else if (CurrentColor == "WildColour") // Done
                {
                    cout << "\nEnter Color That You Choose {Red(1), Blue(2), Green(3), Yellow(4)}: ";
                    cin >> color;
                    cout << "\nNow New Color Is: " << colorarray[color - 1] << endl;
                    string combinedElement = colorarray[color - 1] + " " + CurrentValue;
                    DiscardArray.insert(DiscardArray.begin(), combinedElement);
                    PlayerCards[i].erase(PlayerCards[i].begin() + Card_indx - 1);
                    i++;
                }
                else
                {
                    cout << "\nPlease Check Top Card And Then Throw. You Threw the Wrong Card." << endl;
                    i++;
                }
                if (reverseOrder)
                {
                    i--;
                    reverse(playerArrays, playerArrays + NumPlayer);
                    reverseOrder = false;
                }
            }
        }
    }
};
int main()
{
    uno r1;
    r1.Cards();
    r1.ShuffleCards();
    // vector<vector<string> > temp = r1.Distribution(); //upper function 'Rules' Add -'&' Before PlayerCards  
    r1.Rules( r1.Distribution());
    return 0;
}