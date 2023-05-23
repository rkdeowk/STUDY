#include <unordered_map>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

const int DIV = 1000;

struct Node {
	int level;
	int parent;
	vector<int> child;
}node[12005];

struct Range {
	int arr[DIV];
	int lazy;
	void init() {
		memset(arr, 0, sizeof(arr));
		lazy = 0;
	}
	void update(int start, int end, int val) {
		if (start == 0 && end == DIV - 1) {
			lazy += val;
			return;
		}

		for (register int i = start; i <= end; i++)
			arr[i] += val;
	}
}R[1005];

unordered_map<string, int> um;
int ncnt;

void init(char mAncestor[], int mDeathday)
{
	for (register int i = 0; i < 1005; i++) R[i].init();
	for (register int i = 1; i <= ncnt; i++) node[i].child.clear();
	um.clear();
	ncnt = 0;

	um[mAncestor] = ++ncnt;
	node[ncnt].level = 0;
	node[ncnt].parent = -1;

	int end = mDeathday / DIV;
	for (register int i = 0; i <= end; i++) {
		if (i == end)
			R[i].update(0, mDeathday % DIV, 1);
		else
			R[i].update(0, DIV - 1, 1);
	}
}

int add(char mName[], char mParent[], int mBirthday, int mDeathday)
{
	int par = um[mParent];
	int cur = um[mName] = ++ncnt;

	node[cur].level = node[par].level + 1;
	node[cur].parent = par;
	node[par].child.push_back(cur);

	int start = mBirthday / DIV;
	int end = mDeathday / DIV;
	for (register int i = start; i <= end; i++) {
		if (i == start) {
			if (start == end)
				R[i].update(mBirthday % DIV, mDeathday % DIV, 1);
			else
				R[i].update(mBirthday % DIV, DIV - 1, 1);
		}
		else if (i == end)
			R[i].update(0, mDeathday % DIV, 1);
		else
			R[i].update(0, DIV - 1, 1);
	}

	return node[cur].level;
}

int distance(char mName1[], char mName2[])
{
	int id1 = um[mName1];
	int id2 = um[mName2];
	if (node[id1].level > node[id2].level)
		swap(id1, id2);

	int dist = 0;
	while (node[id1].level != node[id2].level) {
		dist++;
		id2 = node[id2].parent;
	}

	while (id1 != id2) {
		dist += 2;
		id1 = node[id1].parent;
		id2 = node[id2].parent;
	}

	return dist;
}

int count(int mDay)
{
	return R[mDay / DIV].arr[mDay % DIV] + R[mDay / DIV].lazy;
}








//void init(char mAncestor[], int mDeathday)
//{
//	return;
//}
//
//int add(char mName[], char mParent[], int mBirthday, int mDeathday)
//{
//	return 0;
//}
//
//int distance(char mName1[], char mName2[])
//{
//	return 0;
//}
//
//int count(int mDay)
//{
//	return 0;
//}
