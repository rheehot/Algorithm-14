#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#define DD 5
using namespace std;

int n = DD;
const int W[5][5] = {   {0, 14, 4, 10, 26},
						{ 14, 0, 7, 8, 7 },
						{4, 5, 0, 7, 6},
						{11, 7, 9, 0, 2},
						{18, 7, 17, 4, 0},
};

struct node
{
	int level;                 // the node's level in the tree
	vector<int> path;
	int bound = 0;
};

struct cmp {
	bool operator()(node t, node v) {
		return t.bound < v.bound;
	}
};

int bound(node k){
	vector<int>::iterator p;
	int min;
	int path_length = k.path.size();

	for (int i = 0; i < n; i++)
	{
		p = find(k.path.begin(), k.path.end() - 1, i);
		if (p != (k.path.end() - 1)) {
			k.bound += W[*p][*(p + 1)];
			continue;
		}


		for (int j = 0; ; j++) {			//min값 초기화
			if (find(k.path.begin() + 1, k.path.end(), i) != k.path.end()) {
				if (j == 0)
					continue;
			}

			if (W[i][j] != 0) {
				min = W[i][j];
				break;
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (find(k.path.begin() + 1, k.path.end(), i) != k.path.end()) {
				if (j == 0)
					continue;
			}


			////
			if (find(k.path.begin() + 1, k.path.end(), j) != k.path.end()) {
				continue;
			}
			else {
				if (W[i][j] < min && W[i][j] > 0)
					min = W[i][j];
			}
			////
		}
		k.bound += min;
	}
	cout <<  "bound: " << k.bound << endl;
	return k.bound;
}


int main() {
	priority_queue<node, vector<node>, cmp> PQ;
	node u, v;
	int minlength = 9000;			//가장 좋은거 : 무한대, 작은 걸 구하기 때문에;
	int i;
	vector<int> opttour;

	v.level = 0;		//루트의 레벨이 0
	v.path.push_back(0);      //패스는 1
	v.bound = bound(v);     //bound : 제일 작은 걸 구하는 함수

	PQ.push(v);			//v를 PQ에 집어넣음
	

	while (!empty(PQ))		//PQ가 empty가 아닐 동안에
	{
		v = PQ.top();		//PQ안의 값 꺼냄
		PQ.pop();
		
		if (v.bound < minlength)		//PQ에서 꺼낸 bound가 지금까지 길이보다 작아야 한다
		{
			u.level = v.level + 1;	//자식 만들어서 level을 증가시킴



			if (u.level == n - 2)		//레벨이 n-2까지 오면 끝!
			{
				u.path = v.path;
				//add(나머지 1개) & 1 to u.path; //나머지 1개랑 1 path에 집어넣고
				for (i = 2; i <= n; i++) {
					if (find(u.path.begin(), u.path.end(), i) == u.path.end()) {
						u.path.push_back(i - 1);
						break;
					}
				}

				u.path.push_back(0);	//1집어넣음
				

				if(u.bound < minlength) {	//지금까지 length보다 더 좋을 것 같으면
					minlength = u.bound;	//가장 좋은 거로 바꿔준다
					opttour = u.path;		//투어로 저장한다 (가장 좋은 패스!)
				}
			}
			else {				//아니면, 아직 덜 왔으면
				for (i = 2; i <= n; i++)	//all 2 <= i <= n && i <= v.path
				{		//path에 없는 걸 넣는다. 1 - 4로 왔으면 2, 3, 5를 넣는다, 2에서 n 사이 
					if (find(u.path.begin(), u.path.end(), i - 1) == u.path.end())	//path에 없는 거
					{
						u.path = v.path;
						u.path.push_back(i -1);		//add i to u.path;
						u.bound = bound(u);		//bound를 구하고
						
						///
						for (int k = 0; k < u.path.size(); k++) {
							cout << u.path[k] << " ";
						}
						cout << endl;
						///
						
						if (u.bound < minlength)	//bound가 더 좋으면 insert queue한다
							PQ.push(u);
					}
				}
			}
		}
	}
	cout << "opttour: ";
	for (i = 0; i < opttour.size(); i++) {
		cout << opttour[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}
