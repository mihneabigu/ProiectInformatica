#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <limits>
using namespace std;

bool exitGame=0;

void creareCont(char username[100][30],char password[100][30], char suma[100][30], int &linie)
{
    ofstream fout("BazaDate.txt", ios::out | ios::app);
    backToCreareCont:
    system("CLS");
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"$                                 $"<<endl;
    cout<<"$    Casino Games - BLACK JACK    $"<<endl;
    cout<<"$                                 $"<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

    cout<<"Please enter your Username (between 1 and 30 characters): ";
    cin>>username[linie];
    bool oki=0;
    for (int i=1;i<linie;i++)
        if (strcmp(username[linie],username[i])==0)
            {
                oki=1;
                break;
            }
    if (oki==1)
    {
        cout<<endl<<"The Username you have entered is already registered. Please enter a new username"<<endl<<endl;
        system("pause");
        goto backToCreareCont;
    }
    cout<<endl;
    cout<<"Please enter your Password (between 1 and 30 characters): ";
    cin>>password[linie];
    cout<<endl<<endl;
    strcpy(suma[linie],"1000");
    cout<<"You have been automatically credited with 1000$"<<endl;
    Sleep(2000);
    fout<<username[linie]<<" "<<password[linie]<<" "<<suma[linie]<<endl;
    linie++;

}

bool verificareContUser(char a[30], char b[30])
{
    if (strcmp(a,b)!=0)
        return 0;
    return 1;
}

bool checkIfNotBust(int a)
{
    if (a>21)
        return 0;
    return 1;
}

void afisareCasino()
{
    system("CLS");
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"$                                 $"<<endl;
    cout<<"$    Casino Games - BLACKJACK     $"<<endl;
    cout<<"$                                 $"<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;
}

void afisareDealer(int vCarti[20], int vSimbol[20], int &total, int contor)
{
    system("CLS");
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"$                                 $"<<endl;
    cout<<"$    Casino Games - BLACK JACK    $"<<endl;
    cout<<"$                                 $"<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;



    cout<<"Dealer's hand: ";


    total=0;
    int t=0;
    for (int i=1; i<contor; i++)
    {
        if (vCarti[i]<=10)
            cout<<vCarti[i];
        if (vCarti[i]==11)
            cout<<"J";
        if (vCarti[i]==12)
            cout<<"Q";
        if (vCarti[i]==13)
            cout<<"K";
        if (vCarti[i]==14)
        {
            cout<<"A";
            t++;
        }
        if (vSimbol[i]==1)
            cout<<'\5'<<" ";
        if (vSimbol[i]==2)
            cout<<'\3'<<" ";
        if (vSimbol[i]==3)
            cout<<'\6'<<" ";
        if (vSimbol[i]==4)
            cout<<'\4'<<" ";
        if (vCarti[i]>10&&vCarti[i]<14)
            total=total+10;
        else if (vCarti[i]==14)
        {
            if (total+11<=21)
                total=total+11;
            else
                total=total+1;
        }
        else
            total=total+vCarti[i];
    }
    if (total>21&&t>0)
        while(total>21&&t!=0)
        {
            total=total-10;
            t--;
        }
    if (checkIfNotBust(total)==1)

        cout<<"TOTAL: "<<total<<endl<<endl;
    else
    {
        cout<<"TOTAL: "<<total<<endl<<endl;
        cout<<"BUSTED"<<endl<<endl;
    }
}

