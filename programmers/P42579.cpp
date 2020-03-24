/*
테스트 케이스 5 ~ 14 실패
*/


#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comparePlays(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}

bool compareGenre(pair<string, vector<pair<int, int> > > &a, pair<string, vector<pair<int, int> > > &b) {
    if (a.second[0].second == b.second[0].second) {
        return a.second[0].first < b.second[0].first;
    }

    return a.second[0].second > b.second[0].second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, vector<pair<int, int> > > albums;
    for (int i = 0; i < genres.size(); i++) {
        if (albums.count(genres[i]) == 0) {
            vector<pair<int, int> > play;
            play.push_back(make_pair(i, plays[i]));
            albums.insert(make_pair(genres[i], play));
        }
        else {
            albums.at(genres[i]).push_back(make_pair(i, plays[i]));
        }
    }

    for (auto it = albums.begin(); it != albums.end(); it++) {
        sort(it->second.begin(), it->second.end(), comparePlays);
    }

    vector<pair<string, vector<pair<int, int> > > > vectorAlbums;
    for (auto it = albums.begin(); it != albums.end(); it++) {
        vectorAlbums.push_back(make_pair(it->first, it->second));
    }

    sort(vectorAlbums.begin(), vectorAlbums.end(), compareGenre);

    for (int i = 0; i < vectorAlbums.size(); i++) {
        vector<pair<int, int> > &p = vectorAlbums[i].second;
        for (int j = 0; j < p.size(); j++) {
            if (j == 2) break;

            answer.push_back(p[j].first);
        }
    }

    return answer;
}