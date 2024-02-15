
//#pragma region Orginal
//
//constexpr int MAX_STOCK = 100001;
//constexpr int MAX_TABLE = 10001;
//
//unsigned long long hash(const char* s) {
//	unsigned long long h = 0;
//	for (register int i = 0; s[i]; i++) {
//		h |= (unsigned long long)(s[i] - 96) << (45 - 5 * i);
//	}
//	return h;
//}
//
//template <typename T>
//void swap(T& a, T& b) {
//	T c = a; a = b; b = c;
//}
//
//template <typename T>
//void quickSort(T* arr, int s, int e) {
//	if (s >= e) return;
//	int pivot = s, i = s, j = e;
//	while (i < j) {
//		while (arr[i] <= arr[pivot] && i < e) i++;
//		while (arr[j] > arr[pivot]) j--;
//		if (i < j) swap(arr[i], arr[j]);
//	}
//	swap(arr[j], arr[pivot]);
//	quickSort(arr, s, j - 1);
//	quickSort(arr, j + 1, e);
//}
//
//struct Stock {
//	unsigned long long h;
//	int id, price, diff, new_id;
//	Stock* next;
//	int getPrice() {
//		return price + diff;
//	}
//	bool operator<=(const Stock& t) const {
//		return h <= t.h;
//	}
//	bool operator>(const Stock& t) const {
//		return h > t.h;
//	}
//}Stocks[MAX_STOCK], * HashTable[MAX_TABLE];
//
//Stock* findStock(char* str) {
//	unsigned long long h = hash(str);
//	Stock* s = HashTable[h % MAX_TABLE];
//	while (s) {
//		if (s->h == h) {
//			return s;
//		}
//		s = s->next;
//	}
//	return 0;
//}
//
//void init(int N, char mStocks[][MAX_STOCK_LEN + 1], int mPrices[])
//{
//	for (register int i = 0; i < MAX_TABLE; i++) HashTable[i] = 0;
//
//	for (register int i = 0; i < N; i++) {
//		Stocks[i] = { hash(mStocks[i]), i, mPrices[i], 0, 0, 0 };
//	}
//
//	quickSort(Stocks, 0, N - 1);
//
//	for (register int i = 0; i < N; i++) {
//		Stocks[i].new_id = i;
//		Stocks[i].next = HashTable[Stocks[i].h % MAX_TABLE];
//		HashTable[Stocks[i].h % MAX_TABLE] = &Stocks[i];
//	}
//}
//
//void changePrices(char mFromStock[], char mToStock[], int mPriceDiff)
//{
//	register Stock* from = findStock(mFromStock);
//	register Stock* to = findStock(mToStock);
//	for (register int i = from->new_id; i <= to->new_id; i++) {
//		Stocks[i].diff += mPriceDiff;
//	}
//}
//
//int getPrice(char mStock[])
//{
//	return findStock(mStock)->getPrice();
//}
//
//int getMostIncreasedStock(char mFromStock[], char mToStock[])
//{
//	register Stock* from = findStock(mFromStock);
//	register Stock* to = findStock(mToStock);
//	register int maxV = -1e9, maxID = -1;
//	for (register int i = from->new_id; i <= to->new_id; i++) {
//		if (maxV < Stocks[i].diff || (maxV == Stocks[i].diff && maxID > Stocks[i].id)) {
//			maxV = Stocks[i].diff;
//			maxID = Stocks[i].id;
//		}
//	}
//	return maxID;
//}
//
//#pragma endregion