void afisarePlayer(int vCarti[20], int vSimbol[20], int &total, int contor)
{
    cout<<"Player's hand: ";
    total=0;
    int t=0;
    for (int i=1; i<contor; i++)
    {
        if (vCarti[i]<=10)
            cout<<vCarti[i];
        if (vCarti[i]==11)
            cout<<"J";
        if (vCarti[i]==12)
            cout<<"Q";
        if (vCarti[i]==13)
            cout<<"K";
        if (vCarti[i]==14)
        {
            cout<<"A";
            t++;
        }
        if (vSimbol[i]==1)
            cout<<'\5'<<" ";
        if (vSimbol[i]==2)
            cout<<'\3'<<" ";
        if (vSimbol[i]==3)
            cout<<'\6'<<" ";
        if (vSimbol[i]==4)
            cout<<'\4'<<" ";
        if (vCarti[i]>10&&vCarti[i]<14)
            total=total+10;
        else if (vCarti[i]==14)
        {
            if (total+11<=21)
                total=total+11;
            else
                total=total+1;
        }
        else
            total=total+vCarti[i];
    }
    if (total>21&&t>0)
        while(total>21&&t!=0)
        {
            total=total-10;
            t--;
        }
    if (checkIfNotBust(total)==1)

        cout<<"TOTAL: "<<total<<endl<<endl;
    else
    {
        cout<<"TOTAL: "<<total<<endl<<endl;
        cout<<"BUSTED"<<endl<<endl;
    }
}

void Hit(int vCarti[20], int vSimbol[20], int &contor)
{
    vCarti[contor]=rand()%13+2;
    vSimbol[contor]=rand()%4+1;
    contor++;
}

void citireBazaDate(char username[100][30], char password[100][30], char suma[100][30], int linie)
{
    ifstream fin("BazaDate.txt");
    int t;
    for(t=1; t<=linie-1; t++)
    {
        int oki=0;
        char a[90];
        fin.getline(a,90);
        char *p;
        p=strtok(a," ");
        while(p!=NULL)
        {
            if (oki==0)
            {
                strcpy(username[t],p);
                oki=1;
            }
            else if (oki==1)
            {
                strcpy(password[t],p);
                oki=2;
            }
            else if (oki==2)
                strcpy(suma[t],p);
            p=strtok(NULL," ");
        }
    }

    fin.close();
}

void afisareReguli()
{

    system("CLS");

    cout<<"1. Blackjack may be played with one to eight decks of 52-card decks."<<endl<<endl;
    cout<<"2. Aces may be counted as 1 or 11 points, 2 to 9 according to pip value, and tens and face cards count as ten points."<<endl<<endl;
    cout<<"3. The value of a hand is the sum of the point values of the individual cards. Except, a blackjack is the highest hand, consisting of an ace and any 10-point card, and it outranks all other 21-point hands."<<endl<<endl;
    cout<<"4. After the players have bet, the dealer will give two cards to each player and two cards to himself."<<endl<<endl;
    cout<<"5. Play begins with the player to the dealer's left. The following are the choices available to the player:"<<endl<<endl;
    cout<<"              *Stand  : Player stands pat with his cards."<<endl<<endl;
    cout<<"              *Hit    : Player draws another card (and more if he wishes). If this card causes the player's total points to exceed 21 (known as breaking or busting) then he loses."<<endl<<endl;
    cout<<"              *Double : Player doubles his bet and gets one, and only one, more card."<<endl<<endl;
    cout<<"6. After each player has had his turn, the dealer will start drawing cards if possible. If the dealer has 16 or less, then he will draw another card."<<endl<<endl;
    cout<<"7. If the dealer goes over 21 points, then any player who didn't already bust will win."<<endl<<endl;
    cout<<"8. If the dealer does not bust, then the higher point total between the player and dealer will win."<<endl<<endl;
    cout<<endl;
    system("pause");



}

void afisareMainMenuFara()
{

    cout<<"1) Single-Player Mode"<<endl;
    cout<<"2) Multiplayer Mode"<<endl;
    cout<<"3) Create or Edit your account"<<endl;
    cout<<"4) Rules"<<endl;
    cout<<"5) Exit game"<<endl<<endl;
    cout<<"Choose your option: ";
}

void afisareMainMenuCu()
{
    cout<<"Please enter a valid number between 1 and 5"<<endl<<endl;

    cout<<"1) Single-Player Mode"<<endl;
    cout<<"2) Multiplayer Mode"<<endl;
    cout<<"3) Create or Edit your account"<<endl;
    cout<<"4) Rules"<<endl;
    cout<<"5) Exit game"<<endl<<endl;
    cout<<"Choose your option: "<<endl;
}

