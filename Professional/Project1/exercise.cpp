//#include <string.h>
//
//const int MAX = 500003;
//const int MAX_CHAR = 26;
//
//int Time;
//
//struct Trie {
//	bool ban;
//	int time, cnt;
//	char word[20];
//	Trie* parent;
//	Trie* child[MAX_CHAR];
//	Trie* best_word;
//	Trie* init() {
//		ban = false;
//		time = cnt = 0;
//		parent = best_word = 0;
//		memset(child, 0, sizeof(child));
//		return this;
//	}
//	Trie* insert(const char* s);
//	Trie* find(const char* s);
//}trie[MAX], * root;
//int trieCnt;
//
//Trie* newTrie() {
//	return trie[trieCnt++].init();
//}
//
//Trie* Trie::insert(const char* s) {
//	if (!*s)
//		return this;
//	int ch = *s - 'a';
//	if (!child[ch]) {
//		child[ch] = newTrie();
//		child[ch]->parent = this;
//	}
//	child[ch]->insert(s + 1);
//}
//
//Trie* Trie::find(const char* s) {
//	if (!*s)
//		return this;
//	int ch = *s - 'a';
//	return child[ch] == 0 ? 0 : child[ch]->find(s + 1);
//}
//
//
//void init()
//{
//	Time = 0;
//	trieCnt = 0;
//	root = newTrie();
//}
//
//void update_bset(Trie* t) {
//	Trie* cur = t;
//	while (cur) {
//		if (cur->best_word == 0 || t->cnt >= cur->best_word->cnt) {
//			cur->best_word = t;
//		}
//		else
//			return;
//		cur = cur->parent;
//	}
//}
//
//void inputWord(char mword[20])
//{
//	Trie* cur = root->insert(mword);
//	if (cur->ban) return;
//	if (cur->cnt == 0) strcpy(cur->word, mword);
//	cur->cnt++;
//	cur->time = ++Time;
//	update_bset(cur);
//}
//
//int recommend(char muser[20], char manswer[20])
//{
//	Trie* cur = root->find(muser);
//	if (cur == 0 || cur->best_word == 0 || cur->best_word->ban) {
//		strcpy(manswer, muser);
//		return strlen(manswer);
//	}
//	strcpy(manswer, cur->best_word->word);
//	return strlen(manswer);
//}
//
//void change_best(Trie* t) {
//	Trie* cur = t;
//	while (cur) {
//		if (cur->best_word != t) return;
//		Trie* best = cur;
//		for (int i = 0; i < MAX_CHAR; i++) {
//			if (cur->child[i] && cur->child[i]->best_word) {
//				Trie* tmp = cur->child[i]->best_word;
//				if (tmp->cnt > best->cnt || (tmp->cnt == best->cnt && tmp->time > best->time)) {
//					best = tmp;
//				}
//			}
//		}
//		cur->best_word = best;
//		cur = cur->parent;
//	}
//}
//
//void banWord(char mword[20])
//{
//	Trie* cur = root->insert(mword);
//	cur->ban = true;
//	cur->cnt = 0;
//	change_best(cur);
//}