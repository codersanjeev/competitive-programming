#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Player {
    int score;
    string name;
};

bool comp(Player p1, Player p2) {
    if (p1.score > p2.score) return true;
    if (p1.score == p2.score) return p1.name < p2.name;
    return false;
}
vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), comp);
    return players;
}

bool compare(Player a, Player b) {
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<Player> players;
    string name;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for (int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}