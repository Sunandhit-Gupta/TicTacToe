#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

string x, y;
char vales[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token;
int index;


void dTurn();
void display();
void player1();
void player2();
bool checkWin();
bool checkDraw();
bool change();


bool checkDraw(){
    for(int i=0; i<3; i++){
        for( int j=0; j<3; j++){
            if(vales[i][j] != 'X' && vales[i][j] != '0'){
                return false;
            }
        }
    }
    return true;
}

bool checkWin(){
    if(vales[0][0]== vales[0][1] && vales[0][0] == vales[0][2] || vales[0][0]== vales[1][0] && vales[0][0] == vales[2][0] || vales[2][0] == vales[2][1] && vales[2][0] == vales[2][2] || vales[0][2]== vales[1][2] && vales[0][2] == vales[2][2] || vales[0][0]== vales[1][1] && vales[0][0] == vales[2][2] || vales[0][2]== vales[1][1] && vales[0][2] == vales[2][0]){
        return true;
    }else{
        return false;
    }
}
bool change()
{
    if (index == 1)
    {
        //.............. checking whether index is already occupied or not ............
        if(vales[0][0]== 'X'|| vales[0][0] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        // ----------------------------changing table--------------------------
       vales[0][0] = token;

    }else if(index == 2){
        if(vales[0][1]== 'X'|| vales[0][1] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[0][1] = token;
    }else if(index == 3){
        if(vales[0][2]== 'X'|| vales[0][2] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[0][2] = token;
    }else if(index == 4){
        if(vales[1][0]== 'X'|| vales[1][0] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[1][0] = token;
    }else if(index == 5){
        if(vales[1][1]== 'X'|| vales[1][1] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[1][1] = token;
    }else if(index == 6){
        if(vales[1][2]== 'X'|| vales[1][2] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[1][2] = token;
    }else if(index == 7){
        if(vales[2][0]== 'X'|| vales[2][0] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[2][0] = token;
    }else if(index == 8){
        if(vales[2][1]== 'X'|| vales[2][1] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[2][1] = token;
    }else if(index == 9){
        if(vales[2][2]== 'X'|| vales[2][2] == '0'){
            cout<<" Already Ocuppied !!!"<<endl;
            return false;
        }
        vales[2][2] = token;
    }else{
        cout<<" Index is Invalid !!!"<<endl;
        return false;
    }
    return true;
}

void player2()
{
    
    display();
    cout << y << " Enter No: ";
    cin >> index;
    cout<<endl;

    if(!change()){
        player2();
    };

    token = 'X';

    if(checkWin()){
        display();
        cout<<y<< " WINS!";
        Sleep(5000);
        return;
    };
    if(checkDraw()){
        display();
        cout<<"!!! GAME DRAW !!!";
        Sleep(5000);
        return;
    };
    player1();
}

void player1(){

    display();
    cout << x << " Enter No: ";
    cin >> index;
    cout<<endl;
    if(!change()){
        player1();
    };
    token = '0';

    if(checkWin()){
        display();
        cout<<x<< " WINS!";
        Sleep(5000);
        return;
    };
    if(checkDraw()){
        display();
        cout<<"!!! GAME DRAW !!!";
        Sleep(5000);
        return;
    };
    player2();

}


void playerNames(){
    cout << "Enter player 1 name: ";
    cin >> x;
    cout << endl
         << "Enter player 2 name: ";
    cin >> y;

    dTurn();
}
void display()
{

    cout << "    |     |    " << endl;
    cout << vales[0][0] << "   |  " << vales[0][1] << "  |    " << vales[0][2] << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << vales[1][0] << "   |  " << vales[1][1] << "  |    " << vales[1][2] << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << vales[2][0] << "   |  " << vales[2][1] << "  |    " << vales[2][2] << endl;
    cout << "    |     |    " << endl;

    
}

void dTurn(){

    // --------------Generating random first turn selector ----------------
    const long long int turn = rand() ;

    if (turn % 2 == 0)
    {
        cout << y << " will play first" << endl;
        token = '0';
        player2();
    }
    else
    {
        cout << x << " will play first" << endl;
        token = 'X';
        
        player1();
    }

}


int main()
{
    srand(time(0));
    playerNames();

    return 0;
}