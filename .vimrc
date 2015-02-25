call pathogen#infect()

syntax on
filetype plugin indent on
set number
set noswapfile
set tabstop=4
set shiftwidth=4
set ignorecase
set hlsearch
set smartindent
set expandtab
set mouse=a

let NERDTreeShowHidden=1
map <F3> :NERDTreeToggle<CR>
map <F8> :TagbarToggle<CR>

"set background=dark
colorscheme solarized 
set noshowmode


nmap <Tab> <C-w><C-w>

let g:ycm_global_ycm_extra_conf="~/.vim/.ycm_extra_conf.py"
let g:Powerline_symbols="fancy"
"let g:powerline_loaded=1
set rtp+=/usr/local/lib/python2.7/dist-packages/powerline/bindings/vim/
" Always show statusline
set nocompatible
set encoding=utf-8
set laststatus=2
set t_Co=256
