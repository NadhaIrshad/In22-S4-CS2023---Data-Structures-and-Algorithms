#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);
    for (const auto &q : queries) {
        int l = q[0], r = q[1], value = q[2];
        arr[l] += value;
        if (r + 1 <= n) {
            arr[r + 1] -= value;
        }
    }
    
    long max_val = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        max_val = max(max_val, current);
    }

    return max_val;
}

int main()
{
    // Read the input
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);
    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]); // Size of the array
    int m = stoi(first_multiple_input[1]); // Number of queries

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);
        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);
        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));
        
        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);
            queries[i][j] = queries_row_item;
        }
    }

    // Compute the result
    long result = arrayManipulation(n, queries);

    // Output the result to console
    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
