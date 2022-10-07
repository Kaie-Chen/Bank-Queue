#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;


struct Comparator{
	bool operator()(const pair<int, int> a, const pair<int, int> b) const{
		return a.first > b.first;
	}
};


	/*
4 4
1000 1
2000 2
500 2
1200 0

	
10 10
2000 0
100 0
3000 3
200 5
100 7
200 7
300 7
400 7
500 7
500 7

10 10
10 0
10 4
10 0
10 4
10 5
10 6
10 3
10 2
10 1
10 1
10 8



	*/


void greedy(){
	int numOfPeople = 0;
	int timeTillClosure = 0;
	int amountOfCash = 0;
	int timeTillLeaving = 0;
	priority_queue<pair<int, int>> Clients;

	cin >> numOfPeople >> timeTillClosure;

	for (int i  = 0; i < numOfPeople; i++){
	//	cout << "Inserting!\n";
		cin >> amountOfCash >> timeTillLeaving;
		Clients.push(make_pair(timeTillLeaving, amountOfCash));
	}

	pair<int, int> sortedClients[numOfPeople];
	for (int i  = 0; i < numOfPeople; i++){
		sortedClients[i] = Clients.top();
		Clients.pop();

	}

	int amountInBank = 0;
	

	priority_queue<int> customerCash;
	int customersDealtWith = 0;


	int time = timeTillClosure - 1;

	for (int i = 0; i < numOfPeople; i++){
		customerCash = priority_queue<int>();


	//	cout << Clients.top().second << " ";
		// This deals with the case that people are going to leave right now and we must deal with them
		if (sortedClients[i].first >= time){
			int j = i;
			while (sortedClients[j].first >= i){
				customerCash.push(sortedClients[j].second);
				j++;
			//	cout << "Client leaving right now at" << i << " Cash they have " << Clients.top().second <<  "\n";
			//	cout << Clients.top().second << " \n";
				
			}
		// If no one needs to leave right now, then we just process the one that is going to leave next
		} 
		
		
		if (!customerCash.empty()){
				amountInBank += customerCash.top();
			//	cout << "\nAmount in Bank: " << amountInBank << "\n";
			}
		time--;

	}

//	cout << "\n \n";

	cout << amountInBank;

}


int main(){
	greedy();
}
