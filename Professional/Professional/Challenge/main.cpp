
constexpr int LM = 1 << 17;
constexpr int TREE = 1 << 18;

template <typename T>
void swap(T& a, T& b) { T c = a; a = b; b = c; }

int A[LM];

template <typename T>
struct segment_tree {
public:
	void init(T(*comp)(T, T)) {
		cmp = comp;
	}
	void build(int node, int start, int end) {
		if (start == end) {
			Tree[node] = A[start];
			return;
		}
		int mid = (start + end) >> 1, lch = node << 1, rch = lch + 1;
		build(lch, start, mid);
		build(rch, mid + 1, end);
		Tree[node] = cmp(Tree[lch], Tree[rch]);
	}
	void update(int node, int start, int end, int index, int value) {
		if (start == end) {
			Tree[node] = value;
			return;
		}
		int mid = (start + end) >> 1, lch = node << 1, rch = lch + 1;
		if (index <= mid) update(lch, start, mid, index, value);
		else update(rch, mid + 1, end, index, value);
		Tree[node] = cmp(Tree[lch], Tree[rch]);
	}
	T query(int node, int start, int end, int left, int right) {
		if (start > right || end < left) return 0;
		if (start >= left && end <= right) return Tree[node];
		int mid = (start + end) >> 1, lch = node << 1, rch = lch + 1;
		return cmp(query(lch, start, mid, left, right), query(rch, mid + 1, end, left, right));
	}
	void update_lazy(int node, int start, int end) {
		if (Lazy[node] == 0) return;
		Tree[node] += (end - start + 1) * Lazy[node];
		if (start != end) {
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	void update_range(int node, int start, int end, int left, int right, int diff) {
		update_lazy(node, start, end);
		if (start > right || end < left) return;
		if (start >= left && end <= right) {
			Lazy[node] += (end - start + 1) * diff;
			if (start != end) {
				Lazy[node * 2] += diff;
				Lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (start + end) >> 1, lch = node << 1, rch = lch + 1;
		update_range(lch, start, mid, left, right, diff);
		update_range(rch, mid + 1, end, left, right, diff);
		Tree[node] = cmp(Tree[lch], Tree[rch]);
	}
private:
	T Tree[TREE];
	int Lazy[TREE];
	T(*cmp)(T, T);
};
