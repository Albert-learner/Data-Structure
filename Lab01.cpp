#include <iostream>
using namespace std;

/*두 개의 정수 (n,m) 받아들여서
입력: 임의의 두 숫자 3, 7 
출력: add(3, 7) add(2, 8) add(1, 9) add(0, 10) sum= 10 꼴로 출력
Recursive 함수 이용하기
*/

void RecurAdd(int n, int m)
{
	if (n == 0)
	{
		cout << "(" << n << "," << m << ")\n";
		cout << "sum= " << n + m << endl;
		return ;
	}
	else
	{
		cout << "(" << n << "," << m << ")->";
		RecurAdd(n - 1, m + 1);
		return ;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	if (n == 0 || m == 0)
		cout << "프로그램 오류"<<endl;
	else
		RecurAdd(n, m);
}
