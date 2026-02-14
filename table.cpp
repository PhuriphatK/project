#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void showData(vector<string> a, int N, int M){
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1) % M == 0) cout << endl;
        else cout << " ";
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

 int main(){
   int L,M; //จำนวนบรรทัดและแถว
   L = 3;
   M = 5;

   vector<string> status(L*M);

   ifstream source;
   source.open("status table.txt"); //เปิดไฟล์ที่จะอ่าน 
   string texline;
   int number = 0;
   while(getline(source,texline)){
      status[number] = texline;
      number++;
   }
   source.close(); //ปิดไฟล์ที่อ่าน

   showData(status,L,M); //

   updatefile(status);
   return 0;

   // for(int i = 0;i < L; i++) delete [] status[i];
   // delete [] status;
 }