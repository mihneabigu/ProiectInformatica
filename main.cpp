#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <cstring>
using namespace std;

void creareCont(char username[100][30],char password[100][30], char suma[100][30], int &linie)
{
    ofstream fout("BazaDate.txt", ios::out | ios::app);
    system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

    cout<<"Please enter your Username (between 1 and 30 characters): ";
    cin>>username[linie]; cout<<endl;
    cout<<"Please enter your Password (between 1 and 30 characters): "; cin>>password[linie]; cout<<endl;
    strcpy(suma[linie],"1000");
    fout<<username[linie]<<" "<<password[linie]<<" "<<suma[linie]<<endl;
    linie++;
    fout.close();
}

bool verificareContUser(char a[30], char b[30])
{
    if (strcmp(a,b)!=0)
        return 0;
    return 1;
}

bool checkIfBust(int a)
{
    if (a>21)
        return 0;
    return 1;
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

        for (int i=1;i<contor;i++)
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
            cout<<"A";
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
        else
            if (vCarti[i]==14)
                {
                    if (total+11<=21)
                        total=total+11;
                    else
                        total=total+1;
                }
                else
                    total=total+vCarti[i];
    }

    if (checkIfBust(total)==1)

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
        for (int i=1;i<contor;i++)
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
            cout<<"A";
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
        else
            if (vCarti[i]==14)
                {
                    if (total+11<=21)
                        total=total+11;
                    else
                        total=total+1;
                }
                else
                    total=total+vCarti[i];
    }

    if (checkIfBust(total)==1)

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

