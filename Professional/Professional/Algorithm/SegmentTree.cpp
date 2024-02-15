//
//constexpr int MAX = 100'000;
//constexpr int MAX_TREE = 1 << 18;
//
//int A[MAX];
//int Tree[MAX_TREE], Lazy[MAX_TREE];
//
//inline int process(int a, int b) {
//	return a + b;
//}
//
//void build(int node, int start, int end) {
//	if (start == end) {
//		Tree[node] = A[start];
//		return;
//	}
//	register int mid = (start + end) / 2, lch = node * 2, rch = lch + 1;
//	build(lch, start, mid);
//	build(rch, mid + 1, end);
//	Tree[node] = process(Tree[lch], Tree[rch]);
//}
//
//void update(int node, int start, int end, int index, int value) {
//	if (start == end) {
//		Tree[node] = value;
//		return;
//	}
//	register int mid = (start + end) / 2, lch = node * 2, rch = lch + 1;
//	if (index <= mid) update(lch, start, mid, index, value);
//	else update(rch, mid + 1, end, index, value);
//	Tree[node] = process(Tree[lch], Tree[rch]);
//}
//
//void update_lazy(int node, int start, int end) {
//	if (Lazy[node] == 0) return;
//	Tree[node] += (end - start + 1) * Lazy[node];
//	if (start != end) {
//		Lazy[node * 2] += Lazy[node];
//		Lazy[node * 2 + 1] += Lazy[node];
//	}
//	Lazy[node] = 0;
//}
//
//void update_range(int node, int start, int end, int left, int right, int diff) {
//	update_lazy(node, start, end);
//	if (start > right || end < left) return;
//	if (start >= left && end <= right) {
//		Tree[node] += (end - start + 1) * diff;
//		if (start != end) {
//			Lazy[node * 2] += diff;
//			Lazy[node * 2 + 1] += diff;
//		}
//		return;
//	}
//	register int mid = (start + end) / 2, lch = node * 2, rch = lch + 1;
//	update_range(lch, start, mid, left, right, diff);
//	update_range(rch, mid + 1, end, left, right, diff);
//	Tree[node] = process(Tree[lch], Tree[rch]);
//}
//
//int query(int node, int start, int end, int left, int right) {
//	update_lazy(node, start, end);
//	if (start > right || end < left) return 0;
//	if (start >= left && end <= right) return Tree[node];
//	register int mid = (start + end) / 2, lch = node * 2, rch = lch + 1;
//	return process(query(lch, start, mid, left, right), query(rch, mid + 1, end, left, right));
//}
