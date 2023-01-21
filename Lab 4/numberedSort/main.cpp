#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<pair<int, vector<int>>> alph;
vector<vector<char>> text;
vector<vector<char>> ans;
vector<int> indexes;
void RadixSort(int n, int len, int c){
    for (int k = 1; k <= c; k++) {

        for (int i = 0; i < n; i++)
            alph[int(text[indexes[i]][len - k] - 'a')].second.push_back(indexes[i]);

        vector<int> new_indexes;
        for (int i = 0; i < 26; i++) {
            if (alph[i].second.size() != 0) {
                int ind = 0;
                while (alph[i].second.size() != 0) {
                    new_indexes.push_back(alph[i].second[ind]);
                    ind++;
                    alph[i].second.pop_back();
                }
            }
        }

        for (int i = 0; i < new_indexes.size(); i++)
            indexes[i] = new_indexes[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, len, k;
    cin >> n >> len >> k;
    text.resize(n, vector<char> ());
    ans.resize(n, vector<char> (len, 'a'));
    alph.resize(26, pair<int,vector<int>>());
    for (int i = 0; i < n; ++i){
        indexes.push_back(i);
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); ++j){
            text[i].push_back(str[j]);
        }
    }

    RadixSort(n, len, k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < len; j++)
            ans[i][j] = text[indexes[i]][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < len; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}