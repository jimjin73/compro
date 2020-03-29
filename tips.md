# 競技プログラミング用tips

## Standard Template Library
### データ構造
#### 配列
初期化
```
vector<int> v(10)    // 長さ10
vector<int> v(10,5)  // 長さ10で初期値5
```
操作
```
v.push_back(n) // 配列の延長
v1.insert(v1.begin(), v2.begin(), v2.end()) // 配列の連結
```

#### 文字列
初期化
```
string s
```
操作
```
s = s1 + s2        // 連結
s.substr(i,k)      // i番目からk文字の部分文字列
s.find(t)          // tが含まれる場合その先頭アドレス　含まれないならs.nopsが返り値
s.replace(i,k,t)   // i番目以降k文字をtで置換する　tを空文字列にすれば削除
s.insert(i,t)      // i番目とi+1番目の文字の間にtを挿入
```

#### FIFOキュー
初期化
```
queue<type> q
```
操作
```
q.front() // キューの先頭の要素取得
q.back()  // キューの最後の要素取得
q.push(n)  // キューに値を入れる
q.pop()   // キューの先頭要素を削除する
q.empty() // キューが空かどうか判定する
```

#### リスト
初期化
```
list<type> l
list<int>::iterater p
list<int>::reverse_iterater r
```
操作
```
for (p=li.begin(); p!=li.end(); p++)   *p   // 前から走査
for (r=li.rbegin(); r!=li.rend(); r++) *r   // 後ろから走査
li.push_front() //先頭に挿入
li.front()      //先頭の要素を参照
li.pop_front()  //先頭の要素を削除
li.push_back(n) //末尾にnを挿入
li.back()       //末尾の要素を参照
li.pop_back()   //末尾の要素を削除
li.insert(p, n) //pのさす要素の直前にnを挿入
li.erase(p)     //pの指す要素を削除
li.erase(p, q)  //pの指す要素からqの指す要素まで削除
```

#### 双方向キュー
初期化
```
deque<type> d
```
操作
```
d.push_front(n)  //先頭に挿入
d.front()        //先頭の要素を参照
d.pop_front()    //先頭の要素を削除
d.push_back(n)   //末尾に挿入
d.back()         //末尾の要素を参照
d.pop_back()     //末尾の要素を削除
```

#### 優先度付きキュー
初期化
```
priority_queue<type>
priority_queue<type, vector<type>, greater<type>> // 降順
```
[詳細](https://cpprefjp.github.io/reference/queue/priority_queue.html)

操作
```
que.push(n) // 要素の追加
que.top()   // 先頭をみる
que.pop()   // 先頭を削除
```

#### LIFOスタック
初期化
```
stack<type> s
```
操作
```
s.back()        // 最後の値参照
s.push_back(n)  // 値挿入
s.pop_back()    // 値削除
```

#### ペア
初期化
```
pair<type type> p
```
操作
```
p.first
p.second
```

#### 辞書 (map)
初期化
```
unorderd_map<key_type, value_type> um  // multimapはググる
```
操作
```
um[k] = v    //要素にアクセス
um.find(v)   //要素へのイテレーターを返す．なければm.end()を返却
um.erase(p)  //イテレーターの指す要素を削除
unordered_map<key_type, value_type>::iterator p            //イテレーターを用いた走査
for (p=um.begin(); p!=um.end(); p++)  p->first, p->second  // keyとvalue全列挙
```

#### 集合 (set)
初期化
```
unordered_set<type> s        // ハッシュテーブルで管理される(通常のsetは平衡二分探索木)
unordered_multiset<type> ms  // 要素の重複を許可(要素の個数がわかる)
```
操作
```
s.insert(n) //要素の追加
s.erase(n)  //要素の削除
s.find(n)   //発見したらその要素へのイテレータを返す
s.count(n)  //要素の数を返す (multisetの時に使う)
s.empty()   //空ならtrue
```

### STLの操作
#### イテレータ
vector内のitemを全列挙
```
for(const auto& e : v) e
```

#### 最大値、最小値
```
min(a, b)
max(a, b)
```

#### 入れ替え
```
swap(a, b)
```

#### 並び替え
```
sort(v.begin(), v.end())                    // 小さいのが先
sort(v.begin(), v.end(), greater<type>())   // 大きいのが先
```

#### 要素数
```
v.size()
```

#### 二分探索
```
binary_search(v.begin(), v.end(), x)  //trueかfalseを返す
lower_bound(v.begin(), v.end(), x)    //x以上の値が初めて現れる位置のイテレータを返す
upper_bound(v.begin(), v.end(), x)    //xより大きい値が初めて現れる位置のイテレータを返す
equal_range(v.begin(), v.end(), x)    //上記2カ所のイテレータのペアを返す
```
[詳細](https://pyteyon.hatenablog.com/entry/2019/02/20/194140)

#### 重複削除
```
v.erase(unique(v.begin(),v.end()), v.end())
```
unique関数は**隣り合った**重複要素を詰めて、戻り値として終端ポインタを返す。erase関数で、余分な要素を削除できる。
#### 空にする
```
v.clear()
```


## 型
### 数値の扱い
#### long long
+ intが約2e9程度まで扱えるのに対して、こちらは約9e18程度まで扱える
+ よく使う省略記法
```
typedef long long ll;
```

#### double
+ 値を出力する際に何桁表示するか明記したほうが良い
**TODO:ここ書く**
#### 構造体定義

## 頻出アルゴリズム
+ 

## 計算量の目安
N=1e6程度ならO(N)が通る。1e7は怪しい。[詳細](https://cppx.hatenablog.com/entry/2017/08/06/104144)
