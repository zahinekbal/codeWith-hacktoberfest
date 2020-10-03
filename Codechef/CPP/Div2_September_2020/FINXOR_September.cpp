#include <iostream>

using namespace std;

int main()
{

    int t, b, answer;

    cin >> t;

    long long int arr[21];
    arr[0] = 1;

    for (int i = 1; i < 21; i++)
        arr[i] = 2 * arr[i - 1];

    while (t--)
    {
        long long int n, s, summ, summm, final;
        cin >> n;
        cout << 1 << " " << arr[20] << endl;
        cout.flush();
        cin >> s;
        s -= arr[20] * n;
        final = 0;
        if (s % 2 != 0)
            final++;
        for (int i = 1; i < 20; i++)
        {
            summ = s + (arr[i] * n);
            cout << 1 << " " << arr[i] << endl;
            cout.flush();
            cin >> summm;
            if (((summ - summm) / (arr[i] * 2)) % 2 != 0)
                final += arr[i];
        }
        cout << 2 << " " << final << endl;
        cout.flush();
        
        cin >> answer;
        
        if (answer == -1)
            break;
    }
}