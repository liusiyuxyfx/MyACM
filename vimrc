set nocp "Bram 爷爷强烈推荐使用 VIM 的不兼容模式                                                                                                                                              
set nu "显示行号
syn on "自动语法高亮
filetype plugin indent on "开启文件类型自动识别，启用文件类型插件，启用针对文件类型的自动缩进
set cin 
set sw=2 "set shiftwidth设定 << 和 >> 命令移动时的宽度为 2
set expandtab "不要tab
set cursorline
set ru "set ruler打开状态栏标尺
set hls "set hlsearch搜索时高亮显示被找到的文本
set showcmd
set lbr "不在单词中间断行
set nobackup "禁止生成临时文件
set noswapfile
set background=dark
set sm "显示括号配对情况
"set mouse=a
"colorscheme solarized
autocmd BufNewFile *.cpp exec ":call SetTitle()"
func SetTitle()
  if &filetype == 'cpp'
    call setline(1, "/*************************************************************************")   
    call append(line("."), "     File Name: ".expand("%"))   
    call append(line(".")+1, "     ID: Liusiyu")   
    call append(line(".")+2, "     BLOG: http://blog.csdn.net/r_o_j ")   
    call append(line(".")+3, "     LANG: C++ ")   
    call append(line(".")+4, "     Mail: 779532360@qq.com ")   
    call append(line(".")+5, "     Created Time: ".strftime("%c"))   
    call append(line(".")+6, " ************************************************************************/")   
    call append(line(".")+7, "#include<bits/stdc++.h>")
    call append(line(".")+8, "#define MEM(a,x) memset(a,x,sizeof(a));") 
    call append(line(".")+9, "#define MEMINF(a) memset(a,0x3f,sizeof(a));") 
    call append(line(".")+10, "using namespace std;") 
    call append(line(".")+11, "typedef long long LL;") 
    call append(line(".")+12, "const int MAXN=205;")
    call append(line(".")+13, "const int INF=0x3f3f3f3f;")  
    call append(line(".")+14, "const int MOD=1000000007;")  
    call append(line(".")+15, "")    
  endif
endfunc

func Run()
  exec "w" 
  if &filetype == 'cpp'
    exec "!g++ -std=c++11 % -o a.exe && ./a.exe < in.txt"
  elseif &filetype == 'python'
    exec "!python %"
  elseif &filetype == 'haskell'
    "exec "!ghc --make % -o hs.exe && ./hs.exe < in.txt"
    exec "!runhaskell % < in.txt"
  endif
endfunc


map <C-K> :call Run()<CR>

