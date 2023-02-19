#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <windows.h>

using namespace std;

string word, topic, Alphabet="", result="";

char guess;
int turn=0, wrongTurn=1, N=0, M;

void set_color( int code );
void printFigure(int x);
void updateABC(char c);
void chooseWord();
void chooseChar();
void restart();
void solve();
void pr(string , int, int);
void normal();

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
        cout<< endl;
        pr("You are excellent!!! The result is: ", 0, 2);
        pr(word, 0, 6);
        cout<< endl;
    }

    else
    {
        printFigure(8);
        cout<< endl;
        pr("Oh no, the rusult is: ", 0, 2);
        pr(word, 0, 6);
        cout<< endl;
    }

}
void set_color( int code )
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}

void normal()
{
    set_color(0 << 4 | 7);
}

void pr(string s, int a, int b)
{
    set_color(a << 4 | b);
    cout<< s;
    normal();
}
void printFigure(int x)
{
    set_color(7 << 4 | 0);
    if (x==1)
    {
        set_color(7 << 4 | 4);
        cout<< "        o        \n";
        cout<< "       /|\\       \n";
        cout<< "       / \\       \n";
        set_color(7 << 4 | 0);
        cout<< "      #####      \n";
        cout<< "     #######     \n";
        cout<< "#################\n";
    }
    if (x==2)
    {
        set_color(7 << 4 | 4);
        cout<< "        o        \n";
        cout<< "       /|\\       \n";
        cout<< "       / \\       \n";
        set_color(7 << 4 | 0);
        cout<< "      #####      \n";
        cout<< "     #######     \n";
        set_color(9 << 4 | 0);
        cout<< "#################\n";
    }
    if (x==3)
    {
        set_color(7 << 4 | 4);
        cout<< "        o        \n";
        cout<< "       /|\\       \n";
        cout<< "       / \\       \n";
        set_color(7 << 4 | 0);
        cout<< "      #####      \n";
        set_color(9 << 4 | 0);
        cout<< "~ ~ ~#######~ ~ ~\n";
        cout<< "#################\n";
    }
    if (x==4)
    {
        set_color(7 << 4 | 4);
        cout<< "        o        \n";
        cout<< "       /|\\       \n";
        cout<< "       / \\       \n";
        set_color(9 << 4 | 0);
        cout<< " ~ ~ ~#####~ ~ ~ \n";
        cout<< "~ ~ ~#######~ ~ ~\n";
        cout<< "#################\n";
        return;
    }
    if (x==5)
    {
        set_color(7 << 4 | 4);
        cout<< "        o        \n";
        cout<< "       /|\\       \n";
        set_color(9 << 4 | 0);
        cout<< "~ ~ ~ ~/ \\~ ~ ~ ~\n";
        cout<< " ~ ~ ~#####~ ~ ~ \n";
        cout<< "~ ~ ~#######~ ~ ~\n";
        cout<< "#################\n";
    }
    if (x==6)
    {
        set_color(7 << 4 | 4);
        cout<< "        o        \n";
        set_color(9 << 4 | 0);
        cout<< " ~ ~ ~ /|\\ ~ ~ ~ \n";
        cout<< "~ ~ ~ ~/ \\~ ~ ~ ~\n";
        cout<< " ~ ~ ~#####~ ~ ~ \n";
        cout<< "~ ~ ~#######~ ~ ~\n";
        cout<< "#################\n";
    }
    if (x==7)
    {
        set_color(7 << 4 | 4);
        cout<< "       \\o/       \n";
        set_color(9 << 4 | 0);
        cout<< "~ ~ ~ ~ | ~ ~ ~ ~\n";
        cout<< " ~ ~ ~ / \\ ~ ~ ~ \n";
        cout<< "~ ~ ~ ~ ~ ~ ~ ~ ~\n";
        cout<< " ~ ~ ~#####~ ~ ~ \n";
        cout<< "~ ~ ~#######~ ~ ~\n";
        cout<< "#################\n";
    }
    if (x==8)
    {
        set_color(9 << 4 | 0);
        cout<< " ~ You lose!!! ~ \n";
        cout<< "~ ~ ~ ~ ~ ~ ~ ~ ~\n";
        cout<< " ~ ~ ~  >-o  ~ ~ \n";
        cout<< "~ ~ ~ ~ ~ ~ ~ ~ ~\n";
        cout<< " ~ ~ ~#####~ ~ ~ \n";
        cout<< "~ ~ ~#######~ ~ ~\n";
        cout<< "#################\n";
    }
    normal();
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
    set_color(0 << 4 | 6);
    cout<< endl<< "TURN "<< turn<< ":"<< endl;
    normal();
    printFigure(wrongTurn);
    cout<< endl;

    pr("  - Result: ", 0, 2);
    cout<< result<< endl<< endl;
    pr("  -- Alphabet: ", 0, 2);
    cout<< Alphabet<< endl<< endl;
    pr("  --- WrongTurn: ", 0, 2);
    cout<< wrongTurn-1<< endl<< endl;
    pr("  ---- Let enter your character: ", 0, 2);
    cin>> guess;
    updateABC(guess);
}

void restart()
{
    Alphabet="a b c d e f g h i j k l m n o p q r s t u v w x y z";
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
    {
        set_color(0 << 4 | 4);
        cout<< "Excellent!!!"<< endl;
        normal();
    }
    else
    {
        set_color(0 << 4 | 4);
        cout<< "Wrongggg!!!"<< endl;
        normal();
        wrongTurn++;
    }
}

void updateABC(char c)
{
    Alphabet[(int(c)-97)*2]='_';
}
