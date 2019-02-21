#include <iostream>
#include <vector>
using namespace std;

void outputRoster(const vector<int> &a, const vector<int> &b);
void addPlayer(vector<int> &a, vector<int> &b);
void removePlayer(vector<int> &a, vector<int> &b);
void updatePlayerRating(const vector<int> &a, vector<int> &b);
void outputPlayersAboveRating(const vector<int> &a, const vector<int> &b);


int main() 
{
    vector<int> a;
    vector<int> b;
    char c;
    int d = 0;
    
    cout << "Enter player 1's jersey number:";
    cin >> d;
    cout << endl;
    
    a.push_back(d);

    cout << "Enter player 1's rating:" << endl;
    cin >> d;
    cout << endl;

    b.push_back(d);
    
    cout << "Enter player 2's jersey number:";
    cin >> d;
    cout << endl;
    
    a.push_back(d);

    cout << "Enter player 2's rating:" << endl;
    cin >> d;
    cout << endl;

    b.push_back(d);
    
    cout << "Enter player 3's jersey number:";
    cin >> d;
    cout << endl;
    
    a.push_back(d);

    cout << "Enter player 3's rating:" << endl;
    cin >> d;
    cout << endl;

    b.push_back(d);
    
    cout << "Enter player 4's jersey number:";
    cin >> d;
    cout << endl;
    
    a.push_back(d);

    cout << "Enter player 4's rating:" << endl;
    cin >> d;
    cout << endl;

    b.push_back(d);
    
    cout << "Enter player 5's jersey number:";
    cin >> d;
    cout << endl;
    
    a.push_back(d);
    
    cout << "Enter player 5's rating:" << endl;
    cin >> d;
    cout << endl;

    b.push_back(d);
    
    outputRoster(a, b);
    
    cout << endl;
    
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;   
    
    cin >> c;
    
    while (c != 'q')
    {
        if (c == 'a')
        {
            addPlayer(a, b);
        }
        if (c == 'd')
        {
            removePlayer(a, b);
        }
        if (c == 'u')
        {
            updatePlayerRating(a, b);
        }
        if (c == 'r')
        {
            outputPlayersAboveRating(a, b);
        }
        if (c == 'o')
        {
            outputRoster(a, b);
        }
        
        cout << endl;
        
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;   
        
        cin >> c;
    }
    
    return 0;
}

void outputRoster(const vector<int> &a, const vector<int> &b)
{
    int count = 0;
    
    cout << "ROSTER" << endl;
    
    for (unsigned int i = 0; i < a.size(); ++i)
    {
        count = count + 1;
        cout << "Player " << count << " -- " << "Jersey number: " << a.at(i) << ", Rating: " << b.at(i) << endl;
    }
    
    return;
}

void addPlayer(vector<int> &a, vector<int> &b)
{
    int c = 0;

    cout << "Enter another player's jersey number:";
    cin >> c;
    cout << endl;
    
    a.push_back(c);
    
    cout << "Enter another player's rating:";
    cin >> c;
    cout << endl;
    
    b.push_back(c);

    return;
}

void removePlayer(vector<int> &a, vector<int> &b)
{
    int j = 0;
    int c = 0;
    
    cout << "Enter a jersey number:" << endl;
    cin >> c;
    
    for (unsigned int i = 0; i < a.size()-1; ++i)
    {
        
        if (a.at(i) == c)
        {
            j = a.at(i+1);
            a.at(i+1) = a.at(i);
            a.at(i) = j;
        
            j = b.at(i+1);
            b.at(i+1) = b.at(i);
            b.at(i) = j;
        }
    }
    
    a.pop_back();
    b.pop_back();
    
    return;
}

void updatePlayerRating(const vector<int> &a, vector<int> &b)
{
    int c = 0;
    int d = 0;
    
    cout << "Enter a jersey number:" << endl;
    cin >> c;
    cout << endl;
    
    cout << "Enter a new rating for player:" << endl;
    cin >> d;
    cout << endl;
    
    for (unsigned int i = 0; i < a.size()-1; ++i)
    {
        if (a.at(i) == c)
        {
            b.at(i) = d;
        }
    }
    
    return;
}

void outputPlayersAboveRating(const vector<int> &a, const vector<int> &b)
{
    int count = 0;
    int c = 0;
    
    cout << "Enter a rating:" << endl;
    cin >> c;
    cout << endl;
    
    cout << "ABOVE " << c << endl;
    
    for (unsigned int i = 0; i < b.size(); ++i)
    {
        ++count;
        if (b.at(i) > c)
        {
            cout << "Player " << count << " -- " << "Jersey number: " << a.at(i) << ", Rating: " << b.at(i) << endl;
        }
        
    }
    
    return;
}
