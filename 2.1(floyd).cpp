#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;

FILE* fpr;
errno_t errr= fopen_s(&fpr, "input.txt", "r");//���ļ�  ֻ��
FILE* fpw;
errno_t errw= fopen_s(&fpw,"output.txt", "w");//�򿪻򴴽��ļ�  ����д

const int maxn = 1e3;
int n, m, dis[maxn][maxn];//n������ m���� dis�������

void Floyd() {
    //cnt��С����ʵ�־ֲ�����
    for (int cnt = 1; cnt <= n; cnt++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][cnt] + dis[cnt][j]);
}

int main()
{
    //��ʼ��
    memset(dis, inf, sizeof dis);//�����ʼ��Ϊ�ܴ��ֵ

    //��ȡ����
    if (errr) {
        printf_s("fail to open the file!");
        exit(1);
    }
    else {
        fscanf_s(fpr, "%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            dis[i][i] = 0;//�Լ����Լ�����Ϊ0
        for (int i = 0; i < m; i++) {
            int u, v, w;
            fscanf_s(fpr, "%d %d %d", &u, &v, &w);
            dis[u][v] = w;
        }
    }

    Floyd();

    //���txt
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fprintf_s(fpw, "%d %d %d\n", i, j, dis[i][j]);

    //�ر��ļ�
    fclose(fpr);
    fclose(fpw);
}
