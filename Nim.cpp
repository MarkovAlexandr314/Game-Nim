#include <iostream>
#include "std_lib_facilities.h"
using namespace std;
#include <vector> 
void invitation(){
    cout<<"Enter your move in the number row format\n"<<
        "\t1 to start the game\n" <<
        "\tor enter 0 to exit the game;\n" <<
        "\t-1 for game settings\n";
    cout<<"Select option: ";
}
void position(vector<int> v){//вывод текущей позиции
    int w{1};
    for (auto i:v){
        cout<<w<<"\t";
        for (auto j=0; j<i;++j){
            cout<<"*";
        }
        cout<<"\n";
        ++w;
    }
}
int nimsum(vector<int> e){//вычисление ним-суммы
    int nsum{e[0]};
    for (int i{1}; i<e.size(); ++i){
        nsum=(nsum^e[i]);
    }
    return nsum;
}
vector<int> bot(vector<int> w){//бот
    vector<int> r=w;
    if (nimsum(r)!=0){
        for (int i{0}; i<r.size();++i){
            r=w;
            while(r[i]!=0){
                --r[i];
                if (nimsum(r)==0){
                    break;
                }
            }
            if (nimsum(r)==0){
                break;
            }
        }
        
    }
    else{
        for (int i{0}; i<r.size();++i){
            if (r[i]!=0){
                --r[i];
                break;
            }
        }
        
    }
    return r;
}
void prov(vector<int> t, int ch, int ch1){
    for (int j=0;j<t.size();++j){
                ch+=t[j];
            }
            if (ch==0){
                if ((ch1%2)==0){
                    cout<<"You lose(((\n";
                    
                }
                else{
                    cout<<"You win!!!\n";
                }
            }
}
int main(){
    int ryd{0};//ряд, откуда убирать
    int kol{0};//кол-во убираемых карт
    int move{0};//первый ход
    int row{0};//изменяемый ряд
    char symbol;//как изменить
    int num{0};//на сколько изменить
    int sum{1};//сумма элементов вектора
    int win{0};//кто победит
    int sum1{0};
    vector<int> q={3,4,5};//начальные настройки игры
    cout << "\tGAME NIM"<<endl;
    cout << "Row" << endl;
    position(q);
    
    while((move==0)||(move==1)||(move==-1)){
    invitation();
    cin>>move;
    switch (move)
    {
    case 1://старт игры
        while (sum!=0){
            sum=0;
            for (int j=0;j<q.size();++j){
                sum+=q[j];
            }
            if (sum==0){
                break;
            }
            cout<<"Enter row and quantity: ";
            cin>>ryd>>kol;
            ++win;
            q[ryd-1]-=kol;
            cout<<"Position after your move:\n";
            prov(q,sum,win);
            position(q);
            cout<<"Position after the bot's move:\n";
            q=bot(q);
            ++win;
            sum1=0;
            position(q);
            prov(q,sum1,win);
        }
        break;
    case 0://выход из игры
        break;
    case -1://настройка игры
        cout<<"Enter, separated by a space: row number, add (+) or remove (-), number of cards.\n";
        cin>>row>>symbol>>num;
        switch (symbol)
        {
        case '+'://добаление карт
            for (int p=0;p<num; ++p){
                ++q[row-1];
            }
            position(q);
            break;
        case '-'://вычитаение карт
            for (int p=0;p<num; ++p){
                --q[row-1];
            }
            position(q);
            break;
        default:
        error("Debil");
            break;
        }
    default:
        break;
    }
    }
    keep_window_open();
}