void MainMenu()
{
    srand(time(NULL));

    system("CLS");

        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;

    cout<<endl;
    cout<<"Choose your option:"<<endl;
    cout<<"1) Single-Player Mode"<<endl;
    cout<<"2) 2-Player Mode"<<endl;
    cout<<"3) Create or Edit your account"<<endl;
    int choice; cout<<endl;
    cin>>choice;
    while (choice!=1 && choice!=2 && choice!=3)
    {
        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;
        cout<<"Please enter a valid number between 1 and 3"<<endl<<endl;
        cout<<"Choose your option:"<<endl;
        cout<<"1) Single-Player Mode"<<endl;
        cout<<"2) 2-Player Mode"<<endl;
        cout<<"3) Create or Edit your account"<<endl<<endl;
        cin>>choice;
    }
    char username[100][30], password[100][30] , suma[100][30];
    int linie;
    ifstream read("fisierNrLinii.txt");

    read>>linie;


    ifstream fin("BazaDate.txt");
    int t;
    for(t=1;t<=linie-1;t++)
    {
        int oki=0;
        char a[61];
        fin.getline(a,60);
        char *p;
        p=strtok(a," ");
        while(p!=NULL)
        {
            if (oki==0)
            { strcpy(username[t],p); oki=1;}
            else
            if (oki==1)
            {
                strcpy(password[t],p);
                oki=2;
            }
            else
            if (oki==2)
                strcpy(suma[t],p);
            p=strtok(NULL," ");
        }
    }

    fin.close();

    if (choice==1)
    {
        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

        cout<<"In order to play, you need to sign in"<<endl;
        cout<<"Please enter your Username: ";


        char user[31];
        cin>>user;
        int oki1=0;
        int gasit=0;
        for(int i=1;i<=linie-1;i++)
            if (verificareContUser(user,username[i])==1)
                { oki1=1; gasit=i;}
        cout<<"Please enter your Password: ";
        char pass[30];
        cin>>pass;
        int oki2=0;
        for(int i=1;i<=linie-1;i++)
            if (verificareContUser(pass,password[i])==1)
                oki2=1;
        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

        cout<<"Validating information."; Sleep(1000);

        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

        cout<<"Validating information.."; Sleep(1000);

        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

        cout<<"Validating information..."; Sleep(1000);


        int gasitBun=0;

        if (oki1==0 || oki2==0)
            {cout<<" Failed to initialize! Please try again or register a new account!";
        Sleep(2000);
        MainMenu();}
        else
        {
            gasitBun=gasit;

        int deposit=atoi(suma[gasitBun]);




        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

        cout<<"Starting game."; Sleep(1000); cout<<"."; Sleep(1000); cout<<"."; Sleep(1000);



        int bet;
        int playAgain=1;
        while(playAgain==1)
        {
             system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

            cout<<"How much do you want to bet? (MAX "<<deposit<<"): "; cin>>bet;

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
            vPlayerSimbol[contorPlayer]=rand()%4+1;
            contorPlayer++;

            int isSplit=0;
            if (vPlayerCarti[1]==vPlayerCarti[2])
                isSplit=1;

            int totalDealer=0,totalPlayer=0;
            afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
            afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
            if (isSplit==0)
            {

                cout<<"Please enter Hit(h), Stand(s) or Double(d): ";
                char s; cin>>s;
                if (s=='h')
                    {
                        int da=1;
                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                        Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                        if (checkIfBust(totalPlayer)==0)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }

                                                da=0;
                        }
                        else
                        while(checkIfBust(totalPlayer)==1&&da==1)
                            {
                                cout<<"Please enter Hit(h) or Stand(s): ";
                                cin>>s;
                                if (s=='h')
                                    {
                                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                        Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                        if (checkIfBust(totalPlayer)==0)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                                                if (totalDealer<totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (totalDealer==totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
                            {
                                cout<<endl<<"DRAW"<<endl;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                        playAgain=0;
                            }
                        if (totalDealer>totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (checkIfBust(totalDealer)==0&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                        if (totalDealer<totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (totalDealer==totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
                            {
                                cout<<endl<<"DRAW"<<endl;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                    playAgain=0;
                            }
                        if (totalDealer>totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (checkIfBust(totalDealer)==0&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
            }}
        if (s=='d')
            {
                afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                if (checkIfBust(totalPlayer)==0)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                }
                else
                if (totalDealer>totalPlayer)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                    if (checkIfBust(totalDealer)==0&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                    }

                    if (totalDealer>totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                    }

                    if (totalDealer<totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                    }

                    if (totalDealer==totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
                    {
                        cout<<endl<<"DRAW"<<endl;
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
        char s; cin>>s;
        if (s=='h')
            {
                        int da=1;
                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                        Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                        if (checkIfBust(totalPlayer)==0)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }

                                                da=0;
                        }
                        else
                        while(checkIfBust(totalPlayer)==1&&da==1)
                            {
                                cout<<"Please enter Hit(h) or Stand(s): ";
                                cin>>s;
                                if (s=='h')
                                    {
                                        afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                                        Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                                        afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                                        if (checkIfBust(totalPlayer)==0)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                                                if (totalDealer<totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (totalDealer==totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
                            {
                                cout<<endl<<"DRAW"<<endl;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                        playAgain=0;
                            }
                        if (totalDealer>totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (checkIfBust(totalDealer)==0&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                        if (totalDealer<totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (totalDealer==totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
                            {
                                cout<<endl<<"DRAW"<<endl;
                                cout<<"Do you want to play again? Yes(y) or No(n): ";
                                                cin>>s;
                                                if (s=='n')
                                                    playAgain=0;
                            }
                        if (totalDealer>totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
                        if (checkIfBust(totalDealer)==0&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                            }
            }}
        if (s=='d')
            {
                afisareDealer(vDealerCarti,vDealerSimbol,totalDealer,contorDealer);
                Hit(vPlayerCarti,vPlayerSimbol,contorPlayer);
                afisarePlayer(vPlayerCarti,vPlayerSimbol,totalPlayer,contorPlayer);
                if (checkIfBust(totalPlayer)==0)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                }
                else
                if (totalDealer>totalPlayer)
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
                                                        for(int i=1;i<=linie-1;i++)
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
                    if (checkIfBust(totalDealer)==0&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                    }

                    if (totalDealer>totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                    }

                    if (totalDealer<totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
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
                                                        for(int i=1;i<=linie-1;i++)
                                                            fout<<username[i]<<" "<<password[i]<<" "<<suma[i]<<endl;
                                                        fout.close();
                                                    }
                    }

                    if (totalDealer==totalPlayer&&checkIfBust(totalDealer)==1&&checkIfBust(totalPlayer)==1)
                    {
                        cout<<endl<<"DRAW"<<endl;
                        cout<<"Do you want to play again? Yes(y) or No(n): ";
                        cin>>s;
                        if (s=='n')
                            playAgain=0;
                    }

                }
            }
        if (s=='S')
            {//Split();
            }

    }
    }}}
    if (choice==2)
    {

    }
    if (choice==3)
    {
        system("CLS");
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$    Casino Games - BLACK JACK    $"<<endl;
        cout<<"$                                 $"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

        cout<<"Choose your option:"<<endl;
        cout<<"1) Create a new account"<<endl;
        cout<<"2) Edit your existing account"<<endl<<endl;
        int choice1;
        cin>>choice1;
        if (choice1==1)
            creareCont(username,password,suma,linie);
        system("CLS");
        MainMenu();
    }
    read.close();
    ofstream write("fisierNrLinii.txt");
    write<<linie;
    write.close();


}


int main()
{

    MainMenu();
    /*fstream file("accounts.txt", ios::out | ios::app);
    file<<user<<" "<<pass<<" "<<sum<<endl;
    file.close();*/
    int login=0;



    return 0;
}
