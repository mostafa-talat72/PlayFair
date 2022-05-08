/*** بسم الله الرحمن الرحيم  ***/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define endl    "\n"	
#define all(v) ((v).begin()), ((v).end())
#define allr(s) s.rbegin(),s.rend()
#define vi      vector<int>
#define vl      vector<ll>
#define SetPrecision(x)  cout << fixed << setprecision(x)
#define sz(s)	(ll)(s.size())
#define PI   acos(-1)
#define Fast  std::ios_base::sync_with_stdio(0);cin.tie(NULL);	cout.tie(NULL);
typedef long long ll;
const ll mod = 1e9 + 7, oo = 0x3f3f3f3f;
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
vector<vector<char>>Matrix(5);
map<char, pair<int, int>>LetterIDX;
void makeMarix(string key)
{
	for (int i = 0; i < sz(key); i++)
	{
		if (key[i] == 'j')
			key[i] = 'i';
	}
	int idx = 0;
	char ch = 'A';
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (idx >= sz(key))
			{
				while (LetterIDX.count(ch) || (ch == 'J' && LetterIDX.count('I')))
				{
					ch++;
				}

				Matrix[i].push_back(ch);
				LetterIDX[ch] = { i,j };
			}
			else
			{
				while (idx < sz(key) && (LetterIDX.count(toupper(key[idx])) || (toupper(key[idx]) == 'J' && LetterIDX.count('I'))))
				{
					idx++;
				}
				if (idx < sz(key))
				{
					Matrix[i].push_back(toupper(key[idx]));
					LetterIDX[toupper(key[idx])] = { i,j };
				}
				else
				{
					j--;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
vector<pair<char, char>> makeplanText(string text)
{
	vector<pair<char, char>>ret;
	if (sz(text) & 1)
	{
		if (toupper(text[sz(text) - 1]) == 'X')
		{
			text += 'Z';
		}
		else
		{
			text += 'X';
		}
	}
	for (int i = 0; i < sz(text); i += 2)
	{
		ret.push_back({ toupper(text[i]),toupper(text[i + 1]) });
	}
	for (auto i : ret)
	{
		cout << i.first << " " << i.second << "\n";
	}
	return ret;
}

string Encrypt(vector<pair<char, char>> text)
{
	string ret;
	for (auto i : text)
	{
		if (LetterIDX[i.first].second == LetterIDX[i.second].second)
		{
			ret += Matrix[(LetterIDX[i.first].first + 1) % 5][LetterIDX[i.first].second];
			ret += Matrix[(LetterIDX[i.second].first + 1) % 5][LetterIDX[i.second].second];
		}
		else if (LetterIDX[i.first].first == LetterIDX[i.second].first)
		{
			ret += Matrix[LetterIDX[i.first].first][(LetterIDX[i.first].second + 1) % 5];
			ret += Matrix[LetterIDX[i.second].first][(LetterIDX[i.second].second + 1) % 5];
		}
		else
		{
			ret += Matrix[LetterIDX[i.first].first][LetterIDX[i.second].second];
			ret += Matrix[LetterIDX[i.second].first][LetterIDX[i.first].second];
		}
	}
	return ret;
}
void solve()
{
	string key, planText;
	cin >> planText >> key;
	makeMarix(key);
	vector<pair<char, char>> EditText = makeplanText(planText);

	cout << Encrypt(EditText) << "\n";
}

int main()
{
	Fast  file();
	int tst = 1;
	//cin >> tst;
	while (tst--)
	{
		solve();
	}
}
