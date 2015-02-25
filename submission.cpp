#include <stdio.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <stack>
using namespace std;
int min(int x, int y){
	if(x < y){
		return x;
	}else{
		return y;
	}
};
void dynamicProgramming(){
	int max = 11;
	int index = 10;
	stack<int> nameStack;
	bool done = false;
	string nameArr[] = {"New York City", "Allentown", "Scranton", "Binghamton", "Albany", "Syracuse", "Montreal", "Kingston", "Rochester", "Buffalo", "Toronto"};
	int pArr[max][max];
	for(int i = 0; i < max; i++){
		for(int j = 0; j < max; j++){
			pArr[i][j] = 0;
		}
	}
	double dArr[max][max];
	for(int i = 0; i < max; i++){
		for(int j = 0; j < max; j++){
			dArr[i][j] = INT_MAX;
		}
	}
	dArr[0][1] = 70;
	dArr[0][2] = 100;
	dArr[0][3] = 180;
	dArr[0][4] = 140;
	dArr[1][0] = 70;
	dArr[1][2] = 65;
	dArr[2][0] = 100;
	dArr[2][1] = 65;
	dArr[2][3] = 60;
	dArr[3][0] = 180;
	dArr[3][2] = 60;
	dArr[3][5] = 70;
	dArr[4][0] = 140;
	dArr[4][5] = 100;
	dArr[4][6] = 130;
	dArr[5][3] = 70;
	dArr[5][4] = 100;
	dArr[5][7] = 65;
	dArr[5][8] = 70;
	dArr[6][4] = 130;
	dArr[6][7] = 160;
	dArr[7][5] = 65;
	dArr[7][6] = 160;
	dArr[7][10] = 180;
	dArr[8][5] = 70;
	dArr[8][9] = 60;
	dArr[9][8] = 60;
	dArr[9][10] = 100;
	for(int k = 0; k < max; k++){
		for(int i = 0; i < max; i++){
			for(int j = 0; j < max; j++){
				if(dArr[i][j] > dArr[i][k] + dArr[k][j]){
					dArr[i][j] = (dArr[i][k] + dArr[k][j]);
					pArr[i][j] = k;
				}
			}
		}
	}cout<<"The distance from New York City to Toronto is: "<<dArr[0][10]<<" miles"<<endl;
	nameStack.push(index);
	while(!done){
		nameStack.push(pArr[0][index]);
		index = pArr[0][index];
		if(index < 1){
			done = true;
		}
	}cout<<"The path from New York City to Toronto is: ";
	while(!nameStack.empty()){
		cout<<nameArr[nameStack.top()]<< " ";
		nameStack.pop();
	}
};
int main(int argc, char* argv[]){
	if(argc != 1){
		cout<<"Please only write the executable."<<endl;
		return 1;
	}else{
		dynamicProgramming();
	}
}