void setariCont(char username[100][30], char password[100][30], char suma[100][30], int &linie)
{
    cout<<"Choose your option:"<<endl<<endl;
    cout<<"1) Create a new account"<<endl;
    cout<<"2) Edit your existing account"<<endl<<endl;
    char choice1;
    cin>>choice1;
    while(choice1!='1'&&choice1!='2')
    {
        afisareCasino();
        cout<<"Please enter a valid number between 1 and 2"<<endl<<endl;
        cout<<"Choose your option:"<<endl<<endl;
        cout<<"1) Create a new account"<<endl;
        cout<<"2) Edit your existing account"<<endl<<endl;
        cin>>choice1;
    }
    if (choice1=='1')
        creareCont(username,password,suma,linie);
    if (choice1=='2')
    {
        afisareCasino();
        cout<<"Please enter your Username: ";
        char user2[31];
        cin>>user2;
        int oki111=0;
        int gasit111=0;
        for(int i=1; i<=linie-1; i++)
            if (verificareContUser(user2,username[i])==1)
            {
                oki111=1;
                gasit111=i;
            }
        cout<<"Please enter your Password: ";
        char pass2[30];
        cin>>pass2;
        int oki222=0;
        for(int i=1; i<=linie-1; i++)
            if (verificareContUser(pass2,password[i])==1)
                oki222=1;

        afisareCasino();
        cout<<"Validating information.";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);

        int gasitBun1=0;
        if (oki111==0 || oki222==0)
        {
            cout<<" Failed to initialize! Please try again or register a new account!";
            Sleep(2000);

        }
        else
        {
            gasitBun1=gasit111;
            afisareCasino();
            cout<<"1) Edit your username"<<endl;
            cout<<"2) Edit your password"<<endl;
            cout<<"3) Make a new deposit"<<endl<<endl;
            cout<<"Choose your option: ";

            char alegere;
            cin>>alegere;
            while(alegere!='1'&&alegere!='2'&&alegere!='3')
            {
                afisareCasino();
                cout<<"1) Edit your username"<<endl;
                cout<<"2) Edit your password"<<endl;
                cout<<"3) Make a new deposit"<<endl<<endl;
                cout<<"Please enter a valid number: ";
                cin>>alegere;
            }
            if (alegere=='1')
            {
                afisareCasino();
                cout<<"Please enter your new username: ";
                char newUser[30];
                cin>>newUser;
                strcpy(username[gasitBun1],newUser);
                ofstream fout("BazaDate.txt");
                for(int i=1; i<=linie-1; i++)
                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                fout.close();
            }
            if (alegere=='2')
            {
                afisareCasino();
                cout<<"Please enter your new password: ";
                char newUser[30];
                cin>>newUser;
                strcpy(password[gasitBun1],newUser);
                ofstream fout("BazaDate.txt");
                for(int i=1; i<=linie-1; i++)
                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                fout.close();
            }
            if (alegere=='3')
            {
                afisareCasino();
                cout<<"How much money would you like to add?: ";
                long newDeposit=0;
                cin>>newDeposit;
                char newDep[30];
                int newDeposit2=0;
                newDeposit2=atoi(suma[gasitBun1]);
                newDeposit2=newDeposit2+newDeposit;
                strcpy(suma[gasitBun1],itoa(newDeposit2,newDep,10));
                ofstream fout("BazaDate.txt");
                for(int i=1; i<=linie-1; i++)
                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                fout.close();
            }
        }

    }
}

void afisareStart()
{
    cout<<"    ____  _               _____ _  __    _         _____ _  __"<<endl;
    cout<<"   |  _ \\| |        /\\   / ____| |/ /   | |  /\\   / ____| |/ /"<<endl;
    cout<<"   | |_) | |       /  \\ | |    | ' /    | | /  \\ | |    | ' / "<<endl;
    cout<<"   |  _ <| |      / /\\ \\| |    |  < _   | |/ /\\ \\| |    |  <  "<<endl;
    cout<<"   | |_) | |____ / ____ | |____| . | |__| / ____ | |____| . \\ "<<endl;
    cout<<"   |____/|______/_/    \\_\\_____|_|\\_\\____/_/    \\_\\_____|_|\\_\\"<<endl;

}

