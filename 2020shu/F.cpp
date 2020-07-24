/*
 * @Date         : 2020-04-18 12:38:10
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, y, m, _d;
int day(int year, int month, int d)
{
    if (month < 3)
        year--, month += 12;
    int c = year / 100;
    int y = year - c * 100;
    int week = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + d - 1;
    week = (week + 7) % 7;
    return week;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> y >> m >> _d;
        if (m < 5) {
            int _day = 1;
            int d = day(y, 5, 1);
            while (d % 7) {
                _day++;
                d++;
                d %= 7;
            }
            _day += 7;
            printf("Mother's Day: May %d", _day);
            if (_day % 10 == 1 && (_day <= 10 || _day >= 20))
                printf("st, %d\n", y);
            else if (_day % 10 == 2 && (_day <= 10 || _day >= 20))
                printf("nd, %d\n", y);
            else if (_day % 10 == 3 && (_day <= 10 || _day >= 20))
                printf("rd, %d\n", y);
            else
                printf("th, %d\n", y);
        }
        else if (m > 6) {
            int _day = 1;
            y++;
            int d = day(y, 5, 1);
            while (d % 7) {
                _day++;
                d++;
                d %= 7;
            }
            _day += 7;
            printf("Mother's Day: May %d", _day);
            if (_day % 10 == 1 && (_day <= 10 || _day >= 20))
                printf("st, %d\n", y);
            else if (_day % 10 == 2 && (_day <= 10 || _day >= 20))
                printf("nd, %d\n", y);
            else if (_day % 10 == 3 && (_day <= 10 || _day >= 20))
                printf("rd, %d\n", y);
            else
                printf("th, %d\n", y);
        }
        else if (m == 5) {
            int _day = 1;
            int d = day(y, 5, 1);
            while (d % 7) {
                _day++;
                d++;
                d %= 7;
            }
            _day += 7;
            if (_d >= _day) {
                _day = 1;
                d = day(y, 6, 1);
                while (d % 7) {
                    _day++;
                    d++;
                    d %= 7;
                }
                _day += 14;
                printf("Father's Day: June %d", _day);
                if (_day % 10 == 1 && (_day <= 10 || _day >= 20))
                    printf("st, %d\n", y);
                else if (_day % 10 == 2 && (_day <= 10 || _day >= 20))
                    printf("nd, %d\n", y);
                else if (_day % 10 == 3 && (_day <= 10 || _day >= 20))
                    printf("rd, %d\n", y);
                else
                    printf("th, %d\n", y);
            }
            else {
                printf("Mother's Day: May %d", _day);
                if (_day % 10 == 1 && (_day <= 10 || _day >= 20))
                    printf("st, %d\n", y);
                else if (_day % 10 == 2 && (_day <= 10 || _day >= 20))
                    printf("nd, %d\n", y);
                else if (_day % 10 == 3 && (_day <= 10 || _day >= 20))
                    printf("rd, %d\n", y);
                else
                    printf("th, %d\n", y);
            }
        }
        else {
            int _day = 1;
            int d = day(y, 6, 1);
            while (d % 7) {
                _day++;
                d++;
                d %= 7;
            }
            _day += 14;
            if (_d >= _day) {
                y++;
                _day = 1;
                d = day(y, 5, 1);
                while (d % 7) {
                    _day++;
                    d++;
                    d %= 7;
                }
                _day += 7;
                printf("Mother's Day: May %d", _day);
                if (_day % 10 == 1 && (_day <= 10 || _day >= 20))
                    printf("st, %d\n", y);
                else if (_day % 10 == 2 && (_day <= 10 || _day >= 20))
                    printf("nd, %d\n", y);
                else if (_day % 10 == 3 && (_day <= 10 || _day >= 20))
                    printf("rd, %d\n", y);
                else
                    printf("th, %d\n", y);
            }
            else {
                printf("Father's Day: June %d", _day);
                if (_day % 10 == 1 && (_day <= 10 || _day >= 20))
                    printf("st, %d\n", y);
                else if (_day % 10 == 2 && (_day <= 10 || _day >= 20))
                    printf("nd, %d\n", y);
                else if (_day % 10 == 3 && (_day <= 10 || _day >= 20))
                    printf("rd, %d\n", y);
                else
                    printf("th, %d\n", y);
            }
        }
    }
}