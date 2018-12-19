class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9) return false;
        for(int i=0;i<9;i++) if(board[i].size()!=9) return false;
        int note[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) note[j]=0;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                note[board[i][j]-'0'-1]+=1;
            }
            for(int j=0;j<9;j++) 
                if(note[j]>1) return false;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) note[j]=0;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                note[board[j][i]-'0'-1]+=1;
            }
            for(int j=0;j<9;j++) 
                if(note[j]>1) return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<9;k++) note[k]=0;
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(board[3*j+a][3*i+b]=='.') continue;
                        note[board[3*j+a][3*i+b]-'0'-1]+=1;
                    }
                }
                for(int j=0;j<9;j++) 
                    if(note[j]>1) return false;
            }
        }
        return true;
    }
};