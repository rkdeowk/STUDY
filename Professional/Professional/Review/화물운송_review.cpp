
//#pragma region UsingBitOperation
//
//constexpr int INF = 30001;
//constexpr int MAX_CITY = 1001;
//constexpr int A = 15;
//constexpr int MASK = (1 << A) - 1;
//
//int Graph[MAX_CITY][MAX_CITY], ChildCnt[MAX_CITY];
//
//int Heap[6001], HeapSize;
//
//void swap(int& a, int& b) {
//	int c = a; a = b; b = c;
//}
//
//void heapPush(int value) {
//	Heap[++HeapSize] = value;
//	register int c = HeapSize;
//	while (c > 1 && Heap[c] > Heap[c >> 1]) {
//		swap(Heap[c], Heap[c >> 1]);
//		c >>= 1;
//	}
//}
//
//int heapPop() {
//	register int ret = Heap[1];
//	swap(Heap[1], Heap[HeapSize--]);
//	register int p = 1, c = p << 1;
//	while (c <= HeapSize) {
//		if (c<HeapSize && Heap[c + 1] > Heap[c]) c++;
//		if (Heap[p] > Heap[c]) break;
//		swap(Heap[p], Heap[c]);
//		p = c, c <<= 1;
//	}
//	return ret;
//}
//
//void init(int N, int K, int sCity[], int eCity[], int mLimit[]) {
//	for (register int i = 0; i < N; i++) {
//		ChildCnt[i] = 0;
//	}
//
//	for (int i = 0; i < K; i++) {
//		Graph[sCity[i]][ChildCnt[sCity[i]]++] = mLimit[i] << A | eCity[i];
//	}
//}
//
//void add(int sCity, int eCity, int mLimit) {
//	Graph[sCity][ChildCnt[sCity]++] = mLimit << A | eCity;
//}
//
//int calculate(int sCity, int eCity) {
//	HeapSize = 0;
//	register bool visited[MAX_CITY] = { 0 };
//	register int minLimit = INF;
//	register bool flag = false;
//	heapPush(INF << A | sCity);
//	while (HeapSize) {
//		register int value = heapPop();
//		register int startLimit = value >> A, start = value & MASK;
//		if (minLimit > startLimit) minLimit = startLimit;
//
//		if (start == eCity) {
//			flag = true;
//			break;
//		}
//
//		visited[start] = true;
//
//		for (int i = 0; i < ChildCnt[start]; i++) {
//			register int value = Graph[start][i];
//			register int endLimit = value >> A, end = value & MASK;
//			if (visited[end]) continue;
//			heapPush(value);
//		}
//	}
//
//	return !flag ? -1 : minLimit;
//}
//
//#pragma endregion
//
//
//
//
//
//#pragma region UsingRegister
//
//constexpr int MAX_CITY = 1001;
//
//template <typename T, typename U>
//struct pair {
//	T first;
//	U second;
//	bool operator<(const pair& t) const {
//		return first != t.first ? first > t.first : second > t.second;
//	}
//	bool operator>(const pair& t) const {
//		return first != t.first ? first < t.first : second < t.second;
//	}
//};
//
//pair<int, int> Graph[MAX_CITY][MAX_CITY];
//int ChildCnt[MAX_CITY];
//
//template <typename T>
//void swap(T& a, T& b) {
//	T c = a; a = b; b = c;
//}
//
//pair<int, int> heap[6001];
//int hcnt;
//
//void heapUp(register int c) {
//	while (c > 1 && heap[c] < heap[c >> 1]) {
//		swap(heap[c], heap[c >> 1]);
//		c >>= 1;
//	}
//}
//void heapDown(register int p) {
//	register int c = p << 1;
//	while (c <= hcnt) {
//		if (c < hcnt && heap[c + 1] < heap[c]) c++;
//		if (heap[p] < heap[c]) break;
//		swap(heap[p], heap[c]);
//		p = c, c <<= 1;
//	}
//}
//
//void heapPush(pair<int, int> value) {
//	heap[++hcnt] = value;
//	heapUp(hcnt);
//}
//
//void heapPop() {
//	swap(heap[1], heap[hcnt--]);
//	heapDown(1);
//}
//
//pair<int, int> heapTop() {
//	return heap[1];
//}
//
//void init(int N, int K, int sCity[], int eCity[], int mLimit[]) {
//	for (register int i = 0; i < MAX_CITY; i++) {
//		ChildCnt[i] = 0;
//	}
//
//	for (register int i = 0; i < K; i++) {
//		Graph[sCity[i]][ChildCnt[sCity[i]]++] = { eCity[i], mLimit[i] };
//	}
//}
//
//void add(int sCity, int eCity, int mLimit) {
//	Graph[sCity][ChildCnt[sCity]++] = { eCity, mLimit };
//}
//
//int calculate(int sCity, int eCity) {
//	register int ret = 2e9;
//	register bool flag = false;
//	register bool visit[MAX_CITY] = { 0 };
//
//	hcnt = 0;
//	heapPush({ (int)2e9, sCity });
//	while (hcnt) {
//		register int start_limit = heap[1].first;
//		register int start = heap[1].second;
//		heapPop();
//		if (ret > start_limit) ret = start_limit;
//
//		if (start == eCity) {
//			flag = true;
//			break;
//		}
//
//		visit[start] = true;
//		for (register int i = 0; i < ChildCnt[start]; i++) {
//			register int end_limit = Graph[start][i].second;
//			register int end = Graph[start][i].first;
//			if (visit[end] == true) continue;
//			heapPush({ end_limit, end });
//		}
//	}
//
//	return !flag ? -1 : ret;
//}
//
//#pragma endregion
//
//
//
//
//
//#pragma region NotUsingSTL
//
//constexpr int MAX_CITY = 1001;
//
//template <typename T, typename U>
//struct pair {
//	T first;
//	U second;
//	bool operator<(const pair& t) const {
//		return first != t.first ? first > t.first : second > t.second;
//	}
//	bool operator>(const pair& t) const {
//		return first != t.first ? first < t.first : second < t.second;
//	}
//};
//
//template <typename T>
//class vector {
//public:
//	void clear() {
//		sz = 0;
//	}
//	int size() const {
//		return sz;
//	}
//	void push_back(T value) {
//		arr[sz++] = value;
//	}
//	T operator[](int idx) {
//		return arr[idx];
//	}
//private:
//	T arr[MAX_CITY];
//	int sz;
//};
//
//vector<pair<int, int>> Graph[MAX_CITY];
//
//template <typename T>
//class priority_queue {
//public:
//	priority_queue() {
//		hcnt = 0;
//	}
//	void clear() {
//		hcnt = 0;
//	}
//	bool empty() const {
//		return hcnt == 0;
//	}
//	void push(T value) {
//		heap[++hcnt] = value;
//		up(hcnt);
//	}
//	T top() {
//		return heap[1];
//	}
//	void pop() {
//		swap(heap[1], heap[hcnt--]);
//		down(1);
//	}
//private:
//	T heap[6001];
//	int hcnt;
//	void swap(T& a, T& b) {
//		T c = a; a = b; b = c;
//	}
//	void up(int c) {
//		while (c > 1 && heap[c] < heap[c >> 1]) {
//			swap(heap[c], heap[c >> 1]);
//			c >>= 1;
//		}
//	}
//	void down(int p) {
//		int c = p << 1;
//		while (c <= hcnt) {
//			if (c < hcnt && heap[c + 1] < heap[c]) c++;
//			if (heap[p] < heap[c]) break;
//			swap(heap[p], heap[c]);
//			p = c, c <<= 1;
//		}
//	}
//};
//
//void init(int N, int K, int sCity[], int eCity[], int mLimit[]) {
//	for (int i = 0; i < MAX_CITY; i++) {
//		Graph[i].clear();
//	}
//
//	for (int i = 0; i < K; i++) {
//		Graph[sCity[i]].push_back({ eCity[i], mLimit[i] });
//	}
//}
//
//void add(int sCity, int eCity, int mLimit) {
//	Graph[sCity].push_back({ eCity, mLimit });
//}
//
//int calculate(int sCity, int eCity) {
//	register int ret = 2e9;
//	register bool flag = false;
//	register bool visit[MAX_CITY] = { 0 };
//
//	priority_queue<pair<int, int>> pq;
//	pq.push({ (int)2e9, sCity });
//	while (!pq.empty()) {
//		register int start_limit = pq.top().first;
//		register int start = pq.top().second;
//		pq.pop();
//		if (ret > start_limit) ret = start_limit;
//
//		if (start == eCity) {
//			flag = true;
//			break;
//		}
//
//		visit[start] = true;
//		for (register int i = 0; i < Graph[start].size(); i++) {
//			register int end_limit = Graph[start][i].second;
//			register int end = Graph[start][i].first;
//			if (visit[end] == true) continue;
//			pq.push({ end_limit, end });
//		}
//	}
//
//	return !flag ? -1 : ret;
//}
//
//#pragma endregion
//
//
//
//
//
//#pragma region UsingSTL
//
//#include <vector>
//#include <queue>
//using namespace std;
//using pii = pair<int, int>;
//
//constexpr int MAX_CITY = 1001;
//
//vector<pii> Graph[MAX_CITY];
//
//void init(int N, int K, int sCity[], int eCity[], int mLimit[]) {
//	for (int i = 0; i < MAX_CITY; i++) {
//		Graph[i].clear();
//	}
//
//	for (int i = 0; i < K; i++) {
//		Graph[sCity[i]].push_back({ eCity[i], mLimit[i] });
//	}
//}
//
//void add(int sCity, int eCity, int mLimit) {
//	Graph[sCity].push_back({ eCity, mLimit });
//}
//
//int vcnt, visit[MAX_CITY];
//int calculate(int sCity, int eCity) {
//	++vcnt;
//	register int ret = 2e9;
//	register bool flag = false;
//
//	priority_queue<pii> pq;
//	pq.push({ 2e9, sCity });
//	while (!pq.empty()) {
//		int start_limit = pq.top().first;
//		int start = pq.top().second;
//		pq.pop();
//		if (ret > start_limit) ret = start_limit;
//
//		if (start == eCity) {
//			flag = true;
//			break;
//		}
//
//		visit[start] = vcnt;
//		for (register int i = 0; i < Graph[start].size(); i++) {
//			register int end_limit = Graph[start][i].second;
//			register int end = Graph[start][i].first;
//			if (visit[end] == vcnt) continue;
//			pq.push({ end_limit, end });
//		}
//	}
//
//	return !flag ? -1 : ret;
//}
//
//#pragma endregion
