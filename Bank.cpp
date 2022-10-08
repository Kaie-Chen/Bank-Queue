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

	cin >> numOfPeople >> timeTillClosure;

	for (int i  = 0; i < numOfPeople; i++){
	//	cout << "Inserting!\n";
		cin >> amountOfCash >> timeTillLeaving;
		Clients.push(make_pair(timeTillLeaving, amountOfCash));
	}


	int amountInBank = 0;
	

	priority_queue<pair<int,int>> customerCash;
	int customersDealtWith = 0;


	for(int time = Clients.top().first; time >= 0; time--){
			
	//	cout << "Sorted Clients size:  " << Clients.size() << "  \n\n";


	

			customerCash = priority_queue<pair<int,int>>();

/*
			if (Clients.top().first == time){
				
				while (!Clients.empty() && Clients.top().first == time){
//					cout << Clients.top().first << " <= " << time << "? == > ";
//					cout << Clients.top().second << "\n";
					customerCash.push(make_pair(Clients.top().second,  Clients.top().first));
//					cout << "Client leaving right now at" << Clients.top().first << " Cash they have " << Clients.top().second <<  "\n";
//					cout << Clients.top().second << " \n";
					Clients.pop();
					
				}
				if (!customerCash.empty()){
						amountInBank += customerCash.top().first;
//						cout << "\nAmount in Bank: " << amountInBank << "\n";
					}
			// If no one needs to leave right now, then we just process the one that is going to leave next
			} else 
*/
				while (!Clients.empty()  && Clients.top().first >= time){

//					cout << Clients.top().first << " <= " << time << "? == > ";
//					cout << Clients.top().second << "\n";
					customerCash.push(make_pair(Clients.top().second , Clients.top().first));
					Clients.pop();
//					cout << "Client leaving right now at" << Clients.top().first << " Cash they have " << Clients.top().second <<  "\n";
//					cout << Clients.top().second << " \n";
					
				}
				if (!customerCash.empty()){
						amountInBank += customerCash.top().first;
						customerCash.pop();
						while(!customerCash.empty()){
							Clients.push(make_pair(customerCash.top().second, customerCash.top().first));
							customerCash.pop();
						}
//						cout << "\nAmount in Bank: " << amountInBank << "\n";
					}
			

		


	}

//	cout << "\n \n";

	cout << amountInBank;

}


int main(){
	greedy();
}
