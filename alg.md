# 競技プログラミング用tips (アルゴリズム)

## 頻出データ構造とアルゴリズム
### 二分探索
関数呼び出しすればOK  
探したい値**以上**なのか**より大きい**なのか考える必要がある

### 深さ優先探索 (DFS)
stackに入れてループ回せばOK

### 幅優先探索 (BFS)
ある位置から特定の距離以内全列挙したい時に便利（辺のコストが異なる場合はダイクストラを用いる必要がある）  
queueを使ってループを回せばOK

## 動的計画法 (DP)
明示的に順番を示しにくいときはメモ化再帰の形で解くと良い

### ダイクストラ法
priority queueを使ってループを回せばOK  

### ワーシャルフロイド法
三重ループ

### 最小全域木構築
+ プリム法：ダイクストラ的に貪欲に構築
+ クラスカル法：unionfindを用いて閉路が無いように貪欲に構築

### 高速な素数判定法
+ 判定先の数の平方根に比例

### べき乗を高速に計算する手法
+ 二乗を繰り返す
+ mintに実装済み

### 逆元を計算する手法
+ フェルマーの小定理
+ mintに実装済み

### 累積和
+ 複数クエリが投げられるタイプはこれが多い
+ 二次元累積和、三角形に対する累積和などが存在

### union find
+ 同一グループを効率よく管理
+ ライブラリ化済み

### 座標圧縮
+ 同じ軸に対して全座標点を列挙して、位置と順番を保存する
+ 検索時は二分探索で座標から位置を再特定 or テーブルを持つ
+ 座標系全体に対して点の数が非常に少ない場合に有効

### 半分全列挙


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

## 数学知識
+ 数え上げ[(写像12相)](https://qiita.com/drken/items/f2ea4b58b0d21621bd5)
    + 重複組み合わせ
    + 完全順列
    + 攪乱順列
    + 包除原理

## 計算量の目安
N=1e6程度ならO(N)が通る。1e7は怪しい。[詳細](https://cppx.hatenablog.com/entry/2017/08/06/104144)

## 引用
+ [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【初級編】](https://qiita.com/e869120/items/f1c6f98364d1443148b3)
+ [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【中級編】](https://qiita.com/e869120/items/eb50fdaece12be418faa)
+ [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【上級編】](https://qiita.com/e869120/items/acba3dd8649d913102b5)
+ [計算量の話](https://cppx.hatenablog.com/entry/2017/08/06/104144)
+ [三分探索](http://kyopro.hateblo.jp/entry/2019/04/25/134128)
+ [DPまとめコンテスト](https://atcoder.jp/contests/dp)