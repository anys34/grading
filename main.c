#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

void Exit() {
    int e = 0;
    while (e != 1) {
        printf("\n나갈려면 1을 입력 : ");
        scanf("%d", &e);
    }
}

int find_stu(char stuname[][100], int stunum, char name[]) {
    for (int i = 0; i < stunum; i++) {
        if (strcmp(name, stuname[i]) == 0) 
            return i;
    }
    return 0;
}

int main(void) {
    int subnum, stunum;
    printf("총 학생 수 입력 : ");
    scanf("%d", &stunum);
    sleep(1);
    system("clear");
    char stuname[stunum][100];

    for (int i = 0; i < stunum; i++) {
        printf("%d번째 학생 이름 입력 : ", i+1);
        scanf("%s", stuname[i]);
    }
    sleep(1);
    system("clear");

    printf("과목의 수를 입력 : ");
    scanf("%d", &subnum);
    sleep(1);
    system("clear");

    int score[stunum][subnum];
    char subject[subnum][100];
    for (int i = 0; i < subnum; i++) {
        printf("%d번째 과목 입력 : ", i+1);
        scanf("%s", subject[i]);
    }
    sleep(1);
    system("clear");

    for (int i = 0; i < stunum; i++) {
        printf("%s 학생 점수 입력\n", stuname[i]);
        printf("------------------------------\n");
        for (int j = 0; j < subnum; j++) {
            printf("%s점수 입력 : ", subject[j]);
            scanf("%d", &score[i][j]);
        }
        sleep(1);
        system("clear");
    }

    int select;
    while (1) {
        system("clear");
        printf("=========================================\n\n");
        printf("\t\t메뉴선택\n\n");
        printf("\t1. 학생이 받은 점수\n");
        printf("\t2. 학생의 평균 점수\n");
        printf("\t3. 과목별 평균 점수\n");
        printf("\t4. 과목별 최고점\n");
        printf("\t5. 과목별 최저점\n");
        printf("\t6. 과목별 순위\n");
        printf("\t7. 표준 편차\n");
        printf("\t8. 종료\n");
        printf("\t메뉴선택 : ");
        scanf("%d", &select);

        switch (select) {
            case 1: { // 학생의 받은 점수
                while(1) {
                    system("clear");
                    printf("\t학생의 받은 점수\n");
                    printf("=========================================\n");
                    char selname[100];
                    printf("검색하고 싶은 학생 입력 : ");
                    scanf("%s", selname);
                    int n = find_stu(stuname, stunum, selname);
                    for (int i = 0; i < subnum; i++) {
                        printf("%s 점수 : %d\n", subject[i], score[n][i]);
                    }
                    Exit();
                    break;
                }
                break;
            }
            case 2: { // 학생의 평균 점수 
                while(1) {
                    system("clear");
                    printf("\t학생의 평균 점수\n");
                    printf("=========================================\n");
                    char selname[100];
                    int result = 0;
                    printf("검색하고 싶은 학생 입력 : ");
                    scanf("%s", selname);
                    int n = find_stu(stuname, stunum, selname);
                    for (int i = 0; i < subnum; i++)
                        result += score[n][i];
                    printf("\n\n=========================================\n\n");
                    printf("%s의 %d과목 평균 점수는 %.2f입니다.\n\n", stuname[n], subnum, (float)result/subnum);
                    printf("=========================================\n");
                    Exit();
                    break;
                }
                break;
            }
            case 3: { // 과목별 평균 점수
                while (1) {
                    system("clear");
                    printf("\t과목별 평균 점수\n");
                    printf("=========================================\n\n");
                    for (int i = 0; i < subnum; i++) {
                        int result = 0;
                        for (int j = 0; j < stunum; j++) {
                            result += score[j][i];
                        }
                        printf("%s의 평균 점수는 %.2f입니다.\n", subject[i], (float)result/stunum);
                    }
                    Exit();
                    break;
                }
                break;
            }
            case 4: { // 과목별 최고점
                while (1) {
                    system("clear");
                    printf("\t과목별 최고점\n");
                    printf("=========================================\n\n");
                    for (int i = 0; i < subnum; i++) {
                        int max = 0;
                        int name = 0;
                        for (int j = 0; j < stunum; j++) {
                            if (max < score[j][i]) {
                                max = score[j][i];
                                name = i;
                            }
                        }
                        printf("%s의 최고점은 %s학생의 %d점 입니다.\n", subject[i], stuname[name], max);
                    }
                    Exit();
                    break;
                }
                break;
            }
            case 5: { // 과목별 최저점
                while (1) {
                    system("clear");
                    printf("\t과목별 최저점\n");
                    printf("=========================================\n\n");
                    for (int i = 0; i < subnum; i++) {
                        int min = 100;
                        int name = 0;
                        for (int j = 0; j < stunum; j++) {
                            if (min > score[j][i]) {
                                min = score[j][i];
                                name = i;
                            }
                        }
                        printf("%s의 최저점은 %s학생의 %d점 입니다.\n", subject[i], stuname[name], min);
                    }
                    Exit();
                    break;
                }
                break;
            }
            case 6: { // 과목별 순위
                while (1) {
                    system("clear");
                    printf("\t과목별 순위\n");
                    printf("=========================================\n\n");
                    int rank[stunum];
                    for (int i = 0; i < subnum; i++) {
                        printf("=====%s=====\n", subject[i]);
                        for (int j = 0; j < stunum; j++) {
                            rank[j] = 1;
                            for (int k = 0; k < stunum; k++) {
                                if (score[j][i] < score[k][i]) {
                                    rank[j]++;
                                }
                            }
                        }
                        for (int j = 0; j < stunum; j++) {
                            for (int k = 0; k < stunum; k++) {
                                if (rank[k] == j+1) {
                                    printf("%d등 : %s(%d점)\n", j+1, stuname[k], score[k][i]);
                                }
                            }
                        }
                    }
                    Exit();
                    break;
                }
                break;
            }
            case 7: { // 표준 편차
                while(1) {
                    system("clear");
                    printf("\t표준 편차\n");
                    printf("=========================================\n");
                    for (int i = 0; i < subnum; i++) {
                        int result = 0;
                        int avg = 0;
                        for (int j = 0; j < stunum; j++)
                            avg += score[j][i];
                        avg /= stunum;
                        for (int j = 0; j < stunum; j++) {
                            result += pow(score[j][i] - avg, 2);
                        }
                        result /= stunum;
                        printf("%s의 표준 편차 : %.2f\n\n", subject[i], (float)sqrt(result));
                    }
                    Exit();
                    break;
                }
                break;
            }
            case 8: {
                system("clear");
                printf("=====성적 산출 프로그램 종료=====");
                return 0;
            }
            default: {
                printf("메뉴 중에 있는 것만 선택하세요");
                break;
            }
        }
    }
    return 0;
}