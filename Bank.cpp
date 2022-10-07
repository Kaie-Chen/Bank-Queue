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



void greedy(){
	int numOfPeople = 0;
	int timeTillClosure = 0;
	int amountOfCash = 0;
	int timeTillLeaving = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, Comparator> Clients;

	cin >> numOfPeople >> timeTillClosure;

	for (int i  = 0; i < numOfPeople; i++){
		cin >> amountOfCash >> timeTillLeaving;
		Clients.push(make_pair(timeTillLeaving, amountOfCash));
	}

	int amountInBank = 0;
	

//	cout << "\n \n";

	/*
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

	*/

	priority_queue<int> customerCash;
	int customersDealtWith = 0;

	for (int i = 0; i < timeTillClosure; i++){
		customerCash = priority_queue<int>();


//		cout << Clients.top().second << " ";
		if (!Clients.empty()){
			if (Clients.top().first == i){
				while (!Clients.empty() && Clients.top().first == i){
//					cout << "Client leaving right now at" << i << " Cash they have " << Clients.top().second <<  "\n";
		//			cout << Clients.top().second << " \n";
					customerCash.push(Clients.top().second);
					Clients.pop();
				}
			} else if (Clients.top().first > i){
//				cout << "No one leaving right now at time " << i << " dealing with next customer: " << Clients.top().first << " They have $" << Clients.top().second << "\n";
				customerCash.push(Clients.top().second);
				Clients.pop();
			}


			if (!customerCash.empty()){
				amountInBank += customerCash.top();
	//			cout << amountInBank << " --> ";
			}
		}

	}

//	cout << "\n \n";

	cout << amountInBank;

}


int main(){
	greedy();
}