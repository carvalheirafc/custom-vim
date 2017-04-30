syntax enable 
set hidden 
set history=100
set wildmenu
set ruler
set cmdheight=2
set backspace=eol,start,indent
set whichwrap+=<,>,h,l
set hlsearch
set showmatch
set mat=2
set foldcolumn=1
set softtabstop=4
set tabstop=4
set number
set showcmd
set cursorline
filetype indent on
set wildmenu
set lazyredraw
set foldenable
set foldlevelstart=10
set foldnestmax=10
set foldmethod=indent
colorscheme focuspoint

noremap <space> za
nnoremap B ^
nnoremap E $
inoremap jk <esc>
call plug#begin ('~/.vim/plugged')
Plug 'embear/vim-localvimrc'
Plug 'kchmck/vim-coffee-script'
Plug 'scrooloose/nerdtree'
Plug 'https://github.com/rafi/awesome-vim-colorschemes.git'

call plug#end()


