#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>

#define BlueOnBlack 1       // player 1
#define RedOnBlack 4        // player 2
#define OrangeOnBlack 6     // win
#define LightRedOnBlack 12
#define AquaOnBlack 11      // table
#define BlueSelect 144      // select player 1
#define RedSelect 192       // select player 2
#define WhiteOnBlack 15

using namespace std;

void AfisareToateAscii()
{
    char s;
    for(int i=0; i<=255;++i)
    {
        s=i;
        cout<<i<<": "<<s<<endl;
    }
}

void DesignTabla()
{
    char s=219; /// █
    for(short int i=0;i<19;++i)
        cout<<s;
    cout<<endl;
    for(short int i=0;i<3;++i)
    {
        cout<<s<<"     "<<s<<"     "<<s<<"     "<<s<<endl;
    }
    for(short int i=0;i<19;++i)
        cout<<s;
    cout<<endl;
    for(short int i=0;i<3;++i)
    {
        cout<<s<<"     "<<s<<"     "<<s<<"     "<<s<<endl;
    }
    for(short int i=0;i<19;++i)
        cout<<s;
    cout<<endl;
    for(short int i=0;i<3;++i)
    {
        cout<<s<<"     "<<s<<"     "<<s<<"     "<<s<<endl;
    }
    for(short int i=0;i<19;++i)
        cout<<s;
    cout<<endl;
}

void DesignX()
{
    char a=220; /// ▄
    char b=223; /// ▀
    char c=219; /// █
    cout<<a<<" "<<a<<endl;
    cout<<" "<<c<<endl;
    cout<<b<<" "<<b<<endl;
}

void Design0()
{
    char a=220; /// ▄
    char b=223; /// ▀
    char c=219; /// █
    cout<<" "<<a<<endl;
    cout<<c<<" "<<c<<endl;
    cout<<" "<<b<<endl;
}

void Color(const long long &a) /// a=reprezinta un numar pt o anumita culoare a e pana la 255
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, a);
}

class Player
{
    string name;
    long long score=0;
public:
    Player()=default;
    ~Player()=default;

    void IncreaseScore()
    {
        score++;
    }

    void ShowName()
    {
        cout<<name<<endl;
    }

    void ShowScore()
    {
        cout<<name;
        Color(WhiteOnBlack);
        cout<<": ";
        Color(OrangeOnBlack);
        cout<<score;
        Color(10);
        cout<<" Wins"<<endl;
    }

    string GetName()
    {
        return name;
    }

    friend istream&operator>>(istream&,Player&);

};

istream&operator>>(istream&is,Player&n)
{
    is>>n.name;
    return is;
}

void ShowLine(const char &a)
{
    for(short int i=0;i<19;++i)
        cout<<a;
    cout<<endl;
}

