long long minimax(int depth, long long alpha, long long beta, int player, int& x, int& y)
{
    long long val = evaluation(player); 
    if (depth == 0 || abs(val) >= 1e8) 
        return val; 

    if (player == 1)
    {
        long long maxEval = (long long)-1e11;
        vector<ii> a(Neighbor.begin(), Neighbor.end());
        for (const ii& tmp : a)
        {
            int i = tmp.F, j = tmp.S;
            if (status[i][j].opt == 0)
            {
                status[i][j].opt = 1; 
                long long eval = minimax(depth - 1, alpha, beta, -1, x, y); 
                status[i][j].opt = 0;
                if (maxEval < eval)
                {
                    maxEval = eval;
                    if (depth == maxDepth) x = i, y = j;
                }
                if (alpha < eval) alpha = eval;
                if (beta <= alpha) 
                    break;
            }
        }
        return maxEval;
    }
    else 
    {
        long long minEval = (long long)1e11;
        vector<ii> a(Neighbor.begin(), Neighbor.end());
        for(const ii &tmp : a)
        {
            int i = tmp.F, j = tmp.S;
            if (status[i][j].opt == 0)
            {
                status[i][j].opt = -1;
                long long eval = minimax(depth - 1, alpha, beta, 1, x, y);
                status[i][j].opt = 0;
                if (minEval > eval)
                {
                    minEval = eval;
                    if (depth == maxDepth) x = i, y = j;
                }
                if (beta > eval) beta = eval;
                if (beta <= alpha)
                    break;
            }
        }
        return minEval;
    }
}