
//void init(int N, int M, int J, int mPoint[], int mJobID[])
//{
//
//}
//
//void destroy()
//{
//
//}
//
//int update(int mID, int mPoint)
//{
//	return -1;
//}
//
//int updateByJob(int mJobID, int mPoint)
//{
//	return -2;
//}
//
//int move(int mNum)
//{
//	return -3;
//}





//#ifndef _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//
//#define CMD_INIT 100
//#define CMD_DESTROY 200
//#define CMD_UPDATE 300
//#define CMD_UPDATE_JOB 400
//#define CMD_MOVE 500
//
///////////////////////////////////////////////////////////////////////////
//extern void init(int N, int M, int J, int mPoint[], int mJobID[]);
//extern void destroy();
//extern int update(int mID, int mPoint);
//extern int updateByJob(int mJobID, int mPoint);
//extern int move(int mNum);
///////////////////////////////////////////////////////////////////////////
//#define MAX_N 100000
//
//static int Point[MAX_N];
//static int JobID[MAX_N];
//
//static int run()
//{
//	int isOK = 0;
//	int N;
//	int cmd, result, check;
//
//	int mN, mM, mJ;
//	int mID, mJobID;
//	int mPoint, mNum;
//
//	scanf("%d", &N);
//
//	for (int c = 0; c < N; ++c)
//	{
//		scanf("%d", &cmd);
//		switch (cmd)
//		{
//		case CMD_INIT:
//			scanf("%d %d %d", &mN, &mM, &mJ);
//			for (int i = 0; i < mN; i++) scanf("%d", &Point[i]);
//			for (int i = 0; i < mN; i++) scanf("%d", &JobID[i]);
//			init(mN, mM, mJ, Point, JobID);
//			isOK = 1;
//			break;
//
//		case CMD_UPDATE:
//			scanf("%d %d", &mID, &mPoint);
//			result = update(mID, mPoint);
//			scanf("%d", &check);
//			if (result != check)
//				isOK = 0;
//			break;
//
//		case CMD_UPDATE_JOB:
//			scanf("%d %d", &mJobID, &mPoint);
//			result = updateByJob(mJobID, mPoint);
//			scanf("%d", &check);
//			if (result != check)
//				isOK = 0;
//			break;
//
//		case CMD_MOVE:
//			scanf("%d", &mNum);
//			result = move(mNum);
//			scanf("%d", &check);
//			if (result != check)
//				isOK = 0;
//			break;
//
//		default:
//			isOK = 0;
//			break;
//		}
//	}
//	destroy();
//	return isOK;
//}
//
//int main()
//{
//	setbuf(stdout, NULL);
//	freopen("��������.txt", "r", stdin);
//
//	int T, MARK;
//	scanf("%d %d", &T, &MARK);
//
//	for (int tc = 1; tc <= T; tc++)
//	{
//		if (run()) printf("#%d %d\n", tc, MARK);
//		else printf("#%d %d\n", tc, 0);
//	}
//	return 0;
//}
