#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;
 
 
void trimBack(string &line)
{
    if (line == "") return;
    for (int i=(int)line.length()-1; !line.empty() && line[i] == ' ' ; i--)
        line.erase(i, 1);
}
 
void trimFront(string &line)
{
    if (line == "") return;
    for (int i=0; !line.empty() && line[i] == ' '; )
        line.erase(i, 1);
}
int main()
{
 
    string output="", line, buffer="";
    bool LineCreated=false;
 
    //ifstream cin("data.txt");;
    while (1)
    {
        line = "";
        if ( !LineCreated && !getline(cin, line)) break;
 
        if (LineCreated) LineCreated = false;
 
        if (line != "" && line[0] == '*') break;
        trimBack(line);
        line = buffer + line;
 
        if (line.length() > 72)
        {
            buffer = "";
            bool BigWord = true;
            int LastGoodPos=-1;
            for (int i=(int)line.length() - 1; i > 0; i--)
                if (line[i] == ' ')
                {
                    LastGoodPos = i;
 
                    if (i <= 72) 
                    {
                        buffer = line.substr(i+1, line.length());
                        line = line.substr(0, i);
                        BigWord = false;
                        break;
                    }
                }
 
            if (LastGoodPos != -1 && BigWord) 
            {
                buffer = line.substr(LastGoodPos, line.length());
                line = line.substr(0, LastGoodPos);
                BigWord = false;
            }
            if (!BigWord) LineCreated = true;
            trimBack(line);
            trimFront(buffer);
             
        }
        else if (line.length() < 72)
        {
            if (line.length() == 0) buffer = "";
            else if (line[(int)line.length() - 1] == ' ') buffer = "";
            else if (cin.peek() == ' ' || cin.peek() == '\n' || cin.eof()) buffer="";
            else {buffer = line + " ", line = ""; continue;}
        }
        else buffer = "";
 
        output += line + '\n';
     
    }
 
    if (output[output.length()-1] == ' ' || output[output.length()-1] == '\n') output.erase(output.length()-1,1);
    cout << output << endl;
 
    return 0;
}