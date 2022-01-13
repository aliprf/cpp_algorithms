#include <iostream>
#include <vector>
#include <string>

using namespace std;

string countAndSay(int n);
string say(string i);

int main ()
{   
    // cout << "1:=> " << countAndSay(1)<< "\r\n";
    // cout << "2:=> " << countAndSay(2)<< "\r\n";
    // cout << "3:=> " << countAndSay(3)<< "\r\n";
    // cout << "4:=> " << countAndSay(4) << "\r\n";
    // cout << "5:=> " << countAndSay(5) << "\r\n";
    // cout << "6:=> " << countAndSay(6) << "\r\n";
    // countAndSay(6);
}
string countAndSay(int n) 
{
    string s = "";
    for (int i=0; i<n; i++)
    {
        s = say(s);
    }
    return s;

}

string say(string input) 
{
    string result="";
    if(input.size()==0)
    {
        return "1";
    }
    else
    {
        // cout << "input=> " << input<< "\n\r";
        for(int j=0;j<=input.size(); j++)
        {
            int count =0;
            for(int k=j;k<=input.size(); k++)
            {
                if(input[j] == input[k])
                {
                    count++;
                    continue;
                }
                else
                {
                    result+=to_string(count);
                    result+= input[j];
                    j=k;
                    count =1;
                }
                // 
            }
        }
    }
    return result;
}