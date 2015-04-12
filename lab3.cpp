#include <iostream>
#include <vector>
#include <fstream>
//#include <iomanip>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	ifstream inFile("file.in",ios::in);
	if(!inFile) {
        cerr<< "Failed opening\n"<<endl;
        exit(1);
    }
    int cow[9],i=0;
    while(inFile>>cow[i]){
    	i++;
    }
    int total=0,insert,move;
    vector<int>cow_v(9);
	for(i=0;i<9;i++){
    	cow_v[i]=cow[i];
    }
    for(i=1;i<9;++i){
    	insert=cow_v.at(i);
    	move=i;
    	while((move>0)&&(cow_v.at(move-1)>insert)){
    		cow_v.at(move)=cow_v.at(move-1);
    		--move;
    	}
    	cow_v.at(move)=insert;
    }
    int Ocow[9];
    for(i=0;i<9;i++){
    	Ocow[i]=cow_v[8-i];
    }
    for(i=0;i<5;i++){
    	total=total+Ocow[i];
    }
    cout<<total<<endl;
	return 0;
}