void ShowX_Top(const char &a, const char &b, const bool &OT)
{
    if(OT)
    {
        Color(BlueOnBlack);
        cout<<b<<" "<<b<<" ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
    else
    {
        Color(BlueOnBlack);
        cout<<" "<<b<<"  ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
}

void Show0_Top(const char &a, const char &b, const bool &OT)
{
    if(OT)
    {
        Color(RedOnBlack);
        cout<<" "<<b<<"  ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
    else
    {
        Color(RedOnBlack);
        cout<<b<<" "<<b<<" ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
}

void ShowFirstLineSquare(const short int &x, const short int &y, const short int &z,const char &a, const char &b, const bool &OT)
{
    cout<<a<<" ";
    if(x==1) /// X = 1
    {
        ShowX_Top(a,b,OT);
    }
    else if(x==2) /// 0
    {
        Show0_Top(a,b,OT);
    }
    else
    {
        cout<<"    "<<a<<" ";
    }
  //  cout<<a<<" ";
    if(y==1) /// X = 1
    {
        ShowX_Top(a,b,OT);
    }
    else if(y==2) /// 0
    {
        Show0_Top(a,b,OT);
    }
    else
    {
        cout<<"    "<<a<<" ";
    }
 //   cout<<a<<" ";
    if(z==1) /// X = 1
    {
        ShowX_Top(a,b,OT);
        cout<<endl;
    }
    else if(z==2) /// 0
    {
        Show0_Top(a,b,OT);
        cout<<endl;
    }
    else
    {
        cout<<"    "<<a<<endl;
    }
}

void ShowX_Middle(const char &a, const bool &OT)
{
    if(OT)
    {
        Color(BlueOnBlack);
        cout<<" "<<a<<"  ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
    else
    {
        Color(BlueOnBlack);
        cout<<a<<" "<<a<<" ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
}

void Show0_Middle(const char &a, const bool &OT)
{
    if(OT)
    {
        Color(RedOnBlack);
        cout<<a<<" "<<a<<" ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
    else
    {
        Color(RedOnBlack);
        cout<<" "<<a<<"  ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
}

void ShowMiddleLineSquare(const short int &x, const short int &y, const short int &z,const char &a, const bool &OT)
{
    cout<<a<<" ";
    if(x==1) /// X = 1
    {
        ShowX_Middle(a,OT);
    }
    else if(x==2) /// 0
    {
        Show0_Middle(a,OT);
    }
    else
    {
        cout<<"    "<<a<<" ";
    }
    //cout<<a<<" ";
    if(y==1) /// X = 1
    {
        ShowX_Middle(a,OT);
    }
    else if(y==2) /// 0
    {
        Show0_Middle(a,OT);
    }
    else
    {
        cout<<"    "<<a<<" ";
    }
    //cout<<a<<" ";
    if(z==1) /// X = 1
    {
        ShowX_Middle(a,OT);
        cout<<endl;
    }
    else if(z==2) /// 0
    {
        Show0_Middle(a,OT);
        cout<<endl;
    }
    else
    {
        cout<<"    "<<a<<endl;
    }
}

void ShowX_Buttom(const char &a, const char &c, const bool &OT)
{
    if(OT)
    {
        Color(BlueOnBlack);
        cout<<c<<" "<<c<<" ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
    else
    {
        Color(BlueOnBlack);
        cout<<" "<<c<<"  ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
}

void Show0_Buttom(const char &a, const char &c, const bool &OT)
{
    if(OT)
    {
        Color(RedOnBlack);
        cout<<" "<<c<<"  ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
    else
    {
        Color(RedOnBlack);
        cout<<c<<" "<<c<<" ";
        Color(AquaOnBlack);
        cout<<a<<" ";
    }
}

void ShowButtomLineSquare(const short int &x, const short int &y, const short int &z,const char &a, const char &c, const bool &OT)
{
    cout<<a<<" ";
    if(x==1) /// X = 1
    {
        ShowX_Buttom(a,c,OT);
    }
    else if(x==2) /// 0
    {
        Show0_Buttom(a,c,OT);
    }
    else
    {
        cout<<"    "<<a<<" ";
    }
    //cout<<a<<" ";
    if(y==1) /// X = 1
    {
        ShowX_Buttom(a,c,OT);
    }
    else if(y==2) /// 0
    {
        Show0_Buttom(a,c,OT);
    }
    else
    {
        cout<<"    "<<a<<" ";
    }
    //cout<<a<<" ";
    if(z==1) /// X = 1
    {
        ShowX_Buttom(a,c,OT);
        cout<<endl;
    }
    else if(z==2) /// 0
    {
        Show0_Buttom(a,c,OT);
        cout<<endl;
    }
    else
    {
        cout<<"    "<<a<<endl;
    }
}

class TicTacToe
{
    ///bool clr; //true=blue , falsse red
    short int VectorTable[9]={0};
public:
    TicTacToe()=default;
    ~TicTacToe()=default;

    short int VerifyWin() // 1/2=cnv castiga, 0=nimeni nu castiga
    {
        ///c1
        if(VectorTable[0]==VectorTable[1] && VectorTable[1]==VectorTable[2])
        {
            if(VectorTable[0])
            {
                return VectorTable[0];
            }
        }
        ///c2
        if(VectorTable[3]==VectorTable[4] && VectorTable[4]==VectorTable[5])
        {
            if(VectorTable[3])
            {
                return VectorTable[3];
            }
        }
        ///c3
        if(VectorTable[6]==VectorTable[7] && VectorTable[7]==VectorTable[8])
        {
            if(VectorTable[7])
            {
                return VectorTable[7];
            }
        }
        ///c4
        if(VectorTable[0]==VectorTable[3] && VectorTable[3]==VectorTable[6])
        {
            if(VectorTable[0])
            {
                return VectorTable[0];
            }
        }
        ///c5
        if(VectorTable[1]==VectorTable[4] && VectorTable[4]==VectorTable[7])
        {
            if(VectorTable[1])
            {
                return VectorTable[1];
            }
        }
        ///c6
        if(VectorTable[2]==VectorTable[5] && VectorTable[5]==VectorTable[8])
        {
            if(VectorTable[2])
            {
                return VectorTable[2];
            }
        }
        ///c7
        if(VectorTable[0]==VectorTable[4] && VectorTable[4]==VectorTable[8])
        {
            if(VectorTable[0])
            {
                return VectorTable[0];
            }
        }
        ///c8
        if(VectorTable[2]==VectorTable[4] && VectorTable[4]==VectorTable[6])
        {
            if(VectorTable[2])
            {
                return VectorTable[2];
            }
        }
        return 0;
    }

    void ShowTable(const bool &OT)
    {
        /*
        for(short int i=0;i<9;++i)
        {
            if(i==3 || i==6)
                cout<<endl;
            cout<<VectorTable[i]<<" ";
        }
        cout<<endl;
        */

        /*
        if(OT)
        {
            /// x=Blue , 0=Red
        }
        else
        {
            /// x=Red , 0=Blue
        }
        */

        char a=219;     /// █
        char b=220;     /// ▄
        char c=223;     /// ▀

        ShowLine(a);
        ShowFirstLineSquare(VectorTable[0],VectorTable[1],VectorTable[2],a,b,OT);
        ShowMiddleLineSquare(VectorTable[0],VectorTable[1],VectorTable[2],a,OT);
        ShowButtomLineSquare(VectorTable[0],VectorTable[1],VectorTable[2],a,c,OT);

        ShowLine(a);
        ShowFirstLineSquare(VectorTable[3],VectorTable[4],VectorTable[5],a,b,OT);
        ShowMiddleLineSquare(VectorTable[3],VectorTable[4],VectorTable[5],a,OT);
        ShowButtomLineSquare(VectorTable[3],VectorTable[4],VectorTable[5],a,c,OT);

        ShowLine(a);
        ShowFirstLineSquare(VectorTable[6],VectorTable[7],VectorTable[8],a,b,OT);
        ShowMiddleLineSquare(VectorTable[6],VectorTable[7],VectorTable[8],a,OT);
        ShowButtomLineSquare(VectorTable[6],VectorTable[7],VectorTable[8],a,c,OT);

        ShowLine(a);
    }

    bool VerifyMoves() /// true=mai avem mutari, false=nu mai avem mutari
    {
        for(short int i=0;i<9;++i)
            if(VectorTable[i]==0)
                return true;
        return false;
    }

    bool VerifyClaim(const short int &n)
    {
        if(VectorTable[n]==0)
            return true;
        return false;
    }

    void SetPosition(const short int &n, const bool &OT)
    {
        if(OT)
        {
            VectorTable[n]=1;
        }
        else
        {
            VectorTable[n]=2;
        }
    }

    void GameReset()
    {
        for(short int i=0;i<9;++i)
            VectorTable[i]=0;
    }
};

void Interface(TicTacToe &Table, Player &One, Player &Two, const bool &OT)
{
    system("cls");
    Color(BlueOnBlack);
    One.ShowScore();
    Color(RedOnBlack);
    Two.ShowScore();
    Color(AquaOnBlack);
    Table.ShowTable(OT);
}

void NavigationRead()
{

}

void PlayingGame(TicTacToe Table, Player &One, Player &Two, bool &OT)
{
    bool Ox=OT;
    ///Interface(Table,One,Two,Ox);

    //short int contor=0;
    for(short int z=0;z<9;++z)
    {
        Interface(Table,One,Two,Ox);
        short int n;
        while(true)
        {
            if(OT)
            {
                Color(BlueOnBlack);
                cout<<One.GetName()<<"'s";
                Color(WhiteOnBlack);
                cout<<" turn:"<<endl;
            }
            else
            {
                Color(RedOnBlack);
                cout<<Two.GetName()<<"'s";
                Color(WhiteOnBlack);
                cout<<" turn:"<<endl;
            }

            ///Interface(Table,One,Two,Ox);
            //aici nu apare al cui e randu
            cin>>n;
            ///Interface(Table,One,Two,Ox);
            if(n<=8 && Table.VerifyClaim(n))
                break;

            Interface(Table,One,Two,Ox);

            Color(LightRedOnBlack);
            cout<<"This spot is taken! Put it somewhere else!"<<endl;
        }
        Table.SetPosition(n,OT);


        if(OT)
            OT=false;
        else if(OT==false)
            OT=true;

        Interface(Table,One,Two,Ox);

        if(Table.VerifyWin())
            break;
    }

    if(Table.VerifyWin()==1)
        One.IncreaseScore();
    else if(Table.VerifyWin()==2)
        Two.IncreaseScore();

    Interface(Table,One,Two,Ox);


    //Table.ShowTable();
    if(Table.VerifyWin()==0)
    {
        Color(LightRedOnBlack);
        cout<<"Draw!"<<endl;
        Color(WhiteOnBlack);
        cout<<"PRESS ANY KEY TO CONTINUE THE GAME!"<<endl;
        if(OT)
            OT=false;
        else if(OT==false)
            OT=true;
    }
    else if(Table.VerifyWin()==1)
    {
   //     One.IncreaseScore();
        Color(BlueOnBlack);
        cout<<One.GetName();
        Color(OrangeOnBlack);
        cout<<" Won!"<<endl;
        Color(WhiteOnBlack);
        cout<<"PRESS ANY KEY TO CONTINUE THE GAME!"<<endl;
        OT=true;
    }
    else
    {
       // Two.IncreaseScore();
        Color(RedOnBlack);
        cout<<Two.GetName();
        Color(OrangeOnBlack);
        cout<<" Won!"<<endl;
        Color(WhiteOnBlack);
        cout<<"PRESS ANY KEY TO CONTINUE THE GAME!"<<endl;
        OT=false;
    }
    Table.GameReset();
    _getch();
}

/// cin.get(a); merge pentru citire enter
// char b='\n'; b=(tasta)enter pt STD
/// a=_getch(); citeste o tasta fara sa apasam noi enter
// char b=13; b=(tasta)enter pt conio.h

int main()
{


    TicTacToe Table;
    Player One,Two;
    bool OT=true; /// true=One, false=Two

    cout<<"Enter the name of the first player:"<<endl;
    Color(BlueOnBlack);
    cin>>One;
    system("cls"); /// clear la consola
    Color(WhiteOnBlack);
    cout<<"Enter the name of the second player:"<<endl;

    while(true)
    {
        Color(RedOnBlack);
        cin>>Two;
        if(Two.GetName()!=One.GetName())
            break;
        else
        {
            Color(WhiteOnBlack);
            cout<<"Players cannot have the same name! Please enter another name!"<<endl;
        }
    }

    while(true)
    {
        PlayingGame(Table,One,Two,OT);
    }







    return 0;
}
