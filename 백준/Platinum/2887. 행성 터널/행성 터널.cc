#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
constexpr int SZ = 1 << 20;
typedef long long ll;

class INPUT {
private:
	char read_buf[SZ];
	int read_idx, next_idx;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in;
}

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT

struct Pos {
    int x, y, z, i;
};
int N;
vector<Pos> p;
vector<vector<pair<int, int>>> edges;

int primMST() {
    vector<int> key(N, INF);
    vector<bool> mstSet(N, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int res = 0;
    pq.push({ 0, 0 }); 
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (mstSet[u]) continue;
        mstSet[u] = 1;
        res += key[u];

        for (auto edge : edges[u]) { 
            int v = edge.second;
            int weight = edge.first;
            if (mstSet[v] == false && key[v] > weight) { 
                key[v] = weight;
                pq.push({ key[v], v });
            }
        }
    }
    return res;
}
int main()
{
    cin >> N;

    p.resize(N);
    edges.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].i = i;
    }

    vector<int> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        x[i] = y[i] = z[i] = i;
    }

    auto compare = [&](int i, int j, auto member) { return member(p[i]) < member(p[j]); };
    auto calc = [&](int i, int j, auto member) {
        int distance = abs(member(p[i]) - member(p[j]));
        edges[i].push_back({ distance, j });
        edges[j].push_back({ distance, i });
    };

    sort(x.begin(), x.end(), [&](int i, int j) { return compare(i, j, [](const Pos& p) { return p.x; }); });
    sort(y.begin(), y.end(), [&](int i, int j) { return compare(i, j, [](const Pos& p) { return p.y; }); });
    sort(z.begin(), z.end(), [&](int i, int j) { return compare(i, j, [](const Pos& p) { return p.z; }); });
    for (int i = 0; i < N - 1; i++) {
        calc(x[i], x[i + 1], [](const Pos& p) { return p.x; });
        calc(y[i], y[i + 1], [](const Pos& p) { return p.y; });
        calc(z[i], z[i + 1], [](const Pos& p) { return p.z; });
    }

    cout << primMST();
    return 0;
}