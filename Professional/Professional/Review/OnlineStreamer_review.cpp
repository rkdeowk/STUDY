
//constexpr int INF = (int)2e9;
//constexpr int LM = 200001;
//constexpr int TLM = 1 << 19;
//
//int N, Subscribe[LM];
//int TreeSum[TLM], TreeMax[TLM], TreeMin[TLM];
//
//inline int max(int a, int b) { return a > b ? a : b; }
//inline int min(int a, int b) { return a > b ? b : a; }
//
//void build(int now, int s, int e) {
//    if (s == e) {
//        TreeSum[now] = TreeMax[now] = TreeMin[now] = Subscribe[s];
//        return;
//    }
//    register int m = (s + e) >> 1, lch = now << 1, rch = lch + 1;
//    build(lch, s, m);
//    build(rch, m + 1, e);
//    TreeSum[now] = TreeSum[lch] + TreeSum[rch];
//    TreeMax[now] = max(TreeMax[lch], TreeMax[rch]);
//    TreeMin[now] = min(TreeMin[lch], TreeMin[rch]);
//}
//
//void update(int now, int s, int e, int idx, int val) {
//    if (s == e) {
//        TreeSum[now] = TreeMax[now] = TreeMin[now] = val;
//        return;
//    }
//    register int m = (s + e) >> 1, lch = now << 1, rch = lch + 1;
//    if (idx <= m) update(lch, s, m, idx, val);
//    else update(rch, m + 1, e, idx, val);
//    TreeSum[now] = TreeSum[lch] + TreeSum[rch];
//    TreeMax[now] = max(TreeMax[lch], TreeMax[rch]);
//    TreeMin[now] = min(TreeMin[lch], TreeMin[rch]);
//}
//
//int querySum(int now, int s, int e, int fs, int fe) {
//    if (s > fe || e < fs) return 0;
//    if (s >= fs && e <= fe) return TreeSum[now];
//    register int m = (s + e) >> 1, lch = now << 1, rch = lch + 1;
//    return querySum(lch, s, m, fs, fe) + querySum(rch, m + 1, e, fs, fe);
//}
//
//int queryMax(int now, int s, int e, int fs, int fe) {
//    if (s > fe || e < fs) return -INF;
//    if (s >= fs && e <= fe) return TreeMax[now];
//    register int m = (s + e) >> 1, lch = now << 1, rch = lch + 1;
//    return max(queryMax(lch, s, m, fs, fe), queryMax(rch, m + 1, e, fs, fe));
//}
//
//int queryMin(int now, int s, int e, int fs, int fe) {
//    if (s > fe || e < fs) return INF;
//    if (s >= fs && e <= fe) return TreeMin[now];
//    register int m = (s + e) >> 1, lch = now << 1, rch = lch + 1;
//    return min(queryMin(lch, s, m, fs, fe), queryMin(rch, m + 1, e, fs, fe));
//}
//
//void init(int N, int mSubscriber[]) {
//    ::N = N;
//    for (register int i = 0; i < N; i++) {
//        Subscribe[i + 1] = mSubscriber[i];
//    }
//
//    build(1, 1, N);
//}
//
//int subscribe(int mId, int mNum) {
//    Subscribe[mId] += mNum;
//    update(1, 1, N, mId, Subscribe[mId]);
//    return Subscribe[mId];
//}
//
//int unsubscribe(int mId, int mNum) {
//    Subscribe[mId] -= mNum;
//    update(1, 1, N, mId, Subscribe[mId]);
//    return Subscribe[mId];
//}
//
//int count(int sId, int eId) {
//    return querySum(1, 1, N, sId, eId);
//}
//
//int calculate(int sId, int eId) {
//    return queryMax(1, 1, N, sId, eId) - queryMin(1, 1, N, sId, eId);
//}
