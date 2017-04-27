#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;

typedef struct node
{
	int x;
	int y;
	int step;
	int ox;
	int oy;
	node(int _x, int _y, int _step = 0, int _ox = 0, int _oy = 0){
		x= _x;y = _y;step = _step;ox = _ox; oy = _oy;
	}
}node;
int main(){
	int row, col;
	cin >> row >> col;
	char map[row][col + 1];
	for (int i = 0; i <= col; ++i){
		cin.getline(map[i], col + 1);
	}
	std::queue<node> sQueue;
	node beginNode(0,0), overNode(0,0);
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			if(map[i][j] == 'S') {
				beginNode.x = i;
				beginNode.y = j;
			}
			if(map[i][j] == 'E'){
				overNode.x = i;
				overNode.y = j;
			}
		}
	}
	sQueue.push(beginNode);
	while(sQueue.front().x != overNode.x && sQueue.front().y != overNode.y && !sQueue.empty()){
		int nowX = sQueue.front().x;
		int nowY = sQueue.front().y;
		int oldX = sQueue.front().ox;
		int oldY = sQueue.front().oy;
		int depth = sQueue.front().step;
		if(map[nowX - 1][nowY] == '.' ){
			if(nowX - 1 != oldX && nowY != oldY)sQueue.push(node(nowX - 1, nowY, depth + 1, nowX, nowY));
		}
		if(map[nowX + 1][nowY] == '.'){
			if(nowX + 1 != oldX && nowY != oldY)sQueue.push(node(nowX + 1, nowY, depth + 1, nowX, nowY));
		}
		if(map[nowX][nowY + 1] == '.' && (nowX != oldX && nowY + 1 != oldY)){
			sQueue.push(node(nowX, nowY + 1, depth + 1, nowX, nowY));
		}
		if(map[nowX][nowY - 1] == '.' && (nowX != oldX && nowY - 1 != oldY)){
			sQueue.push(node(nowX, nowY - 1, depth + 1, nowX, nowY));
		}
		cout << nowX << nowY << endl;
		sQueue.pop();
	}
	if (!sQueue.empty())
	{
		cout << sQueue.front().step << std::endl;
	}
	
}
