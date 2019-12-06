syntax on "自动语法高亮

set ts=4 "Tab width
set expandtab
set autoindent

winpos 5 5 " 设定窗口位置

set lines=40 columns=155 " 设定窗口大小

set nu " 显示行号

set go= " 不要图形按钮

"color asmanian2 " 设置背景主题

set guifont=Courier_New:h10:cANSI " 设置字体

"syntax on " 语法高亮

autocmd InsertLeave * se nocul " 用浅色高亮当前行

autocmd InsertEnter * se cul " 用浅色高亮当前行

set ruler " 显示标尺

set showcmd " 输入的命令显示出来，看的清楚些

"set cmdheight=1 " 命令行（在状态行下）的高度，设置为1

"set whichwrap+=<,>,h,l " 允许backspace和光标键跨越行边界(不建议)

"set scrolloff=3 " 光标移动到buffer的顶部和底部时保持3行距离

set novisualbell " 不要闪烁(不明白)

set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")} "状态行显示的内容

set laststatus=1 " 启动显示状态行(1),总是显示状态行(2)

set foldenable " 允许折叠

set foldmethod=manual " 手动折叠

"set background=dark "背景使用黑色

set nocompatible "去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限

" 显示中文帮助

if version >= 603

 set helplang=cn

 set encoding=utf-8

endif

" 设置配色方案

"colorscheme murphy

"字体

"if (has("gui_running"))

" set guifont=Bitstream\ Vera\ Sans\ Mono\ 10

"endif

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""新文件标题""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"新建.c,.h,.sh,.java文件，自动插入文件头
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
""定义函数SetTitle，自动插入文件头
func SetTitle()
  "如果文件类型为.sh文件
  if &filetype == 'sh'
    call setline(1,"\#########################################################################")
    call append(line("."), "\# File Name: ".expand("%"))
    call append(line(".")+1, "\# Author: phd")
    call append(line(".")+2, "\# mail: panhd@neusoft.com")
    call append(line(".")+3, "\# Created Time: ".strftime("%c"))
    call append(line(".")+4, "\#########################################################################")
    call append(line(".")+5, "\#!/bin/bash")
    call append(line(".")+6, "")
  else
    call setline(1, "/*************************************************************************")
    call append(line("."), "  > File Name: ".expand("%"))
    call append(line(".")+1, "  > Author: phd")
    call append(line(".")+2, "  > Mail: panhd@neusoft.com ")
    call append(line(".")+3, "  > Created Time: ".strftime("%c"))
    call append(line(".")+4, " ************************************************************************/")
    call append(line(".")+5, "")
  endif
  if &filetype == 'cpp'
    call append(line(".")+6, "#include<iostream>")
    call append(line(".")+7, "using namespace std;")
    call append(line(".")+8, "")
  endif
  if &filetype == 'c'
    call append(line(".")+6, "#include<stdio.h>")
    call append(line(".")+7, "")
  endif
  "新建文件后，自动定位到文件末尾
  autocmd BufNewFile * normal G
endfunc

