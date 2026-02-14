#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

class Data{
    string time[3];
    int N_table[5];
    string name[15];
};

int main(){
    // Data Customer = {{"10:00-12:00","13:00-15:00","16:00-18:00"},{1,2,3,4,5},"Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply"};
    string Nickname;
    int N_time;
    int Table;
    const string time[] = {"10:00-12:00","13:00-15:00","16:00-18:00"};
    const int N_table[] = {1,2,3,4,5};
    int N1 = sizeof(N_table)/sizeof(N_table[0]);
    int N2 = sizeof(time)/sizeof(time[0]);
    
    cout << setw(12) << "Time/Table";
    for(int i = 0;i < N1; i++){
        if(i == 0) cout << setw(8) << N_table[i];
        if(i > 0) cout << setw(10) << N_table[i];
    }
    cout << "\n--------------|---------|---------|---------|---------|---------|\n";
    for(int j = 0;j < N2; j++){
        cout << setw(12) << time[j];
        for(int k = 0; k < N1;k++){
            cout << setw(10) << "Emply";
        }
        cout << "\n--------------|---------|---------|---------|---------|---------|\n";
    }
    cout << "*****************************************************************\n";
    for(int k = 0; k < N2; k++){
        cout << "Choose Time " << time[k] << " -> Print " << k+1 << "\n";
    }
    cout << "*****************************************************************\n";
    cout << "[Choose Time] : ";
    cin >> N_time;
    cout << "[Choose Table] : ";
    cin >> Table;
    cout << "[Nickname] :";
    cin >> Nickname;
}