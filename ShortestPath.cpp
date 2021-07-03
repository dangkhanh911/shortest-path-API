#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

#define MAX 3000
#define VOCUNG 1e9

int n;//số đỉnh của đồ thị.
int s;//đỉnh đầu.
int t;//đỉnh cuối
int truoc[MAX];//mảng đánh dấu đường đi.
int d[MAX];//mảng đánh dấu khoảng cách.
int Matrix[MAX][MAX];//ma trận trọng số
bool chuaxet[MAX];//mảng đánh dấu đỉnh đã được gán nhãn.


void Init(void) {
    cout << "So dinh: "; cin >> n;//nhập số đỉnh
    cout << "Dinh dau: "; cin >> s;//nhập đỉnh đầu
    cout << "Dinh cuoi: "; cin >> t;//nhập đỉnh cuối

    //nhập ma trận của đồ thị.
    cout << "Ma tran duong di: " << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Matrix[i][j];
            if (Matrix[i][j] == 0) Matrix[i][j] = VOCUNG;
        }
    }
}

void Result(void) {
    cout << "Duong di ngan nhat tu " << (char)(s + 'A' - 1) << " den " << (char)(t + 'A' - 1) << " la: ";
    cout << (char)(t + 'A' - 1) << "<=";//in đỉnh cuối dưới dạng char.

    int i = truoc[t];

    while (i != s) {
        cout << (char)(i + 'A' - 1) << "<=";//in ra kết quả dưới dạng char
        i = truoc[i];//Truy hồi lại đỉnh đã đi qua
    }

    cout << (char)(s + 'A' - 1);//in đỉnh đầu dưới dạng char.
    cout << endl << "Do dai duong di la : " << d[t] << endl;
}

void Dijkstra(void) {

    int u, minp;//u: kí hiệu đỉnh tạm thời trên đường đi

    //khởi tạo nhãn tạm thời cho các đỉnh.

    for (int v = 1; v <= n; v++) {
        d[v] = Matrix[s][v];//Đường đi từ đỉnh đầu tới các đỉnh còn lại
        truoc[v] = s;
        chuaxet[v] = false;
    }

    truoc[s] = 0;
    d[s] = 0;
    chuaxet[s] = true;

    //bươc lặp

    while (!chuaxet[t]) {
        minp = VOCUNG;

        //tìm đỉnh u sao cho d[u] là nhỏ nhất
        for (int v = 1; v <= n; v++) {
            if ((!chuaxet[v]) && (minp > d[v])) {
                u = v;
                minp = d[v];
            }
        }

        chuaxet[u] = true;// u la dinh co nhan tam thoi nho nhat

        if (!chuaxet[t]) {

            //gán nhãn lại cho các đỉnh.

            for (int v = 1; v <= n; v++) {

                if ((!chuaxet[v]) && (d[u] + Matrix[u][v] < d[v])) {

                    d[v] = d[u] + Matrix[u][v];//Cập nhật lại đường đi ngắn nhất

                    truoc[v] = u;//Gắn điểm u vào lộ trình đi

                }

            }

        }

    }

}

int main() {

    Init();

    Dijkstra();

    Result();

    system("pause");

}