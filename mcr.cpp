#include <iostream>
using namespace std;

bool isWin(char game[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++)
        if (game[i][0] != ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2])
            return true;

    // Check columns
    for (int j = 0; j < 3; j++)
        if (game[0][j] != ' ' && game[0][j] == game[1][j] && game[1][j] == game[2][j])
            return true;

    // Diagonals
    if (game[1][1] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2])
        return true;
    if (game[1][1] != ' ' && game[0][2] == game[1][1] && game[1][1] == game[2][0])
        return true;

    return false;
}

int main() {
    int i, j;
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool turn = true; // false -> Player 1 (X), true -> Player 2 (O). Start with Player 1.
    bool hasWinner = false;

    cout << "X = Player 1" << endl << "O = Player 2" << endl;

    for (int n = 0; n < 9; n++) {
        turn = !turn; // 切换回合

        cout << (turn ? "Player 2" : "Player 1")
             << ": Which cell to mark? i:[1..3], j:[1..3]: ";
        cin >> i >> j;

        i--; j--; // 转换为 0-based 索引

        // 边界检查
        if (i < 0 || i > 2 || j < 0 || j > 2) {
            cout << "输入无效！请输入 1-3 之间的数字。" << endl;
            n--;
            turn = !turn; // 恢复回合
            continue;
        }

        // 已占用？
        if (game[i][j] != ' ') {
            cout << "该位置已被占用，请重新选择！" << endl;
            n--;
            turn = !turn; // 恢复回合
            continue;
        }

        // 落子
        game[i][j] = turn ? 'O' : 'X';

        // 检查胜利
        if (isWin(game)) {
            cout << (turn ? "Player 2" : "Player 1") << " wins!" << endl;
            hasWinner = true;
            break;
        }
    }

    if (!hasWinner)
        cout << "Tie!" << endl;

    //显示最终棋盘
    cout << "\nFinal Board:\n";
    cout << game[0][0] << " | " << game[0][1] << " | " << game[0][2] << endl;
    cout << "--+---+--" << endl;
    cout << game[1][0] << " | " << game[1][1] << " | " << game[1][2] << endl;
    cout << "--+---+--" << endl;
    cout << game[2][0] << " | " << game[2][1] << " | " << game[2][2] << endl;

    return 0;