void MainMenu()
{
    srand(time(NULL));


    ofstream fout("BazaDate.txt", ios::out | ios::app);
    cout<<endl;

    afisareStart();

    cout<<endl;
    system("pause");


    int linie;
    ifstream read("fisierNrLinii.txt");
    read>>linie;
    while(!exitGame)
    {

        char username[100][30], password[100][30], suma[100][30];

backToMainMenu:
        citireBazaDate(username,password,suma,linie);
        afisareCasino();
        afisareMainMenuFara();
        char choice;
        cin>>choice;
        while (choice!='1' && choice!='2' && choice!='3' && choice!='4' && choice!='5')
        {

            afisareCasino();
            afisareMainMenuCu();
            cin>>choice;
        }

        if (choice=='1')
        {
            afisareCasino();

            cout<<"In order to play, you need to sign in"<<endl;
            cout<<"Please enter your Username: ";


            char user[31];
            cin>>user;
            int oki1=0;
            int gasit=0;
            for(int i=1; i<=linie-1; i++)
                if (verificareContUser(user,username[i])==1)
                {
                    oki1=1;
                    gasit=i;
                }
            cout<<"Please enter your Password: ";
            char pass[30];
            cin>>pass;
            int oki2=0;
            for(int i=1; i<=linie-1; i++)
                if (verificareContUser(pass,password[i])==1)
                    oki2=1;

            afisareCasino();

            cout<<"Validating information.";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);

            int gasitBun=0;

            if (oki1==0 || oki2==0)
            {
                cout<<" Failed to initialize! Please try again or register a new account!";
                Sleep(2000);
                goto backToMainMenu;
            }
            else
            {
                gasitBun=gasit;

                long deposit=atoi(suma[gasitBun]);
                if (deposit==0)
                {
                    afisareCasino();
                    cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                    system("pause");
                    goto backToMainMenu;
                }
                afisareCasino();
                cout<<"Starting game.";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                char betChar[30];
                int playAgain=1;
                while(playAgain==1)
                {
                    afisareCasino();
                    cout<<"Please enter the amount of money that you want to bet (MAX "<<deposit<<") or press (q) to go back to the Main Menu: ";
                    cin>>betChar;
                    if (strcmp(betChar,"q")==0)
                        {
                            playAgain=0;
                            char dep[30];
                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                            ofstream fout("BazaDate.txt");
                            for(int i=1; i<=linie-1; i++)
                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                            fout.close();
                            goto backToMainMenu;
                        }
                    long bet;
                    bet=atoi(betChar);
                    if (bet<=0||bet>deposit)
                        while(bet<=0||bet>deposit)
                        {
                            afisareCasino();
                            cout<<"Invalid input! Please enter a number between 1 and "<<deposit<<endl<<endl;
                            cout<<"Please enter the amount of money that you want to bet (MAX "<<deposit<<") or press (q) to go back to the Main Menu: ";
                            cin>>betChar;
                            if (strcmp(betChar,"q")==0)
                                goto backToMainMenu;
                            bet=atoi(betChar);
                        }


                    int contorDealer=1, contorPlayer=1;
                    int vDealerCarti[20], vPlayerCarti[20];
                    int vDealerSimbol[20], vPlayerSimbol[20];

                    vDealerCarti[contorDealer]=rand()%13+2;
                    vDealerSimbol[contorDealer]=rand()%4+1;
                    contorDealer++;

                    vDealerCarti[contorDealer]=rand()%13+2;
                    vDealerSimbol[contorDealer]=rand()%4+1;
                    contorDealer++;

                    vPlayerCarti[contorPlayer]=rand()%13+2;
                    vPlayerSimbol[contorPlayer]=rand()%4+1;
                    contorPlayer++;

                    vPlayerCarti[contorPlayer]=rand()%13+2;
                    if(vPlayerCarti[contorPlayer]==vPlayerCarti[contorPlayer-1])
                        while(vPlayerCarti[contorPlayer]==vPlayerCarti[contorPlayer-1])
                            vPlayerCarti[contorPlayer]=rand()%13+2;
                    vPlayerSimbol[contorPlayer]=rand()%4+1;
                    contorPlayer++;

                    int isSplit=0;
                    if (vPlayerCarti[1]==vPlayerCarti[2])
                        isSplit=1;

                    int totalDealer=0,totalPlayer=0;
backToD:
                    afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                    afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);

                    if (totalDealer==21&&totalPlayer<21)
                    {
                        cout<<endl<<"You LOST"<<endl;
                        deposit=deposit-bet;
                        char s;
                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                        cin>>s;
                        if (s=='n')
                        {
                            playAgain=0;
                            char dep[30];
                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                            ofstream fout("BazaDate.txt");
                            for(int i=1; i<=linie-1; i++)
                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                            fout.close();
                        }
                        else if (deposit==0)
                        {
                            playAgain=0;
                            char dep[30];
                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                            ofstream fout("BazaDate.txt");
                            for(int i=1; i<=linie-1; i++)
                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                            fout.close();
                            afisareCasino();
                            cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                            system("pause");
                            goto backToMainMenu;
                        }
                    }
                    else if (totalPlayer==21&&totalDealer<21)
                    {
                        cout<<endl<<"You WON"<<endl;
                        deposit=deposit+bet;
                        char s;
                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                        cin>>s;
                        if (s=='n')
                        {
                            playAgain=0;
                            char dep[30];
                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                            ofstream fout("BazaDate.txt");
                            for(int i=1; i<=linie-1; i++)
                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                            fout.close();
                        }
                    }
                    else if (totalPlayer==21&&totalDealer==21)
                    {
                        cout<<endl<<"You DRAW"<<endl;
                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                        char s;
                        cin>>s;
                        if (s=='n')
                        {
                            playAgain=0;
                            char dep[30];
                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                            ofstream fout("BazaDate.txt");
                            for(int i=1; i<=linie-1; i++)
                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                            fout.close();
                        }
                    }
                    else if (isSplit==0)
                    {

                        cout<<"Please enter Hit(h), Stand(s) or Double(d): ";
                        char s;
                        cin>>s;
                        if (s=='h')
                        {
                            int da=1;
                            afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                            Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                            afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                            if (checkIfNotBust(totalPlayer)==0)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }
                                else if (deposit==0)
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                    afisareCasino();
                                    cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                    system("pause");
                                    goto backToMainMenu;
                                }

                                da=0;
                            }
                            else
                                while(checkIfNotBust(totalPlayer)==1&&da==1)
                                {
                                    cout<<"Please enter Hit(h) or Stand(s): ";
                                    cin>>s;
                                    if (s=='h')
                                    {
                                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                        Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                        if (checkIfNotBust(totalPlayer)==0)
                                        {
                                            cout<<endl<<"You LOST"<<endl;
                                            deposit=deposit-bet;
                                            cout<<"Do you want to play again? Yes(y) or No(n): ";
                                            cin>>s;
                                            if (s=='n')
                                            {
                                                playAgain=0;
                                                char dep[30];
                                                strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                ofstream fout("BazaDate.txt");
                                                for(int i=1; i<=linie-1; i++)
                                                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                fout.close();
                                            }
                                            else if (deposit==0)
                                            {
                                                playAgain=0;
                                                char dep[30];
                                                strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                ofstream fout("BazaDate.txt");
                                                for(int i=1; i<=linie-1; i++)
                                                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                fout.close();
                                                afisareCasino();
                                                cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                                system("pause");
                                                goto backToMainMenu;
                                            }
                                            da=0;
                                        }
                                    }
                                    if (s=='s')
                                    {
                                        da=0;
                                        if (totalDealer>totalPlayer)
                                        {
                                            cout<<endl<<"You LOST"<<endl;
                                            deposit=deposit-bet;
                                            cout<<"Do you want to play again? Yes(y) or No(n): ";
                                            cin>>s;
                                            if (s=='n')
                                            {
                                                playAgain=0;
                                                char dep[30];
                                                strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                ofstream fout("BazaDate.txt");
                                                for(int i=1; i<=linie-1; i++)
                                                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                fout.close();
                                            }
                                            else if (deposit==0)
                                            {
                                                playAgain=0;
                                                char dep[30];
                                                strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                ofstream fout("BazaDate.txt");
                                                for(int i=1; i<=linie-1; i++)
                                                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                fout.close();
                                                afisareCasino();
                                                cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                                system("pause");
                                                goto backToMainMenu;
                                            }
                                        }
                                        else
                                        {
                                            while(totalDealer<17)
                                            {
                                                afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                                afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                                Hit(vDealerCarti,vDealerSimbol,contorDealer);
                                                Sleep(1000);
                                            }
                                            if (totalDealer<totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You WON"<<endl;
                                                deposit=deposit+bet;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                }
                                            }
                                            if (totalDealer==totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You DRAW"<<endl;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                    playAgain=0;
                                            }
                                            if (totalDealer>totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You LOST"<<endl;
                                                deposit=deposit-bet;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                }
                                                else if (deposit==0)
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                    afisareCasino();
                                                    cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                                    system("pause");
                                                    goto backToMainMenu;
                                                }
                                            }
                                            if (checkIfNotBust(totalDealer)==0&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You WON"<<endl;
                                                deposit=deposit+bet;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                }
                                            }

                                        }
                                    }
                                }
                        }
                        else

                            if (s=='s')
                            {
                                if (totalDealer>totalPlayer)
                                {
                                    cout<<endl<<"You LOST"<<endl;
                                    deposit=deposit-bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                    else if (deposit==0)
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                        afisareCasino();
                                        cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                        system("pause");
                                        goto backToMainMenu;
                                    }
                                }
                                else
                                {
                                    while(totalDealer<17)
                                    {
                                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                        Hit(vDealerCarti,vDealerSimbol,contorDealer);
                                        Sleep(1000);
                                    }
                                    if (totalDealer<totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                    {
                                        cout<<endl<<"You WON"<<endl;
                                        deposit=deposit+bet;
                                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                                        cin>>s;
                                        if (s=='n')
                                        {
                                            playAgain=0;
                                            char dep[30];
                                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                            ofstream fout("BazaDate.txt");
                                            for(int i=1; i<=linie-1; i++)
                                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                            fout.close();
                                        }
                                    }
                                    if (totalDealer==totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                    {
                                        cout<<endl<<"You DRAW"<<endl;
                                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                                        cin>>s;
                                        if (s=='n')
                                            playAgain=0;
                                    }
                                    if (totalDealer>totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                    {
                                        cout<<endl<<"You LOST"<<endl;
                                        deposit=deposit-bet;
                                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                                        cin>>s;
                                        if (s=='n')
                                        {
                                            playAgain=0;
                                            char dep[30];
                                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                            ofstream fout("BazaDate.txt");
                                            for(int i=1; i<=linie-1; i++)
                                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                            fout.close();
                                        }
                                        else if (deposit==0)
                                        {
                                            playAgain=0;
                                            char dep[30];
                                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                            ofstream fout("BazaDate.txt");
                                            for(int i=1; i<=linie-1; i++)
                                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                            fout.close();
                                            afisareCasino();
                                            cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                            system("pause");
                                            goto backToMainMenu;
                                        }
                                    }
                                    if (checkIfNotBust(totalDealer)==0&&checkIfNotBust(totalPlayer)==1)
                                    {
                                        cout<<endl<<"You WON"<<endl;
                                        deposit=deposit+bet;
                                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                                        cin>>s;
                                        if (s=='n')
                                        {
                                            playAgain=0;
                                            char dep[30];
                                            strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                            ofstream fout("BazaDate.txt");
                                            for(int i=1; i<=linie-1; i++)
                                                fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                            fout.close();
                                        }
                                    }
                                }
                            }
                        if (s=='d')
                        {

                            if (deposit-2*bet<0)
                            {
                                cout<<"Not enough funds! Please select another option";
                                Sleep(2000);
                                goto backToD;
                            }
                            afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                            Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                            afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                            if (checkIfNotBust(totalPlayer)==0)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-2*bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }
                                else if (deposit==0)
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                    afisareCasino();
                                    cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                    system("pause");
                                    goto backToMainMenu;
                                }
                            }
                            else if (totalDealer>totalPlayer)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-2*bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }
                                else if (deposit==0)
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                    afisareCasino();
                                    cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                    system("pause");
                                    goto backToMainMenu;
                                }
                            }
                            else
                            {
                                while(totalDealer<17)
                                {
                                    afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                    afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                    Hit(vDealerCarti,vDealerSimbol,contorDealer);
                                    Sleep(1000);
                                }
                                if (checkIfNotBust(totalDealer)==0&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You WON"<<endl;
                                    deposit=deposit+2*bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }

                                if (totalDealer>totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You LOST"<<endl;
                                    deposit=deposit-2*bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                    else if (deposit==0)
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                        afisareCasino();
                                        cout<<"No more funds available! Please go back to the Main Menu and make a new deposit"<<endl<<endl;
                                        system("pause");
                                        goto backToMainMenu;
                                    }
                                }

                                if (totalDealer<totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You WON"<<endl;
                                    deposit=deposit+2*bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }

                                if (totalDealer==totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You DRAW"<<endl;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                        playAgain=0;
                                }

                            }
                        }

                    }
                    else
                    {
                        cout<<"Please enter Hit(h), Stand(s), Double(d) or Split(S): ";
                        char s;
                        cin>>s;
                        if (s=='h')
                        {
                            int da=1;
                            afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                            Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                            afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                            if (checkIfNotBust(totalPlayer)==0)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }

                                da=0;
                            }
                            else
                                while(checkIfNotBust(totalPlayer)==1&&da==1)
                                {
                                    cout<<"Please enter Hit(h) or Stand(s): ";
                                    cin>>s;
                                    if (s=='h')
                                    {
                                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                        Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                        if (checkIfNotBust(totalPlayer)==0)
                                        {
                                            cout<<endl<<"You LOST"<<endl;
                                            deposit=deposit-bet;
                                            cout<<"Do you want to play again? Yes(y) or No(n): ";
                                            cin>>s;
                                            if (s=='n')
                                            {
                                                playAgain=0;
                                                char dep[30];
                                                strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                ofstream fout("BazaDate.txt");
                                                for(int i=1; i<=linie-1; i++)
                                                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                fout.close();
                                            }
                                            da=0;
                                        }
                                    }
                                    if (s=='s')
                                    {
                                        da=0;
                                        if (totalDealer>totalPlayer)
                                        {
                                            cout<<endl<<"You LOST"<<endl;
                                            deposit=deposit-bet;
                                            cout<<"Do you want to play again? Yes(y) or No(n): ";
                                            cin>>s;
                                            if (s=='n')
                                            {
                                                playAgain=0;
                                                char dep[30];
                                                strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                ofstream fout("BazaDate.txt");
                                                for(int i=1; i<=linie-1; i++)
                                                    fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                fout.close();
                                            }
                                        }
                                        else
                                        {
                                            while(totalDealer<17)
                                            {
                                                afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                                afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                                Hit(vDealerCarti,vDealerSimbol,contorDealer);
                                                Sleep(1000);
                                            }
                                            if (totalDealer<totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You WON"<<endl;
                                                deposit=deposit+bet;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                }
                                            }
                                            if (totalDealer==totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"DRAW"<<endl;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                    playAgain=0;
                                            }
                                            if (totalDealer>totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You LOST"<<endl;
                                                deposit=deposit-bet;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                }
                                            }
                                            if (checkIfNotBust(totalDealer)==0&&checkIfNotBust(totalPlayer)==1)
                                            {
                                                cout<<endl<<"You WON"<<endl;
                                                deposit=deposit+bet;
                                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                {
                                                    playAgain=0;
                                                    char dep[30];
                                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                                    ofstream fout("BazaDate.txt");
                                                    for(int i=1; i<=linie-1; i++)
                                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                    fout.close();
                                                }
                                            }

                                        }
                                    }
                                }
                        }
                        else if (s=='s')
                        {
                            if (totalDealer>totalPlayer)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }
                            }
                            else
                            {
                                while(totalDealer<17)
                                {
                                    afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                    afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                    Hit(vDealerCarti,vDealerSimbol,contorDealer);
                                    Sleep(1000);
                                }
                                if (totalDealer<totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You WON"<<endl;
                                    deposit=deposit+bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }
                                if (totalDealer==totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"DRAW"<<endl;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                        playAgain=0;
                                }
                                if (totalDealer>totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You LOST"<<endl;
                                    deposit=deposit-bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }
                                if (checkIfNotBust(totalDealer)==0&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You WON"<<endl;
                                    deposit=deposit+bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }
                            }
                        }
                        else if (s=='d')
                        {
                            afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                            Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                            afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                            if (checkIfNotBust(totalPlayer)==0)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-2*bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }
                            }
                            else if (totalDealer>totalPlayer)
                            {
                                cout<<endl<<"You LOST"<<endl;
                                deposit=deposit-2*bet;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                cin>>s;
                                if (s=='n')
                                {
                                    playAgain=0;
                                    char dep[30];
                                    strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                    ofstream fout("BazaDate.txt");
                                    for(int i=1; i<=linie-1; i++)
                                        fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                    fout.close();
                                }
                            }
                            else
                            {
                                while(totalDealer<17)
                                {
                                    afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                    afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                    Hit(vDealerCarti,vDealerSimbol,contorDealer);
                                    Sleep(1000);
                                }
                                if (checkIfNotBust(totalDealer)==0&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You WON"<<endl;
                                    deposit=deposit+2*bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }

                                if (totalDealer>totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You LOST"<<endl;
                                    deposit=deposit-2*bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }

                                if (totalDealer<totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"You WON"<<endl;
                                    deposit=deposit+2*bet;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                    {
                                        playAgain=0;
                                        char dep[30];
                                        strcpy(suma[gasitBun],itoa(deposit,dep,10));
                                        ofstream fout("BazaDate.txt");
                                        for(int i=1; i<=linie-1; i++)
                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                        fout.close();
                                    }
                                }

                                if (totalDealer==totalPlayer&&checkIfNotBust(totalDealer)==1&&checkIfNotBust(totalPlayer)==1)
                                {
                                    cout<<endl<<"DRAW"<<endl;
                                    cout<<"Do you want to play again? Yes(y) or No(n): ";
                                    cin>>s;
                                    if (s=='n')
                                        playAgain=0;
                                }

                            }
                        }
                        else if (s=='S')
                        {
                            afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                            int v1PlayerC[30],v2PlayerC[30],v1PlayerS[30],v2PlayerS[30];
                            v1PlayerC[1]=vPlayerCarti[1];
                            v1PlayerS[1]=vPlayerSimbol[1];
                            v2PlayerC[1]=vPlayerCarti[2];
                            v2PlayerS[1]=vPlayerSimbol[2];
                            int v1contor=2, v2contor=2;
                            int treceLaAlDoilea=0;

                        }

                    }
                }
            }
        }
        if (choice=='2')
        {

            afisareCasino();
            cout<<"For Multiplayer, please purchase the Full Version of the game"<<endl<<endl;
            system("pause");
            ShellExecute(0, 0, "http://store.steampowered.com/app/436150/", 0, 0 , SW_SHOW );
            goto backToMainMenu;
        }
        if (choice=='3')
        {
            afisareCasino();
            setariCont(username,password,suma,linie);
            system("CLS");
            goto backToMainMenu;
        }
        if (choice=='4')
        {
            afisareReguli();
            goto backToMainMenu;
        }
        if (choice=='5')
        {
            cout<<endl<<"Exiting game in 3... ";
            Sleep(1000);
            cout<<"2... ";
            Sleep(1000);
            cout<<"1... ";
            Sleep(1000);
            exitGame=1;
            fout.close();
        }

    }
    read.close();
    ofstream write("fisierNrLinii.txt");
    write<<linie;
    write.close();
}



int main()
{
    MainMenu();
    system("CLS");
    return 0;
}
