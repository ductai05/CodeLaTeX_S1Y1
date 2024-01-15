void displayWinLine() 
{
#define getVal(i) status[winLine[i].F][winLine[i].S].opt
    
    for (int i = 0; i < winLine.size(); i++)
    {
        if (abs(getVal(i)) == 1) 
        {
            int j = i;
            while (j + 1 < (int)winLine.size() - 1 && getVal(i) == getVal(j + 1)) j++;
            int len = j - i + 1;
            if (len >= 5) 
            {
                for (int T = 0; T < 3; T++) 
                {
                    for (int k = i; k <= j; k++) 
                    {
                        int XX = status[winLine[k].F][winLine[k].S].X;
                        int YY = status[winLine[k].F][winLine[k].S].Y;
                        gotoXY(XX - 1, YY);
                        setColor(getVal(k) == 1 ? 4 : 1, 15);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(500);
                    for (int k = i; k <= j; k++) 
                    {
                        int XX = status[winLine[k].F][winLine[k].S].X;
                        int YY = status[winLine[k].F][winLine[k].S].Y;
                        gotoXY(XX - 1, YY);
                        setColor(15, getVal(k) == 1 ? 4 : 1);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(300);
                }
                return;
            }
        }
    }
}
//_____________________________________________________//
ShowCur(0);
displayWinLine();

drawPopUp(XX - 27, YY + 3, 16, 74);
decorate_draw(XX - 24, YY + 3, "pixel_art/Cup.txt");
if (Turn == -1)
    drawX_WIN(XX + 6, YY + 7), Xscore++;
else if(Turn == 1) 
    drawO_WIN(XX + 6, YY + 7), Oscore++;
else drawDRAW(XX + 7, YY + 7);

gotoXY(XX + 5 - (Turn == -1), YY + 13);
for (int i = 0; i < 38; ++i)
    cout << char(196);

gotoXY(XX + 5 - (Turn == -1), YY + 14);
setColor(15, 8);  cout << "<< Press Y to continue or N to exit >>";
setColor(15, 0);