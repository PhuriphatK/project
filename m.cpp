#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

// class Data{
//     string time[3];
//     int N_table[5];
//     string name[15];
// };

void showData(vector<string> a,string b[],int N, int M){
    for(int i = 0; i < N*M; i++){
        if(i == 0) cout << setw(12) <<b[i];
        cout << setw(10);
        cout << a[i];
        if(i == 14) break;
        if((i+1) % M == 0){ 
            cout << endl ;
            cout << "--------------|---------|---------|---------|---------|---------|\n";
            cout << setw(12) <<b[(i+1)/M];
        }
    }
}

void updatefile(vector<string> status){
   ofstream new_data;
   new_data.open("");
   for(int i = 0; i < status.size(); i++){
      new_data << status[i] << "\n";
   }
   new_data.close();
}

void Check(vector<string> &a,string b,int c,int d){
    if(c == 1 && a[d-1] == "Emply"){
        a[d-1] = b;
    }else if(c == 2 && a[d+4] == "Emply"){
        a[d+4] = b;
    }else if(a[d+9] == "Emply"){
        a[d+9] = b;
    }   
}

int main(){
    // Data Customer = {{"10:00-12:00","13:00-15:00","16:00-18:00"},{1,2,3,4,5},"Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply","Emply"};
    string Nickname;
    int N_time;
    int Table;
    string time[] = {"10:00-12:00","13:00-15:00","16:00-18:00"};
    int N_table[] = {1,2,3,4,5};
    int N1 = sizeof(time)/sizeof(time[0]);
    int N2 = sizeof(N_table)/sizeof(N_table[0]);
    vector<string> status(N1*N2);

    ifstream source;
    source.open("status table.txt"); //เปิดไฟล์ที่จะอ่าน 
    string texline;
    int number = 0;
    while(getline(source,texline)){
        status[number] = texline;
        number++;
    }
    source.close(); //ปิดไฟล์ที่อ่าน
    
    cout << setw(12) << "Time/Table";
    for(int i = 0;i < N2; i++){
        if(i == 0) cout << setw(8) << N_table[i];
        if(i > 0) cout << setw(10) << N_table[i];
    }
    cout << "\n--------------|---------|---------|---------|---------|---------|\n";
    showData(status,time,N1,N2);
    cout << "\n--------------|---------|---------|---------|---------|---------|\n";
    cout << "*****************************************************************\n";
    for(int k = 0; k < N1; k++){
        cout << "Choose Time " << time[k] << " -> Enter " << k+1 << "\n";
    }
    cout << "*****************************************************************\n";
    cout << "[Choose Time] : ";
    cin >> N_time;
    cout << "[Choose Table] : ";
    cin >> Table;
    cout << "Please write your nickname no more 5 characters\n";
    cout << "[Nickname] :";
    cin >> Nickname;
    
    bool x = Check(status,Nickname,N_time,Table);
    while(x == false){
        cout << "Sorry,These is a table that has already booked. Plaese make a new reservation\n";
        cout << "*****************************************************************\n";
        cout << "[Choose Time] : ";
        cin >> N_time;
        cout << "[Choose Table] : ";
        cin >> Table;
        x = Check(status,Nickname,N_time,Table);
    }
    cout << status[1];
}