#include <iostream>
using namespace std;

/*
재귀함수 사용하지 않고 while문 사용하여 재귀함수 꼴로 문제 풀기
*/

int sum(int n, int m)
{
	while (n > 0) {
		cout << "n= " << n << " m= " << m << ";  "; //printf("%d,%d\n", n, m);
		n--;
		m++;
	}
	cout << "n= " << n << " m= " << m << ';' << endl; //printf("%d,%d\n", n, m);
	return m;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	int temp=sum(n,m);
	cout << temp<<endl;
	return 0;
}

/*
while (n > 0)
{
cout << "n= " << n << " m= " << m << ';  '; ->''와 "" 잘 사용하기
n--;
m++;
}
cout << "n= " << n << " m= " << m << ';'<<endl;
cout << "sum= " << n + m << endl;
return m;
*/