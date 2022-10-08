#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

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

6 10
100 0
100 0
1000 1
200 1
1000 4
500 5


6 4
100 0
100 0
1000 1
200 1
1000 3
500 3


	*/


void greedy(){
	int numOfPeople = 0;
	int timeTillClosure = 0;
	int amountOfCash = 0;
	int timeTillLeaving = 0;
	priority_queue<pair<int, int>> Clients;
	vector<pair<int,int>> sortedClients;


	cin >> numOfPeople >> timeTillClosure;

	for (int i  = 0; i < numOfPeople; i++){
	//	cout << "Inserting!\n";
		cin >> amountOfCash >> timeTillLeaving;
		Clients.push(make_pair(timeTillLeaving, amountOfCash));
	}

	while(!Clients.empty()){
		sortedClients.push_back(Clients.top());
		Clients.pop();
	}	
	int amountInBank = 0;
	

	priority_queue<pair<int,int>> customerCash;
	int customersDealtWith = 0;

	int i = 0;
	for(int time = sortedClients[i].first; time >= 0; time--){

	//	cout << "Vector state: \n";

		for (pair<int,int> e : sortedClients){
//			cout << e.first << " , " << e.second << "\n";
		}
				customerCash = priority_queue<pair<int,int>>();
				i = 0;
				while (i < sortedClients.size() && sortedClients[i].first >= time){
	//				cout << " ( " << sortedClients[i].second << ", " << sortedClients[i].first << ") \n";
					customerCash.push(make_pair(sortedClients[i].second , i));
					i++;

				}
				if (!customerCash.empty()){
						amountInBank += customerCash.top().first;
						
						sortedClients.erase(sortedClients.begin()+customerCash.top().second);
					}

	}

	cout << amountInBank;

}


int main(){
	greedy();
}
