#include <string>


using namespace std;

// Reverse-Twice approach.
class Solution
{
public:
    string reverseWords(string s) 
    {
        // Reverse the whole string first.
        int size = s.size();
        for(int i = 0; i < size/2; i++)
        {
            swap(s[i], s[size-1-i]);
        }

        // Delete extra spaces.
        int put_here = 0;
        for(int i = 0; i < size; i++)
        {
            if (s[i] != ' ')
            {
                for(int j = i; s[j] != ' ' && j < size; j++)
                {
                    s[put_here++] = s[j];
                    i++;
                }
                s[put_here++] = ' ';
            }
        }
        s.resize(--put_here);

        cout << s << endl;

        // Re-reverse each word (and delete extra spaces).
        put_here = 0;
        auto end_index = 0;
        auto start_index = s.find_first_not_of(" ");
        do
        {
            end_index = s.find_first_of(" ", start_index);
            if (end_index == string::npos)
            {
                end_index = s.size();
            }
            for(auto i = 1; i <= (end_index - start_index)/2; i++)
            {
                swap(s[put_here++], s[end_index-i]);
            }
            put_here += (end_index - start_index)/2 + ((end_index - start_index)%2);
            s[put_here++] = ' ';

            start_index = s.find_first_not_of(" ", end_index);
            cout << s << endl;
        } while (start_index != string::npos);

        // C++ way of terminating a string.
        s.resize(--put_here);
        return s;
    }
};

class Solution_v3
{
public:
    string reverseWords(string s) 
    {
        string to_return;
        
        auto start_index = s.size()-1;
        auto end_index = s.find_last_not_of(" ", start_index);
        do
        {
            start_index = s.find_last_of(" ", end_index);
            for(int i = start_index + 1; i <= end_index; i++)
            {
                to_return.push_back(s[i]);
            }
            to_return.push_back(' ');
            end_index = s.find_last_not_of(" ", start_index);
        } while (end_index != string::npos);

        to_return.pop_back();
        return to_return;
    }
};

class Solution_v2
{
public:
    string reverseWords(string s) 
    {
        string to_return;
        
        auto start_index = s.size()-1;
        auto end_index = s.find_last_not_of(" ", start_index);
        do
        {
            start_index = s.find_last_of(" ", end_index);
            auto word = s.substr(start_index+1, end_index-start_index);
            word.push_back(' ');
            to_return += word;
            end_index = s.find_last_not_of(" ", start_index);
        } while (end_index != string::npos);

        to_return.pop_back();
        return to_return;
    }
};

class Solution_v1
{
public:
    string reverseWords(string s) 
    {
        string to_return;
        
        auto end_index = 0;
        auto start_index = s.find_first_not_of(" ", end_index);
        do
        {
            end_index = s.find_first_of(" ", start_index); // In [start_index, size()-1].
            // Get [start_index, end_index-start_index).
            //  If end_index == npos, it stops at the end of the string.
            auto word = s.substr(start_index, end_index-start_index); 
            to_return = word + " " + to_return;
            start_index = s.find_first_not_of(" ", end_index);
        } while (start_index != string::npos);

        to_return.pop_back();
        return to_return;
    }
};

// "  hello  world  "