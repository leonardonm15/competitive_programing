call plug#begin()
Plug 'nanotech/jellybeans.vim', { 'tag': 'v1.7' }
Plug 'vim-airline/vim-airline'
Plug 'tpope/vim-commentary'
Plug 'crusoexia/vim-monokai'
Plug 'tomasr/molokai'
Plug 'luochen1990/rainbow'
Plug 'NLKNguyen/papercolor-theme'
" Plug 'scrooloose/syntastic'

" Initialize plugin system
call plug#end()
set background=dark
colorscheme PaperColor
let g:rainbow_active = 1 "set to 0 if you want to enable it later via :RainbowToggle

set nocompatible
filetype on
syntax on
filetype plugin indent on
set number
set relativenumber
set encoding=utf-8

set wrap
set textwidth=80
set formatoptions=tcqrn1
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab
set noshiftround
set undofile

au BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$") | exe "normal g'\"" | endif

autocmd filetype cpp nnoremap <F2> :r /home/leo/competitive_programing/template.cpp <Return> kdd :11 <Return> o
map <F9> :!g++ -std=c++20 -O2 -fsanitize=address,undefined -o  -g % -o %:r  && ./%:r <CR>
map <F5> :!g++ -std=c++20 -O2 -fsanitize=address,undefined -o  -g % -o %:r <CR>
map <F1> :w <CR>
map <F12> :!gdb ./%:r <CR>
