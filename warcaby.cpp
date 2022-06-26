#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

typedef struct square
{
    int background;
    int pawn;
}square;
typedef struct player
{
    int pawn;
    string name;
    string against;
}player;
int play = 1; //petla operujaca gra
square tab[10][10]; //plansza
player pla[2];      //gracze
int currentPlayerNumber = 0;         //obecny gracz
int otherPlayerNumber = 1;
int point[2] = {0,0};


void createTable() // Tworzenie planszy
{
    for(int j=0;j<10;j++) //tworze kafelki
    {
        for(int i=0;i<10;i++)
        {
            if(i%2 == 0)
               {
                   if(j%2 == 0)
                    {
                        tab[i][j].background = 1;
                    }
                    else tab[i][j].background = 0;
               }

            else
            {
                    if(j%2 == 1)
                    {
                        tab[i][j].background = 1;
                    }
                    else tab[i][j].background = 0;
            }

            //cout<<tab[i][j].background<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i=0;i<10;i++) // ustawiam pionki
        {
            for(int j=0;j<3;j++)
            {
                if(tab[j][i].background == 0)
                {
                    tab[j][i].pawn = 1;
                }
                else tab[j][i].pawn = 0;
            }
        }
        for(int i=0;i<10;i++)
        {
            for(int j=7;j<10;j++)
            {
                if(tab[j][i].background == 0)
                {
                    tab[j][i].pawn = 2;
                }
                else tab[j][i].pawn = 0;
            }
        }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<10;i++)
        {

            //cout<<tab[i][j].pawn<<" ";
        }
        cout<<endl;
    }
}
void printTable()  //drukowanie planszy
{
    cout<<"Tura gracza: "<<pla[currentPlayerNumber].name<<"              "<<"Zbite pionki: "<<endl<<endl;

    for(int i=0;i<10;i++) //drukuje numeracje gorna
    {
        if(i==0)
        {
            cout<<"   "<<i<<" ";
        }
        else
        {
            cout<<i<<" ";
        }
    }
    cout<<"     "<<pla[currentPlayerNumber].name<<": "<<point[currentPlayerNumber]<<'\t'<<pla[otherPlayerNumber].name<<": "<<point[otherPlayerNumber];
    cout<<endl;
    cout<<endl;
    for(int i=0;i<10;i++)//numeracja dolna
    {
        cout<<i<<". ";
        for(int j=0;j<10;j++) //plansza
        {
            if(tab[i][j].pawn == 0)
            {
                if(tab[i][j].background == 0)
                {
                    printf("%c ",32);
                }
                else
                {
                    printf("%c ", 176);
                }
            }
            else
            {
                if(tab[i][j].pawn == 1)
                {
                    cout<<"U ";
                }
                else
                {
                    cout<<"A ";
                }
            }
        }
        cout<<endl;
    }
}


void gameEnd()
{
    if(play == 1)
    {
        play = 0;
    }
}

