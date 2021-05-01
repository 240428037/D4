#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, count = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto&e : a)
		e.resize(h, 1);
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 1)
			{
				count++;
				if (i + 2 < w)
					a[i + 2][j] = 0;
				if (j + 2 < h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << count;
	return 0;
}






#include<iostream>
using namespace std;
int main()
{
	int f, f0 = 0, f1 = 1;
	int N, left = 0, right = 0;
	cin >> N;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f < N)
			left = N - f;
		else
		{
			right = f - N;
			break;
		}
	}
	cout << min(left, right) << endl;
	return 0;
}






class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char>sc;
		for (auto ch : A)
		{
			switch (ch)
			{
			case'(':
				sc.push(ch);
				break;
			case')':
			{
					   if (sc.empty() || sc.top() != '(')
						   return false;
					   else
						   sc.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};





#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string>v;
	v.resize(n);
	for (auto&str : v)
		cin >> str;
	bool csort = true, lsort = true;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] >= v[i])
		{
			csort = false;
			break;
		}
	}
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lsort = false;
			break;
		}
	}
	if (csort&&lsort)
		cout << "both" << endl;
	else if (csort)
		cout << "lexicographically" << endl;
	else if (lsort)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}




#include<iostream>
using namespace std;
int main()
{
	int A, B;
	while (cin >> A >> B)
	{
		int m = max(A, B);
		while (1)
		{
			if (m%A == 0 && m%B == 0)
			{
				cout << m << endl;
				break;
			}
			m++;
		}
	}
	return 0;
}





#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int c;
	while (c = a%b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}