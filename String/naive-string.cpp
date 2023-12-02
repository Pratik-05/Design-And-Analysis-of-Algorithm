#include <iostream>
#include <string>
using namespace std;

void naiveStringMatch(string text, string pattern) 
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) 
	{
        int j;
        for (j = 0; j < m; j++) 
		{
            if (text[i + j] != pattern[j]) 
			{
                break;
            }
        }

        if (j == m) 
		{
			cout<<"\nThe pattern is matched....."<<endl;
            cout << "\nThe Pattern is found at index: " << i << endl;
        }
    }
}

int main() 
{
    string text, pattern;
    cout<<"\n\tNAIVE STRING MATCHING"<<endl;
    
    cout << "\nEnter the string: ";
    cin>>text;
    cout<<endl;
    
    cout << "\nEnter the pattern: ";
    cin>>pattern;
    cout<<endl;
    
	naiveStringMatch(text, pattern);
    return 0;
}

/* OUTPUT :-


        NAIVE STRING MATCHING

Enter the string: ABACABA


Enter the pattern: ABA


The pattern is matched.....

The Pattern is found at index: 0

The pattern is matched.....

The Pattern is found at index: 4


...Program finished with exit code 0
Press ENTER to exit console.

*/