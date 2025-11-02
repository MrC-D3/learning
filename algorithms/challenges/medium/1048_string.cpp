// You are given an array of words where each word consists of lowercase English
//  letters. wordA is a predecessor of wordB if and only if we can insert 
//  exactly one letter anywhere in wordA without changing the order of the other
//  characters to make it equal to wordB. For example, "abc" is a predecessor of
//  "abac", while "cba" is not a predecessor of "bcad". A word chain is a 
//  sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a 
//  predecessor of word2, word2 is a predecessor of word3, and so on. A single 
//  word is trivially a word chain with k == 1. Return the length of the longest
//  possible word chain with words chosen from the given list of words.
// Example : Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"] Output: 5
//  Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
//  "pcxbc", "pcxbcf"].

#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution 
{
public:
    int longestStrChain(vector<string>& words) 
    {
        int longest_chain = 1;
        constexpr int WORD_MAX_LENGTH = 16;
        vector<vector<int>> words_by_size(WORD_MAX_LENGTH, vector<int>{});

        vector<int> longest_chains;
        for (int i = 0; i < words.size(); i++)
        {
            int index = words[i].size() % WORD_MAX_LENGTH;
            words_by_size[index].push_back(i);
            longest_chains.push_back(1);
        }

        for (int current_size = 1; current_size < WORD_MAX_LENGTH; current_size++)
        {
            int next_size = (current_size + 1) % WORD_MAX_LENGTH;
            // Checking for empty words_by_size[current_size] or 
            //  or words_by_size[next_size] doesn't improve.
            for (auto i : words_by_size[current_size])
            {
                for (auto j : words_by_size[next_size])
                {
                    int offset = 0;
                    for (int m = 0; (m-offset < current_size) && (offset < 2); m++)
                    {
                        if (words[i][m-offset] != words[j][m])
                        {
                            offset += 1;
                        }
                    }

                    if ((offset < 2) && (longest_chains[j] < longest_chains[i] + 1))
                    {
                        longest_chains[j] = longest_chains[i] + 1;
                        if (longest_chains[j] > longest_chain)
                        {
                            longest_chain = longest_chains[j];
                        }
                    }
                }
            }
        }

        return longest_chain;
    }

    int longestStrChain_v1(vector<string>& words) 
    {
        int longest_chain{1};
        vector<int> longest_chains(1000, 1);

        sort(words.begin(), words.end(), [](string a, string b){
          return a.size() < b.size();
        });

        int current_size = 0;
        int j, next_size;
        for(int i = 0; i < words.size(); i++)
        {
            if (words[i].size() != current_size)
            {
                current_size = words[i].size();
                next_size = current_size + 1;
                for(j = i + 1; j < words.size(); j++)
                {
                    if (words[j].size() == next_size)
                    {
                        break;
                    }
                }
                if (j == words.size())
                {
                    continue;
                }
            }

            for(int k = j; (k < words.size()) && (words[k].size() == next_size); k++)
            {
                int offset = 0;
                for(int m = 0; (m - offset < current_size) && (offset < 2); m++)
                {
                    if (words[i][m-offset] != words[k][m])
                    {
                        offset += 1;
                    }
                }

                if (offset < 2)
                {
                    if (longest_chains[i] + 1 > longest_chains[k])
                    {
                        longest_chains[k] = longest_chains[i] + 1;
                        if(longest_chains[k] > longest_chain)
                        {
                            longest_chain = longest_chains[k];
                        }
                    }
                }
            }
        }

        return longest_chain;
    }
};
