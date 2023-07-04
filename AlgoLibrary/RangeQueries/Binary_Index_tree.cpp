template <class T>
class BIT
{
    static_assert(is_integral<T>::value, "Integer required");

private:
    const size_t N;
    vector<T> data;

public:
    // Binary indexed tree or fenwick tree
    // O (log n) all operations except order
    // order complexity - O (log n)
    // 1 based indexing
    BIT() : N(0) {}
    BIT(const size_t _N) : N(_N), data(_N + 1) {}

    size_t size()
    {
        return N;
    }
    // sum of [1, idx]
    // range sum query
    T sum(size_t idx)
    {
        T ans = 0;
        for (; idx > 0; idx -= (idx & -idx))
        {
            ans += data[idx];
        }
        return ans;
    }
    T sum(size_t l, size_t r)
    {
        return sum(r) - sum(l - 1);
    }

    // Point update
    void add(size_t idx, T val)
    {
        for (; idx <= N; idx += (idx & -idx))
        {
            data[idx] += val;
        }
    }

    // Range update
    void range_add(size_t l, size_t r, T val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    template <class OStream>
    friend OStream &operator<<(OStream &os, BIT &bit)
    {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.N; i++)
        {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
    int order(T sum)
    {
        // find kth smallest element
        // if doesn't exists return 0
        int mxind = 0;
        while (1 << (mxind + 1) <= N)
            mxind++;
        int pos = 0;
        while (mxind >= 0)
        {
            if (pos + (1 << mxind) <= N && data[pos + (1 << mxind)] < sum)
            {
                pos += (1 << mxind);
                sum -= data[pos];
            }
            mxind--;
        }//
        return pos + 1;
    }
    // You can either do one of the following
    // 1. Range update and point query
    // 2. Point update and range query
};
