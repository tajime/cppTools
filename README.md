# C++ Tools
c++でよく使うコードのまとめ

## ファイル読み込み(read.cpp)
ファイル内のデータを読み込み，vector<・>型で保存する．('・'はなんでもよいが，string以外の場合はコードの一部改変が必要)

区切り文字は設定可能．(初期設定は','と' ')


## ファイル書き込み(コードなし)
```
ofstream ofs(filePath);
ofs << "書き込むこと";
```

で書き込み可能

## split
