#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int xx[4] = {-1, 0, 0, 1};
int yy[4] = {0, -1, 1, 0};

void print(vector<vector<char> > &mat)
{
  for( int i = 0 ; i < mat.size() ; ++i )
  {
    for( int j = 0 ; j < mat[i].size() ; ++j )
    {
      cout<<mat[i][j];
    }
    cout<<endl;
  }
}
int bfs(vector<vector<char> > mat, int i, int j) {
  queue<pair<pair<int, int>, int> > q;
  q.push(make_pair(make_pair(i, j), 0));
  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int niv = q.front().second;
    q.pop();

    mat[x][y] = '0';
    for (int i = 0; i < 4; ++i) {
      int nextx = x + xx[i];
      int nexty = y + yy[i];
      if (nextx >= 0 && nexty >= 0 && nextx < mat.size() &&
          nexty < mat[x].size() && mat[nextx][nexty] != '0') {
        // cout<<x<<" "<<y<<" "<<nextx<<" "<<nexty<<endl;
        // print(mat);
        if (mat[nextx][nexty] == '3')
          return niv + 1;
        q.push(make_pair(make_pair(nextx, nexty), niv + 1));
      }
    }
  }
  return -1;
}

int main() {

  int m;
  while (scanf("%d", &m) != EOF) {
    vector<vector<char> > mat(m, vector<char>(m));
    vector<pair<int, int> > pp;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf(" %c", &mat[i][j]);
        if (mat[i][j] == '1')
          pp.push_back(make_pair(i, j));
      }
    }
    // print(mat);
    int may = -99999999;
    for (int i = 0; i < pp.size(); ++i) {
      int temp=bfs(mat,pp[i].first,pp[i].second);
      // cout<<temp<<endl;
      may = max(temp, may);
    }
    printf("%d\n", may);
  }
  return 0;
}
