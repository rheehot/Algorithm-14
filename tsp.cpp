#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int level;                 // the node's level in the tree
	ordered_set path;
	number bound;
};

struct cmp{
	bool operator()(node t, node v){
		return t.bound < v.bound;
	}
}

int main(){
	priority_queue<node, vector<node>, cmp> PQ;
	return 0;
}

void travel 2 (int n, const number W[][], ordered-set& opttour, number& minlength)
{
	//priority_queue_of_node PQ;
	priority_queue<node, vector<node>, cmp> PQ;
	node u, v;
	//initialize (PQ);	//큐 초기화
	v.level = 0;		//루트의 레벨이 0
	v.path = [1];      //패스는 1                         
	v.bound = bound (v);     //bound : 제일 작은 걸 구하는 함수                                 
	minlength = 9000;			//가장 좋은거 : 무한대, 작은 걸 구하기 때문에
	insert (PQ, v);			//v를 PQ에 집어넣음

	while (!empty(PQ))		//PQ가 empty가 아닐 동안에
	{
		remove (PQ, v);		//PQ안의 값 꺼냄
		if (v.bound < minlength)		//PQ에서 꺼낸 bound가 지금까지 길이보다 작아야 한다
		{
			u. level = v. level + 1;	//자식 만들어서 level을 증가시킴
			if (u. level == n - 2)		//레벨이 n-2까지 오면 끝!
			{
				u.path = v.path;
				add(나머지 1개) & 1 to u.path; //나머지 1개랑 1 path에 집어넣고
				if (length (u) < minlength){	//지금까지 length보다 더 좋을 것 같으면
						minlength = length (u);	//가장 좋은 거로 바꿔준다
						opttour = u. path;		//투어로 저장한다 (가장 좋은 패스!)
				}
			}
			else{				//아니면, 아직 덜 왔으면
				for all 2 <= i <= n && i <= v.path{		//path에 없는 걸 넣는다. 1 - 4로 왔으면 2, 3, 5를 넣는다, 2에서 n 사이
					u.path = v.path;
					add i to u.path;
					u. bound = bound(u);		//bound를 구하고
					if (u. bound < minlength)	//bound가 더 좋으면 insert queue한다
						insert (PQ, u);
				}
			}	
		}
	}
}