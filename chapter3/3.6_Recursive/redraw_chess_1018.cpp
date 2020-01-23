//
//  main.cpp
//  algorithm_chess
//
//  Created by 김윤상 on 20/01/2020.
//  Copyright © 2020 김윤상. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int *count(char **board, int size)
{
    char bw[2][2] = {
        {'B', 'W'},
        {'W', 'B'}};

    char wb[2][2] = {
        {'W', 'B'},
        {'B', 'W'}};
    
    int *correct = new int[2];
    int *correct1;
    int *correct2;
    int *correct3;
    int *correct4;

    int bw_correct = 0;
    int wb_correct = 0;
    
    if (size <= 2)
    {
        for(int i =0;i<2;i++){
            for(int j = 0; j<2; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (bw[i][j] == board[i][j])
                {
                    bw_correct++;
                }
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (wb[i][j] == board[i][j])
                {
                    wb_correct++;
                }
            }
        }
        int *c = new int[2];
        c[0] = bw_correct;
        c[1] = wb_correct;
        return c;
    }
    else
    {
        char **board1 = new char *[size / 2];
        char **board2 = new char *[size / 2];
        char **board3 = new char *[size / 2];
        char **board4 = new char *[size / 2];
        for (int i = 0; i < size / 2; i++)
        {
            board1[i] = new char[size / 2];
            board2[i] = new char[size / 2];
            board3[i] = new char[size / 2];
            board4[i] = new char[size / 2];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i < size / 2 && j < size / 2)
                    board1[i][j] = board[i][j];
                else if (i < size / 2 && j >= size / 2)
                    board2[i][j - size / 2] = board[i][j];
                else if (i >= size / 2 && j < size / 2)
                    board3[i - size / 2][j] = board[i][j];
                else if (i >= size / 2 && j >= size / 2)
                    board4[i - size / 2][j - size / 2] = board[i][j];
            }
        }
        correct1 = count(board1, size / 2);
        correct2 = count(board2, size / 2);
        correct3 = count(board3, size / 2);
        correct4 = count(board4, size / 2);
        correct[0] = (correct1[0] + correct2[0] + correct3[0] + correct4[0]);
        correct[1] = (correct1[1] + correct2[1] + correct3[1] + correct4[1]);
        return correct;
    }
    
}

int changeColor(char **chessboard, int row, int col)
{

    char **board = new char *[8];
    for (int i = 0; i < 8; i++)
    {
        board[i] = new char[8];
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = chessboard[i + row][j + col];
        }
    }
    int *correct;
    correct = count(board, 8);
    int bw = correct[0];
    int wb = correct[1];
    if (bw > wb)
        return 64 - bw;
    else
        return 64 - wb;
}



int main()
{

    cout << "입력" << endl;
    int row;
    int col;
    cin >> row;
    cin >> col;

    char **chessboard = new char *[row];
    for (int i = 0; i < row; i++)
    {
        chessboard[i] = new char[col];
    }

    int bw = 0;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bw = rand() % 2;
            if (bw == 0)
            {
                chessboard[i][j] = 'B';
            }
            else
            {
                chessboard[i][j] = 'W';
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << chessboard[i][j];
        }
        cout << endl;
    }

    cout << "시작" << endl;

    cout << endl;
    cout << "출력" << endl;
    int change = 10000000;
    for (int i = 0; i < row - 7; i++)
    {
        for (int j = 0; j < col - 7; j++)
        {
            int temp = 0;
            if (change > (temp = changeColor(chessboard, i, j)))
                change = temp;
        }
    }
    cout << change << endl;
    return 0;
}


