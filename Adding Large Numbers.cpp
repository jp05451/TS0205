#include<iostream>
#include<string>
#include<vector>
using namespace std;
int isNumber(const string& c, int len)
{
				int i;
				for (i = 0; i < len; i++)
				{
								if (isdigit(c[i]) == 0)
												break;
				}
				if (i == len)
								return 1;
				else
								return 0;
}
vector<int> add(vector<int> a, vector<int> b)
{
				int c=0,i,temp;
				size_t alen, blen;
				vector<int> sum;
				alen = a.size();
				blen = b.size();
				for (i = alen - 1; i >= 0; i--)
				{
								temp = a[i] + b[i]+c;
								c = temp / 10;
								temp %= 10;
								sum.push_back(temp);
				}
				if (c != 0)
								sum.push_back(c);
				return sum;
}
int main()
{
				int i=0,j=0,count=0,test=0;
				size_t alen, blen;
				string a ;
				string b;
				cin >> count;
								for (test = 0; test < count; test++)
								{
												cin >> a;
												cin >> b;
												vector<int> sum;
												vector<int> A;
												vector<int> B;
												alen = a.length();
												blen = b.length();
												if (isNumber(a, alen) == 0 || isNumber(b, blen) == 0)
												{
																cout << "Not a valid number, please try again. \n" ;
												}
												else
												{
																if (alen >= blen)//a>b
																{
																				for (i = 0; i < alen; i++)
																				{
																								A.push_back(a[i] - '0');
																				}
																				for (i = 0; i < alen - blen; i++)
																				{
																								B.push_back(0);
																				}
																				for (j = 0; j < blen; j++)
																				{
																								B.push_back(b[j] - '0');
																				}
																}
																if (alen < blen)//b>a
																{
																				for (i = 0; i < blen; i++)
																				{
																								A.push_back(b[i] - '0');
																				}
																				for (i = 0; i < blen - alen; i++)
																				{
																								B.push_back(0);
																				}
																				for (j = 0; j < alen; j++)
																				{
																								B.push_back(a[j] - '0');
																				}
																}
																sum = add(A, B);
																for (i = sum.size() - 1; i >= 0; i--)
																{
																				cout << sum.at(i);
																}
																sum.clear();
																A.clear();
																B.clear();
																
																//cout << "\n";
												}
								}
}