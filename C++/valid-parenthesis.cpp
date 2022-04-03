#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'braces' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY values as parameter.
 */



vector<string> braces(vector<string> values) {

    vector<string> res;
    if(values.size()<1)
        return res;
    // vector<char> open = {'(','{','['};
    // vector<char> close = {')','}',']'};
    for(int i=0;i<values.size();i++)
    {
        string a = values[i];
        int final = 0;
        if(a.size()%2!=0)
        {
            res.push_back("NO");
            continue;
        }
        stack<char> open;
        for(int j=0;j<a.size();j++)
        {
           if(a[j]=='{' || a[j]=='(' || a[j]=='[')
           {
               open.push(a[j]);
           }
           else
           {
               if(open.empty())
               {
                   final = 1;
                   res.push_back("NO");
                   break;
               }
               else
               {
                   char b = open.top();
                   open.pop();
                   char second = a[j];
                   switch (b)
                   {
                        case '{':
                        {
                            if(second!='}')
                            {
                                final = 1;
                            }
                        }
                        break;
                        case '[':
                        {
                            if(second!=']')
                            {
                                final = 1;
                            }
                        }
                        break;
                        case '(':
                        {
                            if(second!=')')
                            {
                                final = 1;
                            }
                        }
                        break;
                        default:{}
                    }
                    if(final)
                    {
                        res.push_back("NO");
                        break;
                    }
               }
           }
        }
        if(open.empty() && !final)
        res.push_back("YES");
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string values_count_temp;
    getline(cin, values_count_temp);

    int values_count = stoi(ltrim(rtrim(values_count_temp)));

    vector<string> values(values_count);

    for (int i = 0; i < values_count; i++) {
        string values_item;
        getline(cin, values_item);

        values[i] = values_item;
    }

    vector<string> result = braces(values);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
