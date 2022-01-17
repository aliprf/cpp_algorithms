#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

pair<int, string> insetPair(string name, int cnt);
void initVector(vector<pair<int, string>> &inp);
void createOptSet(map<int, string> &setMap);
void getMapItem(map<int, string> &setMap, int *fcnt, string *sset);
void insertToMap(map<int, string> &setMap, int sum, string sets);

int main()
{
    // the best way to merge lists
    vector<pair<int, string>> pairWithLenght;
    initVector(pairWithLenght);
    ///
    map<int, string> setMap;
    for (int i = 0; i < pairWithLenght.size(); i++)
        setMap.insert(pair<int, string>(pairWithLenght[i].first, pairWithLenght[i].second));

    //
    createOptSet(setMap);
    return -1;
}

void createOptSet(map<int, string> &setMap)
{
    while (setMap.size() > 1)
    {
        // merge the first two:
        int fcnt;
        string fset;
        getMapItem(setMap, &fcnt, &fset);

        int scnt;
        string sset;
        getMapItem(setMap, &scnt, &sset);

        //
        int sum = fcnt + scnt;
        string sets = "{" + fset + ", " + sset + "}";
        insertToMap(setMap, sum, sets);
        //
    }
}

void getMapItem(map<int, string> &setMap, int *fcnt, string *fset)
{
    auto it = setMap.begin();
    *fcnt = it->first;
    *fset = it->second;
    setMap.erase(setMap.begin());
}

void insertToMap(map<int, string> &setMap, int sum, string sets)
{
    setMap.insert(pair<int, string>(sum, sets));
}

pair<int, string> insetPair(string name, int cnt)
{
    pair<int, string> item;
    item.first = cnt;
    item.second = name;
    return item;
}

void initVector(vector<pair<int, string>> &inp)
{
    vector<string> names = {"A", "B", "C", "D", "E", "F"};
    vector<int> lens = {9, 3, 33, 2, 7, 6};
    for (int i = 0; i < names.size(); i++)
    {
        inp.push_back(insetPair(names[i], lens[i]));
    }
}