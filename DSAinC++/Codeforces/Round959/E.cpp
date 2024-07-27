#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_QUERY = 3;

// Function to query the hash value of a string s
int queryHash(const string &s)
{
    cout << "? " << s << endl;
    cout.flush();

    int hashValue;
    cin >> hashValue;

    return hashValue;
}

// Function to calculate the ord value of a character
int charOrdinal(char c)
{
    return c - 'a';
}

// Function to solve for a single test case
void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p, m;
        cin >> p >> m;

        // We can query up to 3 different strings
        vector<string> queries = {"aa", "ab", "zy"};
        vector<int> hashValues;

        for (const string &query : queries)
        {
            int hashValue = queryHash(query);
            hashValues.push_back(hashValue);
        }

        // Now let's try to find p and m based on these hash values
        for (int candidateP = 27; candidateP <= 50; ++candidateP)
        {
            bool valid = true;
            for (int candidateM = p + 2; candidateM <= 2e9; ++candidateM)
            {

                for (int i = 0; i < MAX_QUERY; ++i)
                {
                    int expectedHash = hashValues[i];
                    int actualHash = 0;
                    const string &query = queries[i];

                    for (int j = 0; j < query.size(); ++j)
                    {
                        actualHash = (actualHash * candidateP + charOrdinal(query[j])) % candidateM;
                    }

                    if (actualHash != expectedHash)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    cout << "! " << candidateP << " " << candidateM << endl;
                    cout.flush();
                    break;
                }
            }

            if (valid)
            {
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
