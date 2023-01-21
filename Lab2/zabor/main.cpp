#include <vector>
#include <iostream>
using namespace std;

void merge(vector<pair<int,int>> &vec, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int,int>> L;
    vector<pair<int,int>> R;

    for (i = 0; i < n1; i++)
        L.push_back(vec[left+i]);
    for (j = 0; j < n2; j++)
        R.push_back(vec[mid+1+j]);
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<pair<int,int>> &vec, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        vec.push_back({a, b});
    }


    int right = 0;
    mergeSort(vec, 0, n - 1);
    int cnt = 0;
    cnt += (vec[0].second - vec[0].first + 1);
    right = vec[0].second;
    //cout << 0  << "  cnt : " << cnt  << " added " << (vec[0].second - vec[0].first + 1) <<  endl;
    for (int i = 1; i < n; i++) {
        if (vec[i].first > right) {
            //    cout << 1  << "  cnt : " << cnt  << " added " << (vec[i].second - vec[i].first + 1) <<  endl;
            cnt += (vec[i].second - vec[i].first + 1);
            right = vec[i].second;
        } else if (vec[i].first == right) {
            //    cout << 2  << "  cnt : " << cnt  << " added " << (vec[i].second - right) <<  endl;
            cnt += (vec[i].second - right);
            right = vec[i].second;
        } else {
            if ((right - vec[i].first) > 0 && vec[i].second >= right) {
                //    cout << 3 << "  cnt : " << cnt  << " added " << (vec[i].second - right) <<  endl;
                cnt += (vec[i].second - right);
                right = vec[i].second;
            }
            //else
            //    cout << "lol" << "  cnt : " << cnt  << endl;
        }
    }
    cout << cnt;

}