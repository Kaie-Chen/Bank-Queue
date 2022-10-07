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

	priority_queue<int> customerCash;

	for (int i = 0; i < timeTillClosure; i++){
		customerCash = priority_queue<int>();

//		cout << Clients.top().second << " ";
		while (!Clients.empty() && Clients.top().first == i){
//			cout << Clients.top().second << " \n";
			customerCash.push(Clients.top().second);
			Clients.pop();
		}

		if (!customerCash.empty()){
			amountInBank += customerCash.top();
		}

	}

//	cout << "\n \n";

	cout << amountInBank;

}


int main(){
	greedy();
}