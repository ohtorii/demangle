C/C++のシンボル名をデマングルする秀丸マクロ
========

###デマングル(demangle)できる形式
- GCC v3
- VisualStudio


###動作環境
- 秀丸エディタ ver8以降
- 田楽(でんがく)ＤＬＬ [http://www.ceres.dti.ne.jp/~sugiura/](http://www.ceres.dti.ne.jp/~sugiura/)

###導入方法
下記ファイルを秀丸エディタのマクロディレクトリへコピーしてください、あとは適当にキーアサインしてお使い下さい。

- demangle.exe
- demangle.mac

###スクリーンショット（その１）
- ![demangle hidemaru](http://cdn-ak.f.st-hatena.com/images/fotolife/o/ohtorii/20110730/20110730155951.gif "デマングル 秀丸エディター")

###スクリーンショット（その２）
- ![demangle hidemaru](http://cdn-ak.f.st-hatena.com/images/fotolife/o/ohtorii/20110730/20110730155938.gif "デマングル 秀丸エディター")

###スクリーンショット（その３）
- ![demangle hidemaru](http://cdn-ak.f.st-hatena.com/images/fotolife/o/ohtorii/20110730/20110730155928.gif "demangle hidemaru")

###変換例
- 変換前
_ZN9wikipedia7article6formatEv
St13bad_exception
3barI5emptyLi17EE
?Fxyxy_i@@YAHP6AHH@ZP6AHF@Z01@Z
??1nested@@QAE@XZ
?Fv_v_stdcall@myclass@@QAGXXZ
??4myclass@@QAEAAV0@ABV0@@Z

- 変換後：アウトプット枠へ出力されます
wikipedia::article::format()
std::bad_exception
bar<empty, 17>
int __cdecl Fxyxy_i(int (__cdecl*)(int),int (__cdecl*)(short),int (__cdecl*)(int),int (__cdecl*)(short))
public: __thiscall nested::~nested(void)
public: void __stdcall myclass::Fv_v_stdcall(void)
public: class myclass & __thiscall myclass::operator=(class myclass const &)
