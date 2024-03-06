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
    // string DiscardArray;
    void Cards()
    {
        string ColorArray[] = {"Red", "Blue", "Green", "Yellow"};
        string NumberArray[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip", "Reverse", "Draw 2"};
        string WildCard[] = {"Wild Draw 4", "Wild Colour"};

        // int SizeOfColor = sizeof(ColorArray) / sizeof(ColorArray[0]);

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
        cout << endl;
    }
    void SuffleCards()
    {
        // srand(static_cast<unsigned int>(time(nullptr)));
        srand(time(0));
        for (int i = Pile_of_Cards.size() - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            swap(Pile_of_Cards[i], Pile_of_Cards[j]);
        }
    }

    void PrintCards()
    {
        for (int k = 0; k < Pile_of_Cards.size(); ++k)
        {
            cout << Pile_of_Cards[k] << "   ";
        }
        cout << endl;
    };

    void Player()
    {
        while (true)
        {
            try
            {
                cout << "Enter Number of Player's : ";
                cin >> NumPlayer;
                if (NumPlayer < 2 || NumPlayer > 10)
                {
                    throw invalid_argument("Enter Minimam 2 or More Players");
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
        cout << "Before edit : " << Pile_of_Cards.size() << endl;
        // PrintCards();
        for (int j = 0; j < NumPlayer; j++)
        {
            for (int i = 0; i < 7; i++)
            {
                if (Pile_of_Cards.size() == 0)
                {
                    cout << "No more Cards to distribute!" << endl;
                    // retu;
                    break;
                }
                PlayerCards[j].push_back(Pile_of_Cards[i]);
                Pile_of_Cards.erase(Pile_of_Cards.begin());
            }
        }
        cout << "After Edits : " << Pile_of_Cards.size() << endl;
        // PrintCards();
        cout << "\nPayer Cards:\n";
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

    // void DiscardedCards()
    // {
    //     if (DiscardArray.size() == 0)
    //     {
    //         DiscardArray.push_back(Pile_of_Cards.at(0));
    //         cout << "Top Card Is : " << DiscardArray.at(0) << endl;
    //         Pile_of_Cards.erase(Pile_of_Cards.begin());
    //     }
    // }
    void Rules(vector<vector<string>  > PlayerCards)
    {
        // Player();
        // cout << "Enter the number of players: ";
        // cin >> NumPlayer;
        string playerArrays[NumPlayer];

        for (int i = 0; i < NumPlayer; ++i)
        {
            cout << "Enter name of player " << i + 1 << ": ";
            string playerName;
            cin >> playerName;
            // playerArrays.push_back(playerName);
            playerArrays[i] = playerName;
        }
        bool reverseOrder = false;
        cout << "Game starts!" << endl;
        int i = 0;
       
        if (DiscardArray.size() == 0)
        {
            DiscardArray.push_back(Pile_of_Cards.at(0));
            // cout  <<"Top Card Is : "<<DiscardArray.at(0) << endl;
            Pile_of_Cards.erase(Pile_of_Cards.begin());
        }
        while (PlayerCards[0].size() != 0)
        {
            if (i >= NumPlayer)
                i = 0;
            cout << "Player " << playerArrays[i] << "'s turn." << endl;
            int Card_indx;
            for (int j = 0; j < PlayerCards[i].size(); j++)
            {
                cout << "  Card " << j + 1 << ": " << PlayerCards[i][j] << endl;
            }
            cout << "Top Cards : ";
            if (DiscardArray.size() < 5)
            {
                for (int i = 0; i < DiscardArray.size(); i++)
                {
                    cout << DiscardArray[i]<<" , "; 
                }
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    cout<< DiscardArray[j]<<" , ";
                }
            }

            cout << "\nEnter Your Card Index(0-n) : ";
            cin >> Card_indx;
            string lastColor = DiscardArray.at(0).substr(0, DiscardArray.at(0).find(" "));
            string lastValue = DiscardArray.at(0).substr(DiscardArray.at(0).find(" ") + 1);
            string CurrentColor = PlayerCards.at(i).at(Card_indx).substr(0, PlayerCards.at(i).at(Card_indx).find(" "));
            string CurrentValue = PlayerCards.at(i).at(Card_indx).substr(PlayerCards.at(i).at(Card_indx).find(" ") + 1);

            if (CurrentValue == "Reverse" && CurrentColor == lastColor)
            {
                reverseOrder = !reverseOrder;
            }
            else if (lastValue == "Skip") // remover color
            {
                cout << playerArrays[i] << "'s turn skipped!" << endl;
                i++;
            }
            else if (lastValue == "Draw2") // romoved color
            {
                // string newElement;
                // cout << "Enter the element to add for " << playerArrays[i][0] << ": ";
                // playerArrays[i].push_back(Pile_of_Cards[0]);
                // Pile_of_Cards.erase(Pile_of_Cards.begin());
                // playerArrays[i].push_back(Pile_of_Cards[0]);
                // Pile_of_Cards.erase(Pile_of_Cards.begin());
                if (Pile_of_Cards.size() < 2)
                {
                    cout << "Not enough cards in the pile to draw 2!" << endl;
                }
                else
                {
                    // string newElement;
                    // cout << "Enter the element to add for " << playerArrays[i][0] << ": ";
                    PlayerCards[i + 1].push_back(Pile_of_Cards[0]);
                    Pile_of_Cards.erase(Pile_of_Cards.begin());

                    PlayerCards[i + 1].push_back(Pile_of_Cards[0]);
                    Pile_of_Cards.erase(Pile_of_Cards.begin());
                    ++i;
                }
            }
            else if (CurrentColor == "WildColour")
            {
                int color;
                string colorarray[] = {"Red", "Blue", "Green", "Yellow"};
                cout << "Enter Color That You Choose {Red(1),Blue(2),Green(3),Yellow(4)}  : ";
                cin >> color;

                cout << "\nNow New Color Is : " << colorarray[color - 1];
                colorarray[color - 1] = lastColor;
            }
            // if (reverseOrder)
            // {reverse(playerArrays[0], playerArrays[NumPlayer - 1]);reverseOrder = false;}
            // else
            // {++i; Move to the next player's turn}
            DiscardArray.insert(DiscardArray.begin(),PlayerCards[i][Card_indx]);
            PlayerCards[Card_indx].erase(PlayerCards[Card_indx].begin() + Card_indx);

            ++i;
        }
    }
};
int main()
{
    uno r1;
    r1.Cards();
    r1.SuffleCards();
    vector<vector<string> > temp = r1.Distribution();
    // r1.DiscardedCards();
    r1.Rules(temp);
    return 0;
}