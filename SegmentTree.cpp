#define left (index << 1)
#define right ((index << 1) + 1)
#define mid ((l + r) / 2)

class SegmentTree
{
public:
    int n;
    vector<ll> ar;
    vector<ll> st;
    void build(int index, int l, int r)
    {
        if (l == r)
        {
            st[index] = ar[l];
        }
        else
        {
            build(left, l, mid);
            build(right, mid + 1, r);
            st[index] = max(st[left], st[right]);
        }
    }
    void update(int index, int l, int r, int ind)
    {
        if (ind < l || ind > r)
            return;
        if (l == r)
        {
            st[index] = ar[ind];
        }
        else
        {
            update(left, l, mid, ind);
            update(right, mid + 1, r, ind);
            st[index] = max(st[left], st[right]);
        }
    }
    ll query(int index, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql)
            return LLONG_MIN;
        if (l >= ql && r <= qr)
            return st[index];
        ll x = query(left, l, mid, ql, qr);
        ll y = query(right, mid + 1, r, ql, qr);
        return max(x, y);
    }
    void update(int ind, ll x)
    {
        ar[ind] = x;
        update(1, 0, n - 1, ind);
    }
    ll query(int ql, int qr)
    {
        return query(1, 0, n - 1, ql, qr);
    }
    SegmentTree(vector<ll> a)
    {
        ar = a;
        n = ar.size();
        st = vector<ll>(4*n);
        build(1, 0, n - 1);
    }
    SegmentTree() {}
};
