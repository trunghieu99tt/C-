#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], i, j;
        int ok = 0, notOk = 0;

        // Biến OK sẽ đếm toàn bộ các phần tử nhỏ hơn hoặc bằng k
        // Vì theo yêu cầu của bài toán thì ta cần phải đưa tất cả các phần tử về cạnh nhau
        // Tức là sau khi sắp xếp thì các phần tử <= k sẽ chiếm 1 đoạn có độ dài là OK trong mảng này
        // Thuật toán giải như sau:

        // Bước 1: Đầu tiên nhập, song song với đó là đếm xem có bao nhiêu phần tử  <= k
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= k)
                ok++;
        }

        // Bước 2: Giờ ta sẽ giả định rằng mình sẽ xếp tất cả các phần tử <= k từ vị trí 0 đến vị trí OK
        // => số bước hoán đổi sẽ bằng số phần tử > k trong đoạn này
        for (i = 0; i < ok; i++)
        {
            if (a[i] > k)
                notOk++;
        }

        // Bước 3: Bây giờ ta sẽ "di chuyển" đoạn giả định ban đầu
        // Đoạn đầu tiên của ta là : 0... ok
        // Đoạn tiếp theo là : 1...ok + 1
        // Cứ thế cứ thế
        // Mỗi lần di chuyển ta lại update số lần hoán đổi để thỏa mãn yêu cầu bài toán (thực ra nó chính = số
        // các phần tử > k trong đoạn này)
        int ans = notOk;
        for (int i = 0, j = ok; j < n; i++, j++)
        {
            if (a[i] > k)
                notOk--;
            if (a[j] > k)
                notOk++;
            ans = min(ans, notOk);
        }
        cout << ans << endl;
    }
}

/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    solve();
    return 0;
}