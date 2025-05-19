 #include <bits/stdc++.h>
using namespace std;

int main()
{
    int ruN, elN[50];
    string in="", line[50], rules[50][50];
    ifstream file("grammar.txt");

    if (!file.is_open())
        {
        cout << "Error opening file.";
        return 1;
    }

    for (ruN=0; getline(file, line[ruN]); ruN++)
        for (int i=0; line[ruN][i]!='-'; i++ )
            rules[ruN][0]+=line[ruN][i];

    for (int i=0; i<ruN; i++)
    {
        bool c=0;
        elN[i]=1;
        for (int j=0; line[i][j]!='\0'; j++)
        {
            if (line[i][j]=='>')
                c=1;
            if (c==1)
            {
                if (line[i][j]=='|')
                    elN[i]++;
                else
                    rules[i][elN[i]] += line[i][j];
            }
        }
    }

    for (int i=0; i<ruN; i++)
    {
        cout<<"I'm here\n";
        for (int j=0; j<=elN[ruN]; j++)
            cout<<rules[i][j]<<"\t";
        cout<<endl;
    }


    return 0;
}
