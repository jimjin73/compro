# 競技プログラミング用tips (アルゴリズム)

## 頻出データ構造とアルゴリズム
+ 全探索
+ 二分探索
+ 深さ優先探索 (DFS)
+ 幅優先探索 (BFS)
+ 動的計画法 (DP)
+ ダイクストラ法
+ ワーシャルフロイド法
+ クラスカル法
+ 高速な素数判定法
+ べき乗を高速に計算する手法
+ 逆元を計算する手法
+ 累積和
+ union find
+ 座標圧縮
+ 半分全列挙
+ 行列累乗
+ ダブリング
+ Grundy数
+ Rolling Hash
+ 平方分割
+ 最大流
+ 最小カット
+ 二部グラフ判定
+ 二部マッチング
+ Binary Indexed Tree
+ セグメント木
### 三分探索
凸関数の最小値を求めるのに利用可能
区間を3つにわけ、最小値が入っていない区間1つを除外していく
3つに分けた際の境界値を見れば判別可能
[詳細](http://kyopro.hateblo.jp/entry/2019/04/25/134128)


## 計算量の目安
N=1e6程度ならO(N)が通る。1e7は怪しい。[詳細](https://cppx.hatenablog.com/entry/2017/08/06/104144)

## 引用
+ [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【初級編】](https://qiita.com/e869120/items/f1c6f98364d1443148b3)
+ [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【中級編】](https://qiita.com/e869120/items/eb50fdaece12be418faa)
+ [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【上級編】](https://qiita.com/e869120/items/acba3dd8649d913102b5)
+ [計算量の話](https://cppx.hatenablog.com/entry/2017/08/06/104144)
+ [三分探索](http://kyopro.hateblo.jp/entry/2019/04/25/134128)