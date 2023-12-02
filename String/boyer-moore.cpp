#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

void badCharHeuristic( string str, int size,
						int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;
	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}

void search( string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, badchar);
    cout<<"The bad character table looks like: "<<endl;
    for(int i=0;i<pat.length()-1;i++)
    {
        cout<<pat[i]<<' ';
    }
    cout<<"*"<<endl;

	int s = 0; // s is shift of the pattern with respect to text
	while(s <= (n - m))
	{
		int j = m - 1;

		while(j >= 0 && pat[j] == txt[s + j])
			j--;
		if (j < 0)
		{
			cout << "pattern occurs at shift = " << s << endl;
			s += (s + m < n)? m-badchar[txt[s + m]] : 1;

		}

		else
			s += max(1, j - badchar[txt[s + j]]);
	}
}

int main()
{
	string txt,pat;
    cout<<"Text: ";
    cin>>txt;
    cout<<"Pattern: ";
    cin>>pat;
	search(txt, pat);
	return 0;
}


/* OUTPUT :-

Text: ABACABA
Pattern: ABA
The bad character table looks like: 
A B *
pattern occurs at shift = 0
pattern occurs at shift = 4


...Program finished with exit code 0
Press ENTER to exit console.

*/