void getPlayers()
{
    cout<<"Nazwa bialych: "<<endl;
    string temp;
    cin>>temp;
    pla[0].name = temp;
    pla[1].against = temp;
    pla[0].pawn = 1;

    cout<<"Nazwa czarnych: "<<endl;
    cin>>temp;
    pla[1].name = temp;
    pla[0].against = temp;
    pla[1].pawn = 2;


}
void changePlayer() // zmiana gracza
{
    if(currentPlayerNumber == 0)
    {
        currentPlayerNumber = 1;
        otherPlayerNumber = 0;
    }
    else
    {
        currentPlayerNumber = 0;
        otherPlayerNumber = 1;
    }
}
void printPlayers()
{
    cout<<"Biale: "<<pla[0].name<<endl;
    cout<<"Czarne: "<<pla[1].name<<endl;
}
void printMenu()
{
    cout<<"Menu: "<<endl;
    cout<<"[1] Wykonaj ruch "<<endl;
    cout<<"[0] Poddaj gre "<<endl;
    cout<<"Wybor: "<<endl;
}
void gameOverSurrender()
{
    cout<<"Gracz "<<pla[currentPlayerNumber].name<<" poddal gre. "<<endl;
    cout<<"Zwyciezca jest "<<pla[currentPlayerNumber].against;
    play = 0;
}
void makeMove()
{
    int pawnX;
    int pawnY;
    int newPawnX;
    int newPawnY;
    int ok1=0;
    int ok2=0;
    int ok3=0;
    int possibility = 0;
    int moveEnded = 0;
    int whatToDo;
    do
    {
        do{
            cout<<"Podaj X i Y pionka ktory chcesz ruszyc: "<<endl;
            cin>>pawnX;
            cin>>pawnY;
            if(tab[pawnY][pawnX].pawn == pla[currentPlayerNumber].pawn)
            {
                ok1 = 1;
            }
            else
            {
                cout<<"to nie Twoj pionek!"<<endl;
                cout<<"Wybierz inne pole: "<<endl;
            }
        }while(!ok1);
        if(currentPlayerNumber == 0)
        {
            if(pawnX==0)
            {
                if(tab[pawnY+1][pawnX+1].pawn == pla[currentPlayerNumber].pawn)
                {
                    possibility = 0;
                }
                else if(tab[pawnY+1][pawnX+1].pawn == pla[otherPlayerNumber].pawn )
                {
                    if(tab[pawnY+2][pawnX+2].pawn == 0)
                    {
                        possibility = 1;
                    }
                    else
                    {
                        possibility = 0;
                    }
                }
                else if(tab[pawnY+1][pawnX+1].pawn == 0)
                {
                    possibility = 1;
                }
            }
            else if(pawnX == 9)
            {
                if(tab[pawnY+1][pawnX-1].pawn == pla[currentPlayerNumber].pawn)
                {
                    possibility = 0;
                }
                else if(tab[pawnY+1][pawnX-1].pawn == pla[otherPlayerNumber].pawn )
                {
                    if(tab[pawnY+2][pawnX-2].pawn == 0)
                    {
                        possibility = 1;
                    }
                    else
                    {
                        possibility = 0;
                    }
                }
                else if(tab[pawnY+1][pawnX-1].pawn == 0)
                {
                    possibility = 1;
                }
            }
            else
            {
                if(tab[pawnY+1][pawnX-1].pawn == pla[currentPlayerNumber].pawn || tab[pawnY+1][pawnX+1].pawn == pla[currentPlayerNumber].pawn)
                {
                    possibility = 0;
                }
                else if(tab[pawnY+1][pawnX-1].pawn == pla[otherPlayerNumber].pawn || tab[pawnY+1][pawnX+1].pawn == pla[otherPlayerNumber].pawn)
                {
                    if(tab[pawnY+2][pawnX-2].pawn == 0 || tab[pawnY+2][pawnX+2].pawn == 0)
                    {
                        possibility = 1;
                    }
                    else
                    {
                        possibility = 0;
                    }
                }
                else if(tab[pawnY+1][pawnX-1].pawn == 0 || tab[pawnY+1][pawnX+1].pawn == 0)
                {
                    possibility = 1;
                }
            }
        }
        else if(currentPlayerNumber == 1)
        {
            if(pawnX==0)
            {
                if(tab[pawnY-1][pawnX+1].pawn == pla[currentPlayerNumber].pawn)
                {
                    possibility = 0;
                }
                else if(tab[pawnY-1][pawnX+1].pawn == pla[otherPlayerNumber].pawn )
                {
                    if(tab[pawnY-2][pawnX+2].pawn == 0)
                    {
                        possibility = 1;
                    }
                    else
                    {
                        possibility = 0;
                    }
                }
                else if(tab[pawnY-1][pawnX+1].pawn == 0)
                {
                    possibility = 1;
                }
            }
            else if(pawnX == 9)
            {
                if(tab[pawnY-1][pawnX-1].pawn == pla[currentPlayerNumber].pawn)
                {
                    possibility = 0;
                }
                else if(tab[pawnY-1][pawnX-1].pawn == pla[otherPlayerNumber].pawn )
                {
                    if(tab[pawnY-2][pawnX-2].pawn == 0)
                    {
                        possibility = 1;
                    }
                    else
                    {
                        possibility = 0;
                    }
                }
                else if(tab[pawnY-1][pawnX-1].pawn == 0)
                {
                    possibility = 1;
                }
            }
            else
            {
                if(tab[pawnY-1][pawnX-1].pawn == pla[currentPlayerNumber].pawn || tab[pawnY-1][pawnX+1].pawn == pla[currentPlayerNumber].pawn)
                {
                    possibility = 0;
                }
                else if(tab[pawnY-1][pawnX-1].pawn == pla[otherPlayerNumber].pawn || tab[pawnY-1][pawnX+1].pawn == pla[otherPlayerNumber].pawn)
                {
                    if(tab[pawnY-2][pawnX-2].pawn == 0 || tab[pawnY-2][pawnX+2].pawn == 0)
                    {
                        possibility = 1;
                    }
                    else
                    {
                        possibility = 0;
                    }
                }
                else if(tab[pawnY-1][pawnX-1].pawn == 0 || tab[pawnY-1][pawnX+1].pawn == 0)
                {
                    possibility = 1;
                }
            }
        }

        if(possibility == 0)
        {
            cout<<"Pionek bez mozliwosci ruchu!"<<endl;
        }
        else if(possibility == 1)
        {
            do{
                do{
                ok2=0;
                cout<<"[1] Wykonaj ruch"<<endl;
                cout<<"[2] Zmien pionek"<<endl;
                cout<<"[0] Poddaj gre"<<endl;

                cin>>whatToDo;
                if((whatToDo == 1 || whatToDo == 2) || whatToDo == 0)
                {
                    ok2 = 1;
                }
                else
                {
                    cout<<"Nie ma takiej opcji."<<endl;
                }
                }while(!ok2);
                if(whatToDo == 0)
                {
                    gameOverSurrender();
                    moveEnded=1;
                    ok3=1;
                }
                else if(whatToDo == 1)
                {
                    cout<<"Podaj gdzie chcesz przesunac pionek"<<endl;
                    cin>>newPawnX;
                    cin>>newPawnY;
                    if(tab[newPawnY][newPawnX].pawn == 0)
                    {
                        tab[newPawnY][newPawnX].pawn = pla[currentPlayerNumber].pawn;
                        tab[pawnY][pawnX].pawn = 0;
                        ok3 = 1;
                        moveEnded = 1;
                    }
                    else if(tab[newPawnY][newPawnX].pawn == pla[otherPlayerNumber].pawn)
                    {
                        if(pawnY < newPawnY)
                        {
                            if(pawnX > newPawnX)
                            {
                                if(tab[newPawnY+1][newPawnX-1].pawn == 0)
                                {
                                    tab[newPawnY+1][newPawnX-1].pawn = pla[currentPlayerNumber].pawn;
                                    tab[newPawnY][newPawnX].pawn = 0;
                                    point[currentPlayerNumber]++;
                                    tab[pawnY][pawnX].pawn = 0;
                                    ok3 = 1;
                                    moveEnded = 1;
                                }
                                else
                                {
                                    cout<<"Nie ma takiej opcji."<<endl;
                                }
                            }
                            else
                            {
                                if(tab[newPawnY+1][newPawnX+1].pawn == 0)
                                {
                                    tab[newPawnY+1][newPawnX+1].pawn = pla[currentPlayerNumber].pawn;
                                    tab[newPawnY][newPawnX].pawn = 0;
                                    point[currentPlayerNumber]++;
                                    tab[pawnY][pawnX].pawn = 0;
                                    ok3 = 1;
                                    moveEnded = 1;
                                }
                                else
                                {
                                    cout<<"Nie ma takiej opcji."<<endl;
                                }
                            }
                        }
                        else//kiedy od dolu atakuje
                        {
                            if(pawnX > newPawnX)
                            {
                                if(tab[newPawnY-1][newPawnX-1].pawn == 0)
                                {
                                    tab[newPawnY-1][newPawnX-1].pawn = pla[currentPlayerNumber].pawn;
                                    tab[newPawnY][newPawnX].pawn = 0;
                                    point[currentPlayerNumber]++;
                                    tab[pawnY][pawnX].pawn = 0;
                                    ok3 = 1;
                                    moveEnded = 1;
                                }
                                else
                                {
                                    cout<<"Nie ma takiej opcji."<<endl;
                                }
                            }
                            else
                            {
                                if(tab[newPawnY-1][newPawnX+1].pawn == 0)
                                {
                                    tab[newPawnY-1][newPawnX+1].pawn = pla[currentPlayerNumber].pawn;
                                    tab[newPawnY][newPawnX].pawn = 0;
                                    point[currentPlayerNumber]++;
                                    tab[pawnY][pawnX].pawn = 0;
                                    ok3 = 1;
                                    moveEnded = 1;
                                }
                                else
                                {
                                    cout<<"Nie ma takiej opcji."<<endl;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout<<"Nie ma takiej opcji."<<endl;
                    }
                }
                else if(whatToDo == 2)
                {
                    cout<<"zmiana pionka."<<endl;
                    ok3=1;

                }
            }while(!ok3);
        }

    }while(!moveEnded);

}
void makeChoice()
{
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
            {
                makeMove();
                break;
            }
        case 0:
            {
                play = 0;
                gameOverSurrender();
                break;
            }

    }
}
void isWinner()
{
    if(point[0] == 15)
    {
        cout<<"Zwyciezca jest: "<<pla[0].name<<" !!!"<<endl;
    }
    else if(point[1] == 15)
    {
        cout<<"Zwyciezca jest: "<<pla[1].name<<" !!!"<<endl;
    }
}
int main()
{
    createTable();//tworze stol
    getPlayers();
    printPlayers();
    Sleep(1000);
    do
    {
        system("cls");
        printTable();//drukuje stol
        printMenu();
        makeChoice();
        changePlayer();
        isWinner();

    }while(play);
    //while(!play);

    return 0;
}
