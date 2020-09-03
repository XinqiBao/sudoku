/*
 * A new method to solve the puzzles,
 * more nice orgnized, and more efficent I suppose.
 * (at least compared to my original one)
 *
 * this one take puzzles and std input,
 * an example puzzle could be found below:
 *      0 0 0 2 6 0 7 0 1
 *      6 8 0 0 7 0 0 9 0
 *      1 9 0 0 0 4 5 0 0
 *      8 2 0 1 0 0 0 4 0
 *      0 0 4 6 0 2 9 0 0
 *      0 5 0 0 0 3 0 2 8
 *      0 0 9 3 0 0 0 7 4
 *      0 4 0 0 5 0 0 3 6
 *      7 0 3 0 1 8 0 0 0
 *
 * after calculation, the correct output should be:
 *      +------+------+-----
 *      |4 3 5 |2 6 9 |7 8 1
 *      |6 8 2 |5 7 1 |4 9 3
 *      |1 9 7 |8 3 4 |5 6 2
 *      +------+------+-----
 *      |8 2 6 |1 9 5 |3 4 7
 *      |3 7 4 |6 8 2 |9 1 5
 *      |9 5 1 |7 4 3 |6 2 8
 *      +------+------+-----
 *      |5 1 9 |3 2 6 |8 7 4
 *      |2 4 8 |9 5 7 |1 3 6
 *      |7 6 3 |4 1 8 |2 5 9
 *
 * Yet, the core computing part is still a kind of brute force,
 * which is more intutive to implement.
 * It might be implemented to my CheaterHub project in the future,
 * but I'm getting really frustrated by 81 boxes in UI design.
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> ori(9, vector<int>(9));
    vector<pair<int, int>> todo;
    int cur = 0;

    // Another idea, is pre-generate checking list
    // for each blank box in the puzzle,
    // it should save some runtime for less checking.
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> ori[i][j];
            if(!ori[i][j])
                todo.push_back({i, j});
        }
    }

    cout << "********************" << endl;

    while(cur < todo.size())
    {
        int x = todo[cur].first;
        int y = todo[cur].second;
        vector<bool> check(10, false);

        // TODO: there are 6 overlapping checks,
        // including (x, y) itself twice.
        // column
        for(int i = 0; i < 9; i++)
            check[ori[i][y]] = true;
        // row
        for(int j = 0; j < 9; j++)
            check[ori[x][j]] = true;
        // 9x9 box
        int ibase = x / 3 * 3;
        int jbase = y / 3 * 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                check[ori[i+ibase][j+jbase]] = true;

        int k = ori[x][y] + 1;
        for(; k < 10; k++)
            if(!check[k]) break;

        if(k > 9)
        {
            ori[x][y] = 0;
            cur--;
            continue;
        }
        else
        {
            ori[x][y] = k;
            cur++;
        }
    }

    for(int i = 0; i < 9; i++)
    {
        if(i%3 == 0) cout << "+------+------+-----" << endl;
        for(int j = 0; j < 9; j++)
        {
            if(j%3 == 0) cout << "|";
            cout << ori[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
