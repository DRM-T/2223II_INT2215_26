#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string word, topic, ABC, result="";
char guess;
int turn=0, wrongTurn=1, N=0, M;

void printFigure(int x)
{
    if (x==1)
    {
        cout<< "  ----------  \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        return;
    }
    if (x==2)
    {
        cout<< "  ----------  \n";
        cout<< "  |        |  \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        return;
    }
    if (x==3)
    {
        cout<< "  ----------  \n";
        cout<< "  |        |  \n";
        cout<< "  |        o  \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        return;
    }
    if (x==4)
    {
        cout<< "  ----------  \n";
        cout<< "  |        |  \n";
        cout<< "  |        o  \n";
        cout<< "  |        |  \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        return;
    }
    if (x==5)
    {
        cout<< "  ----------  \n";
        cout<< "  |        |  \n";
        cout<< "  |        o  \n";
        cout<< "  |       /|  \n";
        cout<< "  |           \n";
        cout<< "  |           \n";
        return;
    }
    if (x==6)
    {
        cout<< "  ----------  \n";
        cout<< "  |        |   \n";
        cout<< "  |        o   \n";
        cout<< "  |       /|\\ \n";
        cout<< "  |            \n";
        cout<< "  |            \n";
        return;
    }
    if (x==7)
    {
        cout<< "  ----------   \n";
        cout<< "  |        |   \n";
        cout<< "  |        o   \n";
        cout<< "  |       /|\\ \n";
        cout<< "  |       /    \n";
        cout<< "  |            \n";
        return;
    }
    if (x==8)
    {
        cout<< "  ----------   \n";
        cout<< "  |        |   \n";
        cout<< "  |        o   \n";
        cout<< "  |       /|\\ \n";
        cout<< "  |       / \\ \n";
        cout<< "  |            \n";
        return;
    }

}

void updateABC(char c)
{
    ABC[(int(c)-97)*2]='_';
}
void chooseWord()
{
    cout<< "Please choose the topic you want to guess from the following topics: \n1. flowers\n2. colors\n3. subjects\n4. countries\n";
    cout<< "Your choice is (1/2/3/4): ";
    int Topic;
    cin>> Topic;
    switch (Topic)
    {
        case 1: topic="flowers"; break;
        case 2: topic="colors"; break;
        case 3: topic="subjects"; break;
        case 4: topic="countries"; break;
    }
    ifstream file("DataHangManGame/"+topic+".txt");
    string listOfWords[1000];
    int n=0;
    while (!file.eof())
    {
        file>> listOfWords[n];
        n++;
    }
    word=listOfWords[rand()%(n-1)];
}

void chooseChar()
{
    turn++;
    cout<< endl<< "TURN "<< turn<< ":"<< endl;
    printFigure(wrongTurn);
    cout<< endl;

    cout<< "result now: "<< result<< endl;
    cout<< "The alphabet now: "<< ABC<< endl;
    cout<< "WrongTurn now: "<< wrongTurn-1<< endl;
    cout<< "Let enter your character: ";
    cin>> guess;
    updateABC(guess);
}
void restart()
{
    ABC="a b c d e f g h i j k l m n o p q r s t u v w x y z";
    chooseWord();
    N=word.length();
    M=N;
    for (int i=0; i<N; i++)
        result+="_ ";
}

void solve()
{
    cout<< endl;
    bool done=false;
    for (int i=0; i<N; i++)
        if (word[i]==guess)
        {
            done=true;
            result[i*2]=guess;
            M--;
        }
    if (done)
        cout<< "Excellent!!!"<< endl;
    else
    {
        cout<< "sai goyyy!!!"<< endl;
        wrongTurn++;
    }

}
int main()
{
    srand(time(0));
    restart();
    while (M>0 && wrongTurn<8)
    {
        chooseChar();
        system("cls");
        solve();
    }
    if (M<=0)
    {
        printFigure(wrongTurn);
        cout<< endl<< "You are excellent!!! The result is: "<< word;
    }

    else
    {
        printFigure(8);
        cout<< endl<< "Oh no, the rusult is: "<< word;
    }

}
